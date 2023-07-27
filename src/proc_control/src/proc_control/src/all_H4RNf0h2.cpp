//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: all_H4RNf0h2.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "all_H4RNf0h2.h"

// Function for MATLAB Function: '<S208>/NLMPC'
void all_H4RNf0h2(const boolean_T x[130], boolean_T y[13])
{
  int32_T i2;
  i2 = 1;
  for (int32_T i{0}; i < 13; i++) {
    int32_T a;
    int32_T ix;
    boolean_T exitg1;
    y[i] = true;
    a = i2 + 9;
    ix = i2;
    i2 += 10;
    exitg1 = false;
    while ((!exitg1) && (ix <= a)) {
      if (!x[ix - 1]) {
        y[i] = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
