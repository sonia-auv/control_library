//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node.h
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
#ifndef RTW_HEADER_proc_control_node_h_
#define RTW_HEADER_proc_control_node_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
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

// Block signals for system '<S149>/MATLAB Function1'
struct B_MATLABFunction1_proc_contro_T {
  real_T matrix[13];
};

// Block states (default storage) for system '<S148>/Subsystem1'
struct DW_Subsystem1_proc_control_no_T {
  int8_T Subsystem1_SubsysRanBC;       // '<S148>/Subsystem1'
};

// Block signals (default storage)
struct B_proc_control_node_T {
  s_1UhBFHxHKUXshhZtLgMUHE_proc_T QRManager;
  s_B2KneB7ks2RV0bvoJc0bxC_proc_T CholManager;
  real_T b_data[576081];
  real_T y_data[576081];
  real_T b_data_m[576081];
  real_T b_data_c[576081];
  real_T b_data_k[576081];
  s_MFLHEgKtV7gODWBOEr7maD_proc_T WorkingSet;
  s_MFLHEgKtV7gODWBOEr7maD_proc_T b_WorkingSet;
  s_JXDNdI64oJvyHGrBwTBHI_proc__T memspace;
  real_T B_data[308154];
  real_T c_data[308154];
  real_T b_rhs_data[308154];
  real_T e_data[308154];
  real_T b_this[78013];
  s_YLC2gJhPBjEs8VvOTvcE4B_proc_T TrialState;
  real_T b_varargout_1[13000];
  real_T A_data[10880];
  real_T varargout_3_data[7176];
  real_T Jc_data[7176];
  real_T varargout_3_data_c[7176];
  real_T Jx[5408];
  real_T Jx_data[5408];
  real_T varargin_1_data[5408];
  creal_T z_data[2563];
  creal_T z_data_b[2563];
  creal_T z_data_p[2563];
  creal_T z_data_c[2563];
  creal_T dz_data[2562];
  creal_T b_y1_data[2562];
  creal_T d1_data[2562];
  creal_T tmp_data[2562];
  creal_T dz_data_f[2562];
  creal_T d1_data_g[2562];
  creal_T Zout[2561];
  creal_T tmp_data_g[2561];
  creal_T Zout_data[2561];
  creal_T b_Zout[2561];
  creal_T d2_data[2561];
  creal_T Zout_data_m[2561];
  creal_T Zout_data_n[2561];
  creal_T zorig_data[2561];
  creal_T z_data_pp[2561];
  creal_T d2_data_l[2561];
  creal_T znew_data[2560];
  creal_T z_data_j[2560];
  creal_T tmp_data_d[2560];
  creal_T znew_data_g[2560];
  creal_T tmp_data_l[2560];
  creal_T d1_data_d[2560];
  creal_T d2_data_d[2559];
  creal_T d1_data_l[2559];
  creal_T zcurrent_data[2559];
  creal_T d2_data_o[2559];
  creal_T d2_data_b[2559];
  real_T unusedExpr[4761];
  real_T Au[4096];
  real_T Auf_data[4096];
  real_T varargout_4[3588];
  real_T varargout_4_n[3588];
  real_T tmp_data_b[3328];
  real_T Jx_l[2704];
  real_T l_data[2562];
  real_T l_data_h[2562];
  real_T l1_data[2562];
  real_T l1_data_b[2562];
  real_T l_data_d[2562];
  real_T l_data_e[2562];
  real_T l1_data_bj[2562];
  real_T l1_data_j[2562];
  real_T u[2561];
  real_T v[2561];
  real_T r[2561];
  real_T s[2561];
  real_T alpha_data[2561];
  real_T l_data_f[2561];
  real_T alpha_data_a[2561];
  real_T a_data[2561];
  real_T tmp_data_j[2561];
  real_T tmp_data_jz[2561];
  real_T r_data[2561];
  real_T s_data[2561];
  real_T alpha_data_o[2561];
  real_T l_data_n[2561];
  real_T alpha_data_i[2561];
  real_T tmp_data_o[2561];
  real_T u_data[2561];
  real_T v_data[2561];
  real_T l_data_nv[2560];
  real_T alpha_data_m[2560];
  real_T b_data_cz[2560];
  real_T b_gamma_data[2560];
  real_T l1_data_m[2560];
  real_T l_data_m[2560];
  real_T alpha_data_j[2560];
  real_T beta_data[2560];
  real_T l1_data_h[2560];
  real_T l1_data_c[2559];
  real_T alpha_data_c[2559];
  real_T l1_data_p[2559];
  real_T tmp_data_p[2048];
  real_T tmp_data_a[2048];
  real_T Jmv[1664];
  real_T varargin_2_data[1664];
  s_51JXCAVDTNAZBtNXKIWdnB_proc_T FcnEvaluator;
  waypointTrajectory_proc_contr_T trajectory;
  creal_T At_data[441];
  creal_T b_At_data[441];
  creal_T c_A_data[441];
  creal_T b_A_data[441];
  creal_T y_data_e[441];
  real_T Jmv_a[832];
  s_jPVC6k54fKlkrevS6u11qC_proc_T QPObjective;
  creal_T At[400];
  creal_T c_A[400];
  creal_T b_A[400];
  real_T b_y_data[759];
  real_T y_data_a[759];
  real_T work_data[759];
  real_T work_data_i[759];
  real_T vn1_data[759];
  real_T vn2_data[759];
  real_T work_data_l[759];
  real_T y_data_o[759];
  real_T y_data_o2[759];
  real_T y_data_i[759];
  real_T y_data_f[759];
  real_T y_data_iz[759];
  real_T y_data_ff[759];
  real_T y_data_g[759];
  s_REWc8VgrfSKVLBFK433XbH_proc_T runtimedata;
  s_REWc8VgrfSKVLBFK433XbH_proc_T expl_temp;
  s_REWc8VgrfSKVLBFK433XbH_proc_T expl_temp_c;
  real_T result_data[546];
  real_T result_data_o[546];
  real_T x[520];
  real_T x_l[520];
  real_T dv[520];
  real_T x_data[520];
  real_T x_data_m[520];
  real_T x_m[520];
  real_T x_c[520];
  real_T dv1[520];
  real_T varargin_2_data_f[500];
  real_T b[500];
  real_T b_p[500];
  real_T tmp_data_e[441];
  real_T T_data[441];
  real_T A_data_o[441];
  real_T A_data_h[441];
  real_T c_h_data[441];
  real_T c_x_data[441];
  real_T c_x_data_l[441];
  real_T tmp_data_h[441];
  real_T e_A_data[441];
  real_T b_A_data_m[441];
  real_T c_a_data[441];
  real_T c_a_data_m[441];
  real_T dv2[400];
  real_T T[400];
  real_T A[400];
  real_T A_h[400];
  real_T d_a[400];
  real_T A_data_c[400];
  real_T b_h[400];
  SL_Bus_proc_control_node_std_msgs_UInt16MultiArray msg;// '<S5>/MATLAB Function3' 
  uint32_T b_state[625];
  SL_Bus_proc_control_node_std_msgs_Int8MultiArray msg_l0;// '<S5>/MATLAB Function1' 
  real_T xi[257];
  int32_T counts_data[400];
  real_T Ak[169];
  real_T Ak1[169];
  real_T List[168];
  real_T b_varargout_1_k[160];
  real_T Ppost[144];
  real_T B_data_p[128];
  real_T b_Bu[128];
  real_T y_data_p[122];
  SL_Bus_proc_control_node_nav_msgs_Odometry msg_d;// '<S8>/MATLAB Function1'
  sACkMJ1zT2VJOHR6eMwwEPC_proc__T userdata;
  real_T zy_data[105];
  real_T z_data_p4[105];
  real_T c_data_a[105];
  real_T varargout_1_data[104];
  real_T varargout_1_data_j[104];
  real_T c_data_e[104];
  real_T varargout_1_data_o[104];
  real_T c_data_b[104];
  real_T b_c[104];
  real_T b_c_data[104];
  real_T b_c_a[104];
  real_T b_c_data_g[104];
  real_T Je_data[104];
  real_T zy[100];
  real_T dv3[100];
  real_T z[100];
  real_T c[100];
  real_T u_data_e[84];
  real_T v_data_f[84];
  real_T obj[80];
  real_T v_h[80];
  real_T dx_tmp[80];
  real_T m[80];
  real_T c_a[80];
  real_T c_a_e[80];
  real_T H[72];
  real_T K[72];
  real_T H_c[72];
  real_T obj_a[72];
  real_T z0[69];
  real_T zLB[69];
  real_T zUB[69];
  real_T TrialState_d[69];
  real_T varargout_2[69];
  real_T X[65];
  real_T X_a[65];
  real_T b_X[65];
  real_T X_p[65];
  real_T X_m[65];
  real_T X_o[65];
  real_T b_X_n[65];
  real_T b_X_l[65];
  real_T b_X_p[65];
  real_T w[63];
  real_T waypoints_data[63];
  real_T Jtri_data[63];
  real_T Jtri_data_p[63];
  real_T b_varargout_2_data[63];
  real_T wprev[63];
  real_T beta_data_f[61];
  real_T e[60];
  real_T Jtri_data_i[60];
  real_T b_varargout_2_data_o[60];
  real_T Jtri[60];
  real_T b_varargout_2[60];
  real_T Jtri_data_k[60];
  real_T b_varargout_2_data_i[60];
  real_T rv[60];
  real_T y_o[60];
  real_T beta[58];
  SL_Bus_proc_control_node_sensor_msgs_Imu In1;// '<S48>/In1'
  real_T Jtri_data_m[57];
  real_T b_varargout_2_data_c[57];
  real_T x_f[57];
  real_T A_hc[57];
  real_T A_m[57];
  SL_Bus_proc_control_node_sensor_msgs_Imu msg_c;// '<S51>/MATLAB Function'
  boolean_T filled_data[441];
  real_T varargout_2_a[52];
  real_T varargout_2_k[52];
  real_T X0[52];
  real_T dv4[52];
  real_T dv5[52];
  real_T dv6[52];
  real_T dv7[52];
  real_T X_pc[52];
  real_T gfX[52];
  real_T b_b[52];
  real_T z_c[52];
  real_T runtimedata_n[52];
  boolean_T filled[400];
  SL_Bus_proc_control_node_gazebo_msgs_ModelState msg_o;// '<S83>/MATLAB Function' 
  creal_T tmp_data_i[21];
  creal_T beta1_data[21];
  creal_T hip_data[21];
  creal_T hip_data_m[21];
  creal_T hip[21];
  creal_T y_data_j[21];
  creal_T hip_data_e[21];
  creal_T hip_data_mv[21];
  creal_T hip_data_m0[21];
  creal_T hip_data_j[21];
  creal_T hip_data_f[21];
  creal_T hip_data_a[21];
  creal_T x_data_g[21];
  creal_T x_n[21];
  real_T constValues[41];
  real_T U[40];
  real_T U_i[40];
  real_T b_U[40];
  real_T U_h[40];
  real_T U_n[40];
  real_T Umv[40];
  real_T U_o[40];
  real_T b_U_c[40];
  real_T b_U_b[40];
  real_T b_U_e[40];
  creal_T obj_d[20];
  creal_T obj_n[20];
  creal_T x_cg[20];
  creal_T beta1[20];
  creal_T hip_data_fx[20];
  creal_T z_data_pm[20];
  creal_T df_da_data[20];
  creal_T y_data_p2[20];
  creal_T b_data_n[20];
  creal_T e_data_k[20];
  creal_T a1_data[20];
  creal_T a2_data[20];
  creal_T fa_data[20];
  creal_T s_data_n[20];
  creal_T r_data_o[20];
  creal_T da2_data[20];
  creal_T y_data_gg[20];
  creal_T x_data_c[20];
  creal_T x_data_cj[20];
  creal_T tmp_data_m[20];
  creal_T tmp_data_jp[20];
  creal_T x_data_k[20];
  creal_T z_m[20];
  creal_T df_da[20];
  creal_T b_x[20];
  creal_T b_data_p[20];
  creal_T e_data_d[20];
  creal_T nik_data[20];
  creal_T e_data_g[20];
  creal_T A_data_c3[20];
  creal_T dm2C_data[20];
  creal_T t_data[20];
  creal_T dt_data[20];
  creal_T dp_data[20];
  creal_T hip_data_c[20];
  creal_T z_i[20];
  creal_T b_x_d[20];
  creal_T hip_data_g[20];
  creal_T hip_data_l[20];
  creal_T b_data_f[20];
  creal_T e_data_db[20];
  creal_T x_data_j[20];
  real_T pp_coefs[36];
  real_T dCoefs[36];
  real_T constValues_d[36];
  real_T dv8[36];
  real_T H_i[36];
  real_T c_A_g[36];
  real_T dCoeffs[36];
  real_T ddCoeffs[36];
  real_T MV0[32];
  real_T MVRateWeights0[32];
  real_T MVMin0[32];
  real_T MVMax0[32];
  real_T dv9[32];
  real_T dv10[32];
  real_T dv11[32];
  real_T Umv_n[32];
  real_T gfU[32];
  real_T c_l[32];
  real_T a[32];
  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL In1_h;// '<S49>/In1'
  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL msg_p;// '<S50>/MATLAB Function' 
  real_T randNums[27];
  real_T y_data_c[24];
  real_T coefsWithFlatStart[24];
  real_T tmp_data_n[22];
  int8_T Ck[169];
  int8_T val[169];
  real_T tpts[21];
  real_T q_d[21];
  real_T t[21];
  real_T course[21];
  real_T gndspeed[21];
  real_T rate[21];
  real_T course_p[21];
  real_T obj_dk[21];
  real_T obj_o[21];
  real_T waypoints_data_j[21];
  real_T waypoints_data_c[21];
  real_T dx_data[21];
  real_T tmp_data_hp[21];
  real_T tmp_data_da[21];
  real_T oldq_data[21];
  real_T b_data_c5[21];
  real_T q_data[21];
  real_T beta_data_p[21];
  real_T v_data_p[21];
  real_T y_data_a4[21];
  real_T tmp_data_ow[21];
  real_T dx_data_j[21];
  real_T tmp_data_pi[21];
  real_T d_data[21];
  real_T e_data_o[21];
  real_T f_data[21];
  real_T Jtri_data_l[21];
  real_T b_y_data_k[21];
  real_T dx_data_jk[21];
  real_T xnew_data[21];
  real_T epsx_data[21];
  real_T epsr_data[21];
  real_T course_data[21];
  real_T course_data_f[21];
  real_T tmp_data_c[21];
  real_T y_data_fq[21];
  real_T a_data_n[21];
  real_T tmp_data_iu[21];
  real_T tmp_data_l4[21];
  real_T v_data_i[21];
  real_T dx_data_k[21];
  real_T xnew_data_f[21];
  real_T b_r_data[21];
  real_T epsx_data_a[21];
  real_T epsr_data_d[21];
  real_T b_varargout_1_data[21];
  real_T work_data_e[21];
  real_T y_data_eh[21];
  real_T tmp_data_bs[21];
  real_T course_data_a[21];
  real_T course_data_i[21];
  real_T tmp_data_f[21];
  real_T alpha_data_ji[21];
  real_T a_o[21];
  real_T b_f[21];
  real_T c_o[21];
  real_T course_data_l[21];
  real_T course_data_lu[21];
  real_T x_data_gf[21];
  real_T Jtri_data_d[21];
  real_T Jtri_data_dv[21];
  real_T Jtri_data_j[21];
  real_T Jtri_data_f[21];
  real_T Jtri_data_js[21];
  real_T Jtri_data_h[21];
  real_T tmp_data_cf[21];
  real_T u_data_n[21];
  real_T z_data_k[21];
  real_T b_data_a[21];
  real_T dv12[21];
  real_T dv13[21];
  real_T alpha_data_f[21];
  real_T z_data_jz[21];
  real_T c_data_k[21];
  real_T z_data_bn[21];
  real_T y_data_h[21];
  real_T y_data_eg[21];
  real_T y_data_hn[21];
  real_T y_data_k[21];
  real_T slopes[21];
  real_T h[20];
  real_T dtheta[20];
  real_T x_j[20];
  real_T tmp_data_oo[20];
  real_T v_data_c[20];
  real_T xnew_data_h[20];
  real_T b_r_data_i[20];
  real_T epsx_data_p[20];
  real_T epsr_data_f[20];
  real_T b_varargout_1_data_e[20];
  real_T y_data_n[20];
  real_T y_data_ho[20];
  real_T courselsq[20];
  real_T v_hp[20];
  real_T dx[20];
  real_T xnew[20];
  real_T b_r[20];
  real_T b_varargout_1_f[20];
  real_T z_iv[20];
  real_T oldq[20];
  real_T q[20];
  real_T alpha[20];
  real_T beta_f[20];
  real_T v_c[20];
  real_T work[20];
  real_T xnew_data_n[20];
  real_T epsx_data_h[20];
  real_T epsr_data_k[20];
  real_T y_data_hz[20];
  real_T y_data_b[20];
  real_T v_data_o[20];
  real_T b_r_data_n[20];
  real_T b_varargout_1_data_m[20];
  real_T a__2_data[20];
  real_T k0_data[20];
  real_T k1_data[20];
  real_T dk0_dc0_data[20];
  real_T dk0_dc1_data[20];
  real_T dk1_dc0_data[20];
  real_T dk1_dc1_data[20];
  real_T course_data_k[20];
  real_T phi_data[20];
  real_T phi0_data[20];
  real_T phi1_data[20];
  real_T da_dphi0_data[20];
  real_T da_dphi1_data[20];
  real_T ilarge_data[20];
  real_T a_data_j[20];
  real_T d_data_h[20];
  real_T c_data_f[20];
  real_T ratio_data[20];
  real_T j_data[20];
  real_T x_data_d[20];
  real_T xabs_data[20];
  real_T ismall_data[20];
  real_T x4_data[20];
  real_T ibig_data[20];
  real_T a__1[20];
  real_T k0[20];
  real_T k1[20];
  real_T dk0_dc0[20];
  real_T dk0_dc1[20];
  real_T dk1_dc0[20];
  real_T dk1_dc1[20];
  real_T x_li[20];
  real_T phi[20];
  real_T phi0[20];
  real_T phi1[20];
  real_T da_dphi0[20];
  real_T da_dphi1[20];
  real_T a_data_k[20];
  real_T d_data_i[20];
  real_T c_data_h[20];
  real_T k_data[20];
  real_T tmp_data_mg[20];
  real_T a__4_data[20];
  real_T k0_data_g[20];
  real_T k1_data_l[20];
  real_T dk0_dc0_data_m[20];
  real_T dk0_dc1_data_n[20];
  real_T dk1_dc0_data_g[20];
  real_T dk1_dc1_data_d[20];
  real_T course_data_m[20];
  real_T u_data_f[20];
  real_T v_data_g[20];
  real_T dadr_data[20];
  real_T d[20];
  real_T e_j[20];
  real_T f[20];
  real_T alpha_c[20];
  real_T alpha_e[20];
  real_T phi_m[20];
  real_T phi0_o[20];
  real_T phi1_a[20];
  real_T u_j[20];
  real_T v_g[20];
  real_T r_j[20];
  real_T b_gamma_data_e[20];
  real_T u_jy[20];
  real_T v_j[20];
  real_T r_g[20];
  real_T s_o[20];
  real_T deltaQuat_a[20];
  real_T deltaQuat_b[20];
  real_T deltaQuat_c[20];
  real_T deltaQuat_d[20];
  real_T qi_b[20];
  real_T qi_c[20];
  real_T qi_d[20];
  real_T mag[20];
  real_T n[20];
  real_T a__3_data[20];
  real_T k0_data_h[20];
  real_T k1_data_c[20];
  real_T dk0_dc0_data_a[20];
  real_T dk0_dc1_data_l[20];
  real_T dk1_dc0_data_j[20];
  real_T dk1_dc1_data_i[20];
  real_T course_data_mi[20];
  real_T a__5_data[20];
  real_T k0_data_f[20];
  real_T k1_data_o[20];
  real_T dk0_dc0_data_i[20];
  real_T dk0_dc1_data_e[20];
  real_T dk1_dc0_data_j0[20];
  real_T dk1_dc1_data_o[20];
  real_T x_data_f[20];
  real_T a_data_m[20];
  real_T d_data_a[20];
  real_T c_data_hi[20];
  real_T b_gamma_data_o[20];
  real_T y_data_hnt[20];
  real_T y_data_j3[20];
  real_T h_g[20];
  real_T del[20];
  real_T Jtri_j[20];
  real_T z_l[20];
  real_T b_k[20];
  real_T tau[19];
  real_T v_data_d[19];
  real_T b_r_data_np[19];
  real_T b_varargout_1_data_j[19];
  real_T b_gamma[19];
  real_T b_gamma_a[19];
  real_T delta_data[19];
  real_T work_h[19];
  real_T delta_data_i[19];
  real_T delta[18];
  real_T delta_d[18];
  boolean_T icf[128];
  uint8_T ii_data[128];
  real_T J_data[16];
  real_T A_data_b[16];
  real_T A_data_hj[16];
  real_T d_A_data[16];
  real_T c_x_data_p[16];
  real_T b_A_data_n[16];
  real_T b_I[16];
  real_T y_j[16];
  real_T b_I_o[16];
  real_T a_b[16];
  real_T b_j[16];
  real_T c_A_e[16];
  real_T c_x_data_i[16];
  sG8JZ69axY52WWR6RKyApQC_proc__T MeritFunction;
  boolean_T icf_n[104];
  int8_T b_data_i[104];
  int32_T ic[26];
  boolean_T icf_p[104];
  int8_T Je[104];
  int8_T b_data_o[104];
  int8_T d_data_m[104];
  int32_T ic_o[26];
  real_T Dynamics[13];
  real_T TmpSignalConversionAtTran_h[13];
  real_T ic_g[13];
  real_T dv14[13];
  real_T dv15[13];
  real_T ic_e[13];
  real_T runtimedata_OutputMin[13];
  real_T ic_i[13];
  real_T runtimedata_OutputMin_g[13];
  real_T ix[13];
  real_T runtimedata_OutputWeights[13];
  real_T gfx[13];
  real_T ic_ge[13];
  real_T dv16[13];
  real_T dv17[13];
  real_T currPose[13];
  real_T xe_post[12];
  real_T coefMat[12];
  real_T coeffMat[12];
  int32_T rscale_data[21];
  creal_T A_data_ci[5];
  creal_T b_A_data_j[5];
  creal_T x_data_kb[5];
  int32_T ismall_data_g[20];
  int32_T izero_data[20];
  int32_T y_tmp_data[20];
  int32_T tmp_data_gr[20];
  int32_T ilarge_data_c[20];
  int32_T ismall_data_k[20];
  int32_T izero_data_d[20];
  int32_T y_tmp_data_k[20];
  int32_T b_data_pd[20];
  int32_T izero_data_p[20];
  int32_T ilarge_data_m[20];
  int32_T ismall_data_kt[20];
  int32_T izero_data_a[20];
  int32_T tmp_data_ft[20];
  int32_T rscale[20];
  real_T TmpSignalConversionAtMATLAB[9];// '<S150>/Subsystem1'
  real_T Rprior[9];
  real_T h1[9];
  real_T h1_h[9];
  real_T rmat[9];
  real_T c_d[9];
  real_T a_j[9];
  real_T A_n[9];
  real_T B[9];
  real_T c_j[9];
  real_T a_l[9];
  real_T c_p[9];
  real_T x_p[9];
  s1TgE9KstXgkd2qJxO1bF4F_proc__T expl_temp_l;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T expl_temp_ld;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions_h;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions_c;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions_g;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions_e;
  s1TgE9KstXgkd2qJxO1bF4F_proc__T qpoptions_n;
  int8_T As[64];
  int8_T Au_tmp[64];
  int8_T Au_tmp_f[64];
  SL_Bus_proc_control_node_sonia_common_AddPose In1_p;// '<S176>/In1'
  SL_Bus_proc_control_node_sonia_common_AddPose In1_ph;// '<S165>/In1'
  real_T FirstOrderHold1[8];           // '<S5>/First Order Hold1'
  real_T FirstOrderHold_c[8];          // '<S5>/First Order Hold'
  real_T twpt[8];
  real_T Tmax[8];
  real_T List_n[8];
  real_T umvk[8];
  real_T duk[8];
  real_T ic_e2[8];
  real_T runtimedata_b[8];
  real_T iu[8];
  real_T umvk_a[8];
  real_T duk_i[8];
  real_T gfu[8];
  real_T twpt_n[8];
  SL_Bus_proc_control_node_sonia_common_AddPose b_varargout_2_f;
  SL_Bus_proc_control_node_geometry_msgs_Pose In1_k;// '<S195>/In1'
  SL_Bus_proc_control_node_geometry_msgs_Pose b_varargout_2_i;
  SL_Bus_proc_control_node_geometry_msgs_Pose msg_p0;// '<S52>/MATLAB Function'
  real_T dv18[7];
  boolean_T bv[52];
  boolean_T bv1[52];
  SL_Bus_proc_control_node_geometry_msgs_Twist In1_pv;// '<S158>/In1'
  SL_Bus_proc_control_node_geometry_msgs_Twist b_varargout_2_k;
  real_T a__3[6];
  real_T a__4[6];
  real_T Gain_o[6];                    // '<S152>/Gain'
  real_T dv19[6];
  real_T constValues_b[6];
  real_T constValues_da[6];
  real_T Sum_n[6];                     // '<S152>/Sum'
  real_T Saturation_h[6];              // '<S157>/Saturation'
  real_T ze[6];
  real_T C[6];
  real_T c_n[5];
  real_T b_data_fj[5];
  char_T b_zeroDelimTopic[33];
  char_T b_zeroDelimTopic_a[32];
  int32_T gfu_tmp[8];
  real_T y[4];                         // '<S12>/Quaternion Normalise'
  real_T RotationTrajectory_o1[4];     // '<S175>/Rotation Trajectory'
  real_T Transpose[7];                 // '<S177>/Transpose'
  real_T DataTypeConversion[6];        // '<S173>/Data Type Conversion'
  real_T q_m[4];
  real_T rq[4];
  real_T b_q[4];
  real_T qRel[4];
  real_T Transpose2[4];                // '<S19>/Transpose2'
  real_T dv20[4];
  real_T tmp_data_gu[4];
  real_T lambda_data[4];
  real_T B_data_n[4];
  real_T c_tau_data[4];
  real_T work_data_c[4];
  real_T vn1_data_d[4];
  real_T vn2_data_k[4];
  real_T dv21[4];
  real_T y_c[4];
  real_T b_coeffVec[4];
  real_T q_j[4];
  real_T rq_m[4];
  real_T b_q_i[4];
  real_T b_this_b[4];
  real_T psquared[4];
  creal_T varargin_1[2];
  char_T b_zeroDelimTopic_o[30];
  char_T b_zeroDelimTopic_g[28];
  char_T b_zeroDelimTopic_e[27];
  char_T b_zeroDelimTopic_tmp[27];
  boolean_T icf_i[26];
  boolean_T icf_e[26];
  char_T b_zeroDelimTopic_i[24];
  real_T WorldPosition_g[3];           // '<S1>/Integrator'
  real_T InitialBodyvelocity[3];       // '<S1>/Initial Body velocity '
  real_T BodyVelocity_i[3];            // '<S1>/Integrator2'
  real_T InitialAngularRates[3];       // '<S1>/Initial Angular Rates'
  real_T AngularRate_b[3];             // '<S1>/Integrator3'
  real_T TmpSignalConversionAtSFun_f[3];// '<S50>/MATLAB Function'
  real_T u2[3];                        // '<S120>/1//2'
  real_T sincos_o1[3];                 // '<S120>/sincos'
  real_T Gain_j[3];
  real_T b_varargout_5[3];
  real_T b_varargout_4[3];
  real_T b_varargout_3[3];
  real_T b_varargout_1_m[3];
  real_T v_d[3];
  real_T gravityAccelGyroDiff[3];
  real_T offDiag[3];
  real_T dv22[3];
  real_T dv23[3];
  real_T v_j4[3];
  real_T magneticfield[3];
  real_T val_p[3];
  real_T val_b[3];
  real_T val_pn[3];
  real_T val_n[3];
  real_T val_c[3];
  real_T val_nh[3];
  real_T val_d[3];
  real_T val_i[3];
  real_T val_no[3];
  real_T val_bi[3];
  real_T val_bt[3];
  real_T val_j[3];
  real_T val_n0[3];
  real_T val_f[3];
  real_T val_e[3];
  real_T val_in[3];
  real_T val_a[3];
  real_T val_fd[3];
  real_T val_k[3];
  real_T whiteNoiseDrift[3];
  real_T temperatureDrift[3];
  real_T temp1[3];
  real_T e_c[3];
  real_T e_j1[3];
  real_T e_l[3];
  real_T w_a[3];
  real_T s_i[3];
  real_T e_o[3];
  real_T jerk[3];
  real_T D[3];
  real_T obj_b[3];
  real_T obj_an[3];
  real_T position[3];
  real_T velocity[3];
  real_T acceleration[3];
  real_T jerk_a[3];
  real_T f_data_i[3];
  real_T g_data[3];
  real_T qimag[3];
  real_T angVel_data[3];
  real_T angAcc_data[3];
  real_T d_data_iz[3];
  real_T qimag_data[3];
  real_T w_data[3];
  real_T udot_data[3];
  real_T wd1_data[3];
  real_T wd1xu_data[3];
  real_T temp0_data[3];
  real_T wd2_data[3];
  real_T angAcc_tmp_data[3];
  real_T angAcc_tmp_data_l[3];
  real_T tmp_data_o5[3];
  real_T tmp_data_py[3];
  real_T w_data_o[3];
  real_T tmp_data_cm[3];
  real_T a_oc[3];
  real_T y_ol[3];
  real_T temperatureDrift_h[3];
  real_T B_i[3];
  real_T y_gn[3];
  real_T c_c[3];
  real_T obj_ok[3];
  real_T bvec[3];
  real_T bvec2_data[3];
  real_T b_data_g[3];
  real_T wf_data[3];
  real_T e_data_o2[3];
  real_T e_data_gf[3];
  real_T val_ad[3];
  real_T val_g[3];
  real_T val_bp[3];
  real_T val_kn[3];
  real_T val_ca[3];
  real_T val_ji[3];
  real_T val_al[3];
  real_T val_dm[3];
  real_T Reast[3];
  real_T c_cx[3];
  char_T b_zeroDelimTopic_d[23];
  char_T b_zeroDelimTopic_tmp_a[23];
  char_T b_zeroDelimTopic_b[22];
  char_T b_zeroDelimTopic_tmp_g[22];
  int8_T range_data[21];
  int8_T b_tmp_data[21];
  boolean_T tmp_data_fb[21];
  boolean_T tmp_data_cg[21];
  int8_T v_data_pn[21];
  boolean_T xnew_data_a[21];
  boolean_T xnew_data_no[21];
  int8_T y_data_hl[21];
  int8_T x_data_mv[21];
  int8_T x_data_f5[21];
  int8_T y_data_bw[21];
  int8_T x_data_e[21];
  int8_T x_data_n[21];
  int8_T z_tmp[20];
  int8_T iv[20];
  int8_T iv1[20];
  int8_T ad_data[20];
  int8_T bd_data[20];
  int8_T e_tmp[20];
  int8_T b_data_ce[20];
  int8_T c_data_g[20];
  int8_T d_data_c[20];
  int8_T e_data_l[20];
  char_T b_zeroDelimTopic_ev[20];
  int8_T iv2[20];
  int8_T iv3[20];
  int8_T iv4[20];
  boolean_T x_p4[20];
  boolean_T criteria_data[20];
  boolean_T criteria_data_i[20];
  boolean_T ibig_data_j[20];
  boolean_T criteria[20];
  boolean_T criteria_l[20];
  boolean_T idx[20];
  boolean_T criteria_d[20];
  boolean_T criteria_m[20];
  int8_T z_tmp_f[19];
  int8_T z_tmp_n[19];
  int8_T e_tmp_o[19];
  char_T b_zeroDelimTopic_en[19];
  int8_T b_I_k[16];
  int8_T b_I_i[16];
  char_T b_zeroDelimTopic_n[16];
  uint16_T NtoPWM[8];                  // '<S9>/N to PWM'
  uint16_T y_j_c[8];                   // '<S1>/MATLAB Function'
  real_T DataTypeConversion1_l[2];     // '<S173>/Data Type Conversion1'
  real_T b_varargout_2_fb[2];
  real_T dv24[2];
  real_T dv25[2];
  real_T n_o[2];
  real_T v_dd[2];
  real_T obj_l[2];
  real_T obj_ls[2];
  real_T obj_dr[2];
  int32_T b_jpvt_data[4];
  int32_T b_jpvt_data_k[4];
  creal_T V;
  creal_T V_m;
  creal_T y_ch;
  creal_T b_g;
  creal_T a2;
  creal_T z_b;
  creal_T x_po;
  creal_T z_p;
  creal_T b_x_a;
  creal_T y_fm;
  creal_T b_gr;
  creal_T e_b;
  creal_T dp;
  creal_T z_k;
  creal_T b_x_b;
  creal_T b_hx;
  creal_T ph;
  creal_T vh;
  creal_T ah;
  creal_T jh;
  creal_T dc;
  creal_T hc;
  creal_T kc;
  creal_T y_data_ni;
  creal_T tmp_data_mm;
  creal_T w_g;
  creal_T w_j;
  creal_T w_data_idx_0;
  creal_T z_data_f;
  creal_T x_ng;
  creal_T ph_g;
  creal_T vh_d;
  creal_T ah_c;
  creal_T jh_m;
  creal_T dc1;
  creal_T a_data_d;
  creal_T z_n;
  creal_T z_bw;
  creal_T z_p2;
  creal_T z_kg;
  creal_T zleft;
  creal_T zright;
  creal_T work_c;
  creal_T work_data_idx_0;
  creal_T alpha1;
  creal_T ctemp;
  creal_T ad11;
  creal_T shift;
  creal_T ascale;
  creal_T t1;
  creal_T alpha1_n;
  creal_T ctemp_n;
  creal_T ad11_c;
  creal_T shift_d;
  creal_T ascale_n;
  creal_T t1_g;
  creal_T zleft_l;
  creal_T zright_g;
  creal_T nikx_data;
  creal_T nhikx_data;
  creal_T hidkxx_data;
  creal_T e_data_p;
  creal_T t_data_k;
  creal_T s_l;
  creal_T s_b;
  boolean_T x_fo[13];
  boolean_T x_p3[13];
  boolean_T x_k[13];
  int32_T Jx_size[3];
  boolean_T flag[10];
  boolean_T flag_k[9];
  int8_T b_I_iv[9];
  char_T b_zeroDelimTopic_ew[9];
  int8_T b_I_f[9];
  int8_T b_I_kx[9];
  int8_T a_n[9];
  boolean_T b_i[9];
  s7RdrPWkr8UPAUyTdDJkLaG_proc__T Flags;
  real_T Sum;                          // '<S133>/Sum'
  real_T Sum_m;                        // '<S132>/Sum'
  real_T Sum_i;                        // '<S131>/Sum'
  real_T qW2S[4];                      // '<S10>/Gain'
  real_T WorldPosition[3];             // '<S10>/Discrete-Time Integrator'
  real_T AngularRate[3];               // '<S10>/Gain1'
  real_T TmpSignalConversionAtFirstOrder[12];// '<S8>/Conversion d'unité'
  real_T Divide3;                      // '<S117>/Divide3'
  real_T Divide2;                      // '<S117>/Divide2'
  real_T Divide1;                      // '<S117>/Divide1'
  real_T Divide;                       // '<S117>/Divide'
  real_T BodyPosition;                 // '<S10>/Discrete-Time Integrator1'
  real_T MultiportSwitch[6];           // '<S152>/Multiport Switch'
  real_T Quaternion[52];               // '<S11>/Merge'
  real_T Merge[8];                     // '<S9>/Merge'
  real_T Saturation[8];                // '<S9>/Saturation'
  real_T DataTypeConversion1[8];       // '<S5>/Data Type Conversion1'
  real_T Gain2;                        // '<S83>/Gain2'
  real_T Gain1;                        // '<S83>/Gain1'
  real_T Sum_d;                        // '<S83>/Sum'
  real_T Gain4;                        // '<S83>/Gain4'
  real_T Gain3;                        // '<S83>/Gain3'
  real_T FirstOrderHold[12];           // '<S8>/First Order Hold'
  real_T DataTypeConversion2;          // '<S173>/Data Type Conversion2'
  real_T Transpose_i[16];              // '<S171>/Transpose'
  real_T Selector1[8];                 // '<S171>/Selector1'
  real_T Selector[6];                  // '<S171>/Selector'
  real_T MatrixConcatenate[2];         // '<S171>/Matrix Concatenate'
  real_T DataTypeConversion_p[6];      // '<S163>/Data Type Conversion'
  real_T DataTypeConversion1_o[2];     // '<S163>/Data Type Conversion1'
  real_T DataTypeConversion2_m;        // '<S163>/Data Type Conversion2'
  real_T y_g[3];                       // '<S10>/MATLAB Function1'
  real_T MATLABSystem[8];              // '<S89>/MATLAB System'
  real_T PulseGenerator;               // '<S90>/Pulse Generator'
  real_T nlpstatus;                    // '<S94>/NLMPC'
  real_T Quaternion_l[4];// '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T WorldPosition_o[3];
                         // '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T BodyVelocity[3];// '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T AngularRate_m[3];
                         // '<S4>/BusConversion_InsertedFor_Output_at_inport_0'
  real_T y_a[4];                       // '<S3>/Quaternion Normalise'
  real_T y_b;                          // '<S3>/MATLAB Function'
  real_T PWMtoN[8];                    // '<S15>/ PWM to N'
  real_T XDrift;                       // '<S16>/X Drift'
  real_T YDrift;                       // '<S16>/Y Drift'
  real_T ZDrift;                       // '<S16>/Z Drift'
  real_T XWave;                        // '<S16>/X Wave'
  real_T YWave;                        // '<S16>/Y Wave'
  real_T ZWave;                        // '<S16>/Z Wave'
  real_T Output;                       // '<S28>/Output'
  real_T Quaternion_p[4];              // '<S18>/Sum1'
  real_T Transpose_d[3];               // '<S19>/Transpose'
  real_T Output_d;                     // '<S29>/Output'
  real_T AngularRate_h[3];             // '<S18>/Sum3'
  real_T Gain_f;                       // '<S36>/Gain'
  real_T Gain1_b;                      // '<S36>/Gain1'
  real_T Gain2_l;                      // '<S36>/Gain2'
  real_T Sum_h;                        // '<S36>/Sum'
  real_T Gain_e;                       // '<S37>/Gain'
  real_T Gain1_bf;                     // '<S37>/Gain1'
  real_T Gain2_d;                      // '<S37>/Gain2'
  real_T Sum_m0;                       // '<S37>/Sum'
  real_T Gain_n;                       // '<S38>/Gain'
  real_T Gain1_l;                      // '<S38>/Gain1'
  real_T Gain2_m;                      // '<S38>/Gain2'
  real_T Sum_c;                        // '<S38>/Sum'
  real_T AHRS_o1[4];                   // '<S19>/AHRS'
  real_T y_f[4];                       // '<S1>/Quaternion Normalise'
  real_T Position_dot[3];              // '<S1>/AUV State Equation'
  real_T Quaternion_dot[4];            // '<S1>/AUV State Equation'
  real_T BodyVelocity_dot[3];          // '<S1>/AUV State Equation'
  real_T AngularRates_dot[3];          // '<S1>/AUV State Equation'
  real_T t20;
  real_T t19;
  real_T t22;
  real_T t23;
  real_T t84;
  real_T t42;
  real_T t50;
  real_T t86;
  real_T t87;
  real_T t51;
  real_T t74;
  real_T t77;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  real_T t12;
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
  real_T t57;
  real_T t58;
  real_T t62;
  real_T t64;
  real_T t70;
  real_T Product1_dz;                  // '<S123>/Product1'
  real_T Product2_ks;                  // '<S123>/Product2'
  real_T Product3_na;                  // '<S123>/Product3'
  real_T Product1_a5;                  // '<S130>/Product1'
  real_T fcn2;                         // '<S136>/fcn2'
  real_T fcn3;                         // '<S136>/fcn3'
  real_T Product_k;                    // '<S35>/Product'
  real_T TransferFcn_b;
  real_T TransferFcn_l;
  real_T TransferFcn_a;
  real_T rtb_sincos_o1_m_idx_2;
  real_T rtb_sincos_o1_m_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T BodyVelocity_dot_tmp;
  real_T BodyVelocity_dot_tmp_i;
  real_T BodyVelocity_dot_tmp_o;
  real_T BodyVelocity_dot_tmp_d;
  real_T BodyVelocity_dot_tmp_iu;
  real_T BodyVelocity_dot_tmp_g;
  real_T BodyVelocity_dot_tmp_c;
  real_T BodyVelocity_dot_tmp_e;
  real_T Sum_e;                        // '<S127>/Sum'
  real_T Sum_g;                        // '<S126>/Sum'
  real_T Sum_a;                        // '<S125>/Sum'
  real_T maxTime;
  real_T dist;
  real_T b_varargout_2_d;
  real_T c_h;
  real_T b_x_e;
  real_T absx;
  real_T course_d;
  real_T freetail_tmp;
  real_T lambda;
  real_T lambdac;
  real_T S;
  real_T b_varargout_1_g;
  real_T b_varargout_1_e;
  real_T R;
  real_T bet;
  real_T q_e;
  real_T x_g;
  real_T br;
  real_T bi;
  real_T brm;
  real_T bim;
  real_T x_gk;
  real_T SMLNUM;
  real_T tst;
  real_T htmp2;
  real_T ba;
  real_T aa;
  real_T bb;
  real_T s_d;
  real_T h21s;
  real_T e_n;
  real_T aa_tmp;
  real_T temp;
  real_T lambda_p;
  real_T lambdac_b;
  real_T S_i;
  real_T b_r_b;
  real_T b_varargout_1_j;
  real_T R_g;
  real_T bet_n;
  real_T scale;
  real_T absxk;
  real_T t_p;
  real_T q_f;
  real_T x_fs;
  real_T br_a;
  real_T bi_g;
  real_T brm_m;
  real_T bim_d;
  real_T x_e;
  real_T xnorm;
  real_T b_alpha1_tmp;
  real_T temp_e;
  real_T lambda_d;
  real_T lambdac_j;
  real_T S_n;
  real_T b_varargout_1_ju;
  real_T b_varargout_1_p;
  real_T bkj;
  real_T tol;
  real_T wj;
  real_T scale_a;
  real_T absxk_d;
  real_T t_pz;
  real_T smax;
  real_T c_d2;
  real_T lambda_pq;
  real_T lambdac_f;
  real_T S_g;
  real_T b_varargout_1_d;
  real_T b_varargout_1_h;
  real_T r_i;
  real_T br_m;
  real_T bi_c;
  real_T brm_l;
  real_T bim_p;
  real_T a_re;
  real_T r_i1;
  real_T a_b3;
  real_T r_gn;
  real_T bi_o;
  real_T ar;
  real_T brm_b;
  real_T bim_e;
  real_T sgnbi;
  real_T a_re_e;
  real_T da2_re;
  real_T da2_im;
  real_T r_im;
  real_T ratio;
  real_T j;
  real_T re;
  real_T im;
  real_T r_l;
  real_T fd;
  real_T fd_c;
  real_T fd_e;
  real_T fd_d;
  real_T fd_o;
  real_T fd_l;
  real_T fd_h;
  real_T fd_ln;
  real_T fd_c5;
  real_T gn;
  real_T gn_c;
  real_T gn_a;
  real_T gn_i;
  real_T gn_l;
  real_T gn_iy;
  real_T gn_az;
  real_T gn_ix;
  real_T gn_c3;
  real_T gn_m;
  real_T gn_n;
  real_T gd;
  real_T gd_c;
  real_T gd_n;
  real_T gd_h;
  real_T gd_i;
  real_T gd_e;
  real_T gd_p;
  real_T gd_k;
  real_T gd_i3;
  real_T gd_nl;
  real_T gd_o;
  real_T gd_l;
  real_T xabs;
  real_T br_p;
  real_T x4_re;
  real_T x4_im;
  real_T x4;
  real_T lambda_b;
  real_T lambdac_fy;
  real_T S_is;
  real_T b_varargout_1_c;
  real_T b_varargout_1_gl;
  real_T b_alpha1;
  real_T tau_i;
  real_T xnorm_b;
  real_T scale_n;
  real_T absxk_p;
  real_T t_o;
  real_T scale_b;
  real_T absxk_o;
  real_T t_c;
  real_T lb;
  real_T optimRelativeFactor;
  real_T p;
  real_T e_jc;
  real_T t2_e;
  real_T t3_p;
  real_T t4_n;
  real_T t5_o;
  real_T t6_d;
  real_T t7_g;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12_i;
  real_T t13;
  real_T t17_i;
  real_T t18;
  real_T t19_c;
  real_T t20_b;
  real_T t21_g;
  real_T t22_d;
  real_T t23_f;
  real_T t24;
  real_T t25_j;
  real_T t26_e;
  real_T t27_p;
  real_T t28_d;
  real_T t29_f;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t42_n;
  real_T t43;
  real_T t44;
  real_T t45;
  real_T t55;
  real_T t56;
  real_T t57_o;
  real_T t58_d;
  real_T t61;
  real_T t62_l;
  real_T t65_f;
  real_T t68;
  real_T t60;
  real_T t46;
  real_T t47;
  real_T t48;
  real_T t27_tmp;
  real_T t31_tmp;
  real_T t24_tmp;
  real_T t32_tmp;
  real_T t25_tmp;
  real_T t29_tmp;
  real_T r_jf;
  real_T ar_g;
  real_T ai;
  real_T brm_lt;
  real_T bim_k;
  real_T a_re_p;
  real_T phi_b;
  real_T b_x_tmp;
  real_T y_tmp;
  real_T l_tmp;
  real_T r_i3;
  real_T a_p;
  real_T r_lb;
  real_T br_e;
  real_T k;
  real_T y_e;
  real_T d_p;
  real_T d1;
  real_T i;
  real_T j_j;
  real_T i_g;
  real_T c_tmp;
  real_T alpha_tmp;
  real_T b_gamma_tmp;
  real_T alpha_tmp_l;
  real_T b_gamma_tmp_j;
  real_T r_p;
  real_T a_re_d;
  real_T phi_k;
  real_T b_x_tmp_m;
  real_T i_f;
  real_T j_m;
  real_T v_n;
  real_T phi_alpha;
  real_T e_m;
  real_T ic_b;
  real_T x_cc;
  real_T s_idx_0;
  real_T s_idx_1;
  real_T bkj_g;
  real_T v_data_tmp;
  real_T v_data_tmp_c;
  real_T alpha_tmp_i;
  real_T b_gamma_tmp_k;
  real_T alpha_data_tmp;
  real_T i_go;
  real_T j_p;
  real_T x_fd;
  real_T r_m;
  real_T X0_m;
  real_T MVWeights0;
  real_T qerr_a;
  real_T qerr_b;
  real_T qerr_c;
  real_T x_a;
  real_T x_b;
  real_T x_c_l;
  real_T x_d;
  real_T n_j;
  real_T scale_m;
  real_T absxk_j;
  real_T t_i;
  real_T linAccelErr_idx_1;
  real_T gyroOffsetErr_idx_2;
  real_T linAccelErr_idx_2;
  real_T smax_a;
  real_T s_h;
  real_T e_d;
  real_T gfE;
  real_T ic_i2;
  real_T work_hr;
  real_T tmp2;
  real_T yv;
  real_T scale_d;
  real_T absxk_l;
  real_T t_f;
  real_T n_l;
  real_T q_d_l;
  real_T q_c;
  real_T q_b;
  real_T q_a;
  real_T n_f;
  real_T tst_g;
  real_T htmp2_g;
  real_T ba_a;
  real_T aa_d;
  real_T bb_b;
  real_T s_dg;
  real_T h21s_f;
  real_T t3_a;
  real_T e_mq;
  real_T p_i;
  real_T bcmax;
  real_T bcmis;
  real_T scale_i;
  real_T z_kq;
  real_T tau_a;
  real_T a_m;
  real_T ab2;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T aasq;
  real_T val_ce;
  real_T n_b;
  real_T maximum;
  real_T x_kg;
  real_T d_u;
  real_T iter;
  real_T dw;
  real_T ca;
  real_T sa;
  real_T windote;
  real_T magsq;
  real_T absx_l;
  real_T temp2_idx_0;
  real_T temp2_idx_1;
  real_T temp2_idx_2;
  real_T temp2_idx_0_tmp;
  real_T windote_tmp;
  real_T nrm;
  real_T rt;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift_n;
  real_T a__3_p;
  real_T d_sn;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_f;
  real_T ads;
  real_T bds;
  real_T d2;
  real_T ar_k;
  real_T ai_e;
  real_T e_na;
  real_T fs;
  real_T wtYerr;
  real_T wtYerr_o;
  real_T umvk_ad;
  real_T duk_b;
  real_T b_gamma_b;
  real_T d3;
  real_T d4;
  real_T mu;
  real_T r_mg;
  real_T a_mc;
  real_T a_k;
  real_T t_m;
  real_T dt;
  real_T b_hk;
  real_T l_0;
  real_T l_1;
  real_T l_2;
  real_T l;
  real_T b_i1;
  real_T r_c;
  real_T f_2_re;
  real_T f_2_im;
  real_T f_1_im;
  real_T dkappa_tmp;
  real_T f_1_im_tmp;
  real_T im_tmp;
  real_T f_1_im_tmp_tmp;
  real_T d_idx_0;
  real_T l_0_tmp;
  real_T f_1_im_tmp_n;
  real_T thresh;
  real_T d_data_il;
  real_T y_data_oc;
  real_T y_data_hy;
  real_T k_data_p;
  real_T v_re;
  real_T thresh_tmp;
  real_T igt_data_idx_0;
  real_T xabs_data_g;
  real_T r_cy;
  real_T ismall_tmp_data;
  real_T a_re_g;
  real_T y_re;
  real_T x4_re_b;
  real_T z_data_idx_0;
  real_T x4_data_idx_0;
  real_T wtYerr_j;
  real_T runtimedata_OutputWeights_h;
  real_T wtYerr_d;
  real_T t8_o;
  real_T t9_k;
  real_T t11_j;
  real_T t12_d;
  real_T t13_f;
  real_T t14_a;
  real_T t15_e;
  real_T t16_n;
  real_T t24_o;
  real_T t27_d;
  real_T t29_c;
  real_T t41_m;
  real_T t44_o;
  real_T t45_b;
  real_T t17_m;
  real_T t18_i;
  real_T t19_i;
  real_T t52;
  real_T t55_g;
  real_T t65_m;
  real_T t68_n;
  real_T t69;
  real_T t70_c;
  real_T t12_tmp;
  real_T t13_tmp;
  real_T t14_tmp;
  real_T t15_tmp;
  real_T out1_tmp;
  real_T out1_tmp_j;
  real_T out1_tmp_e;
  real_T out1_tmp_ep;
  real_T out1_tmp_k;
  real_T out1_tmp_k4;
  real_T out1_tmp_i;
  real_T out1_tmp_eh;
  real_T dt_l;
  real_T wayPoints_idx_0;
  real_T wayPoints_idx_1;
  real_T coefMat_tmp;
  real_T xloc;
  real_T x_ld;
  real_T x2;
  real_T b_qd;
  real_T theta;
  real_T st;
  real_T absxk_lc;
  real_T t_ob;
  real_T ang_data;
  real_T th0_idx_0;
  real_T th0_idx_1;
  real_T th0_idx_2;
  real_T angVel_tmp;
  real_T angVel_tmp_i;
  real_T sa_data;
  real_T thd1_data;
  real_T thd2_data;
  real_T w2_data;
  real_T ca_data;
  real_T m_data_idx_0;
  real_T n_data_idx_0;
  real_T c_data_idx_0;
  real_T q_data_idx_0;
  real_T ut2_data_idx_0;
  real_T wwd_data_idx_0;
  real_T ca_data_idx_0;
  real_T l_0_e;
  real_T l_1_l;
  real_T l_2_n;
  real_T l_e;
  real_T b_cu;
  real_T r_a;
  real_T f_2_re_m;
  real_T f_2_im_c;
  real_T f_1_im_f;
  real_T dkappa_tmp_m;
  real_T f_1_im_tmp_k;
  real_T im_tmp_b;
  real_T f_1_im_tmp_tmp_h;
  real_T d_idx_0_h;
  real_T l_0_tmp_h;
  real_T f_1_im_tmp_b;
  real_T r_b;
  real_T ar_d;
  real_T x_im;
  real_T x_re;
  real_T x_re_j;
  real_T x_im_d;
  real_T d_data_idx_0;
  real_T ar_l;
  real_T ai_j;
  real_T alpha_tmp_b;
  real_T b_gamma_tmp_f;
  real_T b_gamma_data_tmp;
  real_T m_p;
  real_T mnew;
  real_T dz_re;
  real_T dz_im;
  real_T tmp1_re;
  real_T tmp1_im;
  real_T a__1_l;
  real_T nrmGradInf;
  real_T nrmDirInf;
  real_T u1;
  real_T beta_l;
  real_T rho;
  real_T qpfvalLinearExcess;
  real_T qpfvalQuadExcess;
  real_T y_i;
  real_T b_o;
  real_T normDelta;
  real_T i_b;
  real_T s_it;
  real_T temp_g;
  real_T b_po;
  real_T constrViolation_new;
  real_T constrViolation_basicX;
  real_T c_h5;
  real_T b_atmp;
  real_T xnorm_d;
  real_T scale_fb;
  real_T absxk_f;
  real_T t_c1;
  real_T m_d;
  real_T mnew_c;
  real_T nseg;
  real_T zleft_im;
  real_T zright_re;
  real_T zright_im;
  real_T Lbd;
  real_T a_bc;
  real_T b_pw;
  real_T hs;
  real_T hs3;
  real_T anrm;
  real_T absxk_h;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T mul;
  real_T anorm;
  real_T scale_e;
  real_T colscale;
  real_T colssq;
  real_T absxk_lb;
  real_T t_h;
  real_T ar_n;
  real_T ai_k;
  real_T ascale_im;
  real_T eshift_re;
  real_T eshift_im;
  real_T t1_tmp;
  real_T scale_bt;
  real_T g2;
  real_T f2s;
  real_T di;
  real_T b_x_o;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  real_T anrm_n;
  real_T absxk_fi;
  real_T cfromc_g;
  real_T ctoc_d;
  real_T cfrom1_d;
  real_T cto1_e;
  real_T mul_c;
  real_T anorm_a;
  real_T scale_h;
  real_T colscale_e;
  real_T colssq_n;
  real_T absxk_hg;
  real_T t_oc;
  real_T ar_f;
  real_T ai_k1;
  real_T eshift_re_e;
  real_T eshift_im_i;
  real_T t1_tmp_o;
  real_T scale_j;
  real_T g2_k;
  real_T d_j;
  real_T f2s_d;
  real_T b_x_g;
  real_T fs_re_c;
  real_T fs_im_k;
  real_T gs_re_j;
  real_T gs_im_h;
  real_T oldDirIdx;
  real_T constrViolation;
  real_T tol_c;
  real_T qtb;
  real_T temp2;
  real_T smax_d;
  real_T temp_a;
  real_T obj_p;
  real_T B_idx_0;
  real_T whiteNoiseDrift_idx_0;
  real_T B_idx_1;
  real_T whiteNoiseDrift_idx_1;
  real_T B_idx_2;
  real_T whiteNoiseDrift_idx_2;
  real_T x_idx_0;
  real_T x_idx_2;
  real_T x_idx_4;
  real_T penaltyParamTrial;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  real_T b_c_f;
  real_T u0;
  real_T y_h;
  real_T mu_j;
  real_T b_gamma_n;
  real_T obj_o1;
  real_T whiteNoiseDrift_idx_0_o;
  real_T temperatureDrift_idx_0;
  real_T whiteNoiseDrift_idx_1_d;
  real_T temperatureDrift_idx_1;
  real_T whiteNoiseDrift_idx_2_a;
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
  real_T linearScaling;
  real_T n_k;
  real_T q2n_b;
  real_T q2n_c;
  real_T theta0;
  real_T sinv_tmp;
  real_T n_tmp;
  real_T q1n_a_tmp;
  real_T q1n_b_tmp;
  real_T q1n_c_tmp;
  real_T q1n_d_tmp;
  real_T q2n_a_tmp;
  real_T q2n_b_tmp;
  real_T q2n_c_tmp;
  real_T q2n_d_tmp;
  real_T e_idx_0;
  real_T b_idx_0;
  real_T n_tmp_c;
  real_T q1n_a;
  real_T q1n_b;
  real_T q1n_c;
  real_T q1n_d;
  real_T q2n_a;
  real_T q2n_b_j;
  real_T q2n_c_b;
  real_T dp_n;
  real_T theta0_d;
  real_T c_idx_0;
  real_T c_idx_1;
  real_T c_idx_2;
  real_T s_idx_0_h;
  real_T s_idx_1_b;
  real_T s_idx_2;
  real_T q_tmp;
  real_T b0_data;
  real_T tmp_data_pyh;
  real_T e_bp;
  real_T rtb_Transpose1_idx_0;
  real_T smax_p;
  real_T s_n;
  real_T d2_re;
  real_T d2_im;
  real_T optimRelativeFactor_j;
  real_T nlpComplErrorTmp;
  real_T nlpComplErrorLSQ;
  real_T tol_b;
  real_T d5;
  real_T c_ny;
  real_T zleft_re;
  real_T zleft_im_b;
  real_T zright_re_j;
  real_T zright_im_k;
  real_T temp_d;
  real_T r_d;
  real_T a_re_o;
  real_T y_data_idx_0;
  real_T tol_cf;
  real_T denomTol;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio_o;
  real_T c_aj;
  real_T c_dq;
  real_T e_e;
  real_T c_c_i;
  real_T b_s;
  real_T b_temp;
  real_T roe_b;
  real_T absa_a;
  real_T absb_k;
  real_T scale_m2;
  real_T ads_j;
  real_T bds_j;
  real_T ssq;
  real_T c_k;
  real_T c_kp;
  real_T d6;
  real_T stemp_re;
  real_T stemp_im;
  real_T c_ar;
  real_T d7;
  real_T stemp_re_k;
  real_T stemp_im_f;
  real_T x_a_c;
  real_T y_a_o;
  real_T x_b_k;
  real_T y_b_p;
  real_T x_c_f;
  real_T y_c_d;
  real_T x_d_e;
  real_T deltaq_a;
  real_T deltaq_b;
  real_T deltaq_c;
  real_T deltaq_d;
  real_T u1_l;
  real_T c_e;
  real_T u1_h;
  real_T c_g;
  real_T u1_p;
  real_T c_nl;
  real_T neg_D;
  real_T y_o2;
  real_T temp_l;
  real_T pd;
  real_T tol_f;
  real_T temp_h;
  real_T ac2_d;
  real_T ad2_m;
  real_T bc2_i;
  real_T bd2_j;
  real_T cd2_p;
  real_T tol_d;
  real_T scale_jb;
  real_T absxk_k;
  real_T t_mc;
  real_T b1;
  real_T b2;
  real_T b0;
  real_T temp2_idx_0_d;
  real_T b1_p;
  real_T b2_i;
  real_T b0_g;
  real_T temp2_idx_0_e;
  real_T xnorm_h;
  real_T scale_g;
  real_T absxk_c;
  real_T t_a;
  real_T atmp_re;
  real_T atmp_im;
  real_T dotSY;
  real_T curvatureS;
  real_T temp_f;
  real_T vnorm;
  real_T qnorm;
  real_T vscale_data;
  real_T x_data_i;
  real_T atmp_re_c;
  real_T atmp_im_n;
  real_T temp_c;
  real_T scale_c;
  real_T absxk_i;
  real_T t_hu;
  real_T temp_m;
  real_T c_go;
  real_T lbDelta;
  real_T lbLambda;
  real_T ubLambda;
  real_T temp_tmp;
  real_T temp_tmp_o;
  real_T c_m;
  real_T temp_ex;
  real_T c_ea;
  real_T absx_i;
  real_T z_f;
  real_T c_hv;
  real_T c_i;
  real_T absxr;
  real_T absxi;
  real_T c_pi;
  real_T scale_aa;
  real_T absxk_fj;
  real_T c_dd;
  real_T scale_cu;
  real_T absxk_j1;
  SL_Bus_proc_control_node_std_msgs_UInt8 In1_g;// '<S197>/In1'
  uint16_T NtoRPM[8];                  // '<S15>/N to RPM'
  uint32_T u32[2];
  uint32_T b_u[2];
  int32_T A_size[2];
  int32_T waypoints_size[2];
  int32_T Jtri_size[2];
  int32_T b_varargout_2_size[2];
  int32_T y_size[2];
  int32_T tmp_size[2];
  int32_T T_size[2];
  int32_T A_size_c[2];
  int32_T A_size_n[2];
  int32_T c_h_size[2];
  int32_T b_h_size[2];
  int32_T Jtri_size_j[2];
  int32_T b_varargout_2_size_k[2];
  int32_T J_size[2];
  int32_T A_size_o[2];
  int32_T tmp_size_g[2];
  int32_T y_size_k[2];
  int32_T A_size_j[2];
  int32_T b_jpvt_size[2];
  int32_T d_A_size[2];
  int32_T b_jpvt_size_p[2];
  int32_T e_A_size[2];
  int32_T b_A_size[2];
  int32_T Jtri_size_h[2];
  int32_T b_varargout_2_size_n[2];
  int32_T Jtri_size_b[2];
  int32_T b_varargout_2_size_m[2];
  int32_T c_a_size[2];
  int32_T d_a_size[2];
  int32_T c_a_size_k[2];
  int32_T varargout_3_size[2];
  int32_T varargout_1_size[2];
  int32_T varargout_3_size_b[2];
  int32_T varargout_1_size_l[2];
  int32_T c_size[2];
  int32_T Jc_size[2];
  int32_T varargin_2_size[2];
  int32_T result_size[2];
  int32_T x_size[2];
  int32_T varargout_1_size_g[2];
  int32_T c_size_g[2];
  int32_T zy_size[2];
  int32_T result_size_n[2];
  int32_T Jx_c[2];
  int32_T tmp_size_e[2];
  int32_T b_fb[2];
  int32_T tmp_size_k[2];
  int32_T d_size[2];
  int32_T y_size_c[2];
  int32_T y_size_d[2];
  int32_T y_size_m[2];
  int32_T d_size_j[2];
  int32_T k_size[2];
  int32_T ismall_tmp_size[2];
  int32_T e_size[2];
  int32_T f_size[2];
  int32_T g_size[2];
  int32_T ang_size[2];
  int32_T angVel_size[2];
  int32_T qimag_size[2];
  int32_T sa_size[2];
  int32_T w_size[2];
  int32_T udot_size[2];
  int32_T wd1_size[2];
  int32_T wd1xu_size[2];
  int32_T wd2_size[2];
  int32_T tmp_size_c[2];
  int32_T w_size_d[2];
  int32_T tmp_size_p[2];
  int32_T ca_size[2];
  int32_T tmp_size_a[2];
  int32_T A_size_m[2];
  int32_T b_A_size_n[2];
  int32_T r_size[2];
  int32_T s_size[2];
  int32_T iv5[2];
  int32_T iv6[2];
  int32_T iv7[2];
  int32_T tmp_size_k5[2];
  int32_T Zout_size[2];
  int32_T z_size[2];
  int32_T dz_size[2];
  int32_T alpha_size[2];
  int32_T zorig_size[2];
  int32_T z_size_p[2];
  int32_T l_size[2];
  int32_T l_size_k[2];
  int32_T l_size_g[2];
  int32_T c_size_h[2];
  int32_T tmp_size_l[2];
  int32_T Zout_size_o[2];
  int32_T z_size_a[2];
  int32_T d1_size[2];
  int32_T d2_size[2];
  int32_T d1_size_n[2];
  int32_T zcurrent_size[2];
  int32_T l1_size[2];
  int32_T l1_size_o[2];
  int32_T l1_size_d[2];
  int32_T At_size[2];
  int32_T b_At_size[2];
  int32_T b_size[2];
  int32_T b_rhs_size[2];
  int32_T b_size_h[2];
  int32_T bvec2_size[2];
  int32_T b_size_h4[2];
  int32_T wf_size[2];
  int32_T e_size_a[2];
  int32_T tmp_size_kg[2];
  int32_T tmp_size_j[2];
  int32_T z_size_d[2];
  int32_T d1_size_p[2];
  int32_T tmp_size_d[2];
  int32_T d2_size_b[2];
  int32_T d1_size_o[2];
  int32_T l1_size_j[2];
  int32_T l1_size_p[2];
  int32_T l1_size_l[2];
  int32_T e_size_c[2];
  int32_T z_size_m[2];
  int32_T dz_size_h[2];
  int32_T alpha_size_a[2];
  int32_T dz_size_o[2];
  int32_T z_size_i[2];
  int32_T l_size_e[2];
  int32_T l_size_a[2];
  int32_T l_size_eu[2];
  int32_T b_size_d[2];
  int32_T b_size_l[2];
  boolean_T bv2[8];
  int8_T b_ipiv[6];
  int8_T b_ipiv_i[4];
  int32_T i_n;
  int32_T Selector1_tmp;
  int32_T Selector1_tmp_c;
  int32_T B_size;
  int32_T b_i4;
  int32_T b_i_d;
  int32_T i_b4;
  int32_T wpt_count;
  int32_T i_a;
  int32_T i_b5;
  int32_T i_nt;
  int32_T tmp_size_b;
  int32_T b_tmp_data_tmp;
  int32_T c_pik;
  int32_T k_i;
  int32_T loop_ub;
  int32_T u_size;
  int32_T v_size;
  int32_T tmp_size_kf;
  int32_T waypoints_size_c;
  int32_T maxiter;
  int32_T iter_n;
  int32_T loop_ub_b;
  int32_T v_size_m;
  int32_T dx_size;
  int32_T xnew_size;
  int32_T b_r_size;
  int32_T b_varargout_1_size;
  int32_T tmp_size_m;
  int32_T tmp_size_n;
  int32_T loop_ub_tmp;
  int32_T i_m;
  int32_T loop_ub_l;
  int32_T tmp_size_o;
  int32_T c_ix;
  int32_T b_i_p;
  int32_T last;
  int32_T b_idx;
  int32_T b_size_n;
  int32_T q_size;
  int32_T beta_size;
  int32_T y_size_idx_1;
  int32_T y_size_idx_1_c;
  int32_T y_size_idx_1_e;
  int32_T y_size_idx_1_j;
  int32_T y_size_idx_1_l;
  int32_T y_size_idx_1_jt;
  int32_T nx;
  int32_T b_k_c;
  int32_T beta1_size;
  int32_T n_bd;
  int32_T loop_ub_i;
  int32_T istart;
  int32_T jend;
  int32_T b_j_k;
  int32_T nx_l;
  int32_T nx_tmp;
  int32_T m_j;
  int32_T istart_m;
  int32_T jend_j;
  int32_T b_j_e;
  int32_T i_d;
  int32_T n_j4;
  int32_T ldh;
  int32_T itmax;
  int32_T i_k;
  int32_T L;
  int32_T k_o;
  int32_T m_n;
  int32_T nr;
  int32_T hoffset;
  int32_T b_h_b;
  int32_T b_h_data_tmp;
  int32_T h21s_tmp;
  int32_T htmp2_tmp;
  int32_T htmp2_tmp_i;
  int32_T loop_ub_d;
  int32_T c_x;
  int32_T temp_tmp_d;
  int32_T loop_ub_tmp_p;
  int32_T i_e;
  int32_T course_tmp;
  int32_T iter_ne;
  int32_T i_dz;
  int32_T z_tmp_m;
  int32_T i1;
  int32_T b_idx_g;
  int32_T i_i;
  int32_T b_i_k;
  int32_T i_im;
  int32_T istart_mc;
  int32_T b_j_j;
  int32_T im1n;
  int32_T in;
  int32_T ia0;
  int32_T knt;
  int32_T k_a;
  int32_T i_iw;
  int32_T b_alpha1_tmp_e;
  int32_T b_tmp;
  int32_T lastv;
  int32_T lastc;
  int32_T ix_i;
  int32_T b_hv;
  int32_T d_m;
  int32_T rowleft;
  int32_T ia;
  int32_T jA;
  int32_T maxiter_a;
  int32_T iter_o;
  int32_T loop_ub_o;
  int32_T v_size_n;
  int32_T dx_size_k;
  int32_T xnew_size_h;
  int32_T b_r_size_d;
  int32_T b_varargout_1_size_a;
  int32_T tmp_size_h;
  int32_T tmp_size_cc;
  int32_T loop_ub_tmp_b;
  int32_T m_c;
  int32_T inner;
  int32_T n_g;
  int32_T coffset;
  int32_T boffset;
  int32_T b_i_pj;
  int32_T d_size_i;
  int32_T e_size_j;
  int32_T Jtri_size_c;
  int32_T Jtri_size_ce;
  int32_T lambda_size;
  int32_T y_size_idx_1_f;
  int32_T y_size_idx_1_d;
  int32_T na;
  int32_T maxmn;
  int32_T minmana;
  int32_T b_k_n;
  int32_T mn;
  int32_T i_br;
  int32_T ldap1;
  int32_T jA_f;
  int32_T jy;
  int32_T loop_ub_j;
  int32_T c_tmp_h;
  int32_T mmj_tmp;
  int32_T c_x_size_idx_1;
  int32_T c_x_size_idx_0;
  int32_T ma;
  int32_T minmn;
  int32_T nmi;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T b_j_h;
  int32_T kend;
  int32_T b_A_c;
  int32_T work_size;
  int32_T b_jpvt_data_tmp;
  int32_T lastv_g;
  int32_T lastc_e;
  int32_T d_e;
  int32_T coltop;
  int32_T ia_a;
  int32_T jA_h;
  int32_T b_C;
  int32_T maxiter_g;
  int32_T iter_a;
  int32_T loop_ub_g;
  int32_T v_size_o;
  int32_T dx_size_a;
  int32_T xnew_size_e;
  int32_T b_r_size_h;
  int32_T epsr_size;
  int32_T xnew_size_j;
  int32_T loop_ub_tmp_bq;
  int32_T e_k;
  int32_T f_h;
  int32_T k_d;
  int32_T l_o;
  int32_T o;
  int32_T p_k;
  int32_T u_k;
  int32_T cb;
  int32_T loop_ub_on;
  int32_T a__2_size;
  int32_T k0_size;
  int32_T k1_size;
  int32_T dk0_dc0_size;
  int32_T dk0_dc1_size;
  int32_T dk1_dc0_size;
  int32_T dk1_dc1_size;
  int32_T course_size;
  int32_T hip_size;
  int32_T course_size_d;
  int32_T nx_lo;
  int32_T b_k_m;
  int32_T z_size_o;
  int32_T phi_size;
  int32_T phi0_size;
  int32_T phi1_size;
  int32_T da_dphi1_size;
  int32_T y_size_a;
  int32_T nx_tmp_i;
  int32_T nx_f;
  int32_T h_idx_0;
  int32_T criteria_size;
  int32_T y_tmp_size;
  int32_T criteria_size_a;
  int32_T a_size;
  int32_T d_size_g;
  int32_T c_size_k;
  int32_T a_size_idx_0;
  int32_T ilarge_size_idx_0;
  int32_T ismall_size_idx_0;
  int32_T nx_l3;
  int32_T b_k_e;
  int32_T a1_size;
  int32_T a2_size;
  int32_T fa_size;
  int32_T ratio_size;
  int32_T x_size_e;
  int32_T tmp_size_f;
  int32_T s_size_idx_0;
  int32_T i2;
  int32_T loop_ub_dw;
  int32_T tmp_size_bc;
  int32_T x_size_o;
  int32_T i_p;
  int32_T ismall;
  int32_T b_idx_0_l;
  int32_T tmp_size_do;
  int32_T tmp_size_lt;
  int32_T ibig_size;
  int32_T xabs_size_idx_0;
  int32_T ismall_size_idx_0_a;
  int32_T nx_n;
  int32_T idx_e;
  int32_T b_ii;
  int32_T maxiter_n;
  int32_T iter_h;
  int32_T loop_ub_a;
  int32_T v_size_b;
  int32_T dx_size_k5;
  int32_T b_r_size_a;
  int32_T epsx_size;
  int32_T epsr_size_k;
  int32_T xnew_size_p;
  int32_T loop_ub_tmp_o;
  int32_T n_c;
  int32_T im1n_k;
  int32_T in_h;
  int32_T e_bv;
  int32_T c_a_ez;
  int32_T b_i_c;
  int32_T loop_ub_om;
  int32_T mIneq;
  int32_T mConstrMax;
  int32_T maxDims;
  int32_T mLB;
  int32_T k_ar;
  int32_T ix_p;
  int32_T ia_o;
  int32_T c_k_l;
  int32_T loop_ub_f;
  int32_T tmp_size_pn;
  int32_T tmp_size_p5;
  int32_T b_y_size_idx_0;
  int32_T mFixed;
  int32_T mIneq_b;
  int32_T mLB_k;
  int32_T mUB;
  int32_T idxLambdaNonlinIneq;
  int32_T ix_m;
  int32_T iy;
  int32_T ia_g;
  int32_T b_c_b;
  int32_T b_iy;
  int32_T b_ia;
  int32_T loop_ub_il;
  int32_T u1_b;
  int32_T mConstr_tmp;
  int32_T nVar_tmp_tmp;
  int32_T mLinIneq_tmp_tmp;
  int32_T c_idx_col;
  int32_T b_k_h;
  int32_T result;
  int32_T c_result;
  int32_T result_idx_0;
  int32_T i3;
  int32_T b_k_d;
  int32_T nx_f5;
  int32_T b_k_dk;
  int32_T b_size_p;
  int32_T e_size_g;
  int32_T y_tmp_size_f;
  int32_T a_size_o;
  int32_T d_size_f;
  int32_T c_size_o;
  int32_T ilarge_size_idx_0_l;
  int32_T ismall_size_idx_0_e;
  int32_T izero_size_idx_0;
  int32_T nx_g;
  int32_T b_k_b;
  int32_T k_size_j;
  int32_T tmp_size_fp;
  int32_T y_size_idx_0;
  int32_T nik_size_idx_0;
  int32_T e_co;
  int32_T f_f;
  int32_T k_b;
  int32_T l_d;
  int32_T o_j;
  int32_T p_o;
  int32_T u_l;
  int32_T cb_g;
  int32_T loop_ub_m;
  int32_T a__4_size;
  int32_T k0_size_g;
  int32_T k1_size_a;
  int32_T dk0_dc0_size_e;
  int32_T dk0_dc1_size_b;
  int32_T dk1_dc0_size_e;
  int32_T dk1_dc1_size_m;
  int32_T course_size_h;
  int32_T hip_size_b;
  int32_T course_size_dm;
  int32_T n_oh;
  int32_T result_k;
  int32_T result_m;
  int32_T i_fj;
  int32_T b_idx_0_o;
  int32_T u_size_i;
  int32_T v_size_k;
  int32_T tmp_size_kgg;
  int32_T b_k_n1;
  int32_T loop_ub_fq;
  int32_T i_mz;
  int32_T b_k_i;
  int32_T n_i;
  int32_T ibtile;
  int32_T b_k_bl;
  int32_T mLinIneq;
  int32_T loop_ub_n;
  int32_T y_size_idx_0_i;
  int32_T ineqEnd;
  int32_T c_nj;
  int32_T unnamed_idx_1;
  int32_T result_m0;
  int32_T result_idx_0_p;
  int32_T inner_k;
  int32_T coffset_p;
  int32_T boffset_e;
  int32_T inner_k2;
  int32_T u_b;
  int32_T v_size_idx_0;
  int32_T b_k_l;
  int32_T acoef;
  int32_T ia_j;
  int32_T acoef_j;
  int32_T bcoef;
  int32_T alpha_size_idx_0;
  int32_T n_kz;
  int32_T ibtile_p;
  int32_T b_k_p;
  int32_T aoffset;
  int32_T b_i_e;
  int32_T H_tmp;
  int32_T H_tmp_h;
  int32_T H_tmp_i;
  int32_T i4;
  int32_T kBcol;
  int32_T jj;
  int32_T b_j_jd;
  int32_T c_a2;
  int32_T i5;
  int32_T k_j;
  int32_T d_k;
  int32_T i_gc;
  int32_T i6;
  int32_T b_c_size;
  int32_T i7;
  int32_T i8;
  int32_T loop_ub_nj;
  int32_T empty_non_axis_sizes_idx_0;
  int32_T varargin_1_size_idx_1_tmp;
  int32_T m_l;
  int32_T coffset_e;
  int32_T boffset_c;
  int32_T aoffset_h;
  int32_T bkj_o;
  int32_T m_dz;
  int32_T b_i_df;
  int32_T b_k_j;
  int32_T b_j_f;
  int32_T istart_k;
  int32_T b_j_n;
  int32_T i_nb;
  int32_T L_i;
  int32_T k_e;
  int32_T m_k;
  int32_T nr_k;
  int32_T hoffset_p;
  int32_T its;
  int32_T c_j_k;
  int32_T e_j_p;
  int32_T nx_p;
  int32_T k_bp;
  int32_T f_size_idx_1;
  int32_T b_x_data_tmp;
  int32_T i9;
  int32_T b_colIdx;
  int32_T i_c;
  int32_T k_de;
  int32_T b_j_c;
  int32_T b_kk;
  int32_T b_k_a;
  int32_T i_ic;
  int32_T x_tmp;
  int32_T qq;
  int32_T qjj;
  int32_T m_du;
  int32_T e_f;
  int32_T j_n;
  int32_T k_g;
  int32_T m_o;
  int32_T o_m;
  int32_T i10;
  int32_T loop_ub_h;
  int32_T a__3_size;
  int32_T k0_size_e;
  int32_T k1_size_m;
  int32_T dk0_dc0_size_i;
  int32_T dk0_dc1_size_h;
  int32_T dk1_dc0_size_n;
  int32_T dk1_dc1_size_e;
  int32_T course_size_e;
  int32_T hip_size_o;
  int32_T g;
  int32_T h_o;
  int32_T i_fr;
  int32_T j_mh;
  int32_T k_gf;
  int32_T loop_ub_c;
  int32_T a__5_size;
  int32_T k0_size_k;
  int32_T k1_size_d;
  int32_T dk0_dc0_size_c;
  int32_T dk0_dc1_size_k;
  int32_T dk1_dc0_size_k;
  int32_T dk1_dc1_size_f;
  int32_T x_size_g;
  int32_T hip_size_k;
  int32_T x_size_n;
  int32_T nx_pn;
  int32_T b_k_e2;
  int32_T i_l;
  int32_T i_ak;
  int32_T loop_ub_e;
  int32_T i11;
  int32_T Jtri_size_g;
  int32_T Jtri_size_f;
  int32_T tmp_size_ei;
  int32_T f_n;
  int32_T loop_ub_mz;
  int32_T u_size_b;
  int32_T b_i_n;
  int32_T b_j_c4;
  int32_T nx_m;
  int32_T b_k_js;
  int32_T b_size_hu;
  int32_T e_size_ct;
  int32_T tmp_size_mq;
  int32_T a_size_n;
  int32_T d_size_e;
  int32_T c_size_c;
  int32_T ilarge_size_idx_0_b;
  int32_T ismall_size_idx_0_p;
  int32_T izero_size_idx_0_i;
  int32_T i12;
  int32_T i13;
  int32_T trueCount;
  int32_T c_i_o;
  int32_T tmp_size_n3;
  int32_T ii_size_idx_0;
  int32_T ii_size_idx_1;
  int32_T igt_size_idx_0;
  int32_T igt_size_idx_1;
  int32_T ilt_size_idx_0;
  int32_T ilt_size_idx_1;
  int32_T ism_size_idx_0;
  int32_T ism_size_idx_1;
  int32_T nx_me;
  int32_T tmp_data_m4;
  int32_T i_dt;
  int32_T tmp_size_i;
  int32_T ismall_data_idx_0;
  int32_T nx_tmp_e;
  int32_T i14;
  int32_T nx_k;
  int32_T idx_p;
  int32_T ii;
  int32_T idx_j;
  int32_T coefsWithFlatStart_tmp;
  int32_T ii_data_idx_0;
  int32_T ii_size_idx_0_c;
  int32_T tGreaterThanTfIdx_data_idx_0;
  int32_T iv0;
  int32_T loop_ub_b2;
  int32_T loop_ub_lv;
  int32_T ii_size_idx_0_n;
  int32_T ii_size_idx_1_a;
  int32_T nx_nd;
  int32_T i1_d;
  int32_T j_g;
  int32_T thd1_tmp;
  int32_T thd1_tmp_f;
  int32_T thd1_size;
  int32_T thd2_size;
  int32_T i15;
  int32_T trueCount_g;
  int32_T c_i_l;
  int32_T d_j_l;
  int32_T nx_o;
  int32_T k_k;
  int32_T nrows;
  int32_T ibtile_g;
  int32_T b_jtilecol;
  int32_T a_kl;
  int32_T x_size_idx_0;
  int32_T x_size_idx_0_j;
  int32_T ar_tmp;
  int32_T i16;
  int32_T loop_ub_k;
  int32_T x_size_g1;
  int32_T nmax;
  int32_T i_h;
  int32_T loop_ub_me;
  int32_T loop_ub_tmp_tmp;
  int32_T e_kr;
  int32_T f_c;
  int32_T t_huh;
  int32_T v_hi;
  int32_T w_d;
  int32_T y_bl;
  int32_T ab;
  int32_T cb_p;
  int32_T eb;
  int32_T fb;
  int32_T loop_ub_cs;
  int32_T loop_ub_tmp_tmp_b;
  int32_T nVar;
  int32_T b_k_lt;
  int32_T iH0;
  int32_T y_size_idx_0_o;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T mIneq_d;
  int32_T temp_mw;
  int32_T b_mIneq;
  int32_T mLBOrig;
  int32_T mFiniteLB;
  int32_T tf_tmp;
  int32_T nVar_n;
  int32_T b_idx_m;
  int32_T loop_ub_in;
  int32_T y_size_idx_0_ol;
  int32_T PROBTYPE_ORIG;
  int32_T PHASEONE;
  int32_T mEqFixed;
  int32_T nVar_tmp;
  int32_T activeSetChangeID;
  int32_T nVar_a;
  int32_T globalActiveConstrIdx;
  int32_T workingIdx;
  int32_T TYPE;
  int32_T iQR0;
  int32_T iy_k;
  int32_T iyend;
  int32_T b_ix;
  int32_T c_iy;
  int32_T j_mi;
  int32_T ia_gp;
  int32_T nVar_nl;
  int32_T b_k_ic;
  int32_T loop_ub_ev;
  int32_T y_size_idx_0_e;
  int32_T nVar_b;
  int32_T ldq;
  int32_T ix_iv;
  int32_T iy_kh;
  int32_T b_d;
  int32_T ia_k;
  int32_T iAcol;
  int32_T br_az;
  int32_T b_ia_i;
  int32_T f_b;
  int32_T b_ic;
  int32_T mWConstr_tmp_tmp;
  int32_T iA0;
  int32_T iQR0_e;
  int32_T b_idx_l;
  int32_T obj_i;
  int32_T minmana_b;
  int32_T minmn_e;
  int32_T lda;
  int32_T ii_b;
  int32_T mmi_i;
  int32_T i_m1;
  int32_T knt_l;
  int32_T b_k_o;
  int32_T i_nm;
  int32_T i_in;
  int32_T loop_ub_or;
  int32_T loop_ub_tmp_tmp_m;
  int32_T p_a;
  int32_T ab_c;
  int32_T cb_d;
  int32_T db;
  int32_T gb;
  int32_T kb;
  int32_T lb_g;
  int32_T loop_ub_hh;
  int32_T nseg_tmp;
  int32_T nseg_tmp_b;
  int32_T zright_re_tmp;
  int32_T i17;
  int32_T b_k_ds;
  int32_T loop_ub_cp;
  int32_T rscale_size;
  int32_T n_h;
  int32_T j_f;
  int32_T istart_n;
  int32_T ilastm;
  int32_T iiter;
  int32_T jp1;
  int32_T jiter;
  int32_T nm1;
  int32_T col;
  int32_T b_A_size_idx_0;
  int32_T ctemp_tmp;
  int32_T ihi;
  int32_T i_do;
  int32_T j_e;
  int32_T ifirst;
  int32_T ilastm1;
  int32_T ilastm_e;
  int32_T iiter_p;
  int32_T jp1_n;
  int32_T jiter_f;
  int32_T b_x_eg;
  int32_T nm1_k;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  int32_T nVar_f;
  int32_T mConstrMax_k;
  int32_T idx_Aineq;
  int32_T idx_upper;
  int32_T idx_Partition;
  int32_T iy_p;
  int32_T iac;
  int32_T b_ia_h;
  int32_T idx_Aineq_tmp;
  int32_T b_dc;
  int32_T loop_ub_tmp_d;
  int32_T mTotalWorkingEq;
  int32_T totalRank;
  int32_T totalEq;
  int32_T ix_d;
  int32_T iy_j;
  int32_T b_k_aw;
  int32_T loop_ub_al;
  int32_T ma_a;
  int32_T minmana_l;
  int32_T minmn_i;
  int32_T nfxd;
  int32_T ma_n;
  int32_T minmn_b;
  int32_T ii_h;
  int32_T nmi_b;
  int32_T mmi_a;
  int32_T pvt_b;
  int32_T j_l;
  int32_T ix_h;
  int32_T k_do;
  int32_T lastv_g4;
  int32_T lastc_j;
  int32_T coltop_m;
  int32_T ia_l;
  int32_T jA_o;
  int32_T jy_p;
  int32_T nx_d;
  int32_T k_g5;
  int32_T f_size_idx_1_m;
  int32_T b_x_data_tmp_o;
  int32_T i18;
  int32_T k_f;
  int32_T loop_ub_ip;
  int32_T nVar_d;
  int32_T c_idx;
  int32_T b_ldw;
  int32_T A_maxDiag_idx;
  int32_T LD_diagOffset;
  int32_T order;
  int32_T ix_f;
  int32_T e_nq;
  int32_T ia_d;
  int32_T mNull_tmp;
  int32_T A_maxDiag_idx_c;
  int32_T LD_diagOffset_b;
  int32_T order_b;
  int32_T b_k_hh;
  int32_T LDimSizeP1_tmp_tmp;
  int32_T LDimSizeP1;
  int32_T subRows;
  int32_T LD_diagOffset_g;
  int32_T subBlockSize;
  int32_T FMat_offset;
  int32_T k_c;
  int32_T ix_dw;
  int32_T c_a1;
  int32_T ia_h;
  int32_T iy_c;
  int32_T nx_c;
  int32_T k_m;
  int32_T f_size_idx_1_o;
  int32_T b_x_data_tmp_e;
  int32_T i19;
  int32_T i20;
  int32_T i1_j;
  int32_T dx_tmp_tmp;
  int32_T b_I_tmp;
  int32_T jj_l;
  int32_T c_nz;
  int32_T c_en;
  int32_T a_c;
  int32_T i_j;
  int32_T j_my;
  int32_T fb_e;
  int32_T jb;
  int32_T nb;
  int32_T ob;
  int32_T loop_ub_hv;
  int32_T d2_re_tmp;
  int32_T d2_re_tmp_c;
  int32_T z_data_tmp;
  int32_T nVar_j;
  int32_T mFixed_a;
  int32_T mIneq_do;
  int32_T mLB_b;
  int32_T mUB_c;
  int32_T mLambda;
  int32_T nActiveConstr;
  int32_T fullRank_R;
  int32_T rankR;
  int32_T iQR_diag;
  int32_T iQR0_a;
  int32_T idx_i;
  int32_T n_p;
  int32_T k_me;
  int32_T i21;
  int32_T i_b1;
  int32_T itau;
  int32_T iaii;
  int32_T d_e3;
  int32_T b_k_f;
  int32_T ix_mz;
  int32_T b_iy_a;
  int32_T g_o;
  int32_T v_l;
  int32_T w_p;
  int32_T y_d;
  int32_T ab_b;
  int32_T cb_dn;
  int32_T eb_d;
  int32_T fb_eh;
  int32_T loop_ub_l2;
  int32_T dz_re_tmp;
  int32_T zleft_re_tmp;
  int32_T nx_kf;
  int32_T loop_ub_lc;
  int32_T nhikx;
  int32_T nikx_size_idx_0;
  int32_T nikx_size_idx_1;
  int32_T totalIneq;
  int32_T ldw;
  int32_T iyend_j;
  int32_T ix_hr;
  int32_T b_iy_k;
  int32_T iac_e;
  int32_T b_gi;
  int32_T ia_c;
  int32_T ix_o;
  int32_T b_iy_l;
  int32_T i_ej;
  int32_T k_mea;
  int32_T idxRotGCol;
  int32_T iA0_o;
  int32_T iUU0;
  int32_T b_idx_e;
  int32_T b_m;
  int32_T idxA1j;
  int32_T idxAjj;
  int32_T b_j_jo;
  int32_T ix_hj;
  int32_T iy_n;
  int32_T b_jc;
  int32_T n_d;
  int32_T jrow;
  int32_T jcol;
  int32_T jrow_j;
  int32_T jcol_k;
  int32_T j_b;
  int32_T nWFixed;
  int32_T idx_global;
  int32_T iAeq0;
  int32_T iATw0;
  int32_T b_idx_local;
  int32_T c_i_lt;
  int32_T mIneq_j;
  int32_T offsetEq1;
  int32_T offsetEq2;
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T colOffsetAeq;
  int32_T d_idx_row;
  int32_T mLB_n;
  int32_T mUB_g;
  int32_T mFixed_d;
  int32_T mIneq_o;
  int32_T b_k_aj;
  int32_T ix_e;
  int32_T b_iy_o;
  int32_T iac_i;
  int32_T mLB_bv;
  int32_T mUB_a;
  int32_T mFixed_j;
  int32_T mIneq_a;
  int32_T b_k_g;
  int32_T ix_oe;
  int32_T b_iy_ay;
  int32_T iac_c;
  int32_T mLB_d;
  int32_T mUB_d;
  int32_T mFixed_l;
  int32_T mIneq_dz;
  int32_T b_k_jj;
  int32_T ix_k;
  int32_T b_iy_d;
  int32_T iac_ce;
  int32_T LDimSizeP1_k;
  int32_T LD_diagOffset_p;
  int32_T subMatrixDim;
  int32_T k_em;
  int32_T nFixedConstr;
  int32_T nVar_i;
  int32_T idxPosQR;
  int32_T idxPosATwset;
  int32_T nDepIneq;
  int32_T nFixedConstr_b;
  int32_T nVar_iz;
  int32_T idxPosQR_h;
  int32_T idxPosATwset_d;
  int32_T nDepIneq_g;
  int32_T k_my;
  int32_T qs;
  int32_T k_gu;
  int32_T j_h;
  int32_T ii_a;
  int32_T nzcount;
  int32_T b_A_e;
  int32_T ix_ir;
  int32_T j_hl;
  int32_T ii_k;
  int32_T iA0_f;
  int32_T iQR0_l;
  int32_T b_idx_o;
  int32_T b_l;
  int32_T maxRegVar;
  int32_T iy_d;
  int32_T c_k_a;
  int32_T iy_jd;
  int32_T ix_om;
  int32_T br_eh;
  int32_T ar_m;
  int32_T b_cr;
  int32_T br_d;
  int32_T ar_c;
  int32_T ia_i;
  int32_T b_cr_k;
  int32_T c_c5;
  int32_T lastv_f;
  int32_T lastc_jn;
  int32_T ix_ie;
  int32_T idx_c;
  int32_T fMultiplier;
  int32_T iy_da;
  int32_T s_tmp;
  int32_T ix_a;
  int32_T b_iy_h;
  int32_T jjA;
  int32_T ix_kc;
  int32_T lastv_k;
  int32_T lastc_n;
  int32_T ix_j;
  int32_T b_iy_b;
  int32_T ix_es;
  int32_T b_iy_m;
  int32_T iL0;
  int32_T c_idx_o;
  int32_T ix_k3;
  int32_T iy_a;
  int32_T iL0_n;
  int32_T c_idx_p;
  int32_T ix_dq;
  int32_T iy_a3;
  int32_T k_ee;
  int32_T lastv_m;
  uint32_T bpIdx;
  uint32_T nbpts;
  uint32_T r_f;
  uint32_T mti;
  uint32_T y_h1;
  int8_T b_data_fx[3];
  int8_T f_data_l[3];
  int8_T b_data_px[3];
  int8_T f_data_n[3];
  int8_T b_data_id[3];
  int8_T f_data_b[3];
  boolean_T d_ev[3];
  boolean_T d_pr[3];
  boolean_T d_o[3];
  char_T expl_temp_b[3];
  uint16_T rtb_y_j_f;
  int8_T rtPrevAction;
  int8_T n_dg;
  int8_T ad;
  uint8_T Data;  // '<S12>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
  uint8_T u_i;
  boolean_T OR;                        // '<S12>/OR'
  boolean_T Reset;                     // '<S194>/Reset'
  boolean_T Merge1;                    // '<S11>/Merge1'
  boolean_T b_varargout_1_i;
  boolean_T SourceBlock_o1_m;          // '<S47>/SourceBlock'
  boolean_T SourceBlock_o1_g;          // '<S190>/SourceBlock'
  boolean_T SourceBlock_o1_j;          // '<S192>/SourceBlock'
  boolean_T OR1;                       // '<S12>/OR1'
  boolean_T SourceBlock_o1_cz;         // '<S46>/SourceBlock'
  boolean_T p_h;
  boolean_T p_f;
  boolean_T freelead;
  boolean_T freetail;
  boolean_T flag_h;
  boolean_T b_isvalid;
  boolean_T ismall_tmp_data_l;
  boolean_T flag_g;
  SL_Bus_proc_control_node_std_msgs_Int8 BusAssignment;// '<S5>/Bus Assignment'
  SL_Bus_proc_control_node_std_msgs_Bool b_varargout_2_l;
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment_c;// '<S6>/Bus Assignment' 
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment_o;// '<S7>/Bus Assignment' 
  SL_Bus_proc_control_node_std_msgs_Bool BusAssignment1;// '<S5>/Bus Assignment1' 
  SL_Bus_proc_control_node_std_msgs_UInt8 b_varargout_2_m;
  B_MATLABFunction1_proc_contro_T sf_MATLABFunction1_b;// '<S146>/MATLAB Function1' 
  B_MATLABFunction1_proc_contro_T sf_MATLABFunction1_ly;// '<S149>/MATLAB Function1' 
};

