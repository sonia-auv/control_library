//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: mtimes_mjx3OaTZ.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "mtimes_mjx3OaTZ.h"

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
real_T mtimes_mjx3OaTZ(const real_T b_A[9], const real_T b_B[9])
{
  real_T b_C;
  b_C = 0.0;
  for (int32_T k{0}; k < 9; k++) {
    b_C += b_A[k] * b_B[k];
  }

  return b_C;
}

//
// File trailer for generated code.
//
// [EOF]
//
