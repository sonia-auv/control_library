//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_QLyTZPzT.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "trisolve_QLyTZPzT.h"

// Function for MATLAB Function: '<S285>/Correct'
void trisolve_QLyTZPzT(const real_T A[9], real_T B[39])
{
  for (int32_T j{0}; j < 13; j++) {
    real_T tmp;
    int32_T jBcol;
    jBcol = 3 * j;
    tmp = B[jBcol + 2];
    if (tmp != 0.0) {
      B[jBcol + 2] = tmp / A[8];
      for (int32_T i{0}; i < 2; i++) {
        int32_T tmp_0;
        tmp_0 = i + jBcol;
        B[tmp_0] -= B[jBcol + 2] * A[i + 6];
      }
    }

    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[4];
      B[jBcol] -= B[jBcol + 1] * A[3];
    }

    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