// Block states (default storage) for system '<Root>'
struct DW_proc_control_node_T {
  TrajectoryManager_proc_contro_T obj; // '<S150>/MATLAB System'
  fusion_simulink_imuSensor_pro_T obj_i;// '<S19>/IMU'
  fusion_simulink_ahrsfilter_pr_T obj_c;// '<S19>/AHRS'
  AddPose_proc_control_node_T obj_o;   // '<S148>/MATLAB System1'
  mpcManager_proc_control_node_T obj_g;// '<S90>/MPC manager'
  OpenLoopController_proc_contr_T obj_m;// '<S89>/MATLAB System'
  robotics_slcore_internal_bl_b_T obj_gr;// '<S175>/Rotation Trajectory'
  robotics_slcore_internal_bloc_T obj_k;// '<S175>/Polynomial Trajectory1'
  TrajectoryGenerator_proc_cont_T obj_ce;// '<S164>/MATLAB System2'
  AddPose_proc_control_node_b_T obj_or;// '<S150>/MATLAB System1'
  ros_slroscpp_internal_block_S_T obj_b;// '<S193>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_if;// '<S192>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S191>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_iv;// '<S190>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_a;// '<S172>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_gw;// '<S162>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_mi;// '<S161>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_bo;// '<S160>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_l;// '<S153>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_os;// '<S47>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_ai;// '<S46>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_d;// '<S87>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_lm;// '<S82>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_o5;// '<S78>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_bj;// '<S76>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_p;// '<S74>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_j;// '<S73>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_k0;// '<S72>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_jb;// '<S71>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_aj;// '<S70>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_dr;// '<S61>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_f5;// '<S58>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_os4;// '<S55>/SinkBlock'
  real_T Delay_DSTATE[3];              // '<S10>/Delay'
  real_T DiscreteTimeIntegrator_DSTATE[3];// '<S10>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S10>/Discrete-Time Integrator1'
  real_T Integrator_DSTATE[6];         // '<S156>/Integrator'
  real_T Integrator_DSTATE_h[6];       // '<S157>/Integrator'
  real_T Delay_DSTATE_f;               // '<S5>/Delay'
  real_T Delay_DSTATE_j;               // '<S174>/Delay'
  real_T DiscreteTimeIntegrator_DSTATE_a;// '<S175>/Discrete-Time Integrator'
  real_T UD_DSTATE[6];                 // '<S91>/UD'
  real_T Delay_DSTATE_b[8];            // '<S90>/Delay'
  real_T Tk;                           // '<S8>/First Order Hold'
  real_T Ck[12];                       // '<S8>/First Order Hold'
  real_T Mk[12];                       // '<S8>/First Order Hold'
  real_T Uk[12];                       // '<S8>/First Order Hold'
  real_T Tk_m;                         // '<S5>/First Order Hold1'
  real_T Ck_n[8];                      // '<S5>/First Order Hold1'
  real_T Mk_o[8];                      // '<S5>/First Order Hold1'
  real_T Uk_g[8];                      // '<S5>/First Order Hold1'
  real_T Tk_e;                         // '<S5>/First Order Hold'
  real_T Ck_b[8];                      // '<S5>/First Order Hold'
  real_T Mk_h[8];                      // '<S5>/First Order Hold'
  real_T Uk_h[8];                      // '<S5>/First Order Hold'
  real_T XDrift_NextOutput;            // '<S16>/X Drift'
  real_T YDrift_NextOutput;            // '<S16>/Y Drift'
  real_T NextOutput;                   // '<S28>/White Noise'
  real_T NextOutput_k;                 // '<S29>/White Noise'
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<S147>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S12>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     // '<S10>/Scope'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<S10>/Scope3'

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    // '<S9>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     // '<S11>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    // '<S10>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     // '<S175>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     // '<S148>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    // '<S148>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     // '<S89>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_ow;                    // '<S52>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     // '<S2>/Scope'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<S2>/Scope2'

