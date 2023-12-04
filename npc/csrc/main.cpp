#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include "Vtop___024root.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <dlfcn.h>

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))
#define NPC_QUIT 0
#define NPC_ABORT 1

vluint64_t sim_time = 0;
int is_quit = 0;
int quit_state = 0;
char *ref_so_file = "/home/silly/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";

static uint8_t pmem[0x8000000] __attribute((aligned(4096))) = {};
char *img_file = NULL;
static const uint32_t img [] = {
    0x00108093,
    0x00108093,
    0x00108093,
    0x00108093,
    0x00100073,
};
const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

typedef struct cpu_state{
  uint32_t gpr[32];
  uint32_t pc;
} cpu_state;

Vtop *top = new Vtop;
VerilatedVcdC *m_trace = new VerilatedVcdC;
cpu_state cpu;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void init_disasm(const char *triple);

void difftest_step(uint32_t pc);
void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

extern "C" void pmem_read(int raddr, int *rdata) {
    // 总是读取地址为`raddr & ~0x3u`的4字节返回给`rdata`
    uint32_t addr = raddr & ~0x3u;
    *rdata = *(uint32_t *)(pmem + addr - 0x80000000);
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
    // `wmask`中每比特表示`wdata`中1个字节的掩码,
    // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
    uint32_t addr = waddr & ~0x3u;
    uint32_t *p = (uint32_t *)(pmem + addr - 0x80000000);
    uint32_t mask = 0; 
    for (int i = 0; i < 4; i++) {
        if (wmask & (1 << i)) {
            mask |= 0xff << (i * 8);
        }
    }
    *p = (*p & ~mask) | (wdata & mask);
}

void ebreak() {
    is_quit = 1;
}

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
    static char *line_read = NULL;

    if (line_read) {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read) {
        add_history(line_read);
    }

    return line_read;
}

void reg_display() {
    for (int i = 0; i < 32; i++) {
        printf("%3s: 0x%08x", regs[i], top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[i]);
        if (i % 4 == 3) {
            printf("\n");
        } else {
            printf("\t");
        }   
    }
}

void init_mem() {
    memset(pmem, rand(), 0x8000000);
    memcpy(pmem, img, sizeof(img));
    cpu.pc = 0x80000000;
}

void parse_img(int argc, char** argv) {
    img_file = argv[1];
    printf("img_file = %s\n", img_file);
}

