//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node_private.h
//
// Code generated for Simulink model 'proc_control_node'.
//
// Model version                  : 3.48
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Aug  7 17:14:08 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_proc_control_node_private_h_
#define RTW_HEADER_proc_control_node_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "proc_control_node.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
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
extern int32_T div_nzp_s32(int32_T numerator, int32_T denominator);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator);
extern void proc_contro_QuaternionNormalise(real_T rtu_u, real_T rtu_u_o, real_T
  rtu_u_l, real_T rtu_u_d, real_T rty_y[4]);
extern void proc_control_no_MATLABFunction1(const real_T rtu_matrix[13], real_T
  rty_y[52], B_MATLABFunction1_proc_contro_T *localB);
extern void proc_control_no_Subsystem1_Init(real_T rty_Out1[6], real_T
  rty_Out1_h[2], real_T *rty_Out1_g, P_Subsystem1_proc_control_nod_T *localP);
extern void proc_control_node_Subsystem1(boolean_T rtu_Enable, const
  SL_Bus_proc_control_node_sonia_common_AddPose *rtu_In1, real_T rty_Out1[6],
  real_T rty_Out1_h[2], real_T *rty_Out1_g, DW_Subsystem1_proc_control_no_T
  *localDW);

// private model entry point functions
extern void proc_control_node_derivatives(void);

#endif                               // RTW_HEADER_proc_control_node_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
