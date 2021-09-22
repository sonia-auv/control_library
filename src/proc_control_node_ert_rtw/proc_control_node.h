//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node.h
//
// Code generated for Simulink model 'proc_control_node'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Sep  8 14:46:24 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_proc_control_node_h_
#define RTW_HEADER_proc_control_node_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "slros_initialize.h"
#include "proc_control_node_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block states (default storage) for system '<S85>/Subsystem2'
struct DW_Subsystem2_proc_control_no_T {
  int8_T Subsystem2_SubsysRanBC;       // '<S85>/Subsystem2'
};

// Block signals for system '<S190>/MATLAB Function1'
struct B_MATLABFunction1_proc_contro_T {
  real_T matrix[13];
};

// Block signals (default storage)
struct B_proc_control_node_T {
  real_T b_this[78013];
  real_T Su[9600];
  real_T b_SuJm[3840];
  real_T b_Kr[3840];
  real_T Cm[2640];
  real_T b_Kut[2560];
  real_T a[2560];
  real_T dv[2560];
  real_T b_Sx[2400];
  real_T r[2112];
  real_T Bu[1760];
  real_T b_Hv[1320];
  real_T dv1[1280];
  real_T q[1089];
  real_T b_Linv[1089];
  real_T c_Linv[1089];
  real_T c_A[1089];
  real_T b_D[1089];
  real_T b_H[1089];
  real_T U[1089];
  real_T RLinv[1089];
  real_T TL[1089];
  real_T QQ[1089];
  real_T RR[1089];
  real_T b[1024];
  real_T b_SuJm_m[1024];
  real_T b_Jm[1024];
  real_T CovMat[1024];
  real_T b_Su1[960];
  real_T Sum_cl[960];
  real_T b_B[896];
  real_T b_B_k[896];
  int8_T a_c[6400];
  real_T dv2[704];
  real_T b_Kx[640];
  real_T d[580];
  real_T o[512];
  real_T M[400];
  real_T L_tmp[400];
  real_T Kinv[400];
  real_T L_tmp_b[400];
  real_T L_tmp_p[400];
  real_T F[400];
  real_T A2[400];
  real_T U_c[400];
  real_T V[400];
  real_T A3[400];
  real_T A4[400];
  real_T A4_f[400];
  real_T b_A[400];
  real_T b_Kv[352];
  SL_Bus_proc_control_node_std_msgs_UInt16MultiArray msg;// '<S5>/MATLAB Function3' 
  uint32_T b_state[625];
  real_T xi[257];
  real_T b_Ku1[256];
  real_T b_Su1_g[256];
  real_T b_I1[256];
  real_T L[240];
  real_T b_C[240];
  real_T Nk[240];
  real_T L_tmp_g[240];
  real_T dv3[240];
  real_T CA[240];
  real_T CA_m[240];
  real_T Bv[220];
  SL_Bus_proc_control_node_sensor_msgs_Joy b_varargout_2;
  real_T Kinv_n[144];
  real_T C[144];                       // '<S110>/MATLAB Function2'
  real_T A[144];                       // '<S110>/MATLAB Function2'
  real_T Ppost[144];
  real_T c_A_p[144];
  int8_T c_I[1089];
  int8_T b_l[1089];
  real_T Dv[132];
  real_T Dvm[132];
  real_T CA_j[132];
  real_T y_n[130];                     // '<S191>/MATLAB Function1'
  real_T rseq[120];
  real_T B[96];                        // '<S110>/MATLAB Function2'
  real_T rtb_B_d[96];
  real_T Sum_g[96];
  real_T useq[88];                     // '<S144>/FixedHorizonOptimizer'
  real_T b_utarget[80];
  real_T H[72];
  real_T K[72];
  real_T H_l[72];
  real_T obj[72];
  real_T Opt[66];
  real_T Rhs[66];
  real_T b_Mlim[64];
  real_T b_Mlim_d[64];
  real_T b_Mu1[64];
  real_T b_Mlim_dy[64];
  real_T a__1[64];
  real_T cTol[64];
  real_T dv4[64];
  SL_Bus_proc_control_node_sensor_msgs_Imu In1;// '<S61>/In1'
  SL_Bus_proc_control_node_sensor_msgs_Imu msg_m;// '<S64>/MATLAB Function'
  real_T constValues[41];
  real_T pp_coefs[36];
  real_T dCoefs[36];
  real_T constValues_l[36];
  real_T dv5[36];
  real_T H_o[36];
  real_T c_A_b[36];
  real_T dCoeffs[36];
  real_T ddCoeffs[36];
  real_T zopt[33];
  real_T f[33];
  real_T r_n[33];
  real_T z[33];
  real_T b_Ac[33];
  real_T tau[33];
  real_T work[33];
  real_T varargin_1[33];
  real_T work_b[33];
  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL In1_f;// '<S62>/In1'
  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL msg_f;// '<S63>/MATLAB Function' 
  real_T randNums[27];
  real_T coefsWithFlatStart[24];
  real_T xk[20];
  real_T b_xoff[20];
  real_T xk_l[20];
  real_T Bu_h[20];
  int16_T iAnew[64];
  int16_T iC[64];
  real_T TmpSignalConversionAtTran_a[13];
  real_T dv6[13];
  real_T currPose[13];
  real_T y_innov[12];
  real_T TmpSignalConversionAtSFun_k[12];// '<S110>/MATLAB Function2'
  real_T dv7[12];
  real_T dv8[12];
  real_T rtb_A_b[12];
  real_T rtb_B_da[12];
  real_T rtb_C_e[12];
  real_T dv9[12];
  real_T rtb_A_bj[12];
  real_T b_C_j[12];
  real_T xe_post[12];
  real_T coefMat[12];
  real_T coeffMat[12];
  real_T vseq[11];
  real_T TmpSignalConversionAtMATLAB[9];// '<S192>/Subsystem1'
  real_T Rprior[9];
  real_T h1[9];
  real_T h1_f[9];
  real_T rmat[9];
  real_T c[9];
  real_T a_a[9];
  real_T c_j[9];
  real_T a_j[9];
  real_T c_o[9];
  real_T x[9];
  int8_T b_I[64];
  real_T twpt[8];
  real_T u[8];                         // '<S144>/FixedHorizonOptimizer'
  real_T u_scale[8];                   // '<S116>/u_scale'
  real_T dv10[8];
  real_T rtb_u_n[8];
  real_T U_i[8];
  boolean_T bv[64];
  SL_Bus_proc_control_node_sonia_common_AddPose b_varargout_2_o;
  SL_Bus_proc_control_node_geometry_msgs_Pose In1_n;// '<S230>/In1'
  SL_Bus_proc_control_node_geometry_msgs_Pose b_varargout_2_n;
  SL_Bus_proc_control_node_geometry_msgs_Twist In1_o;// '<S200>/In1'
  SL_Bus_proc_control_node_geometry_msgs_Twist msg_ff;// '<S83>/MATLAB Function1' 
  real_T MultiportSwitch[6];           // '<S194>/Multiport Switch'
  real_T Quaternion[130];              // '<S11>/Merge'
  real_T Merge[8];                     // '<S9>/Merge'
  real_T a__4[6];
  real_T Gain3[6];                     // '<S194>/Gain3'
  real_T Saturation[6];                // '<S199>/Saturation'
  real_T Gain_k[6];                    // '<S194>/Gain'
  real_T Sum_aw[6];                    // '<S194>/Sum'
  real_T rtb_Gain3_m[6];
  real_T constValues_c[6];
  real_T ze[6];
  int32_T ipiv[12];
  char_T b_zeroDelimTopic[32];
  real_T y[4];                         // '<S12>/Quaternion Normalise'
  real_T RotationTrajectory_o1[4];     // '<S209>/Rotation Trajectory'
  real_T rq[4];
  real_T b_q[4];
  real_T qRel[4];
  real_T TmpSignalConversionAtSFun_a[4];// '<S3>/Quaternion Normalise'
  real_T Transpose2[4];                // '<S19>/Transpose2'
  real_T dv11[4];
  real_T b_coeffVec[4];
  real_T psquared[4];
  char_T b_zeroDelimTopic_m[29];
  char_T b_zeroDelimTopic_m3[28];
  int8_T UnknownIn[28];
  char_T b_zeroDelimTopic_j[27];
  char_T b_zeroDelimTopic_h[25];
  char_T b_zeroDelimTopic_c[24];
  SL_Bus_proc_control_node_geometry_msgs_Vector3 msg_i;// '<S82>/MATLAB Function1' 
  real_T RotationTrajectory_o2[3];     // '<S209>/Rotation Trajectory'
  real_T Transpose[7];                 // '<S211>/Transpose'
  real_T DataTypeConversion[6];        // '<S207>/Data Type Conversion'
  real_T c_c[3];
  real_T s[3];
  real_T b_varargout_2_p[3];
  real_T Transpose_k[3];               // '<S19>/Transpose'
  real_T Gain_d[3];
  real_T gravityAccelGyroDiff[3];
  real_T offDiag[3];
  real_T magneticfield[3];
  real_T val[3];
  real_T val_p[3];
  real_T val_a[3];
  real_T val_e[3];
  real_T val_ax[3];
  real_T val_as[3];
  real_T val_i[3];
  real_T val_l[3];
  real_T val_o[3];
  real_T val_o2[3];
  real_T val_ip[3];
  real_T val_f[3];
  real_T val_iz[3];
  real_T val_ff[3];
  real_T val_g[3];
  real_T val_c[3];
  real_T val_o3[3];
  real_T val_lm[3];
  real_T val_m[3];
  real_T whiteNoiseDrift[3];
  real_T temperatureDrift[3];
  real_T a_m[3];
  real_T y_c[3];
  real_T temperatureDrift_f[3];
  real_T B_p[3];
  real_T y_e[3];
  real_T c_o4[3];
  real_T varargin_3[3];
  real_T val_h[3];
  real_T val_l5[3];
  real_T val_h2[3];
  real_T val_me[3];
  real_T val_mc[3];
  real_T val_h3[3];
  real_T val_cs[3];
  real_T val_k[3];
  real_T Reast[3];
  real_T c_p[3];
  char_T b_zeroDelimTopic_p[23];
  char_T b_zeroDelimTopic_p4[22];
  int8_T ipiv_a[20];
  char_T b_zeroDelimTopic_jd[20];
  char_T b_zeroDelimTopic_e[19];
  char_T b_zeroDelimTopic_o[16];
  uint16_T NtoRPM[8];                  // '<S15>/N to RPM'
  uint16_T y_f[8];                     // '<S1>/MATLAB Function'
  uint16_T NtoPWM[8];                  // '<S9>/N to PWM'
  real_T DataTypeConversion1[2];       // '<S207>/Data Type Conversion1'
  real_T obj_b[2];
  real_T obj_a[2];
  real_T obj_g[2];
  char_T b_zeroDelimTopic_ex[14];
  boolean_T x_f[13];
  int8_T rows[12];
  boolean_T flag[10];
  boolean_T flag_h[9];
  int8_T b_I_e[9];
  int8_T b_I_c[9];
  int8_T b_I_a[9];
  int8_T a_d[9];
  boolean_T b_a[9];
  real_T Z;       // '<S3>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
  real_T Y;       // '<S3>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
  real_T X;       // '<S3>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
  real_T Sum;                          // '<S175>/Sum'
  real_T Sum_c;                        // '<S174>/Sum'
  real_T Sum_f;                        // '<S173>/Sum'
  real_T qW2S[4];                      // '<S10>/Gain'
  real_T WorldPosition[3];             // '<S10>/Discrete-Time Integrator'
  real_T Divide3;                      // '<S158>/Divide3'
  real_T Divide2;                      // '<S158>/Divide2'
  real_T Divide1;                      // '<S158>/Divide1'
  real_T Divide;                       // '<S158>/Divide'
  real_T BodyPosition[3];              // '<S10>/Discrete-Time Integrator1'
  real_T DataTypeConversion2;          // '<S207>/Data Type Conversion2'
  real_T Transpose_i[16];              // '<S205>/Transpose'
  real_T Selector1[8];                 // '<S205>/Selector1'
  real_T Selector[6];                  // '<S205>/Selector'
  real_T MatrixConcatenate[2];         // '<S205>/Matrix Concatenate'
  real_T q0;                           // '<S163>/q0'
  real_T q1;                           // '<S163>/q1'
  real_T q2;                           // '<S163>/q2'
  real_T q3;                           // '<S163>/q3'
  real_T MATLABSystem[8];              // '<S109>/MATLAB System'
  real_T PulseGenerator;               // '<S110>/Pulse Generator'
  real_T status;                       // '<S144>/FixedHorizonOptimizer'
  real_T q0_c;                         // '<S92>/q0'
  real_T q1_p;                         // '<S92>/q1'
  real_T q2_k;                         // '<S92>/q2'
  real_T q3_d;                         // '<S92>/q3'
  real_T Quaternion_l[4];// '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T WorldPosition_o[3];
                         // '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T BodyVelocity[3];// '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T AngularRate[3]; // '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T y_g;                          // '<S3>/MATLAB Function'
  real_T VectorConcatenate[3];         // '<S49>/Vector Concatenate'
  real_T PWMtoN[8];                    // '<S15>/ PWM to N'
  real_T XDrift;                       // '<S16>/X Drift'
  real_T YDrift;                       // '<S16>/Y Drift'
  real_T ZDrift;                       // '<S16>/Z Drift'
  real_T XWave;                        // '<S16>/X Wave'
  real_T YWave;                        // '<S16>/Y Wave'
  real_T ZWave;                        // '<S16>/Z Wave'
  real_T WorldPosition_d[3];           // '<S1>/Integrator'
  real_T InitialBodyvelocity[3];       // '<S1>/Initial Body velocity '
  real_T BodyVelocity_c[3];            // '<S1>/Integrator2'
  real_T InitialAngularRates[3];       // '<S1>/Initial Angular Rates'
  real_T AngularRate_e[3];             // '<S1>/Integrator3'
  real_T Output;                       // '<S28>/Output'
  real_T Quaternion_k[4];              // '<S18>/Sum1'
  real_T Output_i;                     // '<S29>/Output'
  real_T AngularRate_d[3];             // '<S18>/Sum3'
  real_T Gain_c;                       // '<S37>/Gain'
  real_T Gain1;                        // '<S37>/Gain1'
  real_T Gain2;                        // '<S37>/Gain2'
  real_T Sum_d;                        // '<S37>/Sum'
  real_T Gain_cr;                      // '<S38>/Gain'
  real_T Gain1_d;                      // '<S38>/Gain1'
  real_T Gain2_n;                      // '<S38>/Gain2'
  real_T Sum_i;                        // '<S38>/Sum'
  real_T Gain_l;                       // '<S39>/Gain'
  real_T Gain1_o;                      // '<S39>/Gain1'
  real_T Gain2_i;                      // '<S39>/Gain2'
  real_T Sum_p;                        // '<S39>/Sum'
  real_T AHRS_o1[4];                   // '<S19>/AHRS'
  real_T y_gh[4];                      // '<S1>/Quaternion Normalise'
  real_T Position_dot[3];              // '<S1>/AUV State Equation'
  real_T Quaternion_dot[4];            // '<S1>/AUV State Equation'
  real_T BodyVelocity_dot[3];          // '<S1>/AUV State Equation'
  real_T AngularRates_dot[3];          // '<S1>/AUV State Equation'
  real_T Merge_f;                      // '<S51>/Merge'
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t21;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t65;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t62;
  real_T t70;
  real_T Product2_ei;                  // '<S98>/Product2'
  real_T Product3_gb;                  // '<S98>/Product3'
  real_T fcn5_e;                       // '<S89>/fcn5'
  real_T Product1_fh;                  // '<S98>/Product1'
  real_T fcn4_g;                       // '<S89>/fcn4'
  real_T Merge_a;                      // '<S99>/Merge'
  real_T fcn2;                         // '<S89>/fcn2'
  real_T Product_h;                    // '<S36>/Product'
  real_T rtb_y_a_idx_2;
  real_T rtb_y_a_idx_1;
  real_T rtb_y_a_idx_0;
  real_T rtb_sincos_o1_idx_2;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T d_p;
  real_T d1;
  real_T t25_tmp;
  real_T t25_tmp_m;
  real_T t65_tmp;
  real_T t65_tmp_o;
  real_T rtb_Sum_tmp;
  real_T Sum_a;                        // '<S169>/Sum'
  real_T Sum_p_n;                      // '<S168>/Sum'
  real_T Sum_l;                        // '<S167>/Sum'
  real_T normA;
  real_T b_s;
  real_T d_pe;
  real_T smax;
  real_T y_p;
  real_T BadH;
  real_T Sum_ft;
  real_T x_a;
  real_T x_b;
  real_T x_c;
  real_T x_d;
  real_T s_i;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T gyroOffsetErr_idx_0;
  real_T linAccelErr_idx_0;
  real_T gyroOffsetErr_idx_1;
  real_T linAccelErr_idx_1;
  real_T gyroOffsetErr_idx_2;
  real_T linAccelErr_idx_2;
  real_T smax_o;
  real_T s_k;
  real_T b_Kx_i;
  real_T b_Kr_o;
  real_T b_Ku1_m;
  real_T b_Kv_c;
  real_T b_Kut_f;
  real_T rMin;
  real_T Xnorm0;
  real_T cMin;
  real_T cVal;
  real_T t_h;
  real_T b_Ac_m;
  real_T b_Linv_a;
  real_T b_atmp;
  real_T beta1;
  real_T temp;
  real_T b_Wy;
  real_T W;
  real_T tb;
  real_T tc;
  real_T ab2;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T aasq;
  real_T n;
  real_T x_k;
  real_T d_u;
  real_T Constant2;
  real_T Constant3;
  real_T normH;
  real_T s_p;
  real_T ssq;
  real_T c_b;
  real_T b_temp;
  real_T smax_c;
  real_T y_nb;
  real_T finalTime;
  real_T wayPoints_idx_0;
  real_T wayPoints_idx_1;
  real_T coefMat_tmp;
  real_T xloc;
  real_T t8;
  real_T t9_i;
  real_T t10_m;
  real_T t11_j;
  real_T t12_e;
  real_T t13_m;
  real_T t15_m;
  real_T t20;
  real_T t33;
  real_T t37;
  real_T t39;
  real_T t62_j;
  real_T t65_f;
  real_T t66;
  real_T t16_a;
  real_T t17_g;
  real_T t18;
  real_T t19;
  real_T t21_n;
  real_T t22;
  real_T t23;
  real_T t73;
  real_T t80;
  real_T t81;
  real_T t84;
  real_T t45;
  real_T t55;
  real_T t63;
  real_T t86;
  real_T t87;
  real_T t56_d;
  real_T t85;
  real_T out1_tmp;
  real_T out1_tmp_n;
  real_T out1_tmp_c;
  real_T out1_tmp_f;
  real_T out1_tmp_p;
  real_T out1_tmp_p2;
  real_T out1_tmp_nj;
  real_T out1_tmp_k;
  real_T out1_tmp_n3;
  real_T absx;
  real_T z_o;
  real_T s_g;
  real_T R;
  real_T d2;
  real_T d3;
  real_T obj_c;
  real_T B_idx_0;
  real_T whiteNoiseDrift_idx_0;
  real_T B_idx_1;
  real_T whiteNoiseDrift_idx_1;
  real_T B_idx_2;
  real_T whiteNoiseDrift_idx_2;
  real_T x_idx_0;
  real_T x_idx_2;
  real_T x_idx_4;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t8_c;
  real_T t9_m;
  real_T t10_j;
  real_T t11_k;
  real_T t12_m;
  real_T t13_p;
  real_T t14_d;
  real_T t15_g;
  real_T t16_c;
  real_T t17_c;
  real_T t18_i;
  real_T t19_d;
  real_T t46;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t50;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t55_g;
  real_T t20_l;
  real_T t21_f;
  real_T t22_d;
  real_T t23_j;
  real_T t24;
  real_T t25_i;
  real_T t26_h;
  real_T t27_n;
  real_T t28_o;
  real_T t31;
  real_T t32;
  real_T t37_c;
  real_T t38;
  real_T t39_b;
  real_T t40;
  real_T Ane_tmp;
  real_T Ane_tmp_e;
  real_T Ane_tmp_d;
  real_T Ane_tmp_i;
  real_T obj_gs;
  real_T whiteNoiseDrift_idx_0_n;
  real_T temperatureDrift_idx_0;
  real_T whiteNoiseDrift_idx_1_l;
  real_T temperatureDrift_idx_1;
  real_T whiteNoiseDrift_idx_2_c;
  real_T x_idx_1;
  real_T x_idx_3;
  real_T x_idx_5;
  real_T obj_tmp_tmp;
  real_T pn_a;
  real_T pn_b;
  real_T pn_c;
  real_T pn_d;
  real_T qn_a;
  real_T qn_b;
  real_T qn_c;
  real_T qn_d;
  real_T pnCorrected_b;
  real_T pnCorrected_c;
  real_T pnCorrected_d;
  real_T linearScaling;
  real_T n_n;
  real_T q1n_b;
  real_T q1n_c;
  real_T q1n_d;
  real_T q2n_b;
  real_T q2n_c;
  real_T q2n_d;
  real_T dp;
  real_T theta0;
  real_T sinv_tmp;
  real_T n_tmp;
  real_T n_tmp_p;
  real_T n_tmp_d;
  real_T q2n_b_tmp;
  real_T q2n_c_tmp;
  real_T e_idx_0;
  real_T b_idx_0;
  real_T dp_tmp;
  real_T q1n_a;
  real_T q1n_b_o;
  real_T q1n_c_j;
  real_T q1n_d_c;
  real_T q2n_a;
  real_T q2n_b_h;
  real_T q2n_c_d;
  real_T dp_c;
  real_T theta0_p;
  real_T n_p;
  real_T b_x;
  real_T c_a;
  real_T mf_idx_2;
  real_T rtb_Transpose_k_idx_0;
  real_T R_o;
  real_T k;
  real_T U_j;
  real_T deltaq_a;
  real_T deltaq_b;
  real_T deltaq_c;
  real_T deltaq_d;
  real_T theta;
  real_T st;
  real_T tr;
  real_T d4;
  real_T ac2_p;
  real_T ad2_o;
  real_T bc2_l;
  real_T bd2_k;
  real_T cd2_j;
  real_T aasq_f;
  real_T n_c;
  real_T vnorm;
  real_T qnorm;
  real_T vscale_data;
  real_T x_data;
  real_T d5;
  SL_Bus_proc_control_node_std_msgs_UInt8 In1_b;// '<S232>/In1'
  uint32_T u32[2];
  uint32_T b_u[2];
  int8_T b_ipiv[6];
  int32_T ibmat;
  int32_T ixlast;
  int32_T i;
  int32_T dCoefs_tmp;
  int32_T L_tmp_tmp;
  int32_T i_f;
  int32_T LastPcov_PreviousInput_tmp;
  int32_T b_j;
  int32_T b_i;
  int32_T e;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T F_tmp;
  int32_T e_k;
  int32_T i4;
  int32_T i5;
  int32_T e_k_n;
  int32_T A2_tmp;
  int32_T A_tmp;
  int32_T b_j_i;
  int32_T c_l;
  int32_T ix;
  int32_T iy;
  int32_T jA;
  int32_T c_ix;
  int32_T d_i;
  int32_T ijA;
  int32_T kidx;
  int32_T b_j1;
  int32_T i2_k;
  int32_T i_fc;
  int32_T i6;
  int32_T kidx_a;
  int32_T i_d;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T CA_tmp;
  int32_T aoffset;
  int32_T b_i_e;
  int32_T i13;
  int32_T i14;
  int32_T i15;
  int32_T obj_tmp;
  int32_T H_tmp;
  int32_T Ppost_tmp;
  int32_T i16;
  int32_T jp;
  int32_T jBcol;
  int32_T kBcol;
  int32_T jj;
  int32_T jp1j;
  int32_T c_e;
  int32_T iy_b;
  int32_T jA_a;
  int32_T ijA_i;
  int32_T i_fa;
  int32_T i17;
  int32_T i_j;
  int32_T i18;
  int32_T U_tmp;
  int32_T U_tmp_o;
  int32_T lambda_tmp_tmp;
  int32_T i_fr;
  int32_T f_i;
  int32_T iC_o;
  int32_T RLinv_tmp_tmp;
  int32_T RLinv_tmp;
  int32_T j;
  int32_T i_l;
  int32_T ii;
  int32_T mmip1;
  int32_T knt;
  int32_T b_k;
  int32_T i_lu;
  int32_T mmi_tmp;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T jA_g;
  int32_T jy;
  int32_T ix_d;
  int32_T j_d;
  int32_T b_jo;
  int32_T ijA_f;
  int32_T i_js;
  int32_T i19;
  int32_T b_Kr_tmp;
  int32_T b_SuJm_tmp;
  int32_T i_h;
  int32_T i20;
  int32_T WM_tmp;
  int32_T b_jcol;
  int32_T nx;
  int32_T f_size_idx_1;
  int32_T b_x_data_tmp;
  int32_T i21;
  int32_T b_colIdx;
  int32_T i_c;
  int32_T k_n;
  int32_T b_j_k;
  int32_T b_kk;
  int32_T Tries;
  int32_T j_a;
  int32_T Tries_f;
  int32_T idxAjj;
  int32_T j_j;
  int32_T iy_k;
  int32_T d_b;
  int32_T ia_h;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_k_e;
  int32_T info;
  int32_T jBcol_h;
  int32_T jAcol;
  int32_T kBcol_k;
  int32_T k_j;
  int32_T b_i_o;
  int32_T Y_tmp;
  int32_T j_c;
  int32_T c_h;
  int32_T ix_i;
  int32_T iy_p;
  int32_T jA_f;
  int32_T c_ix_e;
  int32_T d_n;
  int32_T ijA_h;
  int32_T idx;
  int32_T c_j1;
  int32_T i22;
  int32_T idx_h;
  int32_T dCoeffs_tmp;
  int32_T ii_data_idx_0;
  int32_T tGreaterThanTfIdx_data_idx_0;
  int32_T iv0;
  int32_T b_ix_f;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  int32_T e_i;
  int32_T nx_f;
  int32_T k_c;
  int32_T f_size_idx_1_n;
  int32_T b_x_data_tmp_h;
  int32_T i23;
  int32_T nx_k;
  int32_T k_h;
  int32_T f_size_idx_1_b;
  int32_T b_x_data_tmp_o;
  int32_T i24;
  int32_T i25;
  int32_T itau;
  int32_T iaii;
  int32_T b_n;
  int32_T b_k_m;
  int32_T i_k;
  int32_T ix_j;
  int32_T b_iy_h;
  int32_T b_f;
  int32_T iac;
  int32_T d_d;
  int32_T ia_l;
  int32_T b_index;
  int32_T b_i_k;
  int32_T b_k_i;
  int32_T b_index_h;
  int32_T i26;
  int32_T iy_m;
  int32_T xpageoffset;
  int32_T b_ct;
  int32_T i_g;
  int32_T b_utarget_tmp;
  int32_T b_k_l;
  int32_T b_idx;
  int32_T b_m;
  int32_T i27;
  int32_T i28;
  int32_T i29;
  int32_T b_tmp;
  int32_T i30;
  int32_T b_i_n;
  int32_T nx_g;
  int32_T vscale_size_idx_1;
  int32_T x_data_tmp;
  int32_T jBcol_d;
  int32_T kAcol;
  int32_T j_m;
  int32_T k_f;
  int32_T i_gd;
  int32_T i31;
  int32_T i32;
  uint32_T bpIdx;
  uint32_T r_j;
  uint32_T mti;
  uint32_T y_cq;
  boolean_T b_e[4];
  int8_T b_data[3];
  int8_T f_data[3];
  int8_T b_data_m[3];
  int8_T f_data_o[3];
  int8_T b_data_a[3];
  int8_T f_data_j[3];
  boolean_T d_g[3];
  boolean_T d_j[3];
  boolean_T d_e[3];
  boolean_T y_j[3];
  boolean_T x_j[2];
  int16_T nA;
  int16_T kDrop;
  int16_T kNext;
  int16_T i33;
  int16_T i34;
  int16_T b_j_g;
  int16_T c_k;
  int16_T ixw;
  int16_T ixw_o;
  uint16_T rtb_y_f_h;
  uint16_T q_c;
  uint16_T b_x_a;
  int8_T rtPrevAction;
  int8_T rtAction;
  int8_T ipiv_l;
  int8_T i_jc;
  int8_T b_ipiv_i;
  uint8_T Data;  // '<S12>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
  uint8_T u_m;
  boolean_T OR;                        // '<S12>/OR'
  boolean_T Reset;                     // '<S229>/Reset'
  boolean_T Merge1;                    // '<S11>/Merge1'
  boolean_T y_ft;
  boolean_T SourceBlock_o1_d;          // '<S226>/SourceBlock'
  boolean_T SourceBlock_o1_h;          // '<S59>/SourceBlock'
  boolean_T SourceBlock_o1_a;          // '<S224>/SourceBlock'
  boolean_T OR1;                       // '<S12>/OR1'
  boolean_T SourceBlock_o1_n;          // '<S60>/SourceBlock'
  boolean_T isJamming;
  boolean_T cTolComputed;
  boolean_T DualFeasible;
  boolean_T ColdReset;
  boolean_T flag_o;
  boolean_T b_isvalid;
  boolean_T flag_i;
  boolean_T isempty;
  boolean_T y_e0;
  boolean_T nanPageIdx;
  SL_Bus_proc_control_node_std_msgs_Int8 BusAssignment;// '<S5>/Bus Assignment'
  SL_Bus_proc_control_node_std_msgs_Bool b_varargout_2_j;
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment_e;// '<S6>/Bus Assignment' 
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment_a;// '<S7>/Bus Assignment' 
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment1;// '<S5>/Bus Assignment1' 
  SL_Bus_proc_control_node_std_msgs_UInt8 b_varargout_2_o4;
  B_MATLABFunction1_proc_contro_T sf_MATLABFunction1_p;// '<S188>/MATLAB Function1' 
  B_MATLABFunction1_proc_contro_T sf_MATLABFunction1_n;// '<S190>/MATLAB Function1' 
};

