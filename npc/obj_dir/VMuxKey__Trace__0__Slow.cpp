// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMuxKey__Syms.h"


VL_ATTR_COLD void VMuxKey___024root__trace_init_sub__TOP__0(VMuxKey___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+68,"out", false,-1, 0,0);
    tracep->declBus(c+69,"key", false,-1, 0,0);
    tracep->declBus(c+70,"default_out", false,-1, 0,0);
    tracep->declBus(c+71,"lut", false,-1, 3,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declBus(c+75,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKeyWithDefault ");
    tracep->declBus(c+98,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+99,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+99,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+68,"out", false,-1, 0,0);
    tracep->declBus(c+69,"key", false,-1, 0,0);
    tracep->declBus(c+70,"default_out", false,-1, 0,0);
    tracep->declBus(c+71,"lut", false,-1, 3,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+98,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+99,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+99,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+99,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+68,"out", false,-1, 0,0);
    tracep->declBus(c+69,"key", false,-1, 0,0);
    tracep->declBus(c+70,"default_out", false,-1, 0,0);
    tracep->declBus(c+71,"lut", false,-1, 3,0);
    tracep->declBus(c+98,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"pair_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+3+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+5+i*1,"data_list", true,(i+0), 0,0);
    }
    tracep->declBus(c+7,"lut_out", false,-1, 0,0);
    tracep->declBit(c+8,"hit", false,-1);
    tracep->declBus(c+100,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declBus(c+75,"pc", false,-1, 31,0);
    tracep->declBus(c+76,"jump_addr", false,-1, 31,0);
    tracep->declBit(c+77,"rf_wr_en", false,-1);
    tracep->declBit(c+9,"alu_a_sel", false,-1);
    tracep->declBit(c+10,"is_ebreak", false,-1);
    tracep->declBus(c+11,"inst_imm", false,-1, 31,0);
    tracep->declBit(c+12,"do_jump", false,-1);
    tracep->declBit(c+12,"rf_wr_sel", false,-1);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+77,"rf_wr_en", false,-1);
    tracep->declBit(c+10,"is_ebreak", false,-1);
    tracep->declBit(c+9,"alu_a_sel", false,-1);
    tracep->declBit(c+12,"rf_wr_sel", false,-1);
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declBus(c+75,"pc", false,-1, 31,0);
    tracep->declBus(c+11,"imm", false,-1, 31,0);
    tracep->declBus(c+76,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+78,"alu_a", false,-1, 31,0);
    tracep->declBus(c+79,"alu_out", false,-1, 31,0);
    tracep->declBus(c+80,"rf_wdata", false,-1, 31,0);
    tracep->declBus(c+81,"rs1", false,-1, 31,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBus(c+78,"SrcA", false,-1, 31,0);
    tracep->declBus(c+11,"SrcB", false,-1, 31,0);
    tracep->declBus(c+101,"func", false,-1, 3,0);
    tracep->declBus(c+79,"ALUout", false,-1, 31,0);
    tracep->declBus(c+78,"signed_a", false,-1, 31,0);
    tracep->declBus(c+11,"signed_b", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile0 ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+82,"waddr", false,-1, 4,0);
    tracep->declBit(c+77,"rf_wr_en", false,-1);
    tracep->declBus(c+80,"wdata", false,-1, 31,0);
    tracep->declBus(c+83,"raddr", false,-1, 4,0);
    tracep->declBus(c+81,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+36+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declBus(c+75,"pc", false,-1, 31,0);
    tracep->declBit(c+77,"rf_wr_en", false,-1);
    tracep->declBit(c+9,"alu_a_sel", false,-1);
    tracep->declBit(c+12,"rf_wr_sel", false,-1);
    tracep->declBit(c+12,"do_jump", false,-1);
    tracep->declBit(c+10,"is_ebreak", false,-1);
    tracep->declBus(c+11,"inst_imm", false,-1, 31,0);
    tracep->declBus(c+84,"op", false,-1, 6,0);
    tracep->declBus(c+85,"funct", false,-1, 2,0);
    tracep->declBit(c+86,"is_addi", false,-1);
    tracep->declBit(c+87,"is_auipc", false,-1);
    tracep->declBit(c+88,"is_lui", false,-1);
    tracep->declBit(c+89,"is_jal", false,-1);
    tracep->declBit(c+13,"is_jalr", false,-1);
    tracep->declBit(c+90,"is_sw", false,-1);
    tracep->declBit(c+9,"is_I", false,-1);
    tracep->declBit(c+87,"is_U", false,-1);
    tracep->declBit(c+89,"is_J", false,-1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBus(c+74,"inst", false,-1, 31,0);
    tracep->declBus(c+11,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("mux0 ");
    tracep->declBus(c+102,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+103,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+104,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+11,"out", false,-1, 31,0);
    tracep->declBus(c+84,"key", false,-1, 6,0);
    tracep->declArray(c+91,"lut", false,-1, 194,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+102,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+103,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+104,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+105,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+11,"out", false,-1, 31,0);
    tracep->declBus(c+84,"key", false,-1, 6,0);
    tracep->declBus(c+106,"default_out", false,-1, 31,0);
    tracep->declArray(c+91,"lut", false,-1, 194,0);
    tracep->declBus(c+107,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+14+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+24+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+29+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+34,"lut_out", false,-1, 31,0);
    tracep->declBit(c+35,"hit", false,-1);
    tracep->declBus(c+108,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(5);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+73,"rst", false,-1);
    tracep->declBit(c+12,"jump", false,-1);
    tracep->declBus(c+76,"jump_addr", false,-1, 31,0);
    tracep->declBus(c+75,"pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VMuxKey___024root__trace_init_top(VMuxKey___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root__trace_init_top\n"); );
    // Body
    VMuxKey___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VMuxKey___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VMuxKey___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VMuxKey___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VMuxKey___024root__trace_register(VMuxKey___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VMuxKey___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VMuxKey___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VMuxKey___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VMuxKey___024root__trace_full_sub_0(VMuxKey___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VMuxKey___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root__trace_full_top_0\n"); );
    // Init
    VMuxKey___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMuxKey___024root*>(voidSelf);
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VMuxKey___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VMuxKey___024root__trace_full_sub_0(VMuxKey___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<7>/*223:0*/ __Vtemp_hc52fc52b__0;
    // Body
    bufp->fullCData(oldp+1,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),2);
    bufp->fullCData(oldp+2,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),2);
    bufp->fullBit(oldp+3,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+4,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+5,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__data_list[0]));
    bufp->fullBit(oldp+6,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__data_list[1]));
    bufp->fullBit(oldp+7,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__lut_out));
    bufp->fullBit(oldp+8,(vlSelf->MuxKeyWithDefault__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__alu_a_sel));
    bufp->fullBit(oldp+10,(vlSelf->top__DOT__is_ebreak));
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__inst_imm),32);
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__do_jump));
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__idu0__DOT__is_jalr));
    bufp->fullQData(oldp+14,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+16,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+18,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+20,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+22,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullCData(oldp+24,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+25,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+26,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+28,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__key_list[4]),7);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__idu0__DOT__imm0__DOT__mux0__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[0]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[1]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[2]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[3]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[4]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[5]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[6]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[7]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[8]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[9]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[10]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[11]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[12]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[13]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[14]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[15]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[16]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[17]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[18]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[19]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[20]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[21]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[22]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[23]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[24]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[25]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[26]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[27]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[28]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[29]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[30]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf[31]),32);
    bufp->fullBit(oldp+68,(vlSelf->out));
    bufp->fullBit(oldp+69,(vlSelf->key));
    bufp->fullBit(oldp+70,(vlSelf->default_out));
    bufp->fullCData(oldp+71,(vlSelf->lut),4);
    bufp->fullBit(oldp+72,(vlSelf->clk));
    bufp->fullBit(oldp+73,(vlSelf->rst));
    bufp->fullIData(oldp+74,(vlSelf->inst),32);
    bufp->fullIData(oldp+75,(vlSelf->pc),32);
    bufp->fullIData(oldp+76,(((IData)(vlSelf->top__DOT__alu_a_sel)
                               ? (0xfffffffeU & vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)
                               : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)),32);
    bufp->fullBit(oldp+77,(((IData)(vlSelf->top__DOT__alu_a_sel) 
                            | (0x17U == (0x7fU & vlSelf->inst)))));
    bufp->fullIData(oldp+78,(((IData)(vlSelf->top__DOT__alu_a_sel)
                               ? vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))]
                               : vlSelf->pc)),32);
    bufp->fullIData(oldp+79,(vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0),32);
    bufp->fullIData(oldp+80,(((IData)(vlSelf->top__DOT__do_jump)
                               ? ((IData)(4U) + vlSelf->pc)
                               : vlSelf->top__DOT__exu0__DOT__alu0__DOT____VdfgExtracted_h56016fc0__0)),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__exu0__DOT__regfile0__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->fullCData(oldp+82,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+83,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+84,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+85,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullBit(oldp+86,((IData)((0x13U == (0x707fU 
                                              & vlSelf->inst)))));
    bufp->fullBit(oldp+87,((0x17U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+88,((0x37U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+89,((0x6fU == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+90,((IData)((0x2023U == (0x707fU 
                                                & vlSelf->inst)))));
    __Vtemp_hc52fc52b__0[0U] = vlSelf->__VdfgTmp_hf08f7ef8__0[0U];
    __Vtemp_hc52fc52b__0[1U] = vlSelf->__VdfgTmp_hf08f7ef8__0[1U];
    __Vtemp_hc52fc52b__0[2U] = vlSelf->__VdfgTmp_hf08f7ef8__0[2U];
    __Vtemp_hc52fc52b__0[3U] = vlSelf->__VdfgTmp_hf08f7ef8__0[3U];
    __Vtemp_hc52fc52b__0[4U] = (0xdc00000U | vlSelf->__VdfgTmp_hf08f7ef8__0[4U]);
    __Vtemp_hc52fc52b__0[5U] = (0xe0000000U | (0x1ffffe00U 
                                               & (vlSelf->inst 
                                                  >> 3U)));
    __Vtemp_hc52fc52b__0[6U] = 2U;
    bufp->fullWData(oldp+91,(__Vtemp_hc52fc52b__0),195);
    bufp->fullIData(oldp+98,(2U),32);
    bufp->fullIData(oldp+99,(1U),32);
    bufp->fullIData(oldp+100,(2U),32);
    bufp->fullCData(oldp+101,(0U),4);
    bufp->fullIData(oldp+102,(5U),32);
    bufp->fullIData(oldp+103,(7U),32);
    bufp->fullIData(oldp+104,(0x20U),32);
    bufp->fullIData(oldp+105,(0U),32);
    bufp->fullIData(oldp+106,(0U),32);
    bufp->fullIData(oldp+107,(0x27U),32);
    bufp->fullIData(oldp+108,(5U),32);
}
