//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: abs_hS9HYvNd.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.69
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 18 14:22:28 2022
//
#include "rtwtypes.h"
#include "abs_hS9HYvNd.h"
#include <cmath>

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
void abs_hS9HYvNd(const real_T x[25], real_T y[25])
{
  for (int32_T k{0}; k < 25; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