// Block states (default storage) for system '<Root>'
struct DW_proc_control_node_T {
  TrajectoryManager_proc_contro_T obj; // '<S192>/MATLAB System'
  fusion_simulink_imuSensor_pro_T obj_c;// '<S19>/IMU'
  fusion_simulink_ahrsfilter_pr_T obj_l;// '<S19>/AHRS'
  OpenLoopController_proc_contr_T obj_m;// '<S109>/MATLAB System'
  robotics_slcore_internal_bl_b_T obj_j;// '<S209>/Rotation Trajectory'
  robotics_slcore_internal_bloc_T obj_jo;// '<S209>/Polynomial Trajectory1'
  AddPose_proc_control_node_T obj_a;   // '<S192>/MATLAB System1'
  ros_slroscpp_internal_block_S_T obj_a4;// '<S228>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S227>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S226>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S225>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S224>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_h;// '<S206>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_cs;// '<S195>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_mm;// '<S60>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_lu;// '<S59>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_le;// '<S107>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_lj;// '<S87>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_lf;// '<S81>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_eb;// '<S79>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_lfp;// '<S77>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_mj;// '<S76>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_p;// '<S75>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_ab;// '<S70>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_k;// '<S67>/SinkBlock'
  real_T Delay_DSTATE[3];              // '<S10>/Delay'
  real_T Delay_DSTATE_c;               // '<S155>/Delay'
  real_T DiscreteTimeIntegrator_DSTATE[3];// '<S10>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE[3];// '<S10>/Discrete-Time Integrator1'
  real_T Integrator_DSTATE[6];         // '<S198>/Integrator'
  real_T Integrator_DSTATE_l[6];       // '<S199>/Integrator'
  real_T Delay_DSTATE_d;               // '<S85>/Delay'
  real_T Delay_DSTATE_d1;              // '<S5>/Delay'
  real_T Delay_DSTATE_n;               // '<S208>/Delay'
  real_T DiscreteTimeIntegrator_DSTATE_b;// '<S209>/Discrete-Time Integrator'
  real_T UD_DSTATE[6];                 // '<S111>/UD'
  real_T last_mv_DSTATE[8];            // '<S116>/last_mv'
  real_T Delay1_DSTATE[8];             // '<S110>/Delay1'
  real_T LastPcov_PreviousInput[400];  // '<S116>/LastPcov'
  real_T last_x_PreviousInput[20];     // '<S116>/last_x'
  real_T XDrift_NextOutput;            // '<S16>/X Drift'
  real_T YDrift_NextOutput;            // '<S16>/Y Drift'
  real_T NextOutput;                   // '<S28>/White Noise'
  real_T NextOutput_b;                 // '<S29>/White Noise'
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<S189>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S12>/Scope'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<S10>/Scope3'

