#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include <readline/readline.h>
#include <readline/history.h>


#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;
int exited = 0;
int err = 0;
static uint8_t pmem[0x8000000] __attribute((aligned(4096))) = {};
char *img_file = NULL;
static const uint32_t img [] = {
  0x00108093,
  0x00108093,
  0x00108093,
  0x00108093,
  0x00100073,
};

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

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Step through N instructions", cmd_si},
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
  cpu_exec(n);
  return 0;
}

void ebreak() {
  exited = 1;
}

uint32_t pmem_read(uint32_t pc){
    return *(uint32_t *)(pmem + pc - 0x80000000);
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


int main(int argc, char** argv, char** env) {
    Vtop *top = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    init_mem();

    parse_img(argc, argv);

    load_img();

    while (!exited) {
        
        if (sim_time == 0) {
			    top->clk = 0;
			    top->rst = 1;
          top->eval();
          m_trace->dump(sim_time);
          sim_time++;
          top->clk = 1;
          top->rst = 1;
          top->eval();
		    } 
        else {
          top->clk ^= 1;
          top->rst = 0;
          top->eval();
          m_trace->dump(sim_time);
          sim_time++;
          top->clk ^= 1;
          top->inst = pmem_read(top->pc);
          printf("pc : %x, inst : %08x\n", top->pc, top->inst);
          if (top->inst == 0x0000006f) {
            exited = 1;
            err = 1;
          }
          top->eval();
        }
        m_trace->dump(sim_time);
        sim_time++;
    }
    err ? printf("\33[1;41mHIT BAD TRAP\33[0m\n") : printf("\33[1;32mHIT GOOD TRAP\33[0m\n");
    m_trace->close();
    delete top;
    exit(EXIT_SUCCESS);
}