  struct {
    void *LoggedData;
  } Scope3_PWORK_k;                    // '<S2>/Scope3'

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<S2>/Scope4'

  struct {
    void *LoggedData;
  } Scope_PWORK_py;                    // '<S15>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     // '<S1>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     // '<S16>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    // '<S16>/Scope1'

  int32_T clockTickCounter;            // '<S90>/Pulse Generator'
  uint32_T m_bpIndex[8];               // '<S9>/N to PWM'
  uint32_T m_bpIndex_f[8];             // '<S15>/ PWM to N'
  uint32_T m_bpIndex_m[8];             // '<S15>/N to RPM'
  uint32_T RandSeed;                   // '<S16>/X Drift'
  uint32_T RandSeed_n;                 // '<S16>/Y Drift'
  uint32_T RandSeed_g;                 // '<S28>/White Noise'
  uint32_T RandSeed_g2;                // '<S29>/White Noise'
  int_T Integrator1_IWORK;             // '<S1>/Integrator1'
  int_T Integrator_IWORK;              // '<S1>/Integrator'
  int_T Integrator2_IWORK;             // '<S1>/Integrator2'
  int_T Integrator3_IWORK;             // '<S1>/Integrator3'
  boolean_T Delay1_DSTATE;             // '<S150>/Delay1'
  boolean_T Delay_DSTATE_e;            // '<S148>/Delay'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S10>/Discrete-Time Integrator'
  int8_T If_ActiveSubsystem;           // '<S140>/If'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S10>/Discrete-Time Integrator1'
  int8_T Integrator_PrevResetState;    // '<S156>/Integrator'
  int8_T Integrator_PrevResetState_l;  // '<S157>/Integrator'
  int8_T SwitchCase_ActiveSubsystem;   // '<S11>/Switch Case'
  int8_T SwitchCase_ActiveSubsystem_c; // '<S9>/Switch Case'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S193>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_b;// '<S192>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S191>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_l;// '<S190>/Enabled Subsystem'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S11>/If Action Subsystem'
  int8_T singleWptsTrajectory_SubsysRanB;// '<S11>/singleWpts Trajectory'
  int8_T EnabledSubsystem_SubsysRanBC_co;// '<S174>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S182>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S182>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_h;// '<S182>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S172>/Enabled Subsystem'
  int8_T Pretraitement_SubsysRanBC;    // '<S150>/Pre-traitement'
  int8_T SubsystemAuto_SubsysRanBC;    // '<S11>/SubsystemAuto'
  int8_T Subsystem2_SubsysRanBC;       // '<S148>/Subsystem2'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S162>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_g;// '<S161>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_e;// '<S160>/Enabled Subsystem'
  int8_T SubsystemManual_SubsysRanBC;  // '<S11>/SubsystemManual'
  int8_T EnabledSubsystem_SubsysRanBC_m;// '<S153>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_g;// '<S140>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_a;// '<S140>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_b;// '<S140>/If Action Subsystem'
  int8_T IDLE_SubsysRanBC;             // '<S9>/IDLE'
  int8_T JoyStickOpenLoop_SubsysRanBC; // '<S9>/JoyStick OpenLoop'
  int8_T QuaternionNonlinearMPC_SubsysRa;// '<S9>/Quaternion Non linear MPC'
  int8_T SendTargetReached_SubsysRanBC;// '<Root>/Send Target Reached '
  int8_T ROSOutput_SubsysRanBC;        // '<Root>/ROS Output'
  int8_T EnabledSubsystem_SubsysRanBC_o;// '<S47>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S46>/Enabled Subsystem'
  int8_T Plotvalues_SubsysRanBC;       // '<Root>/Plot values'
  int8_T ModlePhysique_SubsysRanBC;    // '<Root>/Modèle Physique'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S10>/Discrete-Time Integrator'
  boolean_T Memory_PreviousInput;      // '<S194>/Memory'
  boolean_T ROSOutput_MODE;            // '<Root>/ROS Output'
  boolean_T Plotvalues_MODE;           // '<Root>/Plot values'
  boolean_T ModlePhysique_MODE;        // '<Root>/Modèle Physique'
  DW_Subsystem1_proc_control_no_T Subsystem1_e;// '<S150>/Subsystem1'
  DW_Subsystem1_proc_control_no_T Subsystem1;// '<S148>/Subsystem1'
};

