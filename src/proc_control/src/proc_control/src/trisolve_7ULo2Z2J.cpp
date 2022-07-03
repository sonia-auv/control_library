//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_7ULo2Z2J.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.17
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Apr 30 21:20:52 2022
//
#include "rtwtypes.h"
#include "trisolve_7ULo2Z2J.h"

// Function for MATLAB Function: '<S288>/Correct'
void trisolve_7ULo2Z2J(const real_T A[4], real_T B[26])
{
  for (int32_T j{0}; j < 13; j++) {
    real_T tmp;
    int32_T jBcol;
    jBcol = j << 1;
    tmp = B[jBcol + 1];
    if (tmp != 0.0) {
      B[jBcol + 1] = tmp / A[3];
      B[jBcol] -= B[jBcol + 1] * A[2];
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
