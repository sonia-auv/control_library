//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: plook_u32u16_binckpan.cpp
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.101
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Feb 21 16:38:10 2023
//
#include "plook_u32u16_binckpan.h"
#include "binsearch_u32u16_prevIdx.h"
#include <string>
#include "rtwtypes.h"

uint32_T plook_u32u16_binckpan(uint16_T u, const uint16_T bp[], uint32_T
  maxIndex, uint32_T *prevIndex)
{
  uint32_T bpIndex;

  // Prelookup - Index only
  // Index Search method: 'binary'
  // Interpolation method: 'Use nearest'
  // Extrapolation method: 'Clip'
  // Use previous index: 'on'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    uint32_T startIndex;
    startIndex = *prevIndex;
    bpIndex = binsearch_u32u16_prevIdx(u, bp, startIndex, maxIndex);
    if ((bpIndex < maxIndex) && (static_cast<uint16_T>(static_cast<uint32_T>
          (bp[bpIndex + 1U]) - u) <= static_cast<uint16_T>(static_cast<uint32_T>
          (u) - bp[bpIndex]))) {
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
