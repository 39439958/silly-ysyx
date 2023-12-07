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
    tracep->declBit(c+151,"clk", false,-1);
    tracep->declBit(c+152,"rst", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+151,"clk", false,-1);
    tracep->declBit(c+152,"rst", false,-1);
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBit(c+108,"jump", false,-1);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+13,"do_jump", false,-1);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+16,"alu_b_sel", false,-1);
    tracep->declBus(c+17,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+18,"imm", false,-1, 31,0);
    tracep->declBus(c+19,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+20,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+109,"jump_addr", false,-1, 31,0);
    tracep->declBit(c+110,"BrE", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+151,"clk", false,-1);
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+16,"alu_b_sel", false,-1);
    tracep->declBus(c+17,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+18,"imm", false,-1, 31,0);
    tracep->declBus(c+19,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+20,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+110,"BrE", false,-1);
    tracep->declBus(c+109,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+111,"alu_a", false,-1, 31,0);
    tracep->declBus(c+112,"alu_b", false,-1, 31,0);
    tracep->declBus(c+113,"alu_out", false,-1, 31,0);
    tracep->declBus(c+114,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+115,"rs1", false,-1, 31,0);
    tracep->declBus(c+116,"rs2", false,-1, 31,0);
    tracep->declBus(c+118,"dm_data", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+111,"SrcA", false,-1, 31,0);
    tracep->declBus(c+112,"SrcB", false,-1, 31,0);
    tracep->declBus(c+17,"func", false,-1, 3,0);
    tracep->declBus(c+113,"ALUout", false,-1, 31,0);
    tracep->declBus(c+111,"signed_a", false,-1, 31,0);
    tracep->declBus(c+112,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branch0 ");
    tracep->declBus(c+115,"REG1", false,-1, 31,0);
    tracep->declBus(c+116,"REG2", false,-1, 31,0);
    tracep->declBus(c+14,"Type", false,-1, 2,0);
    tracep->declBit(c+110,"BrE", false,-1);
    tracep->declBus(c+115,"signed_REG1", false,-1, 31,0);
    tracep->declBus(c+116,"signed_REG2", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+151,"clk", false,-1);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+21,"waddr", false,-1, 4,0);
    tracep->declBus(c+114,"wdata", false,-1, 31,0);
    tracep->declBus(c+22,"raddr1", false,-1, 4,0);
    tracep->declBus(c+23,"raddr2", false,-1, 4,0);
    tracep->declBus(c+115,"rdata1", false,-1, 31,0);
    tracep->declBus(c+116,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+119+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
    tracep->declBit(c+11,"rf_wr_en", false,-1);
    tracep->declBus(c+12,"rf_wr_sel", false,-1, 1,0);
    tracep->declBit(c+13,"do_jump", false,-1);
    tracep->declBus(c+14,"BrType", false,-1, 2,0);
    tracep->declBit(c+15,"alu_a_sel", false,-1);
    tracep->declBit(c+16,"alu_b_sel", false,-1);
    tracep->declBus(c+17,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+19,"dm_rd_sel", false,-1, 2,0);
    tracep->declBus(c+20,"dm_wr_sel", false,-1, 1,0);
    tracep->declBus(c+18,"imm", false,-1, 31,0);
    tracep->declBus(c+24,"op", false,-1, 6,0);
    tracep->declBus(c+25,"funct3", false,-1, 2,0);
    tracep->declBus(c+26,"funct7", false,-1, 6,0);
    tracep->declBit(c+27,"is_addi", false,-1);
    tracep->declBit(c+28,"is_xori", false,-1);
    tracep->declBit(c+29,"is_srai", false,-1);
    tracep->declBit(c+30,"is_andi", false,-1);
    tracep->declBit(c+31,"is_srli", false,-1);
    tracep->declBit(c+32,"is_slli", false,-1);
    tracep->declBit(c+33,"is_auipc", false,-1);
    tracep->declBit(c+34,"is_lui", false,-1);
    tracep->declBit(c+35,"is_jal", false,-1);
    tracep->declBit(c+36,"is_jalr", false,-1);
    tracep->declBit(c+37,"is_ebreak", false,-1);
    tracep->declBit(c+38,"is_sltiu", false,-1);
    tracep->declBit(c+39,"is_sub", false,-1);
    tracep->declBit(c+40,"is_add", false,-1);
    tracep->declBit(c+41,"is_xor", false,-1);
    tracep->declBit(c+42,"is_sltu", false,-1);
    tracep->declBit(c+43,"is_slt", false,-1);
    tracep->declBit(c+44,"is_and", false,-1);
    tracep->declBit(c+45,"is_sll", false,-1);
    tracep->declBit(c+46,"is_sra", false,-1);
    tracep->declBit(c+47,"is_or", false,-1);
    tracep->declBit(c+48,"is_beq", false,-1);
    tracep->declBit(c+49,"is_bne", false,-1);
    tracep->declBit(c+50,"is_blt", false,-1);
    tracep->declBit(c+51,"is_bge", false,-1);
    tracep->declBit(c+52,"is_bltu", false,-1);
    tracep->declBit(c+53,"is_bgeu", false,-1);
    tracep->declBit(c+54,"is_lb", false,-1);
    tracep->declBit(c+55,"is_lbu", false,-1);
    tracep->declBit(c+56,"is_lh", false,-1);
    tracep->declBit(c+57,"is_lhu", false,-1);
    tracep->declBit(c+58,"is_lw", false,-1);
    tracep->declBit(c+59,"is_sb", false,-1);
    tracep->declBit(c+60,"is_sh", false,-1);
    tracep->declBit(c+61,"is_sw", false,-1);
    tracep->declBit(c+62,"is_add_type", false,-1);
    tracep->declBit(c+63,"is_I", false,-1);
    tracep->declBit(c+64,"is_U", false,-1);
    tracep->declBit(c+35,"is_J", false,-1);
    tracep->declBit(c+65,"is_R", false,-1);
    tracep->declBit(c+66,"is_S", false,-1);
    tracep->declBit(c+67,"is_B", false,-1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBus(c+10,"inst", false,-1, 31,0);
    tracep->declBus(c+18,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("mux0 ");
    tracep->declBus(c+153,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+154,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+18,"out", false,-1, 31,0);
    tracep->declBus(c+24,"key", false,-1, 6,0);
    tracep->declArray(c+68,"lut", false,-1, 350,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+153,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+154,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+155,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+156,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+18,"out", false,-1, 31,0);
    tracep->declBus(c+24,"key", false,-1, 6,0);
    tracep->declBus(c+157,"default_out", false,-1, 31,0);
    tracep->declArray(c+68,"lut", false,-1, 350,0);
    tracep->declBus(c+158,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 9; ++i) {
        tracep->declQuad(c+79+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 9; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 9; ++i) {
        tracep->declBus(c+97+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+106,"lut_out", false,-1, 31,0);
    tracep->declBit(c+107,"hit", false,-1);
    tracep->declBus(c+159,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+151,"clk", false,-1);
    tracep->declBit(c+152,"rst", false,-1);
    tracep->declBit(c+108,"jump", false,-1);
    tracep->declBus(c+109,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+117,"pc", false,-1, 31,0);
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
    bufp->fullBit(oldp+11,(((IData)(vlSelf->top__DOT__idu0__DOT__is_I) 
                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_U) 
                               | ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__inst)) 
                                  | (IData)(vlSelf->top__DOT__idu0__DOT__is_R))))));
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__rf_wr_sel),2);
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__do_jump));
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__BrType),3);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__alu_a_sel));
    bufp->fullBit(oldp+16,((1U & (~ (IData)(vlSelf->top__DOT__idu0__DOT__is_R)))));
    bufp->fullCData(oldp+17,(vlSelf->top__DOT__alu_ctrl),4);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+19,(vlSelf->top__DOT__dm_rd_sel),3);
    bufp->fullCData(oldp+20,(((IData)((0x23U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)))
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
    bufp->fullCData(oldp+21,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+22,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+23,((0x1fU & (vlSelf->top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+24,((0x7fU & vlSelf->top__DOT__inst)),7);
    bufp->fullCData(oldp+25,((7U & (vlSelf->top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+26,((vlSelf->top__DOT__inst 
                              >> 0x19U)),7);
    bufp->fullBit(oldp+27,(vlSelf->top__DOT__idu0__DOT__is_addi));
    bufp->fullBit(oldp+28,(vlSelf->top__DOT__idu0__DOT__is_xori));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__idu0__DOT__is_srai));
    bufp->fullBit(oldp+30,(vlSelf->top__DOT__idu0__DOT__is_andi));
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__idu0__DOT__is_srli));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__idu0__DOT__is_slli));
    bufp->fullBit(oldp+33,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+34,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+35,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
    bufp->fullBit(oldp+36,(vlSelf->top__DOT__idu0__DOT__is_jalr));
    bufp->fullBit(oldp+37,(vlSelf->top__DOT__idu0__DOT__is_ebreak));
    bufp->fullBit(oldp+38,(vlSelf->top__DOT__idu0__DOT__is_sltiu));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__idu0__DOT__is_sub));
    bufp->fullBit(oldp+40,(vlSelf->top__DOT__idu0__DOT__is_add));
    bufp->fullBit(oldp+41,(vlSelf->top__DOT__idu0__DOT__is_xor));
    bufp->fullBit(oldp+42,(vlSelf->top__DOT__idu0__DOT__is_sltu));
    bufp->fullBit(oldp+43,(vlSelf->top__DOT__idu0__DOT__is_slt));
    bufp->fullBit(oldp+44,(vlSelf->top__DOT__idu0__DOT__is_and));
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__idu0__DOT__is_sll));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__idu0__DOT__is_sra));
    bufp->fullBit(oldp+47,(vlSelf->top__DOT__idu0__DOT__is_or));
    bufp->fullBit(oldp+48,(vlSelf->top__DOT__idu0__DOT__is_beq));
    bufp->fullBit(oldp+49,(vlSelf->top__DOT__idu0__DOT__is_bne));
    bufp->fullBit(oldp+50,(vlSelf->top__DOT__idu0__DOT__is_blt));
    bufp->fullBit(oldp+51,(vlSelf->top__DOT__idu0__DOT__is_bge));
    bufp->fullBit(oldp+52,(vlSelf->top__DOT__idu0__DOT__is_bltu));
    bufp->fullBit(oldp+53,(vlSelf->top__DOT__idu0__DOT__is_bgeu));
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__idu0__DOT__is_lb));
    bufp->fullBit(oldp+55,(vlSelf->top__DOT__idu0__DOT__is_lbu));
    bufp->fullBit(oldp+56,(vlSelf->top__DOT__idu0__DOT__is_lh));
    bufp->fullBit(oldp+57,(vlSelf->top__DOT__idu0__DOT__is_lhu));
    bufp->fullBit(oldp+58,(vlSelf->top__DOT__idu0__DOT__is_lw));
    bufp->fullBit(oldp+59,((IData)((0x23U == (0x707fU 
                                              & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+60,((IData)((0x1023U == (0x707fU 
                                                & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+61,((IData)((0x2023U == (0x707fU 
                                                & vlSelf->top__DOT__inst)))));
    bufp->fullBit(oldp+62,(((0x17U == (0x7fU & vlSelf->top__DOT__inst)) 
                            | ((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_jalr) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_S) 
                                     | (((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                                         | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                                     | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu)))))) 
                                        | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lb) 
                                           | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lbu) 
                                              | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lh) 
                                                 | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lhu) 
                                                    | ((IData)(vlSelf->top__DOT__idu0__DOT__is_lw) 
                                                       | ((IData)(vlSelf->top__DOT__idu0__DOT__is_add) 
                                                          | (IData)(vlSelf->top__DOT__idu0__DOT__is_addi))))))))))))));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__idu0__DOT__is_I));
    bufp->fullBit(oldp+64,(vlSelf->top__DOT__idu0__DOT__is_U));
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__idu0__DOT__is_R));
    bufp->fullBit(oldp+66,(vlSelf->top__DOT__idu0__DOT__is_S));
    bufp->fullBit(oldp+67,(((IData)(vlSelf->top__DOT__idu0__DOT__is_beq) 
                            | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bne) 
                               | ((IData)(vlSelf->top__DOT__idu0__DOT__is_blt) 
                                  | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bge) 
                                     | ((IData)(vlSelf->top__DOT__idu0__DOT__is_bltu) 
                                        | (IData)(vlSelf->top__DOT__idu0__DOT__is_bgeu))))))));
    bufp->fullWData(oldp+68,(vlSelf->top__DOT__idu0__DOT__imm0__DOT____Vcellinp__mux0____pinNumber3),351);
    bufp->fullQData(oldp+79,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+81,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+83,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+85,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+87,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullQData(oldp+89,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[5]),39);
    bufp->fullQData(oldp+91,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[6]),39);
    bufp->fullQData(oldp+93,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[7]),39);
    bufp->fullQData(oldp+95,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[8]),39);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[5]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[6]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[7]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[8]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+107,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+108,((1U & (((4U & (IData)(vlSelf->top__DOT__BrType))
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
                                         >> 1U) & (
                                                   (1U 
                                                    & (IData)(vlSelf->top__DOT__BrType))
                                                    ? 
                                                   (vlSelf->top__DOT__exu0__DOT__rs1 
                                                    != vlSelf->top__DOT__exu0__DOT__rs2)
                                                    : 
                                                   (vlSelf->top__DOT__exu0__DOT__rs1 
                                                    == vlSelf->top__DOT__exu0__DOT__rs2)))) 
                                   | (IData)(vlSelf->top__DOT__do_jump)))));
    bufp->fullIData(oldp+109,(((IData)(vlSelf->top__DOT__alu_a_sel)
                                ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu_out)
                                : vlSelf->top__DOT__exu0__DOT__alu_out)),32);
    bufp->fullBit(oldp+110,((1U & ((4U & (IData)(vlSelf->top__DOT__BrType))
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
                                                   == vlSelf->top__DOT__exu0__DOT__rs2)))))));
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_a),32);
    bufp->fullIData(oldp+112,(vlSelf->top__DOT__exu0__DOT__alu0__DOT__signed_b),32);
    bufp->fullIData(oldp+113,(vlSelf->top__DOT__exu0__DOT__alu_out),32);
    bufp->fullIData(oldp+114,(((2U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                ? ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? vlSelf->top__DOT__exu0__DOT__dm_data
                                    : vlSelf->top__DOT__exu0__DOT__alu_out)
                                : ((1U & (IData)(vlSelf->top__DOT__rf_wr_sel))
                                    ? ((IData)(4U) 
                                       + vlSelf->top__DOT__pc)
                                    : 0U))),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__exu0__DOT__rs1),32);
    bufp->fullIData(oldp+116,(vlSelf->top__DOT__exu0__DOT__rs2),32);
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__exu0__DOT__dm_data),32);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+120,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+124,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+125,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+126,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+127,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+129,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+130,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+131,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+132,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+134,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+136,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+137,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+142,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+143,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+145,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+146,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+147,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+148,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+149,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+150,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+151,(vlSelf->clk));
    bufp->fullBit(oldp+152,(vlSelf->rst));
    bufp->fullIData(oldp+153,(9U),32);
    bufp->fullIData(oldp+154,(7U),32);
    bufp->fullIData(oldp+155,(0x20U),32);
    bufp->fullIData(oldp+156,(0U),32);
    bufp->fullIData(oldp+157,(0U),32);
    bufp->fullIData(oldp+158,(0x27U),32);
    bufp->fullIData(oldp+159,(9U),32);
}
