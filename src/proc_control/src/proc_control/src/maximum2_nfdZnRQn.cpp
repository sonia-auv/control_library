//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: maximum2_nfdZnRQn.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.10
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr 28 22:47:52 2022
//
#include "rtwtypes.h"
#include "maximum2_nfdZnRQn.h"
#include <cmath>

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
void maximum2_nfdZnRQn(const real_T x[236], real_T y, real_T ex[236])
{
  for (int32_T k{0}; k < 236; k++) {
    ex[k] = std::fmax(x[k], y);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
