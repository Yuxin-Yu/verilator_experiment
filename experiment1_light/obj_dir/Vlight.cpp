// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlight.h for the primary calling header

#include "Vlight.h"
#include "Vlight__Syms.h"

//==========

VL_CTOR_IMP(Vlight) {
    Vlight__Syms* __restrict vlSymsp = __VlSymsp = new Vlight__Syms(this, name());
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlight::__Vconfigure(Vlight__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vlight::~Vlight() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vlight::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlight::eval\n"); );
    Vlight__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("light.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlight::_eval_initial_loop(Vlight__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("light.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vlight::_sequent__TOP__1(Vlight__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_sequent__TOP__1\n"); );
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*15:0*/ __Vdly__led;
    IData/*31:0*/ __Vdly__light__DOT__count;
    // Body
    __Vdly__light__DOT__count = vlTOPp->light__DOT__count;
    __Vdly__led = vlTOPp->led;
    if (vlTOPp->rst) {
        __Vdly__led = 1U;
        __Vdly__light__DOT__count = 0U;
    } else {
        if ((0U == vlTOPp->light__DOT__count)) {
            __Vdly__led = ((0xfffeU & ((IData)(vlTOPp->led) 
                                       << 1U)) | (1U 
                                                  & ((IData)(vlTOPp->led) 
                                                     >> 0xfU)));
        }
        __Vdly__light__DOT__count = ((0x4c4b40U <= vlTOPp->light__DOT__count)
                                      ? 0U : ((IData)(1U) 
                                              + vlTOPp->light__DOT__count));
    }
    vlTOPp->led = __Vdly__led;
    vlTOPp->light__DOT__count = __Vdly__light__DOT__count;
}

void Vlight::_eval(Vlight__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_eval\n"); );
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vlight::_eval_initial(Vlight__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_eval_initial\n"); );
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vlight::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::final\n"); );
    // Variables
    Vlight__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlight::_eval_settle(Vlight__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_eval_settle\n"); );
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vlight::_change_request(Vlight__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_change_request\n"); );
    Vlight* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlight::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG

void Vlight::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    led = VL_RAND_RESET_I(16);
    light__DOT__count = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
