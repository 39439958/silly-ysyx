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
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[5]),7);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[6]),7);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[7]),7);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[8]),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__inst),32);
        bufp->chgBit(oldp+10,(((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_U) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__inst)) 
                                     | (IData)(vlSelf->top__DOT__idu0__DOT__is_R))))));
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__rf_wr_sel),2);
        bufp->chgBit(oldp+12,(vlSelf->top__DOT__do_jump));
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__BrType),3);
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__alu_a_sel));
        bufp->chgBit(oldp+15,((1U & (~ (IData)(vlSelf->top__DOT__idu0__DOT__is_R)))));
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__alu_ctrl),4);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__imm),32);
        bufp->chgCData(oldp+18,(vlSelf->top__DOT__dm_rd_sel),3);
        bufp->chgCData(oldp+19,(((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                                  ? 1U : ((IData)((0x1023U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->top__DOT__inst)))
                                           ? 2U : ((IData)(
                                                           (0x2023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->top__DOT__inst)))
                                                    ? 3U
                                                    : 0U)))),2);
        bufp->chgCData(oldp+20,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+21,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+22,((0x1fU & (vlSelf->top__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+23,((0x7fU & vlSelf->top__DOT__inst)),7);
        bufp->chgCData(oldp+24,((7U & (vlSelf->top__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+25,((vlSelf->top__DOT__inst 
                                 >> 0x19U)),7);
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__idu0__DOT__is_addi));
        bufp->chgBit(oldp+27,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+28,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+29,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
        bufp->chgBit(oldp+30,(vlSelf->top__DOT__idu0__DOT__is_jalr));
        bufp->chgBit(oldp+31,((IData)((0x2023U == (0x707fU 
                                                   & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+32,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
        bufp->chgBit(oldp+33,(vlSelf->top__DOT__idu0__DOT__is_sltiu));
        bufp->chgBit(oldp+34,(vlSelf->top__DOT__idu0__DOT__is_sub));
        bufp->chgBit(oldp+35,(vlSelf->top__DOT__idu0__DOT__is_add));
        bufp->chgBit(oldp+36,(vlSelf->top__DOT__idu0__DOT__is_xor));
        bufp->chgBit(oldp+37,(vlSelf->top__DOT__idu0__DOT__is_sltu));
        bufp->chgBit(oldp+38,(vlSelf->top__DOT__idu0__DOT__is_srai));
        bufp->chgBit(oldp+39,(vlSelf->top__DOT__idu0__DOT__is_beq));
        bufp->chgBit(oldp+40,(vlSelf->top__DOT__idu0__DOT__is_bne));
        bufp->chgBit(oldp+41,(vlSelf->top__DOT__idu0__DOT__is_blt));
        bufp->chgBit(oldp+42,(vlSelf->top__DOT__idu0__DOT__is_bge));
        bufp->chgBit(oldp+43,(vlSelf->top__DOT__idu0__DOT__is_bltu));
        bufp->chgBit(oldp+44,(vlSelf->top__DOT__idu0__DOT__is_bgeu));
        bufp->chgBit(oldp+45,(vlSelf->top__DOT__idu0__DOT__is_lbu));
        bufp->chgBit(oldp+46,(vlSelf->top__DOT__idu0__DOT__is_lw));
        bufp->chgBit(oldp+47,((IData)((0x1023U == (0x707fU 
                                                   & vlSelf->top__DOT__inst)))));
        bufp->chgBit(oldp+48,(((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->top__DOT__inst)) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                        | ((IData)(vlSelf->top__DOT__idu0__DOT__is_S) 
                                           | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw) 
                                              | (((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                                        | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                                           | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                                              | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu)))))) 
                                                 | (IData)(vlSelf->top__DOT__idu0__DOT__is_add))))))))));
        bufp->chgBit(oldp+49,(vlSelf->top__DOT__idu0__DOT__is_I));
        bufp->chgBit(oldp+50,(vlSelf->top__DOT__idu0__DOT__is_U));
        bufp->chgBit(oldp+51,(vlSelf->top__DOT__idu0__DOT__is_R));
        bufp->chgBit(oldp+52,(vlSelf->top__DOT__idu0__DOT__is_S));
        bufp->chgBit(oldp+53,(((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                        | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                           | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu))))))));
        bufp->chgWData(oldp+54,(vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3),351);
        bufp->chgQData(oldp+65,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+67,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+69,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+71,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgQData(oldp+73,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
        bufp->chgQData(oldp+75,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[5]),39);
        bufp->chgQData(oldp+77,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[6]),39);
        bufp->chgQData(oldp+79,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[7]),39);
        bufp->chgQData(oldp+81,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[8]),39);
        bufp->chgIData(oldp+83,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+84,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+85,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+86,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+87,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+88,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[5]),32);
        bufp->chgIData(oldp+89,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[6]),32);
        bufp->chgIData(oldp+90,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[7]),32);
        bufp->chgIData(oldp+91,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[8]),32);
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+93,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+94,((1U & (((4U & (IData)(vlSelf->top__DOT__BrType))
                                       ? ((2U & (IData)(vlSelf->top__DOT__BrType))
                                           ? ((1U & (IData)(vlSelf->top__DOT__BrType))
                                               ? ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                   >> 0x1fU)
                                                   ? 
                                                  ((~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0))
                                                   : 
                                                  ((~ 
                                                    (vlSelf->top__DOT__exu0__DOT__rs2 
                                                     >> 0x1fU)) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)))
                                               : ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                   >> 0x1fU)
                                                   ? 
                                                  ((vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))
                                                   : 
                                                  ((vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU) 
                                                   | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))))
                                           : ((1U & (IData)(vlSelf->top__DOT__BrType))
                                               ? (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)
                                               : (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0)))
                                       : (((IData)(vlSelf->top__DOT__BrType) 
                                           >> 1U) & 
                                          ((1U & (IData)(vlSelf->top__DOT__BrType))
                                            ? (vlSelf->top__DOT__exu0__DOT__rs1 
                                               != vlSelf->top__DOT__exu0__DOT__rs2)
                                            : (vlSelf->top__DOT__exu0__DOT__rs1 
                                               == vlSelf->top__DOT__exu0__DOT__rs2)))) 
                                     | (IData)(vlSelf->top__DOT__do_jump)))));
        bufp->chgIData(oldp+95,(((IData)(vlSelf->top__DOT__alu_a_sel)
                                  ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                                  : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
        bufp->chgBit(oldp+96,((1U & ((4U & (IData)(vlSelf->top__DOT__BrType))
                                      ? ((2U & (IData)(vlSelf->top__DOT__BrType))
                                          ? ((1U & (IData)(vlSelf->top__DOT__BrType))
                                              ? ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                  >> 0x1fU)
                                                  ? 
                                                 ((~ 
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU)) 
                                                  | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0))
                                                  : 
                                                 ((~ 
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU)) 
                                                  & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)))
                                              : ((vlSelf->top__DOT__exu0__DOT__rs1 
                                                  >> 0x1fU)
                                                  ? 
                                                 ((vlSelf->top__DOT__exu0__DOT__rs2 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))
                                                  : 
                                                 ((vlSelf->top__DOT__exu0__DOT__rs2 
                                                   >> 0x1fU) 
                                                  | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))))
                                          : ((1U & (IData)(vlSelf->top__DOT__BrType))
                                              ? (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)
                                              : (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0)))
                                      : (((IData)(vlSelf->top__DOT__BrType) 
                                          >> 1U) & 
                                         ((1U & (IData)(vlSelf->top__DOT__BrType))
                                           ? (vlSelf->top__DOT__exu0__DOT__rs1 
                                              != vlSelf->top__DOT__exu0__DOT__rs2)
                                           : (vlSelf->top__DOT__exu0__DOT__rs1 
                                              == vlSelf->top__DOT__exu0__DOT__rs2)))))));
        bufp->chgIData(oldp+97,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
        bufp->chgIData(oldp+98,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b),32);
        bufp->chgIData(oldp+99,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
        bufp->chgIData(oldp+100,(((2U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                   ? ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                       ? vlSelf->top__DOT__exu0__DOT__dm_data
                                       : vlSelf->top__DOT__exu0__DOT__alu_out)
                                   : ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                       ? ((IData)(4U) 
                                          + vlSelf->top__DOT__pc)
                                       : 0U))),32);
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__exu0__DOT__rs1),32);
        bufp->chgIData(oldp+102,(vlSelf->top__DOT__exu0__DOT__rs2),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+103,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+104,(vlSelf->top__DOT__exu0__DOT__dm_data),32);
        bufp->chgIData(oldp+105,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
        bufp->chgIData(oldp+106,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
        bufp->chgIData(oldp+107,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
        bufp->chgIData(oldp+109,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
        bufp->chgIData(oldp+110,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
        bufp->chgIData(oldp+111,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
        bufp->chgIData(oldp+112,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
        bufp->chgIData(oldp+113,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
        bufp->chgIData(oldp+114,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
        bufp->chgIData(oldp+115,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
        bufp->chgIData(oldp+119,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
        bufp->chgIData(oldp+120,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
        bufp->chgIData(oldp+121,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
        bufp->chgIData(oldp+123,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
        bufp->chgIData(oldp+124,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
        bufp->chgIData(oldp+125,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
        bufp->chgIData(oldp+126,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
        bufp->chgIData(oldp+127,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
        bufp->chgIData(oldp+128,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
        bufp->chgIData(oldp+129,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
        bufp->chgIData(oldp+130,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
        bufp->chgIData(oldp+131,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
        bufp->chgIData(oldp+132,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
        bufp->chgIData(oldp+133,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
        bufp->chgIData(oldp+134,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
        bufp->chgIData(oldp+135,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
        bufp->chgIData(oldp+136,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+137,(vlSelf->clk));
    bufp->chgBit(oldp+138,(vlSelf->rst));
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