long load_img() {
    if (img_file == NULL) {
        printf("No image is given. Use the default build-in image.\n");
        return 4096;
    }

    FILE *fp = fopen(img_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open img file: %s\n", img_file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    int img_size = ftell(fp);

    printf("The image is %s, size = %d\n", img_file, img_size);

    fseek(fp, 0, SEEK_SET);
    if (fread(pmem, img_size, 1, fp) != 1) {
        fprintf(stderr, "Failed to read img file: %s\n", img_file);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return img_size;
}

void npc_rst() {
    top->clk = 0;
    top->rst = 1;
    top->eval();
    m_trace->dump(sim_time);
    sim_time++;

    top->clk = 1;
    top->rst = 1;
    top->eval();
    m_trace->dump(sim_time);
    sim_time++;
}

bool difftest_checkregs(cpu_state *ref_r, uint32_t pc) {
    for (int i = 0; i < 32; i++) {
        if (ref_r->gpr[i] != cpu.gpr[i]) {
            printf("ref_r->gpr[%d] = 0x%08x, cpu.gpr[%d] = 0x%08x\n", i, ref_r->gpr[i], i, cpu.gpr[i]);
            return false;
        }
    }
    if (ref_r->pc != cpu.pc) {
        printf("ref_r->pc=0x%8x, cpu.pc=0x%8x", ref_r->pc, cpu.pc);
        return false;
    }
    return true;
}

static void checkregs(cpu_state *ref, uint32_t pc) {
  if (!difftest_checkregs(ref, pc)) {
    is_quit = 1;
    quit_state = NPC_ABORT;
    reg_display();
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
    assert(ref_so_file != NULL);

    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY);
    assert(handle);

    ref_difftest_memcpy = reinterpret_cast<void (*)(uint32_t, void *, size_t, bool)>(dlsym(handle, "difftest_memcpy"));
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = reinterpret_cast<void (*)(void *, bool)>(dlsym(handle, "difftest_regcpy"));
    assert(ref_difftest_regcpy);

    ref_difftest_exec = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_exec"));
    assert(ref_difftest_exec);

    ref_difftest_raise_intr = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_raise_intr"));
    assert(ref_difftest_raise_intr);

    void (*ref_difftest_init)(int) = reinterpret_cast<void (*)(int)>(dlsym(handle, "difftest_init"));
    assert(ref_difftest_init);

    printf("Differential testing: \33[1;32mON\33[0m \n");
    printf("The result of every instruction will be compared with %s. "
        "This will help you a lot for debugging, but also significantly reduce the performance. "
        "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

    ref_difftest_init(port);
    ref_difftest_memcpy(0x80000000, pmem, img_size, DIFFTEST_TO_REF);
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

void difftest_step(uint32_t pc) {
    cpu_state ref_r;

    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

    checkregs(&ref_r, pc);
}

void npc_exec(int n) {
    while (n--) { 
        top->clk ^= 1;
        top->rst = 0;
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;

        top->clk ^= 1;

        // save pc
        char inst_buf[64];
        char *p = inst_buf;
        uint32_t this_pc = top->rootp->top__DOT__pc;
        p += snprintf(p, sizeof(inst_buf), "0x%08x:", top->rootp->top__DOT__pc);

        // execute
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;

        // save inst
        uint8_t *inst = (uint8_t *)&top->rootp->top__DOT__inst;
        for (int j = 3; j >= 0; j--) {
            p += snprintf(p, 4, " %02x", inst[j]);
        }
        memset(p, ' ', 4);
        p += 4;
        void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
        disassemble(p, inst_buf + sizeof(inst_buf) - p, this_pc, (uint8_t *)&top->rootp->top__DOT__inst, 4);
        printf("%s\n", inst_buf);

        // reset r0 = 0
        top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[0] = 0;

        // store cpu state
        cpu.pc = this_pc;
        for (int i = 0; i < 32; i++) {
            cpu.gpr[i] = top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[i];
        }

        // difftest
        difftest_step(this_pc);

        if (top->rootp->top__DOT__inst == 0x0000006f) {
            is_quit = 1;
            quit_state = NPC_ABORT;
        }

        if (is_quit) {
            break;
        }
    }
}

static int cmd_c(char *args) {
    npc_exec(-1);
    return is_quit;
}

static int cmd_q(char *args) {
    is_quit = 1;
    return 1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static struct {
    const char *name;
    const char *description;
    int (*handler) (char *);
} cmd_table [] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit NPC", cmd_q },
    { "si", "Step through N instructions", cmd_si},
    { "info", "Show the infomation of reg and watch point", cmd_info},
    { "x", "Examine memory", cmd_x},
};

static int cmd_help(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL) {
        /* no argument given */
        for (i = 0; i < NR_CMD; i ++) {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else {
        for (i = 0; i < NR_CMD; i ++) {
            if (strcmp(arg, cmd_table[i].name) == 0) {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

static int cmd_si(char *args) {
    int n = 0;
    if (args == NULL)
        n = 1;
    else
        sscanf(args, "%d", &n);
    npc_exec(n);
    return is_quit;
}

static int cmd_info(char *args) {
    if (strcmp(args, "r") == 0) {
        reg_display();
    } else {
        printf("Unknow parma\n");
    }
    return 0;
}

static int cmd_x(char *args) {
    int n;
    uint32_t addr;
    sscanf(args, "%d 0x%x", &n, &addr);
    for (int i = 0; i < n; i++) {
        uint32_t data;
        pmem_read(addr + i * 4, (int *)&data);
        printf("0x%08x: 0x%08x\n", addr + i * 4, data);
    }
    return 0;
}

void exit_work() {
    quit_state ? printf("\33[1;41mHIT BAD TRAP\33[0m\n") : printf("\33[1;32mHIT GOOD TRAP\33[0m\n");
    m_trace->close();
    delete top;
    exit(EXIT_SUCCESS);
}


int main(int argc, char** argv, char** env) {
    // start waveform trace
    Verilated::traceEverOn(true);
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // initial memory and instruction
    init_mem();
    parse_img(argc, argv);
    long img_size = load_img();
    init_disasm( "riscv32" "-pc-linux-gnu" );

    // initial NPC rst
    npc_rst();

    // initial difftest
    init_difftest(ref_so_file, img_size, 1234);

    for (char *str; (str = rl_gets()) != NULL; ) {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL) { 
            continue; 
        }

        /* treat the remaining string as the arguments,
        * which may need further parsing
        */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end) {
            args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i ++) {
        if (strcmp(cmd, cmd_table[i].name) == 0) {
            if (cmd_table[i].handler(args) != 0) { 
                exit_work();
            }
            break;
        }
        }

        if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    }
}
