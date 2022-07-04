//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xnrm2_UCgE6veV.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "xnrm2_UCgE6veV.h"
#include <cmath>

// Function for MATLAB Function: '<S294>/Predict'
real_T xnrm2_UCgE6veV(int32_T n, const real_T x[338], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
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

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
