//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: Unconstrained_UjzZuo4S.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "Unconstrained_UjzZuo4S.h"

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
void Unconstrained_UjzZuo4S(const real_T b_Hinv[81], const real_T f[9], real_T
  x[9], int32_T n)
{
  for (int32_T b_i{0}; b_i < n; b_i++) {
    real_T b_Hinv_0;
    b_Hinv_0 = 0.0;
    for (int32_T i{0}; i < 9; i++) {
      b_Hinv_0 += -b_Hinv[9 * i + b_i] * f[i];
    }

    x[b_i] = b_Hinv_0;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
