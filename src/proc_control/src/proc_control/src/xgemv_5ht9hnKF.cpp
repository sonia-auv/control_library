//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: xgemv_5ht9hnKF.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "xgemv_5ht9hnKF.h"

// Function for MATLAB Function: '<S289>/Predict'
void xgemv_5ht9hnKF(int32_T m, int32_T n, const real_T A[338], int32_T ia0,
                    const real_T x[338], int32_T ix0, real_T y[13])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T b_iy;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 26 + ia0;
    for (int32_T iac{ia0}; iac <= b; iac += 26) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia{iac}; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
