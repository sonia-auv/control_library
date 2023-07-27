//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: DropConstraint_rIRdy5KO.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "DropConstraint_rIRdy5KO.h"

// Function for MATLAB Function: '<S204>/FixedHorizonOptimizer'
void DropConstraint_rIRdy5KO(int32_T kDrop, boolean_T iA[226], int32_T *nA,
  int32_T iC[226])
{
  if (kDrop > 0) {
    iA[iC[kDrop - 1] - 1] = false;
    if (kDrop < *nA) {
      for (int32_T i{kDrop}; i < *nA; i++) {
        iC[i - 1] = iC[i];
      }
    }

    iC[*nA - 1] = 0;
    (*nA)--;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
