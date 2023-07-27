//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: recomputeBlockDiag_qmxFvKVu.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "recomputeBlockDiag_qmxFvKVu.h"
#include <cmath>

// Function for MATLAB Function: '<S133>/MATLAB Function2'
void recomputeBlockDiag_qmxFvKVu(const real_T A[169], real_T F[169], const
  int32_T blockFormat[12])
{
  for (int32_T j{0}; j < 12; j++) {
    switch (blockFormat[j]) {
     case 0:
      break;

     case 1:
      {
        real_T delta;
        real_T delta_tmp_0;
        real_T delta_tmp_1;
        real_T expa;
        real_T sinchdelta;
        int32_T delta_tmp;
        int32_T delta_tmp_tmp;
        delta_tmp = 13 * j + j;
        delta_tmp_0 = A[delta_tmp];
        delta = std::exp(delta_tmp_0);
        delta_tmp_tmp = (j + 1) * 13 + j;
        delta_tmp_1 = A[delta_tmp_tmp + 1];
        expa = std::exp(delta_tmp_1);
        sinchdelta = (delta_tmp_1 + delta_tmp_0) / 2.0;
        if (std::fmax(sinchdelta, std::abs(delta_tmp_0 - delta_tmp_1) / 2.0) <
            709.782712893384) {
          delta_tmp_0 = (A[delta_tmp_tmp + 1] - A[delta_tmp]) / 2.0;
          if (delta_tmp_0 == 0.0) {
            delta_tmp_0 = 1.0;
          } else {
            delta_tmp_0 = std::sinh(delta_tmp_0) / delta_tmp_0;
          }

          sinchdelta = A[delta_tmp_tmp] * std::exp(sinchdelta) * delta_tmp_0;
        } else {
          sinchdelta = (expa - delta) * A[delta_tmp_tmp] / (delta_tmp_1 -
            delta_tmp_0);
        }

        F[delta_tmp] = delta;
        F[delta_tmp_tmp] = sinchdelta;
        F[delta_tmp_tmp + 1] = expa;
      }
      break;

     default:
      {
        real_T delta;
        real_T delta_tmp_0;
        real_T delta_tmp_1;
        real_T expa;
        real_T sinchdelta;
        int32_T delta_tmp;
        int32_T delta_tmp_tmp;
        delta_tmp = 13 * j + j;
        delta_tmp_0 = A[delta_tmp + 1];
        delta_tmp_tmp = (j + 1) * 13 + j;
        delta_tmp_1 = A[delta_tmp_tmp];
        delta = std::sqrt(std::abs(delta_tmp_1 * delta_tmp_0));
        expa = std::exp(A[delta_tmp]);
        if (delta == 0.0) {
          sinchdelta = 1.0;
        } else {
          sinchdelta = std::sin(delta) / delta;
        }

        F[delta_tmp] = expa * std::cos(delta);
        F[delta_tmp + 1] = delta_tmp_0 * expa * sinchdelta;
        F[delta_tmp_tmp] = delta_tmp_1 * expa * sinchdelta;
        F[delta_tmp_tmp + 1] = F[delta_tmp];
      }
      break;
    }
  }

  if (blockFormat[11] == 0) {
    F[168] = std::exp(A[168]);
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
