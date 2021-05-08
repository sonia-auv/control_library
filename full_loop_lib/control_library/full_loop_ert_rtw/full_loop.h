//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop.h
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
#ifndef RTW_HEADER_full_loop_h_
#define RTW_HEADER_full_loop_h_
#include <cfloat>
#include <cmath>
#include <cstring>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "HostLib_Audio.h"
#include "full_loop_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// External data declarations for dependent source files
extern const SL_Bus_full_loop_sonia_common_BodyVelocityDVL
  full_loop_rtZSL_Bus_full_loop_sonia_common_BodyVelocityDVL;
                        // SL_Bus_full_loop_sonia_common_BodyVelocityDVL ground
extern const SL_Bus_full_loop_sensor_msgs_Imu
  full_loop_rtZSL_Bus_full_loop_sensor_msgs_Imu;
                                     // SL_Bus_full_loop_sensor_msgs_Imu ground
extern const SL_Bus_full_loop_gazebo_msgs_ModelState
  full_loop_rtZSL_Bus_full_loop_gazebo_msgs_ModelState;
                              // SL_Bus_full_loop_gazebo_msgs_ModelState ground
extern const SL_Bus_full_loop_std_msgs_UInt16MultiArray
  full_loop_rtZSL_Bus_full_loop_std_msgs_UInt16MultiArray;
                           // SL_Bus_full_loop_std_msgs_UInt16MultiArray ground

