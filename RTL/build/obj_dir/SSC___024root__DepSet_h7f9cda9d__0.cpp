// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See SSC.h for the primary calling header

#include "verilated.h"

#include "SSC___024root.h"

VL_INLINE_OPT void SSC___024root___sequent__TOP__2(SSC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    SSC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    SSC___024root___sequent__TOP__2\n"); );
    // Init
    IData/*26:0*/ __Vdly__SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter;
    // Body
    __Vdly__SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter 
        = vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter;
    __Vdly__SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter 
        = ((0x752fU <= vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter)
            ? 0U : (0x7ffffffU & ((IData)(1U) + vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter)));
    if ((0x752fU == vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter)) {
        vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q2 
            = vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q1;
        vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q1 
            = vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q0;
        vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q0 
            = vlSelf->btn;
    }
    vlSelf->SingleCycleCore__DOT__clk = ((IData)(vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q1) 
                                         & (~ (IData)(vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__Q2)));
    vlSelf->SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter 
        = __Vdly__SingleCycleCore__DOT__DebouncerSSC__DOT__clock_enable1__DOT__counter;
}

extern const VlUnpacked<IData/*31:0*/, 256> SSC__ConstPool__TABLE_h13652dff_0;
extern const VlUnpacked<CData/*0:0*/, 128> SSC__ConstPool__TABLE_hdba709b1_0;
extern const VlUnpacked<CData/*0:0*/, 128> SSC__ConstPool__TABLE_h74f58f08_0;
extern const VlUnpacked<CData/*0:0*/, 128> SSC__ConstPool__TABLE_ha96005af_0;
extern const VlUnpacked<CData/*0:0*/, 128> SSC__ConstPool__TABLE_h516c5250_0;
extern const VlUnpacked<CData/*0:0*/, 128> SSC__ConstPool__TABLE_h891bc50c_0;
extern const VlUnpacked<CData/*1:0*/, 128> SSC__ConstPool__TABLE_hb121e016_0;
extern const VlUnpacked<CData/*3:0*/, 64> SSC__ConstPool__TABLE_h8d41ffe0_0;

