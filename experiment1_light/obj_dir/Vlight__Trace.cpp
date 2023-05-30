// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlight__Syms.h"


//======================

void Vlight::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vlight* t = (Vlight*)userthis;
    Vlight__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vlight::traceChgThis(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vlight::traceChgThis__2(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->light__DOT__count),32);
    }
}

void Vlight::traceChgThis__3(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+9,(vlTOPp->clk));
        vcdp->chgBit(c+17,(vlTOPp->rst));
        vcdp->chgBus(c+25,(vlTOPp->led),16);
    }
}
