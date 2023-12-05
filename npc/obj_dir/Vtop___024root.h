// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ top__DOT__idu0__DOT__is_ebreak;
    CData/*1:0*/ top__DOT__rf_wr_sel;
    CData/*0:0*/ top__DOT__do_jump;
    CData/*0:0*/ top__DOT__alu_a_sel;
    CData/*3:0*/ top__DOT__alu_ctrl;
    CData/*2:0*/ top__DOT__dm_rd_sel;
    CData/*1:0*/ top__DOT__dm_wr_sel;
    CData/*0:0*/ top__DOT__idu0__DOT__is_addi;
    CData/*0:0*/ top__DOT__idu0__DOT__is_jalr;
    CData/*0:0*/ top__DOT__idu0__DOT__is_sw;
    CData/*0:0*/ top__DOT__idu0__DOT__is_lb;
    CData/*0:0*/ top__DOT__idu0__DOT__is_lbu;
    CData/*0:0*/ top__DOT__idu0__DOT__is_lh;
    CData/*0:0*/ top__DOT__idu0__DOT__is_lhu;
    CData/*0:0*/ top__DOT__idu0__DOT__is_lw;
    CData/*0:0*/ top__DOT__idu0__DOT__is_sb;
    CData/*0:0*/ top__DOT__idu0__DOT__is_sh;
    CData/*0:0*/ top__DOT__idu0__DOT__is_I;
    CData/*0:0*/ top__DOT__idu0__DOT__is_R;
    CData/*0:0*/ top__DOT__idu0__DOT__is_S;
    CData/*0:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__idu0__DOT__is_ebreak;
    CData/*1:0*/ __Vtrigrprev__TOP__top__DOT__rf_wr_sel;
    CData/*2:0*/ __Vtrigrprev__TOP__top__DOT__dm_rd_sel;
    CData/*1:0*/ __Vtrigrprev__TOP__top__DOT__dm_wr_sel;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__inst;
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
    IData/*31:0*/ top__DOT__exu0__DOT__alu_out;
    IData/*31:0*/ top__DOT__exu0__DOT__rf_wdata;
    IData/*31:0*/ top__DOT__exu0__DOT__dm_data;
    IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__signed_a;
    IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0;
    IData/*31:0*/ __VdfgTmp_h441be388__0;
    IData/*31:0*/ __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    IData/*31:0*/ __Vdly__top__DOT__pc;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*38:0*/, 7> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 7> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__exu0__DOT__regfile0__DOT__rf;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