// Class declaration for model full_loop
class full_loopModelClass {
  // public data and function members
 public:
  // Block signals (default storage)
  typedef struct {
    s_3RW6EhlAOINzvAvYfuaanB_full_T QRManager;
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T WorkingSet;
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T b_WorkingSet;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T TrialState;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T q;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T b_TrialState;
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T b_solution;
    s_a5SYZcWNC5KFUTosoMMbl_full__T CholManager;
    real_T b_data[576081];
    real_T b_data_m[576081];
    real_T b_data_c[576081];
    real_T b_data_k[576081];
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T memspace;
    real_T workspace_data[308154];
    real_T c_data[308154];
    real_T f_data[94192];
    real_T k_data[94192];
    real_T b_this[78013];
    cell_wrap_15_full_loop_T reshapes[3];
    real_T l_data[21112];
    real_T A_data[10880];
    creal_T z_data[5251];
    creal_T z_data_c[5251];
    creal_T tmp_data[5250];
    creal_T b_y1_data[5250];
    creal_T tmp_data_b[5250];
    creal_T dz_data[5250];
    creal_T d1_data[5250];
    creal_T Zout_data[5249];
    creal_T tmp_data_p[5249];
    creal_T Zout_data_c[5249];
    creal_T zorig_data[5249];
    creal_T z_data_f[5249];
    creal_T d2_data[5249];
    creal_T tmp_data_g[5248];
    creal_T tmp_data_g1[5248];
    creal_T znew_data[5248];
    creal_T tmp_data_m[5248];
    creal_T d1_data_n[5248];
    creal_T d2_data_p[5247];
    real_T varargout_3_data[7176];
    real_T Jc_data[7176];
    real_T Jc_data_l[7176];
    real_T varargout_3_data_j[7176];
    real_T Jx[5408];
    real_T Jx_data[5408];
    real_T varargin_1_data[5408];
    real_T tmp_data_d[5250];
    real_T tmp_data_gu[5250];
    real_T l_data_l[5250];
    real_T l_data_d[5250];
    real_T l1_data[5250];
    real_T l1_data_d[5250];
    real_T tmp_data_l[5249];
    real_T a_data[5249];
    real_T tmp_data_o[5249];
    real_T r_data[5249];
    real_T s_data[5249];
    real_T alpha_data[5249];
    real_T l_data_b[5249];
    real_T alpha_data_n[5249];
    real_T tmp_data_bs[5249];
    real_T u_data[5249];
    real_T v_data[5249];
    real_T b_data_l[5248];
    real_T Lbd_data[5248];
    real_T l_data_h[5248];
    real_T alpha_data_b[5248];
    real_T beta_data[5248];
    real_T l1_data_da[5248];
    real_T alpha_data_e[5247];
    real_T l1_data_b[5247];
    creal_T z_data_j[2563];
    creal_T z_data_fd[2563];
    creal_T dz_data_a[2562];
    creal_T d1_data_j[2562];
    creal_T Zout[2561];
    creal_T tmp_data_j[2561];
    creal_T Zout_data_o[2561];
    creal_T b_Zout[2561];
    creal_T zorig_data_n[2561];
    creal_T d2_data_i[2561];
    creal_T znew_data_o[2560];
    creal_T d2_data_n[2559];
    creal_T zcurrent_data[2559];
    real_T unusedExpr[4761];
    real_T Au[4096];
    real_T Auf_data[4096];
    real_T varargout_4[3588];
    real_T Jceq[3588];
    real_T varargout_4_m[3588];
    real_T tmp_data_c[3328];
    creal_T At_data[1600];
    creal_T b_At_data[1600];
    creal_T c_A_data[1600];
    creal_T b_A_data[1600];
    creal_T y_data[1600];
    real_T Jx_m[2704];
    real_T l_data_m[2562];
    real_T l_data_j[2562];
    real_T l1_data_h[2562];
    real_T l1_data_c[2562];
    real_T u[2561];
    real_T v[2561];
    real_T r[2561];
    real_T s[2561];
    real_T alpha_data_c[2561];
    real_T l_data_p[2561];
    real_T alpha_data_p[2561];
    real_T l_data_a[2560];
    real_T alpha_data_ev[2560];
    real_T l1_data_a[2560];
    real_T alpha_data_a[2559];
    real_T beta_data_i[2559];
    real_T l1_data_l[2559];
    real_T y_data_o[2048];
    real_T y_data_o2[2048];
    s_CWBQhEwNbz3J2I47jPePeB_full_T FiniteDifferences;
    real_T tmp_data_i[1681];
    real_T Jmv[1664];
    real_T tmp_data_f[1600];
    real_T b_A_data_i[1600];
    real_T tmp_data_ff[1600];
    real_T tmp_data_gx[1600];
    real_T A_data_c[1600];
    real_T A_data_o[1600];
    real_T c_a_data[1600];
    real_T c_a_data_l[1600];
    real_T c_h_data[1600];
    real_T b_h_data[1600];
    real_T c_x_data[1600];
    real_T c_x_data_m[1600];
    real_T e_A_data[1600];
    real_T d_C_data[1600];
    real_T b_C_data[1600];
    real_T b_C_data_m[1600];
    s_siHoaqeHIV5TpidUajpsGD_full_T FcnEvaluator;
    waypointTrajectory_full_loop_T trajectory;
    real_T result_data[1092];
    real_T result_data_c[1092];
    real_T x_data[1066];
    real_T x_data_f[1066];
    real_T varargin_2_data[1025];
    real_T Jmv_p[832];
    s_BtE36YuCWnavoi0lGdvGZF_full_T QPObjective;
    int32_T counts_data[1600];
    creal_T At[400];
    creal_T b_At[400];
    creal_T b_A[400];
    real_T y_data_e[759];
    real_T c_data_o[759];
    real_T work_data[759];
    real_T work_data_h[759];
    real_T vn1_data[759];
    real_T vn2_data[759];
    real_T work_data_l[759];
    real_T y_data_h[759];
    real_T e_data[759];
    real_T g_data[759];
    real_T c_data_m[759];
    real_T b_data_mc[759];
    real_T h_data[759];
    real_T i_data[759];
    real_T y_data_h3[759];
    real_T e_data_c[759];
    real_T y_data_k[759];
    real_T d_data[759];
    int32_T ac_data[1281];
    s_A0rUWcsbMx3S06V1NlippE_full_T runtimedata;
    s_A0rUWcsbMx3S06V1NlippE_full_T expl_temp;
    s_A0rUWcsbMx3S06V1NlippE_full_T expl_temp_p;
    real_T x[520];
    real_T x_p[520];
    real_T x_p4[520];
    real_T x_a[520];
    real_T dv[500];
    real_T dv1[500];
    real_T c_data_j[406];
    real_T g_data_e[406];
    real_T b_data_o[406];
    real_T d_data_b[406];
    real_T c_data_a[406];
    real_T d_data_g[406];
    real_T dv2[400];
    real_T T[400];
    real_T A[400];
    real_T A_e[400];
    real_T b_a[400];
    real_T b_h[400];
    int32_T b_data_f[759];
    int32_T c_data_h[759];
    int32_T d_data_e[759];
    int32_T b_data_ch[759];
    int32_T c_data_ax[759];
    int32_T d_data_d[759];
    int32_T b_data_a[759];
    int32_T c_data_p[759];
    SL_Bus_full_loop_std_msgs_UInt16MultiArray msg;// '<S4>/MATLAB Function1'
    real_T y_data_m[236];
    real_T d_data_o[232];
    real_T h_data_n[232];
    real_T c_data_l[232];
    real_T zy_data[210];
    real_T z_data_p[210];
    real_T c_data_pt[210];
    boolean_T filled_data[1600];
    sscAEMcz7TPKHyH2uh3imDC_full__T info;
    real_T Ix[169];
    real_T Ak[169];
    real_T Ak1[169];
    real_T a[169];
    real_T Ck[169];
    real_T List[168];
    real_T u_data_f[168];
    real_T v_data_i[168];
    real_T B_data[128];
    real_T b_Bu[128];
    h_cell_wrap_full_loop_T reshapes_o[3];
    h_cell_wrap_full_loop_T reshapes_k[3];
    h_cell_wrap_full_loop_T reshapes_i[3];
    f_cell_wrap_full_loop_T tunableEnvironment;
    real_T waypoints_data[126];
    real_T Jtri_data[126];
    real_T b_varargout_2_data[126];
    real_T a_data_o[126];
    real_T Jtri_data_m[123];
    real_T b_varargout_2_data_c[123];
    real_T Jtri_data_f[123];
    real_T b_varargout_2_data_h[123];
    real_T Jtri_data_m4[120];
    real_T b_varargout_2_data_a[120];
    real_T beta_data_k[118];
    sACkMJ1zT2VJOHR6eMwwEPC_full__T userdata;
    real_T varargout_1_data[104];
    real_T c_data_pc[104];
    real_T Bk[104];
    real_T Bk1[104];
    real_T Bk_b[104];
    real_T varargout_1_data_c[104];
    real_T c_data_n[104];
    real_T b_c[104];
    real_T Je_data[104];
    real_T varargout_1_data_i[104];
    real_T zy[100];
    real_T dv3[100];
    real_T z[100];
    real_T c[100];
    creal_T hip_data[42];
    creal_T hip_data_m[42];
    creal_T hip_data_j[42];
    creal_T hip_data_e[42];
    creal_T hip_data_mv[42];
    creal_T hip_data_m0[42];
    creal_T hip_data_jg[42];
    creal_T hip_data_f[42];
    creal_T x_data_a[42];
    creal_T hip_data_g[41];
    creal_T z_data_n[41];
    creal_T f_data_d[41];
    creal_T df_da_data[41];
    creal_T tmp_data_n[41];
    creal_T b_data_cg[41];
    creal_T e_data_f[41];
    creal_T a1_data[41];
    creal_T a2_data[41];
    creal_T fa_data[41];
    creal_T s_data_p[41];
    creal_T r_data_p[41];
    creal_T da2_data[41];
    creal_T x_data_n[41];
    creal_T tmp_data_k[41];
    creal_T a1_data_n[41];
    creal_T tmp_data_oy[41];
    creal_T tmp_data_gg[41];
    creal_T hip_data_c[41];
    creal_T hip_data_cj[41];
    creal_T nik_data[41];
    creal_T e_data_m[41];
    creal_T A_data_j[41];
    creal_T m2C_data[41];
    creal_T dm2C_data[41];
    creal_T t_data[41];
    creal_T dt_data[41];
    creal_T dp_data[41];
    creal_T hip_data_k[41];
    creal_T p_data[41];
    creal_T q_data[41];
    creal_T x_data_m[41];
    creal_T q_data_p[41];
    creal_T r_data_d[41];
    creal_T tmp_data_g4[40];
    creal_T beta1_data[40];
    real_T hpp_coefs[80];
    real_T hspp_coefs[80];
    real_T happ_coefs[80];
    real_T vpp_coefs[80];
    real_T vspp_coefs[80];
    real_T vapp_coefs[80];
    real_T v_c[80];
    real_T x_tmp[80];
    real_T m[80];
    real_T dv4[80];
    real_T dv5[80];
    real_T z0[69];
    real_T zLB[69];
    real_T zUB[69];
    real_T TrialState_c[69];
    real_T varargout_2[69];
    real_T waypoints_data_i[66];
    real_T waypoints_data_d[66];
    real_T X[65];
    real_T X_g[65];
    real_T X_l[65];
    real_T X_f[65];
    real_T X_d[65];
    real_T As[64];
    real_T w[63];
    real_T wprev[63];
    d_cell_wrap_full_loop_T tunableEnvironment_j;
    real_T e[60];
    real_T Jtri[60];
    real_T b_varargout_2[60];
    real_T rv[60];
    real_T b_z1[60];
    real_T beta[58];
    real_T x_i[57];
    real_T A_h[57];
    real_T A_n[57];
    SL_Bus_full_loop_sensor_msgs_Imu msg_o;// '<S38>/MATLAB Function'
    real_T unusedU0[52];
    real_T e_n[52];
    real_T j_l[52];
    real_T d_ce[52];
    real_T varargout_2_n[52];
    real_T X0[52];
    real_T dv6[52];
    real_T dv7[52];
    real_T dv8[52];
    real_T dv9[52];
    real_T varargout_2_p[52];
    real_T gfX[52];
    real_T b[52];
    real_T z_d[52];
    real_T gfX_o[52];
    real_T varargout_2_j[52];
    real_T X_c[52];
    real_T runtimedata_h[52];
    cell_wrap_11_full_loop_T d;
    cell_wrap_11_full_loop_T e_o;
    cell_wrap_11_full_loop_T h;
    cell_wrap_11_full_loop_T i;
    cell_wrap_11_full_loop_T j;
    cell_wrap_11_full_loop_T k;
    cell_wrap_11_full_loop_T d_c;
    cell_wrap_11_full_loop_T e_b;
    cell_wrap_11_full_loop_T h_e;
    cell_wrap_11_full_loop_T i_d;
    cell_wrap_11_full_loop_T j_i;
    cell_wrap_11_full_loop_T k_g;
    boolean_T filled[400];
    SL_Bus_full_loop_gazebo_msgs_ModelState msg_l;// '<S39>/MATLAB Function'
    real_T course_data[45];
    real_T course_data_d[44];
    real_T c_data_c[43];
    real_T courselsq_data[43];
    real_T tmp_data_pw[43];
    real_T range_data[42];
    real_T waypoints_data_p[42];
    real_T waypoints_data_a[42];
    real_T dx_data[42];
    real_T tmp_data_ow[42];
    real_T course_data_j[42];
    real_T course_data_p[42];
    real_T tmp_data_ob[42];
    real_T tmp_data_lm[42];
    real_T tmp_data_kv[42];
    real_T tmp_data_jk[42];
    real_T v_data_f[42];
    real_T dx_data_c[42];
    real_T xnew_data[42];
    real_T b_r_data[42];
    real_T epsx_data[42];
    real_T epsr_data[42];
    real_T xnew_data_f[42];
    real_T a_data_n[42];
    real_T b_data_i[42];
    real_T c_data_l4[42];
    real_T d_data_i[42];
    real_T e_data_k[42];
    real_T f_data_f[42];
    real_T c_data_al[42];
    real_T c_data_d[42];
    real_T alpha_data_ey[42];
    real_T dx_data_b[42];
    real_T tmp_data_a[42];
    real_T course_data_i[42];
    real_T course_data_f[42];
    real_T y_data_j[42];
    real_T tmp_data_oo[42];
    real_T c_z1_data[42];
    real_T dx_data_f[42];
    real_T xnew_data_o[42];
    real_T epsx_data_l[42];
    real_T epsr_data_l[42];
    real_T tmp_data_gf[42];
    real_T oldq_data[42];
    real_T b_data_d[42];
    real_T q_data_d[42];
    real_T lower_data[42];
    real_T center_data[42];
    real_T upper_data[42];
    real_T tmp_data_jo[42];
    real_T center_data_f[42];
    real_T u_data_j[42];
    real_T z_data_h[42];
    real_T b_data_cf[42];
    real_T course_data_n[42];
    real_T course_data_k[42];
    real_T tmp_data_av[42];
    real_T lower_data_f[42];
    real_T center_data_j[42];
    real_T upper_data_k[42];
    real_T z_data_b[42];
    real_T alpha_data_h[42];
    real_T z_data_e[42];
    real_T c_data_hn[42];
    creal_T hip[21];
    creal_T hip_e[21];
    creal_T x_k[21];
    real_T dv10[41];
    real_T y_data_jw[41];
    real_T tmp_data_ooe[41];
    real_T xnew_data_c[41];
    real_T epsx_data_h[41];
    real_T epsr_data_i[41];
    real_T unusedU3_data[41];
    real_T k0_data[41];
    real_T k1_data[41];
    real_T dk0_dc0_data[41];
    real_T dk0_dc1_data[41];
    real_T dk1_dc0_data[41];
    real_T dk1_dc1_data[41];
    real_T course_data_pl[41];
    real_T phi_data[41];
    real_T phi0_data[41];
    real_T phi1_data[41];
    real_T da_dphi0_data[41];
    real_T da_dphi1_data[41];
    real_T d_data_f[41];
    real_T a_data_e[41];
    real_T c_data_nh[41];
    real_T ratio_data[41];
    real_T tmp_data_h[41];
    real_T x_data_h[41];
    real_T xabs_data[41];
    real_T ismall_data[41];
    real_T x4_data[41];
    real_T ibig_data[41];
    real_T unusedU4_data[41];
    real_T k0_data_f[41];
    real_T k1_data_i[41];
    real_T dk0_dc0_data_f[41];
    real_T dk0_dc1_data_c[41];
    real_T dk1_dc0_data_n[41];
    real_T dk1_dc1_data_h[41];
    real_T x_data_k[41];
    real_T y_data_hz[41];
    real_T y_data_b[41];
    real_T y_data_os[41];
    real_T y_data_n[41];
    real_T y_data_mi[41];
    real_T y_data_ku[41];
    real_T b_gamma_data[41];
    real_T v_data_j[41];
    real_T xnew_data_h[41];
    real_T b_r_data_f[41];
    real_T epsx_data_d[41];
    real_T epsr_data_li[41];
    real_T b_varargout_1_data[41];
    real_T unusedU2_data[41];
    real_T k0_data_k[41];
    real_T k1_data_ic[41];
    real_T dk0_dc0_data_h[41];
    real_T dk0_dc1_data_m[41];
    real_T dk1_dc0_data_g[41];
    real_T dk1_dc1_data_l[41];
    real_T course_data_m[41];
    real_T k_data_n[41];
    real_T tmp_data_gv[41];
    real_T v_data_d[41];
    real_T b_r_data_m[41];
    real_T b_varargout_1_data_f[41];
    real_T y_data_g[41];
    real_T y_data_jc[41];
    real_T y_data_c[41];
    real_T y_data_eg[41];
    real_T y_data_mx[41];
    real_T y_data_of[41];
    real_T unusedU1_data[41];
    real_T k0_data_a[41];
    real_T k1_data_j[41];
    real_T dk0_dc0_data_g[41];
    real_T dk0_dc1_data_j[41];
    real_T dk1_dc0_data_e[41];
    real_T dk1_dc1_data_j[41];
    real_T course_data_jb[41];
    real_T u_data_g[41];
    real_T v_data_o[41];
    real_T dadr_data[41];
    real_T y_data_hm[41];
    real_T y_data_c2[41];
    real_T y_data_a[41];
    real_T z_data_l[41];
    real_T b_gamma_data_j[41];
    real_T y_data_i[41];
    real_T y_data_mid[41];
    real_T y_data_f[41];
    real_T U[40];
    real_T v_data_j0[40];
    real_T b_r_data_o[40];
    real_T b_varargout_1_data_fr[40];
    real_T delta_data[40];
    real_T alpha_data_m[40];
    real_T beta_data_a[40];
    real_T U_h[40];
    real_T U_o[40];
    real_T U_hn[40];
    real_T Umv[40];
    real_T U_j[40];
    real_T delta_data_g[40];
    real_T tmp_data_jz[40];
    real_T b_y_data[40];
    real_T work_data_lg[40];
    creal_T x_o[20];
    creal_T beta1[20];
    creal_T z_i[20];
    creal_T df_da[20];
    creal_T b_x[20];
    creal_T z_e[20];
    creal_T f[20];
    real_T dv11[39];
    real_T M[36];
    real_T C[36];
    real_T D[36];
    real_T C_k[36];
    int32_T indexLB[69];
    int32_T indexUB[69];
    real_T unusedU1[32];
    real_T MV0[32];
    real_T MVRateWeights0[32];
    real_T MVMin0[32];
    real_T MVMax0[32];
    real_T dv12[32];
    real_T dv13[32];
    real_T dv14[32];
    real_T gfU[32];
    real_T c_p[32];
    real_T a_n[32];
    real_T gfU_j[32];
    real_T Umv_o[32];
    cell_wrap_13_full_loop_T f_d;
    cell_wrap_13_full_loop_T g;
    cell_wrap_13_full_loop_T l;
    cell_wrap_13_full_loop_T m_n;
    cell_wrap_13_full_loop_T n;
    cell_wrap_13_full_loop_T o;
    cell_wrap_13_full_loop_T p;
    cell_wrap_13_full_loop_T f_j;
    cell_wrap_13_full_loop_T g_a;
    cell_wrap_13_full_loop_T l_h;
    cell_wrap_13_full_loop_T m_i;
    cell_wrap_13_full_loop_T n_d;
    cell_wrap_13_full_loop_T o_b;
    cell_wrap_13_full_loop_T p_h;
    real_T dv15[24];
    real_T y_data_bj[24];
    SL_Bus_full_loop_sonia_common_BodyVelocityDVL msg_g;// '<S37>/MATLAB Function' 
    real_T e_data_j[23];
    real_T e_data_e[23];
    real_T range_data_i[22];
    real_T range_data_n[22];
    int32_T b_data_og[42];
    int32_T v_data_ot[42];
    int32_T g_data_g[42];
    int32_T y_data_ge[42];
    int32_T x_data_g[42];
    int32_T x_data_gr[42];
    int32_T y_data_ca[42];
    int32_T x_data_kt[42];
    int32_T x_data_d[42];
    real_T tpts[21];
    real_T x_ie[21];
    real_T assign_temp_a[21];
    real_T assign_temp_b[21];
    real_T assign_temp_c[21];
    real_T q_a[21];
    real_T q_b[21];
    real_T q_c[21];
    real_T q_d[21];
    real_T t[21];
    real_T t_p[21];
    real_T course[21];
    real_T hcd[21];
    real_T hpp_breaks[21];
    real_T hspp_breaks[21];
    real_T happ_breaks[21];
    real_T vpp_breaks[21];
    real_T vspp_breaks[21];
    real_T vapp_breaks[21];
    real_T y_data_mz[21];
    real_T a_e[21];
    real_T b_i[21];
    real_T c_g[21];
    real_T dv16[21];
    real_T dv17[21];
    real_T gndspeed[21];
    real_T rate[21];
    real_T b_x_k[21];
    real_T b_x_p[21];
    real_T slopes[21];
    int32_T g_data_p[41];
    int32_T ilarge_data[41];
    int32_T ismall_data_m[41];
    int32_T izero_data[41];
    int32_T ii_data[41];
    int32_T bd_data[41];
    int32_T dd_data[41];
    int32_T ii_data_k[41];
    int32_T h_data_a[41];
    int32_T rscale_data[40];
    real_T h_f[20];
    real_T dtheta[20];
    real_T k0[20];
    real_T k1[20];
    real_T hl[20];
    real_T x_c[20];
    real_T ibegin_data[20];
    real_T iend_data[20];
    real_T courselsq[20];
    real_T v_j[20];
    real_T dx[20];
    real_T xnew[20];
    real_T b_r[20];
    real_T unusedU0_k[20];
    real_T k0_h[20];
    real_T k1_d[20];
    real_T dk0_dc0[20];
    real_T dk0_dc1[20];
    real_T dk1_dc0[20];
    real_T dk1_dc1[20];
    real_T xnew_j[20];
    real_T lower[20];
    real_T upper[20];
    real_T z_n[20];
    real_T oldq[20];
    real_T q_j[20];
    real_T alpha[20];
    real_T beta_l[20];
    real_T v_p[20];
    real_T work[20];
    real_T phi[20];
    real_T phi0[20];
    real_T phi1[20];
    real_T da_dphi0[20];
    real_T da_dphi1[20];
    real_T u_p[20];
    real_T v_l[20];
    real_T dadr[20];
    real_T d_l[20];
    real_T e_h[20];
    real_T f_c[20];
    real_T alpha_g[20];
    real_T alpha_e[20];
    real_T assign_temp_a_n[20];
    real_T assign_temp_b_f[20];
    real_T assign_temp_c_n[20];
    real_T assign_temp_d[20];
    real_T dv18[20];
    real_T deltaQuat_a[20];
    real_T deltaQuat_b[20];
    real_T deltaQuat_c[20];
    real_T deltaQuat_d[20];
    real_T obj_d_data[20];
    real_T izero_data_e[20];
    real_T qi_c[20];
    real_T qi_d[20];
    real_T mag[20];
    real_T n_b[20];
    real_T phi_a[20];
    real_T phi0_i[20];
    real_T phi1_n[20];
    real_T v_f[20];
    real_T x_i4[20];
    real_T dv19[20];
    real_T x_k3[20];
    real_T d_b[20];
    real_T c_data_da[20];
    real_T x_h[20];
    real_T d_n[20];
    real_T c_data_f[20];
    real_T h_a[20];
    real_T del[20];
    real_T Jtri_m[20];
    real_T z_g[20];
    real_T b_n[20];
    real_T b_ch[20];
    real_T b_gamma[19];
    real_T b_gamma_d[19];
    real_T work_k[19];
    real_T delta[18];
    real_T delta_c[18];
    boolean_T icf[128];
    uint8_T ii_data_m[128];
    real_T J_data[16];
    real_T A_data_jd[16];
    real_T y_m[16];
    real_T dv20[16];
    real_T dv21[16];
    real_T b_I[16];
    real_T b_ie[16];
    real_T c_A_data_b[16];
    real_T b_A_data_o[16];
    real_T b_C_data_g[16];
    real_T a_ed[16];
    real_T c_A_data_i[16];
    real_T c_x_data_e[16];
    real_T c_A[16];
    real_T c_x_data_i[16];
    s6ICcRyulWOFjNCN0ll7VsE_full__T MeritFunction;
    boolean_T icf_p[104];
    int8_T Je[104];
    int8_T b_data_b[104];
    int8_T d_data_p[104];
    int32_T ic[26];
    real_T TmpSignalConversionAtTransp[13];
    real_T Reshape[13];                // '<S60>/Reshape'
    real_T dv22[13];
    real_T ic_n[13];
    real_T dv23[13];
    real_T dv24[13];
    real_T X_ce[13];
    real_T ic_nh[13];
    real_T runtimedata_OutputMin[13];
    real_T ix[13];
    real_T wtYerr[13];
    real_T gfx[13];
    real_T currPose[13];
    cell_wrap_9_full_loop_T b_d;
    cell_wrap_9_full_loop_T b_j;
    int32_T d_data_da[22];
    creal_T b_A_data_a[5];
    creal_T x_data_fd[5];
    creal_T tmp_data_ko[5];
    int32_T ii_data_i[20];
    int32_T ilarge_data_n[20];
    int32_T ismall_data_b[20];
    int32_T izero_data_b[20];
    int32_T ii_data_j[20];
    int32_T ilarge_data_n0[20];
    int32_T ismall_data_f[20];
    int32_T izero_data_eu[20];
    int32_T ii_data_in[20];
    int32_T rscale[20];
    int32_T ii_data_c[20];
    real_T TmpSignalConversionAtMATLAB[9];// '<S113>/Subsystem1'
    real_T A_j[9];
    real_T B[9];
    boolean_T b_i0[69];
    boolean_T c_i[69];
    s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp_l;
    s1TgE9KstXgkd2qJxO1bF4F_full__T expl_temp_a;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_i;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_o;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_b;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_a;
    s1TgE9KstXgkd2qJxO1bF4F_full__T qpoptions_aq;
    real_T twpt[8];
    real_T Saturation[8];              // '<S6>/Saturation'
    real_T List_p[8];
    real_T U_om[8];
    real_T iu[8];
    real_T umvk[8];
    real_T duk[8];
    real_T gfu[8];
    real_T ic_c[8];
    real_T runtimedata_o[8];
    cell_wrap_10_full_loop_T c_l;
    cell_wrap_10_full_loop_T c_o;
    SL_Bus_full_loop_sonia_common_AddPose b_varargout_2_o;
    SL_Bus_full_loop_geometry_msgs_Pose In1_k;// '<S138>/In1'
    SL_Bus_full_loop_geometry_msgs_Pose b_varargout_2_h;
    real_T TmpSignalConversionAtSFun_a[7];// '<S113>/MATLAB Function'
    real_T sd[7];
    real_T cd[7];
    real_T sd_i[7];
    real_T cd_g[7];
    int32_T gfx_tmp[13];
    boolean_T bv[52];
    SL_Bus_full_loop_geometry_msgs_Twist In1_p;// '<S121>/In1'
    SL_Bus_full_loop_geometry_msgs_Twist b_varargout_2_c;
    real_T Gq[6];
    real_T Gain_o[6];                  // '<S115>/Gain'
    real_T rtb_Gain_o_o[6];
    real_T M_g[6];
    real_T C_o[6];
    real_T M_gf[6];
    real_T Sum[6];                     // '<S115>/Sum'
    real_T Integrator[6];              // '<S120>/Integrator'
    real_T C_a[6];
    real_T cn[6];
    real_T sn[6];
    real_T cn_g[6];
    real_T sn_b[6];
    boolean_T tmp_data_kn[42];
    boolean_T xnew_data_ca[42];
    boolean_T tmp_data_ji[42];
    boolean_T xnew_data_a[42];
    boolean_T criteria_data[41];
    boolean_T x_data_dm[41];
    char_T cv[40];
    real_T b_data_cx[5];
    real_T b_d0[5];
    char_T cv1[37];
    char_T cv2[35];
    int32_T gfu_tmp[8];
    char_T cv3[32];
    real_T q_a2[4];
    real_T rq[4];
    real_T b_q[4];
    real_T qRel[4];
    real_T dv25[4];
    real_T tmp_data_bo[4];
    real_T y_g[4];
    real_T dv26[4];
    real_T b_tau_data[4];
    real_T B_data_f[4];
    real_T work_data_c[4];
    real_T vn1_data_p[4];
    real_T vn2_data_a[4];
    real_T work_data_n[4];
    creal_T varargin_1[2];
    char_T cv4[29];
    char_T cv5[27];
    boolean_T icf_h[26];
    char_T cv6[24];
    real_T u2[3];                      // '<S86>/1//2'
    real_T AngularRate[3];
    real_T AngularRate_m[3];
    real_T b_varargout_5[3];
    real_T b_varargout_3[3];
    real_T b_varargout_1[3];
    real_T b_acceleration[3];
    real_T w_m[3];
    real_T w_f[3];
    real_T wi[3];
    real_T wf[3];
    real_T temp1[3];
    real_T b_e[3];
    real_T b_e_b[3];
    real_T b_e_e[3];
    real_T w_n[3];
    real_T v_p4[3];
    real_T b_v[3];
    real_T position[3];
    real_T velocity[3];
    real_T acceleration[3];
    real_T jerk[3];
    real_T s_i[3];
    real_T e_j[3];
    real_T th0[3];
    real_T th1[3];
    real_T th2[3];
    real_T f_data_l[3];
    real_T th1_data[3];
    real_T th3_data[3];
    real_T u_data_c[3];
    real_T w_data[3];
    real_T udot_data[3];
    real_T wd1xu_data[3];
    real_T temp0_data[3];
    real_T wd2_data[3];
    real_T qimag[3];
    real_T f_tmp_data[3];
    real_T tmp_data_gr[3];
    real_T tmp_data_c5[3];
    real_T tmp_data_ly[3];
    real_T tmp_data_e[3];
    real_T tmp_data_dt[3];
    real_T bvec[3];
    real_T bvec2_data[3];
    real_T e_data_my[3];
    real_T wf_data[3];
    real_T e_data_fi[3];
    real_T wf_data_n[3];
    real_T e_data_o[3];
    real_T e_data_en[3];
    real_T v_m[3];
    real_T b_v_c[3];
    int32_T x_g[6];
    int32_T x_tmp_b[6];
    char_T cv7[23];
    int8_T d_data_po[22];
    int8_T iv[20];
    int8_T iv1[20];
    int8_T iv2[20];
    int8_T z_tmp[20];
    int8_T iv3[20];
    int8_T iv4[20];
    int8_T e_tmp[20];
    int8_T c_data_ap[20];
    int8_T d_data_fm[20];
    int8_T e_data_g[20];
    int8_T iv5[20];
    int8_T iv6[20];
    int8_T iv7[20];
    int8_T b_data_k1[20];
    boolean_T k0_p[20];
    boolean_T idx[20];
    boolean_T criteria[20];
    boolean_T criteria_b[20];
    boolean_T x_kw[20];
    int8_T z_tmp_b[19];
    int8_T z_tmp_i[19];
    int8_T e_tmp_n[19];
    char_T cv8[19];
    int8_T b_I_g[16];
    int32_T b_jpvt_data[4];
    int32_T b_jpvt_data_l[4];
    int32_T b_ipiv_data[4];
    uint16_T y_k[8];                   // '<S1>/MATLAB Function'
    uint16_T NtoPWM[8];                // '<S6>/N to PWM'
    real_T waypoints[2];
    real_T waypoints_e[2];
    real_T dx_g[2];
    real_T dy[2];
    real_T dv27[2];
    real_T v_g[2];
    real_T n_dz[2];
    creal_T a2_data_h;
    creal_T fa_data_n;
    creal_T da2_data_m;
    creal_T x_data_gu;
    creal_T tmp_data_jb;
    creal_T tmp_data_f0;
    creal_T drsfa_data;
    creal_T z_data_ng;
    creal_T V;
    creal_T dt_data_g;
    creal_T nik_data_d;
    creal_T e_data_cj;
    creal_T dp_data_m;
    creal_T z_data_d;
    creal_T t_data_n;
    creal_T dt_data_b;
    creal_T t_data_p;
    creal_T dz_data_k;
    creal_T z_data_cl;
    creal_T dz_data_n;
    creal_T dp_data_n;
    creal_T e_data_cd;
    creal_T z_dk;
    creal_T b_x_n;
    creal_T b_x_g;
    creal_T z_l;
    creal_T z_p;
    creal_T f_k;
    creal_T f_l;
    creal_T ph;
    creal_T vh;
    creal_T ah;
    creal_T jh;
    creal_T dc;
    creal_T nc;
    creal_T nikx_data;
    creal_T nhikx_data;
    creal_T hidkxx_data;
    creal_T e_data_b;
    creal_T t_data_c;
    creal_T e_data_fb;
    creal_T z_data_o;
    creal_T x_data_dd;
    creal_T V_data;
    creal_T ctemp;
    creal_T ad11;
    creal_T t1;
    creal_T ascale;
    creal_T t1_l;
    creal_T zright;
    creal_T work_data_d;
    creal_T ph_k;
    creal_T vh_f;
    creal_T ah_p;
    creal_T jh_k;
    creal_T dc1;
    creal_T q_data_k;
    creal_T a_data_i;
    creal_T z_data_ew;
    creal_T z_data_ft;
    creal_T z_data_k;
    creal_T z_data_ne;
    creal_T q_data_i;
    creal_T z_data_i;
    creal_T zright_o;
    creal_T ctemp_d;
    creal_T ad11_i;
    creal_T t1_g;
    creal_T ascale_c;
    creal_T t1_e;
    creal_T zright_a;
    creal_T zright_h;
    creal_T s_e;
    creal_T s_d;
    creal_T b_A_data_g;
    creal_T b_A_e;
    boolean_T bv1[13];
    boolean_T bv2[13];
    boolean_T b_this_n[13];
    int32_T Jx_size[3];
    s7RdrPWkr8UPAUyTdDJkLaG_full__T Flags;
    real_T Output;                     // '<S25>/Output'
    real_T Gain;                       // '<S99>/Gain'
    real_T Gain1;                      // '<S99>/Gain1'
    real_T Gain2;                      // '<S99>/Gain2'
    real_T Gain_h;                     // '<S98>/Gain'
    real_T Gain2_p;                    // '<S98>/Gain2'
    real_T Gain1_n;                    // '<S98>/Gain1'
    real_T Gain2_d;                    // '<S97>/Gain2'
    real_T Gain_d;                     // '<S97>/Gain'
    real_T Gain1_c;                    // '<S97>/Gain1'
    real_T Output_n;                   // '<S24>/Output'
    real_T Sum_a;                      // '<S91>/Sum'
    real_T Sum_g;                      // '<S92>/Sum'
    real_T Sum_e;                      // '<S93>/Sum'
    real_T WorldPosition[3];           // '<S7>/Discrete-Time Integrator'
    real_T MultiportSwitch[6];         // '<S115>/Multiport Switch'
    real_T Merge[52];                  // '<S8>/Merge'
    real_T FromMultimediaFile[2048];   // '<S1>/From Multimedia File'
    real_T PWMtoN[8];                  // '<S12>/ PWM to N'
    real_T XDrift;                     // '<S13>/X Drift'
    real_T YDrift;                     // '<S13>/Y Drift'
    real_T y[4];                       // '<S9>/Quaternion Normalise'
    real_T MATLABSystem2_o1[13000];    // '<S127>/MATLAB System2'
    real_T MATLABSystem2_o2[2];        // '<S127>/MATLAB System2'
    real_T DataTypeConversion[6];      // '<S126>/Data Type Conversion'
    real_T DataTypeConversion1[2];     // '<S126>/Data Type Conversion1'
    real_T DataTypeConversion2;        // '<S126>/Data Type Conversion2'
    real_T Position_dot[3];            // '<S1>/AUV State Equation'
    real_T Quaternion_dot[4];          // '<S1>/AUV State Equation'
    real_T BodyVelocity_dot[3];        // '<S1>/AUV State Equation'
    real_T AngularRates_dot[3];        // '<S1>/AUV State Equation'
    real_T Merge_b;                    // '<S106>/Merge'
    real_T scale;
    real_T absxk;
    real_T t_p2;
    real_T Product1_a5;                // '<S96>/Product1'
    real_T Sum_b;
    real_T Sum_m;
    real_T Sum_c;
    real_T Divide3;
    real_T Divide2;
    real_T Divide1;
    real_T Divide;
    real_T Sum_i;
    real_T Sum_mk;
    real_T Sum_o;
    real_T rtb_TmpSignalConversionAtSFun_i;
    real_T rtb_TmpSignalConversionAtSFun_b;
    real_T rtb_TmpSignalConversionAtSFu_jv;
    real_T BodyVelocity_idx_2;
    real_T BodyVelocity_idx_1;
    real_T BodyVelocity_idx_0;
    real_T rtb_sincos_o1_idx_2;
    real_T rtb_sincos_o1_idx_1;
    real_T rtb_sincos_o1_idx_0;
    real_T y_l_idx_3;
    real_T y_l_idx_2;
    real_T y_l_idx_1;
    real_T y_l_idx_0;
    real_T Quaternion_idx_3;
    real_T Quaternion_idx_2;
    real_T Quaternion_idx_1;
    real_T Quaternion_idx_0;
    real_T Sum_a_tmp;
    real_T Sum_a_tmp_g;
    real_T Sum_a_tmp_n;
    real_T maxTime;
    real_T dist;
    real_T b_q_a;
    real_T b_q_b;
    real_T b_q_c;
    real_T b_q_d;
    real_T b_p;
    real_T ndbl;
    real_T apnd;
    real_T cdiff;
    real_T u0;
    real_T u1;
    real_T freetail_tmp;
    real_T maxiter;
    real_T lambda;
    real_T lambdac;
    real_T iter;
    real_T S;
    real_T b_varargout_1_f;
    real_T brm;
    real_T bim;
    real_T d_f;
    real_T ar;
    real_T brm_a;
    real_T bim_g;
    real_T sgnbi;
    real_T d_m;
    real_T x_data_im;
    real_T re;
    real_T br;
    real_T x4_data_im;
    real_T ibig_data_d;
    real_T x4_data_e;
    real_T r_e;
    real_T b_x_re;
    real_T b_dl;
    real_T expl_temp_j;
    real_T expl_temp_n;
    real_T expl_temp_ju;
    real_T d_p;
    real_T beta_a;
    real_T rho;
    real_T b_df;
    real_T constrViolation;
    real_T tol;
    real_T qtb;
    real_T temp2;
    real_T b_atmp;
    real_T xnorm;
    real_T scale_p;
    real_T absxk_d;
    real_T t_pq;
    real_T maxiter_f;
    real_T lambda_g;
    real_T lambdac_d;
    real_T iter_h;
    real_T S_i;
    real_T b_varargout_1_m;
    real_T bkj;
    real_T bkj_c;
    real_T v_data_tmp;
    real_T v_data_tmp_l;
    real_T alpha_data_tmp;
    real_T b_gamma_data_tmp;
    real_T b_gamma_data_tmp_p;
    real_T lambda_i;
    real_T lambdac_b;
    real_T S_g;
    real_T unusedU0_o;
    real_T R;
    real_T bet;
    real_T q_b1;
    real_T brm_e;
    real_T bim_e;
    real_T sgnbi_l;
    real_T d_cf;
    real_T b_alpha1;
    real_T tau;
    real_T xnorm_e;
    real_T scale_d;
    real_T absxk_o;
    real_T t_l;
    real_T maxiter_h;
    real_T lambda_l;
    real_T lambdac_c;
    real_T iter_c;
    real_T S_a;
    real_T b_varargout_1_i;
    real_T ai;
    real_T a_re;
    real_T re_l;
    real_T d1;
    real_T d2;
    real_T maxiter_i;
    real_T lambda_a;
    real_T lambdac_i;
    real_T iter_c3;
    real_T S_m;
    real_T b_varargout_1_n;
    real_T R_c;
    real_T d3;
    real_T bet_n;
    real_T q_h;
    real_T b_gamma_i;
    real_T d4;
    real_T d5;
    real_T mu;
    real_T phi_alpha;
    real_T e_e;
    real_T d6;
    real_T t2;
    real_T t3;
    real_T t4;
    real_T t5;
    real_T t6;
    real_T t7;
    real_T t8;
    real_T t9;
    real_T t10;
    real_T t11;
    real_T t12;
    real_T t13;
    real_T t17;
    real_T t18;
    real_T t19;
    real_T t20;
    real_T t21;
    real_T t22;
    real_T t23;
    real_T t24;
    real_T t25;
    real_T t26;
    real_T t27;
    real_T t28;
    real_T t29;
    real_T t30;
    real_T t31;
    real_T t32;
    real_T t33;
    real_T t34;
    real_T t39;
    real_T t40;
    real_T t41;
    real_T t42;
    real_T t43;
    real_T t44;
    real_T t45;
    real_T t55;
    real_T t56;
    real_T t57;
    real_T t60;
    real_T t61;
    real_T t63;
    real_T t64;
    real_T t69;
    real_T t59;
    real_T t46;
    real_T t47;
    real_T t48;
    real_T t27_tmp;
    real_T t31_tmp;
    real_T t24_tmp;
    real_T t32_tmp;
    real_T t25_tmp;
    real_T t29_tmp;
    real_T oldDirIdx;
    real_T tol_p;
    real_T b_atmp_k;
    real_T temp;
    real_T i_i;
    real_T j_n;
    real_T i_o;
    real_T c_tmp;
    real_T e_l;
    real_T r_p;
    real_T a_re_b;
    real_T phi_f;
    real_T dk0_dtheta0;
    real_T k1_i;
    real_T dk1_dtheta0;
    real_T dk0_dtheta1;
    real_T b_x_tmp;
    real_T i_c;
    real_T j_g;
    real_T i_iu;
    real_T c_tmp_b;
    real_T tol_n;
    real_T c_pn;
    real_T alpha_tmp;
    real_T b_gamma_tmp;
    real_T d7;
    real_T alpha_tmp_o;
    real_T b_gamma_tmp_b;
    real_T work_o;
    real_T tmp2;
    real_T ca;
    real_T sa;
    real_T windote;
    real_T magsq;
    real_T absx;
    real_T temp2_idx_0;
    real_T temp2_idx_1;
    real_T temp2_idx_2;
    real_T temp2_idx_0_tmp;
    real_T yv;
    real_T scale_c;
    real_T absxk_j;
    real_T t_e;
    real_T n_p;
    real_T r_n;
    real_T a_re_o;
    real_T phi_d;
    real_T f_tmp;
    real_T i_g;
    real_T j_il;
    real_T c_ih;
    real_T e_c;
    real_T gfE;
    real_T normDelta;
    real_T b_b;
    real_T constrViolation_new;
    real_T constrViolation_minnormX;
    real_T constrViolation_basicX;
    real_T u1_g;
    real_T c_d;
    real_T c_f;
    real_T tst;
    real_T ab;
    real_T ba;
    real_T aa;
    real_T bb;
    real_T h12;
    real_T h21s;
    real_T d_j;
    real_T e_eq;
    real_T p_p;
    real_T bcmax;
    real_T bcmis;
    real_T scale_dd;
    real_T z_f;
    real_T tau_n;
    real_T a_o;
    real_T x_d;
    real_T l_0;
    real_T l_1;
    real_T l_2;
    real_T l_3;
    real_T l_l;
    real_T b_f;
    real_T c_j;
    real_T d_g;
    real_T r_l;
    real_T f_1_im;
    real_T y_re;
    real_T f_2_re;
    real_T f_2_im;
    real_T re_k;
    real_T f_1_im_tmp;
    real_T im_tmp;
    real_T thresh;
    real_T tmp_data_px;
    real_T tmp_data_bu;
    real_T dk_data;
    real_T tmp_data_i3;
    real_T nhikx_data_re;
    real_T nhikx_data_im;
    real_T thresh_tmp;
    real_T xabs_data_p;
    real_T x4_data_l;
    real_T r_ea;
    real_T x_tmp_data;
    real_T br_e;
    real_T x4_data_im_p;
    real_T x4_data_j;
    real_T x_gy;
    real_T r_le;
    real_T b_x_im;
    real_T e_jo;
    real_T gfE_p;
    real_T alpha_data_tmp_d;
    real_T b_gamma_data_tmp_k;
    real_T b_gamma_data_tmp_m;
    real_T s_idx_1;
    real_T brm_f;
    real_T bim_m;
    real_T sgnbi_n;
    real_T d_mi;
    real_T anrm;
    real_T anrmto;
    real_T anorm;
    real_T b_atol;
    real_T bscale;
    real_T temp_b;
    real_T temp2_c;
    real_T tempr;
    real_T ai_g;
    real_T stemp_re;
    real_T stemp_im;
    real_T eshift_re;
    real_T eshift_im;
    real_T t1_tmp;
    real_T scale_ck;
    real_T g2;
    real_T f2s;
    real_T di;
    real_T b_x_i;
    real_T fs_re;
    real_T fs_im;
    real_T gs_re;
    real_T gs_im;
    real_T t8_k;
    real_T t9_g;
    real_T t11_p;
    real_T t12_f;
    real_T t13_m;
    real_T t14;
    real_T t15;
    real_T t16;
    real_T t24_m;
    real_T t26_l;
    real_T t28_j;
    real_T t41_m;
    real_T t43_j;
    real_T t45_i;
    real_T t17_a;
    real_T t18_h;
    real_T t19_d;
    real_T t52;
    real_T t55_i;
    real_T t62;
    real_T t63_h;
    real_T t69_d;
    real_T t70;
    real_T t12_tmp;
    real_T t13_tmp;
    real_T t14_tmp;
    real_T t15_tmp;
    real_T out1_tmp;
    real_T out1_tmp_l;
    real_T out1_tmp_f;
    real_T out1_tmp_lt;
    real_T out1_tmp_l3;
    real_T out1_tmp_f4;
    real_T out1_tmp_g;
    real_T nrm;
    real_T rt;
    real_T ztest;
    real_T smm1;
    real_T emm1;
    real_T sqds;
    real_T shift;
    real_T unusedU2;
    real_T d_sn;
    real_T roe;
    real_T absa;
    real_T absb;
    real_T scale_g;
    real_T ads;
    real_T bds;
    real_T tol_a;
    real_T temp1_d;
    real_T temp2_b;
    real_T b_atmp_d;
    real_T c_fv;
    real_T nmax;
    real_T m_a;
    real_T mnew;
    real_T wb;
    real_T xzero_re;
    real_T xzero_im;
    real_T tmp2_re;
    real_T tmp2_im;
    real_T l_0_m;
    real_T l_1_i;
    real_T l_2_i;
    real_T l_k;
    real_T b_au;
    real_T c_m;
    real_T d_cec;
    real_T xloc;
    real_T r_b;
    real_T f_2_re_k;
    real_T f_2_im_l;
    real_T f_1_im_n;
    real_T y_re_p;
    real_T re_f;
    real_T f_1_im_tmp_k;
    real_T im_tmp_e;
    real_T r_na;
    real_T tmp_data_ol;
    real_T im;
    real_T x_ad;
    real_T x2;
    real_T ang_data;
    real_T ca_data;
    real_T sa_data;
    real_T thd2_data;
    real_T w2_data;
    real_T b_qd;
    real_T theta;
    real_T st;
    real_T scale_b;
    real_T absxk_b;
    real_T t_m;
    real_T thd2_tmp_data;
    real_T thd1_tmp_data;
    real_T tmp_data_mc;
    real_T tmp_data_kw;
    real_T c_data_tmp;
    real_T c_data_tmp_m;
    real_T xloc_h;
    real_T b_x_i1;
    real_T absx_c;
    real_T m_ni;
    real_T mnew_i;
    real_T yb;
    real_T re_o;
    real_T im_h;
    real_T re_p;
    real_T hs;
    real_T hs3;
    real_T w1;
    real_T mu_g;
    real_T b_gamma_c;
    real_T mu_gn;
    real_T b_alpha1_b;
    real_T tau_data;
    real_T temp_j;
    real_T anrm_h;
    real_T anrmto_d;
    real_T anorm_o;
    real_T b_atol_k;
    real_T temp_jw;
    real_T temp2_d;
    real_T tempr_f;
    real_T ai_a;
    real_T stemp_re_e;
    real_T stemp_im_n;
    real_T eshift_re_o;
    real_T eshift_im_d;
    real_T t1_tmp_c;
    real_T scale_m;
    real_T g2_o;
    real_T f2s_b;
    real_T di_m;
    real_T b_x_ii;
    real_T fs_re_i;
    real_T fs_im_g;
    real_T gs_re_m;
    real_T gs_im_n;
    real_T smax;
    real_T s_c;
    real_T t8_j;
    real_T t9_e;
    real_T t10_e;
    real_T t11_k;
    real_T t12_k;
    real_T t13_i;
    real_T t15_e;
    real_T t20_l;
    real_T t32_l;
    real_T t34_l;
    real_T t36;
    real_T t54;
    real_T t57_o;
    real_T t59_i;
    real_T t16_e;
    real_T t17_l;
    real_T t18_n;
    real_T t19_e;
    real_T t21_c;
    real_T t22_a;
    real_T t23_m;
    real_T t66;
    real_T t69_c;
    real_T t78;
    real_T t79;
    real_T t40_f;
    real_T t44_m;
    real_T t56_k;
    real_T t86;
    real_T t87;
    real_T t45_b;
    real_T t74;
    real_T t77;
    real_T out1_tmp_h;
    real_T out1_tmp_hc;
    real_T out1_tmp_h2;
    real_T out1_tmp_b;
    real_T out1_tmp_bf;
    real_T out1_tmp_d;
    real_T out1_tmp_j;
    real_T out1_tmp_dl;
    real_T tmp_data_lo;
    real_T tmp_data_jkk;
    real_T aa_tmp;
    real_T c_b;
    real_T itmax;
    real_T SMLNUM;
    real_T tst_f;
    real_T ab_p;
    real_T ba_l;
    real_T aa_l;
    real_T bb_i;
    real_T h12_o;
    real_T h21s_b;
    real_T cs;
    real_T sn_i;
    real_T xnorm_g;
    real_T scale_po;
    real_T absxk_h;
    real_T t_d;
    real_T t2_f;
    real_T t3_f;
    real_T t4_c;
    real_T t5_d;
    real_T t6_c;
    real_T t7_b;
    real_T t8_p;
    real_T t9_h;
    real_T t10_ei;
    real_T t11_l;
    real_T t12_h;
    real_T t13_n;
    real_T t14_k;
    real_T t15_b;
    real_T t16_o;
    real_T t17_n;
    real_T t21_f;
    real_T t25_g;
    real_T t26_d;
    real_T t27_d;
    real_T t28_e;
    real_T t29_c;
    real_T t65;
    real_T t56_a;
    real_T t57_h;
    real_T t58;
    real_T smax_e;
    real_T s_n;
    real_T ub_tmp;
    real_T temp_h;
    real_T ub_tmp_o;
    real_T optimRelativeFactor;
    real_T nlpComplErrorTmp;
    real_T nlpComplErrorLSQ;
    real_T c_fo;
    real_T d8;
    real_T tol_k;
    real_T denomTol;
    real_T phaseOneCorrectionP;
    real_T pk_corrected;
    real_T ratio;
    real_T c_e;
    real_T u0_i;
    real_T c_o3;
    real_T c_jo;
    real_T b_c_k;
    real_T s_j;
    real_T c_c;
    real_T roe_d;
    real_T absa_g;
    real_T absb_c;
    real_T scale_k;
    real_T ads_j;
    real_T bds_h;
    real_T u1_c;
    real_T c_dh;
    real_T c_a;
    real_T c_pu;
    real_T d9;
    real_T stemp_re_f;
    real_T stemp_im_h;
    real_T ssq;
    real_T c_j5;
    real_T c_n;
    real_T d10;
    real_T stemp_re_o;
    real_T stemp_im_o;
    real_T cfromc;
    real_T ctoc;
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    real_T cfromc_d;
    real_T ctoc_a;
    real_T cfrom1_k;
    real_T cto1_c;
    real_T mul_j;
    real_T ac2;
    real_T ad2;
    real_T bc2;
    real_T bd2;
    real_T cd2;
    real_T aasq;
    real_T scale_bh;
    real_T sumsq;
    real_T temp1_n;
    real_T temp2_dm;
    real_T scale_h;
    real_T sumsq_b;
    real_T temp1_p;
    real_T temp2_bp;
    real_T b1;
    real_T b2;
    real_T b0;
    real_T temp2_idx_2_p;
    real_T temp2_idx_1_n;
    real_T temp2_idx_0_j;
    real_T b1_b;
    real_T b2_n;
    real_T b0_b;
    real_T temp2_idx_2_j;
    real_T temp2_idx_1_k;
    real_T temp2_idx_0_d;
    real_T temp_d;
    real_T xnorm_o;
    real_T scale_cf;
    real_T absxk_oz;
    real_T t_a;
    real_T cfromc_dq;
    real_T ctoc_e;
    real_T cfrom1_i;
    real_T cto1_b;
    real_T mul_a;
    real_T u1_k;
    real_T u1_m;
    real_T c_jx;
    real_T cfromc_j;
    real_T ctoc_k;
    real_T cfrom1_kp;
    real_T cto1_a;
    real_T mul_k;
    real_T atmp_re;
    real_T atmp_im;
    real_T d_fo;
    real_T e_cz;
    real_T c_c_o;
    real_T b_s;
    real_T temp_k;
    real_T atmp_re_p;
    real_T atmp_im_f;
    real_T c_dx;
    real_T c_eb;
    real_T temp_l;
    real_T scale_e;
    real_T absxk_hv;
    real_T t_g;
    real_T c_p5;
    real_T c_nl;
    real_T temp_o;
    real_T scale_l;
    real_T absxk_f;
    real_T t_h;
    real_T temp_d4;
    SL_Bus_full_loop_std_msgs_UInt8 In1_g;// '<S140>/In1'
    int32_T A_size[2];
    int32_T waypoints_size[2];
    int32_T waypoints_size_m[2];
    int32_T Jtri_size[2];
    int32_T b_varargout_2_size[2];
    int32_T f_size[2];
    int32_T k_size[2];
    int32_T l_size[2];
    int32_T b_size[2];
    int32_T waypoints_size_i[2];
    int32_T Jtri_size_j[2];
    int32_T b_varargout_2_size_p[2];
    int32_T A_size_d[2];
    int32_T tmp_size[2];
    int32_T y_size[2];
    int32_T A_size_j[2];
    int32_T zy_size[2];
    int32_T result_size[2];
    int32_T z_size[2];
    int32_T c_size[2];
    int32_T Jtri_size_k[2];
    int32_T b_varargout_2_size_m[2];
    int32_T Jtri_size_d[2];
    int32_T b_varargout_2_size_pz[2];
    int32_T tmp_size_i[2];
    int32_T y_size_g[2];
    int32_T varargout_1_size[2];
    int32_T c_size_e[2];
    int32_T Jc_size[2];
    int32_T b_size_h[2];
    int32_T varargin_2_size[2];
    int32_T varargout_3_size[2];
    int32_T varargout_1_size_g[2];
    int32_T c_size_c[2];
    int32_T Jc_size_a[2];
    int32_T tmp_size_f[2];
    int32_T x_size[2];
    int32_T dk_size[2];
    int32_T k_size_i[2];
    int32_T theta_size[2];
    int32_T k_size_c[2];
    int32_T tmp_size_n[2];
    int32_T dk_size_c[2];
    int32_T tmp_size_c[2];
    int32_T tmp_size_ik[2];
    int32_T dk_size_h[2];
    int32_T tmp_size_m[2];
    int32_T x_size_g[2];
    int32_T tmp_size_o[2];
    int32_T tmp_size_ms[2];
    int32_T tmp_size_e[2];
    int32_T k_size_e[2];
    int32_T tmp_size_il[2];
    int32_T k_size_f[2];
    int32_T xabs_size[2];
    int32_T SZ[2];
    int32_T tmp_size_h[2];
    int32_T A_size_i[2];
    int32_T At_size[2];
    int32_T b_At_size[2];
    int32_T varargout_3_size_p[2];
    int32_T varargout_1_size_a[2];
    int32_T c_A_size[2];
    int32_T b_jpvt_size[2];
    int32_T b_jpvt_size_f[2];
    int32_T e_A_size[2];
    int32_T b_A_size[2];
    int32_T d_C_size[2];
    int32_T b_C_size[2];
    int32_T r_size[2];
    int32_T s_size[2];
    int32_T iv8[2];
    int32_T iv9[2];
    int32_T iv10[2];
    int32_T tmp_size_d[2];
    int32_T Zout_size[2];
    int32_T Zout_size_c[2];
    int32_T Zout_size_j[2];
    int32_T z_size_c[2];
    int32_T l_size_n[2];
    int32_T alpha_size[2];
    int32_T zorig_size[2];
    int32_T dz_size[2];
    int32_T z_size_j[2];
    int32_T l_size_k[2];
    int32_T l_size_o[2];
    int32_T l_size_g[2];
    int32_T tmp_size_k[2];
    int32_T a_size[2];
    int32_T a_size_j[2];
    int32_T e_size[2];
    int32_T f_size_p[2];
    int32_T ang_size[2];
    int32_T th1_size[2];
    int32_T u_size[2];
    int32_T sa_size[2];
    int32_T w_size[2];
    int32_T udot_size[2];
    int32_T wd1_size[2];
    int32_T wd1xu_size[2];
    int32_T e_tmp_size[2];
    int32_T tmp_size_hw[2];
    int32_T tmp_size_nw[2];
    int32_T tmp_size_b[2];
    int32_T tmp_size_mt[2];
    int32_T w_size_k[2];
    int32_T th1_size_b[2];
    int32_T tmp_size_l[2];
    int32_T tmp_size_g[2];
    int32_T tmp_size_g2[2];
    int32_T th3_size[2];
    int32_T tmp_size_n4[2];
    int32_T Zout_size_c3[2];
    int32_T Zout_size_e[2];
    int32_T Zout_size_f[2];
    int32_T z_size_k[2];
    int32_T dz_size_c[2];
    int32_T zorig_size_d[2];
    int32_T zorig_size_m[2];
    int32_T dz_size_j[2];
    int32_T z_size_cf[2];
    int32_T l_size_d[2];
    int32_T l_size_p[2];
    int32_T l_size_a[2];
    int32_T b_size_m[2];
    int32_T Lbd_size[2];
    int32_T A_size_n[2];
    int32_T c_a_size[2];
    int32_T d_a_size[2];
    int32_T c_a_size_k[2];
    int32_T b_C_size_p[2];
    int32_T bvec2_size[2];
    int32_T e_size_k[2];
    int32_T e_size_g[2];
    int32_T e_size_h[2];
    int32_T tmp_size_ld[2];
    int32_T tmp_size_o0[2];
    int32_T c_h_size[2];
    int32_T b_h_size[2];
    int32_T b_h_size_a[2];
    int32_T z_size_n[2];
    int32_T d1_size[2];
    int32_T tmp_size_ov[2];
    int32_T tmp_size_da[2];
    int32_T d2_size[2];
    int32_T d1_size_h[2];
    int32_T zcurrent_size[2];
    int32_T l1_size[2];
    int32_T l1_size_h[2];
    int32_T l1_size_a[2];
    int32_T z_size_kg[2];
    int32_T d1_size_j[2];
    int32_T l1_size_d[2];
    int32_T d2_size_p[2];
    int32_T d1_size_d[2];
    int32_T zcurrent_size_b[2];
    int32_T l1_size_o[2];
    int32_T l1_size_j[2];
    int32_T l1_size_p[2];
    int32_T c_size_l[2];
    int32_T b_size_c[2];
    int32_T b_C_size_m[2];
    boolean_T bv3[8];
    int8_T b_ipiv[4];
    int32_T ibmat;
    int32_T i_h;
    int32_T B_size;
    int32_T M_tmp;
    int32_T b_aw;
    int32_T b_i_o;
    int32_T c_i_i;
    int32_T wpt_count;
    int32_T wpt_count_e;
    int32_T i_a;
    int32_T i_e;
    int32_T b_i_d;
    int32_T nm1d2;
    int32_T k_l;
    int32_T n_i;
    int32_T b_k;
    int32_T c_nk;
    int32_T i_cf;
    int32_T ibegin_size;
    int32_T iend_size;
    int32_T c_size_i;
    int32_T y_size_idx_1;
    int32_T ndbl_d;
    int32_T c_b4;
    int32_T l_a;
    int32_T loop_ub;
    int32_T u_size_b;
    int32_T v_size;
    int32_T tmp_size_nt;
    int32_T waypoints_size_b;
    int32_T i_p;
    int32_T loop_ub_i;
    int32_T v_size_k;
    int32_T dx_size;
    int32_T b_r_size;
    int32_T b_varargout_1_size;
    int32_T tmp_size_cr;
    int32_T tmp_size_nc;
    int32_T tmp_size_bp;
    int32_T loop_ub_tmp;
    int32_T e_m;
    int32_T f_m;
    int32_T l_n;
    int32_T o_m;
    int32_T q_l;
    int32_T ib;
    int32_T mb;
    int32_T loop_ub_o;
    int32_T unusedU3_size;
    int32_T k0_size;
    int32_T k1_size;
    int32_T dk0_dc0_size;
    int32_T dk0_dc1_size;
    int32_T dk1_dc0_size;
    int32_T dk1_dc1_size;
    int32_T course_size;
    int32_T hip_size;
    int32_T course_size_i;
    int32_T g_size_idx_1_tmp;
    int32_T b_i_p;
    int32_T loop_ub_n;
    int32_T z_size_c0;
    int32_T phi_size;
    int32_T phi0_size;
    int32_T phi1_size;
    int32_T da_dphi1_size;
    int32_T tmp_size_et;
    int32_T idx_j;
    int32_T b_size_l;
    int32_T tmp_size_j;
    int32_T d_size;
    int32_T tmp_size_c3;
    int32_T a_size_b;
    int32_T d_size_i;
    int32_T c_size_k;
    int32_T a_size_l;
    int32_T d_size_j;
    int32_T c_size_m;
    int32_T criteria_size_idx_0;
    int32_T ii_size_idx_0;
    int32_T ilarge_size_idx_0;
    int32_T ismall_size_idx_0;
    int32_T h_idx_0;
    int32_T i1;
    int32_T loop_ub_j;
    int32_T a1_size;
    int32_T a2_size;
    int32_T fa_size;
    int32_T s_size_e;
    int32_T r_size_d;
    int32_T ratio_size;
    int32_T tmp_size_j4;
    int32_T a1_size_k;
    int32_T a1_size_o;
    int32_T i2;
    int32_T loop_ub_nc;
    int32_T x_size_b;
    int32_T x_size_i;
    int32_T idx_d;
    int32_T i_dp;
    int32_T tmp_size_p;
    int32_T tmp_size_es;
    int32_T xabs_size_idx_0;
    int32_T b_idx_0;
    int32_T nx;
    int32_T b_k_n;
    int32_T mIneq;
    int32_T mConstrMax;
    int32_T maxDims;
    int32_T mNonlinIneq;
    int32_T mLB;
    int32_T mUB;
    int32_T mFixed;
    int32_T c_size_d;
    int32_T d_size_m;
    int32_T tmp_size_gm;
    int32_T tmp_size_ij;
    int32_T nVar;
    int32_T mFixed_k;
    int32_T mIneq_i;
    int32_T mLB_m;
    int32_T mUB_j;
    int32_T mConstr;
    int32_T mLinIneq;
    int32_T qpoptions_MaxIterations;
    int32_T loop_ub_a;
    int32_T g_size;
    int32_T h_size;
    int32_T u1_i;
    int32_T nVar_e;
    int32_T loop_ub_ik;
    int32_T b_size_hv;
    int32_T d_size_mg;
    int32_T e_size_a;
    int32_T nVarOrig;
    int32_T nVarMax;
    int32_T mIneq_o;
    int32_T temp_os;
    int32_T nArtificial;
    int32_T nVar_n;
    int32_T loop_ub_k;
    int32_T g_size_h;
    int32_T b_d4;
    int32_T c_size_a;
    int32_T mTotalWorkingEq;
    int32_T idx_row;
    int32_T b_idx_col;
    int32_T b_size_hg;
    int32_T c_size_cc;
    int32_T b_idx;
    int32_T ix_b;
    int32_T iy;
    int32_T k_c;
    int32_T loop_ub_g;
    int32_T c_size_p;
    int32_T d_size_ib;
    int32_T ma;
    int32_T minmana;
    int32_T minmn;
    int32_T c_j_j;
    int32_T ma_c;
    int32_T minmn_c;
    int32_T ii;
    int32_T nmi;
    int32_T mmi;
    int32_T i_f;
    int32_T i3;
    int32_T loop_ub_d;
    int32_T tmp_size_nr;
    int32_T e_br;
    int32_T h_f0;
    int32_T j_j;
    int32_T k_h;
    int32_T l_hg;
    int32_T loop_ub_c;
    int32_T dx_size_g;
    int32_T b_r_size_e;
    int32_T b_varargout_1_size_e;
    int32_T unusedU4_size;
    int32_T k0_size_a;
    int32_T k1_size_h;
    int32_T dk0_dc0_size_g;
    int32_T dk0_dc1_size_a;
    int32_T dk1_dc0_size_g;
    int32_T dk1_dc1_size_o;
    int32_T x_size_a;
    int32_T hip_size_e;
    int32_T x_size_h;
    int32_T xnew_size;
    int32_T xnew_size_j;
    int32_T xnew_size_b;
    int32_T hip_size_k;
    int32_T xnew_size_h;
    int32_T m_d;
    int32_T inner;
    int32_T n_o;
    int32_T coffset;
    int32_T boffset;
    int32_T loop_ub_ku;
    int32_T loop_ub_k0;
    int32_T loop_ub_on;
    int32_T loop_ub_do;
    int32_T a_size_lo;
    int32_T b_size_me;
    int32_T d_size_o;
    int32_T c_size_at;
    int32_T a_size_i;
    int32_T lambda_size;
    int32_T y_size_idx_1_f;
    int32_T J_size_idx_0;
    int32_T result;
    int32_T inner_a;
    int32_T inner_g;
    int32_T m_k;
    int32_T coffset_l;
    int32_T boffset_e;
    int32_T loop_ub_tmp_e;
    int32_T b_k_f;
    int32_T k_d;
    int32_T loop_ub_b;
    int32_T alpha_size_o;
    int32_T alpha_data_tmp_p;
    int32_T alpha_data_tmp_l;
    int32_T loop_ub_tmp_d;
    int32_T delta_tmp;
    int32_T b_data_tmp;
    int32_T c_data_tmp_l;
    int32_T acoef;
    int32_T ia;
    int32_T d_a;
    int32_T k_n;
    int32_T acoef_e;
    int32_T bcoef;
    int32_T k_nf;
    int32_T b_i_h;
    int32_T course_tmp;
    int32_T course_tmp_a;
    int32_T iter_b;
    int32_T i_k;
    int32_T z_tmp_a;
    int32_T z_tmp_k;
    int32_T b_idx_p;
    int32_T i_o3;
    int32_T b_i_c;
    int32_T i_kh;
    int32_T istart;
    int32_T b_j_h;
    int32_T im1n;
    int32_T in;
    int32_T b_i_b;
    int32_T u0_e;
    int32_T knt;
    int32_T k_co;
    int32_T b_tmp;
    int32_T kend;
    int32_T loop_ub_om;
    int32_T v_size_a;
    int32_T dx_size_p;
    int32_T b_r_size_o;
    int32_T b_varargout_1_size_l;
    int32_T tmp_size_fr;
    int32_T tmp_size_pn;
    int32_T tmp_size_p5;
    int32_T loop_ub_tmp_b;
    int32_T e_k;
    int32_T l_m;
    int32_T p_g;
    int32_T q_b5;
    int32_T r_i;
    int32_T ib_b;
    int32_T loop_ub_h;
    int32_T unusedU2_size;
    int32_T k0_size_d;
    int32_T k1_size_f;
    int32_T dk0_dc0_size_d;
    int32_T dk0_dc1_size_p;
    int32_T dk1_dc0_size_gs;
    int32_T dk1_dc1_size_f;
    int32_T course_size_o;
    int32_T hip_size_f;
    int32_T course_size_o3;
    int32_T i4;
    int32_T loop_ub_l;
    int32_T k_size_e3;
    int32_T e_size_gn;
    int32_T dt_size;
    int32_T dp_size;
    int32_T tmp_size_ba;
    int32_T y_size_idx_0;
    int32_T nik_size_idx_0;
    int32_T t_size_idx_0;
    int32_T re_j;
    int32_T e_size_f;
    int32_T z_size_co;
    int32_T dz_size_f;
    int32_T nx_b;
    int32_T loop_ub_de;
    int32_T v_size_j;
    int32_T dx_size_o;
    int32_T xnew_size_l;
    int32_T b_r_size_g;
    int32_T epsr_size;
    int32_T xnew_size_m;
    int32_T xnew_size_g;
    int32_T loop_ub_tmp_a;
    int32_T i5;
    int32_T loop_ub_e;
    int32_T tmp_size_b0;
    int32_T c_ez;
    int32_T b_i_m;
    int32_T b_idx_h;
    int32_T b_size_b;
    int32_T q_size;
    int32_T beta_size;
    int32_T alpha_size_idx_0;
    int32_T y_size_idx_1_d;
    int32_T y_size_idx_1_o;
    int32_T y_size_idx_1_k;
    int32_T y_size_idx_1_m;
    int32_T y_size_idx_1_fj;
    int32_T y_size_idx_1_ox;
    int32_T c_tmp_i;
    int32_T loop_ub_ka;
    int32_T i6;
    int32_T center_size;
    int32_T tmp_size_kg;
    int32_T center_size_n;
    int32_T f_f;
    int32_T loop_ub_m;
    int32_T u_size_i;
    int32_T z_size_i;
    int32_T h_size_idx_1_tmp;
    int32_T f_b;
    int32_T mLinIneq_n;
    int32_T evalStatus;
    int32_T loop_ub_ir;
    int32_T c_size_n;
    int32_T e_size_m;
    int32_T ineqEnd;
    int32_T nWIneq_old;
    int32_T nWLower_old;
    int32_T nWUpper_old;
    int32_T nVar_p;
    int32_T mConstrMax_k;
    int32_T b_i_p3;
    int32_T nFixedConstr;
    int32_T idx_e;
    int32_T nDepIneq;
    int32_T b_size_k;
    int32_T c_size_b;
    int32_T b_idx_l;
    int32_T c_size_j;
    int32_T d_size_jx;
    int32_T lda;
    int32_T ii_k;
    int32_T mmi_p;
    int32_T loop_ub_p;
    int32_T e_et;
    int32_T f_h;
    int32_T l_i;
    int32_T o_j;
    int32_T q_a2r;
    int32_T ib_j;
    int32_T mb_g;
    int32_T loop_ub_nj;
    int32_T unusedU1_size;
    int32_T k0_size_l;
    int32_T k1_size_e;
    int32_T dk0_dc0_size_c;
    int32_T dk0_dc1_size_h;
    int32_T dk1_dc0_size_o;
    int32_T dk1_dc1_size_d;
    int32_T course_size_d;
    int32_T hip_size_j;
    int32_T course_size_f;
    int32_T g_size_idx_1_tmp_k;
    int32_T n_n;
    int32_T result_n;
    int32_T result_i;
    int32_T result_e;
    int32_T loop_ub_kj;
    int32_T loop_ub_k3;
    int32_T u_size_p;
    int32_T v_size_kn;
    int32_T tmp_size_p1;
    int32_T result_size_idx_1;
    int32_T b_idx_0_p;
    int32_T x_data_tmp;
    int32_T nrows;
    int32_T ibcol;
    int32_T b_jtilecol;
    int32_T b_k_b;
    int32_T c_idx_row;
    int32_T c_idx_col;
    int32_T result_c;
    int32_T c_result;
    int32_T result_idx_0;
    int32_T partialTrueCount;
    int32_T i_de;
    int32_T i7;
    int32_T Je_size;
    int32_T icf_tmp;
    int32_T b_k_c;
    int32_T n_a;
    int32_T b_k_i;
    int32_T i_du;
    int32_T b_subsb_idx_1;
    int32_T x_tmp_f;
    int32_T ibcol_n;
    int32_T b_jtilecol_g;
    int32_T idx_o;
    int32_T nFixedConstr_m;
    int32_T idx_h;
    int32_T nDepIneq_e;
    int32_T b_size_mw;
    int32_T c_size_im;
    int32_T pvt;
    int32_T itemp;
    int32_T loop_ub_h4;
    int32_T b_k_nm;
    int32_T e_tmp_e;
    int32_T i8;
    int32_T x_tmp_tmp;
    int32_T b_I_tmp;
    int32_T b_k_e;
    int32_T c_k;
    int32_T k_o;
    int32_T i9;
    int32_T ixLead;
    int32_T iyLead;
    int32_T m_o;
    int32_T b_k_fr;
    int32_T b_j_m;
    int32_T obj_b_size;
    int32_T obj_c_size;
    int32_T obj_d_size;
    int32_T izero_size;
    int32_T e_tmp_g;
    int32_T xoffset;
    int32_T c_j_c;
    int32_T b_k_k;
    int32_T n_dd;
    int32_T b_k_cm;
    int32_T i_kn;
    int32_T b_subsb_idx_1_k;
    int32_T x_tmp_fw;
    int32_T b_k_g;
    int32_T PROBTYPE_ORIG;
    int32_T nVar_k;
    int32_T nVarP1;
    int32_T PHASEONE;
    int32_T mEqFixed;
    int32_T activeSetChangeID;
    int32_T nVar_nk;
    int32_T globalActiveConstrIdx;
    int32_T idxMinLambda;
    int32_T TYPE;
    int32_T idx_local;
    int32_T h_size_p;
    int32_T loop_ub_e2;
    int32_T d_size_l;
    int32_T i_size;
    int32_T mWConstr;
    int32_T nVar_a;
    int32_T b_idx_e;
    int32_T b_idx_row;
    int32_T b_size_g;
    int32_T mLB_f;
    int32_T mUB_e;
    int32_T mFixed_n;
    int32_T idx_m;
    int32_T mIneq_b;
    int32_T b_k_nh;
    int32_T ix_c;
    int32_T b_iy;
    int32_T iac;
    int32_T b_m;
    int32_T ia_j;
    int32_T istart_h;
    int32_T b_j_c;
    int32_T i_m;
    int32_T L;
    int32_T k_nb;
    int32_T m_e;
    int32_T nr;
    int32_T hoffset;
    int32_T c_j_ce;
    int32_T d_j_b;
    int32_T e_j_p;
    int32_T ix_i;
    int32_T tst_tmp;
    int32_T b_o;
    int32_T loop_ub_n3;
    int32_T i10;
    int32_T loop_ub_me;
    int32_T y_size_idx_1_m4;
    int32_T idx_dt;
    int32_T b_ii;
    int32_T idx_i;
    int32_T ii_e;
    int32_T i_kb;
    int32_T p_size;
    int32_T q_size_p;
    int32_T a_size_j3;
    int32_T d_size_c;
    int32_T c_size_b2;
    int32_T a_size_lv;
    int32_T d_size_n;
    int32_T c_size_al;
    int32_T nx_n;
    int32_T b_k_d;
    int32_T i11;
    int32_T ip;
    int32_T ip_g;
    int32_T ip_f;
    int32_T ip_gg;
    int32_T tmp_size_la;
    int32_T ii_size_idx_0_l;
    int32_T ii_size_idx_1;
    int32_T igt_size_idx_0;
    int32_T igt_size_idx_1;
    int32_T ilt_size_idx_0;
    int32_T ilt_size_idx_1;
    int32_T ism_size_idx_0;
    int32_T ism_size_idx_1;
    int32_T ismall_data_o;
    int32_T bd_data_k;
    int32_T ed_data;
    int32_T ii_data_g;
    int32_T nx_k;
    int32_T idx_jc;
    int32_T b_ii_k;
    int32_T i_g1;
    int32_T ii_size_idx_0_h;
    int32_T loop_ub_tmp_m;
    int32_T nx_kr;
    int32_T b_k_cz;
    int32_T idx_hu;
    int32_T b_ii_h;
    int32_T idx_dl;
    int32_T ii_b;
    int32_T i_pr;
    int32_T q_size_c;
    int32_T r_size_b;
    int32_T a_size_lt;
    int32_T d_size_oy;
    int32_T c_size_dd;
    int32_T a_size_m;
    int32_T d_size_nr;
    int32_T c_size_me;
    int32_T nx_i;
    int32_T b_k_o;
    int32_T acoef_a;
    int32_T bcoef_k;
    int32_T nsubs;
    int32_T loop_ub_tmp_mi;
    int32_T i12;
    int32_T A_data_tmp;
    int32_T i13;
    int32_T nsubs_g;
    int32_T b_k_nl;
    int32_T b_info;
    int32_T loop_ub_ic;
    int32_T beta1_size;
    int32_T ilo;
    int32_T rscale_size;
    int32_T loop_ub_tmp_ev;
    int32_T n_e;
    int32_T j_b;
    int32_T ifirst;
    int32_T istart_i;
    int32_T ilastm1;
    int32_T ilastm;
    int32_T iiter;
    int32_T jp1;
    int32_T jiter;
    int32_T b_x_kh;
    int32_T b_A_size_idx_0;
    int32_T ctemp_tmp;
    int32_T ctemp_tmp_tmp;
    int32_T count;
    int32_T rescaledir;
    int32_T i14;
    int32_T loop_ub_dk;
    int32_T y_size_idx_1_ke;
    int32_T qp1;
    int32_T qq;
    int32_T qjj;
    int32_T m_az;
    int32_T qs;
    int32_T na;
    int32_T maxmn;
    int32_T c_if;
    int32_T minmana_b;
    int32_T mn;
    int32_T i_e5;
    int32_T ma_l;
    int32_T minmn_i;
    int32_T ii_bq;
    int32_T nmi_e;
    int32_T mmi_b;
    int32_T pvt_i;
    int32_T itemp_m;
    int32_T work_size;
    int32_T m_l;
    int32_T lastv;
    int32_T i_oo;
    int32_T lastc;
    int32_T work_size_n;
    int32_T ix_in;
    int32_T iy_o;
    int32_T b_mr;
    int32_T d_a5;
    int32_T ia_c;
    int32_T i15;
    int32_T loop_ub_dm;
    int32_T x_size_gh;
    int32_T loop_ub_hh;
    int32_T unnamed_idx_1;
    int32_T Zout_size_tmp;
    int32_T b_bt;
    int32_T t_ds;
    int32_T u_c;
    int32_T w_h;
    int32_T ab_f;
    int32_T db;
    int32_T eb;
    int32_T gb;
    int32_T jb;
    int32_T loop_ub_nk;
    int32_T dz_size_tmp;
    int32_T dz_data_re_tmp;
    int32_T z_size_tmp;
    int32_T dimSize;
    int32_T ixLead_d;
    int32_T iyLead_e;
    int32_T c_k_e;
    int32_T i16;
    int32_T i_p5;
    int32_T e_i;
    int32_T ip_n;
    int32_T b_k_f4;
    int32_T loop_ub_eg;
    int32_T x_size_idx_0;
    int32_T b_subsb_idx_0;
    int32_T im_tmp_k;
    int32_T im_tmp_f;
    int32_T im_tmp_tmp;
    int32_T loop_ub_tmp_k;
    int32_T acoef_p;
    int32_T ia_h;
    int32_T k_dc;
    int32_T acoef_d;
    int32_T k_d2;
    int32_T csz_idx_0;
    int32_T br_j;
    int32_T i17;
    int32_T thd2_size;
    int32_T w2_size;
    int32_T thd2_tmp_size;
    int32_T thd1_tmp_size;
    int32_T tmp_size_a;
    int32_T tmp_size_al;
    int32_T tmp_size_ac;
    int32_T tmp_size_ldr;
    int32_T tmp_size_i4;
    int32_T tmp_size_na;
    int32_T ii_size_idx_0_b;
    int32_T ii_size_idx_1_h;
    int32_T loop_ub_tmp_bk;
    int32_T stride;
    int32_T iNext;
    int32_T iEnd;
    int32_T i2_a;
    int32_T i3_b;
    int32_T b_ix;
    int32_T ip_l;
    int32_T ret;
    int32_T low_ip1;
    int32_T high_i;
    int32_T i18;
    int32_T ibmat_h;
    int32_T b_jcol;
    int32_T i19;
    int32_T i_do;
    int32_T loop_ub_g4;
    int32_T e_tmp_j;
    int32_T d_m3;
    int32_T v_le;
    int32_T w_o;
    int32_T y_p;
    int32_T cb;
    int32_T fb;
    int32_T gb_d;
    int32_T ib_g;
    int32_T lb;
    int32_T b_tmp_m;
    int32_T dz_size_tmp_o;
    int32_T dz_data_re_tmp_f;
    int32_T z_size_tmp_i;
    int32_T d_i;
    int32_T loop_ub_dmq;
    int32_T info_f;
    int32_T loop_ub_nq;
    int32_T n_dj;
    int32_T im1n_c;
    int32_T in_b;
    int32_T e_bm;
    int32_T loop_ub_hho;
    int32_T d_idx_0;
    int32_T lastv_g;
    int32_T i_cp;
    int32_T lastc_d;
    int32_T jA;
    int32_T jy;
    int32_T ix_a;
    int32_T c_h;
    int32_T b_k_cr;
    int32_T i20;
    int32_T ihi;
    int32_T i_cfh;
    int32_T j_m;
    int32_T ifirst_o;
    int32_T istart_e;
    int32_T ilast;
    int32_T ilastm1_j;
    int32_T ilastm_l;
    int32_T iiter_n;
    int32_T jp1_e;
    int32_T jiter_c;
    int32_T b_x_j;
    int32_T i_my;
    int32_T ctemp_tmp_e;
    int32_T n_h;
    int32_T LDA;
    int32_T ldap1;
    int32_T c_cf;
    int32_T ix_j;
    int32_T kAcol;
    int32_T iy_a;
    int32_T ixinc;
    int32_T iyinc;
    int32_T n_do;
    int32_T yk;
    int32_T jyinc;
    int32_T c_bb;
    int32_T loop_ub_ck;
    int32_T c_A_size_idx_0;
    int32_T loop_ub_ah;
    int32_T tmp_size_ir;
    int32_T ii_size_idx_0_p;
    int32_T ii_size_idx_1_m;
    int32_T aa_tmp_b;
    int32_T vstride;
    int32_T ic_e;
    int32_T i1_f;
    int32_T j_mz;
    int32_T m_ax;
    int32_T istart_o;
    int32_T jend;
    int32_T i_l;
    int32_T c_h_size_p;
    int32_T n_dm;
    int32_T ldh;
    int32_T i_b;
    int32_T L_d;
    int32_T k_dcj;
    int32_T m_eh;
    int32_T nr_l;
    int32_T hoffset_k;
    int32_T e_j_l;
    int32_T o_jt;
    int32_T loop_ub_hr;
    int32_T b_h_data_tmp;
    int32_T tst_tmp_k;
    int32_T knt_e;
    int32_T k_gi;
    int32_T jj;
    int32_T b_j_cf;
    int32_T c_ob;
    int32_T idxmax;
    int32_T ix_l;
    int32_T k_e;
    int32_T iy_m;
    int32_T jy_o;
    int32_T d_e;
    int32_T hb;
    int32_T kb;
    int32_T loop_ub_mr;
    int32_T d2_size_idx_1_tmp;
    int32_T d2_size_tmp;
    int32_T d2_data_re_tmp;
    int32_T d1_size_tmp;
    int32_T d1_data_re_tmp;
    int32_T nx_j;
    int32_T b_k_h;
    int32_T ix_n;
    int32_T iy_j;
    int32_T c_dxa;
    int32_T d_jx;
    int32_T hb_k;
    int32_T kb_b;
    int32_T loop_ub_lt;
    int32_T d2_size_idx_1_tmp_j;
    int32_T d2_data_re_tmp_n;
    int32_T d1_size_tmp_g;
    int32_T d1_data_re_tmp_d;
    int32_T nVar_o;
    int32_T mFixed_a;
    int32_T mIneq_e;
    int32_T mLB_o;
    int32_T mUB_i;
    int32_T mLambda;
    int32_T nActiveConstr;
    int32_T d_size_b;
    int32_T fullRank_R;
    int32_T rankR;
    int32_T iQR_diag;
    int32_T iQR0;
    int32_T idx_a;
    int32_T n_j;
    int32_T k_a;
    int32_T i21;
    int32_T i_gu;
    int32_T itau;
    int32_T iaii;
    int32_T b_j_o;
    int32_T totalIneq;
    int32_T iyend;
    int32_T ix_ay;
    int32_T b_iy_c;
    int32_T iac_d;
    int32_T mLB_d;
    int32_T mUB_l;
    int32_T mFixed_d;
    int32_T idx_jj;
    int32_T mIneq_k;
    int32_T b_k_dy;
    int32_T ix_ce;
    int32_T b_iy_k;
    int32_T iac_p;
    int32_T b_em;
    int32_T ia_i;
    int32_T n_bv;
    int32_T jrow;
    int32_T jcol;
    int32_T j_iz;
    int32_T stemp_re_tmp;
    int32_T nVar_h;
    int32_T mNull;
    int32_T nullStartIdx;
    int32_T d_idx;
    int32_T c_d5;
    int32_T b_idx_g;
    int32_T idxA1j;
    int32_T idxAjj;
    int32_T jrow_m;
    int32_T jcol_g;
    int32_T j_h;
    int32_T stemp_re_tmp_a;
    int32_T loop_ub_ee;
    int32_T j_ir;
    int32_T b_hl;
    int32_T i_kq;
    int32_T reAij_tmp;
    int32_T j_f;
    int32_T b_l;
    int32_T i_ob;
    int32_T reAij_tmp_l;
    int32_T lastv_d;
    int32_T i_a3;
    int32_T lastc_j;
    int32_T jA_o;
    int32_T jy_e;
    int32_T ix_m;
    int32_T c_dq;
    int32_T knt_c;
    int32_T loop_ub_tmp_i;
    int32_T b_tmp_k;
    int32_T i22;
    int32_T mLB_c;
    int32_T mUB_f;
    int32_T mFixed_j;
    int32_T idx_ie;
    int32_T mIneq_c;
    int32_T i_da;
    int32_T j_a;
    int32_T ii_h;
    int32_T nzcount;
    int32_T b_jj;
    int32_T c_A_size_idx_0_k;
    int32_T j_k;
    int32_T ii_n;
    int32_T nzcount_j;
    int32_T b_jj_b;
    int32_T i_es;
    int32_T mIneq_m;
    int32_T mLBOrig;
    int32_T idx_positive;
    int32_T idx_negative;
    int32_T b_k_oh;
    int32_T ix_k;
    int32_T iac_a;
    int32_T lastv_n;
    int32_T lastc_p;
    int32_T coltop;
    int32_T ia_d;
    int32_T iac_a3;
    int32_T d_ee;
    int32_T jA_m;
    int32_T lastv_f;
    int32_T lastc_h;
    int32_T rowleft;
    int32_T ia_b;
    int32_T iac_f;
    int32_T d_lt;
    int32_T jA_p;
    int32_T ix_nt;
    int32_T kend_i;
    int32_T mIneq_be;
    int32_T b_k_ev;
    int32_T ix_p;
    int32_T b_iy_o;
    int32_T iac_ff;
    int32_T ia_dg;
    int32_T mIneq_i5;
    int32_T b_k_i4;
    int32_T ix_h;
    int32_T b_iy_f;
    int32_T iac_h;
    int32_T ia_l;
    int32_T k_gk;
    int32_T nrows_l;
    int32_T ncols;
    int32_T ibtile;
    int32_T iacol;
    int32_T ibcol_m;
    int32_T b_jtilecol_n;
    int32_T jA_n;
    int32_T jy_l;
    int32_T ix_po;
    int32_T j_ln;
    int32_T c_pg;
    int32_T kend_m;
    int32_T trueCount;
    int32_T e_i_c;
    int32_T mNull_a;
    int32_T ldw;
    int32_T nullStart;
    int32_T b_idx_col_g;
    uint32_T bpIdx;
    uint32_T nbpts;
    boolean_T b_cj[4];
    boolean_T x_ct[3];
    int8_T rtAction;
    uint8_T Data; // '<S9>/BusConversion_InsertedFor_Bus Selector3_at_inport_0'
    uint8_T Sum_l;                     // '<S9>/Sum'
    uint8_T u_m;
    boolean_T Reset;                   // '<S137>/Reset'
    boolean_T SourceBlock_o1;          // '<S134>/SourceBlock'
    boolean_T MATLABSystem_o2;         // '<S113>/MATLAB System'
    boolean_T didZcEventOccur;
    boolean_T SourceBlock_o1_b;        // '<S136>/SourceBlock'
    boolean_T flag;
    boolean_T freelead;
    boolean_T freetail;
    boolean_T empty_non_axis_sizes;
    boolean_T x_data_e;
    SL_Bus_full_loop_std_msgs_Bool b_varargout_2_b;
    SL_Bus_full_loop_std_msgs_Bool BusAssignment;// '<S5>/Bus Assignment'
    SL_Bus_full_loop_std_msgs_UInt8 b_varargout_2_i;
  } B_full_loop_T;

