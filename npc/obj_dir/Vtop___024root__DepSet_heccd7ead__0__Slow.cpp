// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu0__DOT__is_ebreak 
        = vlSelf->top__DOT__idu0__DOT__is_ebreak;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1U] = 0x6fU;
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2U] = 0x13U;
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3U] = 0x37U;
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4U] = 0x17U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/silly/ysyx-workbench/npc/vsrc/top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__idu0__DOT__is_ebreak = (0x73U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__inst));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1U] 
        = (0x6f00000000ULL | (QData)((IData)((((- (IData)(
                                                          (vlSelf->top__DOT__inst 
                                                           >> 0x1fU))) 
                                               << 0x15U) 
                                              | ((0x100000U 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 0xbU)) 
                                                 | ((0xff000U 
                                                     & vlSelf->top__DOT__inst) 
                                                    | ((0x800U 
                                                        & (vlSelf->top__DOT__inst 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->top__DOT__inst 
                                                             >> 0x14U)))))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3U] 
        = (0x3700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->top__DOT__inst))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4U] 
        = (0x1700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->top__DOT__inst))));
    vlSelf->__VdfgTmp_h441be388__0 = (((- (IData)((vlSelf->top__DOT__inst 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->top__DOT__inst 
                                                   >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0x15U) | ((0x100000U & (vlSelf->top__DOT__inst 
                                       >> 0xbU)) | 
                         ((0xff000U & vlSelf->top__DOT__inst) 
                          | ((0x800U & (vlSelf->top__DOT__inst 
                                        >> 9U)) | (0x7feU 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0x14U))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3U] 
        = (0xfffff000U & vlSelf->top__DOT__inst);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4U] 
        = (0xfffff000U & vlSelf->top__DOT__inst);
    vlSelf->top__DOT__idu0__DOT__is_S = ((IData)((0x2023U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->top__DOT__inst))) 
                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_sb) 
                                            | (IData)(vlSelf->top__DOT__idu0__DOT__is_sh)));
    vlSelf->top__DOT__idu0__DOT__is_addi = (IData)(
                                                   (0x13U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_jalr = (IData)(
                                                   (0x67U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                       == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__rf_wr_sel = ((0x6fU == (0x7fU 
                                              & vlSelf->top__DOT__inst)) 
                                   | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr));
    vlSelf->top__DOT__alu_ctrl = (((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                                   | ((0x17U == (0x7fU 
                                                 & vlSelf->top__DOT__inst)) 
                                      | ((0x6fU == 
                                          (0x7fU & vlSelf->top__DOT__inst)) 
                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                            | (IData)(vlSelf->top__DOT__idu0__DOT__is_S)))))
                                   ? 0U : ((0x37U == 
                                            (0x7fU 
                                             & vlSelf->top__DOT__inst))
                                            ? 0xeU : 0U));
    vlSelf->top__DOT__idu0__DOT__is_I = ((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                                         | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr));
    vlSelf->top__DOT__alu_a_sel = ((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__is_R) 
                                      | (IData)(vlSelf->top__DOT__idu0__DOT__is_S)));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
        = ((IData)(vlSelf->top__DOT__alu_a_sel) ? vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
           [(0x1fU & (vlSelf->top__DOT__inst >> 0xfU))]
            : vlSelf->top__DOT__pc);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0 
        = (VL_LTS_III(32, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, vlSelf->top__DOT__imm)
            ? 1U : 0U);
    vlSelf->top__DOT__exu0__DOT__alu_out = ((8U & (IData)(vlSelf->top__DOT__alu_ctrl))
                                             ? ((4U 
                                                 & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 0U
                                                   : vlSelf->top__DOT__imm)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, 
                                                                 (0x1fU 
                                                                  & vlSelf->top__DOT__imm))
                                                   : 0U))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 0U
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   - vlSelf->top__DOT__imm))))
                                             : ((4U 
                                                 & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   & vlSelf->top__DOT__imm)
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   | vlSelf->top__DOT__imm))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__imm))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   ^ vlSelf->top__DOT__imm)))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  ((vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                    >> 0x1fU)
                                                    ? 
                                                   ((vlSelf->top__DOT__imm 
                                                     >> 0x1fU)
                                                     ? vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0
                                                     : 0U)
                                                    : 
                                                   ((vlSelf->top__DOT__imm 
                                                     >> 0x1fU)
                                                     ? 1U
                                                     : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0))
                                                   : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__imm))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   + vlSelf->top__DOT__imm)))));
    if ((3U == ((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                 ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_sh)
                          ? 2U : ((IData)((0x2023U 
                                           == (0x707fU 
                                               & vlSelf->top__DOT__inst)))
                                   ? 3U : 0U))))) {
        Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__pmem_write_TOP(vlSelf->top__DOT__exu0__DOT__alu_out, 
                                                                         vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                                                                         [
                                                                         (0x1fU 
                                                                          & (vlSelf->top__DOT__inst 
                                                                             >> 0x14U))], 0xfU);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] top.idu0.is_ebreak)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] top.idu0.is_ebreak)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__rf_wr_sel = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu_a_sel = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__alu_ctrl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu0__DOT__is_addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_ebreak = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_lb = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_lbu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_lh = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_lhu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_lw = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_sb = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_sh = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_I = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_R = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__idu0__DOT__is_S = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(39);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__exu0__DOT__alu_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__VdfgTmp_h441be388__0 = 0;
    vlSelf->__Vdly__top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__idu0__DOT__is_ebreak = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
