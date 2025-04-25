// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDESIGN_H_
#define _VDESIGN_H_  // guard

#include "verilated.h"

//==========

class Vdesign__Syms;

//----------

VL_MODULE(Vdesign) {
  public:
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdesign__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdesign);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdesign(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdesign();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdesign__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdesign__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdesign__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdesign__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdesign__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdesign__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vdesign__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