  // Block states (default storage) for system '<Root>'
  typedef struct {
    TrajectoryManager_full_loop_T obj; // '<S113>/MATLAB System'
    AddPose_full_loop_T obj_o;         // '<S113>/MATLAB System1'
    mpcManager_full_loop_T obj_g;      // '<S56>/MATLAB System'
    OpenLoopController_full_loop_T obj_m;// '<S55>/MATLAB System'
    TrajectoryGenerator_full_loop_T obj_c;// '<S127>/MATLAB System2'
    DiscontinuityCheck_full_loop_T obj_l;// '<S87>/MATLAB System2'
    ros_slros_internal_block_Publ_T obj_o5;// '<S53>/SinkBlock'
    ros_slros_internal_block_Publ_T obj_j;// '<S51>/SinkBlock'
    ros_slros_internal_block_Publ_T obj_f;// '<S48>/SinkBlock'
    ros_slros_internal_block_Publ_T obj_f5;// '<S45>/SinkBlock'
    ros_slros_internal_block_Publ_T obj_os;// '<S42>/SinkBlock'
    ros_slros_internal_block_Subs_T obj_i;// '<S136>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_ft;// '<S135>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_iv;// '<S134>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_gw;// '<S125>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_mi;// '<S124>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_b;// '<S123>/SourceBlock'
    ros_slros_internal_block_Subs_T obj_l4;// '<S116>/SourceBlock'
    real_T DiscreteTimeIntegrator_DSTATE[3];// '<S7>/Discrete-Time Integrator'
    real_T Integrator_DSTATE[6];       // '<S119>/Integrator'
    real_T Integrator_DSTATE_h[6];     // '<S120>/Integrator'
    real_T UD_DSTATE[6];               // '<S57>/UD'
    real_T x_Delay_DSTATE[65];         // '<S61>/x_Delay'
    real_T mv_Delay_DSTATE[40];        // '<S61>/mv_Delay'
    real_T slack_delay_DSTATE;         // '<S61>/slack_delay'
    real_T NextOutput;                 // '<S25>/White Noise'
    real_T NextOutput_m;               // '<S24>/White Noise'
    real_T FromMultimediaFile_HostLib[137];// '<S1>/From Multimedia File'
    real_T FromMultimediaFile_AudioInfo[5];// '<S1>/From Multimedia File'
    real_T FromMultimediaFile_VideoInfo[11];// '<S1>/From Multimedia File'
    real_T XDrift_NextOutput;          // '<S13>/X Drift'
    real_T YDrift_NextOutput;          // '<S13>/Y Drift'
    real_T Memory1_PreviousInput[8];   // '<S56>/Memory1'
    uint32_T RandSeed;                 // '<S25>/White Noise'
    uint32_T RandSeed_g;               // '<S24>/White Noise'
    uint32_T m_bpIndex[8];             // '<S6>/N to PWM'
    uint32_T m_bpIndex_f[8];           // '<S12>/ PWM to N'
    uint32_T RandSeed_gl;              // '<S13>/X Drift'
    uint32_T RandSeed_n;               // '<S13>/Y Drift'
    int_T Integrator3_IWORK;           // '<S1>/Integrator3'
    int_T Integrator2_IWORK;           // '<S1>/Integrator2'
    int_T Integrator1_IWORK;           // '<S1>/Integrator1'
    int_T Integrator_IWORK;            // '<S1>/Integrator'
    boolean_T Delay_DSTATE;            // '<S113>/Delay'
    int8_T DiscreteTimeIntegrator_PrevRese;// '<S7>/Discrete-Time Integrator'
    int8_T Integrator_PrevResetState;  // '<S119>/Integrator'
    int8_T Integrator_PrevResetState_l;// '<S120>/Integrator'
    int8_T SwitchCase_ActiveSubsystem; // '<S8>/Switch Case'
    int8_T SwitchCase_ActiveSubsystem_c;// '<S6>/Switch Case'
    int8_T If_ActiveSubsystem;         // '<S106>/If'
    uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S7>/Discrete-Time Integrator'
    uint8_T AudioDeviceWriter_AudioDeviceLi[1096];// '<S1>/Audio Device Writer'
    uint8_T icLoad;                    // '<S61>/x_Delay'
    uint8_T icLoad_a;                  // '<S61>/mv_Delay'
    uint8_T icLoad_c;                  // '<S61>/slack_delay'
    boolean_T Memory_PreviousInput;    // '<S137>/Memory'
    boolean_T ROSOutput_MODE;          // '<Root>/ROS Output'
  } DW_full_loop_T;

