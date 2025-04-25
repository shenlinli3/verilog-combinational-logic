// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdesign.h for the primary calling header

#include "Vdesign.h"
#include "Vdesign__Syms.h"

//==========

VL_CTOR_IMP(Vdesign) {
    Vdesign__Syms* __restrict vlSymsp = __VlSymsp = new Vdesign__Syms(this, name());
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdesign::__Vconfigure(Vdesign__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vdesign::~Vdesign() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vdesign::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdesign::eval\n"); );
    Vdesign__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("testbench.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdesign::_eval_initial_loop(Vdesign__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("testbench.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdesign::_initial__TOP__1(Vdesign__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_initial__TOP__1\n"); );
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_FINISH_MT("testbench.sv", 11, "");
}

void Vdesign::_eval(Vdesign__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_eval\n"); );
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdesign::_eval_initial(Vdesign__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_eval_initial\n"); );
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vdesign::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::final\n"); );
    // Variables
    Vdesign__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdesign::_eval_settle(Vdesign__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_eval_settle\n"); );
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vdesign::_change_request(Vdesign__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_change_request\n"); );
    Vdesign* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdesign::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

void Vdesign::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign::_ctor_var_reset\n"); );
}
