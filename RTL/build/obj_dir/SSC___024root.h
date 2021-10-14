// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See SSC.h for the primary calling header

#ifndef VERILATED_SSC___024ROOT_H_
#define VERILATED_SSC___024ROOT_H_  // guard

#include "verilated.h"

class SSC__Syms;
VL_MODULE(SSC___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(original_clk,0,0);
    CData/*0:0*/ SingleCycleCore__DOT__clk;
    VL_IN8(rst,0,0);
    VL_IN8(btn,0,0);
    VL_OUT8(leds,7,0);
    CData/*0:0*/ SingleCycleCore__DOT__RegWrite;
    CData/*0:0*/ SingleCycleCore__DOT__MemWrite;
    CData/*0:0*/ SingleCycleCore__DOT__DebouncerSSC__DOT__Q1;
    CData/*0:0*/ SingleCycleCore__DOT__DebouncerSSC__DOT__Q2;
    CData/*0:0*/ SingleCycleCore__DOT__DebouncerSSC__DOT__Q0;
    CData/*0:0*/ __Vclklast__TOP__original_clk;
    CData/*0:0*/ __Vclklast__TOP__SingleCycleCore__DOT__clk;
    IData/*31:0*/ SingleCycleCore__DOT__Instruction;
    IData/*31:0*/ SingleCycleCore__DOT__ReadData2;
    IData/*31:0*/ SingleCycleCore__DOT__ALUOutput;
    IData/*31:0*/ SingleCycleCore__DOT__rd;
    IData/*31:0*/ SingleCycleCore__DOT__Immediate;
    IData/*31:0*/ SingleCycleCore__DOT__PCNext;
    IData/*31:0*/ SingleCycleCore__DOT__PCtemp;
    IData/*26:0*/ SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter;
    IData/*31:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Simm;
    IData/*31:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Bimm;
    IData/*31:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Uimm;
    IData/*31:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Jimm;
    IData/*31:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Iimm;
    VlUnpacked<IData/*31:0*/, 32> SingleCycleCore__DOT__RegisterFileSCC__DOT__bank;
    VlUnpacked<IData/*31:0*/, 16> SingleCycleCore__DOT__DataMemorySCC__DOT__ram;

    // INTERNAL VARIABLES
    SSC__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    SSC___024root(const char* name);
    ~SSC___024root();
    VL_UNCOPYABLE(SSC___024root);

    // INTERNAL METHODS
    void __Vconfigure(SSC__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