  struct {
    void *LoggedData;
  } Scope1_PWORK_n;                    // '<S10>/Scope1'

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    // '<S9>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     // '<S11>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     // '<S192>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_cp;                    // '<S209>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_nr;                   // '<S209>/Scope1'

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    // '<S190>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     // '<S190>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     // '<S109>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    // '<S2>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     // '<S2>/Scope'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<S2>/Scope2'

  struct {
    void *LoggedData;
  } Scope3_PWORK_c;                    // '<S2>/Scope3'

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<S2>/Scope4'

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     // '<S15>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_cg;                    // '<S1>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     // '<S16>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_a;                    // '<S16>/Scope1'

  int32_T clockTickCounter;            // '<S110>/Pulse Generator'
  uint32_T m_bpIndex[8];               // '<S9>/N to PWM'
  uint32_T m_bpIndex_m[8];             // '<S15>/ PWM to N'
  uint32_T m_bpIndex_c[8];             // '<S15>/N to RPM'
  uint32_T RandSeed;                   // '<S16>/X Drift'
  uint32_T RandSeed_a;                 // '<S16>/Y Drift'
  uint32_T RandSeed_j;                 // '<S28>/White Noise'
  uint32_T RandSeed_d;                 // '<S29>/White Noise'
  int_T Integrator1_IWORK;             // '<S1>/Integrator1'
  int_T Integrator_IWORK;              // '<S1>/Integrator'
  int_T Integrator2_IWORK;             // '<S1>/Integrator2'
  int_T Integrator3_IWORK;             // '<S1>/Integrator3'
  boolean_T Delay1_DSTATE_c;           // '<S192>/Delay1'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S10>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S10>/Discrete-Time Integrator1'
  int8_T If_ActiveSubsystem;           // '<S182>/If'
  int8_T Integrator_PrevResetState;    // '<S198>/Integrator'
  int8_T Integrator_PrevResetState_h;  // '<S199>/Integrator'
  int8_T SwitchCase_ActiveSubsystem;   // '<S11>/Switch Case'
  int8_T SwitchCase_ActiveSubsystem_l; // '<S9>/Switch Case'
  int8_T If_ActiveSubsystem_l;         // '<S99>/If'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S228>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_e;// '<S227>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S226>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_kg;// '<S225>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_d;// '<S224>/Enabled Subsystem'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S11>/If Action Subsystem'
  int8_T singleWptsTrajectory_SubsysRanB;// '<S11>/singleWpts Trajectory'
  int8_T EnabledSubsystem_SubsysRanBC_p;// '<S208>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S216>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S216>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_n;// '<S216>/If Action Subsystem'
  int8_T Subsystem1_SubsysRanBC;       // '<S192>/Subsystem1'
  int8_T EnabledSubsystem_SubsysRanBC_o;// '<S206>/Enabled Subsystem'
  int8_T Pretraitement_SubsysRanBC;    // '<S192>/Pre-traitement'
  int8_T SubsystemAuto_SubsysRanBC;    // '<S11>/SubsystemAuto'
  int8_T SubsystemManual_SubsysRanBC;  // '<S11>/SubsystemManual'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S195>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_b;// '<S182>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_i;// '<S182>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_l;// '<S182>/If Action Subsystem'
  int8_T IDLE_SubsysRanBC;             // '<S9>/IDLE'
  int8_T JoyStickOpenLoop_SubsysRanBC; // '<S9>/JoyStick OpenLoop'
  int8_T QuaternionNonlinearMPC_SubsysRa;// '<S9>/Quaternion Non linear MPC'
  int8_T IfActionSubsystem2_SubsysRanB_o;// '<S149>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_h;// '<S149>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_c;// '<S149>/If Action Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_g;// '<S99>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_b;// '<S99>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_m;// '<S99>/If Action Subsystem'
  int8_T SendTargetReached_SubsysRanBC;// '<Root>/Send Target Reached '
  int8_T ROSOutput_SubsysRanBC;        // '<Root>/ROS Output'
  int8_T EnabledSubsystem_SubsysRanBC_g;// '<S60>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_pz;// '<S59>/Enabled Subsystem'
  int8_T Plotvalues_SubsysRanBC;       // '<Root>/Plot values'
  int8_T If_ActiveSubsystem_j;         // '<S51>/If'
  int8_T IfActionSubsystem2_SubsysRanB_d;// '<S51>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_k;// '<S51>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_f;// '<S51>/If Action Subsystem'
  int8_T ModlePhysique_SubsysRanBC;    // '<Root>/Modèle Physique'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S10>/Discrete-Time Integrator'
  boolean_T Memory_PreviousInput;      // '<S229>/Memory'
  boolean_T Memory_PreviousInput_o[64];// '<S116>/Memory'
  boolean_T ROSOutput_MODE;            // '<Root>/ROS Output'
  boolean_T Plotvalues_MODE;           // '<Root>/Plot values'
  boolean_T ModlePhysique_MODE;        // '<Root>/Modèle Physique'
  DW_Subsystem2_proc_control_no_T Subsystem2_p;// '<S155>/Subsystem2'
  DW_Subsystem2_proc_control_no_T Subsystem2;// '<S85>/Subsystem2'
};

