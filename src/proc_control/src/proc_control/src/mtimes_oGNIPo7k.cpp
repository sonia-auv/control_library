//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mtimes_oGNIPo7k.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.69
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 18 14:22:28 2022
//
#include "rtwtypes.h"
#include "mtimes_oGNIPo7k.h"

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
real_T mtimes_oGNIPo7k(const real_T b_A[25], const real_T b_B[25])
{
  real_T b_C;
  b_C = 0.0;
  for (int32_T k{0}; k < 25; k++) {
    b_C += b_A[k] * b_B[k];
  }

  return b_C;
}

//
// File trailer for generated code.
//
// [EOF]
//
