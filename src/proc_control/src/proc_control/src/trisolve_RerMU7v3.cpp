//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_RerMU7v3.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.17
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Apr 30 21:20:52 2022
//
#include "rtwtypes.h"
#include "trisolve_RerMU7v3.h"

// Function for MATLAB Function: '<S288>/Correct'
void trisolve_RerMU7v3(const real_T A[4], real_T B[26])
{
  for (int32_T j{0}; j < 13; j++) {
    int32_T jBcol;
    jBcol = j << 1;
    if (B[jBcol] != 0.0) {
      B[jBcol] /= A[0];
      B[jBcol + 1] -= B[jBcol] * A[1];
    }

    if (B[jBcol + 1] != 0.0) {
      B[jBcol + 1] /= A[3];
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
