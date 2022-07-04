//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: maximum2_d2MhUgrc.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "maximum2_d2MhUgrc.h"
#include <cmath>

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
void maximum2_d2MhUgrc(const real_T x[252], real_T y, real_T ex[252])
{
  for (int32_T k{0}; k < 252; k++) {
    ex[k] = std::fmax(x[k], y);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
