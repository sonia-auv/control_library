//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_nzh2XTxC.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "trisolve_nzh2XTxC.h"

// Function for MATLAB Function: '<S285>/Correct'
void trisolve_nzh2XTxC(const real_T A[9], real_T B[39])
{
  for (int32_T j{0}; j < 13; j++) {
    real_T tmp;
    int32_T jBcol;
    jBcol = 3 * j;
    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
      for (int32_T i{2}; i < 4; i++) {
        int32_T tmp_0;
        tmp_0 = (i + jBcol) - 1;
        B[tmp_0] -= A[i - 1] * B[jBcol];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[4];
      B[jBcol + 2] -= B[jBcol + 1] * A[5];
    }

    if (B[jBcol + 2] != 0.0) {
      B[jBcol + 2] /= A[8];
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
