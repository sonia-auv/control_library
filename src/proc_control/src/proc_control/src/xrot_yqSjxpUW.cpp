//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrot_yqSjxpUW.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.35
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  8 21:53:38 2022
//
#include "rtwtypes.h"
#include "xrot_yqSjxpUW.h"

// Function for MATLAB Function: '<S144>/MATLAB Function2'
void xrot_yqSjxpUW(real_T x[169], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  for (int32_T k{0}; k < 13; k++) {
    real_T temp_tmp_0;
    real_T temp_tmp_2;
    int32_T temp_tmp;
    int32_T temp_tmp_1;
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
