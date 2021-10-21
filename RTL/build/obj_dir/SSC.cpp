// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "SSC.h"
#include "SSC__Syms.h"

//============================================================
// Constructors

SSC::SSC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new SSC__Syms(_vcontextp__, _vcname__, this)}
    , original_clk{vlSymsp->TOP.original_clk}
    , rst{vlSymsp->TOP.rst}
    , leds{vlSymsp->TOP.leds}
    , rootp{&(vlSymsp->TOP)}
{
}

SSC::SSC(const char* _vcname__)
    : SSC(nullptr, _vcname__)
{
}

//============================================================
// Destructor

SSC::~SSC() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void SSC___024root___eval_initial(SSC___024root* vlSelf);
void SSC___024root___eval_settle(SSC___024root* vlSelf);
void SSC___024root___eval(SSC___024root* vlSelf);
#ifdef VL_DEBUG
void SSC___024root___eval_debug_assertions(SSC___024root* vlSelf);
#endif  // VL_DEBUG
void SSC___024root___final(SSC___024root* vlSelf);

static void _eval_initial_loop(SSC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    SSC___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        SSC___024root___eval_settle(&(vlSymsp->TOP));
        SSC___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void SSC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate SSC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    SSC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        SSC___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Invoke final blocks

void SSC::final() {
    SSC___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* SSC::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* SSC::name() const {
    return vlSymsp->name();
}
