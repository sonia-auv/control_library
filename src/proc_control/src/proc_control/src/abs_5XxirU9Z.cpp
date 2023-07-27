//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: abs_5XxirU9Z.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "abs_5XxirU9Z.h"
#include <cmath>

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
void abs_5XxirU9Z(const real_T x[9], real_T y[9])
{
  for (int32_T k{0}; k < 9; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