// Continuous states (default storage)
struct X_proc_control_node_T {
  real_T Integrator1_CSTATE[4];        // '<S1>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S20>/Transfer Fcn'
  real_T TransferFcn_CSTATE_o;         // '<S21>/Transfer Fcn'
  real_T TransferFcn_CSTATE_p;         // '<S22>/Transfer Fcn'
  real_T TransferFcn_CSTATE_a;         // '<S23>/Transfer Fcn'
  real_T TransferFcn_CSTATE_f;         // '<S24>/Transfer Fcn'
  real_T TransferFcn_CSTATE_e;         // '<S25>/Transfer Fcn'
  real_T TransferFcn_CSTATE_ft;        // '<S26>/Transfer Fcn'
  real_T TransferFcn_CSTATE_fu;        // '<S27>/Transfer Fcn'
  real_T Integrator_CSTATE[3];         // '<S1>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S1>/Integrator2'
  real_T Integrator3_CSTATE[3];        // '<S1>/Integrator3'
};

// State derivatives (default storage)
struct XDot_proc_control_node_T {
  real_T Integrator1_CSTATE[4];        // '<S1>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S20>/Transfer Fcn'
  real_T TransferFcn_CSTATE_o;         // '<S21>/Transfer Fcn'
  real_T TransferFcn_CSTATE_p;         // '<S22>/Transfer Fcn'
  real_T TransferFcn_CSTATE_a;         // '<S23>/Transfer Fcn'
  real_T TransferFcn_CSTATE_f;         // '<S24>/Transfer Fcn'
  real_T TransferFcn_CSTATE_e;         // '<S25>/Transfer Fcn'
  real_T TransferFcn_CSTATE_ft;        // '<S26>/Transfer Fcn'
  real_T TransferFcn_CSTATE_fu;        // '<S27>/Transfer Fcn'
  real_T Integrator_CSTATE[3];         // '<S1>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S1>/Integrator2'
  real_T Integrator3_CSTATE[3];        // '<S1>/Integrator3'
};

// State disabled
struct XDis_proc_control_node_T {
  boolean_T Integrator1_CSTATE[4];     // '<S1>/Integrator1'
  boolean_T TransferFcn_CSTATE;        // '<S20>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_o;      // '<S21>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_p;      // '<S22>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_a;      // '<S23>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_f;      // '<S24>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_e;      // '<S25>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_ft;     // '<S26>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_fu;     // '<S27>/Transfer Fcn'
  boolean_T Integrator_CSTATE[3];      // '<S1>/Integrator'
  boolean_T Integrator2_CSTATE[3];     // '<S1>/Integrator2'
  boolean_T Integrator3_CSTATE[3];     // '<S1>/Integrator3'
};

// Zero-crossing (trigger) state
struct PrevZCX_proc_control_node_T {
  ZCSigState Trajectorygenerator_Reset_ZCE;// '<S192>/Trajectory generator'
  ZCSigState SendTargetReached_Trig_ZCE;// '<Root>/Send Target Reached '
  ZCSigState Integrator1_Reset_ZCE;    // '<S1>/Integrator1'
  ZCSigState Integrator_Reset_ZCE;     // '<S1>/Integrator'
  ZCSigState Integrator2_Reset_ZCE;    // '<S1>/Integrator2'
  ZCSigState Integrator3_Reset_ZCE;    // '<S1>/Integrator3'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters for system: '<S85>/Subsystem2'
struct P_Subsystem2_proc_control_nod_T_ {
  real_T Quat_Y0;                      // Computed Parameter: Quat_Y0
                                          //  Referenced by: '<S91>/Quat'

  real_T siydevant_Value[3];           // Expression: [0,pi,-pi/2]
                                          //  Referenced by: '<S91>/si y devant'

  real_T u2_Gain;                      // Expression: 0.5
                                          //  Referenced by: '<S92>/1//2'

};

// Parameters (default storage)
struct P_proc_control_node_T_ {
  struct_ItE4fzFYlf4Io3uBaGCY9F MPC;   // Variable: MPC
                                          //  Referenced by:
                                          //    '<S9>/Saturation'
                                          //    '<S110>/Constant3'
                                          //    '<S188>/Constant3'
                                          //    '<S190>/Constant3'
                                          //    '<S191>/Constant3'

  struct_XEwOoQFSJ0yXWTYDIQhbTC physics;// Variable: physics
                                           //  Referenced by: '<S109>/MATLAB System'

  real_T N[201];                       // Variable: N
                                          //  Referenced by:
                                          //    '<S9>/N to PWM'
                                          //    '<S15>/ PWM to N'
                                          //    '<S15>/N to RPM'

  real_T RPM[201];                     // Variable: RPM
                                          //  Referenced by: '<S15>/N to RPM'

  real_T binv[48];                     // Variable: binv
                                          //  Referenced by: '<S109>/MATLAB System'

  real_T dMaxX;                        // Variable: dMaxX
                                          //  Referenced by: '<S16>/X Drift'

  real_T dMaxY;                        // Variable: dMaxY
                                          //  Referenced by: '<S16>/Y Drift'

  real_T dMinX;                        // Variable: dMinX
                                          //  Referenced by: '<S16>/X Drift'

  real_T dMinY;                        // Variable: dMinY
                                          //  Referenced by: '<S16>/Y Drift'

  real_T dSeedX;                       // Variable: dSeedX
                                          //  Referenced by: '<S16>/X Drift'

  real_T dSeedY;                       // Variable: dSeedY
                                          //  Referenced by: '<S16>/Y Drift'

  real_T waPhi;                        // Variable: waPhi
                                          //  Referenced by: '<S16>/Roll Wave'

  real_T waPsi;                        // Variable: waPsi
                                          //  Referenced by: '<S16>/Yaw Wave'

  real_T waTheta;                      // Variable: waTheta
                                          //  Referenced by: '<S16>/Pitch Wave'

