//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: kron_5Yeqlajx.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "kron_5Yeqlajx.h"

// Function for MATLAB Function: '<S205>/FixedHorizonOptimizer'
void kron_5Yeqlajx(const real_T b_A[100], const real_T b_B[64], real_T K[6400])
{
  int32_T kidx;
  kidx = -1;
  for (int32_T b_j1{0}; b_j1 < 10; b_j1++) {
    for (int32_T j2{0}; j2 < 8; j2++) {
      for (int32_T i1{0}; i1 < 10; i1++) {
        for (int32_T i2{0}; i2 < 8; i2++) {
          K[(kidx + i2) + 1] = b_A[10 * b_j1 + i1] * b_B[(j2 << 3) + i2];
        }

        kidx += 8;
      }
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