  // Continuous states (default storage)
  typedef struct {
    real_T Integrator3_CSTATE[3];      // '<S1>/Integrator3'
    real_T Integrator2_CSTATE[3];      // '<S1>/Integrator2'
    real_T Integrator1_CSTATE[4];      // '<S1>/Integrator1'
    real_T Integrator_CSTATE[3];       // '<S1>/Integrator'
    real_T TransferFcn_CSTATE;         // '<S16>/Transfer Fcn'
    real_T TransferFcn_CSTATE_g;       // '<S17>/Transfer Fcn'
    real_T TransferFcn_CSTATE_p;       // '<S18>/Transfer Fcn'
    real_T TransferFcn_CSTATE_k;       // '<S19>/Transfer Fcn'
    real_T TransferFcn_CSTATE_e;       // '<S20>/Transfer Fcn'
    real_T TransferFcn_CSTATE_kk;      // '<S21>/Transfer Fcn'
    real_T TransferFcn_CSTATE_o;       // '<S22>/Transfer Fcn'
    real_T TransferFcn_CSTATE_l;       // '<S23>/Transfer Fcn'
    real_T TransferFcn1_CSTATE[2];     // '<S8>/Transfer Fcn1'
  } X_full_loop_T;

  // State derivatives (default storage)
  typedef struct {
    real_T Integrator3_CSTATE[3];      // '<S1>/Integrator3'
    real_T Integrator2_CSTATE[3];      // '<S1>/Integrator2'
    real_T Integrator1_CSTATE[4];      // '<S1>/Integrator1'
    real_T Integrator_CSTATE[3];       // '<S1>/Integrator'
    real_T TransferFcn_CSTATE;         // '<S16>/Transfer Fcn'
    real_T TransferFcn_CSTATE_g;       // '<S17>/Transfer Fcn'
    real_T TransferFcn_CSTATE_p;       // '<S18>/Transfer Fcn'
    real_T TransferFcn_CSTATE_k;       // '<S19>/Transfer Fcn'
    real_T TransferFcn_CSTATE_e;       // '<S20>/Transfer Fcn'
    real_T TransferFcn_CSTATE_kk;      // '<S21>/Transfer Fcn'
    real_T TransferFcn_CSTATE_o;       // '<S22>/Transfer Fcn'
    real_T TransferFcn_CSTATE_l;       // '<S23>/Transfer Fcn'
    real_T TransferFcn1_CSTATE[2];     // '<S8>/Transfer Fcn1'
  } XDot_full_loop_T;

