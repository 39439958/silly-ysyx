// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMuxKey.h for the primary calling header

#ifndef VERILATED_VMUXKEY___024ROOT_H_
#define VERILATED_VMUXKEY___024ROOT_H_  // guard

#include "verilated.h"

class VMuxKey__Syms;
class VMuxKey___024unit;


class VMuxKey___024root final : public VerilatedModule {
  public:
    // CELLS
    VMuxKey___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ top__DOT__is_ebreak;
    VL_OUT8(out,0,0);
    VL_IN8(key,0,0);
    VL_IN8(default_out,0,0);
    VL_IN8(lut,3,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ MuxKeyWithDefault__DOT__i0__DOT__lut_out;
    CData/*0:0*/ MuxKeyWithDefault__DOT__i0__DOT__hit;
    CData/*0:0*/ top__DOT__alu_a_sel;
    CData/*0:0*/ top__DOT__do_jump;
    CData/*0:0*/ top__DOT__idu0__DOT__is_jalr;
    CData/*0:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__is_ebreak;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ top__DOT__inst_imm;
    IData/*31:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
    IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0;
    VlWide<5>/*149:0*/ __VdfgTmp_hf08f7ef8__0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*1:0*/, 2> MuxKeyWithDefault__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> MuxKeyWithDefault__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*0:0*/, 2> MuxKeyWithDefault__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*38:0*/, 5> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 5> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 5> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__exu0__DOT__regfile0__DOT__rf;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VMuxKey__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMuxKey___024root(VMuxKey__Syms* symsp, const char* v__name);
    ~VMuxKey___024root();
    VL_UNCOPYABLE(VMuxKey___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
