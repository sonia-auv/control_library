//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: trisolve_jVll4a1A.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "trisolve_jVll4a1A.h"

// Function for MATLAB Function: '<S287>/Correct'
void trisolve_jVll4a1A(real_T A, real_T B[13])
{
  for (int32_T j{0}; j < 13; j++) {
    if (B[j] != 0.0) {
      B[j] /= A;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
