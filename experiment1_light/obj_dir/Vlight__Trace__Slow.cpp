// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlight__Syms.h"


//======================

void Vlight::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vlight::traceInit, &Vlight::traceFull, &Vlight::traceChg, this);
}
void Vlight::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vlight* t = (Vlight*)userthis;
    Vlight__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vlight::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vlight* t = (Vlight*)userthis;
    Vlight__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vlight::traceInitThis(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vlight::traceFullThis(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vlight::traceInitThis__1(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+9,"clk", false,-1);
        vcdp->declBit(c+17,"rst", false,-1);
        vcdp->declBus(c+25,"led", false,-1, 15,0);
        vcdp->declBit(c+9,"light clk", false,-1);
        vcdp->declBit(c+17,"light rst", false,-1);
        vcdp->declBus(c+25,"light led", false,-1, 15,0);
        vcdp->declBus(c+1,"light count", false,-1, 31,0);
    }
}

void Vlight::traceFullThis__1(Vlight__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->light__DOT__count),32);
        vcdp->fullBit(c+9,(vlTOPp->clk));
        vcdp->fullBit(c+17,(vlTOPp->rst));
        vcdp->fullBus(c+25,(vlTOPp->led),16);
    }
}
