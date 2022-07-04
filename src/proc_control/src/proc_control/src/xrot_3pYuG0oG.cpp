//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrot_3pYuG0oG.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "xrot_3pYuG0oG.h"

// Function for MATLAB Function: '<S144>/MATLAB Function2'
void xrot_3pYuG0oG(int32_T n, real_T x[169], int32_T ix0, int32_T iy0, real_T c,
                   real_T s)
{
  if (n >= 1) {
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (int32_T k{0}; k < n; k++) {
      real_T temp;
      temp = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = temp;
      iy++;
      ix++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
