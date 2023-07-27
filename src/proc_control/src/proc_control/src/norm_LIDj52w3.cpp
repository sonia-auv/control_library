//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: norm_LIDj52w3.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "norm_LIDj52w3.h"
#include <cmath>

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
real_T norm_LIDj52w3(const real_T x[9])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k{0}; k < 9; k++) {
    real_T absxk;
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

//
// File trailer for generated code.
//
// [EOF]
//
