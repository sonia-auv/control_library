//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpc_checkhessian_AF9zNtya.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.72
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Jul 12 22:29:20 2022
//
#include "rtwtypes.h"
#include "mpc_checkhessian_AF9zNtya.h"
#include <cstring>
#include "xpotrf_4MFpOPH5.h"
#include "minimum_NKIx9XVP.h"
#include <cmath>
#include "rt_powd_snf.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
  void mpc_checkhessian_AF9zNtya(real_T b_H[81], real_T L[81], real_T *BadH)
{
  real_T varargin_1[9];
  int32_T Tries;
  int32_T Tries_0;
  int8_T b[81];
  boolean_T guard1{ false };

  *BadH = 0.0;
  std::memcpy(&L[0], &b_H[0], 81U * sizeof(real_T));
  Tries = xpotrf_4MFpOPH5(L);
  guard1 = false;
  if (Tries == 0) {
    Tries_0 = 0;
    for (Tries = 0; Tries < 9; Tries++) {
      varargin_1[Tries] = L[Tries_0];
      Tries_0 += 10;
    }

    if (minimum_NKIx9XVP(varargin_1) > 1.4901161193847656E-7) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    real_T normH;
    boolean_T exitg2;
    normH = 0.0;
    Tries = 0;
    exitg2 = false;
    while ((!exitg2) && (Tries < 9)) {
      real_T s;
      s = 0.0;
      for (Tries_0 = 0; Tries_0 < 9; Tries_0++) {
        s += std::abs(b_H[9 * Tries_0 + Tries]);
      }

      if (std::isnan(s)) {
        normH = (rtNaN);
        exitg2 = true;
      } else {
        if (s > normH) {
          normH = s;
        }

        Tries++;
      }
    }

    if (normH >= 1.0E+10) {
      *BadH = 2.0;
    } else {
      boolean_T exitg1;
      Tries = 0;
      exitg1 = false;
      while ((!exitg1) && (Tries <= 4)) {
        int32_T j;
        boolean_T guard2{ false };

        normH = rt_powd_snf(10.0, static_cast<real_T>(Tries)) *
          1.4901161193847656E-7;
        std::memset(&b[0], 0, 81U * sizeof(int8_T));
        j = 0;
        for (Tries_0 = 0; Tries_0 < 9; Tries_0++) {
          b[j] = 1;
          j += 10;
        }

        for (Tries_0 = 0; Tries_0 < 81; Tries_0++) {
          b_H[Tries_0] += normH * static_cast<real_T>(b[Tries_0]);
          L[Tries_0] = b_H[Tries_0];
        }

        Tries_0 = xpotrf_4MFpOPH5(L);
        guard2 = false;
        if (Tries_0 == 0) {
          j = 0;
          for (Tries_0 = 0; Tries_0 < 9; Tries_0++) {
            varargin_1[Tries_0] = L[j];
            j += 10;
          }

          if (minimum_NKIx9XVP(varargin_1) > 1.4901161193847656E-7) {
            *BadH = 1.0;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          *BadH = 3.0;
          Tries++;
        }
      }
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