  real_T waX;                          // Variable: waX
                                          //  Referenced by: '<S16>/X Wave'

  real_T waY;                          // Variable: waY
                                          //  Referenced by: '<S16>/Y Wave'

  real_T waZ;                          // Variable: waZ
                                          //  Referenced by: '<S16>/Z Wave'

  real_T wfPhi;                        // Variable: wfPhi
                                          //  Referenced by: '<S16>/Roll Wave'

  real_T wfPsi;                        // Variable: wfPsi
                                          //  Referenced by: '<S16>/Yaw Wave'

  real_T wfTheta;                      // Variable: wfTheta
                                          //  Referenced by: '<S16>/Pitch Wave'

  real_T wfX;                          // Variable: wfX
                                          //  Referenced by: '<S16>/X Wave'

  real_T wfY;                          // Variable: wfY
                                          //  Referenced by: '<S16>/Y Wave'

  real_T wfZ;                          // Variable: wfZ
                                          //  Referenced by: '<S16>/Z Wave'

  real_T wn_l;                         // Variable: wn_l
                                          //  Referenced by: '<S194>/Gain'

  real_T wpPhi;                        // Variable: wpPhi
                                          //  Referenced by: '<S16>/Roll Wave'

  real_T wpPsi;                        // Variable: wpPsi
                                          //  Referenced by: '<S16>/Yaw Wave'

  real_T wpTheta;                      // Variable: wpTheta
                                          //  Referenced by: '<S16>/Pitch Wave'

  real_T wpX;                          // Variable: wpX
                                          //  Referenced by: '<S16>/X Wave'

  real_T wpY;                          // Variable: wpY
                                          //  Referenced by: '<S16>/Y Wave'

  real_T wpZ;                          // Variable: wpZ
                                          //  Referenced by: '<S16>/Z Wave'

  real_T zeta_l;                       // Variable: zeta_l
                                          //  Referenced by: '<S194>/Gain'

  uint16_T PWM[201];                   // Variable: PWM
                                          //  Referenced by:
                                          //    '<S9>/N to PWM'
                                          //    '<S15>/ PWM to N'

  real_T BandLimitedWhiteNoise_Cov; // Mask Parameter: BandLimitedWhiteNoise_Cov
                                       //  Referenced by: '<S28>/Output'

  real_T BandLimitedWhiteNoise1_Cov;
                                   // Mask Parameter: BandLimitedWhiteNoise1_Cov
                                      //  Referenced by: '<S29>/Output'

  real_T SecondOrderFilter_FilterType;
                                 // Mask Parameter: SecondOrderFilter_FilterType
                                    //  Referenced by: '<S194>/Constant4'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S111>/UD'

  real_T BandLimitedWhiteNoise_seed;
                                   // Mask Parameter: BandLimitedWhiteNoise_seed
                                      //  Referenced by: '<S28>/White Noise'

  real_T BandLimitedWhiteNoise1_seed;
                                  // Mask Parameter: BandLimitedWhiteNoise1_seed
                                     //  Referenced by: '<S29>/White Noise'

  boolean_T MinMaxRunningResettable_vinit;
                                // Mask Parameter: MinMaxRunningResettable_vinit
                                   //  Referenced by:
                                   //    '<S229>/Initial Condition'
                                   //    '<S229>/Memory'

  SL_Bus_proc_control_node_std_msgs_UInt16MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S71>/Constant'

  SL_Bus_proc_control_node_sensor_msgs_Joy Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S234>/Out1'

  SL_Bus_proc_control_node_sensor_msgs_Joy Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                               //  Referenced by: '<S228>/Constant'

  SL_Bus_proc_control_node_sensor_msgs_Imu Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                                        //  Referenced by: '<S61>/Out1'

  SL_Bus_proc_control_node_sensor_msgs_Imu Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                               //  Referenced by: '<S59>/Constant'

  SL_Bus_proc_control_node_sensor_msgs_Imu Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                               //  Referenced by: '<S68>/Constant'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                                     //  Referenced by: '<S62>/Out1'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S60>/Constant'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S65>/Constant'

  struct_OiyVcB1FUG5CFSJbxuJtpE CleanOutput_Y0;// Computed Parameter: CleanOutput_Y0
                                                  //  Referenced by: '<S1>/Clean Output'

  struct_OiyVcB1FUG5CFSJbxuJtpE Output_Y0;// Computed Parameter: Output_Y0
                                             //  Referenced by: '<S4>/Output'

  struct_Ly3A2XJK4hMO23MSCkZ3VD SensorsOutput_Y0;// Computed Parameter: SensorsOutput_Y0
                                                    //  Referenced by: '<S1>/Sensors Output'

  SL_Bus_proc_control_node_sonia_common_AddPose Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                             //  Referenced by: '<S210>/Out1'

  SL_Bus_proc_control_node_sonia_common_AddPose Constant_Value_lq;// Computed Parameter: Constant_Value_lq
                                                                     //  Referenced by: '<S206>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Pose Out1_Y0_jt;// Computed Parameter: Out1_Y0_jt
                                                            //  Referenced by: '<S230>/Out1'

  SL_Bus_proc_control_node_geometry_msgs_Pose Constant_Value_a3;// Computed Parameter: Constant_Value_a3
                                                                   //  Referenced by: '<S224>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Twist Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                   //  Referenced by: '<S105>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Twist Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                            //  Referenced by: '<S200>/Out1'

  SL_Bus_proc_control_node_geometry_msgs_Twist Constant_Value_hg;// Computed Parameter: Constant_Value_hg
                                                                    //  Referenced by: '<S195>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Vector3 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                     //  Referenced by: '<S84>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                             //  Referenced by: '<S73>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                             //  Referenced by: '<S78>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_m1;// Computed Parameter: Constant_Value_m1
                                                              //  Referenced by: '<S80>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                      //  Referenced by: '<S231>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_ee;// Computed Parameter: Constant_Value_ee
                                                              //  Referenced by: '<S225>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_n;// Computed Parameter: Out1_Y0_n
                                                      //  Referenced by: '<S233>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_a2;// Computed Parameter: Constant_Value_a2
                                                              //  Referenced by: '<S227>/Constant'

  SL_Bus_proc_control_node_std_msgs_Int8 Constant_Value_ly;// Computed Parameter: Constant_Value_ly
                                                              //  Referenced by: '<S72>/Constant'

  SL_Bus_proc_control_node_std_msgs_UInt8 Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                       //  Referenced by: '<S232>/Out1'

  SL_Bus_proc_control_node_std_msgs_UInt8 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                              //  Referenced by: '<S226>/Constant'

  real_T AHRS_AccelerometerNoise;      // Expression: 0.0001924722
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_GyroscopeNoise;          // Expression: 9.1385e-5
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_MagnetometerNoise;       // Expression: 0.1
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_GyroscopeDriftNoise;     // Expression: 3.0462e-13
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_LinearAccelerationNoise; // Expression: 0.0096236100000000012
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_MagneticDisturbanceNoise;// Expression: 0.5
                                          //  Referenced by: '<S19>/AHRS'

  real_T AHRS_LinearAccelerationDecayFac;// Expression: 0.5
                                            //  Referenced by: '<S19>/AHRS'

  real_T AHRS_MagneticDisturbanceDecayFa;// Expression: 0.5
                                            //  Referenced by: '<S19>/AHRS'

  real_T AHRS_ExpectedMagneticFieldStren;// Expression: 50
                                            //  Referenced by: '<S19>/AHRS'

  real_T IMU_Temperature;              // Expression: 25
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagneticFieldNED[3];  // Expression: [ 27.5550, -2.4169, -16.0849 ]
                                      //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsMeasurementRange;// Expression: Inf
                                            //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsResolution;    // Expression: 0
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsConstantBias[3];// Expression: [ 0, 0, 0 ]
                                           //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsAxesMisalignment[3];// Expression: [ 0, 0, 0 ]
                                               //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsNoiseDensity[3];// Expression: [ 0, 0, 0 ]
                                           //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsBiasInstability[3];// Expression: [ 0, 0, 0 ]
                                              //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsRandomWalk[3]; // Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsTemperatureBias[3];// Expression: [ 0, 0, 0 ]
                                              //  Referenced by: '<S19>/IMU'

  real_T IMU_AccelParamsTemperatureScale[3];// Expression: [ 0, 0, 0 ]
                                               //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsMeasurementRange;// Expression: Inf
                                           //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsResolution;     // Expression: 0
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsConstantBias[3];// Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsAxesMisalignment[3];// Expression: [ 0, 0, 0 ]
                                              //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsAccelerationBias[3];// Expression: [ 0, 0, 0 ]
                                              //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsNoiseDensity[3];// Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsBiasInstability[3];// Expression: [ 0, 0, 0 ]
                                             //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsRandomWalk[3];  // Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsTemperatureBias[3];// Expression: [ 0, 0, 0 ]
                                             //  Referenced by: '<S19>/IMU'

  real_T IMU_GyroParamsTemperatureScaleF[3];// Expression: [ 0, 0, 0 ]
                                               //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsMeasurementRange;// Expression: Inf
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsResolution;      // Expression: 0
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsConstantBias[3]; // Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsAxesMisalignment[3];// Expression: [ 0, 0, 0 ]
                                             //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsNoiseDensity[3]; // Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsBiasInstability[3];// Expression: [ 0, 0, 0 ]
                                            //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsRandomWalk[3];   // Expression: [ 0, 0, 0 ]
                                          //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsTemperatureBias[3];// Expression: [ 0, 0, 0 ]
                                            //  Referenced by: '<S19>/IMU'

  real_T IMU_MagParamsTemperatureScaleFa[3];// Expression: [ 0, 0, 0 ]
                                               //  Referenced by: '<S19>/IMU'

  real_T TransferFcn_A;                // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<S20>/Transfer Fcn'

  real_T TransferFcn_C;                // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<S20>/Transfer Fcn'

  real_T TransferFcn_A_j;              // Computed Parameter: TransferFcn_A_j
                                          //  Referenced by: '<S21>/Transfer Fcn'

  real_T TransferFcn_C_m;              // Computed Parameter: TransferFcn_C_m
                                          //  Referenced by: '<S21>/Transfer Fcn'

  real_T TransferFcn_A_h;              // Computed Parameter: TransferFcn_A_h
                                          //  Referenced by: '<S22>/Transfer Fcn'

  real_T TransferFcn_C_l;              // Computed Parameter: TransferFcn_C_l
                                          //  Referenced by: '<S22>/Transfer Fcn'

  real_T TransferFcn_A_i;              // Computed Parameter: TransferFcn_A_i
                                          //  Referenced by: '<S23>/Transfer Fcn'

  real_T TransferFcn_C_f;              // Computed Parameter: TransferFcn_C_f
                                          //  Referenced by: '<S23>/Transfer Fcn'

  real_T TransferFcn_A_jp;             // Computed Parameter: TransferFcn_A_jp
                                          //  Referenced by: '<S24>/Transfer Fcn'

  real_T TransferFcn_C_n;              // Computed Parameter: TransferFcn_C_n
                                          //  Referenced by: '<S24>/Transfer Fcn'

