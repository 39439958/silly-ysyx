// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/silly/ysyx-workbench/npc/vsrc/ysyx_IDU.v:166:34
    extern void ebreak();
    // DPI import at /home/silly/ysyx-workbench/npc/vsrc/top.v:6:34
    extern void pmem_read(int raddr, int* rdata);
    // DPI import at /home/silly/ysyx-workbench/npc/vsrc/ysyx_EXU.v:41:34
    extern void pmem_write(int waddr, int wdata, char wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
