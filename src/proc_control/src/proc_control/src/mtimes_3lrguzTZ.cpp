//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mtimes_3lrguzTZ.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "mtimes_3lrguzTZ.h"

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
real_T mtimes_3lrguzTZ(const real_T b_A[17], const real_T b_B[17])
{
  real_T b_C;
  b_C = 0.0;
  for (int32_T k{0}; k < 17; k++) {
    b_C += b_A[k] * b_B[k];
  }

  return b_C;
}

//
// File trailer for generated code.
//
// [EOF]
//
