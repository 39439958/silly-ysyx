// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &rdata);

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_top__DOT__pmem_read__0__rdata;
    __Vtask_top__DOT__pmem_read__0__rdata = 0;
    // Body
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, __Vtask_top__DOT__pmem_read__0__rdata);
        vlSelf->top__DOT__inst = __Vtask_top__DOT__pmem_read__0__rdata;
    }
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
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->top__DOT__inst) == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
              [7U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[6U] 
        = (0x3700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->top__DOT__inst))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[7U] 
        = (0x1700000000ULL | (QData)((IData)((0xfffff000U 
                                              & vlSelf->top__DOT__inst))));
    vlSelf->__VdfgTmp_h34ce9417__0 = (((- (IData)((vlSelf->top__DOT__inst 
                                                   >> 0x1fU))) 
                                       << 0x15U) | 
                                      ((0x100000U & 
                                        (vlSelf->top__DOT__inst 
                                         >> 0xbU)) 
                                       | ((0xff000U 
                                           & vlSelf->top__DOT__inst) 
                                          | ((0x800U 
                                              & (vlSelf->top__DOT__inst 
                                                 >> 9U)) 
                                             | (0x7feU 
                                                & (vlSelf->top__DOT__inst 
                                                   >> 0x14U))))));
    vlSelf->__VdfgTmp_hc8691d24__0 = (((- (IData)((vlSelf->top__DOT__inst 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelf->top__DOT__inst 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->top__DOT__inst 
                                                         >> 7U))));
    vlSelf->top__DOT__idu0__DOT__is_U = ((0x17U == 
                                          (0x7fU & vlSelf->top__DOT__inst)) 
                                         | (0x37U == 
                                            (0x7fU 
                                             & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | ((0xfe0U & (vlSelf->top__DOT__inst 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlSelf->top__DOT__inst 
                                                    >> 7U))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0x15U) | ((0x100000U & (vlSelf->top__DOT__inst 
                                       >> 0xbU)) | 
                         ((0xff000U & vlSelf->top__DOT__inst) 
                          | ((0x800U & (vlSelf->top__DOT__inst 
                                        >> 9U)) | (0x7feU 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 0x14U))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[5U] 
        = (((- (IData)((vlSelf->top__DOT__inst >> 0x1fU))) 
            << 0xcU) | (vlSelf->top__DOT__inst >> 0x14U));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[6U] 
        = (0xfffff000U & vlSelf->top__DOT__inst);
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[7U] 
        = (0xfffff000U & vlSelf->top__DOT__inst);
    vlSelf->top__DOT__idu0__DOT__is_beq = (IData)((0x63U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_bne = (IData)((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_blt = (IData)((0x4063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_bge = (IData)((0x5063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_bltu = (IData)(
                                                   (0x6063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_bgeu = (IData)(
                                                   (0x7063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->__VdfgTmp_h441be388__0 = (((- (IData)((vlSelf->top__DOT__inst 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->top__DOT__inst 
                                                   >> 0x14U));
    vlSelf->top__DOT__exu0__DOT__rs2 = vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__inst >> 0x14U))];
    vlSelf->top__DOT__exu0__DOT__rs1 = vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__inst >> 0xfU))];
    vlSelf->top__DOT__idu0__DOT__is_S = ((IData)((0x2023U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->top__DOT__inst))) 
                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_sb) 
                                            | (IData)(vlSelf->top__DOT__idu0__DOT__is_sh)));
    vlSelf->top__DOT__idu0__DOT__is_sltiu = (IData)(
                                                    (0x3013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_addi = (IData)(
                                                   (0x13U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_lw = (IData)((0x2003U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__is_jalr = (IData)(
                                                   (0x67U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4U] 
        = (0x6f00000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h34ce9417__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2U] 
        = (0x2300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_hc8691d24__0)));
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
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
        = (vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0x7fU & vlSelf->top__DOT__inst) 
                          == vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list
                          [7U]))) & vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list
              [7U]));
    vlSelf->top__DOT__imm = vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out;
    vlSelf->top__DOT__BrType = ((IData)(vlSelf->top__DOT__idu0__DOT__is_beq)
                                 ? 2U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne)
                                          ? 3U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt)
                                                   ? 4U
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge)
                                                    ? 5U
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu)
                                                     ? 6U
                                                     : 
                                                    ((IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu)
                                                      ? 7U
                                                      : 0U))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[0U] 
        = (IData)((0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[1U] 
        = ((0xffffff80U & (((- (IData)((vlSelf->top__DOT__inst 
                                        >> 0x1fU))) 
                            << 0x13U) | (0x7ff80U & 
                                         (vlSelf->top__DOT__inst 
                                          >> 0xdU)))) 
           | (IData)(((0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0))) 
                      >> 0x20U)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[2U] 
        = (0x180U | (((- (IData)((vlSelf->top__DOT__inst 
                                  >> 0x1fU))) << 0x1aU) 
                     | ((0x3f80000U & (vlSelf->top__DOT__inst 
                                       >> 6U)) | ((0x7c000U 
                                                   & (vlSelf->top__DOT__inst 
                                                      << 7U)) 
                                                  | (0x7fU 
                                                     & ((- (IData)(
                                                                   (vlSelf->top__DOT__inst 
                                                                    >> 0x1fU))) 
                                                        >> 0xdU))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[3U] 
        = (0x8c000U | ((0xffe00000U & (vlSelf->top__DOT__inst 
                                       << 1U)) | (0x3fffU 
                                                  & ((- (IData)(
                                                                (vlSelf->top__DOT__inst 
                                                                 >> 0x1fU))) 
                                                     >> 6U))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[4U] 
        = (0xce00000U | ((0xe0000000U & (vlSelf->top__DOT__inst 
                                         << 8U)) | 
                         (0x1fffffU & ((0x1ffffeU & 
                                        ((- (IData)(
                                                    (vlSelf->top__DOT__inst 
                                                     >> 0x1fU))) 
                                         << 1U)) | 
                                       (vlSelf->top__DOT__inst 
                                        >> 0x1fU)))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[5U] 
        = (0xf0000000U | ((0xffe0000U & ((- (IData)(
                                                    (vlSelf->top__DOT__inst 
                                                     >> 0x1fU))) 
                                         << 0x11U)) 
                          | ((0x10000U & (vlSelf->top__DOT__inst 
                                          >> 0xfU)) 
                             | ((0xff00U & (vlSelf->top__DOT__inst 
                                            >> 4U)) 
                                | ((0x80U & (vlSelf->top__DOT__inst 
                                             >> 0xdU)) 
                                   | (0x7fU & (vlSelf->top__DOT__inst 
                                               >> 0x18U)))))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[6U] 
        = (6U | (0xfffffff8U & (((- (IData)((vlSelf->top__DOT__inst 
                                             >> 0x1fU))) 
                                 << 0xfU) | (0x7ff8U 
                                             & (vlSelf->top__DOT__inst 
                                                >> 0x11U)))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[7U] 
        = (0x98U | ((0xffc00000U & (vlSelf->top__DOT__inst 
                                    << 0xaU)) | (7U 
                                                 & ((- (IData)(
                                                               (vlSelf->top__DOT__inst 
                                                                >> 0x1fU))) 
                                                    >> 0x11U))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[8U] 
        = (0xdc00U | ((0xe0000000U & (vlSelf->top__DOT__inst 
                                      << 0x11U)) | 
                      (0x3fffffU & (vlSelf->top__DOT__inst 
                                    >> 0x16U))));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3[9U] 
        = (0x2e0000U | (0x1fffffffU & (vlSelf->top__DOT__inst 
                                       >> 0xfU)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1U] 
        = (0x300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3U] 
        = (0x6700000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[5U] 
        = (0x1300000000ULL | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0)));
    vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0 
        = VL_LTS_III(32, vlSelf->top__DOT__exu0__DOT__rs1, vlSelf->top__DOT__exu0__DOT__rs2);
    vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0 
        = VL_GTES_III(32, vlSelf->top__DOT__exu0__DOT__rs1, vlSelf->top__DOT__exu0__DOT__rs2);
    vlSelf->top__DOT__do_jump = ((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                                 | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr));
    vlSelf->top__DOT__idu0__DOT__is_add_type = ((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                                                | ((0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__inst)) 
                                                   | ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__inst)) 
                                                      | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_S) 
                                                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw) 
                                                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                                                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                                                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                                                        | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                                                           | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                                                              | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu))))))))))));
    vlSelf->top__DOT__idu0__DOT__is_I = ((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw) 
                                               | (IData)(vlSelf->top__DOT__idu0__DOT__is_sltiu))));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__is_R)
            ? vlSelf->top__DOT__exu0__DOT__rs2 : vlSelf->top__DOT__imm);
    vlSelf->top__DOT__BrE = (1U & ((4U & (IData)(vlSelf->top__DOT__BrType))
                                    ? ((2U & (IData)(vlSelf->top__DOT__BrType))
                                        ? ((1U & (IData)(vlSelf->top__DOT__BrType))
                                            ? ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                >> 0x1fU)
                                                ? (
                                                   (~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0))
                                                : (
                                                   (~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)))
                                            : ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                >> 0x1fU)
                                                ? (
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))
                                                : (
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))))
                                        : ((1U & (IData)(vlSelf->top__DOT__BrType))
                                            ? (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)
                                            : (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0)))
                                    : (((IData)(vlSelf->top__DOT__BrType) 
                                        >> 1U) & ((1U 
                                                   & (IData)(vlSelf->top__DOT__BrType))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__rs1 
                                                   != vlSelf->top__DOT__exu0__DOT__rs2)
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__rs1 
                                                   == vlSelf->top__DOT__exu0__DOT__rs2)))));
    VL_WRITEF("REG1 = %x\nREG2 = %x\nType = %x\nBrE = %x\n",
              32,vlSelf->top__DOT__exu0__DOT__rs1,32,
              vlSelf->top__DOT__exu0__DOT__rs2,3,(IData)(vlSelf->top__DOT__BrType),
              1,vlSelf->top__DOT__BrE);
    vlSelf->top__DOT__rf_wr_sel = ((IData)(vlSelf->top__DOT__do_jump)
                                    ? 1U : (((IData)(vlSelf->top__DOT__idu0__DOT__is_U) 
                                             | ((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                                                | (IData)(vlSelf->top__DOT__idu0__DOT__is_sltiu)))
                                             ? 2U : 
                                            (((IData)(vlSelf->top__DOT__idu0__DOT__is_lb) 
                                              | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lh) 
                                                 | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw) 
                                                    | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lbu) 
                                                       | (IData)(vlSelf->top__DOT__idu0__DOT__is_lhu)))))
                                              ? 3U : 0U)));
    vlSelf->top__DOT__alu_ctrl = ((IData)(vlSelf->top__DOT__idu0__DOT__is_add_type)
                                   ? 0U : ((0x37U == 
                                            (0x7fU 
                                             & vlSelf->top__DOT__inst))
                                            ? 0xeU : 
                                           ((IData)(vlSelf->top__DOT__idu0__DOT__is_sltiu)
                                             ? 3U : 0U)));
    vlSelf->top__DOT__rf_wr_en = ((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_U) 
                                     | (0x6fU == (0x7fU 
                                                  & vlSelf->top__DOT__inst))));
    vlSelf->top__DOT__alu_a_sel = ((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                                   | ((IData)(vlSelf->top__DOT__idu0__DOT__is_R) 
                                      | (IData)(vlSelf->top__DOT__idu0__DOT__is_S)));
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
        = ((IData)(vlSelf->top__DOT__alu_a_sel) ? vlSelf->top__DOT__exu0__DOT__rs1
            : vlSelf->top__DOT__pc);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0 
        = (VL_LTS_III(32, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
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
                                                   : vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, 
                                                                 (0x1fU 
                                                                  & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
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
                                                   - vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))))
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
                                                   & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   | vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   ^ vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)))
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
                                                   ((vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
                                                     >> 0x1fU)
                                                     ? vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0
                                                     : 0U)
                                                    : 
                                                   ((vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
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
                                                    & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   + vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)))));
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(0U)) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__idu0__DOT__ebreak_TOP();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->top__DOT__idu0__DOT__is_ebreak) {
        Vtop___024root____Vdpiimwrap_top__DOT__idu0__DOT__ebreak_TOP();
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_top__DOT__exu0__DOT__pmem_read__3__rdata;
    __Vtask_top__DOT__exu0__DOT__pmem_read__3__rdata = 0;
    // Body
    if (VL_UNLIKELY((3U == ((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                             ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_sh)
                                      ? 2U : ((IData)(
                                                      (0x2023U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->top__DOT__inst)))
                                               ? 3U
                                               : 0U)))))) {
        Vtop___024root____Vdpiimwrap_top__DOT__exu0__DOT__pmem_write_TOP(vlSelf->top__DOT__exu0__DOT__alu_out, vlSelf->top__DOT__exu0__DOT__rs2, 0xfU);
        VL_WRITEF("wr_data = %x\n",32,vlSelf->top__DOT__exu0__DOT__rs2);
    }
    if (VL_UNLIKELY((5U == ((IData)(vlSelf->top__DOT__idu0__DOT__is_lb)
                             ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_lbu)
                                      ? 2U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_lh)
                                               ? 3U
                                               : ((IData)(vlSelf->top__DOT__idu0__DOT__is_lhu)
                                                   ? 4U
                                                   : 
                                                  ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw)
                                                    ? 5U
                                                    : 0U)))))))) {
        Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__exu0__DOT__alu_out, __Vtask_top__DOT__exu0__DOT__pmem_read__3__rdata);
        vlSelf->top__DOT__exu0__DOT__dm_data = __Vtask_top__DOT__exu0__DOT__pmem_read__3__rdata;
        VL_WRITEF("rd_data = %x\n",32,vlSelf->top__DOT__exu0__DOT__dm_data);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vdly__top__DOT__pc;
    __Vdly__top__DOT__pc = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0;
    // Body
    __Vdly__top__DOT__pc = vlSelf->top__DOT__pc;
    __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 0U;
    __Vdly__top__DOT__pc = ((IData)(vlSelf->rst) ? 0x80000000U
                             : (((IData)(vlSelf->top__DOT__BrE) 
                                 | (IData)(vlSelf->top__DOT__do_jump))
                                 ? ((IData)(vlSelf->top__DOT__alu_a_sel)
                                     ? (0xfffffffeU 
                                        & vlSelf->top__DOT__exu0__DOT__alu_out)
                                     : vlSelf->top__DOT__exu0__DOT__alu_out)
                                 : ((IData)(4U) + vlSelf->top__DOT__pc)));
    if (vlSelf->top__DOT__rf_wr_en) {
        __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 
            = ((2U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                ? ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                    ? vlSelf->top__DOT__exu0__DOT__dm_data
                    : vlSelf->top__DOT__exu0__DOT__alu_out)
                : ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                    ? ((IData)(4U) + vlSelf->top__DOT__pc)
                    : 0U));
        __Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0 
            = (0x1fU & (vlSelf->top__DOT__inst >> 7U));
    }
    vlSelf->top__DOT__pc = __Vdly__top__DOT__pc;
    if (__Vdlyvset__top__DOT__exu0__DOT__regfile0__DOT__rf__v0) {
        vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[__Vdlyvdim0__top__DOT__exu0__DOT__regfile0__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__exu0__DOT__regfile0__DOT__rf__v0;
    }
    vlSelf->top__DOT__exu0__DOT__rs2 = vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__inst >> 0x14U))];
    vlSelf->top__DOT__exu0__DOT__rs1 = vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
        [(0x1fU & (vlSelf->top__DOT__inst >> 0xfU))];
    vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0 
        = VL_LTS_III(32, vlSelf->top__DOT__exu0__DOT__rs1, vlSelf->top__DOT__exu0__DOT__rs2);
    vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0 
        = VL_GTES_III(32, vlSelf->top__DOT__exu0__DOT__rs1, vlSelf->top__DOT__exu0__DOT__rs2);
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
        = ((IData)(vlSelf->top__DOT__idu0__DOT__is_R)
            ? vlSelf->top__DOT__exu0__DOT__rs2 : vlSelf->top__DOT__imm);
    vlSelf->top__DOT__BrE = (1U & ((4U & (IData)(vlSelf->top__DOT__BrType))
                                    ? ((2U & (IData)(vlSelf->top__DOT__BrType))
                                        ? ((1U & (IData)(vlSelf->top__DOT__BrType))
                                            ? ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                >> 0x1fU)
                                                ? (
                                                   (~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0))
                                                : (
                                                   (~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)))
                                            : ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                >> 0x1fU)
                                                ? (
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))
                                                : (
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))))
                                        : ((1U & (IData)(vlSelf->top__DOT__BrType))
                                            ? (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)
                                            : (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0)))
                                    : (((IData)(vlSelf->top__DOT__BrType) 
                                        >> 1U) & ((1U 
                                                   & (IData)(vlSelf->top__DOT__BrType))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__rs1 
                                                   != vlSelf->top__DOT__exu0__DOT__rs2)
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__rs1 
                                                   == vlSelf->top__DOT__exu0__DOT__rs2)))));
    VL_WRITEF("REG1 = %x\nREG2 = %x\nType = %x\nBrE = %x\n",
              32,vlSelf->top__DOT__exu0__DOT__rs1,32,
              vlSelf->top__DOT__exu0__DOT__rs2,3,(IData)(vlSelf->top__DOT__BrType),
              1,vlSelf->top__DOT__BrE);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
        = ((IData)(vlSelf->top__DOT__alu_a_sel) ? vlSelf->top__DOT__exu0__DOT__rs1
            : vlSelf->top__DOT__pc);
    vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0 
        = (VL_LTS_III(32, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
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
                                                   : vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a, 
                                                                 (0x1fU 
                                                                  & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
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
                                                   - vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))))
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
                                                   & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   | vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__alu_ctrl))
                                                   ? 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   ^ vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)))
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
                                                   ((vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
                                                     >> 0x1fU)
                                                     ? vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h3a4640af__0
                                                     : 0U)
                                                    : 
                                                   ((vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b 
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
                                                    & vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b))
                                                   : 
                                                  (vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a 
                                                   + vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b)))));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
}

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
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
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
