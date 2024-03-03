#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <cstdio>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include "Vtop___024root.h"
#include <dlfcn.h>
#include <sys/time.h>
#include <cstddef>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <cstdint>

// control the color of printf
#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;35m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"
#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

// npc 
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };
extern int npc_state;
extern Vtop *top;

// cpu
typedef struct cpu_state{
  uint32_t gpr[32];
  uint32_t pc;
} cpu_state;
extern cpu_state cpu;

// memory
extern uint8_t pmem[0x8000000];

//difftest
static char *ref_so_file = "/home/silly/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";

// for main.cpp
inline void welcome() {
    printf(ANSI_FMT("=================================================\n", ANSI_FG_YELLOW));
    printf(ANSI_FMT("Build time: %s, %s\n", ANSI_FG_YELLOW), __TIME__, __DATE__);
    printf(ANSI_FMT("Welcome to NPC!\n", ANSI_FG_YELLOW));
}

inline void exit_work() {
    if (npc_state == NPC_ABORT) {
        printf(ANSI_FMT("HIT BAD TRAP\n", ANSI_FG_RED));
    } else {
        printf(ANSI_FMT("HIT GOOD TRAP\n", ANSI_FG_GREEN));
    }
}

#endif