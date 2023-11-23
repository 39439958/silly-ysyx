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
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBit(c+37,"rf_wr_en", false,-1);
    tracep->declBit(c+38,"is_ebreak", false,-1);
    tracep->declBus(c+39,"inst_rs1", false,-1, 4,0);
    tracep->declBus(c+40,"inst_rd", false,-1, 4,0);
    tracep->declBus(c+41,"inst_imm", false,-1, 31,0);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+37,"rf_wr_en", false,-1);
    tracep->declBit(c+38,"is_ebreak", false,-1);
    tracep->declBus(c+39,"rs1", false,-1, 4,0);
    tracep->declBus(c+40,"rd", false,-1, 4,0);
    tracep->declBus(c+41,"imm", false,-1, 31,0);
    tracep->declBus(c+42,"alu_a", false,-1, 31,0);
    tracep->declBus(c+43,"alu_out", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+42,"SrcA", false,-1, 31,0);
    tracep->declBus(c+41,"SrcB", false,-1, 31,0);
    tracep->declBus(c+47,"func", false,-1, 3,0);
    tracep->declBus(c+43,"ALUout", false,-1, 31,0);
    tracep->declBus(c+42,"signed_a", false,-1, 31,0);
    tracep->declBus(c+41,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+37,"rf_wr_en", false,-1);
    tracep->declBus(c+40,"waddr", false,-1, 4,0);
    tracep->declBus(c+43,"wdata", false,-1, 31,0);
    tracep->declBus(c+39,"raddr", false,-1, 4,0);
    tracep->declBus(c+42,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBit(c+37,"rf_wr_en", false,-1);
    tracep->declBit(c+38,"is_ebreak", false,-1);
    tracep->declBus(c+39,"inst_rs1", false,-1, 4,0);
    tracep->declBus(c+40,"inst_rd", false,-1, 4,0);
    tracep->declBus(c+41,"inst_imm", false,-1, 31,0);
    tracep->declBus(c+44,"op", false,-1, 6,0);
    tracep->declBus(c+45,"funct", false,-1, 2,0);
    tracep->declBus(c+46,"imm", false,-1, 11,0);
    tracep->declBit(c+37,"is_addi", false,-1);
    tracep->declBit(c+37,"is_I", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+33,(vlSelf->clk));
    bufp->fullBit(oldp+34,(vlSelf->rst));
    bufp->fullIData(oldp+35,(vlSelf->inst),32);
    bufp->fullIData(oldp+36,(vlSelf->pc),32);
    bufp->fullBit(oldp+37,((IData)((0x13U == (0x707fU 
                                              & vlSelf->inst)))));
    bufp->fullBit(oldp+38,(vlSelf->top__DOT__is_ebreak));
    bufp->fullCData(oldp+39,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+40,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+41,((((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->inst 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->fullIData(oldp+43,((vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))] 
                              + (((- (IData)((vlSelf->inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->inst 
                                              >> 0x14U)))),32);
    bufp->fullCData(oldp+44,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+45,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullSData(oldp+46,((vlSelf->inst >> 0x14U)),12);
    bufp->fullCData(oldp+47,(0U),4);
}