  real_T TransferFcn_A_l;              // Computed Parameter: TransferFcn_A_l
                                          //  Referenced by: '<S25>/Transfer Fcn'

  real_T TransferFcn_C_nr;             // Computed Parameter: TransferFcn_C_nr
                                          //  Referenced by: '<S25>/Transfer Fcn'

  real_T TransferFcn_A_p;              // Computed Parameter: TransferFcn_A_p
                                          //  Referenced by: '<S26>/Transfer Fcn'

  real_T TransferFcn_C_h;              // Computed Parameter: TransferFcn_C_h
                                          //  Referenced by: '<S26>/Transfer Fcn'

  real_T TransferFcn_A_n;              // Computed Parameter: TransferFcn_A_n
                                          //  Referenced by: '<S27>/Transfer Fcn'

  real_T TransferFcn_C_fa;             // Computed Parameter: TransferFcn_C_fa
                                          //  Referenced by: '<S27>/Transfer Fcn'

  real_T ZDrift_Value;                 // Expression: 0
                                          //  Referenced by: '<S16>/Z Drift'

  real_T XWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S16>/X Wave'

  real_T YWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S16>/Y Wave'

  real_T ZWave_Bias;                   // Expression: 0
                                          //  Referenced by: '<S16>/Z Wave'

  real_T RollWave_Bias;                // Expression: 0
                                          //  Referenced by: '<S16>/Roll Wave'

  real_T PitchWave_Bias;               // Expression: 0
                                          //  Referenced by: '<S16>/Pitch Wave'

  real_T YawWave_Bias;                 // Expression: 0
                                          //  Referenced by: '<S16>/Yaw Wave'

  real_T InitialBodyvelocity_Value[3]; // Expression: [0,0,0]
                                          //  Referenced by: '<S1>/Initial Body velocity '

  real_T InitialAngularRates_Value[3]; // Expression: [0,0,0]
                                          //  Referenced by: '<S1>/Initial Angular Rates'

  real_T WhiteNoise_Mean;              // Expression: 0
                                          //  Referenced by: '<S28>/White Noise'

  real_T WhiteNoise_StdDev;            // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S28>/White Noise'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S19>/Gain'

  real_T WhiteNoise_Mean_e;            // Expression: 0
                                          //  Referenced by: '<S29>/White Noise'

  real_T WhiteNoise_StdDev_d;         // Computed Parameter: WhiteNoise_StdDev_d
                                         //  Referenced by: '<S29>/White Noise'

  real_T ydevantZhaut_Value[3];        // Expression: [0,pi,pi/2]
                                          //  Referenced by: '<S18>/ y devant Z haut'

  real_T u2_Gain;                      // Expression: 0.5
                                          //  Referenced by: '<S33>/1//2'

  real_T Gain_Gain_j;                  // Expression: 2
                                          //  Referenced by: '<S37>/Gain'

  real_T Gain1_Gain;                   // Expression: 2
                                          //  Referenced by: '<S37>/Gain1'

  real_T Constant_Value_k;             // Expression: 0.5
                                          //  Referenced by: '<S37>/Constant'

  real_T Gain2_Gain;                   // Expression: 2
                                          //  Referenced by: '<S37>/Gain2'

  real_T Gain_Gain_e;                  // Expression: 2
                                          //  Referenced by: '<S38>/Gain'

  real_T Gain1_Gain_e;                 // Expression: 2
                                          //  Referenced by: '<S38>/Gain1'

  real_T Constant_Value_gp;            // Expression: 0.5
                                          //  Referenced by: '<S38>/Constant'

  real_T Gain2_Gain_l;                 // Expression: 2
                                          //  Referenced by: '<S38>/Gain2'

  real_T Gain_Gain_m;                  // Expression: 2
                                          //  Referenced by: '<S39>/Gain'

  real_T Gain1_Gain_g;                 // Expression: 2
                                          //  Referenced by: '<S39>/Gain1'

  real_T Constant_Value_i;             // Expression: 0.5
                                          //  Referenced by: '<S39>/Constant'

  real_T Gain2_Gain_b;                 // Expression: 2
                                          //  Referenced by: '<S39>/Gain2'

  real_T Constant_Value_g4;            // Expression: 1
                                          //  Referenced by: '<S52>/Constant'

  real_T Constant_Value_m5;            // Expression: 1
                                          //  Referenced by: '<S53>/Constant'

  real_T Constant_Value_i1;            // Expression: 1
                                          //  Referenced by: '<S100>/Constant'

  real_T Constant_Value_a3q;           // Expression: 1
                                          //  Referenced by: '<S101>/Constant'

  real_T Constant_Value_kr;            // Expression: 1
                                          //  Referenced by: '<S150>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S151>/Constant'

  real_T Output_Y0_n;                  // Computed Parameter: Output_Y0_n
                                          //  Referenced by: '<S110>/Output'

  real_T isActive_Y0;                  // Computed Parameter: isActive_Y0
                                          //  Referenced by: '<S110>/isActive'

  real_T LastPcov_InitialCondition[400];// Expression: lastPcov
                                           //  Referenced by: '<S116>/LastPcov'

  real_T G_zero_Value;                 // Expression: zeros(1,1)
                                          //  Referenced by: '<S112>/G_zero'

  real_T ywt_zero_Value[12];           // Expression: zeros(12,1)
                                          //  Referenced by: '<S112>/y.wt_zero'

  real_T uwt_zero_Value[8];            // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/u.wt_zero'

  real_T duwt_zero_Value[8];           // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/du.wt_zero'

  real_T extmv_zero_Value[8];          // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/ext.mv_zero'

  real_T extmv_scale_Gain[8];          // Expression: RMVscale
                                          //  Referenced by: '<S116>/ext.mv_scale'

  real_T last_mv_InitialCondition[8];  // Expression: lastu+uoff
                                          //  Referenced by: '<S116>/last_mv'

  real_T last_x_InitialCondition[20];  // Expression: lastx+xoff
                                          //  Referenced by: '<S116>/last_x'

  real_T Constant4_Value[12];          // Expression: [0,0,0,0,0,0,0,0,0,0,0,0]
                                          //  Referenced by: '<S110>/Constant4'

  real_T md_zero_Value;                // Expression: zeros(1,1)
                                          //  Referenced by: '<S112>/md_zero'

  real_T umin_zero_Value[8];           // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/umin_zero'

  real_T umax_zero_Value[8];           // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/umax_zero'

  real_T ymin_zero_Value[12];          // Expression: zeros(12,1)
                                          //  Referenced by: '<S112>/ymin_zero'

  real_T ymax_zero_Value[12];          // Expression: zeros(12,1)
                                          //  Referenced by: '<S112>/ymax_zero'

  real_T E_zero_Value[8];              // Expression: zeros(1,8)
                                          //  Referenced by: '<S112>/E_zero'

  real_T umin_scale4_Gain[8];      // Expression: MVscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S116>/umin_scale4'

  real_T F_zero_Value[12];             // Expression: zeros(1,12)
                                          //  Referenced by: '<S112>/F_zero'

  real_T ymin_scale1_Gain[12];      // Expression: Yscale(:,ones(1,max(nCC,1)))'
                                       //  Referenced by: '<S116>/ymin_scale1'

  real_T S_zero_Value;                 // Expression: zeros(1,1)
                                          //  Referenced by: '<S112>/S_zero'

  real_T ymin_scale2_Gain;         // Expression: MDscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S116>/ymin_scale2'

  real_T switch_zero_Value;            // Expression: zeros(1,1)
                                          //  Referenced by: '<S112>/switch_zero'

  real_T mvtarget_zero_Value[8];       // Expression: zeros(8,1)
                                          //  Referenced by: '<S112>/mv.target_zero'

  real_T uref_scale_Gain[8];           // Expression: RMVscale
                                          //  Referenced by: '<S116>/uref_scale'

  real_T ecrwt_zero_Value;             // Expression: zeros(1,1)
                                          //  Referenced by: '<S112>/ecr.wt_zero'

  real_T Delay1_InitialCondition[8];   // Expression: [0,0,0,0,0,0,0,0].'
                                          //  Referenced by: '<S110>/Delay1'

  real_T u_scale_Gain[8];              // Expression: MVscale
                                          //  Referenced by: '<S116>/u_scale'

  real_T PulseGenerator_Amp;           // Expression: 1
                                          //  Referenced by: '<S110>/Pulse Generator'

  real_T PulseGenerator_Period;        // Expression: 2
                                          //  Referenced by: '<S110>/Pulse Generator'

  real_T PulseGenerator_Duty;          // Expression: 1
                                          //  Referenced by: '<S110>/Pulse Generator'

  real_T PulseGenerator_PhaseDelay;    // Expression: 0
                                          //  Referenced by: '<S110>/Pulse Generator'

  real_T MATLABSystem_k;               // Expression: 40
                                          //  Referenced by: '<S109>/MATLAB System'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S111>/TSamp'

  real_T Constant1_Value[8];           // Expression: zeros(1,8)
                                          //  Referenced by: '<S108>/Constant1'

  real_T Constant_Value_mz;            // Expression: 1
                                          //  Referenced by: '<S183>/Constant'

  real_T Constant_Value_df;            // Expression: 1
                                          //  Referenced by: '<S184>/Constant'

  real_T Constant7_Value[7];           // Expression: [0 0 0 1 0 0 0]
                                          //  Referenced by: '<S191>/Constant7'

  real_T Constant_Value_f[13];        // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
                                         //  Referenced by: '<S190>/Constant'

  real_T MATLABSystem_linearConvergence;// Expression: .2
                                           //  Referenced by: '<S192>/MATLAB System'

  real_T MATLABSystem_quaternionConverge;// Expression: .1
                                            //  Referenced by: '<S192>/MATLAB System'

  real_T MATLABSystem_TargetThreshold; // Expression: 3
                                          //  Referenced by: '<S192>/MATLAB System'

  real_T linWpts_Y0;                   // Computed Parameter: linWpts_Y0
                                          //  Referenced by: '<S205>/linWpts'

  real_T RotWpts_Y0;                   // Computed Parameter: RotWpts_Y0
                                          //  Referenced by: '<S205>/RotWpts'

  real_T time_Y0;                      // Computed Parameter: time_Y0
                                          //  Referenced by: '<S205>/time'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S205>/Constant1'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S207>/Out1'

  real_T Constant_Value_p;             // Expression: 1
                                          //  Referenced by: '<S217>/Constant'

  real_T Constant_Value_hy;            // Expression: 1
                                          //  Referenced by: '<S218>/Constant'

  real_T y_Y0;                         // Computed Parameter: y_Y0
                                          //  Referenced by: '<S211>/y'

  real_T PolynomialTrajectory1_VelocityB[6];// Expression: zeros( 3, 2 )
                                               //  Referenced by: '<S209>/Polynomial Trajectory1'

  real_T Constant_Value_ep;            // Expression: 1
                                          //  Referenced by: '<S209>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S209>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S209>/Discrete-Time Integrator'

