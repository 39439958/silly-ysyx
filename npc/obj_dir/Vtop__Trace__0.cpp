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
    VlWide<5>/*159:0*/ __Vtemp_hcabd2efd__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__alu_a_sel));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__is_ebreak));
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__inst_imm),32);
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__do_jump));
        bufp->chgBit(oldp+8,(vlSelf->top__DOT__idu0__DOT__is_jalr));
        bufp->chgQData(oldp+9,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+11,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+13,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+15,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+55,(vlSelf->clk));
    bufp->chgBit(oldp+56,(vlSelf->rst));
    bufp->chgIData(oldp+57,(vlSelf->inst),32);
    bufp->chgIData(oldp+58,(vlSelf->pc),32);
    bufp->chgIData(oldp+59,(((IData)(vlSelf->top__DOT__alu_a_sel)
                              ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)
                              : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)),32);
    bufp->chgBit(oldp+60,(((IData)(vlSelf->top__DOT__alu_a_sel) 
                           | (0x17U == (0x7fU & vlSelf->inst)))));
    bufp->chgIData(oldp+61,(((IData)(vlSelf->top__DOT__alu_a_sel)
                              ? vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))] : vlSelf->pc)),32);
    bufp->chgIData(oldp+62,(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0),32);
    bufp->chgIData(oldp+63,(((IData)(vlSelf->top__DOT__do_jump)
                              ? ((IData)(4U) + vlSelf->pc)
                              : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)),32);
    bufp->chgIData(oldp+64,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                            [(0x1fU & (vlSelf->inst 
                                       >> 0xfU))]),32);
    bufp->chgCData(oldp+65,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+66,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+67,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+68,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgBit(oldp+69,((IData)((0x13U == (0x707fU 
                                             & vlSelf->inst)))));
    bufp->chgBit(oldp+70,((0x17U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+71,((0x37U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+72,((0x6fU == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+73,((IData)((0x2023U == (0x707fU 
                                               & vlSelf->inst)))));
    __Vtemp_hcabd2efd__0[0U] = (IData)((0x6700000000ULL 
                                        | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0))));
    __Vtemp_hcabd2efd__0[1U] = ((0xffffff80U & (((- (IData)(
                                                            (vlSelf->inst 
                                                             >> 0x1fU))) 
                                                 << 0x13U) 
                                                | (0x7ff80U 
                                                   & (vlSelf->inst 
                                                      >> 0xdU)))) 
                                | (IData)(((0x6700000000ULL 
                                            | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0))) 
                                           >> 0x20U)));
    __Vtemp_hcabd2efd__0[2U] = (0x980U | ((0xfc000000U 
                                           & (vlSelf->inst 
                                              << 0xeU)) 
                                          | (0x7fU 
                                             & ((- (IData)(
                                                           (vlSelf->inst 
                                                            >> 0x1fU))) 
                                                >> 0xdU))));
    __Vtemp_hcabd2efd__0[3U] = (0xdc000U | (0x3ffffffU 
                                            & (vlSelf->inst 
                                               >> 0x12U)));
    __Vtemp_hcabd2efd__0[4U] = (0x2e00000U | (0x1ffffeU 
                                              & (vlSelf->inst 
                                                 >> 0xbU)));
    bufp->chgWData(oldp+74,(__Vtemp_hcabd2efd__0),156);
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
