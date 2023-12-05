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
    tracep->declBit(c+126,"clk", false,-1);
    tracep->declBit(c+127,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+126,"clk", false,-1);
    tracep->declBit(c+127,"rst", false,-1);
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+93,"pc", false,-1, 31,0);
    tracep->declBit(c+85,"jump", false,-1);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+13,"do_jump", false,-1);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+130,"alu_b_sel", false,-1);
    tracep->declBus(c+16,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+17,"imm", false,-1, 31,0);
    tracep->declBus(c+18,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+19,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+86,"jump_addr", false,-1, 31,0);
    tracep->declBit(c+87,"BrE", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+126,"clk", false,-1);
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+93,"pc", false,-1, 31,0);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+130,"alu_b_sel", false,-1);
    tracep->declBus(c+16,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+17,"imm", false,-1, 31,0);
    tracep->declBus(c+18,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+19,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+87,"BrE", false,-1);
    tracep->declBus(c+86,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+88,"alu_a", false,-1, 31,0);
    tracep->declBus(c+89,"alu_b", false,-1, 31,0);
    tracep->declBus(c+90,"alu_out", false,-1, 31,0);
    tracep->declBus(c+128,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+91,"rs1", false,-1, 31,0);
    tracep->declBus(c+92,"rs2", false,-1, 31,0);
    tracep->declBus(c+129,"dm_data", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+88,"SrcA", false,-1, 31,0);
    tracep->declBus(c+89,"SrcB", false,-1, 31,0);
    tracep->declBus(c+16,"func", false,-1, 3,0);
    tracep->declBus(c+90,"ALUout", false,-1, 31,0);
    tracep->declBus(c+88,"signed_a", false,-1, 31,0);
    tracep->declBus(c+89,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branch0 ");
    tracep->declBus(c+91,"REG1", false,-1, 31,0);
    tracep->declBus(c+92,"REG2", false,-1, 31,0);
    tracep->declBus(c+14,"Type", false,-1, 2,0);
    tracep->declBit(c+87,"BrE", false,-1);
    tracep->declBus(c+91,"signed_REG1", false,-1, 31,0);
    tracep->declBus(c+92,"signed_REG2", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+126,"clk", false,-1);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+20,"waddr", false,-1, 4,0);
    tracep->declBus(c+128,"wdata", false,-1, 31,0);
    tracep->declBus(c+21,"raddr1", false,-1, 4,0);
    tracep->declBus(c+22,"raddr2", false,-1, 4,0);
    tracep->declBus(c+91,"rdata1", false,-1, 31,0);
    tracep->declBus(c+92,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+94+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+93,"pc", false,-1, 31,0);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+13,"do_jump", false,-1);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+130,"alu_b_sel", false,-1);
    tracep->declBus(c+16,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+18,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+19,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+17,"imm", false,-1, 31,0);
    tracep->declBus(c+23,"op", false,-1, 6,0);
    tracep->declBus(c+24,"funct", false,-1, 2,0);
    tracep->declBit(c+25,"is_addi", false,-1);
    tracep->declBit(c+26,"is_auipc", false,-1);
    tracep->declBit(c+27,"is_lui", false,-1);
    tracep->declBit(c+28,"is_jal", false,-1);
    tracep->declBit(c+29,"is_jalr", false,-1);
    tracep->declBit(c+30,"is_sw", false,-1);
    tracep->declBit(c+31,"is_ebreak", false,-1);
    tracep->declBit(c+32,"is_sltiu", false,-1);
    tracep->declBit(c+33,"is_beq", false,-1);
    tracep->declBit(c+34,"is_bne", false,-1);
    tracep->declBit(c+35,"is_blt", false,-1);
    tracep->declBit(c+36,"is_bge", false,-1);
    tracep->declBit(c+37,"is_bltu", false,-1);
    tracep->declBit(c+38,"is_bgeu", false,-1);
    tracep->declBit(c+131,"is_lb", false,-1);
    tracep->declBit(c+132,"is_lbu", false,-1);
    tracep->declBit(c+133,"is_lh", false,-1);
    tracep->declBit(c+134,"is_lhu", false,-1);
    tracep->declBit(c+39,"is_lw", false,-1);
    tracep->declBit(c+135,"is_sb", false,-1);
    tracep->declBit(c+136,"is_sh", false,-1);
    tracep->declBit(c+40,"is_add_type", false,-1);
    tracep->declBit(c+41,"is_I", false,-1);
    tracep->declBit(c+42,"is_U", false,-1);
    tracep->declBit(c+28,"is_J", false,-1);
    tracep->declBit(c+137,"is_R", false,-1);
    tracep->declBit(c+43,"is_S", false,-1);
    tracep->declBit(c+44,"is_B", false,-1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+17,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("mux0 ");
    tracep->declBus(c+138,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+139,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+140,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+17,"out", false,-1, 31,0);
    tracep->declBus(c+23,"key", false,-1, 6,0);
    tracep->declArray(c+45,"lut", false,-1, 350,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+138,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+139,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+140,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+141,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+17,"out", false,-1, 31,0);
    tracep->declBus(c+23,"key", false,-1, 6,0);
    tracep->declBus(c+142,"default_out", false,-1, 31,0);
    tracep->declArray(c+45,"lut", false,-1, 350,0);
    tracep->declBus(c+143,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 9; ++i) {
        tracep->declQuad(c+56+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 9; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 9; ++i) {
        tracep->declBus(c+74+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+83,"lut_out", false,-1, 31,0);
    tracep->declBit(c+84,"hit", false,-1);
    tracep->declBus(c+144,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+126,"clk", false,-1);
    tracep->declBit(c+127,"rst", false,-1);
    tracep->declBit(c+85,"jump", false,-1);
    tracep->declBus(c+86,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+93,"pc", false,-1, 31,0);
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
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[8]),7);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__inst),32);
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__rf_wr_en));
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__rf_wr_sel),2);
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__do_jump));
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__BrType),3);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__alu_a_sel));
    bufp->fullCData(oldp+16,(vlSelf->top__DOT__alu_ctrl),4);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+18,(((IData)(vlSelf->top__DOT__idu0__DOT__is_lb)
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
    bufp->fullCData(oldp+19,(((IData)(vlSelf->top__DOT__idu0__DOT__is_sb)
                               ? 1U : ((IData)(vlSelf->top__DOT__idu0__DOT__is_sh)
                                        ? 2U : ((IData)(
                                                        (0x2023U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->top__DOT__inst)))
                                                 ? 3U
                                                 : 0U)))),2);
    bufp->fullCData(oldp+20,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+21,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+22,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+23,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullCData(oldp+24,((7U & (vlSelf->top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+25,(vlSelf->top__DOT__idu0__DOT__is_addi));
    bufp->fullBit(oldp+26,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+27,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+28,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__idu0__DOT__is_jalr));
    bufp->fullBit(oldp+30,((IData)((0x2023U == (0x707fU 
                                                & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__idu0__DOT__is_sltiu));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__idu0__DOT__is_beq));
    bufp->fullBit(oldp+34,(vlSelf->top__DOT__idu0__DOT__is_bne));
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__idu0__DOT__is_blt));
    bufp->fullBit(oldp+36,(vlSelf->top__DOT__idu0__DOT__is_bge));
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__idu0__DOT__is_bltu));
    bufp->fullBit(oldp+38,(vlSelf->top__DOT__idu0__DOT__is_bgeu));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__idu0__DOT__is_lw));
    bufp->fullBit(oldp+40,(vlSelf->top__DOT__idu0__DOT__is_add_type));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__idu0__DOT__is_I));
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__idu0__DOT__is_U));
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__idu0__DOT__is_S));
    bufp->fullBit(oldp+44,(((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                        | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu))))))));
    bufp->fullWData(oldp+45,(vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3),351);
    bufp->fullQData(oldp+56,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+58,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+60,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+62,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+64,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullQData(oldp+66,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[5]),39);
    bufp->fullQData(oldp+68,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[6]),39);
    bufp->fullQData(oldp+70,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[7]),39);
    bufp->fullQData(oldp+72,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[8]),39);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+76,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+77,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+78,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[5]),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[6]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[7]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[8]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+84,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+85,((1U & (((4U & (IData)(vlSelf->top__DOT__BrType))
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
                                                   == vlSelf->top__DOT__exu0__DOT__rs2)))) 
                                  | (IData)(vlSelf->top__DOT__do_jump)))));
    bufp->fullIData(oldp+86,(((IData)(vlSelf->top__DOT__alu_a_sel)
                               ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                               : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->fullBit(oldp+87,((1U & ((4U & (IData)(vlSelf->top__DOT__BrType))
                                   ? ((2U & (IData)(vlSelf->top__DOT__BrType))
                                       ? ((1U & (IData)(vlSelf->top__DOT__BrType))
                                           ? ((vlSelf->top__DOT__exu0__DOT__rs1 
                                               >> 0x1fU)
                                               ? ((~ 
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU)) 
                                                  | (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0))
                                               : ((~ 
                                                   (vlSelf->top__DOT__exu0__DOT__rs2 
                                                    >> 0x1fU)) 
                                                  & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h27b9220a__0)))
                                           : ((vlSelf->top__DOT__exu0__DOT__rs1 
                                               >> 0x1fU)
                                               ? ((vlSelf->top__DOT__exu0__DOT__rs2 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->top__DOT__exu0__DOT__branch0__DOT____VdfgExtracted_h2387256d__0))
                                               : ((vlSelf->top__DOT__exu0__DOT__rs2 
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
                                                  == vlSelf->top__DOT__exu0__DOT__rs2)))))));
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__exu0__DOT__rs1),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__exu0__DOT__rs2),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+126,(vlSelf->clk));
    bufp->fullBit(oldp+127,(vlSelf->rst));
    bufp->fullIData(oldp+128,(((2U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                ? ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? vlSelf->top__DOT__exu0__DOT__dm_data
                                    : vlSelf->top__DOT__exu0__DOT__alu_out)
                                : ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? ((IData)(4U) 
                                       + vlSelf->top__DOT__pc)
                                    : 0U))),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__exu0__DOT__dm_data),32);
    bufp->fullBit(oldp+130,((1U & (~ (IData)(vlSelf->top__DOT__idu0__DOT__is_R)))));
    bufp->fullBit(oldp+131,(vlSelf->top__DOT__idu0__DOT__is_lb));
    bufp->fullBit(oldp+132,(vlSelf->top__DOT__idu0__DOT__is_lbu));
    bufp->fullBit(oldp+133,(vlSelf->top__DOT__idu0__DOT__is_lh));
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__idu0__DOT__is_lhu));
    bufp->fullBit(oldp+135,(vlSelf->top__DOT__idu0__DOT__is_sb));
    bufp->fullBit(oldp+136,(vlSelf->top__DOT__idu0__DOT__is_sh));
    bufp->fullBit(oldp+137,(vlSelf->top__DOT__idu0__DOT__is_R));
    bufp->fullIData(oldp+138,(9U),32);
    bufp->fullIData(oldp+139,(7U),32);
    bufp->fullIData(oldp+140,(0x20U),32);
    bufp->fullIData(oldp+141,(0U),32);
    bufp->fullIData(oldp+142,(0U),32);
    bufp->fullIData(oldp+143,(0x27U),32);
    bufp->fullIData(oldp+144,(9U),32);
}
