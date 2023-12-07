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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        CData/*0:0*/ top__DOT__idu0__DOT__is_ebreak;
        VL_IN8(rst,0,0);
        CData/*1:0*/ top__DOT__rf_wr_sel;
        CData/*0:0*/ top__DOT__do_jump;
        CData/*2:0*/ top__DOT__BrType;
        CData/*0:0*/ top__DOT__alu_a_sel;
        CData/*3:0*/ top__DOT__alu_ctrl;
        CData/*2:0*/ top__DOT__dm_rd_sel;
        CData/*0:0*/ top__DOT__idu0__DOT__is_addi;
        CData/*0:0*/ top__DOT__idu0__DOT__is_xori;
        CData/*0:0*/ top__DOT__idu0__DOT__is_srai;
        CData/*0:0*/ top__DOT__idu0__DOT__is_andi;
        CData/*0:0*/ top__DOT__idu0__DOT__is_jalr;
        CData/*0:0*/ top__DOT__idu0__DOT__is_sltiu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_sub;
        CData/*0:0*/ top__DOT__idu0__DOT__is_add;
        CData/*0:0*/ top__DOT__idu0__DOT__is_xor;
        CData/*0:0*/ top__DOT__idu0__DOT__is_sltu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_and;
        CData/*0:0*/ top__DOT__idu0__DOT__is_sll;
        CData/*0:0*/ top__DOT__idu0__DOT__is_or;
        CData/*0:0*/ top__DOT__idu0__DOT__is_beq;
        CData/*0:0*/ top__DOT__idu0__DOT__is_bne;
        CData/*0:0*/ top__DOT__idu0__DOT__is_blt;
        CData/*0:0*/ top__DOT__idu0__DOT__is_bge;
        CData/*0:0*/ top__DOT__idu0__DOT__is_bltu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_bgeu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_lb;
        CData/*0:0*/ top__DOT__idu0__DOT__is_lbu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_lh;
        CData/*0:0*/ top__DOT__idu0__DOT__is_lhu;
        CData/*0:0*/ top__DOT__idu0__DOT__is_lw;
        CData/*0:0*/ top__DOT__idu0__DOT__is_I;
        CData/*0:0*/ top__DOT__idu0__DOT__is_U;
        CData/*0:0*/ top__DOT__idu0__DOT__is_R;
        CData/*0:0*/ top__DOT__idu0__DOT__is_S;
        CData/*0:0*/ top__DOT__idu0__DOT____VdfgTmp_h4d8b3a5b__0;
        CData/*0:0*/ top__DOT__idu0__DOT____VdfgTmp_he69f398c__0;
        CData/*0:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit;
        CData/*0:0*/ top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0;
        CData/*0:0*/ top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0;
        CData/*0:0*/ __Vtrigrprev__TOP__clk;
        CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__idu0__DOT__is_ebreak;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ top__DOT__inst;
        IData/*31:0*/ top__DOT__pc;
        IData/*31:0*/ top__DOT__imm;
        VlWide<11>/*350:0*/ top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3;
        IData/*31:0*/ top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
        IData/*31:0*/ top__DOT__exu0__DOT__alu_out;
        IData/*31:0*/ top__DOT__exu0__DOT__rs1;
        IData/*31:0*/ top__DOT__exu0__DOT__rs2;
        IData/*31:0*/ top__DOT__exu0__DOT__dm_data;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__signed_a;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT__signed_b;
        IData/*31:0*/ top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0;
        IData/*31:0*/ __VdfgTmp_he8947ce0__0;
        IData/*31:0*/ __VdfgTmp_h441bd1e7__0;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*38:0*/, 9> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*6:0*/, 9> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 9> top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__exu0__DOT__regfile0__DOT__rf;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
