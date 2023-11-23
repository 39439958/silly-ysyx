#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"

// end time
#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;
int exited = 0;
static uint8_t pmem[0x8000000] __attribute((aligned(4096))) = {};

void ebreak() {
  exited = 1;
}

void init_mem() {
  memset(pmem, rand(), 0x8000000);
}

uint32_t pmem_read(uint32_t pc){
    return *(uint32_t *)(pmem + pc - 0x80000000);
}


int main(int argc, char** argv, char** env) {
    // 新建需要仿真的对象
    Vtop *dut = new Vtop;

    // 生成仿真波形, "vcd" 文件
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (!exited) {
        if (sim_time == 0) {
			    dut->clk = 0;
			    dut->rst = 1;
          dut->eval();
          m_trace->dump(sim_time);
          sim_time++;
          dut->clk = 1;
          dut->rst = 1;
          dut->eval();
		    } 
        else {
          dut->clk ^= 1;
          dut->rst = 0;
          dut->eval();
          m_trace->dump(sim_time);
          sim_time++;
          dut->clk ^= 1;
          dut->inst = pmem_read(dut->pc);
          printf("pc : %u\n", dut->pc);
          dut->eval();
        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
