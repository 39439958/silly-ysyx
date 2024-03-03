#include <common.h>

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;


const char *regs_name[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

void difftest_skip_ref() {
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

void reg_display() {
    printf(ANSI_FMT("npc regs : \n", ANSI_FG_RED));
    for (int i = 0; i < 32; i++) {
        printf(ANSI_FMT("%3s: 0x%08x", ANSI_FG_RED), regs_name[i], top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[i]);
        if (i % 4 == 3) {
            printf("\n");
        } else {
            printf("\t");
        }   
    }
}

void ref_reg_display(cpu_state *ref) {
    printf(ANSI_FMT("nemu regs : \n", ANSI_FG_RED));
    for (int i = 0; i < 32; i++) {
        printf(ANSI_FMT("%3s: 0x%08x", ANSI_FG_RED), regs_name[i], ref->gpr[i]);
        if (i % 4 == 3) {
            printf("\n");
        } else {
            printf("\t");
        }   
    }
}

void difftest_checkregs(cpu_state *ref_r, uint32_t pc) {
    bool diff_error = false;
    for (int i = 0; i < 32; i++) {
        if (ref_r->gpr[i] != cpu.gpr[i]) {
            diff_error = true;
            break;
        }
    }
    if (ref_r->pc != cpu.pc) diff_error = true;

    if (diff_error) {
        printf("ref_r->pc = 0x%08x, cpu.pc = 0x%08x\n", ref_r->pc, cpu.pc);
        npc_state = NPC_ABORT;
        reg_display();
        ref_reg_display(ref_r);
    }
}

void difftest_step(uint32_t pc) {
    cpu_state ref_r;

    if (is_skip_ref) {
        ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
        is_skip_ref = false;
        return;
    }

    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    difftest_checkregs(&ref_r, pc);
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

    printf(ANSI_FMT("Differential testing:", ANSI_FG_BLUE) ANSI_FMT("ON\n", ANSI_FG_GREEN));
    printf(ANSI_FMT("The result of every instruction will be compared with %s. "
        "This will help you a lot for debugging, but also significantly reduce the performance. "
        "If it is not necessary, you can turn it off in menuconfig.\n", ANSI_FG_BLUE), ref_so_file);

    ref_difftest_init(port);
    ref_difftest_memcpy(0x80000000, pmem, img_size, DIFFTEST_TO_REF);
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}