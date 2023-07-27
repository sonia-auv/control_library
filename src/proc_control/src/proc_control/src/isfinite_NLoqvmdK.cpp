//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: isfinite_NLoqvmdK.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "isfinite_NLoqvmdK.h"
#include <cmath>

// Function for MATLAB Function: '<S208>/NLMPC'
void isfinite_NLoqvmdK(const real_T x[8], boolean_T b[8])
{
  for (int32_T i{0}; i < 8; i++) {
    real_T x_0;
    x_0 = x[i];
    b[i] = ((!std::isinf(x_0)) && (!std::isnan(x_0)));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