  real_T Constant1_Value_i[2];         // Expression: [1,1]
                                          //  Referenced by: '<S192>/Constant1'

  real_T Delay_InitialCondition;       // Expression: 1
                                          //  Referenced by: '<S208>/Delay'

  real_T Constant_Value_ha;            // Expression: 0
                                          //  Referenced by: '<S192>/Constant'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S208>/Constant6'

  real_T Constant_Value_m5h[13];      // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
                                         //  Referenced by: '<S188>/Constant'

  real_T Constant1_Value_n;            // Expression: 10
                                          //  Referenced by: '<S10>/Constant1'

  real_T Delay_InitialCondition_p;     // Expression: 0
                                          //  Referenced by: '<S10>/Delay'

  real_T Delay_InitialCondition_a;     // Expression: 1
                                          //  Referenced by: '<S155>/Delay'

  real_T Gain_Gain_h;                  // Expression: 2
                                          //  Referenced by: '<S175>/Gain'

  real_T Gain1_Gain_k;                 // Expression: 2
                                          //  Referenced by: '<S175>/Gain1'

  real_T Constant_Value_ic;            // Expression: 0.5
                                          //  Referenced by: '<S175>/Constant'

  real_T Gain2_Gain_by;                // Expression: 2
                                          //  Referenced by: '<S175>/Gain2'

  real_T Gain_Gain_n;                  // Expression: 2
                                          //  Referenced by: '<S174>/Gain'

  real_T Constant_Value_pg;            // Expression: 0.5
                                          //  Referenced by: '<S174>/Constant'

  real_T Gain2_Gain_lp;                // Expression: 2
                                          //  Referenced by: '<S174>/Gain2'

  real_T Gain1_Gain_f;                 // Expression: 2
                                          //  Referenced by: '<S174>/Gain1'

  real_T Constant_Value_l4;            // Expression: 0.5
                                          //  Referenced by: '<S173>/Constant'

  real_T Gain2_Gain_a;                 // Expression: 2
                                          //  Referenced by: '<S173>/Gain2'

  real_T Gain_Gain_l;                  // Expression: 2
                                          //  Referenced by: '<S173>/Gain'

  real_T Gain1_Gain_fe;                // Expression: 2
                                          //  Referenced by: '<S173>/Gain1'

  real_T Gain_Gain_m3;                 // Expression: 1
                                          //  Referenced by: '<S10>/Gain'

  real_T Constant_Value_g0;            // Expression: 0.5
                                          //  Referenced by: '<S167>/Constant'

  real_T Gain2_Gain_f;                 // Expression: 2
                                          //  Referenced by: '<S167>/Gain2'

  real_T Gain_Gain_p;                  // Expression: 2
                                          //  Referenced by: '<S167>/Gain'

  real_T Gain1_Gain_gc;                // Expression: 2
                                          //  Referenced by: '<S167>/Gain1'

  real_T Gain_Gain_i;                  // Expression: 2
                                          //  Referenced by: '<S168>/Gain'

  real_T Constant_Value_h3;            // Expression: 0.5
                                          //  Referenced by: '<S168>/Constant'

  real_T Gain2_Gain_ah;                // Expression: 2
                                          //  Referenced by: '<S168>/Gain2'

  real_T Gain1_Gain_kt;                // Expression: 2
                                          //  Referenced by: '<S168>/Gain1'

  real_T Gain_Gain_o;                  // Expression: 2
                                          //  Referenced by: '<S169>/Gain'

  real_T Gain1_Gain_l;                 // Expression: 2
                                          //  Referenced by: '<S169>/Gain1'

  real_T Constant_Value_bb;            // Expression: 0.5
                                          //  Referenced by: '<S169>/Constant'

  real_T Gain2_Gain_n;                 // Expression: 2
                                          //  Referenced by: '<S169>/Gain2'

  real_T DiscreteTimeIntegrator_gainva_o;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_o
                             //  Referenced by: '<S10>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T Gain_Gain_g;                  // Expression: 180/pi
                                          //  Referenced by: '<S179>/Gain'

  real_T Constant_Value_as;            // Expression: 0
                                          //  Referenced by: '<S194>/Constant'

  real_T Constant3_Value;              // Expression: x0
                                          //  Referenced by: '<S194>/Constant3'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S198>/Integrator'

  real_T Integrator_UpperSat;          // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S198>/Integrator'

  real_T Integrator_LowerSat;          // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S198>/Integrator'

  real_T Saturation_UpperSat;          // Expression: windupUpperLimit
                                          //  Referenced by: '<S198>/Saturation'

  real_T Saturation_LowerSat;          // Expression: windupLowerLimit
                                          //  Referenced by: '<S198>/Saturation'

  real_T Gain3_Gain;                   // Expression: (2*pi*fn).^2
                                          //  Referenced by: '<S194>/Gain3'

  real_T Constant1_Value_d;            // Expression: 0
                                          //  Referenced by: '<S194>/Constant1'

  real_T Constant2_Value;              // Expression: xdot0
                                          //  Referenced by: '<S194>/Constant2'

  real_T Integrator_gainval_e;       // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S199>/Integrator'

  real_T Integrator_UpperSat_f;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S199>/Integrator'

  real_T Integrator_LowerSat_p;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S199>/Integrator'

  real_T Saturation_UpperSat_m;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S199>/Saturation'

  real_T Saturation_LowerSat_c;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S199>/Saturation'

  real_T Gain_Gain_ga;                 // Expression: -1
                                          //  Referenced by: '<S189>/Gain'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S85>/Delay'

  real_T Delay_InitialCondition_f;     // Expression: 0.0
                                          //  Referenced by: '<S5>/Delay'

  real_T Constant_Value_j[3];          // Expression: [0,0,0]
                                          //  Referenced by: '<S82>/Constant'

  real_T Constant_Value_oo[3];         // Expression: [0,0,0]
                                          //  Referenced by: '<S83>/Constant'

  real_T Constant6_Value_i;            // Expression: 0
                                          //  Referenced by: '<S85>/Constant6'

  real_T Constant6_Value_o;            // Expression: 0
                                          //  Referenced by: '<S155>/Constant6'

  int16_T FixedHorizonOptimizer_Ndis;  // Expression: Ndis
                                          //  Referenced by: '<S144>/FixedHorizonOptimizer'

  boolean_T Memory_InitialCondition[64];// Expression: iA
                                           //  Referenced by: '<S116>/Memory'

  boolean_T Delay1_InitialCondition_k;
                                // Computed Parameter: Delay1_InitialCondition_k
                                   //  Referenced by: '<S192>/Delay1'

  boolean_T Merge1_InitialOutput;    // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<S11>/Merge1'

