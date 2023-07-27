//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: xgerc_6YFUaNlM.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "xgerc_6YFUaNlM.h"

// Function for MATLAB Function: '<S286>/Correct'
void xgerc_6YFUaNlM(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                    real_T y[3], real_T A[48], int32_T ia0)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    int32_T jy;
    jA = ia0 - 1;
    jy = 0;
    for (int32_T j{0}; j < n; j++) {
      if (y[jy] != 0.0) {
        real_T temp;
        int32_T b;
        int32_T ijA;
        int32_T ix;
        temp = y[jy] * alpha1;
        ix = ix0;
        ijA = jA;
        b = m + jA;
        while (ijA + 1 <= b) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
          ijA++;
        }
      }

      jy++;
      jA += 16;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
