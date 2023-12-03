// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+65,"inst", false,-1, 31,0);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBus(c+65,"inst", false,-1, 31,0);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->declBit(c+67,"rf_wr_en", false,-1);
    tracep->declBit(c+6,"rf_wr_sel", false,-1);
    tracep->declBit(c+6,"do_jump", false,-1);
    tracep->declBit(c+7,"alu_a_sel", false,-1);
    tracep->declBit(c+92,"alu_b_sel", false,-1);
    tracep->declBus(c+8,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+9,"imm", false,-1, 31,0);
    tracep->declBus(c+68,"jump_addr", false,-1, 31,0);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBus(c+65,"inst", false,-1, 31,0);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->declBit(c+67,"rf_wr_en", false,-1);
    tracep->declBit(c+6,"rf_wr_sel", false,-1);
    tracep->declBit(c+7,"alu_a_sel", false,-1);
    tracep->declBit(c+92,"alu_b_sel", false,-1);
    tracep->declBus(c+8,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+9,"imm", false,-1, 31,0);
    tracep->declBus(c+68,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+69,"alu_a", false,-1, 31,0);
    tracep->declBus(c+70,"alu_b", false,-1, 31,0);
    tracep->declBus(c+71,"alu_out", false,-1, 31,0);
    tracep->declBus(c+72,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+73,"rs1", false,-1, 31,0);
    tracep->declBus(c+74,"rs2", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+69,"SrcA", false,-1, 31,0);
    tracep->declBus(c+70,"SrcB", false,-1, 31,0);
    tracep->declBus(c+8,"func", false,-1, 3,0);
    tracep->declBus(c+71,"ALUout", false,-1, 31,0);
    tracep->declBus(c+69,"signed_a", false,-1, 31,0);
    tracep->declBus(c+70,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+67,"rf_wr_en", false,-1);
    tracep->declBus(c+75,"waddr", false,-1, 4,0);
    tracep->declBus(c+72,"wdata", false,-1, 31,0);
    tracep->declBus(c+76,"raddr1", false,-1, 4,0);
    tracep->declBus(c+77,"raddr2", false,-1, 4,0);
    tracep->declBus(c+73,"rdata1", false,-1, 31,0);
    tracep->declBus(c+74,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+31+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+65,"inst", false,-1, 31,0);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->declBit(c+67,"rf_wr_en", false,-1);
    tracep->declBit(c+6,"rf_wr_sel", false,-1);
    tracep->declBit(c+6,"do_jump", false,-1);
    tracep->declBit(c+7,"alu_a_sel", false,-1);
    tracep->declBit(c+92,"alu_b_sel", false,-1);
    tracep->declBus(c+8,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+9,"imm", false,-1, 31,0);
    tracep->declBus(c+78,"op", false,-1, 6,0);
    tracep->declBus(c+79,"funct", false,-1, 2,0);
    tracep->declBit(c+10,"is_addi", false,-1);
    tracep->declBit(c+80,"is_auipc", false,-1);
    tracep->declBit(c+81,"is_lui", false,-1);
    tracep->declBit(c+82,"is_jal", false,-1);
    tracep->declBit(c+11,"is_jalr", false,-1);
    tracep->declBit(c+83,"is_sw", false,-1);
    tracep->declBit(c+12,"is_ebreak", false,-1);
    tracep->declBit(c+84,"is_add_type", false,-1);
    tracep->declBit(c+13,"is_I", false,-1);
    tracep->declBit(c+80,"is_U", false,-1);
    tracep->declBit(c+82,"is_J", false,-1);
    tracep->declBit(c+93,"is_R", false,-1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBus(c+65,"inst", false,-1, 31,0);
    tracep->declBus(c+9,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("mux0 ");
    tracep->declBus(c+94,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+95,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+96,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+9,"out", false,-1, 31,0);
    tracep->declBus(c+78,"key", false,-1, 6,0);
    tracep->declArray(c+85,"lut", false,-1, 194,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+94,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+95,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+96,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+97,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+9,"out", false,-1, 31,0);
    tracep->declBus(c+78,"key", false,-1, 6,0);
    tracep->declBus(c+98,"default_out", false,-1, 31,0);
    tracep->declArray(c+85,"lut", false,-1, 194,0);
    tracep->declBus(c+99,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+14+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+24+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+29,"lut_out", false,-1, 31,0);
    tracep->declBit(c+30,"hit", false,-1);
    tracep->declBus(c+100,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+63,"clk", false,-1);
    tracep->declBit(c+64,"rst", false,-1);
    tracep->declBit(c+6,"jump", false,-1);
    tracep->declBus(c+68,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+66,"pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<7>/*223:0*/ __Vtemp_h3075430c__0;
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4]),7);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__rf_wr_sel));
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__alu_a_sel));
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__alu_ctrl),4);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__imm),32);
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__idu0__DOT__is_addi));
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__idu0__DOT__is_jalr));
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__idu0__DOT__is_I));
    bufp->fullQData(oldp+14,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+16,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+18,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+20,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+22,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+30,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+63,(vlSelf->clk));
    bufp->fullBit(oldp+64,(vlSelf->rst));
    bufp->fullIData(oldp+65,(vlSelf->inst),32);
    bufp->fullIData(oldp+66,(vlSelf->pc),32);
    bufp->fullBit(oldp+67,(((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                            | ((0x17U == (0x7fU & vlSelf->inst)) 
                               | (0x6fU == (0x7fU & vlSelf->inst))))));
    bufp->fullIData(oldp+68,(((IData)(vlSelf->top__DOT__alu_a_sel)
                               ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                               : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
    bufp->fullIData(oldp+72,(((IData)(vlSelf->top__DOT__rf_wr_sel)
                               ? ((IData)(4U) + vlSelf->pc)
                               : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0x14U))]),32);
    bufp->fullCData(oldp+75,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+76,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+77,((0x1fU & (vlSelf->inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+78,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+79,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullBit(oldp+80,((0x17U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+81,((0x37U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+82,((0x6fU == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+83,((IData)((0x2023U == (0x707fU 
                                                & vlSelf->inst)))));
    bufp->fullBit(oldp+84,(((IData)(vlSelf->top__DOT__idu0__DOT__is_addi) 
                            | ((0x17U == (0x7fU & vlSelf->inst)) 
                               | (IData)(vlSelf->top__DOT__rf_wr_sel)))));
    __Vtemp_h3075430c__0[0U] = (IData)((0x6700000000ULL 
                                        | (((QData)((IData)(
                                                            (vlSelf->inst 
                                                             >> 0x1fU))) 
                                            << 0x3bU) 
                                           | (((QData)((IData)(
                                                               (0xffU 
                                                                & (vlSelf->inst 
                                                                   >> 0xcU)))) 
                                               << 0x33U) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & (vlSelf->inst 
                                                                      >> 0x14U)))) 
                                                  << 0x32U) 
                                                 | (((QData)((IData)(
                                                                     (0x3ffU 
                                                                      & (vlSelf->inst 
                                                                         >> 0x15U)))) 
                                                     << 0x28U) 
                                                    | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0))))))));
    __Vtemp_h3075430c__0[1U] = (((- (IData)((vlSelf->inst 
                                             >> 0x1fU))) 
                                 << 0x1cU) | (IData)(
                                                     ((0x6700000000ULL 
                                                       | (((QData)((IData)(
                                                                           (vlSelf->inst 
                                                                            >> 0x1fU))) 
                                                           << 0x3bU) 
                                                          | (((QData)((IData)(
                                                                              (0xffU 
                                                                               & (vlSelf->inst 
                                                                                >> 0xcU)))) 
                                                              << 0x33U) 
                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->inst 
                                                                                >> 0x14U)))) 
                                                                 << 0x32U) 
                                                                | (((QData)((IData)(
                                                                                (0x3ffU 
                                                                                & (vlSelf->inst 
                                                                                >> 0x15U)))) 
                                                                    << 0x28U) 
                                                                   | (QData)((IData)(vlSelf->__VdfgTmp_h6ea4ae17__0))))))) 
                                                      >> 0x20U)));
    __Vtemp_h3075430c__0[2U] = (0x3780U | ((0xffffc000U 
                                            & (((- (IData)(
                                                           (vlSelf->inst 
                                                            >> 0x1fU))) 
                                                << 0x1aU) 
                                               | (0x3ffc000U 
                                                  & (vlSelf->inst 
                                                     >> 6U)))) 
                                           | (0x7fU 
                                              & ((- (IData)(
                                                            (vlSelf->inst 
                                                             >> 0x1fU))) 
                                                 >> 4U))));
    __Vtemp_h3075430c__0[3U] = (0x4c000U | (0x3fffU 
                                            & ((- (IData)(
                                                          (vlSelf->inst 
                                                           >> 0x1fU))) 
                                               >> 6U)));
    __Vtemp_h3075430c__0[4U] = (0x6e00000U | (0x1ffffeU 
                                              & (vlSelf->inst 
                                                 >> 0xbU)));
    __Vtemp_h3075430c__0[5U] = (0x70000000U | (0xfffff00U 
                                               & (vlSelf->inst 
                                                  >> 4U)));
    __Vtemp_h3075430c__0[6U] = 1U;
    bufp->fullWData(oldp+85,(__Vtemp_h3075430c__0),195);
    bufp->fullBit(oldp+92,((1U & (~ (IData)(vlSelf->top__DOT__idu0__DOT__is_R)))));
    bufp->fullBit(oldp+93,(vlSelf->top__DOT__idu0__DOT__is_R));
    bufp->fullIData(oldp+94,(5U),32);
    bufp->fullIData(oldp+95,(7U),32);
    bufp->fullIData(oldp+96,(0x20U),32);
    bufp->fullIData(oldp+97,(0U),32);
    bufp->fullIData(oldp+98,(0U),32);
    bufp->fullIData(oldp+99,(0x27U),32);
    bufp->fullIData(oldp+100,(5U),32);
}
