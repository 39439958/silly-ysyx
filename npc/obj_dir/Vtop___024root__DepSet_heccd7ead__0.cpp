// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__is_ebreak = (0x73U == (0x7fU 
                                             & vlSelf->inst));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)((((- (IData)(
                                                          (vlSelf->inst 
                                                           >> 0x1fU))) 
                                               << 0x15U) 
                                              | ((0x100000U 
                                                  & (vlSelf->inst 
                                                     >> 0xbU)) 
                                                 | ((0xff000U 
                                                     & vlSelf->inst) 
                                                    | ((0x800U 
                                                        & (vlSelf->inst 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->inst 
                                                             >> 0x14U)))))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3U] 
        = (0x3700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->inst))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4U] 
        = (0x1700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->inst))));
    vlSelf->__VdfgTmp_h6ea4ae17__0 = (((- (IData)((vlSelf->inst 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->inst 
                                                   >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__is_jalr = (IData)(
                                                   (0x67U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->inst)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0U] 
        = (((- (IData)((vlSelf->inst >> 0x1fU))) << 0xcU) 
           | (vlSelf->inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1U] 
        = (((- (IData)((vlSelf->inst >> 0x1fU))) << 0x15U) 
           | ((0x100000U & (vlSelf->inst >> 0xbU)) 
              | ((0xff000U & vlSelf->inst) | ((0x800U 
                                               & (vlSelf->inst 
                                                  >> 9U)) 
                                              | (0x7feU 
                                                 & (vlSelf->inst 
                                                    >> 0x14U))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2U] 
        = (((- (IData)((vlSelf->inst >> 0x1fU))) << 0xcU) 
           | (vlSelf->inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3U] 
        = (0xfffff000U & vlSelf->inst);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4U] 
        = (0xfffff000U & vlSelf->inst);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0)));
    vlSelf->top__DOT__do_jump = ((0x6fU == (0x7fU & vlSelf->inst)) 
                                 | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr));
    vlSelf->top__DOT__alu_a_sel = ((IData)((0x13U == 
                                            (0x707fU 
                                             & vlSelf->inst))) 
                                   | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->inst) == 
                          vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->top__DOT__inst_imm = vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0 
        = (((IData)(vlSelf->top__DOT__alu_a_sel) ? 
            vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
            [(0x1fU & (vlSelf->inst >> 0xfU))] : vlSelf->pc) 
           + vlSelf->top__DOT__inst_imm);
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__ebreak_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->top__DOT__is_ebreak) {
        Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__ebreak_TOP();
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vdly__pc;
    __Vdly__pc = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    // Body
    __Vdly__pc = vlSelf->pc;
    __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0U;
    __Vdly__pc = ((IData)(vlSelf->rst) ? 0x80000000U
                   : ((IData)(vlSelf->top__DOT__do_jump)
                       ? ((IData)(vlSelf->top__DOT__alu_a_sel)
                           ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)
                           : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)
                       : ((IData)(4U) + vlSelf->pc)));
    if (((IData)(vlSelf->top__DOT__alu_a_sel) | ((0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->inst)) 
                                                 | (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->inst))))) {
        __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 
            = ((IData)(vlSelf->top__DOT__do_jump) ? 
               ((IData)(4U) + vlSelf->pc) : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0);
        __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 
            = (0x1fU & (vlSelf->inst >> 7U));
    }
    vlSelf->pc = __Vdly__pc;
    if (__Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0) {
        vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[__Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0 
        = (((IData)(vlSelf->top__DOT__alu_a_sel) ? 
            vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
            [(0x1fU & (vlSelf->inst >> 0xfU))] : vlSelf->pc) 
           + vlSelf->top__DOT__inst_imm);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/silly/ysyx-workbench/npc/vsrc/top.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/silly/ysyx-workbench/npc/vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/silly/ysyx-workbench/npc/vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
