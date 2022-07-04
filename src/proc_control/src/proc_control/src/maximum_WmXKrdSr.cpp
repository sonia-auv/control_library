//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: maximum_WmXKrdSr.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "maximum_WmXKrdSr.h"
#include <cmath>

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
real_T maximum_WmXKrdSr(const real_T x[17])
{
  real_T ex;
  int32_T idx;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 17) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

//
// File trailer for generated code.
//
// [EOF]
//
