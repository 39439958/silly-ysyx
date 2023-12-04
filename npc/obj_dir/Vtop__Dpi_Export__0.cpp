// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vtop.h"
#include "Vtop__Syms.h"
#include "verilated_dpi.h"


void Vtop::get_inst(int* inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root::get_inst\n"); );
    // Init
    IData/*31:0*/ inst__Vcvt;
    inst__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_inst");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_get_inst_t __Vcb = (Vtop__Vcb_get_inst_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), inst__Vcvt);
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) *inst = inst__Vcvt;
}
