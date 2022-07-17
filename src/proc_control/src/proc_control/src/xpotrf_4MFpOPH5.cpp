//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xpotrf_4MFpOPH5.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.72
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Jul 12 22:29:20 2022
//
#include "rtwtypes.h"
#include "xpotrf_4MFpOPH5.h"
#include <cmath>

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
int32_T xpotrf_4MFpOPH5(real_T b_A[81])
{
  int32_T info;
  int32_T j;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 9)) {
    real_T ssq;
    int32_T b_ix;
    int32_T b_iy;
    int32_T idxAjj;
    idxAjj = j * 9 + j;
    ssq = 0.0;
    if (j >= 1) {
      b_ix = j;
      b_iy = j;
      for (int32_T b_k{0}; b_k < j; b_k++) {
        ssq += b_A[b_ix] * b_A[b_iy];
        b_ix += 9;
        b_iy += 9;
      }
    }

    ssq = b_A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = std::sqrt(ssq);
      b_A[idxAjj] = ssq;
      if (j + 1 < 9) {
        if (j != 0) {
          b_ix = j;
          b_iy = ((j - 1) * 9 + j) + 2;
          for (int32_T b_k{j + 2}; b_k <= b_iy; b_k += 9) {
            real_T c;
            int32_T d;
            int32_T iy;
            c = -b_A[b_ix];
            iy = idxAjj + 1;
            d = (b_k - j) + 7;
            for (int32_T ia{b_k}; ia <= d; ia++) {
              b_A[iy] += b_A[ia - 1] * c;
              iy++;
            }

            b_ix += 9;
          }
        }

        ssq = 1.0 / ssq;
        b_ix = (idxAjj - j) + 9;
        for (idxAjj++; idxAjj < b_ix; idxAjj++) {
          b_A[idxAjj] *= ssq;
        }
      }

      j++;
    } else {
      b_A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

//
// File trailer for generated code.
//
// [EOF]
//