  P_Subsystem2_proc_control_nod_T Subsystem2_p;// '<S155>/Subsystem2'
  P_Subsystem2_proc_control_nod_T Subsystem2;// '<S85>/Subsystem2'
};

// Real-time Model Data Structure
struct tag_RTM_proc_control_node_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_proc_control_node_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[21];
  real_T odeF[3][21];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint16_T clockTick5;
    boolean_T firstInitCondFlag;
    struct {
      uint16_T TID[6];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[6];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_proc_control_node_T proc_control_node_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_proc_control_node_T proc_control_node_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_proc_control_node_T proc_control_node_X;

// Block states (default storage)
extern struct DW_proc_control_node_T proc_control_node_DW;

// Zero-crossing (trigger) state
extern PrevZCX_proc_control_node_T proc_control_node_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void proc_control_node_initialize(void);
  extern void proc_control_node_step(void);
  extern void proc_control_node_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_proc_control_node_T *const proc_control_node_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S90>/Gain' : Unused code path elimination
//  Block '<S111>/Data Type Duplicate' : Unused code path elimination
//  Block '<S116>/Data Type Conversion22' : Unused code path elimination
//  Block '<S116>/Data Type Conversion23' : Unused code path elimination
//  Block '<S116>/Floor' : Unused code path elimination
//  Block '<S116>/Floor1' : Unused code path elimination
//  Block '<S117>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S118>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S119>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S120>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S121>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S122>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S123>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S124>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S125>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S126>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S127>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S128>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S129>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S130>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S131>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S132>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S133>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S134>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S135>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S136>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S137>/Vector Dimension Check' : Unused code path elimination
//  Block '<S138>/Vector Dimension Check' : Unused code path elimination
//  Block '<S139>/Vector Dimension Check' : Unused code path elimination
//  Block '<S140>/Vector Dimension Check' : Unused code path elimination
//  Block '<S141>/Vector Dimension Check' : Unused code path elimination
//  Block '<S142>/Vector Dimension Check' : Unused code path elimination
//  Block '<S143>/Vector Dimension Check' : Unused code path elimination
//  Block '<S116>/useq_scale' : Unused code path elimination
//  Block '<S116>/useq_scale1' : Unused code path elimination
//  Block '<S116>/ym_zero' : Unused code path elimination
//  Block '<S112>/m_zero' : Unused code path elimination
//  Block '<S112>/p_zero' : Unused code path elimination
//  Block '<S10>/ ' : Unused code path elimination
//  Block '<S10>/Multiport Switch' : Unused code path elimination
//  Block '<S211>/Constant' : Unused code path elimination
//  Block '<S211>/Product' : Unused code path elimination
//  Block '<S213>/1//2' : Unused code path elimination
//  Block '<S213>/q0' : Unused code path elimination
//  Block '<S213>/q1' : Unused code path elimination
//  Block '<S213>/q2' : Unused code path elimination
//  Block '<S213>/q3' : Unused code path elimination
//  Block '<S213>/sincos' : Unused code path elimination
//  Block '<S222>/Data Type Duplicate' : Unused code path elimination
//  Block '<S229>/FixPt Data Type Duplicate2' : Unused code path elimination
//  Block '<S12>/NOT' : Unused code path elimination
//  Block '<S12>/NOT1' : Unused code path elimination
//  Block '<S12>/Product' : Unused code path elimination
//  Block '<S19>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S3>/MinMax' : Eliminated since input is scalar
//  Block '<S3>/MinMax1' : Eliminated since input is scalar
//  Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion13' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion15' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion16' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion17' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion18' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion19' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion20' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion21' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S116>/E Conversion' : Eliminate redundant data type conversion
//  Block '<S116>/F Conversion' : Eliminate redundant data type conversion
//  Block '<S116>/G Conversion' : Eliminate redundant data type conversion
//  Block '<S116>/Reshape' : Reshape block reduction
//  Block '<S116>/Reshape1' : Reshape block reduction
//  Block '<S116>/Reshape2' : Reshape block reduction
//  Block '<S116>/Reshape3' : Reshape block reduction
//  Block '<S116>/Reshape4' : Reshape block reduction
//  Block '<S116>/Reshape5' : Reshape block reduction
//  Block '<S116>/S Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'proc_control_node'
//  '<S1>'   : 'proc_control_node/Modèle Physique'
//  '<S2>'   : 'proc_control_node/Plot values'
//  '<S3>'   : 'proc_control_node/ROS Input'
//  '<S4>'   : 'proc_control_node/ROS Output'
//  '<S5>'   : 'proc_control_node/Send Data to ROS'
//  '<S6>'   : 'proc_control_node/Send Sensor ON'
//  '<S7>'   : 'proc_control_node/Send Target Reached '
//  '<S8>'   : 'proc_control_node/Sensor Manager'
//  '<S9>'   : 'proc_control_node/Subsystem Controller'
//  '<S10>'  : 'proc_control_node/Subsystem ProcNav'
//  '<S11>'  : 'proc_control_node/Subsystem Trajectory'
//  '<S12>'  : 'proc_control_node/Subsystem1'
//  '<S13>'  : 'proc_control_node/Modèle Physique/AUV State Equation'
//  '<S14>'  : 'proc_control_node/Modèle Physique/MATLAB Function'
//  '<S15>'  : 'proc_control_node/Modèle Physique/Modele Thruster'
//  '<S16>'  : 'proc_control_node/Modèle Physique/Perturbations'
//  '<S17>'  : 'proc_control_node/Modèle Physique/Quaternion Normalise'
//  '<S18>'  : 'proc_control_node/Modèle Physique/Sensor Noise'
//  '<S19>'  : 'proc_control_node/Modèle Physique/Sensor model'
//  '<S20>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T1'
//  '<S21>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T2'
//  '<S22>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T3'
//  '<S23>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T4'
//  '<S24>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T5'
//  '<S25>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T6'
//  '<S26>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T7'
//  '<S27>'  : 'proc_control_node/Modèle Physique/Modele Thruster/T8'
//  '<S28>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Band-Limited White Noise'
//  '<S29>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Band-Limited White Noise1'
//  '<S30>'  : 'proc_control_node/Modèle Physique/Sensor Noise/IMU Inverse'
//  '<S31>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Conjugate'
//  '<S32>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1'
//  '<S33>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Rotation Angles to Quaternions'
//  '<S34>'  : 'proc_control_node/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Conjugate'
//  '<S35>'  : 'proc_control_node/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Norm'
//  '<S36>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize'
//  '<S37>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V1'
//  '<S38>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V2'
//  '<S39>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V3'
//  '<S40>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S41>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S42>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse'
//  '<S43>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse/Quaternion Conjugate'
//  '<S44>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse/Quaternion Norm'
//  '<S45>'  : 'proc_control_node/Plot values/Quaternion Inverse'
//  '<S46>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles'
//  '<S47>'  : 'proc_control_node/Plot values/Quaternion Inverse/Quaternion Conjugate'
//  '<S48>'  : 'proc_control_node/Plot values/Quaternion Inverse/Quaternion Norm'
//  '<S49>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Angle Calculation'
//  '<S50>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S51>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S52>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S53>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S54>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S55>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S56>'  : 'proc_control_node/Plot values/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S57>'  : 'proc_control_node/ROS Input/MATLAB Function'
//  '<S58>'  : 'proc_control_node/ROS Input/Quaternion Normalise'
//  '<S59>'  : 'proc_control_node/ROS Input/Subscribe'
//  '<S60>'  : 'proc_control_node/ROS Input/Subscribe1'
//  '<S61>'  : 'proc_control_node/ROS Input/Subscribe/Enabled Subsystem'
//  '<S62>'  : 'proc_control_node/ROS Input/Subscribe1/Enabled Subsystem'
//  '<S63>'  : 'proc_control_node/ROS Output/Send DVL msg'
//  '<S64>'  : 'proc_control_node/ROS Output/Send IMU msg'
//  '<S65>'  : 'proc_control_node/ROS Output/Send DVL msg/   '
//  '<S66>'  : 'proc_control_node/ROS Output/Send DVL msg/MATLAB Function'
//  '<S67>'  : 'proc_control_node/ROS Output/Send DVL msg/Publish'
//  '<S68>'  : 'proc_control_node/ROS Output/Send IMU msg/   '
//  '<S69>'  : 'proc_control_node/ROS Output/Send IMU msg/MATLAB Function'
//  '<S70>'  : 'proc_control_node/ROS Output/Send IMU msg/Publish'
//  '<S71>'  : 'proc_control_node/Send Data to ROS/Blank Message2'
//  '<S72>'  : 'proc_control_node/Send Data to ROS/Blank Message3'
//  '<S73>'  : 'proc_control_node/Send Data to ROS/Blank Message4'
//  '<S74>'  : 'proc_control_node/Send Data to ROS/MATLAB Function3'
//  '<S75>'  : 'proc_control_node/Send Data to ROS/Publish2'
//  '<S76>'  : 'proc_control_node/Send Data to ROS/Publish3'
//  '<S77>'  : 'proc_control_node/Send Data to ROS/Publish4'
//  '<S78>'  : 'proc_control_node/Send Sensor ON/Blank Message'
//  '<S79>'  : 'proc_control_node/Send Sensor ON/Publish'
//  '<S80>'  : 'proc_control_node/Send Target Reached /Blank Message'
//  '<S81>'  : 'proc_control_node/Send Target Reached /Publish'
//  '<S82>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL'
//  '<S83>'  : 'proc_control_node/Sensor Manager/Send DVL velocity To IMU'
//  '<S84>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Blank Message'
//  '<S85>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/DVL2Ship'
//  '<S86>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/MATLAB Function1'
//  '<S87>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Publish'
//  '<S88>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternion Multiplication'
//  '<S89>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles'
//  '<S90>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Radians to Degrees'
//  '<S91>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/DVL2Ship/Subsystem2'
//  '<S92>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/DVL2Ship/Subsystem2/Rotation Angles to Quaternions'
//  '<S93>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternion Multiplication/q0'
//  '<S94>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternion Multiplication/q1'
//  '<S95>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternion Multiplication/q2'
//  '<S96>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternion Multiplication/q3'
//  '<S97>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Angle Calculation'
//  '<S98>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S99>'  : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S100>' : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S101>' : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S102>' : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S103>' : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S104>' : 'proc_control_node/Sensor Manager/Send Attitude To DVL/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S105>' : 'proc_control_node/Sensor Manager/Send DVL velocity To IMU/Blank Message'
//  '<S106>' : 'proc_control_node/Sensor Manager/Send DVL velocity To IMU/MATLAB Function1'
//  '<S107>' : 'proc_control_node/Sensor Manager/Send DVL velocity To IMU/Publish'
//  '<S108>' : 'proc_control_node/Subsystem Controller/IDLE'
//  '<S109>' : 'proc_control_node/Subsystem Controller/JoyStick OpenLoop'
//  '<S110>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC'
//  '<S111>' : 'proc_control_node/Subsystem Controller/JoyStick OpenLoop/Discrete Derivative'
//  '<S112>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller'
//  '<S113>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux'
//  '<S114>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux1'
//  '<S115>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/MATLAB Function2'
//  '<S116>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC'
//  '<S117>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
//  '<S118>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
//  '<S119>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
//  '<S120>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
//  '<S121>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
//  '<S122>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
//  '<S123>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
//  '<S124>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
//  '<S125>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
//  '<S126>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
//  '<S127>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
//  '<S128>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
//  '<S129>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S130>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
//  '<S131>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S132>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S133>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S134>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S135>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S136>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S137>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
//  '<S138>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S139>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S140>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
//  '<S141>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S142>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S143>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
//  '<S144>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/optimizer'
//  '<S145>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
//  '<S146>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles'
//  '<S147>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Angle Calculation'
//  '<S148>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S149>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S150>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S151>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S152>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S153>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S154>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S155>' : 'proc_control_node/Subsystem ProcNav/DVL2Ship'
//  '<S156>' : 'proc_control_node/Subsystem ProcNav/MATLAB Function1'
//  '<S157>' : 'proc_control_node/Subsystem ProcNav/Quaternion Conjugate'
//  '<S158>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse'
//  '<S159>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation'
//  '<S160>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1'
//  '<S161>' : 'proc_control_node/Subsystem ProcNav/Subsystem'
//  '<S162>' : 'proc_control_node/Subsystem ProcNav/DVL2Ship/Subsystem2'
//  '<S163>' : 'proc_control_node/Subsystem ProcNav/DVL2Ship/Subsystem2/Rotation Angles to Quaternions'
//  '<S164>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse/Quaternion Conjugate'
//  '<S165>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse/Quaternion Norm'
//  '<S166>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S167>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S168>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S169>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S170>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S171>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S172>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize'
//  '<S173>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V1'
//  '<S174>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V2'
//  '<S175>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V3'
//  '<S176>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S177>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S178>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles'
//  '<S179>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Radians to Degrees'
//  '<S180>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S181>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S182>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S183>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S184>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S185>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S186>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S187>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S188>' : 'proc_control_node/Subsystem Trajectory/If Action Subsystem'
//  '<S189>' : 'proc_control_node/Subsystem Trajectory/Subsystem'
//  '<S190>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto'
//  '<S191>' : 'proc_control_node/Subsystem Trajectory/SubsystemManual'
//  '<S192>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory'
//  '<S193>' : 'proc_control_node/Subsystem Trajectory/If Action Subsystem/MATLAB Function1'
//  '<S194>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter'
//  '<S195>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2'
//  '<S196>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)'
//  '<S197>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1'
//  '<S198>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)/Discrete'
//  '<S199>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1/Discrete'
//  '<S200>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S201>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/MATLAB Function1'
//  '<S202>' : 'proc_control_node/Subsystem Trajectory/SubsystemManual/MATLAB Function1'
//  '<S203>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/MATLAB Function'
//  '<S204>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/MATLAB Function2'
//  '<S205>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Pre-traitement'
//  '<S206>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe'
//  '<S207>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem1'
//  '<S208>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2'
//  '<S209>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Trajectory generator'
//  '<S210>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe/Enabled Subsystem'
//  '<S211>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem'
//  '<S212>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles'
//  '<S213>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Rotation Angles to Quaternions'
//  '<S214>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S215>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S216>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S217>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S218>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S219>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S220>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S221>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S222>' : 'proc_control_node/Subsystem1/MinMax Running Resettable'
//  '<S223>' : 'proc_control_node/Subsystem1/Quaternion Normalise'
//  '<S224>' : 'proc_control_node/Subsystem1/Subscribe'
//  '<S225>' : 'proc_control_node/Subsystem1/Subscribe1'
//  '<S226>' : 'proc_control_node/Subsystem1/Subscribe2'
//  '<S227>' : 'proc_control_node/Subsystem1/Subscribe3'
//  '<S228>' : 'proc_control_node/Subsystem1/Subscribe4'
//  '<S229>' : 'proc_control_node/Subsystem1/MinMax Running Resettable/Subsystem'
//  '<S230>' : 'proc_control_node/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S231>' : 'proc_control_node/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S232>' : 'proc_control_node/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S233>' : 'proc_control_node/Subsystem1/Subscribe3/Enabled Subsystem'
//  '<S234>' : 'proc_control_node/Subsystem1/Subscribe4/Enabled Subsystem'

#endif                                 // RTW_HEADER_proc_control_node_h_

//
// File trailer for generated code.
//
// [EOF]
//