// Continuous states (default storage)
struct X_proc_control_node_T {
  real_T Integrator1_CSTATE[4];        // '<S1>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S20>/Transfer Fcn'
  real_T TransferFcn_CSTATE_g;         // '<S21>/Transfer Fcn'
  real_T TransferFcn_CSTATE_p;         // '<S22>/Transfer Fcn'
  real_T TransferFcn_CSTATE_k;         // '<S23>/Transfer Fcn'
  real_T TransferFcn_CSTATE_e;         // '<S24>/Transfer Fcn'
  real_T TransferFcn_CSTATE_kk;        // '<S25>/Transfer Fcn'
  real_T TransferFcn_CSTATE_o;         // '<S26>/Transfer Fcn'
  real_T TransferFcn_CSTATE_l;         // '<S27>/Transfer Fcn'
  real_T Integrator_CSTATE[3];         // '<S1>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S1>/Integrator2'
  real_T Integrator3_CSTATE[3];        // '<S1>/Integrator3'
};

// State derivatives (default storage)
struct XDot_proc_control_node_T {
  real_T Integrator1_CSTATE[4];        // '<S1>/Integrator1'
  real_T TransferFcn_CSTATE;           // '<S20>/Transfer Fcn'
  real_T TransferFcn_CSTATE_g;         // '<S21>/Transfer Fcn'
  real_T TransferFcn_CSTATE_p;         // '<S22>/Transfer Fcn'
  real_T TransferFcn_CSTATE_k;         // '<S23>/Transfer Fcn'
  real_T TransferFcn_CSTATE_e;         // '<S24>/Transfer Fcn'
  real_T TransferFcn_CSTATE_kk;        // '<S25>/Transfer Fcn'
  real_T TransferFcn_CSTATE_o;         // '<S26>/Transfer Fcn'
  real_T TransferFcn_CSTATE_l;         // '<S27>/Transfer Fcn'
  real_T Integrator_CSTATE[3];         // '<S1>/Integrator'
  real_T Integrator2_CSTATE[3];        // '<S1>/Integrator2'
  real_T Integrator3_CSTATE[3];        // '<S1>/Integrator3'
};

