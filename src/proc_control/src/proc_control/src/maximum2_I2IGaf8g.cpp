//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: maximum2_I2IGaf8g.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.69
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 18 14:22:28 2022
//
#include "rtwtypes.h"
#include "maximum2_I2IGaf8g.h"
#include <cmath>

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
void maximum2_I2IGaf8g(const real_T x[258], real_T y, real_T ex[258])
{
  for (int32_T k{0}; k < 258; k++) {
    ex[k] = std::fmax(x[k], y);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