VL_INLINE_OPT void SSC___024root___sequent__TOP__4(SSC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    SSC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    SSC___024root___sequent__TOP__4\n"); );
    // Init
    IData/*31:0*/ SingleCycleCore__DOT__rs2;
    CData/*0:0*/ SingleCycleCore__DOT__ALUSrc;
    CData/*0:0*/ SingleCycleCore__DOT__MemtoReg;
    CData/*0:0*/ SingleCycleCore__DOT__MemRead;
    CData/*0:0*/ SingleCycleCore__DOT__Branch;
    CData/*1:0*/ SingleCycleCore__DOT__ALUOp;
    CData/*3:0*/ SingleCycleCore__DOT__ALUCtrl;
    CData/*4:0*/ SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode;
    CData/*7:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*5:0*/ __Vtableidx3;
    CData/*0:0*/ __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v0;
    CData/*4:0*/ __Vdlyvdim0__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32;
    IData/*31:0*/ __Vdlyvval__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32;
    CData/*0:0*/ __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32;
    CData/*3:0*/ __Vdlyvdim0__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0;
    IData/*31:0*/ __Vdlyvval__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0;
    // Body
    __Vdlyvset__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0 = 0U;
    __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v0 = 0U;
    __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32 = 0U;
    if (vlSelf->SingleCycleCore__DOT__MemWrite) {
        __Vdlyvval__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0 
            = vlSelf->SingleCycleCore__DOT__ReadData2;
        __Vdlyvset__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0 = 1U;
        __Vdlyvdim0__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0 
            = (0xfU & (vlSelf->SingleCycleCore__DOT__ALUOutput 
                       >> 2U));
    }
    if (vlSelf->rst) {
        vlSelf->SingleCycleCore__DOT__PCtemp = 0U;
        __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v0 = 1U;
    } else {
        vlSelf->SingleCycleCore__DOT__PCtemp = vlSelf->SingleCycleCore__DOT__PCNext;
        if (vlSelf->SingleCycleCore__DOT__RegWrite) {
            if ((0U != (0x1fU & (vlSelf->SingleCycleCore__DOT__Instruction 
                                 >> 7U)))) {
                __Vdlyvval__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32 
                    = vlSelf->SingleCycleCore__DOT__rd;
                __Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32 = 1U;
                __Vdlyvdim0__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32 
                    = (0x1fU & (vlSelf->SingleCycleCore__DOT__Instruction 
                                >> 7U));
            }
        }
    }
    if (__Vdlyvset__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0) {
        vlSelf->SingleCycleCore__DOT__DataMemorySCC__DOT__ram[__Vdlyvdim0__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0] 
            = __Vdlyvval__SingleCycleCore__DOT__DataMemorySCC__DOT__ram__v0;
    }
    if (__Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v0) {
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[1U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[2U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[3U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[4U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[5U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[6U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[7U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[8U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[9U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xaU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xbU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xcU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xdU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xeU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0xfU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x10U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x11U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x12U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x13U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x14U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x15U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x16U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x17U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x18U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x19U] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1aU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1bU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1cU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1dU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1eU] = 0U;
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[0x1fU] = 0U;
    }
    if (__Vdlyvset__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32) {
        vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank[__Vdlyvdim0__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32] 
            = __Vdlyvval__SingleCycleCore__DOT__RegisterFileSCC__DOT__bank__v32;
    }
    __Vtableidx1 = (0xffU & (vlSelf->SingleCycleCore__DOT__PCtemp 
                             >> 2U));
    vlSelf->SingleCycleCore__DOT__Instruction = SSC__ConstPool__TABLE_h13652dff_0
        [__Vtableidx1];
    vlSelf->SingleCycleCore__DOT__ReadData2 = vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank
        [(0x1fU & (vlSelf->SingleCycleCore__DOT__Instruction 
                   >> 0x14U))];
    SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode = 
        (0x1fU & (vlSelf->SingleCycleCore__DOT__Instruction 
                  >> 2U));
    if ((8U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) {
        vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Simm 
            = (((- (IData)((vlSelf->SingleCycleCore__DOT__Instruction 
                            >> 0x1fU))) << 0xbU) | 
               ((0x7e0U & (vlSelf->SingleCycleCore__DOT__Instruction 
                           >> 0x14U)) | (0x1fU & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                  >> 7U))));
        vlSelf->SingleCycleCore__DOT__Immediate = vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Simm;
    } else if ((0x18U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) {
        vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Bimm 
            = (((- (IData)((vlSelf->SingleCycleCore__DOT__Instruction 
                            >> 0x1fU))) << 0xcU) | 
               ((0x800U & (vlSelf->SingleCycleCore__DOT__Instruction 
                           << 4U)) | ((0x7e0U & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                  >> 7U)))));
        vlSelf->SingleCycleCore__DOT__Immediate = vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Bimm;
    } else if (((5U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode)) 
                | (0xdU == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode)))) {
        vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Uimm 
            = (0xfffff000U & vlSelf->SingleCycleCore__DOT__Instruction);
        vlSelf->SingleCycleCore__DOT__Immediate = vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Uimm;
    } else if ((0x1bU == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) {
        vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Jimm 
            = (((- (IData)((vlSelf->SingleCycleCore__DOT__Instruction 
                            >> 0x1fU))) << 0x14U) | 
               ((0xff000U & vlSelf->SingleCycleCore__DOT__Instruction) 
                | ((0x800U & (vlSelf->SingleCycleCore__DOT__Instruction 
                              >> 9U)) | (0x7feU & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                   >> 0x14U)))));
        vlSelf->SingleCycleCore__DOT__Immediate = vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Jimm;
    } else if ((((((0U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode)) 
                   | (3U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) 
                  | (4U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) 
                 | (0x19U == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode))) 
                | (0x1cU == (IData)(SingleCycleCore__DOT__ImmGenSCC__DOT__Opcode)))) {
        vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Iimm 
            = (((- (IData)((vlSelf->SingleCycleCore__DOT__Instruction 
                            >> 0x1fU))) << 0xcU) | 
               (vlSelf->SingleCycleCore__DOT__Instruction 
                >> 0x14U));
        vlSelf->SingleCycleCore__DOT__Immediate = vlSelf->SingleCycleCore__DOT__ImmGenSCC__DOT__Iimm;
    } else {
        vlSelf->SingleCycleCore__DOT__Immediate = 0U;
    }
    __Vtableidx2 = (0x7fU & vlSelf->SingleCycleCore__DOT__Instruction);
    SingleCycleCore__DOT__ALUSrc = SSC__ConstPool__TABLE_hdba709b1_0
        [__Vtableidx2];
    SingleCycleCore__DOT__MemtoReg = SSC__ConstPool__TABLE_h74f58f08_0
        [__Vtableidx2];
    vlSelf->SingleCycleCore__DOT__RegWrite = SSC__ConstPool__TABLE_ha96005af_0
        [__Vtableidx2];
    SingleCycleCore__DOT__MemRead = SSC__ConstPool__TABLE_h74f58f08_0
        [__Vtableidx2];
    vlSelf->SingleCycleCore__DOT__MemWrite = SSC__ConstPool__TABLE_h516c5250_0
        [__Vtableidx2];
    SingleCycleCore__DOT__Branch = SSC__ConstPool__TABLE_h891bc50c_0
        [__Vtableidx2];
    SingleCycleCore__DOT__ALUOp = SSC__ConstPool__TABLE_hb121e016_0
        [__Vtableidx2];
    SingleCycleCore__DOT__rs2 = ((IData)(SingleCycleCore__DOT__ALUSrc)
                                  ? vlSelf->SingleCycleCore__DOT__Immediate
                                  : vlSelf->SingleCycleCore__DOT__ReadData2);
    __Vtableidx3 = ((0x20U & (vlSelf->SingleCycleCore__DOT__Instruction 
                              >> 0x19U)) | ((0x1cU 
                                             & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                >> 0xaU)) 
                                            | (IData)(SingleCycleCore__DOT__ALUOp)));
    SingleCycleCore__DOT__ALUCtrl = SSC__ConstPool__TABLE_h8d41ffe0_0
        [__Vtableidx3];
    vlSelf->SingleCycleCore__DOT__ALUOutput = ((8U 
                                                & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                ? 0U
                                                : (
                                                   (4U 
                                                    & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                      ? 0U
                                                      : 
                                                     (vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank
                                                      [
                                                      (0x1fU 
                                                       & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                          >> 0xfU))] 
                                                      - SingleCycleCore__DOT__rs2))
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                      ? 0U
                                                      : 
                                                     (vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank
                                                      [
                                                      (0x1fU 
                                                       & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                          >> 0xfU))] 
                                                      + SingleCycleCore__DOT__rs2))
                                                     : 
                                                    ((1U 
                                                      & (IData)(SingleCycleCore__DOT__ALUCtrl))
                                                      ? 
                                                     (vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank
                                                      [
                                                      (0x1fU 
                                                       & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                          >> 0xfU))] 
                                                      | SingleCycleCore__DOT__rs2)
                                                      : 
                                                     (vlSelf->SingleCycleCore__DOT__RegisterFileSCC__DOT__bank
                                                      [
                                                      (0x1fU 
                                                       & (vlSelf->SingleCycleCore__DOT__Instruction 
                                                          >> 0xfU))] 
                                                      & SingleCycleCore__DOT__rs2)))));
    vlSelf->SingleCycleCore__DOT__PCNext = (((IData)(SingleCycleCore__DOT__Branch) 
                                             & (0U 
                                                == vlSelf->SingleCycleCore__DOT__ALUOutput))
                                             ? (vlSelf->SingleCycleCore__DOT__PCtemp 
                                                + vlSelf->SingleCycleCore__DOT__Immediate)
                                             : ((IData)(4U) 
                                                + vlSelf->SingleCycleCore__DOT__PCtemp));
    vlSelf->SingleCycleCore__DOT__rd = ((IData)(SingleCycleCore__DOT__MemtoReg)
                                         ? ((IData)(SingleCycleCore__DOT__MemRead)
                                             ? vlSelf->SingleCycleCore__DOT__DataMemorySCC__DOT__ram
                                            [(0xfU 
                                              & (vlSelf->SingleCycleCore__DOT__ALUOutput 
                                                 >> 2U))]
                                             : 0U) : vlSelf->SingleCycleCore__DOT__ALUOutput);
    vlSelf->leds = ((0xfeU & (IData)(vlSelf->leds)) 
                    | (IData)((0U != (0x1010101U & vlSelf->SingleCycleCore__DOT__rd))));
    vlSelf->leds = ((0xfdU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x2020202U & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 1U));
    vlSelf->leds = ((0xfbU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x4040404U & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 2U));
    vlSelf->leds = ((0xf7U & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x8080808U & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 3U));
    vlSelf->leds = ((0xefU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x10101010U 
                                       & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 4U));
    vlSelf->leds = ((0xdfU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x20202020U 
                                       & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 5U));
    vlSelf->leds = ((0xbfU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x40404040U 
                                       & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 6U));
    vlSelf->leds = ((0x7fU & (IData)(vlSelf->leds)) 
                    | ((IData)((0U != (0x80808080U 
                                       & vlSelf->SingleCycleCore__DOT__rd))) 
                       << 7U));
}

void SSC___024root___eval(SSC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    SSC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    SSC___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->original_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__original_clk)))) {
        SSC___024root___sequent__TOP__2(vlSelf);
    }
    if (((IData)(vlSelf->SingleCycleCore__DOT__clk) 
         & (~ (IData)(vlSelf->__Vclklast__TOP__SingleCycleCore__DOT__clk)))) {
        SSC___024root___sequent__TOP__4(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__original_clk = vlSelf->original_clk;
    vlSelf->__Vclklast__TOP__SingleCycleCore__DOT__clk 
        = vlSelf->SingleCycleCore__DOT__clk;
}

#ifdef VL_DEBUG
void SSC___024root___eval_debug_assertions(SSC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    SSC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    SSC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->original_clk & 0xfeU))) {
        Verilated::overWidthError("original_clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn & 0xfeU))) {
        Verilated::overWidthError("btn");}
}
#endif  // VL_DEBUG