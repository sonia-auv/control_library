//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mldivide_Z0xqFpTr.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.72
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Jul 12 22:29:20 2022
//
#include "rtwtypes.h"
#include "mldivide_Z0xqFpTr.h"
#include <cstring>
#include <cmath>

// Function for MATLAB Function: '<S133>/MATLAB Function2'
void mldivide_Z0xqFpTr(const real_T A[36], const real_T B[36], real_T Y[36])
{
  real_T b_A[36];
  real_T smax;
  int32_T c_ix;
  int32_T ix;
  int32_T iy;
  int32_T jj;
  int8_T ipiv[6];
  std::memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  std::memcpy(&Y[0], &B[0], 36U * sizeof(real_T));
  for (int32_T b_j{0}; b_j < 6; b_j++) {
    ipiv[b_j] = static_cast<int8_T>(b_j + 1);
  }

  for (int32_T b_j{0}; b_j < 5; b_j++) {
    jj = b_j * 7;
    iy = 0;
    ix = jj;
    smax = std::abs(b_A[jj]);
    for (int32_T c_k{2}; c_k <= 6 - b_j; c_k++) {
      real_T s;
      ix++;
      s = std::abs(b_A[ix]);
      if (s > smax) {
        iy = c_k - 1;
        smax = s;
      }
    }

    if (b_A[jj + iy] != 0.0) {
      if (iy != 0) {
        iy += b_j;
        ipiv[b_j] = static_cast<int8_T>(iy + 1);
        for (int32_T c_k{0}; c_k < 6; c_k++) {
          smax = b_A[c_k * 6 + b_j];
          ix = c_k * 6 + iy;
          b_A[b_j + c_k * 6] = b_A[ix];
          b_A[ix] = smax;
        }
      }

      iy = (jj - b_j) + 6;
      for (ix = jj + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[jj];
      }
    }

    iy = jj + 6;
    ix = jj;
    for (int32_T c_k{0}; c_k <= 4 - b_j; c_k++) {
      smax = b_A[iy];
      if (b_A[iy] != 0.0) {
        int32_T c;
        int32_T ijA;
        c_ix = jj + 1;
        ijA = ix + 7;
        c = (ix - b_j) + 12;
        while (ijA + 1 <= c) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
          ijA++;
        }
      }

      iy += 6;
      ix += 6;
    }
  }

  for (int32_T b_j{0}; b_j < 5; b_j++) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[b_j];
    if (b_j + 1 != ipiv_0) {
      for (iy = 0; iy < 6; iy++) {
        jj = 6 * iy + b_j;
        smax = Y[jj];
        ix = (6 * iy + ipiv_0) - 1;
        Y[jj] = Y[ix];
        Y[ix] = smax;
      }
    }
  }

  for (int32_T b_j{0}; b_j < 6; b_j++) {
    jj = 6 * b_j;
    for (iy = 0; iy < 6; iy++) {
      ix = 6 * iy;
      if (Y[iy + jj] != 0.0) {
        for (int32_T c_k{iy + 2}; c_k < 7; c_k++) {
          c_ix = (c_k + jj) - 1;
          Y[c_ix] -= b_A[(c_k + ix) - 1] * Y[iy + jj];
        }
      }
    }
  }

  for (int32_T b_j{0}; b_j < 6; b_j++) {
    jj = 6 * b_j;
    for (iy = 5; iy >= 0; iy--) {
      ix = 6 * iy;
      if (Y[iy + jj] != 0.0) {
        c_ix = iy + jj;
        Y[c_ix] /= b_A[iy + ix];
        for (int32_T c_k{0}; c_k < iy; c_k++) {
          c_ix = c_k + jj;
          Y[c_ix] -= Y[iy + jj] * b_A[c_k + ix];
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
