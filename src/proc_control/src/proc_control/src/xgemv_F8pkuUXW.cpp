//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_F8pkuUXW.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "xgemv_F8pkuUXW.h"

// Function for MATLAB Function: '<S291>/Correct'
void xgemv_F8pkuUXW(int32_T m, int32_T n, const real_T A[208], int32_T ia0,
                    const real_T x[208], int32_T ix0, real_T y[13])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T b_iy;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = ((n - 1) << 4) + ia0;
    for (int32_T iac{ia0}; iac <= b; iac += 16) {
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
