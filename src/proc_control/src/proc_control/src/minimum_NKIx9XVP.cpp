//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: minimum_NKIx9XVP.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "minimum_NKIx9XVP.h"
#include <cmath>

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
real_T minimum_NKIx9XVP(const real_T x[9])
{
  real_T ex;
  int32_T idx;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 9) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

//
// File trailer for generated code.
//
// [EOF]
//
