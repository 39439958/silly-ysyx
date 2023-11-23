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
char *img_file = NULL;
static const uint32_t img [] = {
  0x00108093,
  0x00108093,
  0x00108093,
  0x00108093,
  0x00100073,
};


void ebreak() {
  exited = 1;
}

void init_mem() {
  memset(pmem, rand(), 0x8000000);
  memcpy(pmem, img, sizeof(img));
}

uint32_t pmem_read(uint32_t pc){
    return *(uint32_t *)(pmem + pc - 0x80000000);
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
    fread(pmem, img_size, 1, fp);
        
    fclose(fp);
}


int main(int argc, char** argv, char** env) {
    // 新建需要仿真的对象
    Vtop *dut = new Vtop;

    // 生成仿真波形, "vcd" 文件
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // 初始化内存
    init_mem();

    // 解析命令行参数
    parse_img(argc, argv);

    // 加载镜像文件
    load_img();

    int cnt = 1;
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
          printf("pc : %x, inst : %8x\n", dut->pc, dut->inst);
          cnt++;
          if(cnt == 10) {
            ebreak();
          }
          dut->eval();
        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
