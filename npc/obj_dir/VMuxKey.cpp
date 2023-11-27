// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMuxKey.h"
#include "VMuxKey__Syms.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VMuxKey::VMuxKey(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMuxKey__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , out{vlSymsp->TOP.out}
    , key{vlSymsp->TOP.key}
    , default_out{vlSymsp->TOP.default_out}
    , lut{vlSymsp->TOP.lut}
    , rst{vlSymsp->TOP.rst}
    , inst{vlSymsp->TOP.inst}
    , pc{vlSymsp->TOP.pc}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VMuxKey::VMuxKey(const char* _vcname__)
    : VMuxKey(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMuxKey::~VMuxKey() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMuxKey___024root___eval_debug_assertions(VMuxKey___024root* vlSelf);
#endif  // VL_DEBUG
void VMuxKey___024root___eval_static(VMuxKey___024root* vlSelf);
void VMuxKey___024root___eval_initial(VMuxKey___024root* vlSelf);
void VMuxKey___024root___eval_settle(VMuxKey___024root* vlSelf);
void VMuxKey___024root___eval(VMuxKey___024root* vlSelf);

void VMuxKey::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMuxKey::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMuxKey___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMuxKey___024root___eval_static(&(vlSymsp->TOP));
        VMuxKey___024root___eval_initial(&(vlSymsp->TOP));
        VMuxKey___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMuxKey___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMuxKey::eventsPending() { return false; }

uint64_t VMuxKey::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMuxKey::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMuxKey___024root___eval_final(VMuxKey___024root* vlSelf);

VL_ATTR_COLD void VMuxKey::final() {
    VMuxKey___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMuxKey::hierName() const { return vlSymsp->name(); }
const char* VMuxKey::modelName() const { return "VMuxKey"; }
unsigned VMuxKey::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VMuxKey::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VMuxKey___024root__trace_init_top(VMuxKey___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VMuxKey___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMuxKey___024root*>(voidSelf);
    VMuxKey__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VMuxKey___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VMuxKey___024root__trace_register(VMuxKey___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VMuxKey::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VMuxKey::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VMuxKey___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