  // State disabled
  typedef struct {
    boolean_T Integrator3_CSTATE[3];   // '<S1>/Integrator3'
    boolean_T Integrator2_CSTATE[3];   // '<S1>/Integrator2'
    boolean_T Integrator1_CSTATE[4];   // '<S1>/Integrator1'
    boolean_T Integrator_CSTATE[3];    // '<S1>/Integrator'
    boolean_T TransferFcn_CSTATE;      // '<S16>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_g;    // '<S17>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_p;    // '<S18>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_k;    // '<S19>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_e;    // '<S20>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_kk;   // '<S21>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_o;    // '<S22>/Transfer Fcn'
    boolean_T TransferFcn_CSTATE_l;    // '<S23>/Transfer Fcn'
    boolean_T TransferFcn1_CSTATE[2];  // '<S8>/Transfer Fcn1'
  } XDis_full_loop_T;

  // Zero-crossing (trigger) state
  typedef struct {
    ZCSigState Integrator3_Reset_ZCE;  // '<S1>/Integrator3'
    ZCSigState Integrator2_Reset_ZCE;  // '<S1>/Integrator2'
    ZCSigState Integrator1_Reset_ZCE;  // '<S1>/Integrator1'
    ZCSigState Integrator_Reset_ZCE;   // '<S1>/Integrator'
    ZCSigState Subsystem2_Trig_ZCE;    // '<S113>/Subsystem2'
    ZCSigState SendTargetReached_Trig_ZCE;// '<Root>/Send Target Reached '
  } PrevZCX_full_loop_T;

  // Invariant block signals (default storage)
  typedef const struct tag_ConstB_full_loop_T {
    real_T InitialAngularRates[3];     // '<S1>/Initial Angular Rates'
    real_T InitialBodyvelocity[3];     // '<S1>/Initial Body velocity '
    real_T u2[3];                      // '<S28>/1//2'
    real_T sincos_o1[3];               // '<S28>/sincos'
    real_T sincos_o2[3];               // '<S28>/sincos'
    real_T q0;                         // '<S28>/q0'
    real_T Product;                    // '<S36>/Product'
    real_T q1;                         // '<S28>/q1'
    real_T Product1;                   // '<S36>/Product1'
    real_T q2;                         // '<S28>/q2'
    real_T Product2;                   // '<S36>/Product2'
    real_T q3;                         // '<S28>/q3'
    real_T Product3;                   // '<S36>/Product3'
    real_T Sum;                        // '<S36>/Sum'
    real_T sqrt_e;                     // '<S35>/sqrt'
    real_T Product_k;                  // '<S31>/Product'
    real_T Product1_n;                 // '<S31>/Product1'
    real_T Product2_h;                 // '<S31>/Product2'
    real_T Product3_l;                 // '<S31>/Product3'
    real_T Product_c;                  // '<S32>/Product'
    real_T Product1_d;                 // '<S32>/Product1'
    real_T Sum1;                       // '<S32>/Sum1'
    real_T Gain;                       // '<S32>/Gain'
    real_T Product2_k;                 // '<S32>/Product2'
    real_T Product3_g;                 // '<S32>/Product3'
    real_T Sum2;                       // '<S32>/Sum2'
    real_T Gain1;                      // '<S32>/Gain1'
    real_T Product6;                   // '<S32>/Product6'
    real_T Product7;                   // '<S32>/Product7'
    real_T Sum3;                       // '<S32>/Sum3'
    real_T Gain2;                      // '<S32>/Gain2'
    real_T Product_b;                  // '<S33>/Product'
    real_T Product1_e;                 // '<S33>/Product1'
    real_T Sum1_g;                     // '<S33>/Sum1'
    real_T Gain_e;                     // '<S33>/Gain'
    real_T Product2_p;                 // '<S33>/Product2'
    real_T Product3_j;                 // '<S33>/Product3'
    real_T Sum2_n;                     // '<S33>/Sum2'
    real_T Gain1_b;                    // '<S33>/Gain1'
    real_T Product6_j;                 // '<S33>/Product6'
    real_T Product7_m;                 // '<S33>/Product7'
    real_T Sum3_g;                     // '<S33>/Sum3'
    real_T Gain2_d;                    // '<S33>/Gain2'
    real_T Product_p;                  // '<S34>/Product'
    real_T Product1_nr;                // '<S34>/Product1'
    real_T Sum1_l;                     // '<S34>/Sum1'
    real_T Gain_n;                     // '<S34>/Gain'
    real_T Product2_g;                 // '<S34>/Product2'
    real_T Product3_m;                 // '<S34>/Product3'
    real_T Sum2_g;                     // '<S34>/Sum2'
    real_T Gain1_l;                    // '<S34>/Gain1'
    real_T Product6_e;                 // '<S34>/Product6'
    real_T Product7_b;                 // '<S34>/Product7'
    real_T Sum3_i;                     // '<S34>/Sum3'
    real_T Gain2_m;                    // '<S34>/Gain2'
  } ConstB_full_loop_T;

  // Constant parameters (default storage)
  typedef struct {
    // Expression: Config10
    //  Referenced by: '<S56>/MATLAB System'

    real_T MATLABSystem_Config10[29];

    // Expression: Config19
    //  Referenced by: '<S56>/MATLAB System'

    real_T MATLABSystem_Config19[29];

    // Expression: ones( 1, 8 )*mpc.tmin
    //  Referenced by: '<S56>/MATLAB System'

    real_T MATLABSystem_Tmin[8];

    // Expression: ones( 1, 8 )*mpc.tmax
    //  Referenced by: '<S56>/MATLAB System'

    real_T MATLABSystem_Tmax[8];

    // Expression: constValues
    //  Referenced by: '<S56>/MATLAB System'

    real_T MATLABSystem_MecConst[41];

    // Expression: binv
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_binv[48];

    // Expression: physics.I
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_I[9];

    // Expression: physics.RG
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_RG[3];

    // Expression: physics.RB
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_RB[3];

    // Expression: physics.AddedMass
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_AddedMass[6];

    // Expression: physics.CDL
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_CDL[6];

    // Expression: physics.CDQ
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_CDQ[6];

    // Expression: physics.AF
    //  Referenced by: '<S55>/MATLAB System'

    real_T MATLABSystem_AF[3];

    // Expression: [1 1 .3 .1 .1 .1 .1]
    //  Referenced by: '<S127>/MATLAB System2'

    real_T MATLABSystem2_avanceRapide[7];

    // Expression: [.3 .3 .1 .05 .05 .05 .05]
    //  Referenced by: '<S127>/MATLAB System2'

    real_T MATLABSystem2_avancePrecision[7];

    // Expression: [0.2 0.2 0.1 .02 .02 .02 .02];
    //  Referenced by: '<S127>/MATLAB System2'

    real_T MATLABSystem2_accRapide[7];

    // Pooled Parameter (Expression: N)
    //  Referenced by:
    //    '<S6>/N to PWM'
    //    '<S12>/ PWM to N'

    real_T pooled21[201];

    // Pooled Parameter (Expression: PWM)
    //  Referenced by:
    //    '<S6>/N to PWM'
    //    '<S12>/ PWM to N'

    uint16_T pooled27[201];

    // Expression: simulation.reference_frame
    //  Referenced by: '<S39>/  '

    uint8_T _Value_n[5];
  } ConstP_full_loop_T;

  // Real-time Model Data Structure
  struct RT_MODEL_full_loop_T {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
    X_full_loop_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[23];
    real_T odeF[3][23];
    ODE3_IntgData intgData;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      int_T numContStates;
      int_T numPeriodicContStates;
      int_T numSampTimes;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      boolean_T firstInitCondFlag;
      struct {
        uint16_T TID[6];
      } TaskCounters;

      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[6];
    } Timing;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  full_loopModelClass();

  // Destructor
  ~full_loopModelClass();

  // Real-Time Model get method
  full_loopModelClass::RT_MODEL_full_loop_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_full_loop_T full_loop_B;

  // Block states
  DW_full_loop_T full_loop_DW;
  X_full_loop_T full_loop_X;           // Block continuous states
  PrevZCX_full_loop_T full_loop_PrevZCX;// Triggered events

  // Real-Time Model
  RT_MODEL_full_loop_T full_loop_M;

