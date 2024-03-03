#include <common.h>

int npc_state = NPC_RUNNING;
cpu_state cpu = {.pc = 0x80000000};
Vtop *top = new Vtop;
uint8_t pmem[0x8000000] __attribute((aligned(4096))) = {};


void init_disasm(const char *triple);

// difftest
void init_difftest(char *ref_so_file, long img_size, int port);
void difftest_step(uint32_t pc);

// sdb
void sdb_mainloop();

// memory
long load_img(char *img_file);
void init_mem();

// npc
void npc_rst();


int main(int argc, char** argv, char** env) {
    init_mem();

    welcome();

    long img_size = load_img(argv[1]);

    // initial asm to c instruction
    init_disasm( "riscv32" "-pc-linux-gnu" );

    init_difftest(ref_so_file, img_size, 1234);

    npc_rst();


    sdb_mainloop();

    exit_work();
}
