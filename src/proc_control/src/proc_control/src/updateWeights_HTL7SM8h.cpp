//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: updateWeights_HTL7SM8h.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "updateWeights_HTL7SM8h.h"

// Function for MATLAB Function: '<S166>/VariableHorizonOptimizer'
void updateWeights_HTL7SM8h(const real_T b_signal[8], real_T W[8])
{
  for (int32_T ct{0}; ct < 8; ct++) {
    real_T b_signal_0;
    b_signal_0 = b_signal[ct];
    if (b_signal_0 < 0.0) {
      W[ct] = 0.0;
    } else {
      W[ct] = b_signal_0 * b_signal_0;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
