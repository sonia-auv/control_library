//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: plook_u32d_binckpang.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "plook_u32d_binckpang.h"
#include "binsearch_u32d_prevIdx.h"
#include <string>
#include "rtwtypes.h"

uint32_T plook_u32d_binckpang(real_T u, const real_T bp[], uint32_T maxIndex,
  uint32_T *prevIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index only
  // Index Search method: 'binary'
  // Interpolation method: 'Use nearest'
  // Use previous index: 'on'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'on'

  if (u < bp[maxIndex]) {
    uint32_T startIndex;
    startIndex = *prevIndex;
    bpIndex = binsearch_u32d_prevIdx(u, bp, startIndex, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

//
// File trailer for generated code.
//
// [EOF]
//
