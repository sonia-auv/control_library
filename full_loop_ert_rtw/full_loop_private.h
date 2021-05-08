//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop_private.h
//
// Code generated for Simulink model 'full_loop'.
//
// Model version                  : 1.699
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Fri May  7 11:30:20 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_full_loop_private_h_
#define RTW_HEADER_full_loop_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern uint32_T plook_u32d_binckpan(real_T u, const real_T bp[], uint32_T
  maxIndex, uint32_T *prevIndex);
extern uint32_T plook_u32u16_binckpan(uint16_T u, const uint16_T bp[], uint32_T
  maxIndex, uint32_T *prevIndex);
extern uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
extern uint32_T binsearch_u32u16_prevIdx(uint16_T u, const uint16_T bp[],
  uint32_T startIndex, uint32_T maxIndex);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

// private model entry point functions
extern void full_loop_derivatives();

#endif                                 // RTW_HEADER_full_loop_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
