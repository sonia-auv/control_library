//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: trisolve_bR4rdVHP.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "trisolve_bR4rdVHP.h"

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
void trisolve_bR4rdVHP(const real_T b_A[81], real_T b_B[81])
{
  for (int32_T j{0}; j < 9; j++) {
    int32_T jBcol;
    jBcol = 9 * j;
    for (int32_T k{0}; k < 9; k++) {
      real_T tmp_0;
      int32_T kAcol;
      int32_T tmp;
      kAcol = 9 * k;
      tmp = k + jBcol;
      tmp_0 = b_B[tmp];
      if (tmp_0 != 0.0) {
        b_B[tmp] = tmp_0 / b_A[k + kAcol];
        for (int32_T i{k + 2}; i < 10; i++) {
          int32_T tmp_1;
          tmp_1 = (i + jBcol) - 1;
          b_B[tmp_1] -= b_A[(i + kAcol) - 1] * b_B[tmp];
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
