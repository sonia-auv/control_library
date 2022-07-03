//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: WtMult_eD9sgCWi.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.69
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Jun 18 14:22:28 2022
//
#include "rtwtypes.h"
#include "WtMult_eD9sgCWi.h"

// Function for MATLAB Function: '<S199>/FixedHorizonOptimizer'
void WtMult_eD9sgCWi(const real_T W[8], const real_T M[1920], int32_T nwt,
                     real_T WM[1920])
{
  int16_T ixw;
  ixw = 1;
  for (int32_T i{0}; i < 80; i++) {
    real_T W_0;
    W_0 = W[ixw - 1];
    for (int32_T i_0{0}; i_0 < 24; i_0++) {
      int32_T WM_tmp;
      WM_tmp = 80 * i_0 + i;
      WM[WM_tmp] = M[WM_tmp] * W_0;
    }

    ixw = static_cast<int16_T>(ixw + 1);
    if (ixw > 8) {
      ixw = static_cast<int16_T>(static_cast<int16_T>(8 - nwt) + 1);
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
