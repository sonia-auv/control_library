//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Unconstrained_VQtVdCHQ.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.1
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Apr  7 23:11:26 2022
//
#include "rtwtypes.h"
#include "Unconstrained_VQtVdCHQ.h"

// Function for MATLAB Function: '<S171>/FixedHorizonOptimizer'
void Unconstrained_VQtVdCHQ(const real_T b_Hinv[289], const real_T f[17], real_T
  x[17], int32_T n)
{
  for (int32_T b_i{0}; b_i < n; b_i++) {
    real_T b_Hinv_0;
    b_Hinv_0 = 0.0;
    for (int32_T i{0}; i < 17; i++) {
      b_Hinv_0 += -b_Hinv[17 * i + b_i] * f[i];
    }

    x[b_i] = b_Hinv_0;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
