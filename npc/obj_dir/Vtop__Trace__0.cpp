// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<7>/*223:0*/ __Vtemp_h6749d75c__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4]),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__inst),32);
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__rf_wr_sel));
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__alu_a_sel));
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__alu_ctrl),4);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__imm),32);
        bufp->chgCData(oldp+10,(((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                                  ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_sh)
                                           ? 2U : ((IData)(
                                                           (0x2023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->top__DOT__inst)))
                                                    ? 3U
                                                    : 0U)))),2);
        bufp->chgCData(oldp+11,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+12,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+13,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+14,((0x7fU & vlSelf->top__DOT__inst)),7);
        bufp->chgCData(oldp+15,((7U & (vlSelf->top__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+16,(vlSelf->top__DOT__idu0__DOT__is_addi));
        bufp->chgBit(oldp+17,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+18,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+19,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+20,(vlSelf->top__DOT__idu0__DOT__is_jalr));
        bufp->chgBit(oldp+21,((IData)((0x2023U == (0x707fU 
                                                   & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
        bufp->chgBit(oldp+23,(((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__inst)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                        | (IData)(vlSelf->top__DOT__idu0__DOT__is_S)))))));
        bufp->chgBit(oldp+24,(((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                               | (IData)(vlSelf->top__DOT__idu0__DOT__is_jalr))));
        bufp->chgBit(oldp+25,(vlSelf->top__DOT__idu0__DOT__is_S));
        __Vtemp_h6749d75c__0[0U] = (IData)((0x6700000000ULL 
                                            | (((QData)((IData)(
                                                                (vlSelf->top__DOT__inst 
                                                                 >> 0x1fU))) 
                                                << 0x3bU) 
                                               | (((QData)((IData)(
                                                                   (0xffU 
                                                                    & (vlSelf->top__DOT__inst 
                                                                       >> 0xcU)))) 
                                                   << 0x33U) 
                                                  | (((QData)((IData)(
                                                                      (1U 
                                                                       & (vlSelf->top__DOT__inst 
                                                                          >> 0x14U)))) 
                                                      << 0x32U) 
                                                     | (((QData)((IData)(
                                                                         (0x3ffU 
                                                                          & (vlSelf->top__DOT__inst 
                                                                             >> 0x15U)))) 
                                                         << 0x28U) 
                                                        | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0))))))));
        __Vtemp_h6749d75c__0[1U] = (((- (IData)((vlSelf->top__DOT__inst 
                                                 >> 0x1fU))) 
                                     << 0x1cU) | (IData)(
                                                         ((0x6700000000ULL 
                                                           | (((QData)((IData)(
                                                                               (vlSelf->top__DOT__inst 
                                                                                >> 0x1fU))) 
                                                               << 0x3bU) 
                                                              | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (vlSelf->top__DOT__inst 
                                                                                >> 0xcU)))) 
                                                                  << 0x33U) 
                                                                 | (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->top__DOT__inst 
                                                                                >> 0x14U)))) 
                                                                     << 0x32U) 
                                                                    | (((QData)((IData)(
                                                                                (0x3ffU 
                                                                                & (vlSelf->top__DOT__inst 
                                                                                >> 0x15U)))) 
                                                                        << 0x28U) 
                                                                       | (QData)((IData)(vlSelf->__VdfgTmp_h441be388__0))))))) 
                                                          >> 0x20U)));
        __Vtemp_h6749d75c__0[2U] = (0x3780U | ((0xffffc000U 
                                                & (((- (IData)(
                                                               (vlSelf->top__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0x1aU) 
                                                   | (0x3ffc000U 
                                                      & (vlSelf->top__DOT__inst 
                                                         >> 6U)))) 
                                               | (0x7fU 
                                                  & ((- (IData)(
                                                                (vlSelf->top__DOT__inst 
                                                                 >> 0x1fU))) 
                                                     >> 4U))));
        __Vtemp_h6749d75c__0[3U] = (0x4c000U | (0x3fffU 
                                                & ((- (IData)(
                                                              (vlSelf->top__DOT__inst 
                                                               >> 0x1fU))) 
                                                   >> 6U)));
        __Vtemp_h6749d75c__0[4U] = (0x6e00000U | (0x1ffffeU 
                                                  & (vlSelf->top__DOT__inst 
                                                     >> 0xbU)));
        __Vtemp_h6749d75c__0[5U] = (0x70000000U | (0xfffff00U 
                                                   & (vlSelf->top__DOT__inst 
                                                      >> 4U)));
        __Vtemp_h6749d75c__0[6U] = 1U;
        bufp->chgWData(oldp+26,(__Vtemp_h6749d75c__0),195);
        bufp->chgQData(oldp+33,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+35,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+37,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+39,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgQData(oldp+41,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
        bufp->chgIData(oldp+65,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
        bufp->chgIData(oldp+67,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
        bufp->chgIData(oldp+68,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
        bufp->chgIData(oldp+69,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
        bufp->chgIData(oldp+70,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
        bufp->chgIData(oldp+71,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
        bufp->chgIData(oldp+72,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
        bufp->chgIData(oldp+74,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
        bufp->chgIData(oldp+75,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
        bufp->chgIData(oldp+76,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
        bufp->chgIData(oldp+77,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
        bufp->chgIData(oldp+78,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
        bufp->chgIData(oldp+79,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
        bufp->chgIData(oldp+80,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
        bufp->chgIData(oldp+81,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+82,(vlSelf->clk));
    bufp->chgBit(oldp+83,(vlSelf->rst));
    bufp->chgIData(oldp+84,(vlSelf->top__DOT__pc),32);
    bufp->chgIData(oldp+85,(((IData)(vlSelf->top__DOT__alu_a_sel)
                              ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                              : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->chgIData(oldp+86,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
    bufp->chgIData(oldp+87,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
    bufp->chgIData(oldp+88,(vlSelf->top__DOT__exu0__DOT__rf_wdata),32);
    bufp->chgIData(oldp+89,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                            [(0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0xfU))]),32);
    bufp->chgIData(oldp+90,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                            [(0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0x14U))]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
