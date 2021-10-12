// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See SSC.h for the primary calling header

#include "verilated.h"

#include "SSC__Syms.h"
#include "SSC___024root.h"

void SSC___024root___ctor_var_reset(SSC___024root* vlSelf);

SSC___024root::SSC___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    SSC___024root___ctor_var_reset(this);
}

void SSC___024root::__Vconfigure(SSC__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

SSC___024root::~SSC___024root() {
}