  // private member function(s) for subsystem '<Root>'
  void full_loop_quatmultiply(const real_T q[4], const real_T r[4], real_T qout
    [4]);
  boolean_T full_loop_isequal_p43r(const real_T varargin_1[7], const real_T
    varargin_2[7]);
  void full__quaternioncg_quaternioncg(const real_T varargin_1[84], real_T
    obj_a[21], real_T obj_b[21], real_T obj_c[21], real_T obj_d[21]);
  void waypointTrajectory_setPropertie(waypointTrajectory_full_loop_T *obj,
    const real_T varargin_1[63], const real_T varargin_2[21], real_T varargin_4,
    const real_T varargin_8_a[21], const real_T varargin_8_b[21], const real_T
    varargin_8_c[21], const real_T varargin_8_d[21]);
  boolean_T full_loop_isequal_p43ri(const real_T varargin_1[2], const real_T
    varargin_2[2]);
  void full_loop_pol2cart_p(real_T th[2], const real_T r[2], real_T x[2]);
  void full_loop_endpointpadding_p4(const creal_T zcurrent_data[], const int32_T
    zcurrent_size[2], const creal_T varargin_1[2], creal_T *zleft, creal_T
    *zright);
  void full_loop_diff(const creal_T x_data[], const int32_T x_size[2], creal_T
                      y_data[], int32_T y_size[2]);
  real_T full_loop_rt_hypotd_snf(real_T u0, real_T u1);
  void full_loop_abs(const creal_T x_data[], const int32_T x_size[2], real_T
                     y_data[], int32_T y_size[2]);
  void full_loop_angle(const creal_T x_data[], const int32_T x_size[2], real_T
                       y_data[], int32_T y_size[2]);
  boolean_T full_loop_isnan(const creal_T x);
  void full_loop_tan(const real_T x_data[], const int32_T x_size[2], real_T
                     b_x_data[], int32_T b_x_size[2]);
  void full_loop_midcurve(const creal_T Pb_data[], const int32_T Pb_size[2],
    const creal_T Vbd_data[], const real_T Lab_data[], const int32_T Lab_size[2],
    const real_T Lbd_data[], const int32_T Lbd_size[2], const real_T Lde_data[],
    const int32_T Lde_size[2], const real_T alpha_data[], const real_T
    beta_data[], creal_T Pc_data[], int32_T Pc_size[2]);
  void full_loop_insertCodegen_p(const creal_T zorig_data[], real_T m, real_T
    nmax, const creal_T varargin_1[2], creal_T Zout_data[], int32_T Zout_size[2]);
  void full_loop_optimize_p(const creal_T zcurrent_data[], const int32_T
    zcurrent_size[2], const creal_T zorig_data[], const int32_T zorig_size[2],
    const creal_T varargin_1[2], creal_T Zout_data[], int32_T Zout_size[2]);
  void full_loop_cloth_p(const creal_T z_data[], const int32_T *z_size, const
    creal_T varargin_1[2], real_T r_data[], int32_T r_size[2], real_T s_data[],
    int32_T s_size[2]);
  void full_loop_packageCodegen_p(const real_T r_data[], const real_T s_data[],
    real_T n, real_T u_data[], int32_T *u_size, real_T v_data[], int32_T *v_size);
  void full_loop_dclothoidwp_p(const real_T x_data[], const int32_T *x_size,
    const real_T y_data[], const real_T varargin_1[2], const real_T varargin_2[2],
    real_T u_data[], int32_T *u_size, real_T v_data[], int32_T *v_size);
  void full_loop_angle_p(const creal_T x_data[], const int32_T *x_size, real_T
    y_data[], int32_T *y_size);
  void full_loop_exp_p(creal_T x_data[], const int32_T *x_size);
  real_T full_loop_rt_powd_snf(real_T u0, real_T u1);
  void full_loop_power_p(const real_T a_data[], const int32_T *a_size, real_T
    y_data[], int32_T *y_size);
  void full_loop_repmat_p(const real_T a_data[], const int32_T *a_size, real_T
    b_data[], int32_T b_size[2]);
  void full_loop_fetchAgrad_p(const real_T x_data[], const int32_T *x_size,
    const real_T y_data[], real_T a_data[], int32_T *a_size, real_T dadx_data[],
    int32_T *dadx_size, real_T dady_data[], int32_T *dady_size);
  void full_loop_abs_p(const real_T x_data[], const int32_T *x_size, real_T
                       y_data[], int32_T *y_size);
  creal_T full_loop_sqrt_p(const creal_T x);
  void full_loop_sqrt_p43(creal_T x_data[], const int32_T *x_size);
  void full_loop_fresnelr(const real_T x_data[], const int32_T *x_size, creal_T
    z_data[], int32_T *z_size);
  void full_loop_fresnel(const creal_T x_data[], const int32_T *x_size, creal_T
    z_data[], int32_T *z_size);
  void full_loop_power_p4(const creal_T a_data[], const int32_T *a_size, creal_T
    y_data[], int32_T *y_size);
  void full_loop_sign_p(real_T x_data[], const int32_T *x_size);
  void full_loop_power_p43(const creal_T a_data[], const int32_T *a_size,
    creal_T y_data[], int32_T *y_size);
  void full_loop_fresnelgLargea1(const real_T a_data[], const int32_T *a_size,
    const real_T d_data[], const int32_T *d_size, const real_T c_data[], const
    int32_T *c_size, creal_T rsfa_data[], int32_T *rsfa_size, creal_T
    drsfa_data[], int32_T *drsfa_size);
  void full_loop_power_p43r(const real_T a_data[], const int32_T *a_size, real_T
    y_data[], int32_T *y_size);
  void full_loop_fresnelgSmalla1(const real_T a_data[], const int32_T *a_size,
    const real_T d_data[], const int32_T *d_size, const real_T c_data[], const
    int32_T *c_size, creal_T z_data[], int32_T *z_size, creal_T dz_data[],
    int32_T *dz_size);
  void full_loop_fresnelg1_p(const real_T a_data[], const int32_T *a_size, const
    real_T d_data[], const int32_T *d_size, const real_T c_data[], creal_T
    z_data[], int32_T *z_size, creal_T dz_data[], int32_T *dz_size);
  void full_loop_abs_p4(const creal_T x_data[], const int32_T *x_size, real_T
                        y_data[], int32_T *y_size);
  void full_loop_clothoidG1fit2wp_p(const creal_T z0_data[], const real_T
    theta0_data[], const int32_T *theta0_size, const creal_T z1_data[], const
    int32_T *z1_size, const real_T theta1_data[], const int32_T *theta1_size,
    real_T k0_data[], int32_T *k0_size, real_T k1_data[], int32_T *k1_size,
    real_T l_data[], int32_T *l_size, real_T dk0_dtheta0_data[], int32_T
    *dk0_dtheta0_size, real_T dk0_dtheta1_data[], int32_T *dk0_dtheta1_size,
    real_T dk1_dtheta0_data[], int32_T *dk1_dtheta0_size, real_T
    dk1_dtheta1_data[], int32_T *dk1_dtheta1_size);
  void full_loop___anon_fcn_p43(const real_T waypoints_data[], const int32_T
    waypoints_size[2], const real_T course_data[], const int32_T *course_size,
    const real_T x_data[], real_T varargout_1_data[], int32_T *varargout_1_size,
    real_T varargout_2_data[], int32_T varargout_2_size[2]);
  void full_loop_mulJt_p(const real_T Jtri_data[], const int32_T Jtri_size[2],
    const real_T x_data[], const int32_T *x_size, real_T y_data[], int32_T
    *y_size);
  void full_loop_repmat_p4(real_T varargin_1, real_T b_data[], int32_T *b_size);
  boolean_T full_loop_any_p4(const boolean_T x_data[], const int32_T *x_size);
  void full_loop_bsxfun(const real_T a_data[], const int32_T a_size[2], const
                        real_T b_data[], const int32_T *b_size, real_T c_data[],
                        int32_T c_size[2]);
  void full_loop_sympentdisolve_p4(const real_T d_data[], const real_T e_data[],
    const real_T f_data[], const real_T b_data[], const int32_T b_size[2],
    real_T x_data[], int32_T x_size[2]);
  void full_loop_eye_p(real_T b_I[16]);
  void full_loop_mldivide_p4(const real_T A[16], real_T B[4]);
  void full_loop_cycsympentdisolve_p(const real_T d_data[], const real_T e_data[],
    const real_T f_data[], const real_T b_data[], const int32_T *b_size, real_T
    x_data[], int32_T *x_size);
  void full_loop_sympentdisolve_p(const real_T d_data[], const real_T e_data[],
    const real_T f_data[], const real_T b_data[], const int32_T *b_size, real_T
    x_data[], int32_T *x_size);
  void full_loop_AccumArrayScalarVal(const real_T subs_data[], const int32_T
    subs_size[2], real_T val, const int32_T sz[2], real_T A_data[], int32_T
    A_size[2]);
  void full_loop_accumarray_p(const real_T subs_data[], const int32_T subs_size
    [2], const real_T val_data[], const int32_T *val_size, const real_T sz[2],
    real_T A_data[], int32_T A_size[2]);
  void full_loop_diag_p(const real_T v_data[], const int32_T v_size[2], real_T
                        d_data[], int32_T *d_size);
  void full_loop_diag_p4(const real_T v_data[], const int32_T *v_size, real_T
    d_data[], int32_T d_size[2]);
  real_T full_loop_xnrm2_p43(int32_T n, const real_T x_data[], int32_T ix0);
  int32_T full_loop_ixamax_p(int32_T n, const real_T x_data[], int32_T ix0);
  void full_loop_xswap_p(int32_T n, const real_T x_data[], const int32_T x_size
    [2], int32_T ix0, int32_T iy0, real_T b_x_data[], int32_T b_x_size[2]);
  void full_loop_xzlarfg_p43(int32_T n, real_T alpha1, const real_T x_data[],
    const int32_T x_size[2], int32_T ix0, real_T *b_alpha1, real_T b_x_data[],
    int32_T b_x_size[2], real_T *tau);
  void full_loop_ilazlc_p(int32_T m, int32_T n, const real_T A_data[], const
    int32_T A_size[2], int32_T ia0, int32_T lda, int32_T *j, real_T b_A_data[],
    int32_T b_A_size[2]);
  void full_loop_xgemv_p(int32_T m, int32_T n, const real_T A_data[], int32_T
    ia0, int32_T lda, const real_T x_data[], int32_T ix0, const real_T y_data[],
    const int32_T *y_size, real_T b_y_data[], int32_T *b_y_size);
  void full_loop_xgerc_p(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
    real_T y_data[], const real_T A_data[], const int32_T A_size[2], int32_T ia0,
    int32_T lda, real_T b_A_data[], int32_T b_A_size[2]);
  void full_loop_xzlarf_p43riobt(int32_T m, int32_T n, int32_T iv0, real_T tau,
    const real_T C_data[], const int32_T C_size[2], int32_T ic0, int32_T ldc,
    real_T work_data[], int32_T *work_size, real_T b_C_data[], int32_T b_C_size
    [2]);
  void full_loop_qrpf_p4(const real_T A_data[], const int32_T A_size[2], int32_T
    m, int32_T n, real_T tau_data[], const int32_T jpvt_data[], const int32_T
    jpvt_size[2], real_T b_A_data[], int32_T b_A_size[2], int32_T b_jpvt_data[],
    int32_T b_jpvt_size[2]);
  void full_loop_lusolve_p(const real_T A_data[], const int32_T A_size[2],
    real_T B_data[], const int32_T *B_size);
  void full_loop_mldivide_p(const real_T A_data[], const int32_T A_size[2],
    const real_T B_data[], const int32_T *B_size, real_T Y_data[], int32_T
    *Y_size);
  void full_loo_solveDampenedHessian_p(const real_T Jtri_data[], const int32_T
    Jtri_size[2], real_T lambda, const real_T v_data[], const int32_T *v_size,
    real_T dx_data[], int32_T *dx_size);
  void full_loop_mulJtJ(const real_T Jtri_data[], const int32_T Jtri_size[2],
                        const real_T x_data[], const int32_T *x_size, real_T
                        y_data[], int32_T *y_size);
  real_T full_loop_norm_p4(const real_T x_data[], const int32_T *x_size);
  void full_loop_tridisolve(const real_T a_data[], real_T b_data[], const real_T
    c_data[], const real_T d_data[], const int32_T *d_size, real_T x_data[],
    int32_T *x_size);
  void full_loop_cyctridisolve_p(const real_T a_data[], real_T b_data[], const
    int32_T *b_size, const real_T c_data[], const real_T d_data[], const int32_T
    *d_size, real_T x_data[], int32_T *x_size);
  void full_loop_solveHessian_p(const real_T Jtri_data[], const int32_T
    Jtri_size[2], const real_T v_data[], const int32_T *v_size, real_T dx_data[],
    int32_T *dx_size);
  boolean_T full_loop_anyNonFinite(const real_T x_data[], const int32_T x_size[2]);
  boolean_T full_loop_ishermitian(const real_T A_data[], const int32_T A_size[2]);
  real_T full_loop_xzlangeM_p(const creal_T x_data[], const int32_T x_size[2]);
  boolean_T full_loop_isfinite_p(real_T x);
  void full_loop_xzlascl_p4(real_T cfrom, real_T cto, const creal_T A_data[],
    const int32_T A_size[2], creal_T b_A_data[], int32_T b_A_size[2]);
  void full_loop_xzggbal_p(const creal_T A_data[], const int32_T A_size[2],
    creal_T b_A_data[], int32_T b_A_size[2], int32_T *ilo, int32_T *ihi, int32_T
    rscale_data[], int32_T *rscale_size);
  void full_loop_xzlartg(const creal_T f, const creal_T g, real_T *cs, creal_T
    *sn, creal_T *r);
  void full_loop_xzgghrd_p(int32_T ilo, int32_T ihi, const creal_T A_data[],
    const int32_T A_size[2], creal_T b_A_data[], int32_T b_A_size[2]);
  real_T full_loop_xzlanhs_p(const creal_T A_data[], const int32_T A_size[2],
    int32_T ilo, int32_T ihi);
  int32_T full_loop_mod_p(int32_T x);
  void full_loop_xzlartg_p(const creal_T f, const creal_T g, real_T *cs, creal_T
    *sn);
  void full_loop_xzhgeqz_p(const creal_T A_data[], const int32_T A_size[2],
    int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[], int32_T
    *alpha1_size, creal_T beta1_data[], int32_T *beta1_size);
  void full_loop_xzlascl_p43ri(real_T cfrom, real_T cto, creal_T A_data[], const
    int32_T *A_size);
  void full_loop_xzgeev_p(const real_T A_data[], const int32_T A_size[2],
    int32_T *info, creal_T alpha1_data[], int32_T *alpha1_size, creal_T
    beta1_data[], int32_T *beta1_size);
  void full_loop_ilazlr(int32_T m, int32_T n, const real_T A_data[], const
                        int32_T A_size[2], int32_T ia0, int32_T lda, int32_T *i,
                        real_T b_A_data[], int32_T b_A_size[2]);
  void full_loop_xgemv_p43r(int32_T m, int32_T n, const real_T A_data[], int32_T
    ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
  void full_loop_xgerc_p4(int32_T m, int32_T n, real_T alpha1, const real_T
    x_data[], int32_T iy0, const real_T A_data[], const int32_T A_size[2],
    int32_T ia0, int32_T lda, real_T b_A_data[], int32_T b_A_size[2]);
  void full_loop_xzlarf_p43riobte(int32_T m, int32_T n, int32_T iv0, real_T tau,
    const real_T C_data[], const int32_T C_size[2], int32_T ic0, int32_T ldc,
    real_T work_data[], real_T b_C_data[], int32_T b_C_size[2]);
  void full_loop_xgemv_p43ri(int32_T m, int32_T n, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
  void full_loop_xgerc_p43(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
    const real_T y_data[], const real_T A_data[], const int32_T A_size[2],
    int32_T ia0, int32_T lda, real_T b_A_data[], int32_T b_A_size[2]);
  void full_loop_xzlarf_p43riobte0(int32_T m, int32_T n, int32_T iv0, real_T tau,
    const real_T C_data[], const int32_T C_size[2], int32_T ic0, int32_T ldc,
    real_T work_data[], real_T b_C_data[], int32_T b_C_size[2]);
  void full_loop_xgehrd_p(const real_T a_data[], const int32_T a_size[2], real_T
    b_a_data[], int32_T b_a_size[2]);
  real_T full_loop_xnrm2_p4(int32_T n, const real_T x[3]);
  void full_loop_xzlarfg_p43r(int32_T n, real_T alpha1, real_T x[3], real_T
    *b_alpha1, real_T *tau);
  void full_loop_xdlanv2(real_T a, real_T b, real_T c, real_T d, real_T *rt1r,
    real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *b_a, real_T *b_b, real_T
    *b_c, real_T *b_d, real_T *cs, real_T *sn);
  void full_loop_xrot_p4(int32_T n, const real_T x_data[], const int32_T x_size
    [2], int32_T ix0, int32_T incx, int32_T iy0, int32_T incy, real_T c, real_T
    s, real_T b_x_data[], int32_T b_x_size[2]);
  void full_loop_xrot_p43(int32_T n, const real_T x_data[], const int32_T
    x_size[2], int32_T ix0, int32_T iy0, real_T c, real_T s, real_T b_x_data[],
    int32_T b_x_size[2]);
  void full_loop_eml_dlahqr_p(const real_T h_data[], const int32_T h_size[2],
    real_T b_h_data[], int32_T b_h_size[2], int32_T *info);
  void full_loop_xhseqr_p(const real_T h_data[], const int32_T h_size[2], real_T
    b_h_data[], int32_T b_h_size[2], int32_T *info);
  void full_loop_triu(const real_T x_data[], const int32_T x_size[2], real_T
                      b_x_data[], int32_T b_x_size[2]);
  void full_loop_schur_p(real_T A_data[], int32_T A_size[2], real_T V_data[],
    int32_T V_size[2]);
  void full_loop_mainDiagZeroImag(const real_T D_data[], const int32_T D_size[2],
    real_T d_data[], int32_T *d_size);
  void full_loop_eig_p(const real_T A_data[], const int32_T A_size[2], creal_T
                       V_data[], int32_T *V_size);
  real_T full_loop_leastEigvJtJ_p(const real_T Jtri_data[], const int32_T
    Jtri_size[2], real_T n);
  void full_loop_fletcher_p(real_T S, real_T Snew, const real_T dx_data[], const
    int32_T *dx_size, const real_T v_data[], const real_T Jtri_data[], const
    int32_T Jtri_size[2], real_T lambda, real_T lambdac, real_T *b_lambda,
    real_T *b_lambdac);
  void full_loop_LMFsolve_p43riobte(const real_T FUN_tunableEnvironment_f1_data[],
    const int32_T FUN_tunableEnvironment_f1_size[2], const real_T
    FUN_tunableEnvironment_f2_data[], const int32_T
    *FUN_tunableEnvironment_f2_size, real_T x_data[], const int32_T *x_size);
  void full_loop___anon_fcn_p4(const real_T waypoints_data[], const int32_T
    waypoints_size[2], const real_T course_data[], const int32_T *course_size,
    const real_T x_data[], real_T varargout_1_data[], int32_T *varargout_1_size,
    real_T varargout_2_data[], int32_T varargout_2_size[2]);
  void full_loop_LMFsolve_p43riobt(const real_T FUN_tunableEnvironment_f1_data[],
    const int32_T FUN_tunableEnvironment_f1_size[2], const real_T
    FUN_tunableEnvironment_f2_data[], const int32_T
    *FUN_tunableEnvironment_f2_size, real_T x_data[], const int32_T *x_size);
  void full_loop___anon_fcn_p(const real_T waypoints_data[], const int32_T
    waypoints_size[2], const real_T course_data[], const int32_T *course_size,
    const real_T x_data[], real_T varargout_1_data[], int32_T *varargout_1_size,
    real_T varargout_2_data[], int32_T varargout_2_size[2]);
  void full_loop_LMFsolve_p43riob(const real_T FUN_tunableEnvironment_f1_data[],
    const int32_T FUN_tunableEnvironment_f1_size[2], const real_T
    FUN_tunableEnvironment_f2_data[], const int32_T
    *FUN_tunableEnvironment_f2_size, real_T x_data[], const int32_T *x_size);
  void full_loop_LMFsolve_p43rio(const f_cell_wrap_full_loop_T
    *FUN_tunableEnvironment, real_T x_data[], const int32_T *x_size);
  void full_loop_fitCourse_p(const real_T waypoints_data[], const int32_T
    waypoints_size[2], real_T course_data[], int32_T *course_size);
  void full_loop_fitPartialCourse(const real_T waypoints[63], real_T course[21]);
  void full_loop_partitionCourse(const real_T course[21], real_T ibegin_data[],
    int32_T *ibegin_size, real_T iend_data[], int32_T *iend_size);
  void full_loop_endpointpadding(const creal_T zcurrent_data[], const int32_T
    zcurrent_size[2], const creal_T zorig_data[], const int32_T zorig_size[2],
    creal_T *zleft, creal_T *zright);
  void full_loop_insertCodegen(const creal_T zorig[2561], real_T m, creal_T
    Zout_data[], int32_T Zout_size[2]);
  void full_loop_endpointpadding_p(const creal_T zcurrent_data[], const int32_T
    zcurrent_size[2], const creal_T zorig[21], creal_T *zleft, creal_T *zright);
  void full_loop_optimize(const creal_T zcurrent_data[], const int32_T
    zcurrent_size[2], const creal_T zorig[21], creal_T Zout_data[], int32_T
    Zout_size[2]);
  void full_loop_cloth(const creal_T z[21], real_T r[2561], real_T s[2561]);
  void full_loop_packageCodegen(const real_T r[2561], const real_T s[2561],
    real_T u[2561], real_T v[2561]);
  void full_loop_dclothoidwp(const real_T x[21], const real_T y[21], real_T u
    [2561], real_T v[2561]);
  void full_loop_power(const real_T a[20], real_T y[20]);
  void full_loop_repmat(const real_T a[20], real_T b[500]);
  void full_loop_fetchAgrad(const real_T x[20], const real_T y[20], real_T a[20],
    real_T dadx[20], real_T dady[20]);
  void full_loop_fresnelg1(const real_T a[20], const real_T d[20], const real_T
    c[20], creal_T z[20], creal_T dz[20]);
  void full_loop_clothoidG1fit2wp(const creal_T z0[20], const real_T theta0[20],
    const creal_T z1[20], const real_T theta1[20], real_T k0[20], real_T k1[20],
    real_T l[20], real_T dk0_dtheta0[20], real_T dk0_dtheta1[20], real_T
    dk1_dtheta0[20], real_T dk1_dtheta1[20]);
  void full_loop_mulJt(const real_T Jtri[60], const real_T x[20], real_T y[20]);
  boolean_T full_loop_any_p(const boolean_T x[20]);
  void full_loop_sympentdisolve(const real_T d[20], const real_T e[20], const
    real_T f[20], const real_T b[100], real_T x[100]);
  void full_loop_cycsympentdisolve(const real_T d[20], const real_T e[20], const
    real_T f[20], const real_T b[20], real_T x[20]);
  void full_loop_solveDampenedHessian(const real_T Jtri[60], real_T lambda,
    const real_T v[20], real_T dx[20]);
  void full_loop_cyctridisolve_p4(const real_T a[20], real_T b[20], const real_T
    c[20], real_T d[20]);
  void full_loop_solveHessian_p4(const real_T Jtri[60], real_T v[20]);
  real_T full_loop_norm_p(const real_T x[20]);
  void full_loop_accumarray(const real_T val[58], real_T A[400]);
  real_T full_loop_xzlangeM(const creal_T x[400]);
  void full_loop_xzlascl(real_T cfrom, real_T cto, const creal_T A[400], creal_T
    b_A[400]);
  void full_loop_xzggbal(const creal_T A[400], creal_T b_A[400], int32_T *ilo,
    int32_T *ihi, int32_T rscale[20]);
  void full_loop_xzgghrd(int32_T ilo, int32_T ihi, const creal_T A[400], creal_T
    b_A[400]);
  real_T full_loop_xzlanhs(const creal_T A[400], int32_T ilo, int32_T ihi);
  void full_loop_xzhgeqz(const creal_T A[400], int32_T ilo, int32_T ihi, int32_T
    *info, creal_T alpha1[20], creal_T beta1[20]);
  void full_loop_xzlascl_p43r(real_T cfrom, real_T cto, creal_T A[20]);
  void full_loop_xzgeev(const real_T A[400], int32_T *info, creal_T alpha1[20],
                        creal_T beta1[20]);
  real_T full_loop_xnrm2_p(int32_T n, const real_T x[400], int32_T ix0);
  void full_loop_xzlarfg_p(int32_T n, real_T alpha1, const real_T x[400],
    int32_T ix0, real_T *b_alpha1, real_T b_x[400], real_T *tau);
  void full_loop_xzlarf_p43rio(int32_T n, int32_T iv0, real_T tau, const real_T
    C[400], int32_T ic0, real_T work[20], real_T b_C[400]);
  void full_loop_xzlarf_p43riob(int32_T m, int32_T n, int32_T iv0, real_T tau,
    const real_T C[400], int32_T ic0, real_T work[20], real_T b_C[400]);
  void full_loop_xgehrd(const real_T a[400], real_T b_a[400]);
  void full_loop_xrot_p(int32_T n, const real_T x[400], int32_T ix0, int32_T iy0,
                        real_T c, real_T s, real_T b_x[400]);
  void full_loop_eml_dlahqr(const real_T h[400], real_T b_h[400], int32_T *info);
  void full_loop_xhseqr(const real_T h[400], real_T b_h[400], int32_T *info);
  void full_loop_schur(real_T A[400], real_T V[400]);
  void full_loop_eig(const real_T A[400], creal_T V[20]);
  real_T full_loop_leastEigvJtJ(const real_T Jtri[60]);
  void full_loop_fletcher(real_T S, real_T Snew, const real_T dx[20], const
    real_T v[20], const real_T Jtri[60], real_T lambda, real_T lambdac, real_T
    *b_lambda, real_T *b_lambdac);
  void full_loop_LMFsolve_p43ri(const d_cell_wrap_full_loop_T
    *FUN_tunableEnvironment, real_T x[20]);
  void full_loop_fitLoopCourse(const real_T waypoints[63], real_T course[21]);
  void full_loop_fitPartialCourseLoop(const real_T waypoints[63], real_T course
    [21]);
  void full_clothoidG2fitMissingCourse(const real_T waypoints[63], real_T
    course[21]);
  void full_loop_fetchA(const real_T x[20], const real_T y[20], real_T a[20]);
  void full_loop_fresnelg1_p4(const real_T a[20], const real_T d[20], const
    real_T c[20], creal_T z[20]);
  void full_loop_clothoidG1fit2wp_p4(const creal_T z0[20], const real_T theta0
    [20], const creal_T z1[20], const real_T theta1[20], real_T k0[20], real_T
    k1[20], real_T l[20]);
  void full_loop_pchip(const real_T x[21], const real_T y[21], real_T v_breaks
                       [21], real_T v_coefs[80]);
  void full_loop_repmat_p43(real_T b[80]);
  void full_loop_circshift(const real_T a[80], real_T b_a[80]);
  void full_loop_derivpp(const real_T pp_breaks[21], const real_T pp_coefs[80],
    real_T dpp_breaks[21], real_T dpp_coefs[80]);
  void waypointTrajectory_setupPositio(waypointTrajectory_full_loop_T *obj);
  void ful_quaternioncg_parenReference(const real_T obj_a[21], const real_T
    obj_b[21], const real_T obj_c[21], const real_T obj_d[21], const real_T
    varargin_1[20], real_T o_a[20], real_T o_b[20], real_T o_c[20], real_T o_d
    [20]);
  void full_loop_quaternioncg_times(const real_T x_a[20], const real_T x_b[20],
    const real_T x_c[20], const real_T x_d[20], const real_T y_a[20], const
    real_T y_b[20], const real_T y_c[20], const real_T y_d[20], real_T o_a[20],
    real_T o_b[20], real_T o_c[20], real_T o_d[20]);
  void f_quaternioncg_parenReference_p(const real_T obj_a[20], const real_T
    obj_b[20], const real_T obj_c[20], const real_T obj_d[20], const boolean_T
    varargin_1[20], real_T o_a_data[], int32_T *o_a_size, real_T o_b_data[],
    int32_T *o_b_size, real_T o_c_data[], int32_T *o_c_size, real_T o_d_data[],
    int32_T *o_d_size);
  void full_loop_quaternionBase_rotvec(const real_T q_a[20], const real_T q_b[20],
    const real_T q_c[20], const real_T q_d[20], real_T rv[60]);
  void full_loop_getang(const real_T qi_a[20], const real_T qi_b[20], const
                        real_T qi_c[20], const real_T qi_d[20], const real_T
                        qf_a[20], const real_T qf_b[20], const real_T qf_c[20],
                        const real_T qf_d[20], real_T dtheta[20], real_T e[60]);
  void full_loop_bd(const real_T e[3], real_T dtheta, const real_T xin[3],
                    real_T xout[3]);
  void full_loop_bd_p(const real_T e[3], real_T dtheta, const real_T xin[3],
                      real_T xout[3]);
  real_T full_loop_xnrm2_p43rio(int32_T n, const real_T x[57], int32_T ix0);
  real_T full_loop_xdotc(int32_T n, const real_T x[57], int32_T ix0, const
    real_T y[57], int32_T iy0);
  void full_loop_xaxpy_p(int32_T n, real_T a, int32_T ix0, const real_T y[57],
    int32_T iy0, real_T b_y[57]);
  real_T full_loop_xnrm2_p43riob(int32_T n, const real_T x[3], int32_T ix0);
  void full_loop_xrotg_p(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T *c,
    real_T *s);
  void full_loop_svd(const real_T A[57], real_T U[3]);
  void full_loop_quaternionC2fit(const real_T y_a[21], const real_T y_b[21],
    const real_T y_c[21], const real_T y_d[21], const real_T x[21], real_T h[20],
    real_T dtheta[20], real_T e[60], real_T w[63]);
  int32_T full_loop_bsearch(const real_T x[21], real_T xi);
  void waypointTrajectory_setupWaypoin(waypointTrajectory_full_loop_T *obj);
  real_T full_loop_mapElementsToBins(real_T x, const real_T edges[21], boolean_T
    right);
  void full_loop_sqrt_p4(const real_T x_data[], const int32_T x_size[2], real_T
    b_x_data[], int32_T b_x_size[2]);
  void full_loop_abs_p43(const real_T x_data[], const int32_T x_size[2], real_T
    y_data[], int32_T y_size[2]);
  void full_loop_fresnel_p(const real_T x_data[], const int32_T x_size[2],
    creal_T z_data[], int32_T z_size[2]);
  void full_loop_power_p43ri(const real_T a_data[], const int32_T a_size[2],
    real_T y_data[], int32_T y_size[2]);
  void full_loop_repmat_p43r(const creal_T a_data[], const int32_T a_size[2],
    creal_T b_data[], int32_T b_size[2]);
  void full_loop_bsxfun_p(const creal_T a_data[], const int32_T a_size[2],
    creal_T c_data[], int32_T c_size[2]);
  void full_loop_fresnelgzero(const real_T x_data[], const int32_T x_size[2],
    const real_T dk_data[], const int32_T dk_size[2], const real_T k_data[],
    const int32_T k_size[2], const real_T theta_data[], const int32_T
    theta_size[2], creal_T z_data[], int32_T *z_size);
  creal_T full_loop_fresnelg2(real_T x, real_T dk, real_T k, real_T theta);
  void full_loop_getPositionalState(const real_T hcd[21], const creal_T hip[21],
    const real_T hl[20], const real_T k0[20], const real_T k1[20], const real_T
    course[21], const real_T hpp_breaks[21], const real_T hpp_coefs[80], const
    real_T hspp_breaks[21], const real_T hspp_coefs[80], const real_T
    happ_breaks[21], const real_T happ_coefs[80], const real_T hjpp_breaks[21],
    const real_T hjpp_coefs[80], creal_T *position, creal_T *velocity, creal_T
    *acceleration, creal_T *jerk);
  real_T full_loop_ppval(const real_T pp_breaks[21], const real_T pp_coefs[80],
    real_T x);
  void waypointTrajectory_fetchPositio(const waypointTrajectory_full_loop_T *obj,
    real_T position[3], real_T velocity[3], real_T acceleration[3], real_T jerk
    [3]);
  void full_waypointTrajectory_setPose(waypointTrajectory_full_loop_T *obj);
  waypointTrajectory_full_loop_T *waypointTrajectory_waypointTraj
    (waypointTrajectory_full_loop_T *obj, const real_T varargin_1[63], const
     real_T varargin_2[21], real_T varargin_4, const real_T varargin_8_a[21],
     const real_T varargin_8_b[21], const real_T varargin_8_c[21], const real_T
     varargin_8_d[21]);
  void full_loop_getPositionalState_p(const real_T hcd[21], const creal_T hip[21],
    const real_T hl[20], const real_T k0[20], const real_T k1[20], const real_T
    course[21], const real_T hpp_breaks[21], const real_T hpp_coefs[80], const
    real_T hspp_breaks[21], const real_T hspp_coefs[80], const real_T
    happ_breaks[21], const real_T happ_coefs[80], const real_T hjpp_breaks[21],
    const real_T hjpp_coefs[80], real_T t, creal_T *position, creal_T *velocity,
    creal_T *acceleration, creal_T *jerk);
  void waypointTrajectory_fetchPosit_p(const waypointTrajectory_full_loop_T *obj,
    real_T simulationTime, real_T position[3], real_T velocity[3], real_T
    acceleration[3], real_T jerk[3]);
  void full_loop_cross(const real_T a_data[], const int32_T a_size[2], const
                       real_T b_data[], real_T c_data[], int32_T c_size[2]);
  void full_loop_dot(const real_T a_data[], const int32_T a_size[2], const
                     real_T b_data[], real_T c_data[], int32_T *c_size);
  void full_loop_bsxmul(const real_T x_data[], const int32_T *x_size, const
                        real_T y_data[], const int32_T y_size[2], real_T z_data[],
                        int32_T z_size[2]);
  void full_loop_bsxmul_p(const real_T x_data[], const int32_T x_size[2], const
    real_T y_data[], const int32_T y_size[2], real_T z_data[], int32_T z_size[2]);
  void full_loop_slew3_init(real_T dt, real_T dtheta, const real_T e[3], const
    real_T wi[3], const real_T wf[3], real_T aa[9], real_T bb[9], real_T cc[6],
    real_T dd[3]);
  void full_loop_bsxmul_p4(const real_T x[3], real_T y, real_T z[3]);
  void full_loop_bsxmul_p43(real_T x, const real_T y[3], real_T z[3]);
  void full_loop_bsxdiv(const real_T x_data[], const int32_T x_size[2], const
                        real_T y_data[], const int32_T y_size[2], real_T z_data[],
                        int32_T z_size[2]);
  void full_loop_sum(const real_T x_data[], const int32_T x_size[2], real_T
                     y_data[], int32_T *y_size);
  void full_loop_slew3(real_T t, real_T dt, real_T qi_a, real_T qi_b, real_T
                       qi_c, real_T qi_d, const real_T a[9], const real_T b[9],
                       const real_T c[6], const real_T d[3], real_T *q_a, real_T
                       *q_b, real_T *q_c, real_T *q_d, real_T angVel[3], real_T
                       angAcc[3], real_T angJerk[3]);
  void full_loop_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
    real_T q_d, real_T r[9]);
  void fu_TrajectoryGenerator_stepImpl(TrajectoryGenerator_full_loop_T *b_this,
    const real_T wpts[160], real_T wpt_count, real_T pose[13000], real_T b_new[2]);
  void full_loop_SystemCore_step(TrajectoryGenerator_full_loop_T *obj, const
    real_T varargin_1[160], real_T varargin_2, real_T varargout_1[13000], real_T
    varargout_2[2]);
  void f_TrajectoryManager_BufferReset(TrajectoryManager_full_loop_T *b_this,
    uint8_T reset, const real_T mesuredPose[7]);
  void full_loop_string_disp(void);
  void TrajectoryManager_processNewPos(TrajectoryManager_full_loop_T *b_this,
    const real_T pose[13000], real_T count, real_T b_new);
  boolean_T full_loop_ifWhileCond(const boolean_T x[13]);
  void TrajectoryManager_SendCurrentPo(TrajectoryManager_full_loop_T *b_this,
    real_T currPose[52]);
  real_T full_loop_norm(const real_T x[3]);
  boolean_T full_loop_isequal(const real_T varargin_1[29], const real_T
    varargin_2[29]);
  boolean_T full_loop_isequal_p(const real_T varargin_1[8], const real_T
    varargin_2[8]);
  void full_loop_znlmpc_setDecisions(const real_T X[52], const real_T Umv[32],
    real_T e, real_T z[69]);
  void full__structConstructorHelper_o(const cell_wrap_9_full_loop_T *varargin_2,
    const cell_wrap_10_full_loop_T *varargin_4, const cell_wrap_11_full_loop_T
    *varargin_6, const cell_wrap_11_full_loop_T *varargin_10, const
    cell_wrap_13_full_loop_T *varargin_12, const cell_wrap_13_full_loop_T
    *varargin_14, const cell_wrap_11_full_loop_T *varargin_18, const
    cell_wrap_11_full_loop_T *varargin_20, const cell_wrap_11_full_loop_T
    *varargin_22, const cell_wrap_11_full_loop_T *varargin_24, const
    cell_wrap_13_full_loop_T *varargin_26, const cell_wrap_13_full_loop_T
    *varargin_28, const cell_wrap_13_full_loop_T *varargin_30, const
    cell_wrap_13_full_loop_T *varargin_32, const cell_wrap_13_full_loop_T
    *varargin_34, s_A0rUWcsbMx3S06V1NlippE_full_T *s);
  void full_lo_structConstructorHelper(const real_T varargin_2[13], const real_T
    varargin_4[8], const real_T varargin_6[52], const real_T varargin_10[52],
    const real_T varargin_12[32], const real_T varargin_14[32], const real_T
    varargin_18[52], const real_T varargin_20[52], const real_T varargin_22[52],
    const real_T varargin_24[52], const real_T varargin_26[32], const real_T
    varargin_28[32], const real_T varargin_30[32], const real_T varargin_32[32],
    const real_T varargin_34[32], s_A0rUWcsbMx3S06V1NlippE_full_T *s);
  void full_znlmpc_generateRuntimeData(const real_T x[13], const real_T lastMV[8],
    const real_T ref0[52], const real_T OutputWeights0[13], const real_T
    MVWeights0[8], const real_T MVRateWeights0[8], const real_T MVMin0[8], const
    real_T MVMax0[8], const real_T X0[39], const real_T MV0[24], real_T Slack0,
    s_A0rUWcsbMx3S06V1NlippE_full_T *runtimedata,
    sACkMJ1zT2VJOHR6eMwwEPC_full__T *userdata, real_T z0[69]);
  void full_loop_znlmpc_getZBounds(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *runtimedata, real_T zLB[69], real_T zUB[69]);
  void full_loop_diag(real_T d[64]);
  void full_loop_isfinite_m(const real_T x[8], boolean_T b[8]);
  void full_loop_znlmpc_getUBounds(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *runtimedata, real_T A_data[], int32_T A_size[2], real_T Bu_data[], int32_T *
    Bu_size);
  void full_loop_znlmpc_getDecisions(const real_T z[69], real_T X[52], real_T
    Umv[32], real_T *e);
  void full_loop_znlmpc_getXUe(const real_T z[69], const real_T x[13], real_T X
    [65], real_T U[40], real_T *e);
  void full_loop_eye(real_T b_I[169]);
  void full_loop_AUVQuatJacobianMatrix(const real_T in1[13], real_T Anqv[169],
    real_T Bnqv[104]);
  void full_loop_AUVQuatSimFcn(const real_T in1[13], const real_T in2[8], real_T
    out1[13]);
  void full_loop_stateEvolution(const real_T X[65], const real_T U[40], real_T
    c[52], real_T J[3588]);
  void full_loop_all(const boolean_T x[52], boolean_T y[13]);
  boolean_T full_loop_all_l(const boolean_T x[13]);
  void full_loop_isfinite_mo(const real_T x[13], boolean_T b[13]);
  boolean_T full_loop_any(const boolean_T x[26]);
  void full_loop_znlmpc_reformJacobian(const real_T Jx_data[], const int32_T
    Jx_size[3], const real_T Jmv_data[], const real_T Je_data[], const int32_T
    *Je_size, real_T Jc_data[], int32_T Jc_size[2]);
  void full_loop_outputBounds(const real_T runtimedata_OutputMin[52], const
    real_T runtimedata_OutputMax[52], const real_T X[65], real_T e, real_T
    c_data[], int32_T c_size[2], real_T Jc_data[], int32_T Jc_size[2]);
  void full_loop___anon_fcn(const real_T runtimedata_x[13], const real_T
    runtimedata_OutputMin[52], const real_T runtimedata_OutputMax[52], const
    real_T z[69], real_T varargout_1_data[], int32_T varargout_1_size[2], real_T
    varargout_2[52], real_T varargout_3_data[], int32_T varargout_3_size[2],
    real_T varargout_4[3588]);
  int32_T full_loop_checkNonlinearInputs(const real_T x0[69], const real_T
    nonlcon_tunableEnvironment_f1_x[13], const real_T
    nonlcon_tunableEnvironment_f1_O[52], const real_T
    nonlcon_tunableEnvironment_f1_0[52]);
  void full_loop_factoryConstruct(int32_T nVarMax, int32_T mConstrMax, int32_T
    mIneq, int32_T mNonlinIneq, s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  void full_loop_xcopy(const real_T x[69], real_T y[69]);
  void full_loop_factoryConstruct_c(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *objfun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *objfun_tunableEnvironment_f2, const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlcon_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlcon_tunableEnvironment_f2, int32_T mCineq,
    s_siHoaqeHIV5TpidUajpsGD_full_T *obj);
  void full_loop_compressBounds(int32_T indexLB[69], const real_T lb[69],
    int32_T *mLB, int32_T *mUB, int32_T *mFixed);
  void full_lo_factoryConstruct_cntp2b(int32_T mIneq, int32_T mLinIneq, const
    real_T Aineq_data[], const int32_T Aineq_size[2], int32_T mLB, const int32_T
    indexLB[69], int32_T mUB, const int32_T indexUB[69], int32_T mFixed, const
    int32_T indexFixed[69], int32_T nVarMax, int32_T mConstrMax,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_quadraticObjective(const real_T runtimedata_lastMV[8], const
    real_T runtimedata_ref[52], const real_T runtimedata_OutputWeights[52],
    const real_T runtimedata_MVWeights[32], const real_T
    runtimedata_MVRateWeights[32], const real_T runtimedata_MVScaledTarget[32],
    const real_T X[65], const real_T U[40], real_T e, real_T *f, real_T gfx[52],
    real_T gfu[32], real_T *gfe);
  void full_loop___anon_fcn_b(const real_T runtimedata_x[13], const real_T
    runtimedata_lastMV[8], const real_T runtimedata_ref[52], const real_T
    runtimedata_OutputWeights[52], const real_T runtimedata_MVWeights[32], const
    real_T runtimedata_MVRateWeights[32], const real_T
    runtimedata_MVScaledTarget[32], const real_T z[69], real_T *varargout_1,
    real_T varargout_2[69]);
  void computeObjectiveAndUserGradient(const real_T
    obj_objfun_tunableEnvironment_f[13], const real_T
    obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T x[69], real_T
    grad_workspace_data[], real_T *fval, int32_T *status);
  void full_loop_xcopy_gpr(const real_T x[52], real_T y[52]);
  void full_loop_xcopy_gp(int32_T n, const real_T x_data[], real_T y_data[],
    int32_T iy0);
  int32_T full_loop_checkVectorNonFinite(int32_T N, const real_T vec_data[],
    int32_T iv0);
  int32_T full_loo_checkVectorNonFinite_e(const real_T vec[52]);
  int32_T full_loop_checkMatrixNonFinite(int32_T ncols, const real_T mat_data[],
    const int32_T mat_size[2], int32_T col0);
  int32_T full_loo_checkMatrixNonFinite_n(const real_T mat_data[], const int32_T
    mat_size[2]);
  int32_T computeConstraintsAndUserJacobi(const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52],
    real_T JacIneqTrans_workspace_data[], const int32_T
    JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
    JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2]);
  void evalObjAndConstrAndDerivatives(const real_T
    obj_objfun_tunableEnvironment_f[13], const real_T
    obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0,
    real_T Ceq_workspace[52], real_T JacIneqTrans_workspace_data[], const
    int32_T JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
    JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2],
    real_T *fval, int32_T *status);
  void full_loo_computeLinearResiduals(const real_T x[69], real_T
    workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T mLinIneq,
    const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi);
  void full_l_updateWorkingSetForNewQP(const real_T xk[69],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, int32_T mIneq, const real_T
    cIneq_data[], const real_T cEq[52], int32_T mLB, const real_T lb[69],
    int32_T mUB, int32_T mFixed);
  void full_lo_modifyOverheadPhaseOne_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_modifyOverheadRegularized_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_setProblemType(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    PROBLEM_TYPE);
  void full_loop_initActiveSet(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_l_factoryConstruct_cntp2b1(real_T fval, const real_T
    Cineq_workspace_data[], int32_T mNonlinIneq, const real_T Ceq_workspace[52],
    s6ICcRyulWOFjNCN0ll7VsE_full__T *obj);
  void full_loop_factoryConstruct_cn(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *objfun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *objfun_tunableEnvironment_f2, const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlin_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlin_tunableEnvironment_f2, int32_T mCineq, const real_T lb[69],
    s_CWBQhEwNbz3J2I47jPePeB_full_T *obj);
  void full_loop_factoryConstruct_cnt(int32_T maxRows, int32_T maxCols,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *obj);
  void full_loop_factoryConstruct_cntp(int32_T MaxDims, int32_T obj_FMat_size[2],
    int32_T *obj_ldm, int32_T *obj_ndims, int32_T *obj_info);
  void full_loo_factoryConstruct_cntp2(int32_T MaxVars,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *obj);
  void full_loop_setQuadratic(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    NumVars);
  void full_loop_computeGradLag(real_T workspace_data[], int32_T ldA, int32_T
    nVar, const real_T grad_data[], int32_T mIneq, const real_T AineqTrans_data[],
    const real_T AeqTrans_data[], const int32_T finiteFixed_data[], int32_T
    mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
  real_T full_loo_computePrimalFeasError(const real_T x[69], int32_T mLinIneq,
    int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[52], const
    int32_T finiteLB_data[], int32_T mLB, const real_T lb[69], const int32_T
    finiteUB_data[], int32_T mUB);
  void full_loop_computeDualFeasError(int32_T nVar, const real_T gradLag_data[],
    boolean_T *gradOK, real_T *val);
  int32_T full_loop_ixamax(int32_T n, const real_T x_data[]);
  void full_loop_test_exit(s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_ZxHOyfVSozxr6pSGbgUCkF_full_T
    *TrialState, const real_T lb[69], boolean_T *Flags_gradOK, boolean_T
    *Flags_fevalOK, boolean_T *Flags_done, boolean_T *Flags_stepAccepted,
    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType);
  void full_loop_saveJacobian(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj, int32_T nVar,
    int32_T mIneq, const real_T JacCineqTrans_data[], int32_T ineqCol0, const
    real_T JacCeqTrans_data[], int32_T ldJ);
  void full_loop_saveState(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  void full_loop_revertSolution(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *obj);
  boolean_T full_loop_isfinite(real_T x);
  real_T full_loop_computeComplError(const int32_T
    *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
    const real_T xCurrent[69], int32_T mIneq, const real_T cIneq_data[], const
    int32_T finiteLB_data[], int32_T mLB, const real_T lb[69], const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[], int32_T iL0);
  void full_loop_xcopy_gprn(int32_T n, const real_T x_data[], real_T y_data[]);
  void full_loop_computeGradLag_a(real_T workspace_data[], int32_T ldA, int32_T
    nVar, const real_T grad_data[], int32_T mIneq, const real_T AineqTrans_data[],
    const real_T AeqTrans_data[], const int32_T finiteFixed_data[], int32_T
    mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
    finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
  void full_loo_computeDualFeasError_m(int32_T nVar, const real_T gradLag_data[],
    boolean_T *gradOK, real_T *val);
  boolean_T full_loop_isDeltaXTooSmall(const real_T xCurrent[69], const real_T
    delta_x_data[], int32_T nVar);
  void full_updateWorkingSetForNewQP_h(const real_T xk[69],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, int32_T mIneq, int32_T
    mNonlinIneq, const real_T cIneq_data[], const real_T cEq[52], int32_T mLB,
    const real_T lb[69], int32_T mUB, int32_T mFixed);
  real_T full_loop_xnrm2(int32_T n, const real_T x_data[], int32_T ix0);
  real_T full_loop_xzlarfg(int32_T n, real_T *alpha1, real_T x_data[], int32_T
    ix0);
  int32_T full_loop_ilazlc(int32_T m, int32_T n, const real_T A_data[], int32_T
    ia0, int32_T lda);
  void full_loop_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0,
                       int32_T lda, const real_T x_data[], int32_T ix0, real_T
                       y_data[]);
  void full_loop_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                       real_T y_data[], real_T A_data[], int32_T ia0, int32_T
                       lda);
  void full_loop_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
                        C_data[], int32_T ic0, int32_T ldc, real_T work_data[]);
  void full_loop_qrf(real_T A_data[], const int32_T A_size[2], int32_T m,
                     int32_T n, int32_T nfxd, real_T tau_data[]);
  int32_T full_loop_ixamax_l(int32_T n, const real_T x_data[], int32_T ix0);
  void full_loop_xswap(int32_T n, real_T x_data[], int32_T ix0, int32_T iy0);
  void full_loop_qrpf(real_T A_data[], const int32_T A_size[2], int32_T m,
                      int32_T n, int32_T nfxd, real_T tau_data[], int32_T
                      jpvt_data[]);
  void full_loop_xgeqp3(real_T A_data[], const int32_T A_size[2], int32_T m,
                        int32_T n, int32_T jpvt_data[], real_T tau_data[],
                        int32_T *tau_size);
  void full_loop_xcopy_gprnb(int32_T n, const real_T x_data[], int32_T ix0,
    real_T y_data[], int32_T iy0);
  void full_loop_factorQRE(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const real_T
    A_data[], const int32_T A_size[2], int32_T mrows, int32_T ncols);
  void full_loop_xscal(int32_T n, real_T a, real_T x_data[], int32_T ix0);
  void full_loop_xorgqr(int32_T m, int32_T n, int32_T k, real_T A_data[], const
                        int32_T A_size[2], int32_T lda, const real_T tau_data[]);
  void full_loop_computeQ_(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T nrows);
  void full_loop_xgemv_j(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xtrsv(int32_T n, const real_T A_data[], int32_T lda, real_T
                       x_data[]);
  void full_loop_computeLambdaLSQ(int32_T nVar, int32_T mConstr,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager, const real_T ATwset_data[],
    const int32_T ATwset_size[2], const real_T grad_data[], real_T
    lambdaLSQ_data[], real_T workspace_data[]);
  void full_loop_sortLambdaQP(real_T lambda_data[], int32_T
    WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
    WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const
    int32_T WorkingSet_Wlocalidx_data[], real_T workspace_data[]);
  void full_loop_test_exit_a(s7RdrPWkr8UPAUyTdDJkLaG_full__T *Flags,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T *
    fscales_cineq_constraint_size, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *QRManager, const real_T lb[69]);
  void full_loop_computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
    real_T workspace_data[], const real_T grad_data[], const real_T
    JacIneqTrans_data[], int32_T ineqJ0, const real_T JacEqTrans_data[], const
    real_T grad_old_data[], const real_T JacIneqTrans_old_data[], const real_T
    JacEqTrans_old_data[], const real_T lambda_data[], int32_T ineqL0, int32_T
    eqL0);
  boolean_T full_loop_BFGSUpdate(int32_T nvar, real_T Bk[4761], const real_T
    sk_data[], real_T yk_data[], real_T workspace_data[]);
  void full_loop_xcopy_g(int32_T n, const real_T x[69], real_T y_data[]);
  void full_addBoundToActiveSetMatrix_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    int32_T TYPE, int32_T idx_local);
  void full_loop_makeBoundFeasible(real_T xk_data[],
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet);
  void full_loop_xcopy_gprnbz1rec(int32_T n, const real_T x[69], real_T y[69]);
  void full_loop_updateWorkingSet(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    const real_T TrialState_cIneq_data[], const real_T TrialState_cEq[52], const
    real_T TrialState_searchDir_data[], int32_T workspace_int_data[]);
  void full_loop_snap_bounds(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, const
    real_T workingset_lb_data[], const real_T workingset_ub_data[], const
    int32_T workingset_indexLB_data[], const int32_T workingset_indexUB_data[],
    const int32_T workingset_indexFixed_data[], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6], const boolean_T
    workingset_isActiveConstr_data[]);
  void full_loop_factorQRE_n(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T mrows,
    int32_T ncols);
  int32_T full_loo_ComputeNumDependentEq_(s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager, const real_T beqf_data[], int32_T mConstr, int32_T nVar);
  void full_loop_IndexOfDependentEq_(int32_T depIdx_data[], int32_T mFixed,
    int32_T nDep, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, const real_T
    AeqfPrime_data[], const int32_T AeqfPrime_size[2], int32_T mRows, int32_T
    nCols);
  void full_loop_countsort(int32_T x_data[], int32_T xLen, int32_T
    workspace_data[], int32_T xMin, int32_T xMax);
  void full_loop_removeConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_global);
  void full_loop_removeEqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_global);
  int32_T full_loop_RemoveDependentEq_(s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager);
  void full_loop_removeAllIneqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj);
  void full_loop_RemoveDependentIneq_(s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  void full_loop_xgemv_jh(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xgeqrf(real_T A_data[], const int32_T A_size[2], int32_T m,
                        int32_T n, real_T tau_data[], int32_T *tau_size);
  void full_loop_factorQR_i(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const real_T
    A_data[], const int32_T A_size[2], int32_T mrows, int32_T ncols);
  void full_loop_xtrsm_k(int32_T m, const real_T A_data[], int32_T lda, real_T
    B_data[], int32_T ldb);
  void full_loop_xgemm_g(int32_T m, int32_T k, const real_T A_data[], int32_T
    lda, const real_T B_data[], int32_T ldb, real_T C_data[], int32_T ldc);
  void full_loop_factorQR(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T mrows,
    int32_T ncols);
  void full_loop_xgemm(int32_T m, int32_T k, const real_T A_data[], int32_T lda,
                       const real_T B_data[], int32_T ldb, real_T C_data[],
                       int32_T ldc);
  void full_loop_xtrsm(int32_T m, const real_T A_data[], int32_T lda, real_T
                       B_data[], int32_T ldb);
  void full_loop_xaxpy(int32_T n, const real_T x_data[], real_T y_data[]);
  void full_loop_xgemv_jhg(int32_T m, const real_T A_data[], int32_T lda, const
    real_T x_data[], real_T y_data[]);
  real_T maxConstraintViolation_AMats_no(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T maxConstraintViolation_AMats_re(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T full_loo_maxConstraintViolation(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  void full_loop_xgemv_jhgj(int32_T m, int32_T n, const real_T A_data[], int32_T
    lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
  void full_loop_xgemv_jhgj1(int32_T m, const real_T A_data[], int32_T lda,
    const real_T x_data[], int32_T ix0, real_T y_data[]);
  real_T maxConstraintViolation_AMats__e(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  real_T maxConstraintViolation_AMats__g(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  real_T full_l_maxConstraintViolation_a(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[], int32_T ix0);
  void full_loop_xcopy_gprnbz1r(int32_T n, const real_T x_data[], int32_T ix0,
    real_T y_data[]);
  void full_loop_xcopy_gprnbz1(int32_T n, const real_T x_data[], real_T y_data[]);
  boolean_T full_lo_feasibleX0ForWorkingSet(real_T workspace_data[], const
    int32_T workspace_size[2], real_T xCurrent_data[], int32_T *xCurrent_size,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *qrmanager);
  void full_loo_RemoveDependentIneq__d(s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  void full_loop_xgemv_jhgj1v(int32_T m, const real_T A_data[], int32_T lda,
    const real_T x_data[], real_T y_data[]);
  real_T maxConstraintViolation_AMats_ev(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T maxConstraintViolation_AMats_g3(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  real_T full__maxConstraintViolation_ae(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj,
    const real_T x_data[]);
  void full_loop_PresolveWorkingSet(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager);
  void full_loop_xgemv_jhgj1v0(int32_T m, int32_T n, const real_T A[4761],
    int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_computeGrad_StoreHx(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, const
    real_T H[4761], const real_T f_data[], const real_T x_data[]);
  real_T full_loop_computeFval_ReuseHx(const s_BtE36YuCWnavoi0lGdvGZF_full_T
    *obj, real_T workspace_data[], const real_T f_data[], const real_T x_data[]);
  void full_loop_xcopy_gprnbz(int32_T n, real_T y_data[]);
  void full_loop_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
  void full_loop_xrot(int32_T n, real_T x_data[], int32_T ix0, int32_T iy0,
                      real_T c, real_T s);
  void full_loop_squareQ_appendCol(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, const
    real_T vec_data[], int32_T iv0);
  void full_loop_xrot_i(int32_T n, real_T x_data[], int32_T ix0, int32_T incx,
                        int32_T iy0, int32_T incy, real_T c, real_T s);
  void full_loop_deleteColMoveEnd(s_3RW6EhlAOINzvAvYfuaanB_full_T *obj, int32_T
    idx);
  void full_loop_xgemm_gu(int32_T m, int32_T n, int32_T k, const real_T A[4761],
    int32_T lda, const real_T B_data[], int32_T ib0, int32_T ldb, real_T C_data[],
    int32_T ldc);
  void full_loop_xgemm_gu5(int32_T m, int32_T n, int32_T k, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T B_data[], int32_T ldb, real_T C_data[],
    int32_T ldc);
  void computeProjectedHessian_regular(real_T beta, const real_T H[4761],
    int32_T nVarOrig, s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *
    memspace);
  void full_lo_computeProjectedHessian(const real_T H[4761],
    s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *
    memspace);
  int32_T full_loop_xpotrf(int32_T n, real_T A_data[], int32_T lda);
  void full_loop_factor_a(s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, int32_T ndims);
  void full_loop_xgemv_jhgj1v0ny(int32_T m, int32_T n, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_solve_k(const s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, real_T
    rhs_data[]);
  void full_loop_xgemv_jhgj1v0n(int32_T m, int32_T n, const real_T A_data[],
    int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_xcopy_gprnbz1re(int32_T n, const real_T x[4761], int32_T ix0,
    real_T y_data[], int32_T iy0);
  void full_loop_factor(s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, const real_T A
                        [4761], int32_T ndims, int32_T ldA);
  void full_loop_solve(const s_a5SYZcWNC5KFUTosoMMbl_full__T *obj, real_T
                       rhs_data[]);
  void full_loop_xscal_n(int32_T n, real_T a, real_T x_data[], int32_T ix0);
  void full_loop_compute_deltax(const real_T H[4761],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, const s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager,
    s_a5SYZcWNC5KFUTosoMMbl_full__T *cholmanager, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective);
  real_T full_loop_xnrm2_n(int32_T n, const real_T x_data[]);
  void full_loop_xgemv_jhgj1v0ny5(int32_T m, int32_T n, const real_T A_data[],
    int32_T lda, const real_T x_data[], real_T y_data[]);
  void full_loop_feasibleratiotest(const real_T solution_xstar_data[], const
    real_T solution_searchDir_data[], real_T workspace_data[], const int32_T
    workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA, const
    real_T workingset_Aineq_data[], const real_T workingset_bineq_data[], const
    real_T workingset_lb_data[], const real_T workingset_ub_data[], const
    int32_T workingset_indexLB_data[], const int32_T workingset_indexUB_data[],
    const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr_data[], const int32_T
    workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha, boolean_T
    *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void full_l_checkUnboundedOrIllPosed(s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    const s_BtE36YuCWnavoi0lGdvGZF_full_T *objective);
  void full_loop_addAineqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_local);
  void full_loop_xaxpy_k(int32_T n, real_T a, const real_T x_data[], real_T
    y_data[]);
  void full_loop_compute_lambda(real_T workspace_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, const
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager);
  int32_T full_loop_find_neg_lambda(const real_T solution_lambda_data[], int32_T
    workingset_nActiveConstr, const int32_T workingset_nWConstr[5]);
  int32_T full_loop_mod(int32_T x);
  void full_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const real_T
    f_data[], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, const
    s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *
    workingset, s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, real_T
    options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
    updateFval);
  void full_loop_iterate(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective, real_T
    options_StepTolerance, real_T options_ObjectiveLimit, int32_T
    runTimeOptions_MaxIterations);
  void full_loop_setPhaseOne(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    NumVars);
  void full_loop_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
    workspace_data[], const real_T H[4761], const real_T f_data[], const real_T
    x_data[]);
  real_T full_loop_computeFval(const s_BtE36YuCWnavoi0lGdvGZF_full_T *obj,
    real_T workspace_data[], const real_T H[4761], const real_T f_data[], const
    real_T x_data[]);
  void full_loop_restoreFromPhaseOne(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj);
  void full_loop_phaseone(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *runTimeOptions);
  void full_loop_driver_e(const real_T H[4761], const real_T f_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *solution, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *workingset,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *qrmanager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    cholmanager, s_BtE36YuCWnavoi0lGdvGZF_full_T *objective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *options, s1TgE9KstXgkd2qJxO1bF4F_full__T
    *runTimeOptions);
  void full_loop_restoreWorkingSet(boolean_T stepSuccess, int32_T nWIneq_old,
    int32_T nWLower_old, int32_T nWUpper_old, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet, const real_T TrialState_cIneq_data[], const real_T
    TrialState_cEq[52], const int32_T workspace_int_data[]);
  void full_loop_addAeqConstr(s_Mspqy2ajbjhxqxIYYuZUwC_full_T *obj, int32_T
    idx_local);
  boolean_T full_loop_soc(const real_T Hessian[4761], const real_T grad_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
    s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager, s_a5SYZcWNC5KFUTosoMMbl_full__T *
    CholManager, s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_updatePenaltyParam(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj, real_T
    fval, const real_T ineq_workspace_data[], int32_T mIneq, const real_T
    eq_workspace[52], int32_T sqpiter, real_T qpval);
  void full_loop_normal(const real_T Hessian[4761], const real_T grad_data[],
                        s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
                        s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
                        s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
                        s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
                        s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
                        s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
                        s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
                        s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_setRegularized(s_BtE36YuCWnavoi0lGdvGZF_full_T *obj, int32_T
    numQuadVars, real_T beta, real_T rho);
  void full_lo_assignResidualsToXSlack(int32_T nVarOrig,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_ZxHOyfVSozxr6pSGbgUCkF_full_T
    *TrialState, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace);
  int32_T full_findActiveSlackLowerBounds(s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
    *memspace, const int32_T WorkingSet_sizes[5], const int32_T
    WorkingSet_isActiveIdx[6], const boolean_T WorkingSet_isActiveConstr_data[]);
  real_T full_loop_xasum(int32_T n, const real_T x_data[], int32_T ix0);
  real_T full_loop_xdot(int32_T n, const real_T x_data[], int32_T ix0, const
                        real_T y_data[], int32_T iy0);
  void full_loop_updatePenaltyParam_o(s6ICcRyulWOFjNCN0ll7VsE_full__T *obj,
    real_T fval, const real_T ineq_workspace_data[], int32_T mIneq, const real_T
    eq_workspace[52], int32_T sqpiter, real_T qpval, const real_T x_data[],
    int32_T iReg0, int32_T nRegularized);
  void fu_removeActiveSlackLowerBounds(int32_T nActiveLBArtificial,
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet);
  void full_loop_relaxed(const real_T Hessian[4761], const real_T grad_data[],
    s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, s6ICcRyulWOFjNCN0ll7VsE_full__T
    *MeritFunction, s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
    s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet, s_3RW6EhlAOINzvAvYfuaanB_full_T
    *QRManager, s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_BFGSReset(real_T Hessian[4761], const real_T grad_data[], const
    real_T searchDir_data[]);
  void full_loop_saturateDirection(const real_T xk[69], real_T delta_x_data[],
    real_T xstarqp_data[], const int32_T indexLB_data[], int32_T mLB, const
    real_T lb[69]);
  boolean_T full_loop_step_n(int32_T *STEP_TYPE, real_T Hessian[4761], const
    real_T lb[69], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
    s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction,
    s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace, s_Mspqy2ajbjhxqxIYYuZUwC_full_T
    *WorkingSet, s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
    s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
    s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective,
    s1TgE9KstXgkd2qJxO1bF4F_full__T *qpoptions);
  void full_loop_computeObjective_(const real_T obj_objfun_tunableEnvironment_f
    [13], const real_T obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T x[69], real_T *fval,
    int32_T *status);
  void full_loop___anon_fcn_bv(const real_T runtimedata_x[13], const real_T
    runtimedata_OutputMin[52], const real_T runtimedata_OutputMax[52], const
    real_T z[69], real_T varargout_1_data[], int32_T varargout_1_size[2], real_T
    varargout_2[52]);
  int32_T full_loop_computeConstraints_(const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52]);
  void full_loop_evalObjAndConstr(const real_T obj_objfun_tunableEnvironment_f
    [13], const real_T obj_objfun_tunableEnvironment_0[8], const real_T
    obj_objfun_tunableEnvironment_1[52], const real_T
    obj_objfun_tunableEnvironment_2[52], const real_T
    obj_objfun_tunableEnvironment_3[32], const real_T
    obj_objfun_tunableEnvironment_4[32], const real_T
    obj_objfun_tunableEnvironment_5[32], const real_T
    obj_nonlcon_tunableEnvironment_[13], const real_T
    obj_nonlcon_tunableEnvironmen_0[52], const real_T
    obj_nonlcon_tunableEnvironmen_1[52], int32_T obj_mCineq, const real_T x[69],
    real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[52],
    real_T *fval, int32_T *status);
  void full_l_computeLinearResiduals_l(const real_T x[69], int32_T nVar, real_T
    workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T mLinIneq,
    const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi);
  real_T full_loop_computeMeritFcn(real_T obj_penaltyParam, real_T fval, const
    real_T Cineq_workspace_data[], int32_T mIneq, const real_T Ceq_workspace[52],
    boolean_T evalWellDefined);
  void full_loop_linesearch(boolean_T *evalWellDefined, const real_T bineq_data[],
    int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const real_T
    WorkingSet_Aineq_data[], s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState, real_T
    MeritFunction_penaltyParam, real_T MeritFunction_phi, real_T
    MeritFunction_phiPrimePlus, real_T MeritFunction_phiFullStep, const
    s_A0rUWcsbMx3S06V1NlippE_full_T *FcnEvaluator_objfun_tunableEnvi, const
    s_A0rUWcsbMx3S06V1NlippE_full_T *FcnEvaluator_nonlcon_tunableEnv, int32_T
    FcnEvaluator_mCineq, boolean_T socTaken, real_T *alpha, int32_T *exitflag);
  void full_loop_driver(const real_T bineq_data[], const real_T lb[69],
                        s_ZxHOyfVSozxr6pSGbgUCkF_full_T *TrialState,
                        s6ICcRyulWOFjNCN0ll7VsE_full__T *MeritFunction, const
                        s_siHoaqeHIV5TpidUajpsGD_full_T *FcnEvaluator,
                        s_i4ZL8C3jdkCeOA2IrFHlEF_full_T *memspace,
                        s_Mspqy2ajbjhxqxIYYuZUwC_full_T *WorkingSet,
                        s_3RW6EhlAOINzvAvYfuaanB_full_T *QRManager,
                        s_a5SYZcWNC5KFUTosoMMbl_full__T *CholManager,
                        s_BtE36YuCWnavoi0lGdvGZF_full_T *QPObjective, const
                        int32_T *fscales_lineq_constraint_size, const int32_T
                        *fscales_cineq_constraint_size, real_T Hessian[4761]);
  void full_loop_fillOutputStruct(int32_T TrialState_FunctionEvaluations,
    int32_T TrialState_sqpIterations, real_T TrialState_steplength, const real_T
    TrialState_delta_x_data[], real_T MeritFunction_nlpPrimalFeasErro, real_T
    MeritFunction_firstOrderOpt, real_T *output_iterations, real_T
    *output_funcCount, char_T output_algorithm[3], real_T
    *output_constrviolation, real_T *output_stepsize, real_T
    *output_lssteplength, real_T *output_firstorderopt);
  void full_loop_fmincon(const s_A0rUWcsbMx3S06V1NlippE_full_T
    *fun_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *fun_tunableEnvironment_f2, const real_T x0[69], const real_T Aineq_data[],
    const int32_T Aineq_size[2], const real_T bineq_data[], const int32_T
    *bineq_size, const real_T lb[69], const s_A0rUWcsbMx3S06V1NlippE_full_T
    *nonlcon_tunableEnvironment_f1, const sACkMJ1zT2VJOHR6eMwwEPC_full__T
    *nonlcon_tunableEnvironment_f2, real_T x[69], real_T *fval, real_T *exitflag,
    real_T *output_iterations, real_T *output_constrviolation);
  void full_loop_znlmpc_computeInfo(const real_T X[65], const real_T U[40],
    real_T e, real_T cost, real_T ExitFlag, real_T iter, real_T X0[52], real_T
    MV0[32], real_T *Slack0, sscAEMcz7TPKHyH2uh3imDC_full__T *info);
  boolean_T full_loop_isequal_p4(const real_T varargin_1[3], const real_T
    varargin_2[3]);
  boolean_T full_loop_isequal_p43(const real_T varargin_1[6], const real_T
    varargin_2[6]);
  void full_loop_AUVModelMatrices(const real_T in1[13], const real_T in2[41],
    real_T M[36], real_T C[36], real_T D[36], real_T Gq[6]);
  real_T full_loop_erf(real_T x);
  void full_loo_AUVQuatPerturbedSimFcn(const real_T in1[13], const real_T in2[6],
    const real_T in3[8], real_T out1[13]);
  void matlabCodegenHandle_matla_p43ri(ros_slros_internal_block_Subs_T *obj);
  void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
  void ful_TrajectoryManager_setupImpl(TrajectoryManager_full_loop_T *b_this);

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void full_loop_derivatives();
};

extern const full_loopModelClass::ConstB_full_loop_T full_loop_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const full_loopModelClass::ConstP_full_loop_T full_loop_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/N to RPM' : Unused code path elimination
//  Block '<S12>/Scope' : Unused code path elimination
//  Block '<S13>/Scope' : Unused code path elimination
//  Block '<S13>/Scope1' : Unused code path elimination
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<S2>/Scope2' : Unused code path elimination
//  Block '<S2>/Scope3' : Unused code path elimination
//  Block '<S2>/Scope4' : Unused code path elimination
//  Block '<S57>/Data Type Duplicate' : Unused code path elimination
//  Block '<S55>/Scope' : Unused code path elimination
//  Block '<S62>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S63>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S64>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S65>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S66>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S67>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S68>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S69>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S70>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S71>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S72>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S73>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S74>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S75>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S76>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S77>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S78>/Vector Dimension Check' : Unused code path elimination
//  Block '<S79>/Vector Dimension Check' : Unused code path elimination
//  Block '<S80>/Vector Dimension Check' : Unused code path elimination
//  Block '<S81>/Vector Dimension Check' : Unused code path elimination
//  Block '<S59>/mv.init_zero' : Unused code path elimination
//  Block '<S59>/x.init_zero' : Unused code path elimination
//  Block '<S56>/Scope' : Unused code path elimination
//  Block '<S6>/Scope1' : Unused code path elimination
//  Block '<S6>/Scope4' : Unused code path elimination
//  Block '<S7>/Discrete-Time Integrator1' : Unused code path elimination
//  Block '<S7>/Display' : Unused code path elimination
//  Block '<S7>/Scope' : Unused code path elimination
//  Block '<S7>/Scope1' : Unused code path elimination
//  Block '<S7>/Scope2' : Unused code path elimination
//  Block '<S7>/Scope3' : Unused code path elimination
//  Block '<S7>/Scope4' : Unused code path elimination
//  Block '<S7>/Scope6' : Unused code path elimination
//  Block '<S87>/Display' : Unused code path elimination
//  Block '<S103>/Gain' : Unused code path elimination
//  Block '<S87>/Scope' : Unused code path elimination
//  Block '<S87>/Scope1' : Unused code path elimination
//  Block '<S8>/Scope' : Unused code path elimination
//  Block '<S112>/Scope1' : Unused code path elimination
//  Block '<S113>/Scope' : Unused code path elimination
//  Block '<S113>/Scope1' : Unused code path elimination
//  Block '<S114>/Scope' : Unused code path elimination
//  Block '<S114>/Scope1' : Unused code path elimination
//  Block '<S9>/Delay' : Unused code path elimination
//  Block '<S9>/Display1' : Unused code path elimination
//  Block '<S132>/Data Type Duplicate' : Unused code path elimination
//  Block '<S137>/FixPt Data Type Duplicate2' : Unused code path elimination
//  Block '<S39>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S39>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S60>/Reshape1' : Reshape block reduction
//  Block '<S60>/mo or x Conversion' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion1' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion10' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion11' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion12' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion13' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion14' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion15' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion16' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion17' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion18' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion19' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion2' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion3' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion4' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion5' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion6' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion7' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion8' : Eliminate redundant data type conversion
//  Block '<S60>/mo or x Conversion9' : Eliminate redundant data type conversion
//  Block '<S61>/reshape_mv' : Reshape block reduction
//  Block '<S7>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S7>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S119>/Saturation' : Eliminated Saturate block
//  Block '<S120>/Saturation' : Eliminated Saturate block
//  Block '<S7>/si y devant' : Unused code path elimination


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
//  '<Root>' : 'full_loop'
//  '<S1>'   : 'full_loop/Modèle Physique'
//  '<S2>'   : 'full_loop/Plot values'
//  '<S3>'   : 'full_loop/ROS Output'
//  '<S4>'   : 'full_loop/Send PWM to ROS'
//  '<S5>'   : 'full_loop/Send Target Reached '
//  '<S6>'   : 'full_loop/Subsystem Controller'
//  '<S7>'   : 'full_loop/Subsystem ProcNav'
//  '<S8>'   : 'full_loop/Subsystem Trajectory'
//  '<S9>'   : 'full_loop/Subsystem1'
//  '<S10>'  : 'full_loop/Modèle Physique/AUV State Equation'
//  '<S11>'  : 'full_loop/Modèle Physique/MATLAB Function'
//  '<S12>'  : 'full_loop/Modèle Physique/Modele Thruster'
//  '<S13>'  : 'full_loop/Modèle Physique/Perturbations'
//  '<S14>'  : 'full_loop/Modèle Physique/Quaternion Normalise'
//  '<S15>'  : 'full_loop/Modèle Physique/Sensor Noise'
//  '<S16>'  : 'full_loop/Modèle Physique/Modele Thruster/T1'
//  '<S17>'  : 'full_loop/Modèle Physique/Modele Thruster/T2'
//  '<S18>'  : 'full_loop/Modèle Physique/Modele Thruster/T3'
//  '<S19>'  : 'full_loop/Modèle Physique/Modele Thruster/T4'
//  '<S20>'  : 'full_loop/Modèle Physique/Modele Thruster/T5'
//  '<S21>'  : 'full_loop/Modèle Physique/Modele Thruster/T6'
//  '<S22>'  : 'full_loop/Modèle Physique/Modele Thruster/T7'
//  '<S23>'  : 'full_loop/Modèle Physique/Modele Thruster/T8'
//  '<S24>'  : 'full_loop/Modèle Physique/Sensor Noise/Band-Limited White Noise'
//  '<S25>'  : 'full_loop/Modèle Physique/Sensor Noise/Band-Limited White Noise1'
//  '<S26>'  : 'full_loop/Modèle Physique/Sensor Noise/IMU Inverse'
//  '<S27>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1'
//  '<S28>'  : 'full_loop/Modèle Physique/Sensor Noise/Rotation Angles to Quaternions'
//  '<S29>'  : 'full_loop/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Conjugate'
//  '<S30>'  : 'full_loop/Modèle Physique/Sensor Noise/IMU Inverse/Quaternion Norm'
//  '<S31>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize'
//  '<S32>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/V1'
//  '<S33>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/V2'
//  '<S34>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/V3'
//  '<S35>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S36>'  : 'full_loop/Modèle Physique/Sensor Noise/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S37>'  : 'full_loop/ROS Output/Send DVL msg'
//  '<S38>'  : 'full_loop/ROS Output/Send IMU msg'
//  '<S39>'  : 'full_loop/ROS Output/Send to Gazebo'
//  '<S40>'  : 'full_loop/ROS Output/Send DVL msg/   '
//  '<S41>'  : 'full_loop/ROS Output/Send DVL msg/MATLAB Function'
//  '<S42>'  : 'full_loop/ROS Output/Send DVL msg/Publish'
//  '<S43>'  : 'full_loop/ROS Output/Send IMU msg/   '
//  '<S44>'  : 'full_loop/ROS Output/Send IMU msg/MATLAB Function'
//  '<S45>'  : 'full_loop/ROS Output/Send IMU msg/Publish'
//  '<S46>'  : 'full_loop/ROS Output/Send to Gazebo/   '
//  '<S47>'  : 'full_loop/ROS Output/Send to Gazebo/MATLAB Function'
//  '<S48>'  : 'full_loop/ROS Output/Send to Gazebo/Publish'
//  '<S49>'  : 'full_loop/Send PWM to ROS/Blank Message'
//  '<S50>'  : 'full_loop/Send PWM to ROS/MATLAB Function1'
//  '<S51>'  : 'full_loop/Send PWM to ROS/Publish'
//  '<S52>'  : 'full_loop/Send Target Reached /Blank Message'
//  '<S53>'  : 'full_loop/Send Target Reached /Publish'
//  '<S54>'  : 'full_loop/Subsystem Controller/IDLE'
//  '<S55>'  : 'full_loop/Subsystem Controller/JoyStick OpenLoop'
//  '<S56>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC'
//  '<S57>'  : 'full_loop/Subsystem Controller/JoyStick OpenLoop/Discrete Derivative'
//  '<S58>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Bus2Mux'
//  '<S59>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller'
//  '<S60>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC'
//  '<S61>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/xmvs_router'
//  '<S62>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check'
//  '<S63>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S64>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check10'
//  '<S65>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check11'
//  '<S66>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check12'
//  '<S67>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check13'
//  '<S68>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check14'
//  '<S69>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check15'
//  '<S70>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check16'
//  '<S71>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S72>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S73>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check5'
//  '<S74>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check6'
//  '<S75>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check7'
//  '<S76>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check8'
//  '<S77>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Preview Signal Check9'
//  '<S78>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S79>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S80>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S81>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S82>'  : 'full_loop/Subsystem Controller/Quaternion Non linear MPC/Nonlinear MPC Controller/MPC/NLMPC'
//  '<S83>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1'
//  '<S84>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation'
//  '<S85>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation1'
//  '<S86>'  : 'full_loop/Subsystem ProcNav/Rotation Angles to Quaternions'
//  '<S87>'  : 'full_loop/Subsystem ProcNav/Subsystem'
//  '<S88>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Conjugate'
//  '<S89>'  : 'full_loop/Subsystem ProcNav/Quaternion Inverse1/Quaternion Norm'
//  '<S90>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize'
//  '<S91>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V1'
//  '<S92>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V2'
//  '<S93>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/V3'
//  '<S94>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
//  '<S95>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S96>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize'
//  '<S97>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V1'
//  '<S98>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V2'
//  '<S99>'  : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/V3'
//  '<S100>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
//  '<S101>' : 'full_loop/Subsystem ProcNav/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S102>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles'
//  '<S103>' : 'full_loop/Subsystem ProcNav/Subsystem/Radians to Degrees'
//  '<S104>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation'
//  '<S105>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S106>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S107>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S108>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S109>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S110>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S111>' : 'full_loop/Subsystem ProcNav/Subsystem/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S112>' : 'full_loop/Subsystem Trajectory/Subsystem'
//  '<S113>' : 'full_loop/Subsystem Trajectory/SubsystemAuto'
//  '<S114>' : 'full_loop/Subsystem Trajectory/SubsystemManual'
//  '<S115>' : 'full_loop/Subsystem Trajectory/Subsystem/Second-Order Filter'
//  '<S116>' : 'full_loop/Subsystem Trajectory/Subsystem/Subscribe2'
//  '<S117>' : 'full_loop/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)'
//  '<S118>' : 'full_loop/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1'
//  '<S119>' : 'full_loop/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)/Discrete'
//  '<S120>' : 'full_loop/Subsystem Trajectory/Subsystem/Second-Order Filter/Integrator (Discrete or Continuous)1/Discrete'
//  '<S121>' : 'full_loop/Subsystem Trajectory/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S122>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/MATLAB Function'
//  '<S123>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe'
//  '<S124>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe1'
//  '<S125>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe2'
//  '<S126>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subsystem1'
//  '<S127>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subsystem2'
//  '<S128>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe/Enabled Subsystem'
//  '<S129>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe1/Enabled Subsystem'
//  '<S130>' : 'full_loop/Subsystem Trajectory/SubsystemAuto/Subscribe2/Enabled Subsystem'
//  '<S131>' : 'full_loop/Subsystem Trajectory/SubsystemManual/MATLAB Function1'
//  '<S132>' : 'full_loop/Subsystem1/MinMax Running Resettable'
//  '<S133>' : 'full_loop/Subsystem1/Quaternion Normalise'
//  '<S134>' : 'full_loop/Subsystem1/Subscribe'
//  '<S135>' : 'full_loop/Subsystem1/Subscribe1'
//  '<S136>' : 'full_loop/Subsystem1/Subscribe2'
//  '<S137>' : 'full_loop/Subsystem1/MinMax Running Resettable/Subsystem'
//  '<S138>' : 'full_loop/Subsystem1/Subscribe/Enabled Subsystem'
//  '<S139>' : 'full_loop/Subsystem1/Subscribe1/Enabled Subsystem'
//  '<S140>' : 'full_loop/Subsystem1/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_full_loop_h_

//
// File trailer for generated code.
//
// [EOF]
//
