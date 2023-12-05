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
    tracep->declBit(c+104,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+104,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBus(c+9,"inst", false,-1, 31,0);
    tracep->declBus(c+106,"pc", false,-1, 31,0);
    tracep->declBit(c+10,"rf_wr_en", false,-1);
    tracep->declBus(c+11,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+12,"do_jump", false,-1);
    tracep->declBit(c+13,"alu_a_sel", false,-1);
    tracep->declBit(c+115,"alu_b_sel", false,-1);
    tracep->declBus(c+14,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+15,"imm", false,-1, 31,0);
    tracep->declBus(c+16,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+17,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+107,"jump_addr", false,-1, 31,0);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+104,"clk", false,-1);
    tracep->declBus(c+9,"inst", false,-1, 31,0);
    tracep->declBus(c+106,"pc", false,-1, 31,0);
    tracep->declBit(c+10,"rf_wr_en", false,-1);
    tracep->declBus(c+11,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+13,"alu_a_sel", false,-1);
    tracep->declBit(c+115,"alu_b_sel", false,-1);
    tracep->declBus(c+14,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+15,"imm", false,-1, 31,0);
    tracep->declBus(c+16,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+17,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+107,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+108,"alu_a", false,-1, 31,0);
    tracep->declBus(c+109,"alu_b", false,-1, 31,0);
    tracep->declBus(c+110,"alu_out", false,-1, 31,0);
    tracep->declBus(c+111,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+112,"rs1", false,-1, 31,0);
    tracep->declBus(c+113,"rs2", false,-1, 31,0);
    tracep->declBus(c+114,"dm_data", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+108,"SrcA", false,-1, 31,0);
    tracep->declBus(c+109,"SrcB", false,-1, 31,0);
    tracep->declBus(c+14,"func", false,-1, 3,0);
    tracep->declBus(c+110,"ALUout", false,-1, 31,0);
    tracep->declBus(c+108,"signed_a", false,-1, 31,0);
    tracep->declBus(c+109,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+104,"clk", false,-1);
    tracep->declBit(c+10,"rf_wr_en", false,-1);
    tracep->declBus(c+18,"waddr", false,-1, 4,0);
    tracep->declBus(c+111,"wdata", false,-1, 31,0);
    tracep->declBus(c+19,"raddr1", false,-1, 4,0);
    tracep->declBus(c+20,"raddr2", false,-1, 4,0);
    tracep->declBus(c+112,"rdata1", false,-1, 31,0);
    tracep->declBus(c+113,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+72+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+9,"inst", false,-1, 31,0);
    tracep->declBus(c+106,"pc", false,-1, 31,0);
    tracep->declBit(c+10,"rf_wr_en", false,-1);
    tracep->declBus(c+11,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+12,"do_jump", false,-1);
    tracep->declBit(c+13,"alu_a_sel", false,-1);
    tracep->declBit(c+115,"alu_b_sel", false,-1);
    tracep->declBus(c+14,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+16,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+17,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+15,"imm", false,-1, 31,0);
    tracep->declBus(c+21,"op", false,-1, 6,0);
    tracep->declBus(c+22,"funct", false,-1, 2,0);
    tracep->declBit(c+23,"is_addi", false,-1);
    tracep->declBit(c+24,"is_auipc", false,-1);
    tracep->declBit(c+25,"is_lui", false,-1);
    tracep->declBit(c+26,"is_jal", false,-1);
    tracep->declBit(c+27,"is_jalr", false,-1);
    tracep->declBit(c+28,"is_sw", false,-1);
    tracep->declBit(c+29,"is_ebreak", false,-1);
    tracep->declBit(c+30,"is_sltiu", false,-1);
    tracep->declBit(c+116,"is_lb", false,-1);
    tracep->declBit(c+117,"is_lbu", false,-1);
    tracep->declBit(c+118,"is_lh", false,-1);
    tracep->declBit(c+119,"is_lhu", false,-1);
    tracep->declBit(c+31,"is_lw", false,-1);
    tracep->declBit(c+120,"is_sb", false,-1);
    tracep->declBit(c+121,"is_sh", false,-1);
    tracep->declBit(c+32,"is_add_type", false,-1);
    tracep->declBit(c+33,"is_I", false,-1);
    tracep->declBit(c+34,"is_U", false,-1);
    tracep->declBit(c+26,"is_J", false,-1);
    tracep->declBit(c+122,"is_R", false,-1);
    tracep->declBit(c+35,"is_S", false,-1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBus(c+9,"inst", false,-1, 31,0);
    tracep->declBus(c+15,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("mux0 ");
    tracep->declBus(c+123,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+124,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+125,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+15,"out", false,-1, 31,0);
    tracep->declBus(c+21,"key", false,-1, 6,0);
    tracep->declArray(c+36,"lut", false,-1, 311,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+123,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+124,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+125,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+126,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+15,"out", false,-1, 31,0);
    tracep->declBus(c+21,"key", false,-1, 6,0);
    tracep->declBus(c+127,"default_out", false,-1, 31,0);
    tracep->declArray(c+36,"lut", false,-1, 311,0);
    tracep->declBus(c+128,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declQuad(c+46+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+62+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+70,"lut_out", false,-1, 31,0);
    tracep->declBit(c+71,"hit", false,-1);
    tracep->declBus(c+129,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+104,"clk", false,-1);
    tracep->declBit(c+105,"rst", false,-1);
    tracep->declBit(c+12,"jump", false,-1);
    tracep->declBus(c+107,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+106,"pc", false,-1, 31,0);
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
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4]),7);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[5]),7);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[6]),7);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[7]),7);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__inst),32);
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__rf_wr_en));
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__rf_wr_sel),2);
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__do_jump));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__alu_a_sel));
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__alu_ctrl),4);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+16,(((IData)(vlSelf->top__DOT__idu0__DOT__is_lb)
                               ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_lbu)
                                        ? 2U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_lh)
                                                 ? 3U
                                                 : 
                                                ((IData)(vlSelf->top__DOT__idu0__DOT__is_lhu)
                                                  ? 4U
                                                  : 
                                                 ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw)
                                                   ? 5U
                                                   : 0U)))))),3);
    bufp->fullCData(oldp+17,(((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                               ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_sh)
                                        ? 2U : ((IData)(
                                                        (0x2023U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->top__DOT__inst)))
                                                 ? 3U
                                                 : 0U)))),2);
    bufp->fullCData(oldp+18,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+19,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+20,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+21,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullCData(oldp+22,((7U & (vlSelf->top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__idu0__DOT__is_addi));
    bufp->fullBit(oldp+24,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+25,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+26,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+27,(vlSelf->top__DOT__idu0__DOT__is_jalr));
    bufp->fullBit(oldp+28,((IData)((0x2023U == (0x707fU 
                                                & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
    bufp->fullBit(oldp+30,(vlSelf->top__DOT__idu0__DOT__is_sltiu));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__idu0__DOT__is_lw));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__idu0__DOT__is_add_type));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__idu0__DOT__is_I));
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__idu0__DOT__is_U));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__idu0__DOT__is_S));
    bufp->fullWData(oldp+36,(vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3),312);
    bufp->fullQData(oldp+46,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+48,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+50,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+52,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+54,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullQData(oldp+56,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[5]),39);
    bufp->fullQData(oldp+58,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[6]),39);
    bufp->fullQData(oldp+60,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[7]),39);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[5]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[6]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[7]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+71,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+104,(vlSelf->clk));
    bufp->fullBit(oldp+105,(vlSelf->rst));
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+107,(((IData)(vlSelf->top__DOT__alu_a_sel)
                                ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                                : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
    bufp->fullIData(oldp+111,(((2U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                ? ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? vlSelf->top__DOT__exu0__DOT__dm_data
                                    : vlSelf->top__DOT__exu0__DOT__alu_out)
                                : ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? ((IData)(4U) 
                                       + vlSelf->top__DOT__pc)
                                    : 0U))),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                              [(0x1fU & (vlSelf->top__DOT__inst 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                              [(0x1fU & (vlSelf->top__DOT__inst 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__exu0__DOT__dm_data),32);
    bufp->fullBit(oldp+115,((1U & (~ (IData)(vlSelf->top__DOT__idu0__DOT__is_R)))));
    bufp->fullBit(oldp+116,(vlSelf->top__DOT__idu0__DOT__is_lb));
    bufp->fullBit(oldp+117,(vlSelf->top__DOT__idu0__DOT__is_lbu));
    bufp->fullBit(oldp+118,(vlSelf->top__DOT__idu0__DOT__is_lh));
    bufp->fullBit(oldp+119,(vlSelf->top__DOT__idu0__DOT__is_lhu));
    bufp->fullBit(oldp+120,(vlSelf->top__DOT__idu0__DOT__is_sb));
    bufp->fullBit(oldp+121,(vlSelf->top__DOT__idu0__DOT__is_sh));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__idu0__DOT__is_R));
    bufp->fullIData(oldp+123,(8U),32);
    bufp->fullIData(oldp+124,(7U),32);
    bufp->fullIData(oldp+125,(0x20U),32);
    bufp->fullIData(oldp+126,(0U),32);
    bufp->fullIData(oldp+127,(0U),32);
    bufp->fullIData(oldp+128,(0x27U),32);
    bufp->fullIData(oldp+129,(8U),32);
}
