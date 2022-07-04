//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: log2_blLsPIAE.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "log2_blLsPIAE.h"
#include <cmath>
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S139>/MATLAB Function2'
  real_T log2_blLsPIAE(real_T x)
{
  real_T f;
  int32_T inte;
  if (x == 0.0) {
    f = (rtMinusInf);
  } else if ((!std::isinf(x)) && (!std::isnan(x))) {
    real_T t;
    t = frexp(x, &inte);
    if (t == 0.5) {
      f = static_cast<real_T>(inte) - 1.0;
    } else if ((inte == 1) && (t < 0.75)) {
      f = std::log(2.0 * t) / 0.69314718055994529;
    } else {
      f = std::log(t) / 0.69314718055994529 + static_cast<real_T>(inte);
    }
  } else {
    f = x;
  }

  return f;
}

//
// File trailer for generated code.
//
// [EOF]
//
