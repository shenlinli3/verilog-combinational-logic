// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VAND_GATE_H_
#define _VAND_GATE_H_  // guard

#include "verilated_heavy.h"

//==========

class Vand_gate__Syms;

//----------

VL_MODULE(Vand_gate) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ testbench__DOT__A;
    CData/*0:0*/ testbench__DOT__B;
    CData/*0:0*/ testbench__DOT__Y;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vchglast__TOP__testbench__DOT__Y;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vand_gate__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vand_gate);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vand_gate(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vand_gate();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vand_gate__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vand_gate__Syms* symsp, bool first);
  private:
    static QData _change_request(Vand_gate__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vand_gate__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vand_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vand_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vand_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__2(Vand_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
