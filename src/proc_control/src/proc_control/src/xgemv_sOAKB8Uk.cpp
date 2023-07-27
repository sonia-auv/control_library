//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: xgemv_sOAKB8Uk.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "xgemv_sOAKB8Uk.h"

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
void xgemv_sOAKB8Uk(int32_T b_m, int32_T n, const real_T b_A[81], int32_T ia0,
                    const real_T x[81], int32_T ix0, real_T y[9])
{
  if ((b_m != 0) && (n != 0)) {
    int32_T b;
    int32_T b_iy;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 9 + ia0;
    for (int32_T iac{ia0}; iac <= b; iac += 9) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = ix0;
      c = 0.0;
      d = (iac + b_m) - 1;
      for (int32_T ia{iac}; ia <= d; ia++) {
        c += b_A[ia - 1] * x[ix - 1];
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
