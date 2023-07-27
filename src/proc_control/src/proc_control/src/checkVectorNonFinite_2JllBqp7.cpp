//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: checkVectorNonFinite_2JllBqp7.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "checkVectorNonFinite_2JllBqp7.h"
#include <cmath>

// Function for MATLAB Function: '<S208>/NLMPC'
int32_T checkVectorNonFinite_2JllBqp7(const real_T vec[130])
{
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = -1;
  while (allFinite && (idx_current + 2 <= 130)) {
    real_T allFinite_tmp;
    allFinite_tmp = vec[idx_current + 1];
    allFinite = ((!std::isinf(allFinite_tmp)) && (!std::isnan(allFinite_tmp)));
    idx_current++;
  }

  if (!allFinite) {
    if (std::isnan(vec[idx_current])) {
      status = -3;
    } else if (vec[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

//
// File trailer for generated code.
//
// [EOF]
//
