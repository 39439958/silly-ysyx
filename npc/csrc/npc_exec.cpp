#include <common.h>
// #define INST_DISPLAY 1

void difftest_step(uint32_t pc);


void ebreak() {
    npc_state = NPC_END;
}

void npc_rst() {
    top->clk = 0;
    top->rst = 1;
    top->eval();

    top->clk = 1;
    top->rst = 1;
    top->eval();
}

void npc_exec(int n) {
    while (n--) { 
        top->clk ^= 1;
        top->rst = 0;
        top->eval();

        // save pc
        char inst_buf[64];
        char *p = inst_buf;
        uint32_t this_pc = top->rootp->top__DOT__pc;
        p += snprintf(p, sizeof(inst_buf), "0x%08x:", top->rootp->top__DOT__pc);

        // execute
        top->clk ^= 1;
        top->eval();

        // save inst
        uint8_t *inst = (uint8_t *)&top->rootp->top__DOT__inst;
        for (int j = 3; j >= 0; j--) {
            p += snprintf(p, 4, " %02x", inst[j]);
        }
        memset(p, ' ', 4);
        p += 4;
        void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
        disassemble(p, inst_buf + sizeof(inst_buf) - p, this_pc, (uint8_t *)&top->rootp->top__DOT__inst, 4);

        #ifdef INST_DISPLAY
          printf("%s\n", inst_buf);
        #endif

        // reset r0 = 0
        top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[0] = 0;

        // store cpu state
        cpu.pc = top->rootp->top__DOT__pc;
        for (int i = 0; i < 32; i++) {
            cpu.gpr[i] = top->rootp->top__DOT__exu0__DOT__regfile0__DOT__rf[i];
        }

        // difftest
        // difftest_step(top->rootp->top__DOT__pc);

        // if (top->rootp->top__DOT__inst == 0x00078463) {
        //     npc_state = NPC_ABORT;
        // }

        if (npc_state == NPC_ABORT || npc_state == NPC_END || npc_state == NPC_QUIT) {
            break;
        }
    }
}