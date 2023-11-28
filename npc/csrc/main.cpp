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

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))
#define NPC_QUIT 0
#define NPC_ABORT 1

vluint64_t sim_time = 0;
int is_quit = 0;
int quit_state = 0;

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


Vtop *top = new Vtop;
VerilatedVcdC *m_trace = new VerilatedVcdC;

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

void init_mem() {
    memset(pmem, rand(), 0x8000000);
    memcpy(pmem, img, sizeof(img));
}

void parse_img(int argc, char** argv) {
    img_file = argv[1];
    printf("img_file = %s\n", img_file);
}

void load_img() {
    if (img_file == NULL) {
        return;
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

uint32_t pmem_read(uint32_t pc){
    return *(uint32_t *)(pmem + pc - 0x80000000);
}

void npc_exec(int n) {
    while (n--) { 
        top->clk ^= 1;
        top->rst = 0;
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;

        top->clk ^= 1;
        top->inst = pmem_read(top->pc);
        top->eval();
        m_trace->dump(sim_time);
        sim_time++;

        if (top->inst == 0x0000006f) {
            is_quit = 1;
            quit_state = NPC_ABORT;
        }
        printf("pc : %x, inst : %08x\n", top->pc, top->inst);

        if (is_quit) {
            break;
        }
    }
}

void reg_display() {
    for (int i = 0; i < 32; i++) {
    printf("%s : 0x%08x\n", regs[i], top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[i]);
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
    load_img();

    // initial NPC rst
    npc_rst();

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
