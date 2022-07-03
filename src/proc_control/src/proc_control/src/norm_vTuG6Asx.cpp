//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: norm_vTuG6Asx.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.69
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 18 14:22:28 2022
//
#include "rtwtypes.h"
#include "norm_vTuG6Asx.h"
#include <cmath>

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
real_T norm_vTuG6Asx(const real_T x[25])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k{0}; k < 25; k++) {
    real_T absxk;
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

//
// File trailer for generated code.
//
// [EOF]
//
