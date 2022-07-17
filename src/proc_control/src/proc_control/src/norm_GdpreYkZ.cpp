//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: norm_GdpreYkZ.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "norm_GdpreYkZ.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S139>/MATLAB Function2'
  real_T norm_GdpreYkZ(const real_T x[169])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 13)) {
    real_T s;
    s = 0.0;
    for (int32_T i{0}; i < 13; i++) {
      s += std::abs(x[13 * j + i]);
    }

    if (std::isnan(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
