//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: eye_4CWHrAiR.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "eye_4CWHrAiR.h"
#include <cstring>

// Function for MATLAB Function: '<S133>/MATLAB Function2'
void eye_4CWHrAiR(real_T b_I[36])
{
  int32_T k_0;
  std::memset(&b_I[0], 0, 36U * sizeof(real_T));
  k_0 = 0;
  for (int32_T k{0}; k < 6; k++) {
    b_I[k_0] = 1.0;
    k_0 += 7;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
