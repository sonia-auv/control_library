//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: updateWeights_YixtX2P7.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "updateWeights_YixtX2P7.h"

// Function for MATLAB Function: '<S176>/VariableHorizonOptimizer'
void updateWeights_YixtX2P7(const real_T b_signal[13], real_T W[13])
{
  for (int32_T ct{0}; ct < 13; ct++) {
    real_T b_signal_0;
    b_signal_0 = b_signal[ct];
    if (b_signal_0 < 0.0) {
      W[ct] = 0.0;
    } else {
      W[ct] = b_signal_0 * b_signal_0;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
