//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_jVll4a1A.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.29
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu May 12 22:26:11 2022
//
#include "rtwtypes.h"
#include "trisolve_jVll4a1A.h"

// Function for MATLAB Function: '<S292>/Correct'
void trisolve_jVll4a1A(real_T A, real_T B[13])
{
  for (int32_T j{0}; j < 13; j++) {
    if (B[j] != 0.0) {
      B[j] /= A;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