// State disabled
struct XDis_proc_control_node_T {
  boolean_T Integrator1_CSTATE[4];     // '<S1>/Integrator1'
  boolean_T TransferFcn_CSTATE;        // '<S20>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_g;      // '<S21>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_p;      // '<S22>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_k;      // '<S23>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_e;      // '<S24>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_kk;     // '<S25>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_o;      // '<S26>/Transfer Fcn'
  boolean_T TransferFcn_CSTATE_l;      // '<S27>/Transfer Fcn'
  boolean_T Integrator_CSTATE[3];      // '<S1>/Integrator'
  boolean_T Integrator2_CSTATE[3];     // '<S1>/Integrator2'
  boolean_T Integrator3_CSTATE[3];     // '<S1>/Integrator3'
};

// Zero-crossing (trigger) state
struct PrevZCX_proc_control_node_T {
  ZCSigState Trajectorygenerator_Reset_ZCE;// '<S150>/Trajectory generator'
  ZCSigState Subsystem2_Trig_ZCE;      // '<S148>/Subsystem2'
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

// Parameters for system: '<S148>/Subsystem1'
struct P_Subsystem1_proc_control_nod_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S163>/Out1'

};

// Parameters (default storage)
struct P_proc_control_node_T_ {
  struct_ItE4fzFYlf4Io3uBaGCY9F mpc;   // Variable: mpc
                                          //  Referenced by:
                                          //    '<S9>/Saturation'
                                          //    '<S90>/MPC manager'
                                          //    '<S146>/Constant3'
                                          //    '<S149>/Constant3'

