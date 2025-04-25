// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vand_gate.h for the primary calling header

#include "Vand_gate.h"
#include "Vand_gate__Syms.h"

//==========

VL_CTOR_IMP(Vand_gate) {
    Vand_gate__Syms* __restrict vlSymsp = __VlSymsp = new Vand_gate__Syms(this, name());
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vand_gate::__Vconfigure(Vand_gate__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vand_gate::~Vand_gate() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vand_gate::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vand_gate::eval\n"); );
    Vand_gate__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("tests/testbench.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vand_gate::_eval_initial_loop(Vand_gate__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("tests/testbench.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vand_gate::_initial__TOP__1(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_initial__TOP__1\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("Time: %0t | A: 0, B: 0, Y: %b\n",64,
              VL_TIME_Q(),1,(IData)(vlTOPp->testbench__DOT__Y));
    VL_WRITEF("Time: %0t | A: 0, B: 1, Y: %b\n",64,
              VL_TIME_Q(),1,(IData)(vlTOPp->testbench__DOT__Y));
    VL_WRITEF("Time: %0t | A: 1, B: 0, Y: %b\n",64,
              VL_TIME_Q(),1,(IData)(vlTOPp->testbench__DOT__Y));
    vlTOPp->testbench__DOT__A = 1U;
    vlTOPp->testbench__DOT__B = 1U;
    VL_WRITEF("Time: %0t | A: 1, B: 1, Y: %b\n",64,
              VL_TIME_Q(),1,(IData)(vlTOPp->testbench__DOT__Y));
    VL_FINISH_MT("tests/testbench.sv", 25, "");
    vlTOPp->testbench__DOT__Y = 1U;
}

void Vand_gate::_settle__TOP__2(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_settle__TOP__2\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->testbench__DOT__Y = ((IData)(vlTOPp->testbench__DOT__A) 
                                 & (IData)(vlTOPp->testbench__DOT__B));
}

void Vand_gate::_eval(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vand_gate::_eval_initial(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval_initial\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vand_gate::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::final\n"); );
    // Variables
    Vand_gate__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vand_gate::_eval_settle(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval_settle\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vand_gate::_change_request(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_change_request\n"); );
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->testbench__DOT__Y ^ vlTOPp->__Vchglast__TOP__testbench__DOT__Y));
    VL_DEBUG_IF( if(__req && ((vlTOPp->testbench__DOT__Y ^ vlTOPp->__Vchglast__TOP__testbench__DOT__Y))) VL_DBG_MSGF("        CHANGE: tests/testbench.sv:4: testbench.Y\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__testbench__DOT__Y = vlTOPp->testbench__DOT__Y;
    return __req;
}

#ifdef VL_DEBUG
void Vand_gate::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

void Vand_gate::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_ctor_var_reset\n"); );
    // Body
    testbench__DOT__A = VL_RAND_RESET_I(1);
    testbench__DOT__B = VL_RAND_RESET_I(1);
    testbench__DOT__Y = VL_RAND_RESET_I(1);
    __Vchglast__TOP__testbench__DOT__Y = VL_RAND_RESET_I(1);
}
