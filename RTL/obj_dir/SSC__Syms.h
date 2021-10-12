// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_SSC__SYMS_H_
#define VERILATED_SSC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "SSC.h"

// INCLUDE MODULE CLASSES
#include "SSC___024root.h"

// SYMS CLASS (contains all model state)
class SSC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    SSC* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    SSC___024root                  TOP;

    // CONSTRUCTORS
    SSC__Syms(VerilatedContext* contextp, const char* namep, SSC* modelp);
    ~SSC__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