  struct_XEwOoQFSJ0yXWTYDIQhbTC physics;// Variable: physics
                                           //  Referenced by:
                                           //    '<S83>/Constant'
                                           //    '<S89>/MATLAB System'

  struct_RoPeIRaOs110XaoEJ1OUdD simulation;// Variable: simulation
                                              //  Referenced by:
                                              //    '<S83>/ '
                                              //    '<S83>/  '

  real_T Config10[29];                 // Variable: Config10
                                          //  Referenced by: '<S90>/MPC manager'

  real_T Config19[29];                 // Variable: Config19
                                          //  Referenced by: '<S90>/MPC manager'

  real_T N[201];                       // Variable: N
                                          //  Referenced by:
                                          //    '<S9>/N to PWM'
                                          //    '<S15>/ PWM to N'
                                          //    '<S15>/N to RPM'

  real_T RPM[201];                     // Variable: RPM
                                          //  Referenced by: '<S15>/N to RPM'

  real_T Ui[8];                        // Variable: Ui
                                          //  Referenced by: '<S90>/MPC manager'

  real_T binv[48];                     // Variable: binv
                                          //  Referenced by: '<S89>/MATLAB System'

  real_T constValues[41];              // Variable: constValues
                                          //  Referenced by: '<S90>/MPC manager'

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
                                          //  Referenced by: '<S152>/Gain'

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
                                          //  Referenced by: '<S152>/Gain'

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
                                    //  Referenced by: '<S152>/Constant4'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S91>/UD'

