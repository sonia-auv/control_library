//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_Ewqm83ue.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.17
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Apr 30 21:20:52 2022
//
#include "rtwtypes.h"
#include "trisolve_Ewqm83ue.h"

// Function for MATLAB Function: '<S286>/Correct'
void trisolve_Ewqm83ue(const real_T A[49], real_T B[91])
{
  for (int32_T j{0}; j < 13; j++) {
    int32_T jBcol;
    jBcol = 7 * j;
    for (int32_T k{0}; k < 7; k++) {
      real_T tmp_0;
      int32_T kAcol;
      int32_T tmp;
      kAcol = 7 * k;
      tmp = k + jBcol;
      tmp_0 = B[tmp];
      if (tmp_0 != 0.0) {
        B[tmp] = tmp_0 / A[k + kAcol];
        for (int32_T i{k + 2}; i < 8; i++) {
          int32_T tmp_1;
          tmp_1 = (i + jBcol) - 1;
          B[tmp_1] -= A[(i + kAcol) - 1] * B[tmp];
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
