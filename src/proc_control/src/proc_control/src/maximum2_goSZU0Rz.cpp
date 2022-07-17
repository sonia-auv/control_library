//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: maximum2_goSZU0Rz.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "maximum2_goSZU0Rz.h"
#include <cmath>

// Function for MATLAB Function: '<S210>/FixedHorizonOptimizer'
void maximum2_goSZU0Rz(const real_T x[226], real_T y, real_T ex[226])
{
  for (int32_T k{0}; k < 226; k++) {
    ex[k] = std::fmax(x[k], y);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
