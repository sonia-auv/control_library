//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: isfinite_NLoqvmdK.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "isfinite_NLoqvmdK.h"
#include <cmath>

// Function for MATLAB Function: '<S209>/NLMPC'
void isfinite_NLoqvmdK(const real_T x[8], boolean_T b[8])
{
  for (int32_T i{0}; i < 8; i++) {
    real_T x_0;
    x_0 = x[i];
    b[i] = ((!std::isinf(x_0)) && (!std::isnan(x_0)));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