  real_T BandLimitedWhiteNoise_seed;
                                   // Mask Parameter: BandLimitedWhiteNoise_seed
                                      //  Referenced by: '<S28>/White Noise'

  real_T BandLimitedWhiteNoise1_seed;
                                  // Mask Parameter: BandLimitedWhiteNoise1_seed
                                     //  Referenced by: '<S29>/White Noise'

  boolean_T MinMaxRunningResettable_vinit;
                                // Mask Parameter: MinMaxRunningResettable_vinit
                                   //  Referenced by:
                                   //    '<S194>/Initial Condition'
                                   //    '<S194>/Memory'

  SL_Bus_proc_control_node_std_msgs_UInt16MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S63>/Constant'

  SL_Bus_proc_control_node_std_msgs_UInt16MultiArray Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S64>/Constant'

  SL_Bus_proc_control_node_std_msgs_Int8MultiArray Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                      //  Referenced by: '<S62>/Constant'

  SL_Bus_proc_control_node_nav_msgs_Odometry Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                 //  Referenced by: '<S79>/Constant'

  SL_Bus_proc_control_node_sensor_msgs_Imu Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S48>/Out1'

  SL_Bus_proc_control_node_sensor_msgs_Imu Constant_Value_d5;// Computed Parameter: Constant_Value_d5
                                                                //  Referenced by: '<S46>/Constant'

  SL_Bus_proc_control_node_sensor_msgs_Imu Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                               //  Referenced by: '<S56>/Constant'

  SL_Bus_proc_control_node_gazebo_msgs_ModelState Constant_Value_py;// Computed Parameter: Constant_Value_py
                                                                      //  Referenced by: '<S85>/Constant'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                                     //  Referenced by: '<S49>/Out1'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                      //  Referenced by: '<S47>/Constant'

  SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                      //  Referenced by: '<S53>/Constant'

  struct_OiyVcB1FUG5CFSJbxuJtpE CleanOutput_Y0;// Computed Parameter: CleanOutput_Y0
                                                  //  Referenced by: '<S1>/Clean Output'

  struct_OiyVcB1FUG5CFSJbxuJtpE Output_Y0;// Computed Parameter: Output_Y0
                                             //  Referenced by: '<S4>/Output'

  struct_Ly3A2XJK4hMO23MSCkZ3VD SensorsOutput_Y0;// Computed Parameter: SensorsOutput_Y0
                                                    //  Referenced by: '<S1>/Sensors Output'

  SL_Bus_proc_control_node_sonia_common_AddPose Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                             //  Referenced by: '<S165>/Out1'

  SL_Bus_proc_control_node_sonia_common_AddPose Constant_Value_gj;// Computed Parameter: Constant_Value_gj
                                                                     //  Referenced by: '<S160>/Constant'

  SL_Bus_proc_control_node_sonia_common_AddPose Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                             //  Referenced by: '<S176>/Out1'

  SL_Bus_proc_control_node_sonia_common_AddPose Constant_Value_ck;// Computed Parameter: Constant_Value_ck
                                                                     //  Referenced by: '<S172>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Pose Constant_Value_g5;// Computed Parameter: Constant_Value_g5
                                                                   //  Referenced by: '<S59>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Pose Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                           //  Referenced by: '<S195>/Out1'

  SL_Bus_proc_control_node_geometry_msgs_Pose Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                  //  Referenced by: '<S190>/Constant'

  SL_Bus_proc_control_node_geometry_msgs_Twist Out1_Y0_b;// Computed Parameter: Out1_Y0_b
                                                            //  Referenced by: '<S158>/Out1'

  SL_Bus_proc_control_node_geometry_msgs_Twist Constant_Value_p3;// Computed Parameter: Constant_Value_p3
                                                                    //  Referenced by: '<S153>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                             //  Referenced by: '<S66>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                             //  Referenced by: '<S75>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_mi;// Computed Parameter: Constant_Value_mi
                                                              //  Referenced by: '<S77>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_au;// Computed Parameter: Out1_Y0_au
                                                       //  Referenced by: '<S166>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                             //  Referenced by: '<S161>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                                      //  Referenced by: '<S167>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_g5r;// Computed Parameter: Constant_Value_g5r
                                                               //  Referenced by: '<S162>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_ki;// Computed Parameter: Out1_Y0_ki
                                                       //  Referenced by: '<S196>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_ch;// Computed Parameter: Constant_Value_ch
                                                              //  Referenced by: '<S191>/Constant'

  SL_Bus_proc_control_node_std_msgs_Bool Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                                      //  Referenced by: '<S198>/Out1'

  SL_Bus_proc_control_node_std_msgs_Bool Constant_Value_pn;// Computed Parameter: Constant_Value_pn
                                                              //  Referenced by: '<S193>/Constant'

  SL_Bus_proc_control_node_std_msgs_Int8 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                             //  Referenced by: '<S65>/Constant'

  SL_Bus_proc_control_node_std_msgs_UInt8 Out1_Y0_ae;// Computed Parameter: Out1_Y0_ae
                                                        //  Referenced by: '<S197>/Out1'

  SL_Bus_proc_control_node_std_msgs_UInt8 Constant_Value_kv;// Computed Parameter: Constant_Value_kv
                                                               //  Referenced by: '<S192>/Constant'

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

  real_T TransferFcn_A_h;              // Computed Parameter: TransferFcn_A_h
                                          //  Referenced by: '<S21>/Transfer Fcn'

  real_T TransferFcn_C_m;              // Computed Parameter: TransferFcn_C_m
                                          //  Referenced by: '<S21>/Transfer Fcn'

  real_T TransferFcn_A_k;              // Computed Parameter: TransferFcn_A_k
                                          //  Referenced by: '<S22>/Transfer Fcn'

  real_T TransferFcn_C_a;              // Computed Parameter: TransferFcn_C_a
                                          //  Referenced by: '<S22>/Transfer Fcn'

  real_T TransferFcn_A_j;              // Computed Parameter: TransferFcn_A_j
                                          //  Referenced by: '<S23>/Transfer Fcn'

  real_T TransferFcn_C_j;              // Computed Parameter: TransferFcn_C_j
                                          //  Referenced by: '<S23>/Transfer Fcn'

  real_T TransferFcn_A_n;              // Computed Parameter: TransferFcn_A_n
                                          //  Referenced by: '<S24>/Transfer Fcn'

  real_T TransferFcn_C_d;              // Computed Parameter: TransferFcn_C_d
                                          //  Referenced by: '<S24>/Transfer Fcn'

  real_T TransferFcn_A_l;              // Computed Parameter: TransferFcn_A_l
                                          //  Referenced by: '<S25>/Transfer Fcn'

  real_T TransferFcn_C_k;              // Computed Parameter: TransferFcn_C_k
                                          //  Referenced by: '<S25>/Transfer Fcn'

  real_T TransferFcn_A_j1;             // Computed Parameter: TransferFcn_A_j1
                                          //  Referenced by: '<S26>/Transfer Fcn'

  real_T TransferFcn_C_g;              // Computed Parameter: TransferFcn_C_g
                                          //  Referenced by: '<S26>/Transfer Fcn'

  real_T TransferFcn_A_d;              // Computed Parameter: TransferFcn_A_d
                                          //  Referenced by: '<S27>/Transfer Fcn'

  real_T TransferFcn_C_c;              // Computed Parameter: TransferFcn_C_c
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

  real_T Gain_Gain_i;                  // Expression: -1
                                          //  Referenced by: '<S18>/Gain'

  real_T WhiteNoise_Mean_n;            // Expression: 0
                                          //  Referenced by: '<S29>/White Noise'

  real_T WhiteNoise_StdDev_f;         // Computed Parameter: WhiteNoise_StdDev_f
                                         //  Referenced by: '<S29>/White Noise'

  real_T ydevantZhaut_Value[3];        // Expression: [0,pi,pi/2]
                                          //  Referenced by: '<S18>/ y devant Z haut'

  real_T u2_Gain;                      // Expression: 0.5
                                          //  Referenced by: '<S32>/1//2'

  real_T Gain_Gain_c;                  // Expression: 2
                                          //  Referenced by: '<S36>/Gain'

  real_T Gain1_Gain;                   // Expression: 2
                                          //  Referenced by: '<S36>/Gain1'

  real_T Constant_Value_nr;            // Expression: 0.5
                                          //  Referenced by: '<S36>/Constant'

  real_T Gain2_Gain;                   // Expression: 2
                                          //  Referenced by: '<S36>/Gain2'

  real_T Gain_Gain_cc;                 // Expression: 2
                                          //  Referenced by: '<S37>/Gain'

  real_T Gain1_Gain_b;                 // Expression: 2
                                          //  Referenced by: '<S37>/Gain1'

  real_T Constant_Value_f;             // Expression: 0.5
                                          //  Referenced by: '<S37>/Constant'

  real_T Gain2_Gain_c;                 // Expression: 2
                                          //  Referenced by: '<S37>/Gain2'

  real_T Gain_Gain_f;                  // Expression: 2
                                          //  Referenced by: '<S38>/Gain'

  real_T Gain1_Gain_n;                 // Expression: 2
                                          //  Referenced by: '<S38>/Gain1'

  real_T Constant_Value_pd;            // Expression: 0.5
                                          //  Referenced by: '<S38>/Constant'

  real_T Gain2_Gain_i;                 // Expression: 2
                                          //  Referenced by: '<S38>/Gain2'

  real_T MPCmanager_eInit;             // Expression: 0
                                          //  Referenced by: '<S90>/MPC manager'

  real_T Output_Y0_i;                  // Computed Parameter: Output_Y0_i
                                          //  Referenced by: '<S90>/Output'

  real_T isActive_Y0;                  // Computed Parameter: isActive_Y0
                                          //  Referenced by: '<S90>/isActive'

  real_T Delay_InitialCondition[8];    // Expression: [0,0,0,0,0,0,0,0].'
                                          //  Referenced by: '<S90>/Delay'

  real_T md_zero_Value;                // Expression: zeros(1,1)
                                          //  Referenced by: '<S93>/md_zero'

  real_T mvtarget_zero_Value[8];       // Expression: zeros(8,1)
                                          //  Referenced by: '<S93>/mv.target_zero'

  real_T ymin_zero_Value[13];          // Expression: zeros(13,1)
                                          //  Referenced by: '<S93>/y.min_zero'

  real_T ymax_zero_Value[13];          // Expression: zeros(13,1)
                                          //  Referenced by: '<S93>/y.max_zero'

  real_T dmvmin_zero_Value[8];         // Expression: zeros(8,1)
                                          //  Referenced by: '<S93>/dmv.min_zero'

  real_T dmvmax_zero_Value[8];         // Expression: zeros(8,1)
                                          //  Referenced by: '<S93>/dmv.max_zero'

  real_T xmin_zero_Value[13];          // Expression: zeros(13,1)
                                          //  Referenced by: '<S93>/x.min_zero'

  real_T xmax_zero_Value[13];          // Expression: zeros(13,1)
                                          //  Referenced by: '<S93>/x.max_zero'

  real_T ecrwt_zero_Value;             // Expression: zeros(1,1)
                                          //  Referenced by: '<S93>/ecr.wt_zero'

  real_T params_zero_Value;            // Expression: zeros(1,1)
                                          //  Referenced by: '<S93>/params_zero'

  real_T PulseGenerator_Amp;           // Expression: 1
                                          //  Referenced by: '<S90>/Pulse Generator'

  real_T PulseGenerator_Period;        // Expression: 2
                                          //  Referenced by: '<S90>/Pulse Generator'

  real_T PulseGenerator_Duty;          // Expression: 1
                                          //  Referenced by: '<S90>/Pulse Generator'

  real_T PulseGenerator_PhaseDelay;    // Expression: 0
                                          //  Referenced by: '<S90>/Pulse Generator'

  real_T MATLABSystem_k;               // Expression: 40
                                          //  Referenced by: '<S89>/MATLAB System'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S91>/TSamp'

  real_T Constant1_Value[8];           // Expression: zeros(1,8)
                                          //  Referenced by: '<S88>/Constant1'

  real_T Constant_Value_ms;            // Expression: 1
                                          //  Referenced by: '<S141>/Constant'

  real_T Constant_Value_jf;            // Expression: 1
                                          //  Referenced by: '<S142>/Constant'

  real_T Constant7_Value[7];           // Expression: [0 0 0 1 0 0 0]
                                          //  Referenced by: '<S149>/Constant7'

  real_T MATLABSystem2_avanceRapide[7];// Expression: [1 1 .3 .1 .1 .1 .1]
                                          //  Referenced by: '<S164>/MATLAB System2'

  real_T MATLABSystem2_avancePrecision[7];// Expression: [.3 .3 .1 .05 .05 .05 .05]
                                             //  Referenced by: '<S164>/MATLAB System2'

  real_T MATLABSystem2_accRapide[7];
                                   // Expression: [0.2 0.2 0.1 .02 .02 .02 .02];
                                      //  Referenced by: '<S164>/MATLAB System2'

  real_T MATLABSystem2_accPrecision;   // Expression: 0.1
                                          //  Referenced by: '<S164>/MATLAB System2'

  real_T MATLABSystem2_Ts;             // Expression: 0.25
                                          //  Referenced by: '<S164>/MATLAB System2'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S164>/Out1'

  real_T Out2_Y0;                      // Computed Parameter: Out2_Y0
                                          //  Referenced by: '<S164>/Out2'

  real_T MATLABSystem_linearConvergence;// Expression: .2
                                           //  Referenced by: '<S150>/MATLAB System'

  real_T MATLABSystem_quaternionConverge;// Expression: .1
                                            //  Referenced by: '<S150>/MATLAB System'

  real_T MATLABSystem_TargetThreshold; // Expression: 3
                                          //  Referenced by: '<S150>/MATLAB System'

  real_T linWpts_Y0;                   // Computed Parameter: linWpts_Y0
                                          //  Referenced by: '<S171>/linWpts'

  real_T RotWpts_Y0;                   // Computed Parameter: RotWpts_Y0
                                          //  Referenced by: '<S171>/RotWpts'

  real_T time_Y0;                      // Computed Parameter: time_Y0
                                          //  Referenced by: '<S171>/time'

  real_T Constant1_Value_l;            // Expression: 0
                                          //  Referenced by: '<S171>/Constant1'

  real_T Constant_Value_a;             // Expression: 1
                                          //  Referenced by: '<S183>/Constant'

  real_T Constant_Value_ax;            // Expression: 1
                                          //  Referenced by: '<S184>/Constant'

  real_T y_Y0;                         // Computed Parameter: y_Y0
                                          //  Referenced by: '<S177>/y'

  real_T PolynomialTrajectory1_VelocityB[6];// Expression: zeros( 3, 2 )
                                               //  Referenced by: '<S175>/Polynomial Trajectory1'

  real_T Constant_Value_en;            // Expression: 1
                                          //  Referenced by: '<S175>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S175>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S175>/Discrete-Time Integrator'

  real_T Constant1_Value_m[2];         // Expression: [1,1]
                                          //  Referenced by: '<S150>/Constant1'

  real_T Delay_InitialCondition_f;     // Expression: 1
                                          //  Referenced by: '<S174>/Delay'

  real_T Constant_Value_ct;            // Expression: 0
                                          //  Referenced by: '<S150>/Constant'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S174>/Constant6'

  real_T Constant_Value_cy[13];       // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
                                         //  Referenced by: '<S146>/Constant'

  real_T Constant1_Value_p;            // Expression: 10
                                          //  Referenced by: '<S10>/Constant1'

  real_T Delay_InitialCondition_a;     // Expression: 0
                                          //  Referenced by: '<S10>/Delay'

  real_T siydevant_Value[3];           // Expression: [0,pi,pi/2]
                                          //  Referenced by: '<S10>/si y devant'

  real_T u2_Gain_k;                    // Expression: 0.5
                                          //  Referenced by: '<S120>/1//2'

  real_T Gain_Gain_a;                  // Expression: 2
                                          //  Referenced by: '<S133>/Gain'

  real_T Gain1_Gain_c;                 // Expression: 2
                                          //  Referenced by: '<S133>/Gain1'

  real_T Constant_Value_n5;            // Expression: 0.5
                                          //  Referenced by: '<S133>/Constant'

