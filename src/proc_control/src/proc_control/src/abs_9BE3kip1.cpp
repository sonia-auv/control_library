//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: abs_9BE3kip1.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "abs_9BE3kip1.h"
#include <cmath>

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
void abs_9BE3kip1(const real_T x[17], real_T y[17])
{
  for (int32_T k{0}; k < 17; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
