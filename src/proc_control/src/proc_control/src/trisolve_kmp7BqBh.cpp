//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: trisolve_kmp7BqBh.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "trisolve_kmp7BqBh.h"

// Function for MATLAB Function: '<S285>/Correct'
void trisolve_kmp7BqBh(const real_T A[49], real_T B[91])
{
  for (int32_T j{0}; j < 13; j++) {
    int32_T jBcol;
    jBcol = 7 * j;
    for (int32_T k{6}; k >= 0; k--) {
      real_T tmp_0;
      int32_T kAcol;
      int32_T tmp;
      kAcol = 7 * k;
      tmp = k + jBcol;
      tmp_0 = B[tmp];
      if (tmp_0 != 0.0) {
        B[tmp] = tmp_0 / A[k + kAcol];
        for (int32_T i{0}; i < k; i++) {
          int32_T tmp_1;
          tmp_1 = i + jBcol;
          B[tmp_1] -= A[i + kAcol] * B[tmp];
        }
      }
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