  real_T Gain2_Gain_l;                 // Expression: 2
                                          //  Referenced by: '<S133>/Gain2'

  real_T Gain_Gain_i5;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain'

  real_T Constant_Value_ja;            // Expression: 0.5
                                          //  Referenced by: '<S132>/Constant'

  real_T Gain2_Gain_b;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain2'

  real_T Gain1_Gain_m;                 // Expression: 2
                                          //  Referenced by: '<S132>/Gain1'

  real_T Constant_Value_pns;           // Expression: 0.5
                                          //  Referenced by: '<S131>/Constant'

  real_T Gain2_Gain_bx;                // Expression: 2
                                          //  Referenced by: '<S131>/Gain2'

  real_T Gain_Gain_b;                  // Expression: 2
                                          //  Referenced by: '<S131>/Gain'

  real_T Gain1_Gain_p;                 // Expression: 2
                                          //  Referenced by: '<S131>/Gain1'

  real_T Gain_Gain_g;                  // Expression: 1
                                          //  Referenced by: '<S10>/Gain'

  real_T Constant_Value_er;            // Expression: 0.5
                                          //  Referenced by: '<S125>/Constant'

  real_T Gain2_Gain_a;                 // Expression: 2
                                          //  Referenced by: '<S125>/Gain2'

  real_T Gain_Gain_cg;                 // Expression: 2
                                          //  Referenced by: '<S125>/Gain'

  real_T Gain1_Gain_g;                 // Expression: 2
                                          //  Referenced by: '<S125>/Gain1'

  real_T Gain_Gain_ca;                 // Expression: 2
                                          //  Referenced by: '<S126>/Gain'

  real_T Constant_Value_or;            // Expression: 0.5
                                          //  Referenced by: '<S126>/Constant'

  real_T Gain2_Gain_f;                 // Expression: 2
                                          //  Referenced by: '<S126>/Gain2'

  real_T Gain1_Gain_c1;                // Expression: 2
                                          //  Referenced by: '<S126>/Gain1'

  real_T Gain_Gain_n;                  // Expression: 2
                                          //  Referenced by: '<S127>/Gain'

  real_T Gain1_Gain_d;                 // Expression: 2
                                          //  Referenced by: '<S127>/Gain1'

  real_T Constant_Value_ao;            // Expression: 0.5
                                          //  Referenced by: '<S127>/Constant'

  real_T Gain2_Gain_g;                 // Expression: 2
                                          //  Referenced by: '<S127>/Gain2'

  real_T DiscreteTimeIntegrator_gainva_a;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_a
                             //  Referenced by: '<S10>/Discrete-Time Integrator'

  real_T Gain_Gain_bc;                 // Expression: 180/pi
                                          //  Referenced by: '<S137>/Gain'

  real_T Gain1_Gain_pq;                // Expression: -1
                                          //  Referenced by: '<S10>/Gain1'

  real_T Gain_Gain_n3;                 // Expression: 180/pi
                                          //  Referenced by: '<S84>/Gain'

  real_T Gain_Gain_m;                  // Expression: -1
                                          //  Referenced by: '<S80>/Gain'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S10>/Discrete-Time Integrator1'

  real_T Constant_Value_ji;            // Expression: 0
                                          //  Referenced by: '<S152>/Constant'

  real_T Constant3_Value;              // Expression: x0
                                          //  Referenced by: '<S152>/Constant3'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S156>/Integrator'

  real_T Integrator_UpperSat;          // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S156>/Integrator'

  real_T Integrator_LowerSat;          // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S156>/Integrator'

  real_T Saturation_UpperSat;          // Expression: windupUpperLimit
                                          //  Referenced by: '<S156>/Saturation'

  real_T Saturation_LowerSat;          // Expression: windupLowerLimit
                                          //  Referenced by: '<S156>/Saturation'

  real_T Gain3_Gain;                   // Expression: (2*pi*fn).^2
                                          //  Referenced by: '<S152>/Gain3'

  real_T Constant1_Value_pt;           // Expression: 0
                                          //  Referenced by: '<S152>/Constant1'

  real_T Constant2_Value;              // Expression: xdot0
                                          //  Referenced by: '<S152>/Constant2'

  real_T Integrator_gainval_a;       // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S157>/Integrator'

  real_T Integrator_UpperSat_p;        // Expression: antiwindupUpperLimit
                                          //  Referenced by: '<S157>/Integrator'

  real_T Integrator_LowerSat_j;        // Expression: antiwindupLowerLimit
                                          //  Referenced by: '<S157>/Integrator'

  real_T Saturation_UpperSat_n;        // Expression: windupUpperLimit
                                          //  Referenced by: '<S157>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: windupLowerLimit
                                          //  Referenced by: '<S157>/Saturation'

  real_T Gain_Gain_ib;                 // Expression: -1
                                          //  Referenced by: '<S147>/Gain'

  real_T Gain2_Gain_n;                 // Expression: 1
                                          //  Referenced by: '<S83>/Gain2'

  real_T Gain1_Gain_cu;                // Expression: 1
                                          //  Referenced by: '<S83>/Gain1'

  real_T Gain_Gain_ac;                 // Expression: -1
                                          //  Referenced by: '<S83>/Gain'

  real_T Gain4_Gain;                   // Expression: -1
                                          //  Referenced by: '<S83>/Gain4'

  real_T Gain3_Gain_d;                 // Expression: -1
                                          //  Referenced by: '<S83>/Gain3'

  real_T Delay_InitialCondition_h;     // Expression: 0.0
                                          //  Referenced by: '<S5>/Delay'

  real_T FirstOrderHold_IniOut;        // Expression: 0
                                          //  Referenced by: '<S8>/First Order Hold'

  real_T FirstOrderHold_ErrTol;        // Expression: inf
                                          //  Referenced by: '<S8>/First Order Hold'

  real_T FirstOrderHold1_IniOut;       // Expression: 0
                                          //  Referenced by: '<S5>/First Order Hold1'

  real_T FirstOrderHold1_ErrTol;       // Expression: inf
                                          //  Referenced by: '<S5>/First Order Hold1'

  real_T FirstOrderHold_IniOut_c;      // Expression: 0
                                          //  Referenced by: '<S5>/First Order Hold'

  real_T FirstOrderHold_ErrTol_p;      // Expression: inf
                                          //  Referenced by: '<S5>/First Order Hold'

  boolean_T Delay_InitialCondition_n;
                                 // Computed Parameter: Delay_InitialCondition_n
                                    //  Referenced by: '<S148>/Delay'

  boolean_T Delay1_InitialCondition;
                                  // Computed Parameter: Delay1_InitialCondition
                                     //  Referenced by: '<S150>/Delay1'

  boolean_T Merge1_InitialOutput;    // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<S11>/Merge1'

  P_Subsystem1_proc_control_nod_T Subsystem1_e;// '<S150>/Subsystem1'
  P_Subsystem1_proc_control_nod_T Subsystem1;// '<S148>/Subsystem1'
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
    uint32_T clockTick5;
    uint16_T clockTick6;
    boolean_T firstInitCondFlag;
    struct {
      uint16_T TID[7];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[7];
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
//  Block '<S91>/Data Type Duplicate' : Unused code path elimination
//  Block '<S95>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S96>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S97>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S98>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S99>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S100>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S101>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S102>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S103>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S104>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S105>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S106>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S107>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S108>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S109>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S110>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S111>/Vector Dimension Check' : Unused code path elimination
//  Block '<S112>/Vector Dimension Check' : Unused code path elimination
//  Block '<S113>/Vector Dimension Check' : Unused code path elimination
//  Block '<S114>/Vector Dimension Check' : Unused code path elimination
//  Block '<S10>/ ' : Unused code path elimination
//  Block '<S10>/Discrete-Time Integrator2' : Unused code path elimination
//  Block '<S10>/Multiport Switch' : Unused code path elimination
//  Block '<S177>/Constant' : Unused code path elimination
//  Block '<S177>/Product' : Unused code path elimination
//  Block '<S179>/1//2' : Unused code path elimination
//  Block '<S179>/q0' : Unused code path elimination
//  Block '<S179>/q1' : Unused code path elimination
//  Block '<S179>/q2' : Unused code path elimination
//  Block '<S179>/q3' : Unused code path elimination
//  Block '<S179>/sincos' : Unused code path elimination
//  Block '<S188>/Data Type Duplicate' : Unused code path elimination
//  Block '<S194>/FixPt Data Type Duplicate2' : Unused code path elimination
//  Block '<S19>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S3>/MinMax' : Eliminated since input is scalar
//  Block '<S3>/MinMax1' : Eliminated since input is scalar
//  Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S94>/Reshape1' : Reshape block reduction
//  Block '<S94>/mo or x Conversion' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion1' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion10' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion11' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion12' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion13' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion14' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion15' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion16' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion17' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion18' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion19' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion2' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion3' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion4' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion5' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion6' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion7' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion8' : Eliminate redundant data type conversion
//  Block '<S94>/mo or x Conversion9' : Eliminate redundant data type conversion


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
//  '<S8>'   : 'proc_control_node/Send To Telemetry '
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
//  '<S31>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1'
//  '<S32>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Rotation Angles to Quaternions'
//  '<S33>'  : 'proc_control_node/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Conjugate'
//  '<S34>'  : 'proc_control_node/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Norm'
//  '<S35>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize'
//  '<S36>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V1'
//  '<S37>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V2'
//  '<S38>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/V3'
//  '<S39>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S40>'  : 'proc_control_node/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S41>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse'
//  '<S42>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse/Quaternion Conjugate'
//  '<S43>'  : 'proc_control_node/Modèle Physique/Sensor model/IMU Inverse/Quaternion Norm'
//  '<S44>'  : 'proc_control_node/ROS Input/MATLAB Function'
//  '<S45>'  : 'proc_control_node/ROS Input/Quaternion Normalise'
//  '<S46>'  : 'proc_control_node/ROS Input/Subscribe'
//  '<S47>'  : 'proc_control_node/ROS Input/Subscribe1'
//  '<S48>'  : 'proc_control_node/ROS Input/Subscribe/Enabled Subsystem'
//  '<S49>'  : 'proc_control_node/ROS Input/Subscribe1/Enabled Subsystem'
//  '<S50>'  : 'proc_control_node/ROS Output/Send DVL msg'
//  '<S51>'  : 'proc_control_node/ROS Output/Send IMU msg'
//  '<S52>'  : 'proc_control_node/ROS Output/Send to Unity'
//  '<S53>'  : 'proc_control_node/ROS Output/Send DVL msg/   '
//  '<S54>'  : 'proc_control_node/ROS Output/Send DVL msg/MATLAB Function'
//  '<S55>'  : 'proc_control_node/ROS Output/Send DVL msg/Publish'
//  '<S56>'  : 'proc_control_node/ROS Output/Send IMU msg/   '
//  '<S57>'  : 'proc_control_node/ROS Output/Send IMU msg/MATLAB Function'
//  '<S58>'  : 'proc_control_node/ROS Output/Send IMU msg/Publish'
//  '<S59>'  : 'proc_control_node/ROS Output/Send to Unity/   '
//  '<S60>'  : 'proc_control_node/ROS Output/Send to Unity/MATLAB Function'
//  '<S61>'  : 'proc_control_node/ROS Output/Send to Unity/Publish'
//  '<S62>'  : 'proc_control_node/Send Data to ROS/Blank Message'
//  '<S63>'  : 'proc_control_node/Send Data to ROS/Blank Message1'
//  '<S64>'  : 'proc_control_node/Send Data to ROS/Blank Message2'
//  '<S65>'  : 'proc_control_node/Send Data to ROS/Blank Message3'
//  '<S66>'  : 'proc_control_node/Send Data to ROS/Blank Message4'
//  '<S67>'  : 'proc_control_node/Send Data to ROS/MATLAB Function1'
//  '<S68>'  : 'proc_control_node/Send Data to ROS/MATLAB Function2'
//  '<S69>'  : 'proc_control_node/Send Data to ROS/MATLAB Function3'
//  '<S70>'  : 'proc_control_node/Send Data to ROS/Publish'
//  '<S71>'  : 'proc_control_node/Send Data to ROS/Publish1'
//  '<S72>'  : 'proc_control_node/Send Data to ROS/Publish2'
//  '<S73>'  : 'proc_control_node/Send Data to ROS/Publish3'
//  '<S74>'  : 'proc_control_node/Send Data to ROS/Publish4'
//  '<S75>'  : 'proc_control_node/Send Sensor ON/Blank Message'
//  '<S76>'  : 'proc_control_node/Send Sensor ON/Publish'
//  '<S77>'  : 'proc_control_node/Send Target Reached /Blank Message'
//  '<S78>'  : 'proc_control_node/Send Target Reached /Publish'
//  '<S79>'  : 'proc_control_node/Send To Telemetry /Blank Message'
//  '<S80>'  : 'proc_control_node/Send To Telemetry /Conversion d'unité'
//  '<S81>'  : 'proc_control_node/Send To Telemetry /MATLAB Function1'
//  '<S82>'  : 'proc_control_node/Send To Telemetry /Publish'
//  '<S83>'  : 'proc_control_node/Send To Telemetry /Send to Gazebo'
//  '<S84>'  : 'proc_control_node/Send To Telemetry /Conversion d'unité/Radians to Degrees'
//  '<S85>'  : 'proc_control_node/Send To Telemetry /Send to Gazebo/   '
//  '<S86>'  : 'proc_control_node/Send To Telemetry /Send to Gazebo/MATLAB Function'
//  '<S87>'  : 'proc_control_node/Send To Telemetry /Send to Gazebo/Publish'
//  '<S88>'  : 'proc_control_node/Subsystem Controller/IDLE'
//  '<S89>'  : 'proc_control_node/Subsystem Controller/JoyStick OpenLoop'
//  '<S90>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC'
//  '<S91>'  : 'proc_control_node/Subsystem Controller/JoyStick OpenLoop/Discrete Derivative'
//  '<S92>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux'
//  '<S93>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller'
//  '<S94>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC'
//  '<S95>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check'
//  '<S96>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S97>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check10'
//  '<S98>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check11'
//  '<S99>'  : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check12'
//  '<S100>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check13'
//  '<S101>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check14'
//  '<S102>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check15'
//  '<S103>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check16'
//  '<S104>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S105>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S106>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S107>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S108>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S109>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S110>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check9'
//  '<S111>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S112>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S113>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S114>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S115>' : 'proc_control_node/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/NLMPC'
//  '<S116>' : 'proc_control_node/Subsystem ProcNav/MATLAB Function1'
//  '<S117>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse'
//  '<S118>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation'
//  '<S119>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1'
//  '<S120>' : 'proc_control_node/Subsystem ProcNav/Rotation Angles to Quaternions'
//  '<S121>' : 'proc_control_node/Subsystem ProcNav/Subsystem'
//  '<S122>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse/Quaternion Conjugate'
//  '<S123>' : 'proc_control_node/Subsystem ProcNav/Quaternion Inverse/Quaternion Norm'
//  '<S124>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S125>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S126>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S127>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S128>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S129>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S130>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize'
//  '<S131>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V1'
//  '<S132>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V2'
//  '<S133>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/V3'
//  '<S134>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S135>' : 'proc_control_node/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S136>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles'
//  '<S137>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Radians to Degrees'
//  '<S138>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S139>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S140>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S141>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S142>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S143>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S144>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S145>' : 'proc_control_node/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S146>' : 'proc_control_node/Subsystem Trajectory/If Action Subsystem'
//  '<S147>' : 'proc_control_node/Subsystem Trajectory/Subsystem'
//  '<S148>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto'
//  '<S149>' : 'proc_control_node/Subsystem Trajectory/SubsystemManual'
//  '<S150>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory'
//  '<S151>' : 'proc_control_node/Subsystem Trajectory/If Action Subsystem/MATLAB Function1'
//  '<S152>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter'
//  '<S153>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2'
//  '<S154>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)'
//  '<S155>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1'
//  '<S156>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)/Discrete'
//  '<S157>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1/Discrete'
//  '<S158>' : 'proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S159>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/MATLAB Function'
//  '<S160>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe'
//  '<S161>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe1'
//  '<S162>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe2'
//  '<S163>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subsystem1'
//  '<S164>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subsystem2'
//  '<S165>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe/Enabled Subsystem'
//  '<S166>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe1/Enabled Subsystem'
//  '<S167>' : 'proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe2/Enabled Subsystem'
//  '<S168>' : 'proc_control_node/Subsystem Trajectory/SubsystemManual/MATLAB Function1'
//  '<S169>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/MATLAB Function'
//  '<S170>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/MATLAB Function2'
//  '<S171>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Pre-traitement'
//  '<S172>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe'
//  '<S173>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem1'
//  '<S174>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2'
//  '<S175>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Trajectory generator'
//  '<S176>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe/Enabled Subsystem'
//  '<S177>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem'
//  '<S178>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles'
//  '<S179>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Rotation Angles to Quaternions'
//  '<S180>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S181>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S182>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S183>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S184>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S185>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S186>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S187>' : 'proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subsystem2/Enabled Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S188>' : 'proc_control_node/Subsystem1/MinMax Running Resettable'
//  '<S189>' : 'proc_control_node/Subsystem1/Quaternion Normalise'
//  '<S190>' : 'proc_control_node/Subsystem1/Subscribe'
//  '<S191>' : 'proc_control_node/Subsystem1/Subscribe1'
//  '<S192>' : 'proc_control_node/Subsystem1/Subscribe2'
//  '<S193>' : 'proc_control_node/Subsystem1/Subscribe3'
//  '<S194>' : 'proc_control_node/Subsystem1/MinMax Running Resettable/Subsystem'
//  '<S195>' : 'proc_control_node/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S196>' : 'proc_control_node/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S197>' : 'proc_control_node/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S198>' : 'proc_control_node/Subsystem1/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_proc_control_node_h_

//
// File trailer for generated code.
//
// [EOF]
//
