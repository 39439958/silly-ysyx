// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMuxKey.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VMuxKey__Syms.h"
#include "VMuxKey___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VMuxKey___024root___dump_triggers__ico(VMuxKey___024root* vlSelf);
#endif  // VL_DEBUG

void VMuxKey___024root___eval_triggers__ico(VMuxKey___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VMuxKey___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMuxKey___024root___dump_triggers__act(VMuxKey___024root* vlSelf);
#endif  // VL_DEBUG

void VMuxKey___024root___eval_triggers__act(VMuxKey___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->top__DOT__is_ebreak) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__is_ebreak));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__top__DOT__is_ebreak 
        = vlSelf->top__DOT__is_ebreak;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VMuxKey___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VMuxKey___024unit____Vdpiimwrap_ebreak_TOP____024unit();

VL_INLINE_OPT void VMuxKey___024root___nba_sequent__TOP__0(VMuxKey___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKey___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->top__DOT__is_ebreak) {
        VMuxKey___024unit____Vdpiimwrap_ebreak_TOP____024unit();
    }
}