//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: xzlarf_2N2eIztg.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "rtwtypes.h"
#include "xzlarf_2N2eIztg.h"

// Function for MATLAB Function: '<S133>/MATLAB Function2'
void xzlarf_2N2eIztg(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C[169],
                     int32_T ic0, real_T work[13])
{
  int32_T coltop;
  int32_T jy;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n - 1;
    exitg2 = false;
    while ((!exitg2) && (lastc + 1 > 0)) {
      int32_T exitg1;
      coltop = lastc * 13 + ic0;
      jy = coltop;
      do {
        exitg1 = 0;
        if (jy <= (coltop + lastv) - 1) {
          if (C[jy - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jy++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T ia;
    int32_T ix;
    if (lastc + 1 != 0) {
      for (coltop = 0; coltop <= lastc; coltop++) {
        work[coltop] = 0.0;
      }

      coltop = 0;
      jy = 13 * lastc + ic0;
      for (int32_T iac{ic0}; iac <= jy; iac += 13) {
        ix = iv0;
        c = 0.0;
        d = (iac + lastv) - 1;
        for (ia = iac; ia <= d; ia++) {
          c += C[ia - 1] * C[ix - 1];
          ix++;
        }

        work[coltop] += c;
        coltop++;
      }
    }

    if (!(-tau == 0.0)) {
      coltop = ic0 - 1;
      jy = 0;
      for (int32_T iac{0}; iac <= lastc; iac++) {
        if (work[jy] != 0.0) {
          c = work[jy] * -tau;
          ix = iv0;
          d = coltop;
          ia = lastv + coltop;
          while (d + 1 <= ia) {
            C[d] += C[ix - 1] * c;
            ix++;
            d++;
          }
        }

        jy++;
        coltop += 13;
      }
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
