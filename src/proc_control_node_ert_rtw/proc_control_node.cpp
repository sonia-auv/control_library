//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node.cpp
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
#include "proc_control_node.h"
#include "proc_control_node_private.h"
#include "proc_control_node_dt.h"

// Named constants for MATLAB Function: '<S144>/FixedHorizonOptimizer'
const real_T proc_control_node_nu = 8.0;
const real_T proc_control_node_ny = 12.0;

// Block signals (default storage)
B_proc_control_node_T proc_control_node_B;

// Continuous states
X_proc_control_node_T proc_control_node_X;

// Block states (default storage)
DW_proc_control_node_T proc_control_node_DW;

// Previous zero-crossings (trigger) states
PrevZCX_proc_control_node_T proc_control_node_PrevZCX;

// Real-time model
RT_MODEL_proc_control_node_T proc_control_node_M_ = RT_MODEL_proc_control_node_T
  ();
RT_MODEL_proc_control_node_T *const proc_control_node_M = &proc_control_node_M_;

// Forward declaration for local functions
static void proc_control_node_quatmultiply(const real_T q[4], const real_T r[4],
  real_T qout[4]);
static void proc_contr_quaternionBase_slerp(real_T q1_a, real_T q1_b, real_T
  q1_c, real_T q1_d, real_T q2_a, real_T q2_b, real_T q2_c, real_T q2_d, real_T
  t, real_T *qo_a, real_T *qo_b, real_T *qo_c, real_T *qo_d);
static void proc_control_quaternionBase_log(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T *b_q_a, real_T *b_q_b, real_T *b_q_c, real_T *b_q_d);
static void proc_contro_SystemCore_step_b4n(robotics_slcore_internal_bl_b_T *obj,
  real_T varargin_1, const real_T varargin_2[4], const real_T varargin_3[4],
  const real_T varargin_4[2], real_T varargout_1[4], real_T varargout_2[3],
  real_T varargout_3[3]);
static real_T proc_control_node_rt_powd_snf(real_T u0, real_T u1);
static void proc_control_node_ppval(const real_T pp_breaks[4], const real_T
  pp_coefs[36], const real_T x[2], real_T v[6]);
static void proc_control_node_cubicpolytraj(const real_T wayPoints[6], const
  real_T timePoints[2], const real_T t[2], const real_T varargin_2[6], real_T q
  [6], real_T qd[6], real_T qdd[6], real_T pp_breaks[4], real_T pp_coefs[36]);
static void proc_control_node_ppval_b(const real_T pp_breaks[4], const real_T
  pp_coefs[36], real_T x, real_T v[3]);
static void TrajectoryManager_SendCurrentPo(TrajectoryManager_proc_contro_T
  *b_this, real_T currPose[130]);
static real_T proc_control_node_norm_b(const real_T x[3]);
static void proc_contr_AUVEULJacobianMatrix(const real_T in1[12], real_T Ane[144]);
static int32_T proc_control_node_xgetrfs(real_T A[400], real_T B[400]);
static void proc_control_node_lusolve(const real_T A[400], const real_T B[400],
  real_T X[400]);
static void proc_co_PadeApproximantOfDegree(const real_T A[400], uint8_T m,
  real_T F[400]);
static void proc_control_node_expm(real_T A[400], real_T F[400]);
static void proc_control_no_mpc_plantupdate(const real_T a[144], real_T b[96],
  const real_T c[144], real_T b_A[400], real_T b_B[580], real_T b_C[240], const
  real_T b_D[348], const real_T b_mvindex[8], const real_T b_myindex[12], const
  real_T b_Uscale[8], const real_T b_Yscale[12], real_T Bu[160], real_T Bv[20],
  real_T Cm[240], real_T Dv[12], real_T Dvm[12], real_T QQ[400], real_T RR[144],
  real_T NN[240]);
static real_T proc_control_node_mod_g(real_T x);
static real_T proc_control_node_mod(real_T x);
static void proc_cont_mpc_updateFromNominal(real_T b_Mlim[64], const real_T
  b_Mrows[64], const real_T U0[8], const real_T b_Uscale[8], const real_T
  old_mvoff[8], const real_T b_mvindex[8], real_T b_utarget[80], const real_T
  Y0[12], const real_T b_Yscale[12], const real_T old_yoff[12], const real_T
  b_myindex[12], const real_T X0[12], real_T b_xoff[20], const real_T DX0[12],
  real_T Bv[220], real_T new_mvoff[8], real_T new_yoff[12], real_T new_myoff[12]);
static void proc_control_node_xgetrf(real_T b_A[144], int32_T ipiv[12], int32_T *
  info);
static void proc_control_node_mrdiv_c(const real_T b_A[144], const real_T b_B
  [144], real_T Y[144]);
static void proc_control_mpc_constraintcoef(const real_T b_A[400], const real_T
  Bu[160], const real_T Bv[20], const real_T b_C[240], const real_T Dv[12],
  const real_T b_Jm[2560], real_T b_SuJm[3840], real_T b_Sx[2400], real_T b_Su1
  [960], real_T b_Hv[1320]);
static void proc_control_node_WtMult(const real_T W[8], const real_T M[2560],
  real_T nwt, real_T WM[2560]);
static void proc_contr_mpc_calculatehessian(const real_T b_Wy[12], const real_T
  b_Wu[8], const real_T b_Wdu[8], const real_T b_SuJm[3840], const real_T I2Jm
  [2560], const real_T b_Jm[2560], const real_T b_I1[640], const real_T b_Su1
  [960], const real_T b_Sx[2400], const real_T b_Hv[1320], real_T nmv, real_T
  b_ny, real_T b_H[1024], real_T b_Ku1[256], real_T b_Kut[2560], real_T b_Kx[640],
  real_T b_Kv[352], real_T b_Kr[3840]);
static int32_T proc_control_node_xpotrf(real_T b_A[1089]);
static real_T proc_control_node_minimum(const real_T x[33]);
static void proc_control_n_mpc_checkhessian(real_T b_H[1089], real_T L[1089],
  real_T *BadH);
static void proc_control_node_trisolve(const real_T b_A[1089], real_T b_B[1089]);
static void proc_control_node_Unconstrained(const real_T b_Hinv[1089], const
  real_T f[33], real_T x[33], int16_T n);
static real_T proc_control_node_norm(const real_T x[33]);
static void proc_control_node_abs(const real_T x[33], real_T y[33]);
static real_T proc_control_node_maximum(const real_T x[33]);
static void proc_control_node_abs_i(const real_T x[64], real_T y[64]);
static void proc_control_node_maximum2(const real_T x[64], real_T y, real_T ex
  [64]);
static real_T proc_control_node_xnrm2(int32_T n, const real_T x[1089], int32_T
  ix0);
static void proc_control_node_xgemv(int32_T b_m, int32_T n, const real_T b_A
  [1089], int32_T ia0, const real_T x[1089], int32_T ix0, real_T y[33]);
static void proc_control_node_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[33], real_T b_A[1089], int32_T ia0);
static void proc_control_node_xzlarf(int32_T b_m, int32_T n, int32_T iv0, real_T
  tau, real_T b_C[1089], int32_T ic0, real_T work[33]);
static void proc_control_node_qrf(real_T b_A[1089], int32_T ia0, int32_T b_m,
  int32_T n, int32_T nfxd, real_T tau[33]);
static void proc_control_node_xgeqrf(real_T b_A[1089], real_T tau[33]);
static void proc_control_node_xorgqr(int32_T b_m, int32_T n, int32_T k, real_T
  b_A[1089], int32_T ia0, const real_T tau[33], int32_T itau0);
static void proc_control_node_qr(const real_T b_A[1089], real_T Q[1089], real_T
  R[1089]);
static void proc_control_node_KWIKfactor(const real_T b_Ac[2112], const int16_T
  iC[64], int16_T nA, const real_T b_Linv[1089], real_T b_D[1089], real_T b_H
  [1089], int16_T n, real_T RLinv[1089], real_T *Status);
static real_T proc_control_node_mtimes(const real_T b_A[33], const real_T b_B[33]);
static void proc_control_nod_DropConstraint(int16_T kDrop, int16_T iA[64],
  int16_T *nA, int16_T iC[64]);
static void proc_control_node_qpkwik(const real_T b_Linv[1089], const real_T
  b_Hinv[1089], const real_T f[33], const real_T b_Ac[2112], const real_T b[64],
  int16_T iA[64], int16_T maxiter, real_T FeasTol, real_T x[33], real_T lambda
  [64], real_T *status);
static void proc_control_node_mpc_solveQP(const real_T xQP[20], const real_T
  b_Kx[640], const real_T b_Kr[3840], const real_T rseq[120], const real_T
  b_Ku1[256], const real_T old_u[8], const real_T b_Kv[352], const real_T vseq
  [11], const real_T b_Kut[2560], const real_T b_utarget[80], const real_T
  b_Linv[1089], const real_T b_Hinv[1089], const real_T b_Ac[2112], const real_T
  Bc[64], boolean_T iA[64], real_T zopt[33], real_T f[33], real_T *status);
static void proc_control_mpcblock_optimizer(const real_T rseq[120], const real_T
  vseq[11], const real_T x[20], const real_T old_u[8], const boolean_T iA[64],
  const real_T b_Mlim[64], real_T b_Mx[1280], real_T b_Mu1[512], real_T b_Mv[704],
  const real_T b_utarget[80], const real_T b_uoff[8], real_T b_H[1089], real_T
  b_Ac[2112], const real_T b_Wy[12], const real_T b_Wdu[8], const real_T b_Jm
  [2560], const real_T b_Wu[8], const real_T b_I1[640], const real_T b_A[400],
  const real_T Bu[1760], const real_T Bv[220], const real_T b_C[240], const
  real_T Dv[132], const real_T b_Mrows[64], real_T u[8], real_T useq[88], real_T
  *status, boolean_T iAout[64]);
static boolean_T proc_control_node_isequal(const real_T varargin_1[3], const
  real_T varargin_2[3]);
static boolean_T proc_control_node_isequal_b4(const real_T varargin_1[6], const
  real_T varargin_2[6]);
static real_T proc_control_node_erf(real_T x);
static void proc_con_AUVQuatPerturbedSimFcn(const real_T in1[13], const real_T
  in2[6], const real_T in3[8], real_T out1[13]);
static void imuSensor_set_MagneticFieldNED(fusion_simulink_imuSensor_pro_T *obj,
  const real_T val[3]);
static void IMUSensorParameters_updateSyste(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3],
  h_fusion_internal_Acceleromet_T *sobj);
static void IMUSensorParameters_updateSys_b(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3], const
  real_T obj_AccelerationBias[3], h_fusion_internal_GyroscopeSi_T *sobj);
static void IMUSensorParameters_updateSy_b4(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3],
  h_fusion_internal_Magnetomete_T *sobj);
static boolean_T proc_control_node_vectorAny(const boolean_T x_data[], const
  int32_T x_size[2]);
static void proc_co_genrand_uint32_vector_b(uint32_T mt[625], uint32_T u[2]);
static real_T proc_control_node_genrandu_b(uint32_T mt[625]);
static real_T proc_contr_eml_rand_mt19937ar_b(uint32_T state[625]);
static void IMUSensorBase_stepRandomStream(fusion_simulink_imuSensor_pro_T *obj,
  real_T whiteNoise[27]);
static void proc_control_node_filter(real_T b, real_T a[2], const real_T x[3],
  const real_T zi[3], real_T y[3], real_T zf[3]);
static void proc_control__SystemCore_step_b(h_fusion_internal_Acceleromet_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[9], const real_T
  varargin_3[9], real_T varargout_1[3]);
static void proc_control_SystemCore_step_b4(h_fusion_internal_GyroscopeSi_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[9], const real_T varargin_4[9], real_T varargout_1[3]);
static void proc_control_no_SystemCore_step(fusion_simulink_imuSensor_pro_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[4], real_T varargout_1[3], real_T varargout_2[3], real_T
  varargout_3[3]);
static void IMUFusionCommon_computeAngularV(const real_T gfast[3], const real_T
  offset[3], real_T av[3]);
static void proc_control_node_NED_ecompass(const real_T a[3], const real_T m[3],
  real_T R[9]);
static void proc_cont_quaternion_quaternion(const real_T varargin_1[9], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void proc_co_quaternion_quaternion_b(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void IMUFusionCommon_predictOrientat(const
  fusion_simulink_ahrsfilter_pr_T *obj, const real_T gfast[3], const real_T
  offset[3], real_T qorient_a, real_T qorient_b, real_T qorient_c, real_T
  qorient_d, real_T *b_qorient_a, real_T *b_qorient_b, real_T *b_qorient_c,
  real_T *b_qorient_d);
static void proc_cont_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9]);
static void proc_control_node_mrdiv(const real_T A[72], const real_T B[36],
  real_T Y[72]);
static void proc_contro_ahrsfilter_stepImpl(fusion_simulink_ahrsfilter_pr_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], const real_T magIn[3], real_T
  orientOut[4], real_T av[3]);
static void pro_TrajectoryManager_setupImpl(TrajectoryManager_proc_contro_T
  *b_this);
static void proc_control_n_SystemCore_setup(fusion_simulink_imuSensor_pro_T *obj);
static void proc_co_IMUSensorBase_resetImpl(fusion_simulink_imuSensor_pro_T *obj);
static void proc_c_AHRSFilterBase_resetImpl(fusion_simulink_ahrsfilter_pr_T *obj);
static void rate_scheduler(void);
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
    bpIndex = binsearch_u32d_prevIdx(u, bp, *prevIndex, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

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
    bpIndex = binsearch_u32u16_prevIdx(u, bp, *prevIndex, maxIndex);
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

uint32_T plook_u32d_binckpan(real_T u, const real_T bp[], uint32_T maxIndex,
  uint32_T *prevIndex)
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
    bpIndex = binsearch_u32d_prevIdx(u, bp, *prevIndex, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

uint32_T binsearch_u32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  // Binary Search using Previous Index
  bpIndex = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIndex]) {
      iRght = bpIndex - 1U;
      bpIndex = ((bpIndex + iLeft) - 1U) >> 1U;
    } else if (u < bp[bpIndex + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIndex + 1U;
      bpIndex = ((bpIndex + iRght) + 1U) >> 1U;
    }
  }

  return bpIndex;
}

uint32_T binsearch_u32u16_prevIdx(uint16_T u, const uint16_T bp[], uint32_T
  startIndex, uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  // Binary Search using Previous Index
  bpIndex = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIndex]) {
      iRght = bpIndex - 1U;
      bpIndex = ((bpIndex + iLeft) - 1U) >> 1U;
    } else if (u < bp[bpIndex + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIndex + 1U;
      bpIndex = ((bpIndex + iRght) + 1U) >> 1U;
    }
  }

  return bpIndex;
}

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (proc_control_node_M->Timing.TaskCounters.TID[2])++;
  if ((proc_control_node_M->Timing.TaskCounters.TID[2]) > 2) {// Sample time: [0.05s, 0.0s] 
    proc_control_node_M->Timing.TaskCounters.TID[2] = 0;
  }

  (proc_control_node_M->Timing.TaskCounters.TID[3])++;
  if ((proc_control_node_M->Timing.TaskCounters.TID[3]) > 5) {// Sample time: [0.1s, 0.0s] 
    proc_control_node_M->Timing.TaskCounters.TID[3] = 0;
  }

  (proc_control_node_M->Timing.TaskCounters.TID[4])++;
  if ((proc_control_node_M->Timing.TaskCounters.TID[4]) > 59) {// Sample time: [1.0s, 0.0s] 
    proc_control_node_M->Timing.TaskCounters.TID[4] = 0;
  }

  (proc_control_node_M->Timing.TaskCounters.TID[5])++;
  if ((proc_control_node_M->Timing.TaskCounters.TID[5]) > 299) {// Sample time: [5.0s, 0.0s] 
    proc_control_node_M->Timing.TaskCounters.TID[5] = 0;
  }
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  proc_control_node_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  proc_control_node_step();
  proc_control_node_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  proc_control_node_step();
  proc_control_node_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// System initialize for enable system:
//    '<S85>/Subsystem2'
//    '<S155>/Subsystem2'
//
void proc_control_no_Subsystem2_Init(real_T *rty_Quat, real_T *rty_Quat_a,
  real_T *rty_Quat_i, real_T *rty_Quat_p, P_Subsystem2_proc_control_nod_T
  *localP)
{
  // SystemInitialize for Outport: '<S91>/Quat'
  *rty_Quat = localP->Quat_Y0;
  *rty_Quat_a = localP->Quat_Y0;
  *rty_Quat_i = localP->Quat_Y0;
  *rty_Quat_p = localP->Quat_Y0;
}

//
// Output and update for enable system:
//    '<S85>/Subsystem2'
//    '<S155>/Subsystem2'
//
void proc_control_node_Subsystem2(RT_MODEL_proc_control_node_T * const
  proc_control_node_M, real_T rtu_Enable, real_T *rty_Quat, real_T *rty_Quat_a,
  real_T *rty_Quat_i, real_T *rty_Quat_p, DW_Subsystem2_proc_control_no_T
  *localDW, P_Subsystem2_proc_control_nod_T *localP)
{
  real_T rtb_sincos_o1_b_idx_0;
  real_T rtb_sincos_o1_b_idx_1;
  real_T rtb_sincos_o1_b_idx_2;
  real_T rtb_sincos_o2_m_idx_0;
  real_T rtb_sincos_o2_m_idx_1;
  real_T rtb_sincos_o2_m_idx_2;
  real_T tmp;
  real_T tmp_0;

  // Outputs for Enabled SubSystem: '<S85>/Subsystem2' incorporates:
  //   EnablePort: '<S91>/Enable'

  if (rtu_Enable > 0.0) {
    // Gain: '<S92>/1//2' incorporates:
    //   Constant: '<S91>/si y devant'

    rtb_sincos_o2_m_idx_2 = localP->u2_Gain * localP->siydevant_Value[0];

    // Trigonometry: '<S92>/sincos'
    rtb_sincos_o1_b_idx_0 = sin(rtb_sincos_o2_m_idx_2);
    rtb_sincos_o2_m_idx_0 = cos(rtb_sincos_o2_m_idx_2);

    // Gain: '<S92>/1//2' incorporates:
    //   Constant: '<S91>/si y devant'

    rtb_sincos_o2_m_idx_2 = localP->u2_Gain * localP->siydevant_Value[1];

    // Trigonometry: '<S92>/sincos'
    rtb_sincos_o1_b_idx_1 = sin(rtb_sincos_o2_m_idx_2);
    rtb_sincos_o2_m_idx_1 = cos(rtb_sincos_o2_m_idx_2);

    // Gain: '<S92>/1//2' incorporates:
    //   Constant: '<S91>/si y devant'

    rtb_sincos_o2_m_idx_2 = localP->u2_Gain * localP->siydevant_Value[2];

    // Trigonometry: '<S92>/sincos'
    rtb_sincos_o1_b_idx_2 = sin(rtb_sincos_o2_m_idx_2);
    rtb_sincos_o2_m_idx_2 = cos(rtb_sincos_o2_m_idx_2);

    // Fcn: '<S92>/q0' incorporates:
    //   Fcn: '<S92>/q3'

    tmp = rtb_sincos_o2_m_idx_0 * rtb_sincos_o2_m_idx_1;
    tmp_0 = rtb_sincos_o1_b_idx_0 * rtb_sincos_o1_b_idx_1;
    *rty_Quat = tmp * rtb_sincos_o2_m_idx_2 - tmp_0 * rtb_sincos_o1_b_idx_2;

    // Fcn: '<S92>/q1' incorporates:
    //   Fcn: '<S92>/q2'

    rtb_sincos_o2_m_idx_0 *= rtb_sincos_o1_b_idx_1;
    rtb_sincos_o1_b_idx_0 *= rtb_sincos_o2_m_idx_1;
    *rty_Quat_a = rtb_sincos_o2_m_idx_0 * rtb_sincos_o1_b_idx_2 +
      rtb_sincos_o1_b_idx_0 * rtb_sincos_o2_m_idx_2;

    // Fcn: '<S92>/q2'
    *rty_Quat_i = rtb_sincos_o2_m_idx_0 * rtb_sincos_o2_m_idx_2 -
      rtb_sincos_o1_b_idx_0 * rtb_sincos_o1_b_idx_2;

    // Fcn: '<S92>/q3'
    *rty_Quat_p = tmp * rtb_sincos_o1_b_idx_2 + tmp_0 * rtb_sincos_o2_m_idx_2;
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      srUpdateBC(localDW->Subsystem2_SubsysRanBC);
    }
  }

  // End of Outputs for SubSystem: '<S85>/Subsystem2'
}

//
// Output and update for atomic system:
//    '<S190>/MATLAB Function1'
//    '<S188>/MATLAB Function1'
//
void proc_control_no_MATLABFunction1(const real_T rtu_matrix[13], real_T rty_y
  [130], B_MATLABFunction1_proc_contro_T *localB)
{
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  memcpy(&localB->matrix[0], &rtu_matrix[0], 13U * sizeof(real_T));
  localB->matrix[9] = -rtu_matrix[9];
  for (jcol = 0; jcol < 13; jcol++) {
    ibmat = jcol * 10;
    for (itilerow = 0; itilerow < 10; itilerow++) {
      rty_y[ibmat + itilerow] = localB->matrix[jcol];
    }
  }
}

static void proc_control_node_quatmultiply(const real_T q[4], const real_T r[4],
  real_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - r[2] * q[3]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (r[1] * q[3] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - r[1] * q[2]);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void proc_contr_quaternionBase_slerp(real_T q1_a, real_T q1_b, real_T
  q1_c, real_T q1_d, real_T q2_a, real_T q2_b, real_T q2_c, real_T q2_d, real_T
  t, real_T *qo_a, real_T *qo_b, real_T *qo_c, real_T *qo_d)
{
  proc_control_node_B.n_p = sqrt(((q1_a * q1_a + q1_b * q1_b) + q1_c * q1_c) +
    q1_d * q1_d);
  proc_control_node_B.q1n_a = q1_a / proc_control_node_B.n_p;
  proc_control_node_B.q1n_b_o = q1_b / proc_control_node_B.n_p;
  proc_control_node_B.q1n_c_j = q1_c / proc_control_node_B.n_p;
  proc_control_node_B.q1n_d_c = q1_d / proc_control_node_B.n_p;
  proc_control_node_B.n_p = sqrt(((q2_a * q2_a + q2_b * q2_b) + q2_c * q2_c) +
    q2_d * q2_d);
  proc_control_node_B.q2n_a = q2_a / proc_control_node_B.n_p;
  proc_control_node_B.q2n_b_h = q2_b / proc_control_node_B.n_p;
  proc_control_node_B.q2n_c_d = q2_c / proc_control_node_B.n_p;
  proc_control_node_B.n_p = q2_d / proc_control_node_B.n_p;
  proc_control_node_B.dp_c = ((proc_control_node_B.q1n_a *
    proc_control_node_B.q2n_a + proc_control_node_B.q1n_b_o *
    proc_control_node_B.q2n_b_h) + proc_control_node_B.q1n_c_j *
    proc_control_node_B.q2n_c_d) + proc_control_node_B.q1n_d_c *
    proc_control_node_B.n_p;
  if (proc_control_node_B.dp_c < 0.0) {
    proc_control_node_B.q2n_a = -proc_control_node_B.q2n_a;
    proc_control_node_B.q2n_b_h = -proc_control_node_B.q2n_b_h;
    proc_control_node_B.q2n_c_d = -proc_control_node_B.q2n_c_d;
    proc_control_node_B.n_p = -proc_control_node_B.n_p;
    proc_control_node_B.dp_c = -proc_control_node_B.dp_c;
  }

  if (proc_control_node_B.dp_c > 1.0) {
    proc_control_node_B.dp_c = 1.0;
  }

  proc_control_node_B.theta0_p = acos(proc_control_node_B.dp_c);
  proc_control_node_B.dp_c = 1.0 / sin(proc_control_node_B.theta0_p);
  proc_control_node_B.b_x = sin((1.0 - t) * proc_control_node_B.theta0_p);
  proc_control_node_B.theta0_p = sin(t * proc_control_node_B.theta0_p);
  *qo_a = (proc_control_node_B.b_x * proc_control_node_B.q1n_a +
           proc_control_node_B.theta0_p * proc_control_node_B.q2n_a) *
    proc_control_node_B.dp_c;
  *qo_b = (proc_control_node_B.b_x * proc_control_node_B.q1n_b_o +
           proc_control_node_B.theta0_p * proc_control_node_B.q2n_b_h) *
    proc_control_node_B.dp_c;
  *qo_c = (proc_control_node_B.b_x * proc_control_node_B.q1n_c_j +
           proc_control_node_B.theta0_p * proc_control_node_B.q2n_c_d) *
    proc_control_node_B.dp_c;
  *qo_d = (proc_control_node_B.b_x * proc_control_node_B.q1n_d_c +
           proc_control_node_B.theta0_p * proc_control_node_B.n_p) *
    proc_control_node_B.dp_c;
  if (rtIsInf(proc_control_node_B.dp_c)) {
    *qo_a = proc_control_node_B.q1n_a;
    *qo_b = proc_control_node_B.q1n_b_o;
    *qo_c = proc_control_node_B.q1n_c_j;
    *qo_d = proc_control_node_B.q1n_d_c;
  }

  proc_control_node_B.n_p = sqrt(((*qo_a * *qo_a + *qo_b * *qo_b) + *qo_c *
    *qo_c) + *qo_d * *qo_d);
  *qo_a /= proc_control_node_B.n_p;
  *qo_b /= proc_control_node_B.n_p;
  *qo_c /= proc_control_node_B.n_p;
  *qo_d /= proc_control_node_B.n_p;
}

static void proc_control_quaternionBase_log(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T *b_q_a, real_T *b_q_b, real_T *b_q_c, real_T *b_q_d)
{
  proc_control_node_B.vnorm = sqrt((q_b * q_b + q_c * q_c) + q_d * q_d);
  proc_control_node_B.qnorm = sqrt(q_a * q_a + proc_control_node_B.vnorm *
    proc_control_node_B.vnorm);
  proc_control_node_B.b_i_n = 0;
  if (proc_control_node_B.vnorm != 0.0) {
    for (proc_control_node_B.nx_g = 0; proc_control_node_B.nx_g < 1;
         proc_control_node_B.nx_g++) {
      proc_control_node_B.b_i_n++;
    }
  }

  proc_control_node_B.vscale_size_idx_1 = proc_control_node_B.b_i_n;
  proc_control_node_B.b_i_n--;
  for (proc_control_node_B.nx_g = 0; proc_control_node_B.nx_g <=
       proc_control_node_B.b_i_n; proc_control_node_B.nx_g++) {
    proc_control_node_B.vscale_data = q_a / proc_control_node_B.qnorm;
  }

  if (0 <= proc_control_node_B.vscale_size_idx_1 - 1) {
    proc_control_node_B.x_data_tmp = 0;
    proc_control_node_B.x_data = proc_control_node_B.vscale_data;
  }

  proc_control_node_B.nx_g = proc_control_node_B.vscale_size_idx_1 - 1;
  for (proc_control_node_B.b_i_n = 0; proc_control_node_B.b_i_n <=
       proc_control_node_B.nx_g; proc_control_node_B.b_i_n++) {
    proc_control_node_B.x_data_tmp = 0;
    proc_control_node_B.x_data = acos(proc_control_node_B.x_data);
  }

  if (0 <= proc_control_node_B.vscale_size_idx_1 - 1) {
    proc_control_node_B.b_i_n = 0;
    proc_control_node_B.vscale_data = proc_control_node_B.x_data /
      proc_control_node_B.vnorm;
  }

  if (0 <= proc_control_node_B.vscale_size_idx_1 - 1) {
    proc_control_node_B.x_data_tmp = 0;
    proc_control_node_B.x_data = q_b * proc_control_node_B.vscale_data;
  }

  *b_q_d = q_b;
  proc_control_node_B.nx_g = 0;
  if (proc_control_node_B.vnorm != 0.0) {
    for (proc_control_node_B.b_i_n = 0; proc_control_node_B.b_i_n < 1;
         proc_control_node_B.b_i_n++) {
      *b_q_d = proc_control_node_B.x_data;
      proc_control_node_B.nx_g++;
    }
  }

  *b_q_b = *b_q_d;
  if (!(proc_control_node_B.vnorm != 0.0)) {
    *b_q_b = 0.0;
  }

  if (0 <= proc_control_node_B.vscale_size_idx_1 - 1) {
    proc_control_node_B.x_data_tmp = 0;
    proc_control_node_B.x_data = q_c * proc_control_node_B.vscale_data;
  }

  *b_q_d = q_c;
  proc_control_node_B.nx_g = 0;
  if (proc_control_node_B.vnorm != 0.0) {
    for (proc_control_node_B.b_i_n = 0; proc_control_node_B.b_i_n < 1;
         proc_control_node_B.b_i_n++) {
      *b_q_d = proc_control_node_B.x_data;
      proc_control_node_B.nx_g++;
    }
  }

  *b_q_c = *b_q_d;
  if (!(proc_control_node_B.vnorm != 0.0)) {
    *b_q_c = 0.0;
  }

  if (0 <= proc_control_node_B.vscale_size_idx_1 - 1) {
    proc_control_node_B.x_data_tmp = 0;
    proc_control_node_B.x_data = q_d * proc_control_node_B.vscale_data;
  }

  *b_q_d = q_d;
  proc_control_node_B.nx_g = 0;
  if (proc_control_node_B.vnorm != 0.0) {
    for (proc_control_node_B.b_i_n = 0; proc_control_node_B.b_i_n < 1;
         proc_control_node_B.b_i_n++) {
      *b_q_d = proc_control_node_B.x_data;
      proc_control_node_B.nx_g++;
    }
  }

  if (!(proc_control_node_B.vnorm != 0.0)) {
    *b_q_d = 0.0;
  }

  *b_q_a = log(proc_control_node_B.qnorm);
}

static void proc_contro_SystemCore_step_b4n(robotics_slcore_internal_bl_b_T *obj,
  real_T varargin_1, const real_T varargin_2[4], const real_T varargin_3[4],
  const real_T varargin_4[2], real_T varargout_1[4], real_T varargout_2[3],
  real_T varargout_3[3])
{
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }

  proc_control_node_B.linearScaling = 1.0 / (varargin_4[1] - varargin_4[0]);
  proc_control_node_B.b_idx_0 = (varargin_1 - varargin_4[0]) *
    proc_control_node_B.linearScaling;
  if (varargin_1 < varargin_4[0]) {
    proc_control_node_B.b_idx_0 = 0.0;
  }

  if (varargin_1 > varargin_4[1]) {
    proc_control_node_B.b_idx_0 = 1.0;
  }

  if (varargin_1 < varargin_4[0]) {
    proc_control_node_B.linearScaling = 0.0;
  }

  proc_control_node_B.e_idx_0 = proc_control_node_B.linearScaling;
  if (varargin_1 > varargin_4[1]) {
    proc_control_node_B.e_idx_0 = 0.0;
  }

  proc_control_node_B.n_n = sqrt(((varargin_2[0] * varargin_2[0] + varargin_2[1]
    * varargin_2[1]) + varargin_2[2] * varargin_2[2]) + varargin_2[3] *
    varargin_2[3]);
  proc_control_node_B.pn_a = varargin_2[0] / proc_control_node_B.n_n;
  proc_control_node_B.pn_b = varargin_2[1] / proc_control_node_B.n_n;
  proc_control_node_B.pn_c = varargin_2[2] / proc_control_node_B.n_n;
  proc_control_node_B.pn_d = varargin_2[3] / proc_control_node_B.n_n;
  proc_control_node_B.n_n = sqrt(((varargin_3[0] * varargin_3[0] + varargin_3[1]
    * varargin_3[1]) + varargin_3[2] * varargin_3[2]) + varargin_3[3] *
    varargin_3[3]);
  proc_control_node_B.qn_a = varargin_3[0] / proc_control_node_B.n_n;
  proc_control_node_B.qn_b = varargin_3[1] / proc_control_node_B.n_n;
  proc_control_node_B.qn_c = varargin_3[2] / proc_control_node_B.n_n;
  proc_control_node_B.qn_d = varargin_3[3] / proc_control_node_B.n_n;
  proc_control_node_B.n_tmp = sqrt(((proc_control_node_B.pn_a *
    proc_control_node_B.pn_a + proc_control_node_B.pn_b *
    proc_control_node_B.pn_b) + proc_control_node_B.pn_c *
    proc_control_node_B.pn_c) + proc_control_node_B.pn_d *
    proc_control_node_B.pn_d);
  proc_control_node_B.n_tmp_d = proc_control_node_B.pn_a /
    proc_control_node_B.n_tmp;
  proc_control_node_B.q1n_b = proc_control_node_B.pn_b /
    proc_control_node_B.n_tmp;
  proc_control_node_B.q1n_c = proc_control_node_B.pn_c /
    proc_control_node_B.n_tmp;
  proc_control_node_B.q1n_d = proc_control_node_B.pn_d /
    proc_control_node_B.n_tmp;
  proc_control_node_B.n_tmp_p = sqrt(((proc_control_node_B.qn_a *
    proc_control_node_B.qn_a + proc_control_node_B.qn_b *
    proc_control_node_B.qn_b) + proc_control_node_B.qn_c *
    proc_control_node_B.qn_c) + proc_control_node_B.qn_d *
    proc_control_node_B.qn_d);
  proc_control_node_B.n_tmp = proc_control_node_B.qn_a /
    proc_control_node_B.n_tmp_p;
  proc_control_node_B.n_n = proc_control_node_B.n_tmp;
  proc_control_node_B.q2n_b_tmp = proc_control_node_B.qn_b /
    proc_control_node_B.n_tmp_p;
  proc_control_node_B.q2n_b = proc_control_node_B.q2n_b_tmp;
  proc_control_node_B.q2n_c_tmp = proc_control_node_B.qn_c /
    proc_control_node_B.n_tmp_p;
  proc_control_node_B.q2n_c = proc_control_node_B.q2n_c_tmp;
  proc_control_node_B.n_tmp_p = proc_control_node_B.qn_d /
    proc_control_node_B.n_tmp_p;
  proc_control_node_B.q2n_d = proc_control_node_B.n_tmp_p;
  proc_control_node_B.dp_tmp = ((proc_control_node_B.n_tmp_d *
    proc_control_node_B.n_tmp + proc_control_node_B.q1n_b *
    proc_control_node_B.q2n_b_tmp) + proc_control_node_B.q1n_c *
    proc_control_node_B.q2n_c_tmp) + proc_control_node_B.q1n_d *
    proc_control_node_B.n_tmp_p;
  proc_control_node_B.dp = proc_control_node_B.dp_tmp;
  if (proc_control_node_B.dp_tmp < 0.0) {
    proc_control_node_B.n_n = -proc_control_node_B.n_tmp;
    proc_control_node_B.q2n_b = -proc_control_node_B.q2n_b_tmp;
    proc_control_node_B.q2n_c = -proc_control_node_B.q2n_c_tmp;
    proc_control_node_B.q2n_d = -proc_control_node_B.n_tmp_p;
    proc_control_node_B.dp = -proc_control_node_B.dp_tmp;
  }

  if (proc_control_node_B.dp > 1.0) {
    proc_control_node_B.dp = 1.0;
  }

  proc_control_node_B.theta0 = acos(proc_control_node_B.dp);
  proc_control_node_B.sinv_tmp = sin(proc_control_node_B.theta0);
  proc_control_node_B.dp = 1.0 / proc_control_node_B.sinv_tmp;
  proc_control_node_B.theta0 = sin(0.0 * proc_control_node_B.theta0);
  proc_control_node_B.linearScaling = (proc_control_node_B.sinv_tmp *
    proc_control_node_B.n_tmp_d + proc_control_node_B.theta0 *
    proc_control_node_B.n_n) * proc_control_node_B.dp;
  proc_control_node_B.pnCorrected_b = (proc_control_node_B.sinv_tmp *
    proc_control_node_B.q1n_b + proc_control_node_B.theta0 *
    proc_control_node_B.q2n_b) * proc_control_node_B.dp;
  proc_control_node_B.pnCorrected_c = (proc_control_node_B.sinv_tmp *
    proc_control_node_B.q1n_c + proc_control_node_B.theta0 *
    proc_control_node_B.q2n_c) * proc_control_node_B.dp;
  proc_control_node_B.pnCorrected_d = (proc_control_node_B.sinv_tmp *
    proc_control_node_B.q1n_d + proc_control_node_B.theta0 *
    proc_control_node_B.q2n_d) * proc_control_node_B.dp;
  if (rtIsInf(proc_control_node_B.dp)) {
    proc_control_node_B.linearScaling = proc_control_node_B.n_tmp_d;
    proc_control_node_B.pnCorrected_b = proc_control_node_B.q1n_b;
    proc_control_node_B.pnCorrected_c = proc_control_node_B.q1n_c;
    proc_control_node_B.pnCorrected_d = proc_control_node_B.q1n_d;
  }

  proc_control_node_B.n_n = sqrt(((proc_control_node_B.linearScaling *
    proc_control_node_B.linearScaling + proc_control_node_B.pnCorrected_b *
    proc_control_node_B.pnCorrected_b) + proc_control_node_B.pnCorrected_c *
    proc_control_node_B.pnCorrected_c) + proc_control_node_B.pnCorrected_d *
    proc_control_node_B.pnCorrected_d);
  proc_control_node_B.linearScaling /= proc_control_node_B.n_n;
  proc_control_node_B.pnCorrected_b /= proc_control_node_B.n_n;
  proc_control_node_B.pnCorrected_c /= proc_control_node_B.n_n;
  proc_control_node_B.pnCorrected_d /= proc_control_node_B.n_n;
  proc_control_node_B.n_n = proc_control_node_B.n_tmp;
  proc_control_node_B.q2n_b = proc_control_node_B.q2n_b_tmp;
  proc_control_node_B.q2n_c = proc_control_node_B.q2n_c_tmp;
  proc_control_node_B.q2n_d = proc_control_node_B.n_tmp_p;
  proc_control_node_B.dp = proc_control_node_B.dp_tmp;
  if (proc_control_node_B.dp_tmp < 0.0) {
    proc_control_node_B.n_n = -proc_control_node_B.n_tmp;
    proc_control_node_B.q2n_b = -proc_control_node_B.q2n_b_tmp;
    proc_control_node_B.q2n_c = -proc_control_node_B.q2n_c_tmp;
    proc_control_node_B.q2n_d = -proc_control_node_B.n_tmp_p;
    proc_control_node_B.dp = -proc_control_node_B.dp_tmp;
  }

  if (proc_control_node_B.dp > 1.0) {
    proc_control_node_B.dp = 1.0;
  }

  proc_control_node_B.theta0 = acos(proc_control_node_B.dp);
  proc_control_node_B.sinv_tmp = sin(proc_control_node_B.theta0);
  proc_control_node_B.dp = 1.0 / proc_control_node_B.sinv_tmp;
  proc_control_node_B.theta0 = sin(0.0 * proc_control_node_B.theta0);
  proc_control_node_B.n_tmp = (proc_control_node_B.theta0 *
    proc_control_node_B.n_tmp_d + proc_control_node_B.sinv_tmp *
    proc_control_node_B.n_n) * proc_control_node_B.dp;
  proc_control_node_B.n_tmp_p = (proc_control_node_B.theta0 *
    proc_control_node_B.q1n_b + proc_control_node_B.sinv_tmp *
    proc_control_node_B.q2n_b) * proc_control_node_B.dp;
  proc_control_node_B.q2n_c = (proc_control_node_B.theta0 *
    proc_control_node_B.q1n_c + proc_control_node_B.sinv_tmp *
    proc_control_node_B.q2n_c) * proc_control_node_B.dp;
  proc_control_node_B.q2n_d = (proc_control_node_B.theta0 *
    proc_control_node_B.q1n_d + proc_control_node_B.sinv_tmp *
    proc_control_node_B.q2n_d) * proc_control_node_B.dp;
  if (rtIsInf(proc_control_node_B.dp)) {
    proc_control_node_B.n_tmp = proc_control_node_B.n_tmp_d;
    proc_control_node_B.n_tmp_p = proc_control_node_B.q1n_b;
    proc_control_node_B.q2n_c = proc_control_node_B.q1n_c;
    proc_control_node_B.q2n_d = proc_control_node_B.q1n_d;
  }

  proc_control_node_B.n_n = sqrt(((proc_control_node_B.n_tmp *
    proc_control_node_B.n_tmp + proc_control_node_B.n_tmp_p *
    proc_control_node_B.n_tmp_p) + proc_control_node_B.q2n_c *
    proc_control_node_B.q2n_c) + proc_control_node_B.q2n_d *
    proc_control_node_B.q2n_d);
  proc_control_node_B.n_tmp /= proc_control_node_B.n_n;
  proc_control_node_B.n_tmp_p /= proc_control_node_B.n_n;
  proc_control_node_B.q2n_c /= proc_control_node_B.n_n;
  proc_control_node_B.q2n_d /= proc_control_node_B.n_n;
  proc_contr_quaternionBase_slerp(proc_control_node_B.pn_a,
    proc_control_node_B.pn_b, proc_control_node_B.pn_c, proc_control_node_B.pn_d,
    proc_control_node_B.qn_a, proc_control_node_B.qn_b, proc_control_node_B.qn_c,
    proc_control_node_B.qn_d, proc_control_node_B.b_idx_0,
    &proc_control_node_B.n_n, &proc_control_node_B.q1n_b,
    &proc_control_node_B.q1n_c, &proc_control_node_B.q1n_d);
  proc_control_quaternionBase_log(((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp_p) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_d, ((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp_p + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_d) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_c, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_c - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_d) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp_p, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_d + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp_p) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp, &proc_control_node_B.pn_a,
    &proc_control_node_B.pn_b, &proc_control_node_B.pn_c,
    &proc_control_node_B.pn_d);
  proc_control_node_B.qn_a = (((proc_control_node_B.n_n *
    proc_control_node_B.pn_a - proc_control_node_B.q1n_b *
    proc_control_node_B.pn_b) - proc_control_node_B.q1n_c *
    proc_control_node_B.pn_c) - proc_control_node_B.q1n_d *
    proc_control_node_B.pn_d) * proc_control_node_B.e_idx_0 * 2.0;
  proc_control_node_B.qn_b = (((proc_control_node_B.n_n *
    proc_control_node_B.pn_b + proc_control_node_B.q1n_b *
    proc_control_node_B.pn_a) + proc_control_node_B.q1n_c *
    proc_control_node_B.pn_d) - proc_control_node_B.q1n_d *
    proc_control_node_B.pn_c) * proc_control_node_B.e_idx_0 * 2.0;
  proc_control_node_B.qn_c = (((proc_control_node_B.n_n *
    proc_control_node_B.pn_c - proc_control_node_B.q1n_b *
    proc_control_node_B.pn_d) + proc_control_node_B.q1n_c *
    proc_control_node_B.pn_a) + proc_control_node_B.q1n_d *
    proc_control_node_B.pn_b) * proc_control_node_B.e_idx_0 * 2.0;
  proc_control_node_B.pn_d = (((proc_control_node_B.n_n *
    proc_control_node_B.pn_d + proc_control_node_B.q1n_b *
    proc_control_node_B.pn_c) - proc_control_node_B.q1n_c *
    proc_control_node_B.pn_b) + proc_control_node_B.q1n_d *
    proc_control_node_B.pn_a) * proc_control_node_B.e_idx_0 * 2.0;
  proc_control_quaternionBase_log(((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp_p) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_d, ((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp_p + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_d) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_c, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_c - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_d) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp_p, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_d + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp_p) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp, &proc_control_node_B.pn_a,
    &proc_control_node_B.pn_b, &proc_control_node_B.pn_c,
    &proc_control_node_B.qn_d);
  proc_control_node_B.dp = ((proc_control_node_B.n_n * proc_control_node_B.pn_a
    - proc_control_node_B.q1n_b * proc_control_node_B.pn_b) -
    proc_control_node_B.q1n_c * proc_control_node_B.pn_c) -
    proc_control_node_B.q1n_d * proc_control_node_B.qn_d;
  proc_control_node_B.sinv_tmp = ((proc_control_node_B.n_n *
    proc_control_node_B.pn_b + proc_control_node_B.q1n_b *
    proc_control_node_B.pn_a) + proc_control_node_B.q1n_c *
    proc_control_node_B.qn_d) - proc_control_node_B.q1n_d *
    proc_control_node_B.pn_c;
  proc_control_node_B.q2n_b = ((proc_control_node_B.n_n *
    proc_control_node_B.pn_c - proc_control_node_B.q1n_b *
    proc_control_node_B.qn_d) + proc_control_node_B.q1n_c *
    proc_control_node_B.pn_a) + proc_control_node_B.q1n_d *
    proc_control_node_B.pn_b;
  proc_control_node_B.theta0 = ((proc_control_node_B.n_n *
    proc_control_node_B.qn_d + proc_control_node_B.q1n_b *
    proc_control_node_B.pn_c) - proc_control_node_B.q1n_c *
    proc_control_node_B.pn_b) + proc_control_node_B.q1n_d *
    proc_control_node_B.pn_a;
  proc_control_quaternionBase_log(((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp_p) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_d, ((proc_control_node_B.linearScaling *
    proc_control_node_B.n_tmp_p + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.q2n_d) - -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.q2n_c, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_c - -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_d) + -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp_p, ((proc_control_node_B.linearScaling *
    proc_control_node_B.q2n_d + -proc_control_node_B.pnCorrected_b *
    proc_control_node_B.q2n_c) - -proc_control_node_B.pnCorrected_c *
    proc_control_node_B.n_tmp_p) + -proc_control_node_B.pnCorrected_d *
    proc_control_node_B.n_tmp, &proc_control_node_B.pn_a,
    &proc_control_node_B.pn_b, &proc_control_node_B.pn_c,
    &proc_control_node_B.qn_d);
  proc_control_node_B.linearScaling = (((proc_control_node_B.dp *
    proc_control_node_B.pn_a - proc_control_node_B.sinv_tmp *
    proc_control_node_B.pn_b) - proc_control_node_B.q2n_b *
    proc_control_node_B.pn_c) - proc_control_node_B.theta0 *
    proc_control_node_B.qn_d) * 0.0 * 2.0;
  proc_control_node_B.pnCorrected_b = (((proc_control_node_B.dp *
    proc_control_node_B.pn_b + proc_control_node_B.sinv_tmp *
    proc_control_node_B.pn_a) + proc_control_node_B.q2n_b *
    proc_control_node_B.qn_d) - proc_control_node_B.theta0 *
    proc_control_node_B.pn_c) * 0.0 * 2.0;
  proc_control_node_B.pnCorrected_c = (((proc_control_node_B.dp *
    proc_control_node_B.pn_c - proc_control_node_B.sinv_tmp *
    proc_control_node_B.qn_d) + proc_control_node_B.q2n_b *
    proc_control_node_B.pn_a) + proc_control_node_B.theta0 *
    proc_control_node_B.pn_b) * 0.0 * 2.0;
  proc_control_node_B.qn_d = (((proc_control_node_B.dp *
    proc_control_node_B.qn_d + proc_control_node_B.sinv_tmp *
    proc_control_node_B.pn_c) - proc_control_node_B.q2n_b *
    proc_control_node_B.pn_b) + proc_control_node_B.theta0 *
    proc_control_node_B.pn_a) * 0.0 * 2.0;
  varargout_1[0] = proc_control_node_B.n_n;
  varargout_1[1] = proc_control_node_B.q1n_b;
  varargout_1[2] = proc_control_node_B.q1n_c;
  varargout_1[3] = proc_control_node_B.q1n_d;
  varargout_2[0] = ((proc_control_node_B.qn_a * -proc_control_node_B.q1n_b +
                     proc_control_node_B.qn_b * proc_control_node_B.n_n) +
                    proc_control_node_B.qn_c * -proc_control_node_B.q1n_d) -
    proc_control_node_B.pn_d * -proc_control_node_B.q1n_c;
  varargout_2[1] = ((proc_control_node_B.qn_a * -proc_control_node_B.q1n_c -
                     proc_control_node_B.qn_b * -proc_control_node_B.q1n_d) +
                    proc_control_node_B.qn_c * proc_control_node_B.n_n) +
    proc_control_node_B.pn_d * -proc_control_node_B.q1n_b;
  varargout_2[2] = ((proc_control_node_B.qn_a * -proc_control_node_B.q1n_d +
                     proc_control_node_B.qn_b * -proc_control_node_B.q1n_c) -
                    proc_control_node_B.qn_c * -proc_control_node_B.q1n_b) +
    proc_control_node_B.pn_d * proc_control_node_B.n_n;
  varargout_3[0] = ((proc_control_node_B.linearScaling *
                     -proc_control_node_B.q1n_b +
                     proc_control_node_B.pnCorrected_b * proc_control_node_B.n_n)
                    + proc_control_node_B.pnCorrected_c *
                    -proc_control_node_B.q1n_d) - proc_control_node_B.qn_d *
    -proc_control_node_B.q1n_c;
  varargout_3[1] = ((proc_control_node_B.linearScaling *
                     -proc_control_node_B.q1n_c -
                     proc_control_node_B.pnCorrected_b *
                     -proc_control_node_B.q1n_d) +
                    proc_control_node_B.pnCorrected_c * proc_control_node_B.n_n)
    + proc_control_node_B.qn_d * -proc_control_node_B.q1n_b;
  varargout_3[2] = ((proc_control_node_B.linearScaling *
                     -proc_control_node_B.q1n_d +
                     proc_control_node_B.pnCorrected_b *
                     -proc_control_node_B.q1n_c) -
                    proc_control_node_B.pnCorrected_c *
                    -proc_control_node_B.q1n_b) + proc_control_node_B.qn_d *
    proc_control_node_B.n_n;
}

static real_T proc_control_node_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    proc_control_node_B.d2 = fabs(u0);
    proc_control_node_B.d3 = fabs(u1);
    if (rtIsInf(u1)) {
      if (proc_control_node_B.d2 == 1.0) {
        y = 1.0;
      } else if (proc_control_node_B.d2 > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (proc_control_node_B.d3 == 0.0) {
      y = 1.0;
    } else if (proc_control_node_B.d3 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void proc_control_node_ppval(const real_T pp_breaks[4], const real_T
  pp_coefs[36], const real_T x[2], real_T v[6])
{
  for (proc_control_node_B.b_ix_f = 0; proc_control_node_B.b_ix_f < 2;
       proc_control_node_B.b_ix_f++) {
    proc_control_node_B.iv0 = proc_control_node_B.b_ix_f * 3 - 1;
    if (rtIsNaN(x[proc_control_node_B.b_ix_f])) {
      v[proc_control_node_B.iv0 + 1] = x[proc_control_node_B.b_ix_f];
      v[proc_control_node_B.iv0 + 2] = x[proc_control_node_B.b_ix_f];
      v[proc_control_node_B.iv0 + 3] = x[proc_control_node_B.b_ix_f];
    } else {
      proc_control_node_B.low_i = 0;
      proc_control_node_B.low_ip1 = 1;
      proc_control_node_B.high_i = 4;
      while (proc_control_node_B.high_i > proc_control_node_B.low_ip1 + 1) {
        proc_control_node_B.mid_i = ((proc_control_node_B.low_i +
          proc_control_node_B.high_i) + 1) >> 1;
        if (x[proc_control_node_B.b_ix_f] >= pp_breaks[proc_control_node_B.mid_i
            - 1]) {
          proc_control_node_B.low_i = proc_control_node_B.mid_i - 1;
          proc_control_node_B.low_ip1 = proc_control_node_B.mid_i;
        } else {
          proc_control_node_B.high_i = proc_control_node_B.mid_i;
        }
      }

      proc_control_node_B.low_ip1 = proc_control_node_B.low_i * 3;
      proc_control_node_B.xloc = x[proc_control_node_B.b_ix_f] -
        pp_breaks[proc_control_node_B.low_i];
      v[proc_control_node_B.iv0 + 1] = pp_coefs[proc_control_node_B.low_ip1];
      v[proc_control_node_B.iv0 + 2] = pp_coefs[proc_control_node_B.low_ip1 + 1];
      v[proc_control_node_B.iv0 + 3] = pp_coefs[proc_control_node_B.low_ip1 + 2];
      for (proc_control_node_B.low_i = 0; proc_control_node_B.low_i < 3;
           proc_control_node_B.low_i++) {
        proc_control_node_B.high_i = ((proc_control_node_B.low_i + 1) * 9 +
          proc_control_node_B.low_ip1) - 1;
        v[proc_control_node_B.iv0 + 1] = v[proc_control_node_B.iv0 + 1] *
          proc_control_node_B.xloc + pp_coefs[proc_control_node_B.high_i + 1];
        v[proc_control_node_B.iv0 + 2] = v[proc_control_node_B.iv0 + 2] *
          proc_control_node_B.xloc + pp_coefs[proc_control_node_B.high_i + 2];
        v[proc_control_node_B.iv0 + 3] = v[proc_control_node_B.iv0 + 3] *
          proc_control_node_B.xloc + pp_coefs[proc_control_node_B.high_i + 3];
      }
    }
  }
}

static void proc_control_node_cubicpolytraj(const real_T wayPoints[6], const
  real_T timePoints[2], const real_T t[2], const real_T varargin_2[6], real_T q
  [6], real_T qd[6], real_T qdd[6], real_T pp_breaks[4], real_T pp_coefs[36])
{
  boolean_T exitg1;
  memset(&proc_control_node_B.coefMat[0], 0, 12U * sizeof(real_T));
  proc_control_node_B.finalTime = timePoints[1] - timePoints[0];
  for (proc_control_node_B.idx = 0; proc_control_node_B.idx < 3;
       proc_control_node_B.idx++) {
    proc_control_node_B.b_coeffVec[0] = wayPoints[proc_control_node_B.idx];
    proc_control_node_B.b_coeffVec[1] = varargin_2[proc_control_node_B.idx];
    proc_control_node_B.wayPoints_idx_0 = wayPoints[proc_control_node_B.idx + 3]
      - (proc_control_node_B.finalTime * proc_control_node_B.b_coeffVec[1] +
         proc_control_node_B.b_coeffVec[0]);
    proc_control_node_B.wayPoints_idx_1 = varargin_2[proc_control_node_B.idx + 3]
      - (0.0 * proc_control_node_B.b_coeffVec[0] +
         proc_control_node_B.b_coeffVec[1]);
    proc_control_node_B.b_coeffVec[3] = proc_control_node_B.b_coeffVec[0];
    proc_control_node_B.coefMat_tmp = proc_control_node_B.finalTime *
      proc_control_node_B.finalTime;
    proc_control_node_B.coefMat[proc_control_node_B.idx] = 1.0 /
      proc_control_node_B.coefMat_tmp * proc_control_node_B.wayPoints_idx_1 +
      -2.0 / proc_control_node_rt_powd_snf(proc_control_node_B.finalTime, 3.0) *
      proc_control_node_B.wayPoints_idx_0;
    proc_control_node_B.coefMat[proc_control_node_B.idx + 3] = 3.0 /
      proc_control_node_B.coefMat_tmp * proc_control_node_B.wayPoints_idx_0 +
      -1.0 / proc_control_node_B.finalTime * proc_control_node_B.wayPoints_idx_1;
    proc_control_node_B.coefMat[proc_control_node_B.idx + 6] =
      proc_control_node_B.b_coeffVec[1];
    proc_control_node_B.coefMat[proc_control_node_B.idx + 9] =
      proc_control_node_B.b_coeffVec[3];
  }

  memset(&proc_control_node_B.coeffMat[0], 0, 12U * sizeof(real_T));
  for (proc_control_node_B.c_j1 = 0; proc_control_node_B.c_j1 < 3;
       proc_control_node_B.c_j1++) {
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] = 0.0;
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefMat[proc_control_node_B.c_j1] * 0.0;
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefMat[proc_control_node_B.c_j1 + 3] * 0.0;
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefMat[proc_control_node_B.c_j1 + 6] * 0.0;
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefMat[proc_control_node_B.c_j1 + 9];
  }

  memset(&proc_control_node_B.coefsWithFlatStart[0], 0, 24U * sizeof(real_T));
  proc_control_node_B.c_j1 = 0;
  proc_control_node_B.idx = 0;
  for (proc_control_node_B.idx_h = 0; proc_control_node_B.idx_h < 4;
       proc_control_node_B.idx_h++) {
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx];
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 3] =
      proc_control_node_B.coefMat[proc_control_node_B.idx];
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 1] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx + 1];
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 4] =
      proc_control_node_B.coefMat[proc_control_node_B.idx + 1];
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 2] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx + 2];
    proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 5] =
      proc_control_node_B.coefMat[proc_control_node_B.idx + 2];
    proc_control_node_B.c_j1 += 6;
    proc_control_node_B.idx += 3;
  }

  proc_control_node_B.b_coeffVec[0] = proc_control_node_rt_powd_snf
    (proc_control_node_B.finalTime, 3.0);
  proc_control_node_B.b_coeffVec[1] = proc_control_node_rt_powd_snf
    (proc_control_node_B.finalTime, 2.0);
  proc_control_node_B.b_coeffVec[2] = proc_control_node_rt_powd_snf
    (proc_control_node_B.finalTime, 1.0);
  proc_control_node_B.b_coeffVec[3] = proc_control_node_rt_powd_snf
    (proc_control_node_B.finalTime, 0.0);
  memset(&proc_control_node_B.coeffMat[0], 0, 12U * sizeof(real_T));
  for (proc_control_node_B.c_j1 = 0; proc_control_node_B.c_j1 < 3;
       proc_control_node_B.c_j1++) {
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] = 0.0;
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 3] *
      proc_control_node_B.b_coeffVec[0];
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 9] *
      proc_control_node_B.b_coeffVec[1];
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 15] *
      proc_control_node_B.b_coeffVec[2];
    proc_control_node_B.coeffMat[proc_control_node_B.c_j1 + 9] +=
      proc_control_node_B.coefsWithFlatStart[proc_control_node_B.c_j1 + 21] *
      proc_control_node_B.b_coeffVec[3];
  }

  memset(&pp_coefs[0], 0, 36U * sizeof(real_T));
  proc_control_node_B.c_j1 = 0;
  proc_control_node_B.idx = 0;
  proc_control_node_B.idx_h = 0;
  for (proc_control_node_B.dCoeffs_tmp = 0; proc_control_node_B.dCoeffs_tmp < 4;
       proc_control_node_B.dCoeffs_tmp++) {
    for (proc_control_node_B.i22 = 0; proc_control_node_B.i22 < 6;
         proc_control_node_B.i22++) {
      pp_coefs[proc_control_node_B.i22 + proc_control_node_B.c_j1] =
        proc_control_node_B.coefsWithFlatStart[proc_control_node_B.i22 +
        proc_control_node_B.idx_h];
    }

    pp_coefs[proc_control_node_B.c_j1 + 6] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx];
    pp_coefs[proc_control_node_B.c_j1 + 7] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx + 1];
    pp_coefs[proc_control_node_B.c_j1 + 8] =
      proc_control_node_B.coeffMat[proc_control_node_B.idx + 2];
    proc_control_node_B.c_j1 += 9;
    proc_control_node_B.idx += 3;
    proc_control_node_B.idx_h += 6;
  }

  pp_breaks[0] = timePoints[0] - 1.0;
  pp_breaks[1] = timePoints[0];
  pp_breaks[2] = timePoints[1];
  pp_breaks[3] = timePoints[1] + 1.0;
  proc_control_node_ppval(pp_breaks, pp_coefs, t, q);
  proc_control_node_B.b_coeffVec[0] = timePoints[0] - 1.0;
  proc_control_node_B.b_coeffVec[1] = timePoints[0];
  proc_control_node_B.b_coeffVec[3] = timePoints[1] + 1.0;
  proc_control_node_B.finalTime = 0.01;
  proc_control_node_B.x_j[0] = (t[0] > timePoints[1]);
  proc_control_node_B.x_j[1] = (t[1] > timePoints[1]);
  proc_control_node_B.idx = 0;
  proc_control_node_B.idx_h = 1;
  proc_control_node_B.c_j1 = 1;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.c_j1 - 1 < 2)) {
    if (proc_control_node_B.x_j[proc_control_node_B.c_j1 - 1]) {
      proc_control_node_B.idx = 1;
      proc_control_node_B.ii_data_idx_0 = proc_control_node_B.c_j1;
      exitg1 = true;
    } else {
      proc_control_node_B.c_j1++;
    }
  }

  if (proc_control_node_B.idx == 0) {
    proc_control_node_B.idx_h = 0;
  }

  if (0 <= proc_control_node_B.idx_h - 1) {
    proc_control_node_B.tGreaterThanTfIdx_data_idx_0 =
      proc_control_node_B.ii_data_idx_0;
  }

  if (proc_control_node_B.idx_h != 0) {
    proc_control_node_B.wayPoints_idx_0 =
      (t[proc_control_node_B.tGreaterThanTfIdx_data_idx_0 - 1] - timePoints[1]) /
      2.0;
    if (proc_control_node_B.wayPoints_idx_0 < 0.01) {
      proc_control_node_B.finalTime = proc_control_node_B.wayPoints_idx_0;
    }
  }

  proc_control_node_B.b_coeffVec[2] = timePoints[1] +
    proc_control_node_B.finalTime;
  memset(&proc_control_node_B.dCoeffs[0], 0, 36U * sizeof(real_T));
  proc_control_node_B.idx_h = 0;
  for (proc_control_node_B.idx = 0; proc_control_node_B.idx < 3;
       proc_control_node_B.idx++) {
    for (proc_control_node_B.c_j1 = 0; proc_control_node_B.c_j1 < 9;
         proc_control_node_B.c_j1++) {
      proc_control_node_B.dCoeffs_tmp = proc_control_node_B.c_j1 +
        proc_control_node_B.idx_h;
      proc_control_node_B.dCoeffs[proc_control_node_B.dCoeffs_tmp + 9] =
        pp_coefs[proc_control_node_B.dCoeffs_tmp] * static_cast<real_T>(3 -
        proc_control_node_B.idx);
    }

    proc_control_node_B.idx_h += 9;
  }

  proc_control_node_ppval(proc_control_node_B.b_coeffVec,
    proc_control_node_B.dCoeffs, t, qd);
  memset(&proc_control_node_B.ddCoeffs[0], 0, 36U * sizeof(real_T));
  proc_control_node_B.idx_h = 0;
  for (proc_control_node_B.idx = 0; proc_control_node_B.idx < 3;
       proc_control_node_B.idx++) {
    for (proc_control_node_B.c_j1 = 0; proc_control_node_B.c_j1 < 9;
         proc_control_node_B.c_j1++) {
      proc_control_node_B.dCoeffs_tmp = proc_control_node_B.c_j1 +
        proc_control_node_B.idx_h;
      proc_control_node_B.ddCoeffs[proc_control_node_B.dCoeffs_tmp + 9] =
        proc_control_node_B.dCoeffs[proc_control_node_B.dCoeffs_tmp] *
        static_cast<real_T>(3 - proc_control_node_B.idx);
    }

    proc_control_node_B.idx_h += 9;
  }

  proc_control_node_ppval(proc_control_node_B.b_coeffVec,
    proc_control_node_B.ddCoeffs, t, qdd);
}

static void proc_control_node_ppval_b(const real_T pp_breaks[4], const real_T
  pp_coefs[36], real_T x, real_T v[3])
{
  real_T xloc;
  int32_T high_i;
  int32_T ic0;
  int32_T low_i;
  int32_T low_ip1;
  if (rtIsNaN(x)) {
    v[0] = x;
    v[1] = x;
    v[2] = x;
  } else {
    low_i = 0;
    low_ip1 = 1;
    high_i = 4;
    while (high_i > low_ip1 + 1) {
      ic0 = ((low_i + high_i) + 1) >> 1;
      if (x >= pp_breaks[ic0 - 1]) {
        low_i = ic0 - 1;
        low_ip1 = ic0;
      } else {
        high_i = ic0;
      }
    }

    low_ip1 = low_i * 3;
    xloc = x - pp_breaks[low_i];
    v[0] = pp_coefs[low_ip1];
    v[1] = pp_coefs[low_ip1 + 1];
    v[2] = pp_coefs[low_ip1 + 2];
    for (high_i = 0; high_i < 3; high_i++) {
      ic0 = ((high_i + 1) * 9 + low_ip1) - 1;
      v[0] = xloc * v[0] + pp_coefs[ic0 + 1];
      v[1] = xloc * v[1] + pp_coefs[ic0 + 2];
      v[2] = xloc * v[2] + pp_coefs[ic0 + 3];
    }
  }
}

static void TrajectoryManager_SendCurrentPo(TrajectoryManager_proc_contro_T
  *b_this, real_T currPose[130])
{
  boolean_T exitg1;
  boolean_T exitg2;

  //  Fonction qui retourne la pose actuelle
  //  Vérification des prédictions.
  proc_control_node_B.b_index = 2;
  proc_control_node_B.isempty = false;
  proc_control_node_B.b_i_k = 0;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.b_i_k < 9)) {
    proc_control_node_B.b_index = proc_control_node_B.b_i_k + 2;
    for (proc_control_node_B.i26 = 0; proc_control_node_B.i26 < 13;
         proc_control_node_B.i26++) {
      proc_control_node_B.x_f[proc_control_node_B.i26] = (b_this->poseBuffer
        [(6001 * proc_control_node_B.i26 + proc_control_node_B.b_i_k) + 1] ==
        b_this->emptyArray[proc_control_node_B.i26]);
    }

    proc_control_node_B.y_e0 = true;
    proc_control_node_B.b_k_i = 0;
    exitg2 = false;
    while ((!exitg2) && (proc_control_node_B.b_k_i < 13)) {
      if (!proc_control_node_B.x_f[proc_control_node_B.b_k_i]) {
        proc_control_node_B.y_e0 = false;
        exitg2 = true;
      } else {
        proc_control_node_B.b_k_i++;
      }
    }

    if (proc_control_node_B.y_e0) {
      proc_control_node_B.isempty = true;
      exitg1 = true;
    } else {
      proc_control_node_B.b_i_k++;
    }
  }

  memset(&currPose[0], 0, 130U * sizeof(real_T));
  proc_control_node_B.i26 = 0;
  proc_control_node_B.b_i_k = 0;
  for (proc_control_node_B.b_k_i = 0; proc_control_node_B.b_k_i < 13;
       proc_control_node_B.b_k_i++) {
    for (proc_control_node_B.b_index_h = 0; proc_control_node_B.b_index_h <
         proc_control_node_B.b_index; proc_control_node_B.b_index_h++) {
      currPose[proc_control_node_B.b_index_h + proc_control_node_B.i26] =
        b_this->poseBuffer[proc_control_node_B.b_index_h +
        proc_control_node_B.b_i_k];
    }

    proc_control_node_B.i26 += 10;
    proc_control_node_B.b_i_k += 6001;
  }

  if (proc_control_node_B.isempty) {
    proc_control_node_B.b_k_i = 10 - proc_control_node_B.b_index;
    for (proc_control_node_B.b_i_k = 0; proc_control_node_B.b_i_k <=
         proc_control_node_B.b_k_i; proc_control_node_B.b_i_k++) {
      proc_control_node_B.b_index_h = proc_control_node_B.b_index +
        proc_control_node_B.b_i_k;
      for (proc_control_node_B.i26 = 0; proc_control_node_B.i26 < 13;
           proc_control_node_B.i26++) {
        proc_control_node_B.currPose[proc_control_node_B.i26] = currPose
          [(proc_control_node_B.b_index + 10 * proc_control_node_B.i26) - 2];
      }

      for (proc_control_node_B.i26 = 0; proc_control_node_B.i26 < 13;
           proc_control_node_B.i26++) {
        currPose[(proc_control_node_B.b_index_h + 10 * proc_control_node_B.i26)
          - 1] = proc_control_node_B.currPose[proc_control_node_B.i26];
      }
    }
  }

  //  Ne pas supprimer le point si c'est le dernier.
  proc_control_node_B.i26 = 0;
  for (proc_control_node_B.b_i_k = 0; proc_control_node_B.b_i_k < 13;
       proc_control_node_B.b_i_k++) {
    proc_control_node_B.x_f[proc_control_node_B.b_i_k] = !(b_this->
      poseBuffer[proc_control_node_B.i26 + 10] == b_this->
      emptyArray[proc_control_node_B.b_i_k]);
    proc_control_node_B.i26 += 6001;
  }

  proc_control_node_B.y_e0 = true;
  proc_control_node_B.b_k_i = 0;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.b_k_i < 13)) {
    if (!proc_control_node_B.x_f[proc_control_node_B.b_k_i]) {
      proc_control_node_B.y_e0 = false;
      exitg1 = true;
    } else {
      proc_control_node_B.b_k_i++;
    }
  }

  if (proc_control_node_B.y_e0) {
    proc_control_node_B.i26 = 0;
    for (proc_control_node_B.b_i_k = 0; proc_control_node_B.b_i_k < 13;
         proc_control_node_B.b_i_k++) {
      memcpy(&proc_control_node_B.b_this[proc_control_node_B.i26],
             &b_this->poseBuffer[proc_control_node_B.i26 + 1], 6000U * sizeof
             (real_T));
      proc_control_node_B.i26 += 6001;
    }

    proc_control_node_B.i26 = 0;
    for (proc_control_node_B.b_i_k = 0; proc_control_node_B.b_i_k < 13;
         proc_control_node_B.b_i_k++) {
      proc_control_node_B.b_this[proc_control_node_B.i26 + 6000] =
        b_this->emptyArray[proc_control_node_B.b_i_k];
      proc_control_node_B.i26 += 6001;
    }

    memcpy(&b_this->poseBuffer[0], &proc_control_node_B.b_this[0], 78013U *
           sizeof(real_T));
    b_this->bufferCount--;
    b_this->done = false;
  } else {
    b_this->done = true;
  }
}

static real_T proc_control_node_norm_b(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S110>/MATLAB Function2'
static void proc_contr_AUVEULJacobianMatrix(const real_T in1[12], real_T Ane[144])
{
  proc_control_node_B.t2 = fabs(in1[9]);
  proc_control_node_B.t3 = fabs(in1[10]);
  proc_control_node_B.t4 = fabs(in1[11]);
  proc_control_node_B.t5 = cos(in1[3]);
  proc_control_node_B.t6 = cos(in1[5]);
  proc_control_node_B.t7 = fabs(in1[6]);
  proc_control_node_B.t8_c = fabs(in1[7]);
  proc_control_node_B.t9_m = cos(in1[4]);
  proc_control_node_B.t10_j = fabs(in1[8]);
  if (in1[9] < 0.0) {
    proc_control_node_B.t11_k = -1.0;
  } else if (in1[9] > 0.0) {
    proc_control_node_B.t11_k = 1.0;
  } else if (in1[9] == 0.0) {
    proc_control_node_B.t11_k = 0.0;
  } else {
    proc_control_node_B.t11_k = (rtNaN);
  }

  proc_control_node_B.t12_m = sin(in1[3]);
  proc_control_node_B.t13_p = sin(in1[5]);
  if (in1[10] < 0.0) {
    proc_control_node_B.t14_d = -1.0;
  } else if (in1[10] > 0.0) {
    proc_control_node_B.t14_d = 1.0;
  } else if (in1[10] == 0.0) {
    proc_control_node_B.t14_d = 0.0;
  } else {
    proc_control_node_B.t14_d = (rtNaN);
  }

  if (in1[11] < 0.0) {
    proc_control_node_B.t15_g = -1.0;
  } else if (in1[11] > 0.0) {
    proc_control_node_B.t15_g = 1.0;
  } else if (in1[11] == 0.0) {
    proc_control_node_B.t15_g = 0.0;
  } else {
    proc_control_node_B.t15_g = (rtNaN);
  }

  proc_control_node_B.t16_c = sin(in1[4]);
  if (in1[6] < 0.0) {
    proc_control_node_B.t17_c = -1.0;
  } else if (in1[6] > 0.0) {
    proc_control_node_B.t17_c = 1.0;
  } else if (in1[6] == 0.0) {
    proc_control_node_B.t17_c = 0.0;
  } else {
    proc_control_node_B.t17_c = (rtNaN);
  }

  if (in1[7] < 0.0) {
    proc_control_node_B.t18_i = -1.0;
  } else if (in1[7] > 0.0) {
    proc_control_node_B.t18_i = 1.0;
  } else if (in1[7] == 0.0) {
    proc_control_node_B.t18_i = 0.0;
  } else {
    proc_control_node_B.t18_i = (rtNaN);
  }

  if (in1[8] < 0.0) {
    proc_control_node_B.t19_d = -1.0;
  } else if (in1[8] > 0.0) {
    proc_control_node_B.t19_d = 1.0;
  } else if (in1[8] == 0.0) {
    proc_control_node_B.t19_d = 0.0;
  } else {
    proc_control_node_B.t19_d = (rtNaN);
  }

  proc_control_node_B.t46 = in1[11] * 1.0571299073092789E-5;
  proc_control_node_B.t47 = in1[10] * 9.7602896722846373E-5;
  proc_control_node_B.t48 = in1[7] * 0.01129023503850542;
  proc_control_node_B.t49 = in1[6] * 0.00477039452928936;
  proc_control_node_B.t50 = in1[9] * 9.1703771260780813E-5;
  proc_control_node_B.t52 = in1[8] * 0.143523560675718;
  proc_control_node_B.t53 = in1[6] * 0.00568699616459184;
  proc_control_node_B.t54 = in1[8] * 0.069014505171846527;
  proc_control_node_B.t55_g = in1[7] * 0.0071670223909459834;
  proc_control_node_B.t20_l = proc_control_node_B.t16_c *
    proc_control_node_B.t16_c;
  proc_control_node_B.t21_f = in1[11] * proc_control_node_B.t5;
  proc_control_node_B.t22_d = in1[10] * proc_control_node_B.t12_m;
  proc_control_node_B.t23_j = proc_control_node_B.t5 * proc_control_node_B.t6;
  proc_control_node_B.t24 = proc_control_node_B.t5 * proc_control_node_B.t13_p;
  proc_control_node_B.t25_i = proc_control_node_B.t6 * proc_control_node_B.t12_m;
  proc_control_node_B.t26_h = proc_control_node_B.t12_m *
    proc_control_node_B.t13_p;
  proc_control_node_B.t27_n = 1.0 / proc_control_node_B.t9_m;
  proc_control_node_B.t28_o = proc_control_node_B.t27_n *
    proc_control_node_B.t27_n;
  proc_control_node_B.t31 = proc_control_node_B.t16_c * proc_control_node_B.t24;
  proc_control_node_B.t32 = proc_control_node_B.t16_c *
    proc_control_node_B.t25_i;
  proc_control_node_B.t37_c = proc_control_node_B.t16_c *
    proc_control_node_B.t26_h + proc_control_node_B.t23_j;
  proc_control_node_B.t38 = proc_control_node_B.t16_c *
    proc_control_node_B.t23_j + proc_control_node_B.t26_h;
  proc_control_node_B.t39_b = proc_control_node_B.t24 + -proc_control_node_B.t32;
  proc_control_node_B.t40 = proc_control_node_B.t25_i + -proc_control_node_B.t31;
  memset(&Ane[0], 0, 36U * sizeof(real_T));
  Ane[36] = proc_control_node_B.t38 * in1[7] + proc_control_node_B.t39_b * in1[8];
  Ane[37] = -proc_control_node_B.t40 * in1[7] - proc_control_node_B.t37_c * in1
    [8];
  proc_control_node_B.Ane_tmp_d = proc_control_node_B.t5 *
    proc_control_node_B.t9_m;
  proc_control_node_B.Ane_tmp_i = proc_control_node_B.t9_m *
    proc_control_node_B.t12_m;
  Ane[38] = proc_control_node_B.Ane_tmp_d * in1[7] -
    proc_control_node_B.Ane_tmp_i * in1[8];
  proc_control_node_B.Ane_tmp = in1[10] * proc_control_node_B.t5;
  proc_control_node_B.Ane_tmp_e = in1[11] * proc_control_node_B.t12_m;
  Ane[39] = proc_control_node_B.Ane_tmp * proc_control_node_B.t16_c *
    proc_control_node_B.t27_n - proc_control_node_B.Ane_tmp_e *
    proc_control_node_B.t16_c * proc_control_node_B.t27_n;
  Ane[40] = -proc_control_node_B.t21_f - proc_control_node_B.t22_d;
  Ane[41] = proc_control_node_B.Ane_tmp * proc_control_node_B.t27_n -
    proc_control_node_B.Ane_tmp_e * proc_control_node_B.t27_n;
  proc_control_node_B.Ane_tmp = proc_control_node_B.t9_m *
    (proc_control_node_B.t12_m * 0.062 + proc_control_node_B.t5 * 0.369378);
  Ane[42] = (proc_control_node_B.Ane_tmp_d * 0.0003038485611411295 -
             proc_control_node_B.Ane_tmp_i * 0.0030804819903427929) -
    proc_control_node_B.Ane_tmp * 0.0012787556591776421;
  Ane[43] = (proc_control_node_B.Ane_tmp_d * -0.09962138533478937 -
             proc_control_node_B.Ane_tmp_i * 0.0001558786802929103) -
    proc_control_node_B.Ane_tmp * 0.2146651116826197;
  Ane[44] = (proc_control_node_B.Ane_tmp_d * 0.0001262558405802736 +
             proc_control_node_B.Ane_tmp_i * 0.091796606188097957) +
    proc_control_node_B.Ane_tmp * 0.022292555139725449;
  Ane[45] = (proc_control_node_B.Ane_tmp_d * -0.095020813300146653 -
             proc_control_node_B.Ane_tmp_i * 0.01218289469126858) -
    proc_control_node_B.Ane_tmp * 16.7769453147126;
  Ane[46] = (proc_control_node_B.Ane_tmp_d * 0.000439745529355291 +
             proc_control_node_B.Ane_tmp_i * 0.17922689172220771) +
    proc_control_node_B.Ane_tmp * 0.078743486942211408;
  Ane[47] = (proc_control_node_B.Ane_tmp_d * 0.16306065763088379 +
             proc_control_node_B.Ane_tmp_i * 2.2159046954574339E-5) +
    proc_control_node_B.Ane_tmp * 0.03910191918844614;
  Ane[48] = (-proc_control_node_B.t6 * proc_control_node_B.t16_c * in1[6] +
             proc_control_node_B.t9_m * proc_control_node_B.t25_i * in1[7]) +
    proc_control_node_B.t9_m * proc_control_node_B.t23_j * in1[8];
  Ane[49] = (-proc_control_node_B.t13_p * proc_control_node_B.t16_c * in1[6] +
             proc_control_node_B.t9_m * proc_control_node_B.t26_h * in1[7]) +
    proc_control_node_B.t9_m * proc_control_node_B.t24 * in1[8];
  proc_control_node_B.Ane_tmp = proc_control_node_B.t5 *
    proc_control_node_B.t16_c;
  proc_control_node_B.Ane_tmp_e = proc_control_node_B.t12_m *
    proc_control_node_B.t16_c;
  Ane[50] = (-proc_control_node_B.t9_m * in1[6] - proc_control_node_B.Ane_tmp_e *
             in1[7]) - proc_control_node_B.Ane_tmp * in1[8];
  Ane[51] = (proc_control_node_B.t20_l * proc_control_node_B.t21_f *
             proc_control_node_B.t28_o + (proc_control_node_B.t21_f +
              proc_control_node_B.t22_d)) + proc_control_node_B.t20_l *
    proc_control_node_B.t22_d * proc_control_node_B.t28_o;
  Ane[52] = 0.0;
  Ane[53] = proc_control_node_B.t16_c * proc_control_node_B.t21_f *
    proc_control_node_B.t28_o + proc_control_node_B.t16_c *
    proc_control_node_B.t22_d * proc_control_node_B.t28_o;
  proc_control_node_B.t20_l = proc_control_node_B.t16_c *
    (proc_control_node_B.t5 * 0.062 + -(proc_control_node_B.t12_m * 0.369378));
  Ane[54] = ((proc_control_node_B.t9_m * 0.16976989872018719 -
              proc_control_node_B.Ane_tmp * 0.0030804819903427929) -
             proc_control_node_B.Ane_tmp_e * 0.0003038485611411295) +
    proc_control_node_B.t20_l * -0.0012787556591776421;
  Ane[55] = ((proc_control_node_B.t9_m * 0.0001159747557612512 -
              proc_control_node_B.Ane_tmp * 0.0001558786802929103) +
             proc_control_node_B.Ane_tmp_e * 0.09962138533478937) +
    proc_control_node_B.t20_l * -0.2146651116826197;
  Ane[56] = ((proc_control_node_B.Ane_tmp * 0.091796606188097957 +
              proc_control_node_B.t9_m * -0.001466640088431202) -
             proc_control_node_B.Ane_tmp_e * 0.0001262558405802736) +
    proc_control_node_B.t20_l * 0.022292555139725449;
  Ane[57] = ((proc_control_node_B.t9_m * 0.027220608953117141 -
              proc_control_node_B.Ane_tmp * 0.01218289469126858) +
             proc_control_node_B.Ane_tmp_e * 0.095020813300146653) +
    proc_control_node_B.t20_l * -16.7769453147126;
  Ane[58] = ((proc_control_node_B.Ane_tmp * 0.17922689172220771 +
              proc_control_node_B.t9_m * -2.158269221315801) -
             proc_control_node_B.Ane_tmp_e * 0.000439745529355291) +
    proc_control_node_B.t20_l * 0.078743486942211408;
  Ane[59] = ((proc_control_node_B.Ane_tmp * 2.2159046954574339E-5 +
              proc_control_node_B.t9_m * 0.32679971736964308) -
             proc_control_node_B.Ane_tmp_e * 0.16306065763088379) +
    proc_control_node_B.t20_l * 0.03910191918844614;
  proc_control_node_B.t20_l = proc_control_node_B.t9_m *
    proc_control_node_B.t13_p;
  Ane[60] = (-proc_control_node_B.t37_c * in1[7] + proc_control_node_B.t40 *
             in1[8]) - proc_control_node_B.t20_l * in1[6];
  proc_control_node_B.t6 *= proc_control_node_B.t9_m;
  Ane[61] = (-proc_control_node_B.t39_b * in1[7] + proc_control_node_B.t38 *
             in1[8]) + proc_control_node_B.t6 * in1[6];
  memset(&Ane[62], 0, 10U * sizeof(real_T));
  Ane[72] = proc_control_node_B.t6;
  Ane[73] = proc_control_node_B.t20_l;
  Ane[74] = -proc_control_node_B.t16_c;
  Ane[75] = 0.0;
  Ane[76] = 0.0;
  Ane[77] = 0.0;
  proc_control_node_B.t20_l = proc_control_node_B.t17_c * in1[6];
  Ane[78] = (((((proc_control_node_B.t7 * -0.036243063166504788 +
                 proc_control_node_B.t46) + proc_control_node_B.t47) -
               proc_control_node_B.t48) - proc_control_node_B.t52) -
             proc_control_node_B.t20_l * 0.036243063166504788) -
    0.34849099198562289;
  Ane[79] = (((in1[7] * 0.00477039452928936 - in1[8] * 0.001468966557066211) -
              proc_control_node_B.t20_l * 1.109195745194835E-6) -
             1.066534370379649E-5) + ((in1[10] * 0.00041592787873873338 - in1[11]
    * 0.74121409319149256) - proc_control_node_B.t7 * 1.109195745194835E-6);
  Ane[80] = (((in1[7] * -5.890830655932608E-5 + in1[8] * 0.00568699616459184) +
              proc_control_node_B.t20_l * 7.9830677445685858E-6) +
             7.6760266774697944E-5) + ((in1[10] * 0.69409782663856512 - in1[11] *
    0.00032422410747795261) + proc_control_node_B.t7 * 7.9830677445685858E-6);
  Ane[81] = (((in1[10] * 0.032506453976272241 + in1[11] * 0.24400486517334929) -
              proc_control_node_B.t7 * 0.0001525121428377004) + ((in1[7] *
    0.044446246736648841 - in1[8] * 0.1148218101592509) -
              proc_control_node_B.t20_l * 0.0001525121428377004)) +
    -0.0014664629119009651;
  Ane[82] = (((in1[7] * 1.7911420833141059E-5 + in1[8] * 8.3502908029033716) +
              proc_control_node_B.t20_l * 0.011738978516892359) +
             0.11287479343165729) + ((in1[10] * -0.00568699616459184 - in1[11] *
    0.001145088836853196) + proc_control_node_B.t7 * 0.011738978516892359);
  Ane[83] = (((in1[10] * -7.5569972812640509E-5 - in1[11] * 0.00477039452928936)
              - proc_control_node_B.t7 * 0.0011846302503005471) + ((in1[7] *
    -5.91169722427816 - in1[8] * 2.2977499514997389E-5) -
              proc_control_node_B.t20_l * 0.0011846302503005471)) +
    -0.01139067548365911;
  Ane[84] = -proc_control_node_B.t24 + proc_control_node_B.t32;
  Ane[85] = proc_control_node_B.t37_c;
  Ane[86] = proc_control_node_B.Ane_tmp_i;
  Ane[87] = 0.0;
  Ane[88] = 0.0;
  Ane[89] = 0.0;
  proc_control_node_B.Ane_tmp_i = proc_control_node_B.t18_i * in1[7];
  Ane[90] = (((in1[9] * -2.1519484922730651E-5 + in1[11] * 1.3454180758607359) -
              proc_control_node_B.t8_c * 7.7738505218783331E-7) - in1[6] *
             0.01129023503850542) + ((in1[8] * -0.00041111798914172931 -
    proc_control_node_B.Ane_tmp_i * 7.7738505218783331E-7) -
    1.422045827172866E-5);
  Ane[91] = (((((proc_control_node_B.t8_c * -0.01903042325061665 +
                 proc_control_node_B.t46) + proc_control_node_B.t49) +
               -proc_control_node_B.t50) - proc_control_node_B.t54) -
             proc_control_node_B.Ane_tmp_i * 0.01903042325061665) -
    0.34811749848688989;
  Ane[92] = (((in1[6] * -5.890830655932608E-5 + in1[8] * 0.0071670223909459834)
              + proc_control_node_B.Ane_tmp_i * 2.3842573459475649E-5) +
             0.00043614463645382288) + ((in1[9] * -0.93255469429176219 - in1[11]
    * 7.6083411800115719E-5) + proc_control_node_B.t8_c * 2.3842573459475649E-5);
  Ane[93] = (((in1[9] * -0.0071670223909459834 + in1[11] * 0.00145353196782447)
              - proc_control_node_B.t8_c * 0.017943464992838758) + ((in1[6] *
    0.044446246736648841 - in1[8] * 5.3937622658585171) -
              proc_control_node_B.Ane_tmp_i * 0.017943464992838758)) +
    -0.3282341157226602;
  Ane[94] = (((in1[9] * 0.0012538688125934979 - in1[11] * 0.1118794885864644) +
              proc_control_node_B.t8_c * 8.4206769578830268E-5) + in1[6] *
             1.7911420833141059E-5) + ((proc_control_node_B.Ane_tmp_i *
    8.4206769578830268E-5 + in1[8] * 0.025315910649035739) +
    0.001540367736198115);
  Ane[95] = (((in1[9] * 1.6661666253314429E-5 + in1[11] * 0.01129023503850542) +
              proc_control_node_B.t8_c * 0.00035080205133418912) + ((in1[6] *
    -5.91169722427816 + in1[8] * 0.01257120723021817) +
              proc_control_node_B.Ane_tmp_i * 0.00035080205133418912)) +
    0.0064171106951376048;
  Ane[96] = proc_control_node_B.t38;
  Ane[97] = -proc_control_node_B.t25_i + proc_control_node_B.t31;
  Ane[98] = proc_control_node_B.Ane_tmp_d;
  Ane[99] = 0.0;
  Ane[100] = 0.0;
  Ane[101] = 0.0;
  proc_control_node_B.Ane_tmp_d = proc_control_node_B.t19_d * in1[8];
  Ane[102] = (((in1[9] * 2.989993556213668E-6 - in1[10] * 1.4431163638272659) +
               proc_control_node_B.t10_j * 5.1582899272597018E-6) - in1[6] *
              0.143523560675718) + ((proc_control_node_B.Ane_tmp_d *
    5.1582899272597018E-6 + in1[7] * -0.00041111798914172931) +
    0.0001194048594273079);
  Ane[103] = (((in1[9] * 1.0731951852318531 - in1[10] * 1.356129262930646E-5) +
               proc_control_node_B.t10_j * 2.1981689677272681E-5) + ((in1[6] *
    -0.001468966557066211 - in1[7] * 0.069014505171846527) +
    proc_control_node_B.Ane_tmp_d * 2.1981689677272681E-5)) +
    0.00050883540919612676;
  Ane[104] = (((((proc_control_node_B.t10_j * -0.01616685726098728 +
                  proc_control_node_B.t47) + -proc_control_node_B.t50) +
                proc_control_node_B.t53) + proc_control_node_B.t55_g) -
              proc_control_node_B.Ane_tmp_d * 0.01616685726098728) -
    0.37423280696729833;
  Ane[105] = (((in1[9] * 0.069014505171846527 - in1[10] * 0.0018646499569661989)
               + proc_control_node_B.t10_j * 0.00171795837774031) + ((in1[6] *
    -0.1148218101592509 - in1[7] * 5.3937622658585171) +
    proc_control_node_B.Ane_tmp_d * 0.00171795837774031)) + 0.039767555040284952;
  Ane[106] = (((in1[9] * -0.00032387772021301561 + in1[10] * 0.143523560675718)
               - proc_control_node_B.t10_j * 0.00030055639757781919) + ((in1[6] *
    8.3502908029033716 + in1[7] * 0.025315910649035739) -
    proc_control_node_B.Ane_tmp_d * 0.00030055639757781919)) +
    -0.0069573240180050748;
  Ane[107] = (((in1[9] * -0.0013492616947596331 - in1[10] * 0.01448357294143097)
               - proc_control_node_B.t10_j * 3.993855127780116E-6) - in1[6] *
              2.2977499514997389E-5) + ((in1[7] * 0.01257120723021817 -
    proc_control_node_B.Ane_tmp_d * 3.993855127780116E-6) -
    9.2450350180095273E-5);
  Ane[108] = 0.0;
  Ane[109] = 0.0;
  Ane[110] = 0.0;
  Ane[111] = 1.0;
  Ane[112] = 0.0;
  Ane[113] = 0.0;
  proc_control_node_B.Ane_tmp_d = in1[9] * proc_control_node_B.t11_k;
  Ane[114] = (((in1[9] * -0.00010396365424827521 - in1[10] *
                0.0030560301354578762) - in1[11] * 0.030270009262121408) -
              proc_control_node_B.t2 * 2.1768827225552109E-5) + (((in1[7] *
    -2.1519484922730651E-5 + in1[8] * 2.989993556213668E-6) -
    proc_control_node_B.Ane_tmp_d * 2.1768827225552109E-5) -
    0.0003258806470891034);
  Ane[115] = ((((in1[9] * 0.0028513455484883 - in1[10] * 0.00032316342950661811)
                + in1[11] * 4.2079285691049859E-5) - proc_control_node_B.t2 *
               0.0036543398217122828) + ((in1[7] * -9.1703771260780813E-5 + in1
    [8] * 1.0731951852318531) - proc_control_node_B.Ane_tmp_d *
    0.0036543398217122828)) + -0.054705685953776693;
  Ane[116] = (((in1[9] * 0.023864851221217471 + in1[10] * 4.0426879502317728E-6)
               - in1[11] * 0.00016269010774240791) + ((proc_control_node_B.t2 *
    0.0003794960966701478 - in1[7] * 0.93255469429176219) - in1[8] *
    9.1703771260780813E-5)) + (proc_control_node_B.Ane_tmp_d *
    0.0003794960966701478 + 0.0056810792914692787);
  Ane[117] = ((((proc_control_node_B.t2 * -0.28560141361437341 +
                 proc_control_node_B.t54) - proc_control_node_B.t55_g) -
               proc_control_node_B.Ane_tmp_d * 0.28560141361437341) -
              4.2754702636882254) + ((in1[9] * 0.00017692814721597281 - in1[10] *
    0.00301187450220627) + in1[11] * 0.0032852614324183722);
  Ane[118] = (((in1[9] * 0.005100926963153893 + in1[10] * 7.54282242443926E-5) +
               in1[11] * 0.76112100692746432) + ((proc_control_node_B.t2 *
    0.0013404854555911631 + in1[7] * 0.0012538688125934979) - in1[8] *
    0.00032387772021301561)) + (proc_control_node_B.Ane_tmp_d *
    0.0013404854555911631 + 0.02006714753878986);
  Ane[119] = (((in1[9] * -0.0085297096290247246 - in1[10] * 0.59953739020136265)
               - in1[11] * 6.8948828938803766E-5) + ((proc_control_node_B.t2 *
    0.00066564938883491385 + in1[7] * 1.6661666253314429E-5) - in1[8] *
    0.0013492616947596331)) + (proc_control_node_B.Ane_tmp_d *
    0.00066564938883491385 + 0.0099648112101035);
  Ane[120] = 0.0;
  Ane[121] = 0.0;
  Ane[122] = 0.0;
  Ane[123] = proc_control_node_B.Ane_tmp_e * proc_control_node_B.t27_n;
  Ane[124] = proc_control_node_B.t5;
  Ane[125] = proc_control_node_B.t12_m * proc_control_node_B.t27_n;
  proc_control_node_B.Ane_tmp_d = in1[10] * proc_control_node_B.t14_d;
  Ane[126] = (((in1[9] * -0.0030560301354578762 + in1[10] * 0.001929418735906703)
               + in1[11] * 6.2884941489263073E-5) + proc_control_node_B.t3 *
              0.001003331497170287) + (((in1[6] * 9.7602896722846373E-5 - in1[8]
    * 1.4431163638272659) + proc_control_node_B.Ane_tmp_d * 0.001003331497170287)
    + 0.01755830120048002);
  Ane[127] = (((in1[9] * -0.00032316342950661811 + in1[10] *
                4.5292476302332957E-6) - in1[11] * 0.016528998001422841) +
              proc_control_node_B.t3 * 1.026911824132076E-5) + (((in1[6] *
    0.00041592787873873338 - in1[8] * 1.356129262930646E-5) +
    proc_control_node_B.Ane_tmp_d * 1.026911824132076E-5) +
    0.0001797095692231134);
  Ane[128] = (((in1[9] * 4.0426879502317728E-6 + in1[10] * 0.023860477346842442)
               - in1[11] * 0.000941018323416786) + ((proc_control_node_B.t3 *
    -3.9756137245743291E-5 + in1[6] * 0.69409782663856512) + in1[8] *
    9.7602896722846373E-5)) + (proc_control_node_B.Ane_tmp_d *
    -3.9756137245743291E-5 - 0.00069573240180050748);
  Ane[129] = (((in1[9] * -0.00301187450220627 + in1[10] * 0.00082864946354184129)
               - in1[11] * 0.291807921220024) + ((proc_control_node_B.t3 *
    0.00080268590155159437 + in1[6] * 0.032506453976272241) - in1[8] *
    0.0018646499569661989)) + (proc_control_node_B.Ane_tmp_d *
    0.00080268590155159437 + 0.0140470032771529);
  Ane[130] = ((((proc_control_node_B.t3 * -0.058374455968341669 +
                 proc_control_node_B.t52) - proc_control_node_B.t53) -
               proc_control_node_B.Ane_tmp_d * 0.058374455968341669) -
              1.021552979445979) + ((in1[9] * 7.54282242443926E-5 - in1[10] *
    0.00019446645525741661) - in1[11] * 0.003324115892995542);
  Ane[131] = ((((proc_control_node_B.t3 * 1.6062902063655571E-7 - in1[6] *
                 7.5569972812640509E-5) - in1[8] * 0.01448357294143097) +
               proc_control_node_B.Ane_tmp_d * 1.6062902063655571E-7) + ((in1[9]
    * -0.59953739020136265 + in1[10] * 0.0085432434746820687) + in1[11] *
    0.0030111351640179931)) + 2.8110078611397252E-6;
  Ane[132] = 0.0;
  Ane[133] = 0.0;
  Ane[134] = 0.0;
  Ane[135] = proc_control_node_B.Ane_tmp * proc_control_node_B.t27_n;
  Ane[136] = -proc_control_node_B.t12_m;
  Ane[137] = proc_control_node_B.t5 * proc_control_node_B.t27_n;
  proc_control_node_B.Ane_tmp_d = in1[11] * proc_control_node_B.t15_g;
  Ane[138] = (((in1[9] * -0.030270009262121408 + in1[10] * 6.2884941489263073E-5)
               + in1[11] * 0.0020006959490984312) - proc_control_node_B.t4 *
              0.0001032754577185093) + (((in1[6] * 1.0571299073092789E-5 + in1[7]
    * 1.3454180758607359) - proc_control_node_B.Ane_tmp_d *
    0.0001032754577185093) - 0.00379689182788637);
  Ane[139] = (((in1[9] * 4.2079285691049859E-5 - in1[10] * 0.016528998001422841)
               + in1[11] * 0.00283488707941543) + proc_control_node_B.t4 *
              4.3636352726935713E-5) + (((in1[6] * -0.74121409319149256 + in1[7]
    * 1.0571299073092789E-5) + proc_control_node_B.Ane_tmp_d *
    4.3636352726935713E-5) + 0.001604277673784401);
  Ane[140] = ((((proc_control_node_B.t4 * -5.3885346962112674E-7 - in1[6] *
                 0.00032422410747795261) - in1[7] * 7.6083411800115719E-5) -
               proc_control_node_B.Ane_tmp_d * 5.3885346962112674E-7) + ((in1[9]
    * -0.00016269010774240791 - in1[10] * 0.000941018323416786) - in1[11] *
    2.6641242336162E-6)) + -1.981078932430613E-5;
  Ane[141] = (((in1[9] * 0.0032852614324183722 - in1[10] * 0.291807921220024) -
               in1[11] * 0.00063467747547131872) + ((proc_control_node_B.t4 *
    0.00040656429737222281 + in1[6] * 0.24400486517334929) + in1[7] *
    0.00145353196782447)) + (proc_control_node_B.Ane_tmp_d *
    0.00040656429737222281 + 0.01494721681515525);
  Ane[142] = ((((proc_control_node_B.t4 * 1.6384160104928689E-7 - in1[6] *
                 0.001145088836853196) - in1[7] * 0.1118794885864644) +
               proc_control_node_B.Ane_tmp_d * 1.6384160104928689E-7) + ((in1[9]
    * 0.76112100692746432 - in1[10] * 0.003324115892995542) - in1[11] *
    0.005288701994301117)) + 6.02358827387084E-6;
  Ane[143] = ((((proc_control_node_B.t4 * -0.054076220260104418 +
                 proc_control_node_B.t48) - proc_control_node_B.t49) -
               proc_control_node_B.Ane_tmp_d * 0.054076220260104418) -
              1.988096333092074) + ((in1[9] * -6.8948828938803766E-5 + in1[10] *
    0.0030111351640179931) + in1[11] * 1.7711862430984169E-5);
}

// Function for MATLAB Function: '<S110>/MATLAB Function2'
static int32_T proc_control_node_xgetrfs(real_T A[400], real_T B[400])
{
  int32_T info;
  for (proc_control_node_B.c_ix = 0; proc_control_node_B.c_ix < 20;
       proc_control_node_B.c_ix++) {
    proc_control_node_B.ipiv_a[proc_control_node_B.c_ix] = static_cast<int8_T>
      (proc_control_node_B.c_ix + 1);
  }

  info = 0;
  for (proc_control_node_B.b_j_i = 0; proc_control_node_B.b_j_i < 19;
       proc_control_node_B.b_j_i++) {
    proc_control_node_B.c_l = proc_control_node_B.b_j_i * 21;
    proc_control_node_B.jA = 0;
    proc_control_node_B.ix = proc_control_node_B.c_l;
    proc_control_node_B.smax = fabs(A[proc_control_node_B.c_l]);
    proc_control_node_B.iy = 2;
    while (proc_control_node_B.iy <= 20 - proc_control_node_B.b_j_i) {
      proc_control_node_B.ix++;
      proc_control_node_B.y_p = fabs(A[proc_control_node_B.ix]);
      if (proc_control_node_B.y_p > proc_control_node_B.smax) {
        proc_control_node_B.jA = proc_control_node_B.iy - 1;
        proc_control_node_B.smax = proc_control_node_B.y_p;
      }

      proc_control_node_B.iy++;
    }

    if (A[proc_control_node_B.c_l + proc_control_node_B.jA] != 0.0) {
      if (proc_control_node_B.jA != 0) {
        proc_control_node_B.c_ix = proc_control_node_B.b_j_i +
          proc_control_node_B.jA;
        proc_control_node_B.ipiv_a[proc_control_node_B.b_j_i] =
          static_cast<int8_T>(proc_control_node_B.c_ix + 1);
        for (proc_control_node_B.jA = 0; proc_control_node_B.jA < 20;
             proc_control_node_B.jA++) {
          proc_control_node_B.ix = proc_control_node_B.jA * 20 +
            proc_control_node_B.b_j_i;
          proc_control_node_B.smax = A[proc_control_node_B.ix];
          proc_control_node_B.iy = proc_control_node_B.jA * 20 +
            proc_control_node_B.c_ix;
          A[proc_control_node_B.ix] = A[proc_control_node_B.iy];
          A[proc_control_node_B.iy] = proc_control_node_B.smax;
        }
      }

      proc_control_node_B.jA = (proc_control_node_B.c_l -
        proc_control_node_B.b_j_i) + 20;
      proc_control_node_B.ix = proc_control_node_B.c_l + 1;
      while (proc_control_node_B.ix + 1 <= proc_control_node_B.jA) {
        A[proc_control_node_B.ix] /= A[proc_control_node_B.c_l];
        proc_control_node_B.ix++;
      }
    } else {
      info = proc_control_node_B.b_j_i + 1;
    }

    proc_control_node_B.jA = proc_control_node_B.c_l;
    proc_control_node_B.ix = proc_control_node_B.c_l + 20;
    proc_control_node_B.iy = 0;
    while (proc_control_node_B.iy <= 18 - proc_control_node_B.b_j_i) {
      if (A[proc_control_node_B.ix] != 0.0) {
        proc_control_node_B.smax = -A[proc_control_node_B.ix];
        proc_control_node_B.c_ix = proc_control_node_B.c_l + 1;
        proc_control_node_B.d_i = (proc_control_node_B.jA -
          proc_control_node_B.b_j_i) + 40;
        proc_control_node_B.ijA = proc_control_node_B.jA + 21;
        while (proc_control_node_B.ijA + 1 <= proc_control_node_B.d_i) {
          A[proc_control_node_B.ijA] += A[proc_control_node_B.c_ix] *
            proc_control_node_B.smax;
          proc_control_node_B.c_ix++;
          proc_control_node_B.ijA++;
        }
      }

      proc_control_node_B.ix += 20;
      proc_control_node_B.jA += 20;
      proc_control_node_B.iy++;
    }
  }

  if ((info == 0) && (!(A[399] != 0.0))) {
    info = 20;
  }

  for (proc_control_node_B.b_j_i = 0; proc_control_node_B.b_j_i < 19;
       proc_control_node_B.b_j_i++) {
    proc_control_node_B.ipiv_l =
      proc_control_node_B.ipiv_a[proc_control_node_B.b_j_i];
    if (proc_control_node_B.b_j_i + 1 != proc_control_node_B.ipiv_l) {
      for (proc_control_node_B.c_l = 0; proc_control_node_B.c_l < 20;
           proc_control_node_B.c_l++) {
        proc_control_node_B.ix = 20 * proc_control_node_B.c_l +
          proc_control_node_B.b_j_i;
        proc_control_node_B.smax = B[proc_control_node_B.ix];
        proc_control_node_B.c_ix = (proc_control_node_B.ipiv_l + 20 *
          proc_control_node_B.c_l) - 1;
        B[proc_control_node_B.ix] = B[proc_control_node_B.c_ix];
        B[proc_control_node_B.c_ix] = proc_control_node_B.smax;
      }
    }
  }

  for (proc_control_node_B.b_j_i = 0; proc_control_node_B.b_j_i < 20;
       proc_control_node_B.b_j_i++) {
    proc_control_node_B.jA = 20 * proc_control_node_B.b_j_i;
    for (proc_control_node_B.c_l = 0; proc_control_node_B.c_l < 20;
         proc_control_node_B.c_l++) {
      proc_control_node_B.ix = 20 * proc_control_node_B.c_l;
      if (B[proc_control_node_B.c_l + proc_control_node_B.jA] != 0.0) {
        proc_control_node_B.iy = proc_control_node_B.c_l + 2;
        while (proc_control_node_B.iy < 21) {
          proc_control_node_B.c_ix = (proc_control_node_B.iy +
            proc_control_node_B.jA) - 1;
          B[proc_control_node_B.c_ix] -= A[(proc_control_node_B.iy +
            proc_control_node_B.ix) - 1] * B[proc_control_node_B.c_l +
            proc_control_node_B.jA];
          proc_control_node_B.iy++;
        }
      }
    }
  }

  for (proc_control_node_B.b_j_i = 0; proc_control_node_B.b_j_i < 20;
       proc_control_node_B.b_j_i++) {
    proc_control_node_B.jA = 20 * proc_control_node_B.b_j_i;
    for (proc_control_node_B.c_l = 19; proc_control_node_B.c_l >= 0;
         proc_control_node_B.c_l--) {
      proc_control_node_B.ix = 20 * proc_control_node_B.c_l;
      proc_control_node_B.c_ix = proc_control_node_B.c_l +
        proc_control_node_B.jA;
      proc_control_node_B.smax = B[proc_control_node_B.c_ix];
      if (proc_control_node_B.smax != 0.0) {
        B[proc_control_node_B.c_ix] = proc_control_node_B.smax /
          A[proc_control_node_B.c_l + proc_control_node_B.ix];
        proc_control_node_B.iy = 0;
        while (proc_control_node_B.iy <= proc_control_node_B.c_l - 1) {
          proc_control_node_B.d_i = proc_control_node_B.iy +
            proc_control_node_B.jA;
          B[proc_control_node_B.d_i] -= B[proc_control_node_B.c_ix] *
            A[proc_control_node_B.iy + proc_control_node_B.ix];
          proc_control_node_B.iy++;
        }
      }
    }
  }

  return info;
}

// Function for MATLAB Function: '<S110>/MATLAB Function2'
static void proc_control_node_lusolve(const real_T A[400], const real_T B[400],
  real_T X[400])
{
  memcpy(&X[0], &B[0], 400U * sizeof(real_T));
  memcpy(&proc_control_node_B.b_A[0], &A[0], 400U * sizeof(real_T));
  proc_control_node_xgetrfs(proc_control_node_B.b_A, X);
}

// Function for MATLAB Function: '<S110>/MATLAB Function2'
static void proc_co_PadeApproximantOfDegree(const real_T A[400], uint8_T m,
  real_T F[400])
{
  for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
       proc_control_node_B.i4++) {
    memset(&proc_control_node_B.A2[proc_control_node_B.i4 * 20], 0, 20U * sizeof
           (real_T));
    for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
         proc_control_node_B.e_k++) {
      for (proc_control_node_B.e_k_n = 0; proc_control_node_B.e_k_n < 20;
           proc_control_node_B.e_k_n++) {
        proc_control_node_B.A2_tmp = 20 * proc_control_node_B.i4 +
          proc_control_node_B.e_k_n;
        proc_control_node_B.A2[proc_control_node_B.A2_tmp] += A[20 *
          proc_control_node_B.e_k + proc_control_node_B.e_k_n] * A[20 *
          proc_control_node_B.i4 + proc_control_node_B.e_k];
      }
    }
  }

  if (m == 3) {
    memcpy(&proc_control_node_B.U_c[0], &proc_control_node_B.A2[0], 400U *
           sizeof(real_T));
    proc_control_node_B.e_k_n = 0;
    proc_control_node_B.A2_tmp = 0;
    for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
         proc_control_node_B.e_k++) {
      memset(&proc_control_node_B.A4_f[proc_control_node_B.A2_tmp], 0, 20U *
             sizeof(real_T));
      proc_control_node_B.U_c[proc_control_node_B.e_k_n] += 60.0;
      proc_control_node_B.e_k_n += 21;
      proc_control_node_B.A2_tmp += 20;
    }

    proc_control_node_B.e_k_n = 0;
    for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
         proc_control_node_B.e_k++) {
      proc_control_node_B.A2_tmp = 0;
      for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
           proc_control_node_B.i5++) {
        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
             proc_control_node_B.i4++) {
          proc_control_node_B.A_tmp = proc_control_node_B.i4 +
            proc_control_node_B.e_k_n;
          proc_control_node_B.A4_f[proc_control_node_B.A_tmp] +=
            A[proc_control_node_B.i4 + proc_control_node_B.A2_tmp] *
            proc_control_node_B.U_c[proc_control_node_B.i5 +
            proc_control_node_B.e_k_n];
        }

        proc_control_node_B.A2_tmp += 20;
      }

      proc_control_node_B.e_k_n += 20;
    }

    for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
         proc_control_node_B.i4++) {
      proc_control_node_B.U_c[proc_control_node_B.i4] =
        proc_control_node_B.A4_f[proc_control_node_B.i4];
      proc_control_node_B.V[proc_control_node_B.i4] = 12.0 *
        proc_control_node_B.A2[proc_control_node_B.i4];
    }

    proc_control_node_B.d_pe = 120.0;
  } else {
    for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
         proc_control_node_B.i4++) {
      memset(&proc_control_node_B.A3[proc_control_node_B.i4 * 20], 0, 20U *
             sizeof(real_T));
      for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
           proc_control_node_B.e_k++) {
        for (proc_control_node_B.e_k_n = 0; proc_control_node_B.e_k_n < 20;
             proc_control_node_B.e_k_n++) {
          proc_control_node_B.A2_tmp = 20 * proc_control_node_B.i4 +
            proc_control_node_B.e_k_n;
          proc_control_node_B.A3[proc_control_node_B.A2_tmp] +=
            proc_control_node_B.A2[20 * proc_control_node_B.e_k +
            proc_control_node_B.e_k_n] * proc_control_node_B.A2[20 *
            proc_control_node_B.i4 + proc_control_node_B.e_k];
        }
      }
    }

    if (m == 5) {
      for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
           proc_control_node_B.i4++) {
        proc_control_node_B.U_c[proc_control_node_B.i4] = 420.0 *
          proc_control_node_B.A2[proc_control_node_B.i4] +
          proc_control_node_B.A3[proc_control_node_B.i4];
      }

      proc_control_node_B.e_k_n = 0;
      proc_control_node_B.A2_tmp = 0;
      for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
           proc_control_node_B.e_k++) {
        memset(&proc_control_node_B.A4_f[proc_control_node_B.A2_tmp], 0, 20U *
               sizeof(real_T));
        proc_control_node_B.U_c[proc_control_node_B.e_k_n] += 15120.0;
        proc_control_node_B.e_k_n += 21;
        proc_control_node_B.A2_tmp += 20;
      }

      proc_control_node_B.e_k_n = 0;
      for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
           proc_control_node_B.e_k++) {
        proc_control_node_B.A2_tmp = 0;
        for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
             proc_control_node_B.i5++) {
          for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
               proc_control_node_B.i4++) {
            proc_control_node_B.A_tmp = proc_control_node_B.i4 +
              proc_control_node_B.e_k_n;
            proc_control_node_B.A4_f[proc_control_node_B.A_tmp] +=
              A[proc_control_node_B.i4 + proc_control_node_B.A2_tmp] *
              proc_control_node_B.U_c[proc_control_node_B.i5 +
              proc_control_node_B.e_k_n];
          }

          proc_control_node_B.A2_tmp += 20;
        }

        proc_control_node_B.e_k_n += 20;
      }

      for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
           proc_control_node_B.i4++) {
        proc_control_node_B.U_c[proc_control_node_B.i4] =
          proc_control_node_B.A4_f[proc_control_node_B.i4];
        proc_control_node_B.V[proc_control_node_B.i4] = 30.0 *
          proc_control_node_B.A3[proc_control_node_B.i4] + 3360.0 *
          proc_control_node_B.A2[proc_control_node_B.i4];
      }

      proc_control_node_B.d_pe = 30240.0;
    } else {
      for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
           proc_control_node_B.i4++) {
        memset(&proc_control_node_B.A4[proc_control_node_B.i4 * 20], 0, 20U *
               sizeof(real_T));
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          for (proc_control_node_B.e_k_n = 0; proc_control_node_B.e_k_n < 20;
               proc_control_node_B.e_k_n++) {
            proc_control_node_B.A2_tmp = 20 * proc_control_node_B.i4 +
              proc_control_node_B.e_k_n;
            proc_control_node_B.A4[proc_control_node_B.A2_tmp] +=
              proc_control_node_B.A3[20 * proc_control_node_B.e_k +
              proc_control_node_B.e_k_n] * proc_control_node_B.A2[20 *
              proc_control_node_B.i4 + proc_control_node_B.e_k];
          }
        }
      }

      switch (m) {
       case 7:
        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.U_c[proc_control_node_B.i4] = (1512.0 *
            proc_control_node_B.A3[proc_control_node_B.i4] +
            proc_control_node_B.A4[proc_control_node_B.i4]) + 277200.0 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        proc_control_node_B.e_k_n = 0;
        proc_control_node_B.A2_tmp = 0;
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          memset(&proc_control_node_B.A4_f[proc_control_node_B.A2_tmp], 0, 20U *
                 sizeof(real_T));
          proc_control_node_B.U_c[proc_control_node_B.e_k_n] += 8.64864E+6;
          proc_control_node_B.e_k_n += 21;
          proc_control_node_B.A2_tmp += 20;
        }

        proc_control_node_B.e_k_n = 0;
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          proc_control_node_B.A2_tmp = 0;
          for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
               proc_control_node_B.i5++) {
            for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
                 proc_control_node_B.i4++) {
              proc_control_node_B.A_tmp = proc_control_node_B.i4 +
                proc_control_node_B.e_k_n;
              proc_control_node_B.A4_f[proc_control_node_B.A_tmp] +=
                A[proc_control_node_B.i4 + proc_control_node_B.A2_tmp] *
                proc_control_node_B.U_c[proc_control_node_B.i5 +
                proc_control_node_B.e_k_n];
            }

            proc_control_node_B.A2_tmp += 20;
          }

          proc_control_node_B.e_k_n += 20;
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.U_c[proc_control_node_B.i4] =
            proc_control_node_B.A4_f[proc_control_node_B.i4];
          proc_control_node_B.V[proc_control_node_B.i4] = (56.0 *
            proc_control_node_B.A4[proc_control_node_B.i4] + 25200.0 *
            proc_control_node_B.A3[proc_control_node_B.i4]) + 1.99584E+6 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        proc_control_node_B.d_pe = 1.729728E+7;
        break;

       case 9:
        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
             proc_control_node_B.i4++) {
          memset(&proc_control_node_B.V[proc_control_node_B.i4 * 20], 0, 20U *
                 sizeof(real_T));
          for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
               proc_control_node_B.e_k++) {
            for (proc_control_node_B.e_k_n = 0; proc_control_node_B.e_k_n < 20;
                 proc_control_node_B.e_k_n++) {
              proc_control_node_B.A2_tmp = 20 * proc_control_node_B.i4 +
                proc_control_node_B.e_k_n;
              proc_control_node_B.V[proc_control_node_B.A2_tmp] +=
                proc_control_node_B.A4[20 * proc_control_node_B.e_k +
                proc_control_node_B.e_k_n] * proc_control_node_B.A2[20 *
                proc_control_node_B.i4 + proc_control_node_B.e_k];
            }
          }
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.U_c[proc_control_node_B.i4] = ((3960.0 *
            proc_control_node_B.A4[proc_control_node_B.i4] +
            proc_control_node_B.V[proc_control_node_B.i4]) + 2.16216E+6 *
            proc_control_node_B.A3[proc_control_node_B.i4]) + 3.027024E+8 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        proc_control_node_B.e_k_n = 0;
        proc_control_node_B.A2_tmp = 0;
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          memset(&proc_control_node_B.A4_f[proc_control_node_B.A2_tmp], 0, 20U *
                 sizeof(real_T));
          proc_control_node_B.U_c[proc_control_node_B.e_k_n] += 8.8216128E+9;
          proc_control_node_B.e_k_n += 21;
          proc_control_node_B.A2_tmp += 20;
        }

        proc_control_node_B.e_k_n = 0;
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          proc_control_node_B.A2_tmp = 0;
          for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
               proc_control_node_B.i5++) {
            for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
                 proc_control_node_B.i4++) {
              proc_control_node_B.A_tmp = proc_control_node_B.i4 +
                proc_control_node_B.e_k_n;
              proc_control_node_B.A4_f[proc_control_node_B.A_tmp] +=
                A[proc_control_node_B.i4 + proc_control_node_B.A2_tmp] *
                proc_control_node_B.U_c[proc_control_node_B.i5 +
                proc_control_node_B.e_k_n];
            }

            proc_control_node_B.A2_tmp += 20;
          }

          proc_control_node_B.e_k_n += 20;
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.U_c[proc_control_node_B.i4] =
            proc_control_node_B.A4_f[proc_control_node_B.i4];
          proc_control_node_B.V[proc_control_node_B.i4] = ((90.0 *
            proc_control_node_B.V[proc_control_node_B.i4] + 110880.0 *
            proc_control_node_B.A4[proc_control_node_B.i4]) + 3.027024E+7 *
            proc_control_node_B.A3[proc_control_node_B.i4]) + 2.0756736E+9 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        proc_control_node_B.d_pe = 1.76432256E+10;
        break;

       default:
        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.U_c[proc_control_node_B.i4] = (3.352212864E+10 *
            proc_control_node_B.A4[proc_control_node_B.i4] + 1.05594705216E+13 *
            proc_control_node_B.A3[proc_control_node_B.i4]) +
            1.1873537964288E+15 * proc_control_node_B.A2[proc_control_node_B.i4];
        }

        proc_control_node_B.e_k_n = 0;
        for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
             proc_control_node_B.e_k++) {
          proc_control_node_B.U_c[proc_control_node_B.e_k_n] +=
            3.238237626624E+16;
          proc_control_node_B.e_k_n += 21;
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.V[proc_control_node_B.i4] = (16380.0 *
            proc_control_node_B.A3[proc_control_node_B.i4] +
            proc_control_node_B.A4[proc_control_node_B.i4]) + 4.08408E+7 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
             proc_control_node_B.i4++) {
          proc_control_node_B.e_k_n = 0;
          for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
               proc_control_node_B.e_k++) {
            proc_control_node_B.d_pe = 0.0;
            proc_control_node_B.A2_tmp = 0;
            for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
                 proc_control_node_B.i5++) {
              proc_control_node_B.d_pe +=
                proc_control_node_B.A4[proc_control_node_B.A2_tmp +
                proc_control_node_B.i4] *
                proc_control_node_B.V[proc_control_node_B.i5 +
                proc_control_node_B.e_k_n];
              proc_control_node_B.A2_tmp += 20;
            }

            proc_control_node_B.A2_tmp = proc_control_node_B.e_k_n +
              proc_control_node_B.i4;
            proc_control_node_B.A4_f[proc_control_node_B.A2_tmp] =
              proc_control_node_B.U_c[proc_control_node_B.A2_tmp] +
              proc_control_node_B.d_pe;
            proc_control_node_B.e_k_n += 20;
          }
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
             proc_control_node_B.i4++) {
          memset(&proc_control_node_B.U_c[proc_control_node_B.i4 * 20], 0, 20U *
                 sizeof(real_T));
          for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
               proc_control_node_B.e_k++) {
            for (proc_control_node_B.e_k_n = 0; proc_control_node_B.e_k_n < 20;
                 proc_control_node_B.e_k_n++) {
              proc_control_node_B.A2_tmp = 20 * proc_control_node_B.i4 +
                proc_control_node_B.e_k_n;
              proc_control_node_B.U_c[proc_control_node_B.A2_tmp] += A[20 *
                proc_control_node_B.e_k + proc_control_node_B.e_k_n] *
                proc_control_node_B.A4_f[20 * proc_control_node_B.i4 +
                proc_control_node_B.e_k];
            }
          }
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 400;
             proc_control_node_B.i4++) {
          proc_control_node_B.A4_f[proc_control_node_B.i4] = (182.0 *
            proc_control_node_B.A4[proc_control_node_B.i4] + 960960.0 *
            proc_control_node_B.A3[proc_control_node_B.i4]) + 1.32324192E+9 *
            proc_control_node_B.A2[proc_control_node_B.i4];
        }

        for (proc_control_node_B.i4 = 0; proc_control_node_B.i4 < 20;
             proc_control_node_B.i4++) {
          proc_control_node_B.e_k_n = 0;
          for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
               proc_control_node_B.e_k++) {
            proc_control_node_B.d_pe = 0.0;
            proc_control_node_B.A2_tmp = 0;
            for (proc_control_node_B.i5 = 0; proc_control_node_B.i5 < 20;
                 proc_control_node_B.i5++) {
              proc_control_node_B.d_pe +=
                proc_control_node_B.A4[proc_control_node_B.A2_tmp +
                proc_control_node_B.i4] *
                proc_control_node_B.A4_f[proc_control_node_B.i5 +
                proc_control_node_B.e_k_n];
              proc_control_node_B.A2_tmp += 20;
            }

            proc_control_node_B.A2_tmp = proc_control_node_B.e_k_n +
              proc_control_node_B.i4;
            proc_control_node_B.V[proc_control_node_B.A2_tmp] =
              ((proc_control_node_B.A4[proc_control_node_B.A2_tmp] *
                6.704425728E+11 + proc_control_node_B.d_pe) +
               proc_control_node_B.A3[proc_control_node_B.A2_tmp] *
               1.29060195264E+14) +
              proc_control_node_B.A2[proc_control_node_B.A2_tmp] *
              7.7717703038976E+15;
            proc_control_node_B.e_k_n += 20;
          }
        }

        proc_control_node_B.d_pe = 6.476475253248E+16;
        break;
      }
    }
  }

  proc_control_node_B.e_k_n = 0;
  for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
       proc_control_node_B.e_k++) {
    proc_control_node_B.V[proc_control_node_B.e_k_n] += proc_control_node_B.d_pe;
    proc_control_node_B.e_k_n += 21;
  }

  for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 400;
       proc_control_node_B.e_k++) {
    proc_control_node_B.V[proc_control_node_B.e_k] -=
      proc_control_node_B.U_c[proc_control_node_B.e_k];
    proc_control_node_B.U_c[proc_control_node_B.e_k] *= 2.0;
  }

  proc_control_node_lusolve(proc_control_node_B.V, proc_control_node_B.U_c, F);
  proc_control_node_B.e_k_n = 0;
  for (proc_control_node_B.e_k = 0; proc_control_node_B.e_k < 20;
       proc_control_node_B.e_k++) {
    F[proc_control_node_B.e_k_n]++;
    proc_control_node_B.e_k_n += 21;
  }
}

// Function for MATLAB Function: '<S110>/MATLAB Function2'
static void proc_control_node_expm(real_T A[400], real_T F[400])
{
  static const real_T theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  static const uint8_T b[5] = { 3U, 5U, 7U, 9U, 13U };

  boolean_T exitg1;
  proc_control_node_B.normA = 0.0;
  proc_control_node_B.b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.b_j < 20)) {
    proc_control_node_B.b_s = 0.0;
    for (proc_control_node_B.b_i = 0; proc_control_node_B.b_i < 20;
         proc_control_node_B.b_i++) {
      proc_control_node_B.b_s += fabs(A[20 * proc_control_node_B.b_j +
        proc_control_node_B.b_i]);
    }

    if (rtIsNaN(proc_control_node_B.b_s)) {
      proc_control_node_B.normA = (rtNaN);
      exitg1 = true;
    } else {
      if (proc_control_node_B.b_s > proc_control_node_B.normA) {
        proc_control_node_B.normA = proc_control_node_B.b_s;
      }

      proc_control_node_B.b_j++;
    }
  }

  if (proc_control_node_B.normA <= 5.3719203511481517) {
    proc_control_node_B.b_j = 0;
    exitg1 = false;
    while ((!exitg1) && (proc_control_node_B.b_j < 5)) {
      if (proc_control_node_B.normA <= theta[proc_control_node_B.b_j]) {
        proc_co_PadeApproximantOfDegree(A, b[proc_control_node_B.b_j], F);
        exitg1 = true;
      } else {
        proc_control_node_B.b_j++;
      }
    }
  } else {
    proc_control_node_B.b_s = proc_control_node_B.normA / 5.3719203511481517;
    if ((!rtIsInf(proc_control_node_B.b_s)) && (!rtIsNaN(proc_control_node_B.b_s)))
    {
      proc_control_node_B.b_s = frexp(proc_control_node_B.b_s,
        &proc_control_node_B.e);
    } else {
      proc_control_node_B.e = 0;
    }

    proc_control_node_B.normA = proc_control_node_B.e;
    if (proc_control_node_B.b_s == 0.5) {
      proc_control_node_B.normA = static_cast<real_T>(proc_control_node_B.e) -
        1.0;
    }

    proc_control_node_B.b_s = proc_control_node_rt_powd_snf(2.0,
      proc_control_node_B.normA);
    for (proc_control_node_B.b_i = 0; proc_control_node_B.b_i < 400;
         proc_control_node_B.b_i++) {
      A[proc_control_node_B.b_i] /= proc_control_node_B.b_s;
    }

    proc_co_PadeApproximantOfDegree(A, 13, F);
    proc_control_node_B.b_j = 0;
    while (proc_control_node_B.b_j <= static_cast<int32_T>
           (proc_control_node_B.normA) - 1) {
      for (proc_control_node_B.b_i = 0; proc_control_node_B.b_i < 20;
           proc_control_node_B.b_i++) {
        proc_control_node_B.e = 0;
        for (proc_control_node_B.i1 = 0; proc_control_node_B.i1 < 20;
             proc_control_node_B.i1++) {
          proc_control_node_B.F_tmp = proc_control_node_B.e +
            proc_control_node_B.b_i;
          proc_control_node_B.F[proc_control_node_B.F_tmp] = 0.0;
          proc_control_node_B.i3 = 0;
          for (proc_control_node_B.i2 = 0; proc_control_node_B.i2 < 20;
               proc_control_node_B.i2++) {
            proc_control_node_B.F[proc_control_node_B.F_tmp] +=
              F[proc_control_node_B.i3 + proc_control_node_B.b_i] *
              F[proc_control_node_B.i2 + proc_control_node_B.e];
            proc_control_node_B.i3 += 20;
          }

          proc_control_node_B.e += 20;
        }
      }

      memcpy(&F[0], &proc_control_node_B.F[0], 400U * sizeof(real_T));
      proc_control_node_B.b_j++;
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_no_mpc_plantupdate(const real_T a[144], real_T b[96],
  const real_T c[144], real_T b_A[400], real_T b_B[580], real_T b_C[240], const
  real_T b_D[348], const real_T b_mvindex[8], const real_T b_myindex[12], const
  real_T b_Uscale[8], const real_T b_Yscale[12], real_T Bu[160], real_T Bv[20],
  real_T Cm[240], real_T Dv[12], real_T Dvm[12], real_T QQ[400], real_T RR[144],
  real_T NN[240])
{
  proc_control_node_B.i29 = 0;
  for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 8;
       proc_control_node_B.i28++) {
    for (proc_control_node_B.i27 = 0; proc_control_node_B.i27 < 12;
         proc_control_node_B.i27++) {
      proc_control_node_B.b_tmp = proc_control_node_B.i27 +
        proc_control_node_B.i29;
      b[proc_control_node_B.b_tmp] *= b_Uscale[proc_control_node_B.i28];
    }

    proc_control_node_B.i29 += 12;
  }

  proc_control_node_B.i29 = 0;
  proc_control_node_B.i28 = 0;
  for (proc_control_node_B.i27 = 0; proc_control_node_B.i27 < 12;
       proc_control_node_B.i27++) {
    for (proc_control_node_B.b_tmp = 0; proc_control_node_B.b_tmp < 12;
         proc_control_node_B.b_tmp++) {
      proc_control_node_B.i30 = proc_control_node_B.b_tmp +
        proc_control_node_B.i29;
      b_C[proc_control_node_B.i30] = c[proc_control_node_B.i30] /
        b_Yscale[proc_control_node_B.b_tmp];
      b_A[proc_control_node_B.b_tmp + proc_control_node_B.i28] =
        a[proc_control_node_B.i30];
    }

    proc_control_node_B.i29 += 12;
    proc_control_node_B.i28 += 20;
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 8;
       proc_control_node_B.i29++) {
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 12;
         proc_control_node_B.i28++) {
      b_B[proc_control_node_B.i28 + 20 * proc_control_node_B.i29] = b[(
        static_cast<int32_T>(b_mvindex[proc_control_node_B.i29]) - 1) * 12 +
        proc_control_node_B.i28];
    }

    memcpy(&Bu[proc_control_node_B.i29 * 20], &b_B[proc_control_node_B.i29 * 20],
           20U * sizeof(real_T));
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 20;
       proc_control_node_B.i29++) {
    Bv[proc_control_node_B.i29] = b_B[proc_control_node_B.i29 + 160];
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 12;
         proc_control_node_B.i28++) {
      Cm[proc_control_node_B.i28 + 12 * proc_control_node_B.i29] = b_C[(12 *
        proc_control_node_B.i29 + static_cast<int32_T>
        (b_myindex[proc_control_node_B.i28])) - 1];
    }
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 12;
       proc_control_node_B.i29++) {
    Dv[proc_control_node_B.i29] = b_D[proc_control_node_B.i29 + 96];
    Dvm[proc_control_node_B.i29] = b_D[static_cast<int32_T>
      (b_myindex[proc_control_node_B.i29]) + 95];
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 28;
       proc_control_node_B.i29++) {
    proc_control_node_B.UnknownIn[proc_control_node_B.i29] = 0;
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 8;
       proc_control_node_B.i29++) {
    proc_control_node_B.UnknownIn[proc_control_node_B.i29] = static_cast<int8_T>
      (proc_control_node_B.i29 + 1);
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 20;
       proc_control_node_B.i29++) {
    proc_control_node_B.UnknownIn[proc_control_node_B.i29 + 8] =
      static_cast<int8_T>(proc_control_node_B.i29 + 10);
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 28;
       proc_control_node_B.i29++) {
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 20;
         proc_control_node_B.i28++) {
      proc_control_node_B.b_B[proc_control_node_B.i28 + (proc_control_node_B.i29
        << 5)] = b_B[(proc_control_node_B.UnknownIn[proc_control_node_B.i29] - 1)
        * 20 + proc_control_node_B.i28];
    }
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 28;
       proc_control_node_B.i29++) {
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 12;
         proc_control_node_B.i28++) {
      proc_control_node_B.b_B[(proc_control_node_B.i28 +
        (proc_control_node_B.i29 << 5)) + 20] = b_D
        [((proc_control_node_B.UnknownIn[proc_control_node_B.i29] - 1) * 12 +
          static_cast<int32_T>(b_myindex[proc_control_node_B.i28])) - 1];
    }
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 20;
       proc_control_node_B.i29++) {
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 28;
         proc_control_node_B.i28++) {
      proc_control_node_B.b_B_k[proc_control_node_B.i28 + 28 *
        proc_control_node_B.i29] = b_B
        [(proc_control_node_B.UnknownIn[proc_control_node_B.i28] - 1) * 20 +
        proc_control_node_B.i29];
    }
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 12;
       proc_control_node_B.i29++) {
    for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 28;
         proc_control_node_B.i28++) {
      proc_control_node_B.b_B_k[proc_control_node_B.i28 + 28 *
        (proc_control_node_B.i29 + 20)] = b_D
        [((proc_control_node_B.UnknownIn[proc_control_node_B.i28] - 1) * 12 +
          static_cast<int32_T>(b_myindex[proc_control_node_B.i29])) - 1];
    }
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 32;
       proc_control_node_B.i29++) {
    memset(&proc_control_node_B.CovMat[proc_control_node_B.i29 << 5], 0, sizeof
           (real_T) << 5U);
    for (proc_control_node_B.i27 = 0; proc_control_node_B.i27 < 28;
         proc_control_node_B.i27++) {
      for (proc_control_node_B.i28 = 0; proc_control_node_B.i28 < 32;
           proc_control_node_B.i28++) {
        proc_control_node_B.b_tmp = (proc_control_node_B.i29 << 5) +
          proc_control_node_B.i28;
        proc_control_node_B.CovMat[proc_control_node_B.b_tmp] +=
          proc_control_node_B.b_B[(proc_control_node_B.i27 << 5) +
          proc_control_node_B.i28] * proc_control_node_B.b_B_k[28 *
          proc_control_node_B.i29 + proc_control_node_B.i27];
      }
    }
  }

  proc_control_node_B.i29 = 0;
  proc_control_node_B.i28 = 0;
  for (proc_control_node_B.i27 = 0; proc_control_node_B.i27 < 20;
       proc_control_node_B.i27++) {
    memcpy(&QQ[proc_control_node_B.i29],
           &proc_control_node_B.CovMat[proc_control_node_B.i28], 20U * sizeof
           (real_T));
    proc_control_node_B.i29 += 20;
    proc_control_node_B.i28 += 32;
  }

  for (proc_control_node_B.i29 = 0; proc_control_node_B.i29 < 12;
       proc_control_node_B.i29++) {
    memcpy(&RR[proc_control_node_B.i29 * 12], &proc_control_node_B.CovMat
           [(proc_control_node_B.i29 << 5) + 660], 12U * sizeof(real_T));
    memcpy(&NN[proc_control_node_B.i29 * 20], &proc_control_node_B.CovMat
           [(proc_control_node_B.i29 << 5) + 640], 20U * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_mod_g(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, proc_control_node_nu);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += proc_control_node_nu;
    }
  }

  return r;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, proc_control_node_ny);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += proc_control_node_ny;
    }
  }

  return r;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_cont_mpc_updateFromNominal(real_T b_Mlim[64], const real_T
  b_Mrows[64], const real_T U0[8], const real_T b_Uscale[8], const real_T
  old_mvoff[8], const real_T b_mvindex[8], real_T b_utarget[80], const real_T
  Y0[12], const real_T b_Yscale[12], const real_T old_yoff[12], const real_T
  b_myindex[12], const real_T X0[12], real_T b_xoff[20], const real_T DX0[12],
  real_T Bv[220], real_T new_mvoff[8], real_T new_yoff[12], real_T new_myoff[12])
{
  for (proc_control_node_B.i_g = 0; proc_control_node_B.i_g < 8;
       proc_control_node_B.i_g++) {
    proc_control_node_B.U_i[proc_control_node_B.i_g] =
      U0[proc_control_node_B.i_g] / b_Uscale[proc_control_node_B.i_g];
  }

  for (proc_control_node_B.i_g = 0; proc_control_node_B.i_g < 12;
       proc_control_node_B.i_g++) {
    new_yoff[proc_control_node_B.i_g] = Y0[proc_control_node_B.i_g] /
      b_Yscale[proc_control_node_B.i_g];
  }

  for (proc_control_node_B.i_g = 0; proc_control_node_B.i_g < 8;
       proc_control_node_B.i_g++) {
    proc_control_node_B.k = b_mvindex[proc_control_node_B.i_g];
    new_mvoff[proc_control_node_B.i_g] = U0[static_cast<int32_T>
      (proc_control_node_B.k) - 1] / b_Uscale[static_cast<int32_T>
      (proc_control_node_B.k) - 1];
  }

  for (proc_control_node_B.i_g = 0; proc_control_node_B.i_g < 12;
       proc_control_node_B.i_g++) {
    new_myoff[proc_control_node_B.i_g] = new_yoff[static_cast<int32_T>
      (b_myindex[proc_control_node_B.i_g]) - 1];
  }

  for (proc_control_node_B.b_ct = 0; proc_control_node_B.b_ct < 64;
       proc_control_node_B.b_ct++) {
    proc_control_node_B.k = b_Mrows[proc_control_node_B.b_ct];
    if (proc_control_node_B.k <= 120.0) {
      proc_control_node_B.k = proc_control_node_mod(proc_control_node_B.k - 1.0)
        + 1.0;
      b_Mlim[proc_control_node_B.b_ct] += old_yoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1] - new_yoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1];
    } else if (proc_control_node_B.k <= 240.0) {
      proc_control_node_B.k = proc_control_node_mod((proc_control_node_B.k -
        120.0) - 1.0) + 1.0;
      b_Mlim[proc_control_node_B.b_ct] -= old_yoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1] - new_yoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1];
    } else if (proc_control_node_B.k <= 320.0) {
      proc_control_node_B.k = proc_control_node_mod_g((proc_control_node_B.k -
        240.0) - 1.0) + 1.0;
      b_Mlim[proc_control_node_B.b_ct] += old_mvoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1] - proc_control_node_B.U_i
        [static_cast<int32_T>(b_mvindex[static_cast<int32_T>
        (proc_control_node_B.k) - 1]) - 1];
    } else if (proc_control_node_B.k <= 400.0) {
      proc_control_node_B.k = proc_control_node_mod_g(((proc_control_node_B.k -
        240.0) - 80.0) - 1.0) + 1.0;
      b_Mlim[proc_control_node_B.b_ct] -= old_mvoff[static_cast<int32_T>
        (proc_control_node_B.k) - 1] - proc_control_node_B.U_i
        [static_cast<int32_T>(b_mvindex[static_cast<int32_T>
        (proc_control_node_B.k) - 1]) - 1];
    }
  }

  for (proc_control_node_B.b_ct = 0; proc_control_node_B.b_ct < 8;
       proc_control_node_B.b_ct++) {
    proc_control_node_B.k = old_mvoff[proc_control_node_B.b_ct];
    proc_control_node_B.U_j = proc_control_node_B.U_i[static_cast<int32_T>
      (b_mvindex[proc_control_node_B.b_ct]) - 1];
    for (proc_control_node_B.i_g = 0; proc_control_node_B.i_g < 10;
         proc_control_node_B.i_g++) {
      proc_control_node_B.b_utarget_tmp = (proc_control_node_B.i_g << 3) +
        proc_control_node_B.b_ct;
      b_utarget[proc_control_node_B.b_utarget_tmp] =
        (b_utarget[proc_control_node_B.b_utarget_tmp] + proc_control_node_B.k) -
        proc_control_node_B.U_j;
    }
  }

  memcpy(&b_xoff[0], &X0[0], 12U * sizeof(real_T));
  memcpy(&Bv[0], &DX0[0], 12U * sizeof(real_T));
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xgetrf(real_T b_A[144], int32_T ipiv[12], int32_T *
  info)
{
  for (proc_control_node_B.ix_i = 0; proc_control_node_B.ix_i < 12;
       proc_control_node_B.ix_i++) {
    ipiv[proc_control_node_B.ix_i] = proc_control_node_B.ix_i + 1;
  }

  *info = 0;
  for (proc_control_node_B.j_c = 0; proc_control_node_B.j_c < 11;
       proc_control_node_B.j_c++) {
    proc_control_node_B.c_h = proc_control_node_B.j_c * 13;
    proc_control_node_B.jA_f = 0;
    proc_control_node_B.ix_i = proc_control_node_B.c_h;
    proc_control_node_B.smax_c = fabs(b_A[proc_control_node_B.c_h]);
    proc_control_node_B.iy_p = 2;
    while (proc_control_node_B.iy_p <= 12 - proc_control_node_B.j_c) {
      proc_control_node_B.ix_i++;
      proc_control_node_B.y_nb = fabs(b_A[proc_control_node_B.ix_i]);
      if (proc_control_node_B.y_nb > proc_control_node_B.smax_c) {
        proc_control_node_B.jA_f = proc_control_node_B.iy_p - 1;
        proc_control_node_B.smax_c = proc_control_node_B.y_nb;
      }

      proc_control_node_B.iy_p++;
    }

    if (b_A[proc_control_node_B.c_h + proc_control_node_B.jA_f] != 0.0) {
      if (proc_control_node_B.jA_f != 0) {
        proc_control_node_B.iy_p = proc_control_node_B.j_c +
          proc_control_node_B.jA_f;
        ipiv[proc_control_node_B.j_c] = proc_control_node_B.iy_p + 1;
        for (proc_control_node_B.jA_f = 0; proc_control_node_B.jA_f < 12;
             proc_control_node_B.jA_f++) {
          proc_control_node_B.c_ix_e = proc_control_node_B.jA_f * 12 +
            proc_control_node_B.j_c;
          proc_control_node_B.smax_c = b_A[proc_control_node_B.c_ix_e];
          proc_control_node_B.ix_i = proc_control_node_B.jA_f * 12 +
            proc_control_node_B.iy_p;
          b_A[proc_control_node_B.c_ix_e] = b_A[proc_control_node_B.ix_i];
          b_A[proc_control_node_B.ix_i] = proc_control_node_B.smax_c;
        }
      }

      proc_control_node_B.jA_f = (proc_control_node_B.c_h -
        proc_control_node_B.j_c) + 12;
      proc_control_node_B.ix_i = proc_control_node_B.c_h + 1;
      while (proc_control_node_B.ix_i + 1 <= proc_control_node_B.jA_f) {
        b_A[proc_control_node_B.ix_i] /= b_A[proc_control_node_B.c_h];
        proc_control_node_B.ix_i++;
      }
    } else {
      *info = proc_control_node_B.j_c + 1;
    }

    proc_control_node_B.jA_f = proc_control_node_B.c_h;
    proc_control_node_B.ix_i = proc_control_node_B.c_h + 12;
    proc_control_node_B.iy_p = 0;
    while (proc_control_node_B.iy_p <= 10 - proc_control_node_B.j_c) {
      if (b_A[proc_control_node_B.ix_i] != 0.0) {
        proc_control_node_B.smax_c = -b_A[proc_control_node_B.ix_i];
        proc_control_node_B.c_ix_e = proc_control_node_B.c_h + 1;
        proc_control_node_B.d_n = (proc_control_node_B.jA_f -
          proc_control_node_B.j_c) + 24;
        proc_control_node_B.ijA_h = proc_control_node_B.jA_f + 13;
        while (proc_control_node_B.ijA_h + 1 <= proc_control_node_B.d_n) {
          b_A[proc_control_node_B.ijA_h] += b_A[proc_control_node_B.c_ix_e] *
            proc_control_node_B.smax_c;
          proc_control_node_B.c_ix_e++;
          proc_control_node_B.ijA_h++;
        }
      }

      proc_control_node_B.ix_i += 12;
      proc_control_node_B.jA_f += 12;
      proc_control_node_B.iy_p++;
    }
  }

  if ((*info == 0) && (!(b_A[143] != 0.0))) {
    *info = 12;
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_mrdiv_c(const real_T b_A[144], const real_T b_B
  [144], real_T Y[144])
{
  memcpy(&proc_control_node_B.c_A_p[0], &b_B[0], 144U * sizeof(real_T));
  proc_control_node_xgetrf(proc_control_node_B.c_A_p, proc_control_node_B.ipiv,
    &proc_control_node_B.info);
  memcpy(&Y[0], &b_A[0], 144U * sizeof(real_T));
  for (proc_control_node_B.info = 0; proc_control_node_B.info < 12;
       proc_control_node_B.info++) {
    proc_control_node_B.jBcol_h = 12 * proc_control_node_B.info;
    proc_control_node_B.k_j = 0;
    while (proc_control_node_B.k_j <= proc_control_node_B.info - 1) {
      proc_control_node_B.kBcol_k = 12 * proc_control_node_B.k_j;
      proc_control_node_B.b_temp =
        proc_control_node_B.c_A_p[proc_control_node_B.k_j +
        proc_control_node_B.jBcol_h];
      if (proc_control_node_B.b_temp != 0.0) {
        for (proc_control_node_B.b_i_o = 0; proc_control_node_B.b_i_o < 12;
             proc_control_node_B.b_i_o++) {
          proc_control_node_B.Y_tmp = proc_control_node_B.b_i_o +
            proc_control_node_B.jBcol_h;
          Y[proc_control_node_B.Y_tmp] -= proc_control_node_B.b_temp *
            Y[proc_control_node_B.b_i_o + proc_control_node_B.kBcol_k];
        }
      }

      proc_control_node_B.k_j++;
    }

    proc_control_node_B.b_temp = 1.0 /
      proc_control_node_B.c_A_p[proc_control_node_B.info +
      proc_control_node_B.jBcol_h];
    for (proc_control_node_B.jAcol = 0; proc_control_node_B.jAcol < 12;
         proc_control_node_B.jAcol++) {
      proc_control_node_B.Y_tmp = proc_control_node_B.jAcol +
        proc_control_node_B.jBcol_h;
      Y[proc_control_node_B.Y_tmp] *= proc_control_node_B.b_temp;
    }
  }

  for (proc_control_node_B.info = 11; proc_control_node_B.info >= 0;
       proc_control_node_B.info--) {
    proc_control_node_B.jBcol_h = 12 * proc_control_node_B.info;
    proc_control_node_B.jAcol = 12 * proc_control_node_B.info - 1;
    proc_control_node_B.k_j = proc_control_node_B.info + 2;
    while (proc_control_node_B.k_j < 13) {
      proc_control_node_B.kBcol_k = (proc_control_node_B.k_j - 1) * 12;
      proc_control_node_B.b_temp =
        proc_control_node_B.c_A_p[proc_control_node_B.k_j +
        proc_control_node_B.jAcol];
      if (proc_control_node_B.b_temp != 0.0) {
        for (proc_control_node_B.b_i_o = 0; proc_control_node_B.b_i_o < 12;
             proc_control_node_B.b_i_o++) {
          proc_control_node_B.Y_tmp = proc_control_node_B.b_i_o +
            proc_control_node_B.jBcol_h;
          Y[proc_control_node_B.Y_tmp] -= proc_control_node_B.b_temp *
            Y[proc_control_node_B.b_i_o + proc_control_node_B.kBcol_k];
        }
      }

      proc_control_node_B.k_j++;
    }
  }

  for (proc_control_node_B.info = 10; proc_control_node_B.info >= 0;
       proc_control_node_B.info--) {
    proc_control_node_B.k_j = proc_control_node_B.ipiv[proc_control_node_B.info];
    if (proc_control_node_B.info + 1 != proc_control_node_B.k_j) {
      for (proc_control_node_B.jAcol = 0; proc_control_node_B.jAcol < 12;
           proc_control_node_B.jAcol++) {
        proc_control_node_B.kBcol_k = 12 * proc_control_node_B.info +
          proc_control_node_B.jAcol;
        proc_control_node_B.b_temp = Y[proc_control_node_B.kBcol_k];
        proc_control_node_B.Y_tmp = (proc_control_node_B.k_j - 1) * 12 +
          proc_control_node_B.jAcol;
        Y[proc_control_node_B.kBcol_k] = Y[proc_control_node_B.Y_tmp];
        Y[proc_control_node_B.Y_tmp] = proc_control_node_B.b_temp;
      }
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_mpc_constraintcoef(const real_T b_A[400], const real_T
  Bu[160], const real_T Bv[20], const real_T b_C[240], const real_T Dv[12],
  const real_T b_Jm[2560], real_T b_SuJm[3840], real_T b_Sx[2400], real_T b_Su1
  [960], real_T b_Hv[1320])
{
  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 20;
       proc_control_node_B.i8++) {
    memset(&proc_control_node_B.CA[proc_control_node_B.i8 * 12], 0, 12U * sizeof
           (real_T));
    for (proc_control_node_B.i9 = 0; proc_control_node_B.i9 < 20;
         proc_control_node_B.i9++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.CA_tmp = 12 * proc_control_node_B.i8 +
          proc_control_node_B.i7;
        proc_control_node_B.CA[proc_control_node_B.CA_tmp] += b_C[12 *
          proc_control_node_B.i9 + proc_control_node_B.i7] * b_A[20 *
          proc_control_node_B.i8 + proc_control_node_B.i9];
      }
    }
  }

  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 8;
       proc_control_node_B.i8++) {
    memset(&proc_control_node_B.Sum_g[proc_control_node_B.i8 * 12], 0, 12U *
           sizeof(real_T));
    for (proc_control_node_B.i9 = 0; proc_control_node_B.i9 < 20;
         proc_control_node_B.i9++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.CA_tmp = 12 * proc_control_node_B.i8 +
          proc_control_node_B.i7;
        proc_control_node_B.Sum_g[proc_control_node_B.CA_tmp] += b_C[12 *
          proc_control_node_B.i9 + proc_control_node_B.i7] * Bu[20 *
          proc_control_node_B.i8 + proc_control_node_B.i9];
      }
    }
  }

  memset(&proc_control_node_B.b_C_j[0], 0, 12U * sizeof(real_T));
  proc_control_node_B.i7 = 0;
  for (proc_control_node_B.i9 = 0; proc_control_node_B.i9 < 20;
       proc_control_node_B.i9++) {
    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 12;
         proc_control_node_B.i8++) {
      proc_control_node_B.b_C_j[proc_control_node_B.i8] +=
        b_C[proc_control_node_B.i8 + proc_control_node_B.i7] *
        Bv[proc_control_node_B.i9];
    }

    proc_control_node_B.i7 += 12;
  }

  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 12;
       proc_control_node_B.i8++) {
    b_Hv[proc_control_node_B.i8] =
      proc_control_node_B.b_C_j[proc_control_node_B.i8];
    b_Hv[proc_control_node_B.i8 + 120] = Dv[proc_control_node_B.i8];
  }

  proc_control_node_B.i8 = 0;
  for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 9;
       proc_control_node_B.i7++) {
    memset(&b_Hv[proc_control_node_B.i8 + 240], 0, 12U * sizeof(real_T));
    proc_control_node_B.i8 += 120;
  }

  proc_control_node_B.i8 = 0;
  for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 11;
       proc_control_node_B.i7++) {
    memset(&b_Hv[proc_control_node_B.i8 + 12], 0, 108U * sizeof(real_T));
    proc_control_node_B.i8 += 120;
  }

  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 20;
       proc_control_node_B.i8++) {
    memcpy(&b_Sx[proc_control_node_B.i8 * 120],
           &proc_control_node_B.CA[proc_control_node_B.i8 * 12], 12U * sizeof
           (real_T));
    memset(&b_Sx[proc_control_node_B.i8 * 120 + 12], 0, 108U * sizeof(real_T));
  }

  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 8;
       proc_control_node_B.i8++) {
    memcpy(&b_Su1[proc_control_node_B.i8 * 120],
           &proc_control_node_B.Sum_g[proc_control_node_B.i8 * 12], 12U * sizeof
           (real_T));
    memset(&b_Su1[proc_control_node_B.i8 * 120 + 12], 0, 108U * sizeof(real_T));
    memcpy(&proc_control_node_B.Su[proc_control_node_B.i8 * 120],
           &proc_control_node_B.Sum_g[proc_control_node_B.i8 * 12], 12U * sizeof
           (real_T));
  }

  proc_control_node_B.i8 = 0;
  for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 72;
       proc_control_node_B.i7++) {
    memset(&proc_control_node_B.Su[proc_control_node_B.i8 + 960], 0, 12U *
           sizeof(real_T));
    proc_control_node_B.i8 += 120;
  }

  proc_control_node_B.i8 = 0;
  for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 80;
       proc_control_node_B.i7++) {
    memset(&proc_control_node_B.Su[proc_control_node_B.i8 + 12], 0, 108U *
           sizeof(real_T));
    proc_control_node_B.i8 += 120;
  }

  for (proc_control_node_B.i_d = 0; proc_control_node_B.i_d < 9;
       proc_control_node_B.i_d++) {
    proc_control_node_B.i_jc = static_cast<int8_T>((proc_control_node_B.i_d + 1)
      * 12 + 1);
    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 12;
         proc_control_node_B.i8++) {
      proc_control_node_B.rows[proc_control_node_B.i8] = static_cast<int8_T>
        (proc_control_node_B.i8 + proc_control_node_B.i_jc);
      proc_control_node_B.i7 = 0;
      proc_control_node_B.i9 = 0;
      for (proc_control_node_B.i10 = 0; proc_control_node_B.i10 < 8;
           proc_control_node_B.i10++) {
        proc_control_node_B.Sum_ft = 0.0;
        proc_control_node_B.i12 = 0;
        for (proc_control_node_B.i11 = 0; proc_control_node_B.i11 < 20;
             proc_control_node_B.i11++) {
          proc_control_node_B.Sum_ft +=
            proc_control_node_B.CA[proc_control_node_B.i12 +
            proc_control_node_B.i8] * Bu[proc_control_node_B.i11 +
            proc_control_node_B.i9];
          proc_control_node_B.i12 += 12;
        }

        proc_control_node_B.CA_tmp = proc_control_node_B.i7 +
          proc_control_node_B.i8;
        proc_control_node_B.Sum_g[proc_control_node_B.CA_tmp] +=
          proc_control_node_B.Sum_ft;
        proc_control_node_B.i7 += 12;
        proc_control_node_B.i9 += 20;
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 8;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.CA_tmp = 12 * proc_control_node_B.i8 +
          proc_control_node_B.i7;
        proc_control_node_B.Sum_ft =
          proc_control_node_B.Sum_g[proc_control_node_B.CA_tmp];
        b_Su1[(proc_control_node_B.rows[proc_control_node_B.i7] + 120 *
               proc_control_node_B.i8) - 1] = proc_control_node_B.Sum_ft;
        proc_control_node_B.Sum_cl[proc_control_node_B.CA_tmp] =
          proc_control_node_B.Sum_ft;
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 72;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.Sum_cl[proc_control_node_B.i7 + 12 *
          (proc_control_node_B.i8 + 8)] = proc_control_node_B.Su[(120 *
          proc_control_node_B.i8 +
          proc_control_node_B.rows[proc_control_node_B.i7]) - 13];
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 80;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.Su[(proc_control_node_B.rows[proc_control_node_B.i7]
          + 120 * proc_control_node_B.i8) - 1] = proc_control_node_B.Sum_cl[12 *
          proc_control_node_B.i8 + proc_control_node_B.i7];
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 12;
         proc_control_node_B.i8++) {
      proc_control_node_B.b_C_j[proc_control_node_B.i8] = 0.0;
      proc_control_node_B.i7 = 0;
      for (proc_control_node_B.i9 = 0; proc_control_node_B.i9 < 20;
           proc_control_node_B.i9++) {
        proc_control_node_B.b_C_j[proc_control_node_B.i8] +=
          proc_control_node_B.CA[proc_control_node_B.i7 + proc_control_node_B.i8]
          * Bv[proc_control_node_B.i9];
        proc_control_node_B.i7 += 12;
      }

      proc_control_node_B.CA_j[proc_control_node_B.i8] =
        proc_control_node_B.b_C_j[proc_control_node_B.i8];
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 10;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        proc_control_node_B.CA_j[proc_control_node_B.i7 + 12 *
          (proc_control_node_B.i8 + 1)] = b_Hv[(120 * proc_control_node_B.i8 +
          proc_control_node_B.rows[proc_control_node_B.i7]) - 13];
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 11;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        b_Hv[(proc_control_node_B.rows[proc_control_node_B.i7] + 120 *
              proc_control_node_B.i8) - 1] = proc_control_node_B.CA_j[12 *
          proc_control_node_B.i8 + proc_control_node_B.i7];
      }
    }

    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 12;
         proc_control_node_B.i8++) {
      proc_control_node_B.i7 = 0;
      proc_control_node_B.i9 = 0;
      for (proc_control_node_B.i10 = 0; proc_control_node_B.i10 < 20;
           proc_control_node_B.i10++) {
        proc_control_node_B.CA_tmp = proc_control_node_B.i7 +
          proc_control_node_B.i8;
        proc_control_node_B.CA_m[proc_control_node_B.CA_tmp] = 0.0;
        proc_control_node_B.i12 = 0;
        for (proc_control_node_B.i11 = 0; proc_control_node_B.i11 < 20;
             proc_control_node_B.i11++) {
          proc_control_node_B.CA_m[proc_control_node_B.CA_tmp] +=
            proc_control_node_B.CA[proc_control_node_B.i12 +
            proc_control_node_B.i8] * b_A[proc_control_node_B.i11 +
            proc_control_node_B.i9];
          proc_control_node_B.i12 += 12;
        }

        proc_control_node_B.i7 += 12;
        proc_control_node_B.i9 += 20;
      }
    }

    memcpy(&proc_control_node_B.CA[0], &proc_control_node_B.CA_m[0], 240U *
           sizeof(real_T));
    for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 20;
         proc_control_node_B.i8++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 12;
           proc_control_node_B.i7++) {
        b_Sx[(proc_control_node_B.rows[proc_control_node_B.i7] + 120 *
              proc_control_node_B.i8) - 1] = proc_control_node_B.CA[12 *
          proc_control_node_B.i8 + proc_control_node_B.i7];
      }
    }
  }

  for (proc_control_node_B.i8 = 0; proc_control_node_B.i8 < 32;
       proc_control_node_B.i8++) {
    memset(&b_SuJm[proc_control_node_B.i8 * 120], 0, 120U * sizeof(real_T));
    for (proc_control_node_B.i9 = 0; proc_control_node_B.i9 < 80;
         proc_control_node_B.i9++) {
      for (proc_control_node_B.i7 = 0; proc_control_node_B.i7 < 120;
           proc_control_node_B.i7++) {
        proc_control_node_B.i_d = 120 * proc_control_node_B.i8 +
          proc_control_node_B.i7;
        b_SuJm[proc_control_node_B.i_d] += proc_control_node_B.Su[120 *
          proc_control_node_B.i9 + proc_control_node_B.i7] * b_Jm[80 *
          proc_control_node_B.i8 + proc_control_node_B.i9];
      }
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_WtMult(const real_T W[8], const real_T M[2560],
  real_T nwt, real_T WM[2560])
{
  proc_control_node_B.ixw_o = 1;
  for (proc_control_node_B.i_h = 0; proc_control_node_B.i_h < 80;
       proc_control_node_B.i_h++) {
    proc_control_node_B.W = W[proc_control_node_B.ixw_o - 1];
    for (proc_control_node_B.i20 = 0; proc_control_node_B.i20 < 32;
         proc_control_node_B.i20++) {
      proc_control_node_B.WM_tmp = 80 * proc_control_node_B.i20 +
        proc_control_node_B.i_h;
      WM[proc_control_node_B.WM_tmp] = M[proc_control_node_B.WM_tmp] *
        proc_control_node_B.W;
    }

    proc_control_node_B.i20 = proc_control_node_B.ixw_o + 1;
    if (proc_control_node_B.ixw_o + 1 > 32767) {
      proc_control_node_B.i20 = 32767;
    }

    proc_control_node_B.ixw_o = static_cast<int16_T>(proc_control_node_B.i20);
    if (static_cast<int16_T>(proc_control_node_B.i20) > 8) {
      proc_control_node_B.W = rt_roundd_snf(8.0 - nwt);
      if (proc_control_node_B.W < 32768.0) {
        if (proc_control_node_B.W >= -32768.0) {
          proc_control_node_B.ixw_o = static_cast<int16_T>(proc_control_node_B.W);
        } else {
          proc_control_node_B.ixw_o = MIN_int16_T;
        }
      } else {
        proc_control_node_B.ixw_o = MAX_int16_T;
      }

      proc_control_node_B.i20 = proc_control_node_B.ixw_o + 1;
      if (proc_control_node_B.W < 32768.0) {
        if (proc_control_node_B.W >= -32768.0) {
          proc_control_node_B.ixw_o = static_cast<int16_T>(proc_control_node_B.W);
        } else {
          proc_control_node_B.ixw_o = MIN_int16_T;
        }
      } else {
        proc_control_node_B.ixw_o = MAX_int16_T;
      }

      if (proc_control_node_B.ixw_o + 1 > 32767) {
        proc_control_node_B.i20 = 32767;
      }

      proc_control_node_B.ixw_o = static_cast<int16_T>(proc_control_node_B.i20);
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_contr_mpc_calculatehessian(const real_T b_Wy[12], const real_T
  b_Wu[8], const real_T b_Wdu[8], const real_T b_SuJm[3840], const real_T I2Jm
  [2560], const real_T b_Jm[2560], const real_T b_I1[640], const real_T b_Su1
  [960], const real_T b_Sx[2400], const real_T b_Hv[1320], real_T nmv, real_T
  b_ny, real_T b_H[1024], real_T b_Ku1[256], real_T b_Kut[2560], real_T b_Kx[640],
  real_T b_Kv[352], real_T b_Kr[3840])
{
  proc_control_node_B.ixw = 1;
  for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 120;
       proc_control_node_B.i_js++) {
    proc_control_node_B.b_Wy = b_Wy[proc_control_node_B.ixw - 1];
    for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 32;
         proc_control_node_B.i19++) {
      proc_control_node_B.b_Kr_tmp = 120 * proc_control_node_B.i19 +
        proc_control_node_B.i_js;
      b_Kr[proc_control_node_B.b_Kr_tmp] = b_SuJm[proc_control_node_B.b_Kr_tmp] *
        proc_control_node_B.b_Wy;
    }

    proc_control_node_B.i19 = proc_control_node_B.ixw + 1;
    if (proc_control_node_B.ixw + 1 > 32767) {
      proc_control_node_B.i19 = 32767;
    }

    proc_control_node_B.ixw = static_cast<int16_T>(proc_control_node_B.i19);
    if (static_cast<int16_T>(proc_control_node_B.i19) > 12) {
      proc_control_node_B.b_Wy = rt_roundd_snf(12.0 - b_ny);
      if (proc_control_node_B.b_Wy < 32768.0) {
        if (proc_control_node_B.b_Wy >= -32768.0) {
          proc_control_node_B.ixw = static_cast<int16_T>
            (proc_control_node_B.b_Wy);
        } else {
          proc_control_node_B.ixw = MIN_int16_T;
        }
      } else {
        proc_control_node_B.ixw = MAX_int16_T;
      }

      proc_control_node_B.i19 = proc_control_node_B.ixw + 1;
      if (proc_control_node_B.b_Wy < 32768.0) {
        if (proc_control_node_B.b_Wy >= -32768.0) {
          proc_control_node_B.ixw = static_cast<int16_T>
            (proc_control_node_B.b_Wy);
        } else {
          proc_control_node_B.ixw = MIN_int16_T;
        }
      } else {
        proc_control_node_B.ixw = MAX_int16_T;
      }

      if (proc_control_node_B.ixw + 1 > 32767) {
        proc_control_node_B.i19 = 32767;
      }

      proc_control_node_B.ixw = static_cast<int16_T>(proc_control_node_B.i19);
    }
  }

  proc_control_node_WtMult(b_Wu, I2Jm, nmv, b_Kut);
  proc_control_node_WtMult(b_Wdu, b_Jm, nmv, proc_control_node_B.dv);
  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 32;
       proc_control_node_B.i19++) {
    for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 32;
         proc_control_node_B.i_js++) {
      proc_control_node_B.b_SuJm_tmp = proc_control_node_B.i_js +
        (proc_control_node_B.i19 << 5);
      proc_control_node_B.b_SuJm_m[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 120;
           proc_control_node_B.b_Kr_tmp++) {
        proc_control_node_B.b_SuJm_m[proc_control_node_B.b_SuJm_tmp] += b_SuJm
          [120 * proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] *
          b_Kr[120 * proc_control_node_B.i19 + proc_control_node_B.b_Kr_tmp];
      }

      proc_control_node_B.b_Jm[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 80;
           proc_control_node_B.b_Kr_tmp++) {
        proc_control_node_B.b_Jm[proc_control_node_B.b_SuJm_tmp] += b_Jm[80 *
          proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] *
          proc_control_node_B.dv[80 * proc_control_node_B.i19 +
          proc_control_node_B.b_Kr_tmp];
      }
    }
  }

  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 32;
       proc_control_node_B.i19++) {
    for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 32;
         proc_control_node_B.i_js++) {
      proc_control_node_B.b_Wy = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 80;
           proc_control_node_B.b_Kr_tmp++) {
        proc_control_node_B.b_Wy += I2Jm[80 * proc_control_node_B.i19 +
          proc_control_node_B.b_Kr_tmp] * b_Kut[80 * proc_control_node_B.i_js +
          proc_control_node_B.b_Kr_tmp];
      }

      proc_control_node_B.b_Kr_tmp = (proc_control_node_B.i_js << 5) +
        proc_control_node_B.i19;
      b_H[proc_control_node_B.b_Kr_tmp] =
        (proc_control_node_B.b_SuJm_m[proc_control_node_B.b_Kr_tmp] +
         proc_control_node_B.b_Jm[proc_control_node_B.b_Kr_tmp]) +
        proc_control_node_B.b_Wy;
    }

    for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 8;
         proc_control_node_B.i_js++) {
      proc_control_node_B.b_SuJm_tmp = proc_control_node_B.i_js +
        (proc_control_node_B.i19 << 3);
      proc_control_node_B.b_Su1_g[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 120;
           proc_control_node_B.b_Kr_tmp++) {
        proc_control_node_B.b_Su1_g[proc_control_node_B.b_SuJm_tmp] += b_Su1[120
          * proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] * b_Kr[120 *
          proc_control_node_B.i19 + proc_control_node_B.b_Kr_tmp];
      }

      proc_control_node_B.b_I1[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 80;
           proc_control_node_B.b_Kr_tmp++) {
        proc_control_node_B.b_I1[proc_control_node_B.b_SuJm_tmp] += b_I1[80 *
          proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] * b_Kut[80 *
          proc_control_node_B.i19 + proc_control_node_B.b_Kr_tmp];
      }
    }
  }

  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 256;
       proc_control_node_B.i19++) {
    b_Ku1[proc_control_node_B.i19] =
      proc_control_node_B.b_Su1_g[proc_control_node_B.i19] +
      proc_control_node_B.b_I1[proc_control_node_B.i19];
  }

  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 2560;
       proc_control_node_B.i19++) {
    b_Kut[proc_control_node_B.i19] = -b_Kut[proc_control_node_B.i19];
  }

  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 32;
       proc_control_node_B.i19++) {
    for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 20;
         proc_control_node_B.i_js++) {
      proc_control_node_B.b_SuJm_tmp = proc_control_node_B.i_js + 20 *
        proc_control_node_B.i19;
      b_Kx[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 120;
           proc_control_node_B.b_Kr_tmp++) {
        b_Kx[proc_control_node_B.b_SuJm_tmp] += b_Sx[120 *
          proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] * b_Kr[120 *
          proc_control_node_B.i19 + proc_control_node_B.b_Kr_tmp];
      }
    }

    for (proc_control_node_B.i_js = 0; proc_control_node_B.i_js < 11;
         proc_control_node_B.i_js++) {
      proc_control_node_B.b_SuJm_tmp = proc_control_node_B.i_js + 11 *
        proc_control_node_B.i19;
      b_Kv[proc_control_node_B.b_SuJm_tmp] = 0.0;
      for (proc_control_node_B.b_Kr_tmp = 0; proc_control_node_B.b_Kr_tmp < 120;
           proc_control_node_B.b_Kr_tmp++) {
        b_Kv[proc_control_node_B.b_SuJm_tmp] += b_Hv[120 *
          proc_control_node_B.i_js + proc_control_node_B.b_Kr_tmp] * b_Kr[120 *
          proc_control_node_B.i19 + proc_control_node_B.b_Kr_tmp];
      }
    }
  }

  for (proc_control_node_B.i19 = 0; proc_control_node_B.i19 < 3840;
       proc_control_node_B.i19++) {
    b_Kr[proc_control_node_B.i19] = -b_Kr[proc_control_node_B.i19];
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static int32_T proc_control_node_xpotrf(real_T b_A[1089])
{
  int32_T info;
  boolean_T exitg1;
  info = 0;
  proc_control_node_B.j_j = 0;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.j_j < 33)) {
    proc_control_node_B.idxAjj = proc_control_node_B.j_j * 33 +
      proc_control_node_B.j_j;
    proc_control_node_B.ssq = 0.0;
    if (proc_control_node_B.j_j >= 1) {
      proc_control_node_B.b_ix = proc_control_node_B.j_j;
      proc_control_node_B.b_iy = proc_control_node_B.j_j;
      proc_control_node_B.b_k_e = 0;
      while (proc_control_node_B.b_k_e <= proc_control_node_B.j_j - 1) {
        proc_control_node_B.ssq += b_A[proc_control_node_B.b_ix] *
          b_A[proc_control_node_B.b_iy];
        proc_control_node_B.b_ix += 33;
        proc_control_node_B.b_iy += 33;
        proc_control_node_B.b_k_e++;
      }
    }

    proc_control_node_B.ssq = b_A[proc_control_node_B.idxAjj] -
      proc_control_node_B.ssq;
    if (proc_control_node_B.ssq > 0.0) {
      proc_control_node_B.ssq = sqrt(proc_control_node_B.ssq);
      b_A[proc_control_node_B.idxAjj] = proc_control_node_B.ssq;
      if (proc_control_node_B.j_j + 1 < 33) {
        if (proc_control_node_B.j_j != 0) {
          proc_control_node_B.b_ix = proc_control_node_B.j_j;
          proc_control_node_B.b_iy = ((proc_control_node_B.j_j - 1) * 33 +
            proc_control_node_B.j_j) + 2;
          proc_control_node_B.b_k_e = proc_control_node_B.j_j + 2;
          while (proc_control_node_B.b_k_e <= proc_control_node_B.b_iy) {
            proc_control_node_B.c_b = -b_A[proc_control_node_B.b_ix];
            proc_control_node_B.iy_k = proc_control_node_B.idxAjj + 1;
            proc_control_node_B.d_b = (proc_control_node_B.b_k_e -
              proc_control_node_B.j_j) + 31;
            proc_control_node_B.ia_h = proc_control_node_B.b_k_e;
            while (proc_control_node_B.ia_h <= proc_control_node_B.d_b) {
              b_A[proc_control_node_B.iy_k] += b_A[proc_control_node_B.ia_h - 1]
                * proc_control_node_B.c_b;
              proc_control_node_B.iy_k++;
              proc_control_node_B.ia_h++;
            }

            proc_control_node_B.b_ix += 33;
            proc_control_node_B.b_k_e += 33;
          }
        }

        proc_control_node_B.ssq = 1.0 / proc_control_node_B.ssq;
        proc_control_node_B.b_ix = (proc_control_node_B.idxAjj -
          proc_control_node_B.j_j) + 33;
        proc_control_node_B.idxAjj++;
        while (proc_control_node_B.idxAjj + 1 <= proc_control_node_B.b_ix) {
          b_A[proc_control_node_B.idxAjj] *= proc_control_node_B.ssq;
          proc_control_node_B.idxAjj++;
        }
      }

      proc_control_node_B.j_j++;
    } else {
      b_A[proc_control_node_B.idxAjj] = proc_control_node_B.ssq;
      info = proc_control_node_B.j_j + 1;
      exitg1 = true;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_minimum(const real_T x[33])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 34)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 33) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_n_mpc_checkhessian(real_T b_H[1089], real_T L[1089],
  real_T *BadH)
{
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *BadH = 0.0;
  memcpy(&L[0], &b_H[0], 1089U * sizeof(real_T));
  proc_control_node_B.Tries = proc_control_node_xpotrf(L);
  guard1 = false;
  if (proc_control_node_B.Tries == 0) {
    proc_control_node_B.Tries_f = 0;
    for (proc_control_node_B.Tries = 0; proc_control_node_B.Tries < 33;
         proc_control_node_B.Tries++) {
      proc_control_node_B.varargin_1[proc_control_node_B.Tries] =
        L[proc_control_node_B.Tries_f];
      proc_control_node_B.Tries_f += 34;
    }

    if (proc_control_node_minimum(proc_control_node_B.varargin_1) >
        1.4901161193847656E-7) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    proc_control_node_B.normH = 0.0;
    proc_control_node_B.Tries = 0;
    exitg2 = false;
    while ((!exitg2) && (proc_control_node_B.Tries < 33)) {
      proc_control_node_B.s_p = 0.0;
      for (proc_control_node_B.Tries_f = 0; proc_control_node_B.Tries_f < 33;
           proc_control_node_B.Tries_f++) {
        proc_control_node_B.s_p += fabs(b_H[33 * proc_control_node_B.Tries_f +
          proc_control_node_B.Tries]);
      }

      if (rtIsNaN(proc_control_node_B.s_p)) {
        proc_control_node_B.normH = (rtNaN);
        exitg2 = true;
      } else {
        if (proc_control_node_B.s_p > proc_control_node_B.normH) {
          proc_control_node_B.normH = proc_control_node_B.s_p;
        }

        proc_control_node_B.Tries++;
      }
    }

    if (proc_control_node_B.normH >= 1.0E+10) {
      *BadH = 2.0;
    } else {
      proc_control_node_B.Tries = 0;
      exitg1 = false;
      while ((!exitg1) && (proc_control_node_B.Tries <= 4)) {
        proc_control_node_B.normH = proc_control_node_rt_powd_snf(10.0,
          static_cast<real_T>(proc_control_node_B.Tries)) *
          1.4901161193847656E-7;
        memset(&proc_control_node_B.b_l[0], 0, 1089U * sizeof(int8_T));
        proc_control_node_B.j_a = 0;
        for (proc_control_node_B.Tries_f = 0; proc_control_node_B.Tries_f < 33;
             proc_control_node_B.Tries_f++) {
          proc_control_node_B.b_l[proc_control_node_B.j_a] = 1;
          proc_control_node_B.j_a += 34;
        }

        for (proc_control_node_B.Tries_f = 0; proc_control_node_B.Tries_f < 1089;
             proc_control_node_B.Tries_f++) {
          b_H[proc_control_node_B.Tries_f] += proc_control_node_B.normH *
            static_cast<real_T>
            (proc_control_node_B.b_l[proc_control_node_B.Tries_f]);
          L[proc_control_node_B.Tries_f] = b_H[proc_control_node_B.Tries_f];
        }

        proc_control_node_B.Tries_f = proc_control_node_xpotrf(L);
        guard2 = false;
        if (proc_control_node_B.Tries_f == 0) {
          proc_control_node_B.j_a = 0;
          for (proc_control_node_B.Tries_f = 0; proc_control_node_B.Tries_f < 33;
               proc_control_node_B.Tries_f++) {
            proc_control_node_B.varargin_1[proc_control_node_B.Tries_f] =
              L[proc_control_node_B.j_a];
            proc_control_node_B.j_a += 34;
          }

          if (proc_control_node_minimum(proc_control_node_B.varargin_1) >
              1.4901161193847656E-7) {
            *BadH = 1.0;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          *BadH = 3.0;
          proc_control_node_B.Tries++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_trisolve(const real_T b_A[1089], real_T b_B[1089])
{
  for (proc_control_node_B.j_m = 0; proc_control_node_B.j_m < 33;
       proc_control_node_B.j_m++) {
    proc_control_node_B.jBcol_d = 33 * proc_control_node_B.j_m;
    for (proc_control_node_B.k_f = 0; proc_control_node_B.k_f < 33;
         proc_control_node_B.k_f++) {
      proc_control_node_B.kAcol = 33 * proc_control_node_B.k_f;
      proc_control_node_B.i31 = proc_control_node_B.k_f +
        proc_control_node_B.jBcol_d;
      proc_control_node_B.d5 = b_B[proc_control_node_B.i31];
      if (proc_control_node_B.d5 != 0.0) {
        b_B[proc_control_node_B.i31] = proc_control_node_B.d5 /
          b_A[proc_control_node_B.k_f + proc_control_node_B.kAcol];
        proc_control_node_B.i_gd = proc_control_node_B.k_f + 2;
        while (proc_control_node_B.i_gd < 34) {
          proc_control_node_B.i32 = (proc_control_node_B.i_gd +
            proc_control_node_B.jBcol_d) - 1;
          b_B[proc_control_node_B.i32] -= b_A[(proc_control_node_B.i_gd +
            proc_control_node_B.kAcol) - 1] * b_B[proc_control_node_B.i31];
          proc_control_node_B.i_gd++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_Unconstrained(const real_T b_Hinv[1089], const
  real_T f[33], real_T x[33], int16_T n)
{
  real_T b_Hinv_0;
  int32_T i;
  int32_T i_0;
  for (i = 1; i - 1 < n; i++) {
    b_Hinv_0 = 0.0;
    for (i_0 = 0; i_0 < 33; i_0++) {
      b_Hinv_0 += -b_Hinv[(33 * i_0 + static_cast<int16_T>(i)) - 1] * f[i_0];
    }

    x[static_cast<int16_T>(i) - 1] = b_Hinv_0;
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_norm(const real_T x[33])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 33; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_abs(const real_T x[33], real_T y[33])
{
  int32_T k;
  for (k = 0; k < 33; k++) {
    y[k] = fabs(x[k]);
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_maximum(const real_T x[33])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 34)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 33) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_abs_i(const real_T x[64], real_T y[64])
{
  int32_T k;
  for (k = 0; k < 64; k++) {
    y[k] = fabs(x[k]);
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_maximum2(const real_T x[64], real_T y, real_T ex
  [64])
{
  real_T u0;
  int32_T k;
  for (k = 0; k < 64; k++) {
    u0 = x[k];
    if ((u0 > y) || rtIsNaN(y)) {
      ex[k] = u0;
    } else {
      ex[k] = y;
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_xnrm2(int32_T n, const real_T x[1089], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xgemv(int32_T b_m, int32_T n, const real_T b_A
  [1089], int32_T ia0, const real_T x[1089], int32_T ix0, real_T y[33])
{
  if ((b_m != 0) && (n != 0)) {
    proc_control_node_B.b_iy_h = 0;
    while (proc_control_node_B.b_iy_h <= n - 1) {
      y[proc_control_node_B.b_iy_h] = 0.0;
      proc_control_node_B.b_iy_h++;
    }

    proc_control_node_B.b_iy_h = 0;
    proc_control_node_B.b_f = (n - 1) * 33 + ia0;
    proc_control_node_B.iac = ia0;
    while (proc_control_node_B.iac <= proc_control_node_B.b_f) {
      proc_control_node_B.ix_j = ix0;
      proc_control_node_B.c_a = 0.0;
      proc_control_node_B.d_d = (proc_control_node_B.iac + b_m) - 1;
      proc_control_node_B.ia_l = proc_control_node_B.iac;
      while (proc_control_node_B.ia_l <= proc_control_node_B.d_d) {
        proc_control_node_B.c_a += b_A[proc_control_node_B.ia_l - 1] *
          x[proc_control_node_B.ix_j - 1];
        proc_control_node_B.ix_j++;
        proc_control_node_B.ia_l++;
      }

      y[proc_control_node_B.b_iy_h] += proc_control_node_B.c_a;
      proc_control_node_B.b_iy_h++;
      proc_control_node_B.iac += 33;
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xgerc(int32_T b_m, int32_T n, real_T alpha1,
  int32_T ix0, const real_T y[33], real_T b_A[1089], int32_T ia0)
{
  if (!(alpha1 == 0.0)) {
    proc_control_node_B.jA_g = ia0 - 1;
    proc_control_node_B.jy = 0;
    proc_control_node_B.j_d = 0;
    while (proc_control_node_B.j_d <= n - 1) {
      if (y[proc_control_node_B.jy] != 0.0) {
        proc_control_node_B.temp = y[proc_control_node_B.jy] * alpha1;
        proc_control_node_B.ix_d = ix0;
        proc_control_node_B.b_jo = b_m + proc_control_node_B.jA_g;
        proc_control_node_B.ijA_f = proc_control_node_B.jA_g;
        while (proc_control_node_B.ijA_f + 1 <= proc_control_node_B.b_jo) {
          b_A[proc_control_node_B.ijA_f] += b_A[proc_control_node_B.ix_d - 1] *
            proc_control_node_B.temp;
          proc_control_node_B.ix_d++;
          proc_control_node_B.ijA_f++;
        }
      }

      proc_control_node_B.jy++;
      proc_control_node_B.jA_g += 33;
      proc_control_node_B.j_d++;
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xzlarf(int32_T b_m, int32_T n, int32_T iv0, real_T
  tau, real_T b_C[1089], int32_T ic0, real_T work[33])
{
  int32_T exitg1;
  boolean_T exitg2;
  if (tau != 0.0) {
    proc_control_node_B.lastv = b_m;
    proc_control_node_B.lastc = iv0 + b_m;
    while ((proc_control_node_B.lastv > 0) && (b_C[proc_control_node_B.lastc - 2]
            == 0.0)) {
      proc_control_node_B.lastv--;
      proc_control_node_B.lastc--;
    }

    proc_control_node_B.lastc = n;
    exitg2 = false;
    while ((!exitg2) && (proc_control_node_B.lastc > 0)) {
      proc_control_node_B.coltop = (proc_control_node_B.lastc - 1) * 33 + ic0;
      proc_control_node_B.ia = proc_control_node_B.coltop;
      do {
        exitg1 = 0;
        if (proc_control_node_B.ia <= (proc_control_node_B.coltop +
             proc_control_node_B.lastv) - 1) {
          if (b_C[proc_control_node_B.ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            proc_control_node_B.ia++;
          }
        } else {
          proc_control_node_B.lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    proc_control_node_B.lastv = 0;
    proc_control_node_B.lastc = 0;
  }

  if (proc_control_node_B.lastv > 0) {
    proc_control_node_xgemv(proc_control_node_B.lastv, proc_control_node_B.lastc,
      b_C, ic0, b_C, iv0, work);
    proc_control_node_xgerc(proc_control_node_B.lastv, proc_control_node_B.lastc,
      -tau, iv0, work, b_C, ic0);
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_qrf(real_T b_A[1089], int32_T ia0, int32_T b_m,
  int32_T n, int32_T nfxd, real_T tau[33])
{
  memset(&proc_control_node_B.work[0], 0, 33U * sizeof(real_T));
  proc_control_node_B.i_lu = 0;
  while (proc_control_node_B.i_lu <= nfxd - 1) {
    proc_control_node_B.ii = ((proc_control_node_B.i_lu * 33 + ia0) +
      proc_control_node_B.i_lu) - 1;
    proc_control_node_B.mmi_tmp = b_m - proc_control_node_B.i_lu;
    if (proc_control_node_B.i_lu + 1 < b_m) {
      proc_control_node_B.b_atmp = b_A[proc_control_node_B.ii];
      tau[proc_control_node_B.i_lu] = 0.0;
      if (proc_control_node_B.mmi_tmp > 0) {
        proc_control_node_B.beta1 = proc_control_node_xnrm2
          (proc_control_node_B.mmi_tmp - 1, b_A, proc_control_node_B.ii + 2);
        if (proc_control_node_B.beta1 != 0.0) {
          proc_control_node_B.beta1 = rt_hypotd_snf(b_A[proc_control_node_B.ii],
            proc_control_node_B.beta1);
          if (b_A[proc_control_node_B.ii] >= 0.0) {
            proc_control_node_B.beta1 = -proc_control_node_B.beta1;
          }

          if (fabs(proc_control_node_B.beta1) < 1.0020841800044864E-292) {
            proc_control_node_B.knt = -1;
            proc_control_node_B.mmip1 = proc_control_node_B.ii +
              proc_control_node_B.mmi_tmp;
            do {
              proc_control_node_B.knt++;
              proc_control_node_B.b_k = proc_control_node_B.ii + 1;
              while (proc_control_node_B.b_k + 1 <= proc_control_node_B.mmip1) {
                b_A[proc_control_node_B.b_k] *= 9.9792015476736E+291;
                proc_control_node_B.b_k++;
              }

              proc_control_node_B.beta1 *= 9.9792015476736E+291;
              proc_control_node_B.b_atmp *= 9.9792015476736E+291;
            } while (!(fabs(proc_control_node_B.beta1) >=
                       1.0020841800044864E-292));

            proc_control_node_B.beta1 = rt_hypotd_snf(proc_control_node_B.b_atmp,
              proc_control_node_xnrm2(proc_control_node_B.mmi_tmp - 1, b_A,
              proc_control_node_B.ii + 2));
            if (proc_control_node_B.b_atmp >= 0.0) {
              proc_control_node_B.beta1 = -proc_control_node_B.beta1;
            }

            tau[proc_control_node_B.i_lu] = (proc_control_node_B.beta1 -
              proc_control_node_B.b_atmp) / proc_control_node_B.beta1;
            proc_control_node_B.b_atmp = 1.0 / (proc_control_node_B.b_atmp -
              proc_control_node_B.beta1);
            proc_control_node_B.b_k = proc_control_node_B.ii + 1;
            while (proc_control_node_B.b_k + 1 <= proc_control_node_B.mmip1) {
              b_A[proc_control_node_B.b_k] *= proc_control_node_B.b_atmp;
              proc_control_node_B.b_k++;
            }

            proc_control_node_B.mmip1 = 0;
            while (proc_control_node_B.mmip1 <= proc_control_node_B.knt) {
              proc_control_node_B.beta1 *= 1.0020841800044864E-292;
              proc_control_node_B.mmip1++;
            }

            proc_control_node_B.b_atmp = proc_control_node_B.beta1;
          } else {
            tau[proc_control_node_B.i_lu] = (proc_control_node_B.beta1 -
              b_A[proc_control_node_B.ii]) / proc_control_node_B.beta1;
            proc_control_node_B.b_atmp = 1.0 / (b_A[proc_control_node_B.ii] -
              proc_control_node_B.beta1);
            proc_control_node_B.knt = proc_control_node_B.ii +
              proc_control_node_B.mmi_tmp;
            proc_control_node_B.mmip1 = proc_control_node_B.ii + 1;
            while (proc_control_node_B.mmip1 + 1 <= proc_control_node_B.knt) {
              b_A[proc_control_node_B.mmip1] *= proc_control_node_B.b_atmp;
              proc_control_node_B.mmip1++;
            }

            proc_control_node_B.b_atmp = proc_control_node_B.beta1;
          }
        }
      }

      b_A[proc_control_node_B.ii] = proc_control_node_B.b_atmp;
    } else {
      tau[proc_control_node_B.i_lu] = 0.0;
    }

    if (proc_control_node_B.i_lu + 1 < n) {
      proc_control_node_B.b_atmp = b_A[proc_control_node_B.ii];
      b_A[proc_control_node_B.ii] = 1.0;
      proc_control_node_xzlarf(proc_control_node_B.mmi_tmp, (n -
        proc_control_node_B.i_lu) - 1, proc_control_node_B.ii + 1,
        tau[proc_control_node_B.i_lu], b_A, proc_control_node_B.ii + 34,
        proc_control_node_B.work);
      b_A[proc_control_node_B.ii] = proc_control_node_B.b_atmp;
    }

    proc_control_node_B.i_lu++;
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xgeqrf(real_T b_A[1089], real_T tau[33])
{
  memset(&tau[0], 0, 33U * sizeof(real_T));
  proc_control_node_qrf(b_A, 1, 33, 33, 33, tau);
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_xorgqr(int32_T b_m, int32_T n, int32_T k, real_T
  b_A[1089], int32_T ia0, const real_T tau[33], int32_T itau0)
{
  if (n >= 1) {
    proc_control_node_B.itau = k;
    while (proc_control_node_B.itau <= n - 1) {
      proc_control_node_B.i_k = (proc_control_node_B.itau * 33 + ia0) - 1;
      proc_control_node_B.iaii = 0;
      while (proc_control_node_B.iaii <= b_m - 1) {
        b_A[proc_control_node_B.i_k + proc_control_node_B.iaii] = 0.0;
        proc_control_node_B.iaii++;
      }

      b_A[proc_control_node_B.i_k + proc_control_node_B.itau] = 1.0;
      proc_control_node_B.itau++;
    }

    proc_control_node_B.itau = (itau0 + k) - 2;
    memset(&proc_control_node_B.work_b[0], 0, 33U * sizeof(real_T));
    proc_control_node_B.i_k = k;
    while (proc_control_node_B.i_k >= 1) {
      proc_control_node_B.iaii = (((proc_control_node_B.i_k - 1) * 33 + ia0) +
        proc_control_node_B.i_k) - 1;
      if (proc_control_node_B.i_k < n) {
        b_A[proc_control_node_B.iaii - 1] = 1.0;
        proc_control_node_xzlarf((b_m - proc_control_node_B.i_k) + 1, n -
          proc_control_node_B.i_k, proc_control_node_B.iaii,
          tau[proc_control_node_B.itau], b_A, proc_control_node_B.iaii + 33,
          proc_control_node_B.work_b);
      }

      if (proc_control_node_B.i_k < b_m) {
        proc_control_node_B.b_n = (proc_control_node_B.iaii + b_m) -
          proc_control_node_B.i_k;
        proc_control_node_B.b_k_m = proc_control_node_B.iaii;
        while (proc_control_node_B.b_k_m + 1 <= proc_control_node_B.b_n) {
          b_A[proc_control_node_B.b_k_m] *= -tau[proc_control_node_B.itau];
          proc_control_node_B.b_k_m++;
        }
      }

      b_A[proc_control_node_B.iaii - 1] = 1.0 - tau[proc_control_node_B.itau];
      proc_control_node_B.b_n = 0;
      while (proc_control_node_B.b_n <= proc_control_node_B.i_k - 2) {
        b_A[(proc_control_node_B.iaii - proc_control_node_B.b_n) - 2] = 0.0;
        proc_control_node_B.b_n++;
      }

      proc_control_node_B.itau--;
      proc_control_node_B.i_k--;
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_qr(const real_T b_A[1089], real_T Q[1089], real_T
  R[1089])
{
  memcpy(&proc_control_node_B.c_A[0], &b_A[0], 1089U * sizeof(real_T));
  proc_control_node_xgeqrf(proc_control_node_B.c_A, proc_control_node_B.tau);
  for (proc_control_node_B.j = 0; proc_control_node_B.j < 33;
       proc_control_node_B.j++) {
    proc_control_node_B.i_l = 0;
    while (proc_control_node_B.i_l <= proc_control_node_B.j) {
      R[proc_control_node_B.i_l + 33 * proc_control_node_B.j] =
        proc_control_node_B.c_A[33 * proc_control_node_B.j +
        proc_control_node_B.i_l];
      proc_control_node_B.i_l++;
    }

    proc_control_node_B.i_l = proc_control_node_B.j + 1;
    while (proc_control_node_B.i_l + 1 < 34) {
      R[proc_control_node_B.i_l + 33 * proc_control_node_B.j] = 0.0;
      proc_control_node_B.i_l++;
    }
  }

  proc_control_node_xorgqr(33, 33, 33, proc_control_node_B.c_A, 1,
    proc_control_node_B.tau, 1);
  proc_control_node_B.i_l = 0;
  for (proc_control_node_B.j = 0; proc_control_node_B.j < 33;
       proc_control_node_B.j++) {
    memcpy(&Q[proc_control_node_B.i_l],
           &proc_control_node_B.c_A[proc_control_node_B.i_l], 33U * sizeof
           (real_T));
    proc_control_node_B.i_l += 33;
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_KWIKfactor(const real_T b_Ac[2112], const int16_T
  iC[64], int16_T nA, const real_T b_Linv[1089], real_T b_D[1089], real_T b_H
  [1089], int16_T n, real_T RLinv[1089], real_T *Status)
{
  int32_T exitg1;
  *Status = 1.0;
  memset(&RLinv[0], 0, 1089U * sizeof(real_T));
  proc_control_node_B.i_fr = 1;
  while (proc_control_node_B.i_fr - 1 <= nA - 1) {
    proc_control_node_B.iC_o = iC[static_cast<int16_T>(proc_control_node_B.i_fr)
      - 1];
    for (proc_control_node_B.RLinv_tmp_tmp = 0;
         proc_control_node_B.RLinv_tmp_tmp < 33;
         proc_control_node_B.RLinv_tmp_tmp++) {
      proc_control_node_B.f_i = proc_control_node_B.RLinv_tmp_tmp + 33 * (
        static_cast<int16_T>(proc_control_node_B.i_fr) - 1);
      RLinv[proc_control_node_B.f_i] = 0.0;
      for (proc_control_node_B.RLinv_tmp = 0; proc_control_node_B.RLinv_tmp < 33;
           proc_control_node_B.RLinv_tmp++) {
        RLinv[proc_control_node_B.f_i] += b_Ac[((proc_control_node_B.RLinv_tmp <<
          6) + proc_control_node_B.iC_o) - 1] * b_Linv[33 *
          proc_control_node_B.RLinv_tmp + proc_control_node_B.RLinv_tmp_tmp];
      }
    }

    proc_control_node_B.i_fr++;
  }

  proc_control_node_qr(RLinv, proc_control_node_B.QQ, proc_control_node_B.RR);
  proc_control_node_B.i_fr = 1;
  do {
    exitg1 = 0;
    if (proc_control_node_B.i_fr - 1 <= nA - 1) {
      if (fabs(proc_control_node_B.RR[((static_cast<int16_T>
             (proc_control_node_B.i_fr) - 1) * 33 + static_cast<int16_T>
            (proc_control_node_B.i_fr)) - 1]) < 1.0E-12) {
        *Status = -2.0;
        exitg1 = 1;
      } else {
        proc_control_node_B.i_fr++;
      }
    } else {
      proc_control_node_B.i_fr = 1;
      while (proc_control_node_B.i_fr - 1 <= n - 1) {
        proc_control_node_B.f_i = 1;
        while (proc_control_node_B.f_i - 1 <= n - 1) {
          proc_control_node_B.b_Linv_a = 0.0;
          for (proc_control_node_B.RLinv_tmp_tmp = 0;
               proc_control_node_B.RLinv_tmp_tmp < 33;
               proc_control_node_B.RLinv_tmp_tmp++) {
            proc_control_node_B.b_Linv_a += b_Linv[(static_cast<int16_T>
              (proc_control_node_B.i_fr) - 1) * 33 +
              proc_control_node_B.RLinv_tmp_tmp] * proc_control_node_B.QQ[(
              static_cast<int16_T>(proc_control_node_B.f_i) - 1) * 33 +
              proc_control_node_B.RLinv_tmp_tmp];
          }

          proc_control_node_B.TL[(static_cast<int16_T>(proc_control_node_B.i_fr)
            + 33 * (static_cast<int16_T>(proc_control_node_B.f_i) - 1)) - 1] =
            proc_control_node_B.b_Linv_a;
          proc_control_node_B.f_i++;
        }

        proc_control_node_B.i_fr++;
      }

      memset(&RLinv[0], 0, 1089U * sizeof(real_T));
      proc_control_node_B.b_j_g = nA;
      while (proc_control_node_B.b_j_g > 0) {
        proc_control_node_B.RLinv_tmp_tmp = 33 * (proc_control_node_B.b_j_g - 1);
        proc_control_node_B.f_i = (proc_control_node_B.b_j_g +
          proc_control_node_B.RLinv_tmp_tmp) - 1;
        RLinv[proc_control_node_B.f_i] = 1.0;
        proc_control_node_B.c_k = proc_control_node_B.b_j_g;
        while (proc_control_node_B.c_k <= nA) {
          proc_control_node_B.RLinv_tmp = ((proc_control_node_B.c_k - 1) * 33 +
            proc_control_node_B.b_j_g) - 1;
          RLinv[proc_control_node_B.RLinv_tmp] /=
            proc_control_node_B.RR[proc_control_node_B.f_i];
          proc_control_node_B.c_k = static_cast<int16_T>(proc_control_node_B.c_k
            + 1);
        }

        if (proc_control_node_B.b_j_g > 1) {
          proc_control_node_B.i_fr = 1;
          while (proc_control_node_B.i_fr - 1 <= proc_control_node_B.b_j_g - 2)
          {
            proc_control_node_B.c_k = proc_control_node_B.b_j_g;
            while (proc_control_node_B.c_k <= nA) {
              proc_control_node_B.f_i = (proc_control_node_B.c_k - 1) * 33;
              proc_control_node_B.RLinv_tmp = (proc_control_node_B.f_i +
                static_cast<int16_T>(proc_control_node_B.i_fr)) - 1;
              RLinv[proc_control_node_B.RLinv_tmp] -= proc_control_node_B.RR
                [(proc_control_node_B.RLinv_tmp_tmp + static_cast<int16_T>
                  (proc_control_node_B.i_fr)) - 1] * RLinv
                [(proc_control_node_B.f_i + proc_control_node_B.b_j_g) - 1];
              proc_control_node_B.c_k = static_cast<int16_T>
                (proc_control_node_B.c_k + 1);
            }

            proc_control_node_B.i_fr++;
          }
        }

        proc_control_node_B.b_j_g = static_cast<int16_T>
          (proc_control_node_B.b_j_g - 1);
      }

      proc_control_node_B.i_fr = 1;
      while (proc_control_node_B.i_fr - 1 <= n - 1) {
        proc_control_node_B.b_j_g = static_cast<int16_T>
          (proc_control_node_B.i_fr);
        while (proc_control_node_B.b_j_g <= n) {
          proc_control_node_B.RLinv_tmp_tmp = (static_cast<int16_T>
            (proc_control_node_B.i_fr) + 33 * (proc_control_node_B.b_j_g - 1)) -
            1;
          b_H[proc_control_node_B.RLinv_tmp_tmp] = 0.0;
          proc_control_node_B.RLinv_tmp = nA + 1;
          if (nA + 1 > 32767) {
            proc_control_node_B.RLinv_tmp = 32767;
          }

          proc_control_node_B.c_k = static_cast<int16_T>
            (proc_control_node_B.RLinv_tmp);
          while (proc_control_node_B.c_k <= n) {
            proc_control_node_B.RLinv_tmp = (proc_control_node_B.c_k - 1) * 33;
            b_H[proc_control_node_B.RLinv_tmp_tmp] -= proc_control_node_B.TL
              [(proc_control_node_B.RLinv_tmp + static_cast<int16_T>
                (proc_control_node_B.i_fr)) - 1] * proc_control_node_B.TL
              [(proc_control_node_B.RLinv_tmp + proc_control_node_B.b_j_g) - 1];
            proc_control_node_B.c_k = static_cast<int16_T>
              (proc_control_node_B.c_k + 1);
          }

          b_H[(proc_control_node_B.b_j_g + 33 * (static_cast<int16_T>
                (proc_control_node_B.i_fr) - 1)) - 1] =
            b_H[proc_control_node_B.RLinv_tmp_tmp];
          proc_control_node_B.b_j_g = static_cast<int16_T>
            (proc_control_node_B.b_j_g + 1);
        }

        proc_control_node_B.i_fr++;
      }

      proc_control_node_B.i_fr = 1;
      while (proc_control_node_B.i_fr - 1 <= nA - 1) {
        proc_control_node_B.f_i = 1;
        while (proc_control_node_B.f_i - 1 <= n - 1) {
          proc_control_node_B.RLinv_tmp_tmp = (static_cast<int16_T>
            (proc_control_node_B.f_i) + 33 * (static_cast<int16_T>
            (proc_control_node_B.i_fr) - 1)) - 1;
          b_D[proc_control_node_B.RLinv_tmp_tmp] = 0.0;
          proc_control_node_B.b_j_g = static_cast<int16_T>
            (proc_control_node_B.i_fr);
          while (proc_control_node_B.b_j_g <= nA) {
            proc_control_node_B.RLinv_tmp = (proc_control_node_B.b_j_g - 1) * 33;
            b_D[proc_control_node_B.RLinv_tmp_tmp] += proc_control_node_B.TL
              [(proc_control_node_B.RLinv_tmp + static_cast<int16_T>
                (proc_control_node_B.f_i)) - 1] * RLinv
              [(proc_control_node_B.RLinv_tmp + static_cast<int16_T>
                (proc_control_node_B.i_fr)) - 1];
            proc_control_node_B.b_j_g = static_cast<int16_T>
              (proc_control_node_B.b_j_g + 1);
          }

          proc_control_node_B.f_i++;
        }

        proc_control_node_B.i_fr++;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static real_T proc_control_node_mtimes(const real_T b_A[33], const real_T b_B[33])
{
  real_T b_C;
  int32_T k;
  b_C = 0.0;
  for (k = 0; k < 33; k++) {
    b_C += b_A[k] * b_B[k];
  }

  return b_C;
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_nod_DropConstraint(int16_T kDrop, int16_T iA[64],
  int16_T *nA, int16_T iC[64])
{
  int32_T tmp;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (*nA - 1 < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= static_cast<int16_T>(tmp); i = static_cast<int16_T>(i +
          1)) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (*nA - 1 < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_qpkwik(const real_T b_Linv[1089], const real_T
  b_Hinv[1089], const real_T f[33], const real_T b_Ac[2112], const real_T b[64],
  int16_T iA[64], int16_T maxiter, real_T FeasTol, real_T x[33], real_T lambda
  [64], real_T *status)
{
  int32_T exitg1;
  int32_T exitg3;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  memset(&lambda[0], 0, sizeof(real_T) << 6U);
  memset(&x[0], 0, 33U * sizeof(real_T));
  memset(&proc_control_node_B.r_n[0], 0, 33U * sizeof(real_T));
  proc_control_node_B.rMin = 0.0;
  proc_control_node_B.cTolComputed = false;
  for (proc_control_node_B.i_j = 0; proc_control_node_B.i_j < 64;
       proc_control_node_B.i_j++) {
    proc_control_node_B.cTol[proc_control_node_B.i_j] = 1.0;
    proc_control_node_B.iC[proc_control_node_B.i_j] = 0;
  }

  proc_control_node_B.nA = 0;
  for (proc_control_node_B.i_j = 0; proc_control_node_B.i_j < 64;
       proc_control_node_B.i_j++) {
    if (iA[proc_control_node_B.i_j] == 1) {
      proc_control_node_B.U_tmp = proc_control_node_B.nA + 1;
      if (proc_control_node_B.nA + 1 > 32767) {
        proc_control_node_B.U_tmp = 32767;
      }

      proc_control_node_B.nA = static_cast<int16_T>(proc_control_node_B.U_tmp);
      proc_control_node_B.iC[static_cast<int16_T>(proc_control_node_B.U_tmp) - 1]
        = static_cast<int16_T>(proc_control_node_B.i_j + 1);
    }
  }

  guard1 = false;
  if (proc_control_node_B.nA > 0) {
    memset(&proc_control_node_B.Opt[0], 0, 66U * sizeof(real_T));
    for (proc_control_node_B.i_j = 0; proc_control_node_B.i_j < 33;
         proc_control_node_B.i_j++) {
      proc_control_node_B.Rhs[proc_control_node_B.i_j] =
        f[proc_control_node_B.i_j];
      proc_control_node_B.Rhs[proc_control_node_B.i_j + 33] = 0.0;
    }

    proc_control_node_B.DualFeasible = false;
    proc_control_node_B.U_tmp = 3 * proc_control_node_B.nA;
    if (proc_control_node_B.U_tmp > 32767) {
      proc_control_node_B.U_tmp = 32767;
    }

    if (static_cast<int16_T>(proc_control_node_B.U_tmp) > 50) {
      proc_control_node_B.kNext = static_cast<int16_T>(proc_control_node_B.U_tmp);
    } else {
      proc_control_node_B.kNext = 50;
    }

    proc_control_node_B.q_c = static_cast<uint16_T>(proc_control_node_B.kNext /
      10U);
    proc_control_node_B.b_x_a = static_cast<uint16_T>(static_cast<uint32_T>
      (proc_control_node_B.kNext) - proc_control_node_B.q_c * 10);
    if ((proc_control_node_B.b_x_a > 0) && (proc_control_node_B.b_x_a >= 5)) {
      proc_control_node_B.q_c = static_cast<uint16_T>(proc_control_node_B.q_c +
        1);
    }

    proc_control_node_B.ColdReset = false;
    do {
      exitg3 = 0;
      if ((!proc_control_node_B.DualFeasible) && (proc_control_node_B.nA > 0) &&
          (static_cast<int32_T>(*status) <= maxiter)) {
        proc_control_node_KWIKfactor(b_Ac, proc_control_node_B.iC,
          proc_control_node_B.nA, b_Linv, proc_control_node_B.b_D,
          proc_control_node_B.b_H, 33, proc_control_node_B.RLinv,
          &proc_control_node_B.Xnorm0);
        if (proc_control_node_B.Xnorm0 < 0.0) {
          if (proc_control_node_B.ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            proc_control_node_B.nA = 0;
            memset(&iA[0], 0, sizeof(int16_T) << 6U);
            memset(&proc_control_node_B.iC[0], 0, sizeof(int16_T) << 6U);
            proc_control_node_B.ColdReset = true;
          }
        } else {
          proc_control_node_B.i_j = 1;
          while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1) {
            proc_control_node_B.U_tmp = static_cast<int16_T>
              (proc_control_node_B.i_j) + 33;
            if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
              proc_control_node_B.U_tmp = 32767;
            }

            proc_control_node_B.Rhs[proc_control_node_B.U_tmp - 1] =
              b[proc_control_node_B.iC[static_cast<int16_T>
              (proc_control_node_B.i_j) - 1] - 1];
            proc_control_node_B.kNext = static_cast<int16_T>
              (proc_control_node_B.i_j);
            while (proc_control_node_B.kNext <= proc_control_node_B.nA) {
              proc_control_node_B.U_tmp = (proc_control_node_B.kNext + 33 * (
                static_cast<int16_T>(proc_control_node_B.i_j) - 1)) - 1;
              proc_control_node_B.U[proc_control_node_B.U_tmp] = 0.0;
              proc_control_node_B.lambda_tmp_tmp = 1;
              while (proc_control_node_B.lambda_tmp_tmp - 1 <=
                     proc_control_node_B.nA - 1) {
                proc_control_node_B.U_tmp_o = (static_cast<int16_T>
                  (proc_control_node_B.lambda_tmp_tmp) - 1) * 33;
                proc_control_node_B.U[proc_control_node_B.U_tmp] +=
                  proc_control_node_B.RLinv[(proc_control_node_B.U_tmp_o +
                  proc_control_node_B.kNext) - 1] * proc_control_node_B.RLinv
                  [(proc_control_node_B.U_tmp_o + static_cast<int16_T>
                    (proc_control_node_B.i_j)) - 1];
                proc_control_node_B.lambda_tmp_tmp++;
              }

              proc_control_node_B.U[(static_cast<int16_T>
                (proc_control_node_B.i_j) + 33 * (proc_control_node_B.kNext - 1))
                - 1] = proc_control_node_B.U[proc_control_node_B.U_tmp];
              proc_control_node_B.kNext = static_cast<int16_T>
                (proc_control_node_B.kNext + 1);
            }

            proc_control_node_B.i_j++;
          }

          for (proc_control_node_B.i_j = 0; proc_control_node_B.i_j < 33;
               proc_control_node_B.i_j++) {
            proc_control_node_B.Xnorm0 = 0.0;
            for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
                 proc_control_node_B.U_tmp++) {
              proc_control_node_B.Xnorm0 +=
                proc_control_node_B.b_H[proc_control_node_B.i_j + 33 *
                proc_control_node_B.U_tmp] *
                proc_control_node_B.Rhs[proc_control_node_B.U_tmp];
            }

            proc_control_node_B.Opt[proc_control_node_B.i_j] =
              proc_control_node_B.Xnorm0;
            proc_control_node_B.lambda_tmp_tmp = 1;
            while (proc_control_node_B.lambda_tmp_tmp - 1 <=
                   proc_control_node_B.nA - 1) {
              proc_control_node_B.U_tmp = static_cast<int16_T>
                (proc_control_node_B.lambda_tmp_tmp) + 33;
              if (static_cast<int16_T>(proc_control_node_B.lambda_tmp_tmp) + 33 >
                  32767) {
                proc_control_node_B.U_tmp = 32767;
              }

              proc_control_node_B.Opt[proc_control_node_B.i_j] +=
                proc_control_node_B.b_D[(static_cast<int16_T>
                (proc_control_node_B.lambda_tmp_tmp) - 1) * 33 +
                proc_control_node_B.i_j] *
                proc_control_node_B.Rhs[proc_control_node_B.U_tmp - 1];
              proc_control_node_B.lambda_tmp_tmp++;
            }
          }

          proc_control_node_B.i_j = 1;
          while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1) {
            proc_control_node_B.Xnorm0 = 0.0;
            for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
                 proc_control_node_B.U_tmp++) {
              proc_control_node_B.Xnorm0 += proc_control_node_B.b_D[(
                static_cast<int16_T>(proc_control_node_B.i_j) - 1) * 33 +
                proc_control_node_B.U_tmp] *
                proc_control_node_B.Rhs[proc_control_node_B.U_tmp];
            }

            proc_control_node_B.U_tmp = static_cast<int16_T>
              (proc_control_node_B.i_j) + 33;
            if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
              proc_control_node_B.U_tmp = 32767;
            }

            proc_control_node_B.Opt[proc_control_node_B.U_tmp - 1] =
              proc_control_node_B.Xnorm0;
            proc_control_node_B.lambda_tmp_tmp = 1;
            while (proc_control_node_B.lambda_tmp_tmp - 1 <=
                   proc_control_node_B.nA - 1) {
              proc_control_node_B.U_tmp = static_cast<int16_T>
                (proc_control_node_B.i_j) + 33;
              if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
                proc_control_node_B.U_tmp = 32767;
              }

              proc_control_node_B.U_tmp_o = static_cast<int16_T>
                (proc_control_node_B.i_j) + 33;
              if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
                proc_control_node_B.U_tmp_o = 32767;
              }

              proc_control_node_B.i18 = static_cast<int16_T>
                (proc_control_node_B.lambda_tmp_tmp) + 33;
              if (static_cast<int16_T>(proc_control_node_B.lambda_tmp_tmp) + 33 >
                  32767) {
                proc_control_node_B.i18 = 32767;
              }

              proc_control_node_B.Opt[proc_control_node_B.U_tmp - 1] =
                proc_control_node_B.U[((static_cast<int16_T>
                (proc_control_node_B.lambda_tmp_tmp) - 1) * 33 +
                static_cast<int16_T>(proc_control_node_B.i_j)) - 1] *
                proc_control_node_B.Rhs[proc_control_node_B.i18 - 1] +
                proc_control_node_B.Opt[proc_control_node_B.U_tmp_o - 1];
              proc_control_node_B.lambda_tmp_tmp++;
            }

            proc_control_node_B.i_j++;
          }

          proc_control_node_B.Xnorm0 = -1.0E-12;
          proc_control_node_B.kDrop = 0;
          proc_control_node_B.i_j = 1;
          while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1) {
            proc_control_node_B.U_tmp = static_cast<int16_T>
              (proc_control_node_B.i_j) + 33;
            if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
              proc_control_node_B.U_tmp = 32767;
            }

            lambda[proc_control_node_B.iC[static_cast<int16_T>
              (proc_control_node_B.i_j) - 1] - 1] =
              proc_control_node_B.Opt[proc_control_node_B.U_tmp - 1];
            proc_control_node_B.U_tmp = static_cast<int16_T>
              (proc_control_node_B.i_j) + 33;
            if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
              proc_control_node_B.U_tmp = 32767;
            }

            if ((proc_control_node_B.Opt[proc_control_node_B.U_tmp - 1] <
                 proc_control_node_B.Xnorm0) && (static_cast<int16_T>
                 (proc_control_node_B.i_j) <= proc_control_node_B.nA)) {
              proc_control_node_B.kDrop = static_cast<int16_T>
                (proc_control_node_B.i_j);
              proc_control_node_B.U_tmp = static_cast<int16_T>
                (proc_control_node_B.i_j) + 33;
              if (static_cast<int16_T>(proc_control_node_B.i_j) + 33 > 32767) {
                proc_control_node_B.U_tmp = 32767;
              }

              proc_control_node_B.Xnorm0 =
                proc_control_node_B.Opt[proc_control_node_B.U_tmp - 1];
            }

            proc_control_node_B.i_j++;
          }

          if (proc_control_node_B.kDrop <= 0) {
            proc_control_node_B.DualFeasible = true;
            memcpy(&x[0], &proc_control_node_B.Opt[0], 33U * sizeof(real_T));
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > proc_control_node_B.q_c) {
              proc_control_node_B.nA = 0;
              memset(&iA[0], 0, sizeof(int16_T) << 6U);
              memset(&proc_control_node_B.iC[0], 0, sizeof(int16_T) << 6U);
              proc_control_node_B.ColdReset = true;
            } else {
              lambda[proc_control_node_B.iC[proc_control_node_B.kDrop - 1] - 1] =
                0.0;
              proc_control_nod_DropConstraint(proc_control_node_B.kDrop, iA,
                &proc_control_node_B.nA, proc_control_node_B.iC);
            }
          }
        }
      } else {
        if (proc_control_node_B.nA <= 0) {
          memset(&lambda[0], 0, sizeof(real_T) << 6U);
          proc_control_node_Unconstrained(b_Hinv, f, x, 33);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    proc_control_node_Unconstrained(b_Hinv, f, x, 33);
    guard1 = true;
  }

  if (guard1) {
    proc_control_node_B.Xnorm0 = proc_control_node_norm(x);
    exitg2 = false;
    while ((!exitg2) && (static_cast<int32_T>(*status) <= maxiter)) {
      proc_control_node_B.cMin = -FeasTol;
      proc_control_node_B.kNext = 0;
      for (proc_control_node_B.i_j = 0; proc_control_node_B.i_j < 64;
           proc_control_node_B.i_j++) {
        proc_control_node_B.t_h =
          proc_control_node_B.cTol[proc_control_node_B.i_j];
        if (!proc_control_node_B.cTolComputed) {
          for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
               proc_control_node_B.U_tmp++) {
            proc_control_node_B.b_Ac[proc_control_node_B.U_tmp] =
              b_Ac[proc_control_node_B.i_j + (proc_control_node_B.U_tmp << 6)] *
              x[proc_control_node_B.U_tmp];
          }

          proc_control_node_abs(proc_control_node_B.b_Ac, proc_control_node_B.z);
          proc_control_node_B.cVal = proc_control_node_maximum
            (proc_control_node_B.z);
          if ((!(proc_control_node_B.t_h > proc_control_node_B.cVal)) &&
              (!rtIsNaN(proc_control_node_B.cVal))) {
            proc_control_node_B.t_h = proc_control_node_B.cVal;
          }
        }

        if (iA[proc_control_node_B.i_j] == 0) {
          proc_control_node_B.b_Ac_m = 0.0;
          for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
               proc_control_node_B.U_tmp++) {
            proc_control_node_B.b_Ac_m += b_Ac[proc_control_node_B.i_j +
              (proc_control_node_B.U_tmp << 6)] * x[proc_control_node_B.U_tmp];
          }

          proc_control_node_B.cVal = (proc_control_node_B.b_Ac_m -
            b[proc_control_node_B.i_j]) / proc_control_node_B.t_h;
          if (proc_control_node_B.cVal < proc_control_node_B.cMin) {
            proc_control_node_B.cMin = proc_control_node_B.cVal;
            proc_control_node_B.kNext = static_cast<int16_T>
              (proc_control_node_B.i_j + 1);
          }
        }

        proc_control_node_B.cTol[proc_control_node_B.i_j] =
          proc_control_node_B.t_h;
      }

      proc_control_node_B.cTolComputed = true;
      if (proc_control_node_B.kNext <= 0) {
        exitg2 = true;
      } else if (static_cast<int32_T>(*status) == maxiter) {
        *status = 0.0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((proc_control_node_B.kNext > 0) && (static_cast<int32_T>(*status) <=
               maxiter)) {
            guard2 = false;
            if (proc_control_node_B.nA == 0) {
              for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
                   proc_control_node_B.U_tmp++) {
                proc_control_node_B.z[proc_control_node_B.U_tmp] = 0.0;
                for (proc_control_node_B.U_tmp_o = 0;
                     proc_control_node_B.U_tmp_o < 33;
                     proc_control_node_B.U_tmp_o++) {
                  proc_control_node_B.z[proc_control_node_B.U_tmp] += b_Ac
                    [((proc_control_node_B.U_tmp_o << 6) +
                      proc_control_node_B.kNext) - 1] * b_Hinv[33 *
                    proc_control_node_B.U_tmp_o + proc_control_node_B.U_tmp];
                }
              }

              guard2 = true;
            } else {
              proc_control_node_KWIKfactor(b_Ac, proc_control_node_B.iC,
                proc_control_node_B.nA, b_Linv, proc_control_node_B.b_D,
                proc_control_node_B.b_H, 33, proc_control_node_B.RLinv,
                &proc_control_node_B.cMin);
              if (proc_control_node_B.cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp <
                     1089; proc_control_node_B.U_tmp++) {
                  proc_control_node_B.U[proc_control_node_B.U_tmp] =
                    -proc_control_node_B.b_H[proc_control_node_B.U_tmp];
                }

                for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp <
                     33; proc_control_node_B.U_tmp++) {
                  proc_control_node_B.z[proc_control_node_B.U_tmp] = 0.0;
                  for (proc_control_node_B.U_tmp_o = 0;
                       proc_control_node_B.U_tmp_o < 33;
                       proc_control_node_B.U_tmp_o++) {
                    proc_control_node_B.z[proc_control_node_B.U_tmp] += b_Ac
                      [((proc_control_node_B.U_tmp_o << 6) +
                        proc_control_node_B.kNext) - 1] * proc_control_node_B.U
                      [33 * proc_control_node_B.U_tmp_o +
                      proc_control_node_B.U_tmp];
                  }
                }

                proc_control_node_B.i_j = 1;
                while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1)
                {
                  proc_control_node_B.b_Ac_m = 0.0;
                  for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp <
                       33; proc_control_node_B.U_tmp++) {
                    proc_control_node_B.b_Ac_m += b_Ac
                      [((proc_control_node_B.U_tmp << 6) +
                        proc_control_node_B.kNext) - 1] *
                      proc_control_node_B.b_D[(static_cast<int16_T>
                      (proc_control_node_B.i_j) - 1) * 33 +
                      proc_control_node_B.U_tmp];
                  }

                  proc_control_node_B.r_n[static_cast<int16_T>
                    (proc_control_node_B.i_j) - 1] = proc_control_node_B.b_Ac_m;
                  proc_control_node_B.i_j++;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              proc_control_node_B.kDrop = 0;
              proc_control_node_B.cMin = 0.0;
              proc_control_node_B.DualFeasible = true;
              proc_control_node_B.ColdReset = true;
              if (proc_control_node_B.nA > 0) {
                proc_control_node_B.i_j = 0;
                exitg4 = false;
                while ((!exitg4) && (proc_control_node_B.i_j <=
                                     proc_control_node_B.nA - 1)) {
                  if (proc_control_node_B.r_n[proc_control_node_B.i_j] >=
                      1.0E-12) {
                    proc_control_node_B.ColdReset = false;
                    exitg4 = true;
                  } else {
                    proc_control_node_B.i_j++;
                  }
                }
              }

              if ((proc_control_node_B.nA != 0) &&
                  (!proc_control_node_B.ColdReset)) {
                proc_control_node_B.i_j = 1;
                while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1)
                {
                  proc_control_node_B.t_h = proc_control_node_B.r_n[static_cast<
                    int16_T>(proc_control_node_B.i_j) - 1];
                  if (proc_control_node_B.t_h > 1.0E-12) {
                    proc_control_node_B.cVal = lambda[proc_control_node_B.iC[
                      static_cast<int16_T>(proc_control_node_B.i_j) - 1] - 1] /
                      proc_control_node_B.t_h;
                    if ((proc_control_node_B.kDrop == 0) ||
                        (proc_control_node_B.cVal < proc_control_node_B.rMin)) {
                      proc_control_node_B.rMin = proc_control_node_B.cVal;
                      proc_control_node_B.kDrop = static_cast<int16_T>
                        (proc_control_node_B.i_j);
                    }
                  }

                  proc_control_node_B.i_j++;
                }

                if (proc_control_node_B.kDrop > 0) {
                  proc_control_node_B.cMin = proc_control_node_B.rMin;
                  proc_control_node_B.DualFeasible = false;
                }
              }

              for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp < 33;
                   proc_control_node_B.U_tmp++) {
                proc_control_node_B.b_Ac[proc_control_node_B.U_tmp] = b_Ac
                  [((proc_control_node_B.U_tmp << 6) + proc_control_node_B.kNext)
                  - 1];
              }

              proc_control_node_B.cVal = proc_control_node_mtimes
                (proc_control_node_B.z, proc_control_node_B.b_Ac);
              if (proc_control_node_B.cVal <= 0.0) {
                proc_control_node_B.cVal = 0.0;
                proc_control_node_B.ColdReset = true;
              } else {
                proc_control_node_B.b_Ac_m = 0.0;
                for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp <
                     33; proc_control_node_B.U_tmp++) {
                  proc_control_node_B.b_Ac_m += b_Ac[((proc_control_node_B.U_tmp
                    << 6) + proc_control_node_B.kNext) - 1] *
                    x[proc_control_node_B.U_tmp];
                }

                proc_control_node_B.cVal = (b[proc_control_node_B.kNext - 1] -
                  proc_control_node_B.b_Ac_m) / proc_control_node_B.cVal;
                proc_control_node_B.ColdReset = false;
              }

              if (proc_control_node_B.DualFeasible &&
                  proc_control_node_B.ColdReset) {
                *status = -1.0;
                exitg1 = 1;
              } else {
                if (proc_control_node_B.ColdReset) {
                  proc_control_node_B.t_h = proc_control_node_B.cMin;
                } else if (proc_control_node_B.DualFeasible) {
                  proc_control_node_B.t_h = proc_control_node_B.cVal;
                } else if ((proc_control_node_B.cMin < proc_control_node_B.cVal)
                           || rtIsNaN(proc_control_node_B.cVal)) {
                  proc_control_node_B.t_h = proc_control_node_B.cMin;
                } else {
                  proc_control_node_B.t_h = proc_control_node_B.cVal;
                }

                proc_control_node_B.i_j = 1;
                while (proc_control_node_B.i_j - 1 <= proc_control_node_B.nA - 1)
                {
                  proc_control_node_B.lambda_tmp_tmp = proc_control_node_B.iC[
                    static_cast<int16_T>(proc_control_node_B.i_j) - 1];
                  lambda[proc_control_node_B.lambda_tmp_tmp - 1] -=
                    proc_control_node_B.r_n[static_cast<int16_T>
                    (proc_control_node_B.i_j) - 1] * proc_control_node_B.t_h;
                  if ((proc_control_node_B.lambda_tmp_tmp <= 64) &&
                      (lambda[proc_control_node_B.lambda_tmp_tmp - 1] < 0.0)) {
                    lambda[proc_control_node_B.lambda_tmp_tmp - 1] = 0.0;
                  }

                  proc_control_node_B.i_j++;
                }

                lambda[proc_control_node_B.kNext - 1] += proc_control_node_B.t_h;
                if (proc_control_node_B.t_h == proc_control_node_B.cMin) {
                  proc_control_nod_DropConstraint(proc_control_node_B.kDrop, iA,
                    &proc_control_node_B.nA, proc_control_node_B.iC);
                }

                if (!proc_control_node_B.ColdReset) {
                  for (proc_control_node_B.U_tmp = 0; proc_control_node_B.U_tmp <
                       33; proc_control_node_B.U_tmp++) {
                    x[proc_control_node_B.U_tmp] += proc_control_node_B.t_h *
                      proc_control_node_B.z[proc_control_node_B.U_tmp];
                  }

                  if (proc_control_node_B.t_h == proc_control_node_B.cVal) {
                    if (proc_control_node_B.nA == 33) {
                      *status = -1.0;
                      exitg1 = 1;
                    } else {
                      proc_control_node_B.U_tmp = proc_control_node_B.nA + 1;
                      if (proc_control_node_B.nA + 1 > 32767) {
                        proc_control_node_B.U_tmp = 32767;
                      }

                      proc_control_node_B.nA = static_cast<int16_T>
                        (proc_control_node_B.U_tmp);
                      proc_control_node_B.iC[static_cast<int16_T>
                        (proc_control_node_B.U_tmp) - 1] =
                        proc_control_node_B.kNext;
                      proc_control_node_B.kDrop = static_cast<int16_T>
                        (proc_control_node_B.U_tmp);
                      exitg4 = false;
                      while ((!exitg4) && (proc_control_node_B.kDrop > 1)) {
                        proc_control_node_B.i33 =
                          proc_control_node_B.iC[proc_control_node_B.kDrop - 1];
                        proc_control_node_B.i34 =
                          proc_control_node_B.iC[proc_control_node_B.kDrop - 2];
                        if (proc_control_node_B.i33 > proc_control_node_B.i34) {
                          exitg4 = true;
                        } else {
                          proc_control_node_B.iC[proc_control_node_B.kDrop - 1] =
                            proc_control_node_B.i34;
                          proc_control_node_B.iC[proc_control_node_B.kDrop - 2] =
                            proc_control_node_B.i33;
                          proc_control_node_B.kDrop = static_cast<int16_T>
                            (proc_control_node_B.kDrop - 1);
                        }
                      }

                      iA[proc_control_node_B.kNext - 1] = 1;
                      proc_control_node_B.kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            proc_control_node_B.cMin = proc_control_node_norm(x);
            if (fabs(proc_control_node_B.cMin - proc_control_node_B.Xnorm0) >
                0.001) {
              proc_control_node_B.Xnorm0 = proc_control_node_B.cMin;
              proc_control_node_abs_i(b, proc_control_node_B.dv4);
              proc_control_node_maximum2(proc_control_node_B.dv4, 1.0,
                proc_control_node_B.cTol);
              proc_control_node_B.cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_node_mpc_solveQP(const real_T xQP[20], const real_T
  b_Kx[640], const real_T b_Kr[3840], const real_T rseq[120], const real_T
  b_Ku1[256], const real_T old_u[8], const real_T b_Kv[352], const real_T vseq
  [11], const real_T b_Kut[2560], const real_T b_utarget[80], const real_T
  b_Linv[1089], const real_T b_Hinv[1089], const real_T b_Ac[2112], const real_T
  Bc[64], boolean_T iA[64], real_T zopt[33], real_T f[33], real_T *status)
{
  memset(&f[0], 0, 33U * sizeof(real_T));
  for (proc_control_node_B.i_fa = 0; proc_control_node_B.i_fa < 32;
       proc_control_node_B.i_fa++) {
    proc_control_node_B.b_Kx_i = 0.0;
    for (proc_control_node_B.i17 = 0; proc_control_node_B.i17 < 20;
         proc_control_node_B.i17++) {
      proc_control_node_B.b_Kx_i += b_Kx[20 * proc_control_node_B.i_fa +
        proc_control_node_B.i17] * xQP[proc_control_node_B.i17];
    }

    proc_control_node_B.b_Kr_o = 0.0;
    for (proc_control_node_B.i17 = 0; proc_control_node_B.i17 < 120;
         proc_control_node_B.i17++) {
      proc_control_node_B.b_Kr_o += b_Kr[120 * proc_control_node_B.i_fa +
        proc_control_node_B.i17] * rseq[proc_control_node_B.i17];
    }

    proc_control_node_B.b_Ku1_m = 0.0;
    for (proc_control_node_B.i17 = 0; proc_control_node_B.i17 < 8;
         proc_control_node_B.i17++) {
      proc_control_node_B.b_Ku1_m += b_Ku1[(proc_control_node_B.i_fa << 3) +
        proc_control_node_B.i17] * old_u[proc_control_node_B.i17];
    }

    proc_control_node_B.b_Kv_c = 0.0;
    for (proc_control_node_B.i17 = 0; proc_control_node_B.i17 < 11;
         proc_control_node_B.i17++) {
      proc_control_node_B.b_Kv_c += b_Kv[11 * proc_control_node_B.i_fa +
        proc_control_node_B.i17] * vseq[proc_control_node_B.i17];
    }

    proc_control_node_B.b_Kut_f = 0.0;
    for (proc_control_node_B.i17 = 0; proc_control_node_B.i17 < 80;
         proc_control_node_B.i17++) {
      proc_control_node_B.b_Kut_f += b_Kut[80 * proc_control_node_B.i_fa +
        proc_control_node_B.i17] * b_utarget[proc_control_node_B.i17];
    }

    f[proc_control_node_B.i_fa] = (((proc_control_node_B.b_Kx_i +
      proc_control_node_B.b_Kr_o) + proc_control_node_B.b_Ku1_m) +
      proc_control_node_B.b_Kv_c) + proc_control_node_B.b_Kut_f;
  }

  for (proc_control_node_B.i_fa = 0; proc_control_node_B.i_fa < 64;
       proc_control_node_B.i_fa++) {
    proc_control_node_B.iAnew[proc_control_node_B.i_fa] =
      iA[proc_control_node_B.i_fa];
  }

  proc_control_node_qpkwik(b_Linv, b_Hinv, f, b_Ac, Bc,
    proc_control_node_B.iAnew, 388, 0.01, zopt, proc_control_node_B.a__1, status);
  for (proc_control_node_B.i_fa = 0; proc_control_node_B.i_fa < 64;
       proc_control_node_B.i_fa++) {
    iA[proc_control_node_B.i_fa] =
      (proc_control_node_B.iAnew[proc_control_node_B.i_fa] != 0);
  }

  if ((*status < 0.0) || (*status == 0.0)) {
    memset(&zopt[0], 0, 33U * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S144>/FixedHorizonOptimizer'
static void proc_control_mpcblock_optimizer(const real_T rseq[120], const real_T
  vseq[11], const real_T x[20], const real_T old_u[8], const boolean_T iA[64],
  const real_T b_Mlim[64], real_T b_Mx[1280], real_T b_Mu1[512], real_T b_Mv[704],
  const real_T b_utarget[80], const real_T b_uoff[8], real_T b_H[1089], real_T
  b_Ac[2112], const real_T b_Wy[12], const real_T b_Wdu[8], const real_T b_Jm
  [2560], const real_T b_Wu[8], const real_T b_I1[640], const real_T b_A[400],
  const real_T Bu[1760], const real_T Bv[220], const real_T b_C[240], const
  real_T Dv[132], const real_T b_Mrows[64], real_T u[8], real_T useq[88], real_T
  *status, boolean_T iAout[64])
{
  static const int8_T c_A[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1 };

  boolean_T exitg1;
  memset(&useq[0], 0, 88U * sizeof(real_T));
  memset(&iAout[0], 0, sizeof(boolean_T) << 6U);
  proc_control_mpc_constraintcoef(b_A, &Bu[0], &Bv[0], b_C, &Dv[0], b_Jm,
    proc_control_node_B.b_SuJm, proc_control_node_B.b_Sx,
    proc_control_node_B.b_Su1, proc_control_node_B.b_Hv);
  if (b_Mrows[0] > 0.0) {
    proc_control_node_B.kidx = 0;
    exitg1 = false;
    while ((!exitg1) && (proc_control_node_B.kidx < 64)) {
      if (b_Mrows[proc_control_node_B.kidx] <= 120.0) {
        proc_control_node_B.i_fc = static_cast<int32_T>
          (b_Mrows[proc_control_node_B.kidx]);
        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 32;
             proc_control_node_B.b_j1++) {
          b_Ac[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            -proc_control_node_B.b_SuJm[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 20;
             proc_control_node_B.b_j1++) {
          b_Mx[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            -proc_control_node_B.b_Sx[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 8;
             proc_control_node_B.b_j1++) {
          b_Mu1[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            -proc_control_node_B.b_Su1[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 11;
             proc_control_node_B.b_j1++) {
          b_Mv[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            -proc_control_node_B.b_Hv[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        proc_control_node_B.kidx++;
      } else if (b_Mrows[proc_control_node_B.kidx] <= 240.0) {
        proc_control_node_B.i_fc = static_cast<int32_T>
          (b_Mrows[proc_control_node_B.kidx] - 120.0);
        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 32;
             proc_control_node_B.b_j1++) {
          b_Ac[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            proc_control_node_B.b_SuJm[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 20;
             proc_control_node_B.b_j1++) {
          b_Mx[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            proc_control_node_B.b_Sx[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 8;
             proc_control_node_B.b_j1++) {
          b_Mu1[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            proc_control_node_B.b_Su1[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 11;
             proc_control_node_B.b_j1++) {
          b_Mv[proc_control_node_B.kidx + (proc_control_node_B.b_j1 << 6)] =
            proc_control_node_B.b_Hv[(120 * proc_control_node_B.b_j1 +
            proc_control_node_B.i_fc) - 1];
        }

        proc_control_node_B.kidx++;
      } else {
        exitg1 = true;
      }
    }
  }

  memset(&proc_control_node_B.b_I[0], 0, sizeof(int8_T) << 6U);
  proc_control_node_B.kidx_a = 0;
  for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 8;
       proc_control_node_B.kidx++) {
    proc_control_node_B.b_I[proc_control_node_B.kidx_a] = 1;
    proc_control_node_B.kidx_a += 9;
  }

  proc_control_node_B.kidx = -1;
  for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 10;
       proc_control_node_B.b_j1++) {
    for (proc_control_node_B.i_fc = 0; proc_control_node_B.i_fc < 8;
         proc_control_node_B.i_fc++) {
      for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 10;
           proc_control_node_B.kidx_a++) {
        for (proc_control_node_B.i2_k = 0; proc_control_node_B.i2_k < 8;
             proc_control_node_B.i2_k++) {
          proc_control_node_B.a_c[(proc_control_node_B.kidx +
            proc_control_node_B.i2_k) + 1] = static_cast<int8_T>(c_A[10 *
            proc_control_node_B.b_j1 + proc_control_node_B.kidx_a] *
            proc_control_node_B.b_I[(proc_control_node_B.i_fc << 3) +
            proc_control_node_B.i2_k]);
        }

        proc_control_node_B.kidx += 8;
      }
    }
  }

  for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 32;
       proc_control_node_B.b_j1++) {
    memset(&proc_control_node_B.a[proc_control_node_B.b_j1 * 80], 0, 80U *
           sizeof(real_T));
    for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 80;
         proc_control_node_B.kidx_a++) {
      for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 80;
           proc_control_node_B.kidx++) {
        proc_control_node_B.i_fc = 80 * proc_control_node_B.b_j1 +
          proc_control_node_B.kidx;
        proc_control_node_B.a[proc_control_node_B.i_fc] += static_cast<real_T>
          (proc_control_node_B.a_c[80 * proc_control_node_B.kidx_a +
           proc_control_node_B.kidx]) * b_Jm[80 * proc_control_node_B.b_j1 +
          proc_control_node_B.kidx_a];
      }
    }
  }

  proc_contr_mpc_calculatehessian(b_Wy, b_Wu, b_Wdu, proc_control_node_B.b_SuJm,
    proc_control_node_B.a, b_Jm, b_I1, proc_control_node_B.b_Su1,
    proc_control_node_B.b_Sx, proc_control_node_B.b_Hv, proc_control_node_nu,
    proc_control_node_ny, proc_control_node_B.b, proc_control_node_B.b_Ku1,
    proc_control_node_B.b_Kut, proc_control_node_B.b_Kx,
    proc_control_node_B.b_Kv, proc_control_node_B.b_Kr);
  proc_control_node_B.b_j1 = 0;
  proc_control_node_B.kidx = 0;
  for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 32;
       proc_control_node_B.kidx_a++) {
    memcpy(&b_H[proc_control_node_B.b_j1],
           &proc_control_node_B.b[proc_control_node_B.kidx], sizeof(real_T) <<
           5U);
    proc_control_node_B.b_j1 += 33;
    proc_control_node_B.kidx += 32;
  }

  memcpy(&proc_control_node_B.b_Linv[0], &b_H[0], 1089U * sizeof(real_T));
  proc_control_n_mpc_checkhessian(proc_control_node_B.b_Linv,
    proc_control_node_B.c_Linv, &proc_control_node_B.BadH);
  if (proc_control_node_B.BadH > 1.0) {
    proc_control_node_B.kidx = 0;
    for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 8;
         proc_control_node_B.kidx_a++) {
      u[proc_control_node_B.kidx_a] = old_u[proc_control_node_B.kidx_a] +
        b_uoff[proc_control_node_B.kidx_a];
      for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 11;
           proc_control_node_B.b_j1++) {
        useq[proc_control_node_B.b_j1 + proc_control_node_B.kidx] =
          u[proc_control_node_B.kidx_a];
      }

      proc_control_node_B.kidx += 11;
    }

    *status = -2.0;
  } else {
    memset(&proc_control_node_B.c_I[0], 0, 1089U * sizeof(int8_T));
    proc_control_node_B.kidx_a = 0;
    for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 33;
         proc_control_node_B.kidx++) {
      proc_control_node_B.c_I[proc_control_node_B.kidx_a] = 1;
      proc_control_node_B.kidx_a += 34;
    }

    proc_control_node_B.kidx_a = 0;
    for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 33;
         proc_control_node_B.kidx++) {
      for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 33;
           proc_control_node_B.b_j1++) {
        proc_control_node_B.i_fc = proc_control_node_B.b_j1 +
          proc_control_node_B.kidx_a;
        proc_control_node_B.b_Linv[proc_control_node_B.i_fc] =
          proc_control_node_B.c_I[proc_control_node_B.i_fc];
      }

      proc_control_node_B.kidx_a += 33;
    }

    proc_control_node_trisolve(proc_control_node_B.c_Linv,
      proc_control_node_B.b_Linv);
    for (proc_control_node_B.i_fc = 0; proc_control_node_B.i_fc < 64;
         proc_control_node_B.i_fc++) {
      iAout[proc_control_node_B.i_fc] = iA[proc_control_node_B.i_fc];
      proc_control_node_B.BadH = 0.0;
      proc_control_node_B.b_j1 = 0;
      for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 20;
           proc_control_node_B.kidx++) {
        proc_control_node_B.BadH += b_Mx[proc_control_node_B.b_j1 +
          proc_control_node_B.i_fc] * x[proc_control_node_B.kidx];
        proc_control_node_B.b_j1 += 64;
      }

      proc_control_node_B.b_Mlim_d[proc_control_node_B.i_fc] =
        b_Mlim[proc_control_node_B.i_fc] + proc_control_node_B.BadH;
      proc_control_node_B.b_Mu1[proc_control_node_B.i_fc] = 0.0;
    }

    proc_control_node_B.b_j1 = 0;
    for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 8;
         proc_control_node_B.kidx++) {
      for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 64;
           proc_control_node_B.kidx_a++) {
        proc_control_node_B.b_Mu1[proc_control_node_B.kidx_a] +=
          b_Mu1[proc_control_node_B.kidx_a + proc_control_node_B.b_j1] *
          old_u[proc_control_node_B.kidx];
      }

      proc_control_node_B.b_j1 += 64;
    }

    proc_control_node_B.b_j1 = 0;
    for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 33;
         proc_control_node_B.kidx++) {
      proc_control_node_B.kidx_a = 0;
      for (proc_control_node_B.i2_k = 0; proc_control_node_B.i2_k < 33;
           proc_control_node_B.i2_k++) {
        proc_control_node_B.i_fc = proc_control_node_B.i2_k +
          proc_control_node_B.b_j1;
        proc_control_node_B.c_Linv[proc_control_node_B.i_fc] = 0.0;
        for (proc_control_node_B.i6 = 0; proc_control_node_B.i6 < 33;
             proc_control_node_B.i6++) {
          proc_control_node_B.c_Linv[proc_control_node_B.i_fc] +=
            proc_control_node_B.b_Linv[proc_control_node_B.i6 +
            proc_control_node_B.kidx_a] *
            proc_control_node_B.b_Linv[proc_control_node_B.i6 +
            proc_control_node_B.b_j1];
        }

        proc_control_node_B.kidx_a += 33;
      }

      proc_control_node_B.b_j1 += 33;
    }

    for (proc_control_node_B.b_j1 = 0; proc_control_node_B.b_j1 < 64;
         proc_control_node_B.b_j1++) {
      proc_control_node_B.BadH = 0.0;
      proc_control_node_B.kidx = 0;
      for (proc_control_node_B.kidx_a = 0; proc_control_node_B.kidx_a < 11;
           proc_control_node_B.kidx_a++) {
        proc_control_node_B.BadH += b_Mv[proc_control_node_B.kidx +
          proc_control_node_B.b_j1] * vseq[proc_control_node_B.kidx_a];
        proc_control_node_B.kidx += 64;
      }

      proc_control_node_B.b_Mlim_dy[proc_control_node_B.b_j1] =
        -((proc_control_node_B.b_Mlim_d[proc_control_node_B.b_j1] +
           proc_control_node_B.b_Mu1[proc_control_node_B.b_j1]) +
          proc_control_node_B.BadH);
    }

    proc_control_node_mpc_solveQP(x, proc_control_node_B.b_Kx,
      proc_control_node_B.b_Kr, rseq, proc_control_node_B.b_Ku1, old_u,
      proc_control_node_B.b_Kv, vseq, proc_control_node_B.b_Kut, b_utarget,
      proc_control_node_B.b_Linv, proc_control_node_B.c_Linv, b_Ac,
      proc_control_node_B.b_Mlim_dy, iAout, proc_control_node_B.zopt,
      proc_control_node_B.f, status);
    for (proc_control_node_B.kidx = 0; proc_control_node_B.kidx < 8;
         proc_control_node_B.kidx++) {
      u[proc_control_node_B.kidx] = (old_u[proc_control_node_B.kidx] +
        proc_control_node_B.zopt[proc_control_node_B.kidx]) +
        b_uoff[proc_control_node_B.kidx];
    }
  }
}

static boolean_T proc_control_node_isequal(const real_T varargin_1[3], const
  real_T varargin_2[3])
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 3)) {
    if (!(varargin_1[b_k] == varargin_2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  return p;
}

static boolean_T proc_control_node_isequal_b4(const real_T varargin_1[6], const
  real_T varargin_2[6])
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 6)) {
    if (!(varargin_1[b_k] == varargin_2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  return p;
}

// Function for MATLAB Function: '<S1>/AUV State Equation'
static real_T proc_control_node_erf(real_T x)
{
  real_T y;

  // ========================== COPYRIGHT NOTICE ============================
  //  The algorithms for calculating ERF(X) and ERFC(X) are derived
  //  from FDLIBM, which has the following notice:
  //
  //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
  //
  //  Developed at SunSoft, a Sun Microsystems, Inc. business.
  //  Permission to use, copy, modify, and distribute this
  //  software is freely granted, provided that this notice
  //  is preserved.
  // =============================    END    ================================
  proc_control_node_B.absx = fabs(x);
  if (rtIsNaN(x)) {
    y = x;
  } else if (rtIsInf(x)) {
    if (x < 0.0) {
      y = -1.0;
    } else {
      y = 1.0;
    }
  } else if (proc_control_node_B.absx < 0.84375) {
    if (proc_control_node_B.absx < 3.7252902984619141E-9) {
      if (proc_control_node_B.absx < 2.8480945388892178E-306) {
        y = (8.0 * x + 1.0270333367641007 * x) * 0.125;
      } else {
        y = 0.12837916709551259 * x + x;
      }
    } else {
      proc_control_node_B.z_o = x * x;
      y = ((((proc_control_node_B.z_o * -2.3763016656650163E-5 +
              -0.0057702702964894416) * proc_control_node_B.z_o +
             -0.02848174957559851) * proc_control_node_B.z_o +
            -0.3250421072470015) * proc_control_node_B.z_o + 0.12837916709551256)
        / (((((proc_control_node_B.z_o * -3.9602282787753681E-6 +
               0.00013249473800432164) * proc_control_node_B.z_o +
              0.0050813062818757656) * proc_control_node_B.z_o +
             0.0650222499887673) * proc_control_node_B.z_o + 0.39791722395915535)
           * proc_control_node_B.z_o + 1.0) * x + x;
    }
  } else if (proc_control_node_B.absx < 1.25) {
    if (x >= 0.0) {
      y = (((((((proc_control_node_B.absx - 1.0) * -0.0021663755948687908 +
                0.035478304325618236) * (proc_control_node_B.absx - 1.0) +
               -0.11089469428239668) * (proc_control_node_B.absx - 1.0) +
              0.31834661990116175) * (proc_control_node_B.absx - 1.0) +
             -0.37220787603570132) * (proc_control_node_B.absx - 1.0) +
            0.41485611868374833) * (proc_control_node_B.absx - 1.0) +
           -0.0023621185607526594) / (((((((proc_control_node_B.absx - 1.0) *
        0.011984499846799107 + 0.013637083912029051) * (proc_control_node_B.absx
        - 1.0) + 0.12617121980876164) * (proc_control_node_B.absx - 1.0) +
        0.071828654414196266) * (proc_control_node_B.absx - 1.0) +
        0.540397917702171) * (proc_control_node_B.absx - 1.0) +
        0.10642088040084423) * (proc_control_node_B.absx - 1.0) + 1.0) +
        0.84506291151046753;
    } else {
      y = -0.84506291151046753 - (((((((proc_control_node_B.absx - 1.0) *
        -0.0021663755948687908 + 0.035478304325618236) *
        (proc_control_node_B.absx - 1.0) + -0.11089469428239668) *
        (proc_control_node_B.absx - 1.0) + 0.31834661990116175) *
        (proc_control_node_B.absx - 1.0) + -0.37220787603570132) *
        (proc_control_node_B.absx - 1.0) + 0.41485611868374833) *
        (proc_control_node_B.absx - 1.0) + -0.0023621185607526594) /
        (((((((proc_control_node_B.absx - 1.0) * 0.011984499846799107 +
              0.013637083912029051) * (proc_control_node_B.absx - 1.0) +
             0.12617121980876164) * (proc_control_node_B.absx - 1.0) +
            0.071828654414196266) * (proc_control_node_B.absx - 1.0) +
           0.540397917702171) * (proc_control_node_B.absx - 1.0) +
          0.10642088040084423) * (proc_control_node_B.absx - 1.0) + 1.0);
    }
  } else if (proc_control_node_B.absx > 6.0) {
    if (x < 0.0) {
      y = -1.0;
    } else {
      y = 1.0;
    }
  } else {
    proc_control_node_B.s_g = 1.0 / (proc_control_node_B.absx *
      proc_control_node_B.absx);
    if (proc_control_node_B.absx < 2.8571434020996094) {
      proc_control_node_B.R = ((((((proc_control_node_B.s_g *
        -9.8143293441691455 + -81.2874355063066) * proc_control_node_B.s_g +
        -184.60509290671104) * proc_control_node_B.s_g + -162.39666946257347) *
        proc_control_node_B.s_g + -62.375332450326006) * proc_control_node_B.s_g
        + -10.558626225323291) * proc_control_node_B.s_g + -0.69385857270718176)
        * proc_control_node_B.s_g + -0.0098649440348471482;
      proc_control_node_B.s_g = (((((((proc_control_node_B.s_g *
        -0.0604244152148581 + 6.5702497703192817) * proc_control_node_B.s_g +
        108.63500554177944) * proc_control_node_B.s_g + 429.00814002756783) *
        proc_control_node_B.s_g + 645.38727173326788) * proc_control_node_B.s_g
        + 434.56587747522923) * proc_control_node_B.s_g + 137.65775414351904) *
        proc_control_node_B.s_g + 19.651271667439257) * proc_control_node_B.s_g
        + 1.0;
    } else {
      proc_control_node_B.R = (((((proc_control_node_B.s_g * -483.5191916086514
        + -1025.0951316110772) * proc_control_node_B.s_g + -637.56644336838963) *
        proc_control_node_B.s_g + -160.63638485582192) * proc_control_node_B.s_g
        + -17.757954917754752) * proc_control_node_B.s_g + -0.799283237680523) *
        proc_control_node_B.s_g + -0.0098649429247001;
      proc_control_node_B.s_g = ((((((proc_control_node_B.s_g *
        -22.440952446585818 + 474.52854120695537) * proc_control_node_B.s_g +
        2553.0504064331644) * proc_control_node_B.s_g + 3199.8582195085955) *
        proc_control_node_B.s_g + 1536.729586084437) * proc_control_node_B.s_g +
        325.79251299657392) * proc_control_node_B.s_g + 30.338060743482458) *
        proc_control_node_B.s_g + 1.0;
    }

    if (!rtIsNaN(proc_control_node_B.absx)) {
      proc_control_node_B.z_o = frexp(proc_control_node_B.absx,
        &proc_control_node_B.e_i);
    } else {
      proc_control_node_B.z_o = proc_control_node_B.absx;
      proc_control_node_B.e_i = 0;
    }

    proc_control_node_B.z_o = floor(proc_control_node_B.z_o * 2.097152E+6) /
      2.097152E+6 * proc_control_node_rt_powd_snf(2.0, static_cast<real_T>
      (proc_control_node_B.e_i));
    if (x < 0.0) {
      y = exp((proc_control_node_B.z_o - proc_control_node_B.absx) *
              (proc_control_node_B.z_o + proc_control_node_B.absx) +
              proc_control_node_B.R / proc_control_node_B.s_g) * exp
        (-proc_control_node_B.z_o * proc_control_node_B.z_o - 0.5625) /
        proc_control_node_B.absx - 1.0;
    } else {
      y = 1.0 - exp((proc_control_node_B.z_o - proc_control_node_B.absx) *
                    (proc_control_node_B.z_o + proc_control_node_B.absx) +
                    proc_control_node_B.R / proc_control_node_B.s_g) * exp
        (-proc_control_node_B.z_o * proc_control_node_B.z_o - 0.5625) /
        proc_control_node_B.absx;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S1>/AUV State Equation'
static void proc_con_AUVQuatPerturbedSimFcn(const real_T in1[13], const real_T
  in2[6], const real_T in3[8], real_T out1[13])
{
  proc_control_node_B.t8 = in1[4] * in1[6];
  proc_control_node_B.t9_i = in1[5] * in1[6];
  proc_control_node_B.t10_m = in1[3] * in1[4];
  proc_control_node_B.t11_j = in1[3] * in1[5];
  proc_control_node_B.t12_e = in1[4] * in1[4];
  proc_control_node_B.t13_m = in1[5] * in1[5];
  proc_control_node_B.t15_m = in1[4] * in1[5] * 2.0;
  proc_control_node_B.t20 = in1[3] * in1[6] * 2.0;
  proc_control_node_B.t33 = in1[11] / 500.0;
  proc_control_node_B.t37 = in1[10] / 1000.0;
  proc_control_node_B.t39 = in1[12] * 0.018;
  proc_control_node_B.t62_j = in1[7] * 32.4648;
  proc_control_node_B.t65_f = in1[8] * 43.6156;
  proc_control_node_B.t66 = in1[9] * 46.7695;
  proc_control_node_B.t16_a = proc_control_node_B.t8 * 2.0;
  proc_control_node_B.t17_g = proc_control_node_B.t9_i * 2.0;
  proc_control_node_B.t18 = proc_control_node_B.t10_m * 2.0;
  proc_control_node_B.t19 = proc_control_node_B.t11_j * 2.0;
  proc_control_node_B.t21_n = proc_control_node_B.t12_e * 2.0;
  proc_control_node_B.t22 = proc_control_node_B.t13_m * 2.0;
  proc_control_node_B.t23 = in1[6] * in1[6] * 2.0;
  proc_control_node_B.t73 = proc_control_node_B.t33 + proc_control_node_B.t39;
  proc_control_node_B.t33 += proc_control_node_B.t37;
  proc_control_node_B.t37 += proc_control_node_B.t39;
  proc_control_node_B.t39 = in1[11] * 0.558 + proc_control_node_B.t62_j;
  proc_control_node_B.t80 = in1[10] * 0.062 + proc_control_node_B.t66;
  proc_control_node_B.t81 = in1[12] * 0.031 + proc_control_node_B.t65_f;
  proc_control_node_B.t84 = (in1[11] / 125.0 + in1[12] / 250.0) + in1[10] *
    0.592;
  proc_control_node_B.t45 = proc_control_node_B.t17_g + proc_control_node_B.t18;
  proc_control_node_B.t55 = proc_control_node_erf(in1[2] * 13.333333333333334 -
    2.0);
  proc_control_node_B.t63 = (proc_control_node_B.t21_n + proc_control_node_B.t22)
    - 1.0;
  proc_control_node_B.t62_j = in1[12] * 0.062 + -proc_control_node_B.t62_j;
  proc_control_node_B.t65_f = in1[10] * 0.558 + -proc_control_node_B.t65_f;
  proc_control_node_B.t66 = in1[11] * 0.031 + -proc_control_node_B.t66;
  proc_control_node_B.t86 = (in1[10] / 250.0 + -(in1[11] / 1000.0)) + in1[12] *
    1.8864;
  proc_control_node_B.t87 = (in1[10] / 125.0 + -(in1[12] / 1000.0)) + in1[11] *
    1.7228;
  proc_control_node_B.t56_d = proc_control_node_B.t16_a +
    -proc_control_node_B.t19;
  proc_control_node_B.t85 = proc_control_node_B.t55 * 0.01575 + 0.01575;
  proc_control_node_B.t55 = proc_control_node_B.t55 * 15.7185 - 15.2815;
  out1[0] = (((proc_control_node_B.t22 + proc_control_node_B.t23) - 1.0) * -in1
             [7] + (proc_control_node_B.t16_a + proc_control_node_B.t19) * in1[9])
    + (proc_control_node_B.t15_m - proc_control_node_B.t20) * in1[8];
  out1[1] = ((proc_control_node_B.t15_m + proc_control_node_B.t20) * in1[7] -
             ((proc_control_node_B.t21_n + proc_control_node_B.t23) - 1.0) *
             in1[8]) + (proc_control_node_B.t17_g - proc_control_node_B.t18) *
    in1[9];
  out1[2] = (proc_control_node_B.t56_d * in1[7] + proc_control_node_B.t45 * in1
             [8]) - proc_control_node_B.t63 * in1[9];
  out1[3] = (in1[4] * in1[10] * -0.5 - in1[5] * in1[11] / 2.0) - in1[6] * in1[12]
    / 2.0;
  out1[4] = (in1[3] * in1[10] / 2.0 - in1[6] * in1[11] / 2.0) + in1[5] * in1[12]
    / 2.0;
  out1[5] = (in1[6] * in1[10] / 2.0 + in1[3] * in1[11] / 2.0) - in1[4] * in1[12]
    / 2.0;
  out1[6] = (in1[5] * in1[10] * -0.5 + in1[4] * in1[11] / 2.0) + in1[3] * in1[12]
    / 2.0;
  proc_control_node_B.t15_m = in1[10] * (fabs(in1[10]) * 0.167 + 2.5);
  proc_control_node_B.t20 = in1[10] * proc_control_node_B.t73;
  proc_control_node_B.t16_a = in1[10] * proc_control_node_B.t80;
  proc_control_node_B.t17_g = in1[10] * proc_control_node_B.t65_f;
  proc_control_node_B.t18 = in1[10] * proc_control_node_B.t86;
  proc_control_node_B.t19 = in1[10] * proc_control_node_B.t87;
  proc_control_node_B.t21_n = in1[11] * (fabs(in1[11]) / 10.0 + 1.75);
  proc_control_node_B.t22 = in1[11] * proc_control_node_B.t37;
  proc_control_node_B.t23 = in1[11] * proc_control_node_B.t39;
  proc_control_node_B.out1_tmp = in1[11] * proc_control_node_B.t66;
  proc_control_node_B.out1_tmp_n = in1[11] * proc_control_node_B.t84;
  proc_control_node_B.t86 *= in1[11];
  proc_control_node_B.out1_tmp_c = in1[12] * (fabs(in1[12]) * 0.102 + 3.75);
  proc_control_node_B.out1_tmp_f = in1[12] * proc_control_node_B.t33;
  proc_control_node_B.out1_tmp_p = in1[12] * proc_control_node_B.t62_j;
  proc_control_node_B.out1_tmp_p2 = in1[12] * proc_control_node_B.t81;
  proc_control_node_B.t84 *= in1[12];
  proc_control_node_B.t87 *= in1[12];
  proc_control_node_B.out1_tmp_nj = (proc_control_node_B.t9_i +
    proc_control_node_B.t10_m) * proc_control_node_B.t55;
  proc_control_node_B.t45 *= proc_control_node_B.t85;
  proc_control_node_B.out1_tmp_k = (proc_control_node_B.t8 +
    -proc_control_node_B.t11_j) * proc_control_node_B.t55;
  proc_control_node_B.t56_d *= proc_control_node_B.t85;
  proc_control_node_B.t55 *= proc_control_node_B.t63;
  proc_control_node_B.t63 = (fabs(in1[7]) * 1.17 + 11.25) * in1[7];
  proc_control_node_B.t73 *= in1[7];
  proc_control_node_B.t81 *= in1[7];
  proc_control_node_B.t66 *= in1[7];
  proc_control_node_B.t85 = (fabs(in1[8]) * 0.82 + 15.0) * in1[8];
  proc_control_node_B.t37 *= in1[8];
  proc_control_node_B.t62_j *= in1[8];
  proc_control_node_B.t80 *= in1[8];
  proc_control_node_B.out1_tmp_n3 = (fabs(in1[9]) * 0.756 + 17.5) * in1[9];
  proc_control_node_B.t33 *= in1[9];
  proc_control_node_B.t39 *= in1[9];
  proc_control_node_B.t65_f *= in1[9];
  out1[7] = (((((((((((((((((((((in2[0] * 0.030976977065388711 + in2[1] *
    9.4803055144857715E-7) - in2[2] * 6.8231348244175949E-6) + in2[3] *
    0.0001303522588356414) + (in2[4] * -0.010033314971702871 + in2[5] *
    0.0010125044874363649)) + (in3[0] * -0.00033076834054020519 + in3[1] *
    1.8595780444550231E-21)) + in3[2] * 0.00033506403327449372) + (in3[3] *
    0.00033363213569639753 - in3[4] * 0.001819638864719295)) + (in3[5] *
    -0.0018124211550371481 + in3[6] * 0.0018538731733468781)) + (in3[7] *
    0.001778186846409557 - proc_control_node_B.t8 * 0.11107598193630119)) +
                        ((proc_control_node_B.t9_i * -0.00081126583629370218 -
    proc_control_node_B.t10_m * 0.00081126583629370218) +
    proc_control_node_B.t11_j * 0.11107598193630119)) +
                       ((proc_control_node_B.t12_e * -0.0062610285338271466 -
    proc_control_node_B.t13_m * 0.0062610285338271466) + in3[0] *
                        1.4142135623730951 * 0.015171119710606879)) + (((in3[1] *
    1.4142135623730951 * 0.014928824155507611 + in3[2] * 1.4142135623730951 *
    0.015171119710606879) + in3[3] * 1.4142135623730951 * 0.01516372519659284) -
    proc_control_node_B.t15_m * 0.0001303522588356414)) +
                     (((proc_control_node_B.t20 * -0.96028628902704993 +
                        proc_control_node_B.t16_a * 9.4803055144857715E-7) -
                       proc_control_node_B.t17_g * 6.8231348244175949E-6) -
                      proc_control_node_B.t18 * 0.010033314971702871)) +
                    (((proc_control_node_B.t19 * -0.0010125044874363649 +
                       proc_control_node_B.t21_n * 0.010033314971702871) -
                      proc_control_node_B.t22 * 2.9388947094905889E-5) -
                     proc_control_node_B.t23 * 6.8231348244175949E-6)) +
                   (((proc_control_node_B.out1_tmp * 0.030976977065388711 +
                      proc_control_node_B.out1_tmp_n * 0.0010125044874363649) -
                     proc_control_node_B.t86 * 0.0001303522588356414) -
                    proc_control_node_B.out1_tmp_c * 0.0010125044874363649)) +
                  (((proc_control_node_B.out1_tmp_f * 0.0002115171795569455 +
                     proc_control_node_B.out1_tmp_p * 9.4803055144857715E-7) +
                    proc_control_node_B.out1_tmp_p2 * 0.030976977065388711) +
                   proc_control_node_B.t84 * 0.010033314971702871)) +
                 ((proc_control_node_B.t87 * 0.0001303522588356414 -
                   proc_control_node_B.out1_tmp_nj * 1.860035941942108E-5) +
                  proc_control_node_B.t45 * 0.0076571888871557192)) +
                ((proc_control_node_B.out1_tmp_k * -0.60776829002292643 +
                  proc_control_node_B.t56_d * 0.589379797395962) -
                 proc_control_node_B.t55 * 6.6934952627536608E-5)) +
               ((proc_control_node_B.t63 * -0.030976977065388711 +
                 proc_control_node_B.t73 * 0.0040409200239048832) -
                proc_control_node_B.t81 * 0.0010125044874363649)) +
              (((proc_control_node_B.t66 * 0.010033314971702871 -
                 proc_control_node_B.t85 * 9.4803055144857715E-7) -
                proc_control_node_B.t37 * 0.311032764122789) -
               proc_control_node_B.t62_j * 0.0010125044874363649)) +
             (((proc_control_node_B.t80 * -0.0001303522588356414 +
                proc_control_node_B.out1_tmp_n3 * 6.8231348244175949E-6) +
               proc_control_node_B.t33 * 0.031387639110527318) +
              proc_control_node_B.t39 * 0.010033314971702871)) +
    (proc_control_node_B.t65_f * -0.0001303522588356414 + 0.0031305142669135729);
  out1[8] = (((((((((((((((((((((in2[0] * 9.4803055144857715E-7 + in2[1] *
    0.02320783323245932) - in2[2] * 2.9076309096921531E-5) + in2[3] *
    0.021882274381510681) + (in2[4] * -0.0001026911824132076 - in2[5] *
    0.00042780737967584029)) + (in3[0] * 0.00013975754063522079 + in3[1] *
    7.9244610288113972E-21)) + in3[2] * -0.00014157257363048341) + (in3[3] *
    -0.0001409675626320625 - in3[4] * 0.0034249251816346319)) + (in3[5] *
    0.003387750973601051 + in3[6] * 0.0035708122797193441)) + (in3[7] *
    -0.0035336380716857632 - proc_control_node_B.t8 * 0.00060385694847962161)) +
                        ((proc_control_node_B.t9_i * -0.23982646564227009 -
    proc_control_node_B.t10_m * 0.23982646564227009) + proc_control_node_B.t11_j
    * 0.00060385694847962161)) + ((proc_control_node_B.t12_e *
    -0.026680932679612211 - proc_control_node_B.t13_m * 0.026680932679612211) -
    in3[0] * 1.4142135623730951 * 0.01090649593858282)) + ((in3[1] *
    1.4142135623730951 * 0.011000123045544621 - in3[2] * 1.4142135623730951 *
    0.01090649593858282) + in3[3] * 1.4142135623730951 * 0.01090087173345982)) +
                     (((proc_control_node_B.t15_m * -0.021882274381510681 -
                        proc_control_node_B.t20 * 2.9388947094905889E-5) +
                       proc_control_node_B.t16_a * 0.02320783323245932) -
                      proc_control_node_B.t17_g * 2.9076309096921531E-5)) +
                    (((proc_control_node_B.t18 * -0.0001026911824132076 +
                       proc_control_node_B.t19 * 0.00042780737967584029) +
                      proc_control_node_B.t21_n * 0.0001026911824132076) -
                     proc_control_node_B.t22 * 0.71944283020623911)) +
                   (((proc_control_node_B.t23 * -2.9076309096921531E-5 +
                      proc_control_node_B.out1_tmp * 9.4803055144857715E-7) -
                     proc_control_node_B.out1_tmp_n * 0.00042780737967584029) -
                    proc_control_node_B.t86 * 0.021882274381510681)) +
                  (((proc_control_node_B.out1_tmp_c * 0.00042780737967584029 +
                     proc_control_node_B.out1_tmp_f * 0.00090136558200456737) +
                    proc_control_node_B.out1_tmp_p * 0.02320783323245932) +
                   proc_control_node_B.out1_tmp_p2 * 9.4803055144857715E-7)) +
                 ((proc_control_node_B.t84 * 0.0001026911824132076 +
                   proc_control_node_B.t87 * 0.021882274381510681) -
                  proc_control_node_B.out1_tmp_nj * 0.45533768802085189)) +
                ((proc_control_node_B.t45 * 1.2854146887555269 -
                  proc_control_node_B.out1_tmp_k * 1.860035941942108E-5) +
                 proc_control_node_B.t56_d * 0.0060323141908477191)) +
               (((proc_control_node_B.t55 * -0.00028523859224080018 -
                  proc_control_node_B.t63 * 9.4803055144857715E-7) +
                 proc_control_node_B.t73 * 0.678350505826831) +
                proc_control_node_B.t81 * 0.00042780737967584029)) +
              (((proc_control_node_B.t66 * 0.0001026911824132076 -
                 proc_control_node_B.t85 * 0.02320783323245932) -
                proc_control_node_B.t37 * 0.0031834266548094372) +
               proc_control_node_B.t62_j * 0.00042780737967584029)) +
             (((proc_control_node_B.t80 * -0.021882274381510681 +
                proc_control_node_B.out1_tmp_n3 * 2.9076309096921531E-5) -
               proc_control_node_B.t33 * 0.013262028769951049) +
              proc_control_node_B.t39 * 0.0001026911824132076)) +
    (proc_control_node_B.t65_f * -0.021882274381510681 + 0.0133404663398061);
  out1[9] = ((((((((((((((((((((((in2[0] * -6.8231348244175949E-6 - in2[1] *
    2.9076309096921531E-5) + in2[2] * 0.021384731826702759) - in2[3] *
    0.002272431716587712) + (in2[4] * 0.00039756137245743289 + in2[5] *
    5.2828771531483014E-6)) + in3[0] * -1.725827915740819E-6) + in3[1] *
    -5.8281975682474322E-18) + in3[2] * 1.748241265284163E-6) + (in3[3] *
    1.740770148765829E-6 - in3[4] * 0.02095639900015615)) + (in3[5] *
    0.021100316216985739 - in3[6] * 0.021822949502860629)) + (in3[7] *
    0.02167903228603104 + proc_control_node_B.t8 * 0.004346059700124901)) +
                        ((proc_control_node_B.t9_i * 0.024881704687475689 +
    proc_control_node_B.t10_m * 0.024881704687475689) -
    proc_control_node_B.t11_j * 0.004346059700124901)) +
                       ((proc_control_node_B.t12_e * 0.0030060816152820162 +
    proc_control_node_B.t13_m * 0.0030060816152820162) - in3[0] *
                        1.4142135623730951 * 4.8869263875916949E-5)) + ((in3[1] *
    1.4142135623730951 * 6.6264429389244648E-5 - in3[2] * 1.4142135623730951 *
    4.8869263875916949E-5) + in3[3] * 1.4142135623730951 * 6.7490056888775055E-5))
                     + (((proc_control_node_B.t15_m * 0.002272431716587712 +
    proc_control_node_B.t20 * 0.0002115171795569455) - proc_control_node_B.t16_a
    * 2.9076309096921531E-5) + proc_control_node_B.t17_g * 0.021384731826702759))
                    + (((proc_control_node_B.t18 * 0.00039756137245743289 -
    proc_control_node_B.t19 * 5.2828771531483014E-6) - proc_control_node_B.t21_n
                        * 0.00039756137245743289) + proc_control_node_B.t22 *
                       0.00090136558200456737)) + (((proc_control_node_B.t23 *
    0.021384731826702759 - proc_control_node_B.out1_tmp * 6.8231348244175949E-6)
    + proc_control_node_B.out1_tmp_n * 5.2828771531483014E-6) +
    proc_control_node_B.t86 * 0.002272431716587712)) +
                  (((proc_control_node_B.out1_tmp_c * -5.2828771531483014E-6 -
                     proc_control_node_B.out1_tmp_f * 0.66292668662778553) -
                    proc_control_node_B.out1_tmp_p * 2.9076309096921531E-5) -
                   proc_control_node_B.out1_tmp_p2 * 6.8231348244175949E-6)) +
                 ((proc_control_node_B.t84 * -0.00039756137245743289 -
                   proc_control_node_B.t87 * 0.002272431716587712) +
                  proc_control_node_B.out1_tmp_nj * 0.00057047718448160036)) +
                ((proc_control_node_B.t45 * -0.133487820176676 +
                  proc_control_node_B.out1_tmp_k * 0.00013386990525507319) -
                 proc_control_node_B.t56_d * 0.023353661458078809)) +
               (((proc_control_node_B.t55 * 0.2097842192199541 +
                  proc_control_node_B.t63 * 6.8231348244175949E-6) -
                 proc_control_node_B.t73 * 0.070445383214219059) -
                proc_control_node_B.t81 * 5.2828771531483014E-6)) +
              (((proc_control_node_B.t66 * -0.00039756137245743289 +
                 proc_control_node_B.t85 * 2.9076309096921531E-5) +
                proc_control_node_B.t37 * 0.01232440254618042) -
               proc_control_node_B.t62_j * 5.2828771531483014E-6)) +
             (((proc_control_node_B.t80 * 0.002272431716587712 -
                proc_control_node_B.out1_tmp_n3 * 0.021384731826702759) +
               proc_control_node_B.t33 * 0.00016376919174759729) -
              proc_control_node_B.t39 * 0.00039756137245743289)) +
    (proc_control_node_B.t65_f * 0.002272431716587712 - 0.0015030408076410081);
  out1[10] = ((((((((((((((((((((((((in2[0] * 0.0001303522588356414 + in2[1] *
    0.021882274381510681) - in2[2] * 0.002272431716587712) + in2[3] *
    1.71018810547529) + (in2[4] * -0.0080268590155159435 - in2[5] *
    0.0039859244840414)) + in3[0] * 0.0013021350951669831) + in3[1] *
    6.1932883292401409E-19) + in3[2] * -0.00131904594055876) + (in3[3] *
    -0.0013134089920948341 - in3[4] * 0.26767193546582568)) + (in3[5] *
    0.26476621250220889 + in3[6] * 0.2790736050389333)) + (in3[7] *
    -0.27616788207531651 - proc_control_node_B.t8 * 0.0830290934481406)) +
    ((proc_control_node_B.t9_i * -18.72549529020894 - proc_control_node_B.t10_m *
      18.72549529020894) + proc_control_node_B.t11_j * 0.0830290934481406)) +
    ((proc_control_node_B.t12_e * -2.0852233152147792 -
      proc_control_node_B.t13_m * 2.0852233152147792) + in3[0] *
     1.4142135623730951 * 0.043593198825375247)) + ((in3[1] * 1.4142135623730951
    * -0.043051831063235027 + in3[2] * 1.4142135623730951 * 0.043593198825375247)
    - in3[3] * 1.4142135623730951 * 0.043976565543532631)) +
                        ((proc_control_node_B.t15_m * -1.71018810547529 -
    proc_control_node_B.t20 * 0.0040409200239048832) + proc_control_node_B.t16_a
    * 0.021882274381510681)) + ((proc_control_node_B.t17_g *
    -0.002272431716587712 - proc_control_node_B.t18 * 0.0080268590155159435) +
    proc_control_node_B.t19 * 0.0039859244840414)) + ((proc_control_node_B.t21_n
    * 0.0080268590155159435 - proc_control_node_B.t22 * 0.678350505826831) -
    proc_control_node_B.t23 * 0.002272431716587712)) +
                     ((proc_control_node_B.out1_tmp * 0.0001303522588356414 -
                       proc_control_node_B.out1_tmp_n * 0.0039859244840414) -
                      proc_control_node_B.t86 * 1.71018810547529)) +
                    (((proc_control_node_B.out1_tmp_c * 0.0039859244840414 +
                       proc_control_node_B.out1_tmp_f * 0.070445383214219059) +
                      proc_control_node_B.out1_tmp_p * 0.021882274381510681) +
                     proc_control_node_B.out1_tmp_p2 * 0.0001303522588356414)) +
                   ((proc_control_node_B.t84 * 0.0080268590155159435 +
                     proc_control_node_B.t87 * 1.71018810547529) -
                    proc_control_node_B.out1_tmp_nj * 0.42933022336523952)) +
                  ((proc_control_node_B.t45 * 100.460348544499 -
                    proc_control_node_B.out1_tmp_k * 0.0025575113183552841) +
                   proc_control_node_B.t56_d * 0.47151599980996189)) +
                 ((proc_control_node_B.t55 * -0.022292555139725449 -
                   proc_control_node_B.t63 * 0.0001303522588356414) +
                  proc_control_node_B.t73 * 53.015831269733987)) +
                ((proc_control_node_B.t81 * 0.0039859244840414 +
                  proc_control_node_B.t66 * 0.0080268590155159435) -
                 proc_control_node_B.t85 * 0.021882274381510681)) +
               ((proc_control_node_B.t37 * -0.2488326294809943 +
                 proc_control_node_B.t62_j * 0.0039859244840414) -
                proc_control_node_B.t80 * 1.71018810547529)) +
              ((proc_control_node_B.out1_tmp_n3 * 0.002272431716587712 -
                proc_control_node_B.t33 * 0.1235636590052834) +
               proc_control_node_B.t39 * 0.0080268590155159435)) +
    (proc_control_node_B.t65_f * -1.71018810547529 + 1.0426116576073889);
  out1[11] = ((((((((((((((((((((((in2[0] * -0.010033314971702871 - in2[1] *
    0.0001026911824132076) + in2[2] * 0.00039756137245743289) - in2[3] *
    0.0080268590155159435) + (in2[4] * 0.58374455968341665 - in2[5] *
    1.606290206365557E-6)) + (in3[0] * 5.24748238233168E-7 - in3[1] *
    1.083514276897426E-19)) + in3[2] * -5.3156315041823265E-7) + (in3[3] *
    -5.2929151302328333E-7 + in3[4] * 0.10593667623599359)) + (in3[5] *
    0.10537885436940329 - in3[6] * 0.10793139553633729)) + (in3[7] *
    -0.1033841350690595 + proc_control_node_B.t8 * 6.3908140435873166)) +
    ((proc_control_node_B.t9_i * 0.087876754449678615 +
      proc_control_node_B.t10_m * 0.087876754449678615) -
     proc_control_node_B.t11_j * 6.3908140435873166)) +
    ((proc_control_node_B.t12_e * 0.36480930847148191 +
      proc_control_node_B.t13_m * 0.36480930847148191) + in3[0] *
     1.4142135623730951 * 0.013457654526727991)) + ((in3[1] * 1.4142135623730951
    * 0.013869054980635681 + in3[2] * 1.4142135623730951 * 0.013457654526727991)
    + in3[3] * 1.4142135623730951 * 0.01386868232130781)) +
                       (((proc_control_node_B.t15_m * 0.0080268590155159435 +
    proc_control_node_B.t20 * 0.311032764122789) - proc_control_node_B.t16_a *
    0.0001026911824132076) + proc_control_node_B.t17_g * 0.00039756137245743289))
                      + ((proc_control_node_B.t18 * 0.58374455968341665 +
    proc_control_node_B.t19 * 1.606290206365557E-6) - proc_control_node_B.t21_n *
    0.58374455968341665)) + (((proc_control_node_B.t22 * 0.0031834266548094372 +
    proc_control_node_B.t23 * 0.00039756137245743289) -
    proc_control_node_B.out1_tmp * 0.010033314971702871) -
    proc_control_node_B.out1_tmp_n * 1.606290206365557E-6)) +
                    (((proc_control_node_B.t86 * 0.0080268590155159435 +
                       proc_control_node_B.out1_tmp_c * 1.606290206365557E-6) -
                      proc_control_node_B.out1_tmp_f * 0.01232440254618042) -
                     proc_control_node_B.out1_tmp_p * 0.0001026911824132076)) +
                   ((proc_control_node_B.out1_tmp_p2 * -0.010033314971702871 -
                     proc_control_node_B.t84 * 0.58374455968341665) -
                    proc_control_node_B.t87 * 0.0080268590155159435)) +
                  ((proc_control_node_B.out1_tmp_nj * 0.002014800998947134 -
                    proc_control_node_B.t45 * 0.47151599980996189) +
                   proc_control_node_B.out1_tmp_k * 0.19685363974481029)) +
                 ((proc_control_node_B.t56_d * -34.290486373399979 +
                   proc_control_node_B.t55 * 0.003900077063807416) +
                  proc_control_node_B.t63 * 0.010033314971702871)) +
                ((proc_control_node_B.t73 * -0.2488326294809943 +
                  proc_control_node_B.t81 * 1.606290206365557E-6) -
                 proc_control_node_B.t66 * 0.58374455968341665)) +
               (((proc_control_node_B.t85 * 0.0001026911824132076 +
                  proc_control_node_B.t37 * 18.096081350185919) +
                 proc_control_node_B.t62_j * 1.606290206365557E-6) +
                proc_control_node_B.t80 * 0.0080268590155159435)) +
              ((proc_control_node_B.out1_tmp_n3 * -0.00039756137245743289 -
                proc_control_node_B.t33 * 4.9794996397332282E-5) -
               proc_control_node_B.t39 * 0.58374455968341665)) +
    (proc_control_node_B.t65_f * 0.0080268590155159435 - 0.182404654235741);
  out1[12] = (((((((((((((((((((((((in2[0] * 0.0010125044874363649 - in2[1] *
    0.00042780737967584029) + in2[2] * 5.2828771531483014E-6) - in2[3] *
    0.0039859244840414) + (in2[4] * -1.606290206365557E-6 + in2[5] *
    0.53015902215788635)) + in3[0] * -0.1731941163298826) + in3[1] *
    -1.4397960202092559E-21) + in3[2] * 0.175443390567933) + (in3[3] *
    0.17469363248858291 + in3[4] * 0.00062021813460420567)) + (in3[5] *
    -0.0006207996116589 - in3[6] * 0.00064672437426625525)) + (in3[7] *
    0.00064730585132094889 - proc_control_node_B.t8 * 0.64492422651466708)) +
    ((proc_control_node_B.t9_i * 0.3660910622711756 + proc_control_node_B.t10_m *
      0.3660910622711756) + proc_control_node_B.t11_j * 0.64492422651466708)) +
    ((proc_control_node_B.t12_e * 0.0048476610015380046 +
      proc_control_node_B.t13_m * 0.0048476610015380046) + in3[0] *
     1.4142135623730951 * 0.00059255494878017434)) + ((in3[1] *
    1.4142135623730951 * -0.1225770464045467 + in3[2] * 1.4142135623730951 *
    0.00059255494878017434) + in3[3] * 1.4142135623730951 *
    0.00041984673608298361)) + (((proc_control_node_B.t15_m * 0.0039859244840414
    - proc_control_node_B.t20 * 0.031387639110527318) -
    proc_control_node_B.t16_a * 0.00042780737967584029) +
    proc_control_node_B.t17_g * 5.2828771531483014E-6)) +
                      (((proc_control_node_B.t18 * -1.606290206365557E-6 -
    proc_control_node_B.t19 * 0.53015902215788635) + proc_control_node_B.t21_n *
                        1.606290206365557E-6) + proc_control_node_B.t22 *
                       0.013262028769951049)) + (((proc_control_node_B.t23 *
    5.2828771531483014E-6 + proc_control_node_B.out1_tmp * 0.0010125044874363649)
    + proc_control_node_B.out1_tmp_n * 0.53015902215788635) +
    proc_control_node_B.t86 * 0.0039859244840414)) +
                    ((proc_control_node_B.out1_tmp_c * -0.53015902215788635 -
                      proc_control_node_B.out1_tmp_f * 0.00016376919174759729) -
                     proc_control_node_B.out1_tmp_p * 0.00042780737967584029)) +
                   (((proc_control_node_B.out1_tmp_p2 * 0.0010125044874363649 +
                      proc_control_node_B.t84 * 1.606290206365557E-6) -
                     proc_control_node_B.t87 * 0.0039859244840414) +
                    proc_control_node_B.out1_tmp_nj * 0.008393580789239987)) +
                  ((proc_control_node_B.t45 * -0.23414229210041551 -
                    proc_control_node_B.out1_tmp_k * 0.01986533804350149) +
                   proc_control_node_B.t56_d * 9.4357149063583354E-5)) +
                 ((proc_control_node_B.t55 * 5.1825024872384838E-5 -
                   proc_control_node_B.t63 * 0.0010125044874363649) -
                  proc_control_node_B.t73 * 0.1235636590052834)) +
                (((proc_control_node_B.t81 * -0.53015902215788635 +
                   proc_control_node_B.t66 * 1.606290206365557E-6) +
                  proc_control_node_B.t85 * 0.00042780737967584029) -
                 proc_control_node_B.t37 * 4.9794996397332282E-5)) +
               ((proc_control_node_B.t62_j * -0.53015902215788635 +
                 proc_control_node_B.t80 * 0.0039859244840414) -
                proc_control_node_B.out1_tmp_n3 * 5.2828771531483014E-6)) +
              ((proc_control_node_B.t33 * 16.434929686894481 +
                proc_control_node_B.t39 * 1.606290206365557E-6) +
               proc_control_node_B.t65_f * 0.0039859244840414)) +
    -0.0024238305007690032;
}

static void imuSensor_set_MagneticFieldNED(fusion_simulink_imuSensor_pro_T *obj,
  const real_T val[3])
{
  if (obj->isInitialized == 1) {
    obj->TunablePropsChanged = true;
    obj->tunablePropertyChanged[2] = true;
  }

  obj->MagneticField[0] = val[0];
  obj->MagneticField[1] = val[1];
  obj->MagneticField[2] = val[2];
}

static void IMUSensorParameters_updateSyste(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3],
  h_fusion_internal_Acceleromet_T *sobj)
{
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[0] = true;
  }

  sobj->MeasurementRange = obj_MeasurementRange;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[1] = true;
  }

  sobj->Resolution = obj_Resolution;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[2] = true;
  }

  sobj->ConstantBias[0] = obj_ConstantBias[0];
  sobj->ConstantBias[1] = obj_ConstantBias[1];
  sobj->ConstantBias[2] = obj_ConstantBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[3] = true;
  }

  sobj->AxesMisalignment[0] = obj_AxesMisalignment[0];
  sobj->AxesMisalignment[1] = obj_AxesMisalignment[1];
  sobj->AxesMisalignment[2] = obj_AxesMisalignment[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[4] = true;
  }

  sobj->NoiseDensity[0] = obj_NoiseDensity[0];
  sobj->NoiseDensity[1] = obj_NoiseDensity[1];
  sobj->NoiseDensity[2] = obj_NoiseDensity[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[5] = true;
  }

  sobj->BiasInstability[0] = obj_BiasInstability[0];
  sobj->BiasInstability[1] = obj_BiasInstability[1];
  sobj->BiasInstability[2] = obj_BiasInstability[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[6] = true;
  }

  sobj->RandomWalk[0] = obj_RandomWalk[0];
  sobj->RandomWalk[1] = obj_RandomWalk[1];
  sobj->RandomWalk[2] = obj_RandomWalk[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[7] = true;
  }

  sobj->TemperatureBias[0] = obj_TemperatureBias[0];
  sobj->TemperatureBias[1] = obj_TemperatureBias[1];
  sobj->TemperatureBias[2] = obj_TemperatureBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[8] = true;
  }

  sobj->TemperatureScaleFactor[0] = obj_TemperatureScaleFactor[0];
  sobj->TemperatureScaleFactor[1] = obj_TemperatureScaleFactor[1];
  sobj->TemperatureScaleFactor[2] = obj_TemperatureScaleFactor[2];
}

static void IMUSensorParameters_updateSys_b(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3], const
  real_T obj_AccelerationBias[3], h_fusion_internal_GyroscopeSi_T *sobj)
{
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[0] = true;
  }

  sobj->AccelerationBias[0] = obj_AccelerationBias[0];
  sobj->AccelerationBias[1] = obj_AccelerationBias[1];
  sobj->AccelerationBias[2] = obj_AccelerationBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[1] = true;
  }

  sobj->MeasurementRange = obj_MeasurementRange;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[2] = true;
  }

  sobj->Resolution = obj_Resolution;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[3] = true;
  }

  sobj->ConstantBias[0] = obj_ConstantBias[0];
  sobj->ConstantBias[1] = obj_ConstantBias[1];
  sobj->ConstantBias[2] = obj_ConstantBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[4] = true;
  }

  sobj->AxesMisalignment[0] = obj_AxesMisalignment[0];
  sobj->AxesMisalignment[1] = obj_AxesMisalignment[1];
  sobj->AxesMisalignment[2] = obj_AxesMisalignment[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[5] = true;
  }

  sobj->NoiseDensity[0] = obj_NoiseDensity[0];
  sobj->NoiseDensity[1] = obj_NoiseDensity[1];
  sobj->NoiseDensity[2] = obj_NoiseDensity[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[6] = true;
  }

  sobj->BiasInstability[0] = obj_BiasInstability[0];
  sobj->BiasInstability[1] = obj_BiasInstability[1];
  sobj->BiasInstability[2] = obj_BiasInstability[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[7] = true;
  }

  sobj->RandomWalk[0] = obj_RandomWalk[0];
  sobj->RandomWalk[1] = obj_RandomWalk[1];
  sobj->RandomWalk[2] = obj_RandomWalk[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[8] = true;
  }

  sobj->TemperatureBias[0] = obj_TemperatureBias[0];
  sobj->TemperatureBias[1] = obj_TemperatureBias[1];
  sobj->TemperatureBias[2] = obj_TemperatureBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[9] = true;
  }

  sobj->TemperatureScaleFactor[0] = obj_TemperatureScaleFactor[0];
  sobj->TemperatureScaleFactor[1] = obj_TemperatureScaleFactor[1];
  sobj->TemperatureScaleFactor[2] = obj_TemperatureScaleFactor[2];
}

static void IMUSensorParameters_updateSy_b4(real_T obj_MeasurementRange, real_T
  obj_Resolution, const real_T obj_ConstantBias[3], const real_T
  obj_AxesMisalignment[3], const real_T obj_NoiseDensity[3], const real_T
  obj_BiasInstability[3], const real_T obj_RandomWalk[3], const real_T
  obj_TemperatureBias[3], const real_T obj_TemperatureScaleFactor[3],
  h_fusion_internal_Magnetomete_T *sobj)
{
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[0] = true;
  }

  sobj->MeasurementRange = obj_MeasurementRange;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[1] = true;
  }

  sobj->Resolution = obj_Resolution;
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[2] = true;
  }

  sobj->ConstantBias[0] = obj_ConstantBias[0];
  sobj->ConstantBias[1] = obj_ConstantBias[1];
  sobj->ConstantBias[2] = obj_ConstantBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[3] = true;
  }

  sobj->AxesMisalignment[0] = obj_AxesMisalignment[0];
  sobj->AxesMisalignment[1] = obj_AxesMisalignment[1];
  sobj->AxesMisalignment[2] = obj_AxesMisalignment[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[4] = true;
  }

  sobj->NoiseDensity[0] = obj_NoiseDensity[0];
  sobj->NoiseDensity[1] = obj_NoiseDensity[1];
  sobj->NoiseDensity[2] = obj_NoiseDensity[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[5] = true;
  }

  sobj->BiasInstability[0] = obj_BiasInstability[0];
  sobj->BiasInstability[1] = obj_BiasInstability[1];
  sobj->BiasInstability[2] = obj_BiasInstability[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[6] = true;
  }

  sobj->RandomWalk[0] = obj_RandomWalk[0];
  sobj->RandomWalk[1] = obj_RandomWalk[1];
  sobj->RandomWalk[2] = obj_RandomWalk[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[7] = true;
  }

  sobj->TemperatureBias[0] = obj_TemperatureBias[0];
  sobj->TemperatureBias[1] = obj_TemperatureBias[1];
  sobj->TemperatureBias[2] = obj_TemperatureBias[2];
  if (sobj->isInitialized == 1) {
    sobj->TunablePropsChanged = true;
    sobj->tunablePropertyChanged[8] = true;
  }

  sobj->TemperatureScaleFactor[0] = obj_TemperatureScaleFactor[0];
  sobj->TemperatureScaleFactor[1] = obj_TemperatureScaleFactor[1];
  sobj->TemperatureScaleFactor[2] = obj_TemperatureScaleFactor[2];
}

static boolean_T proc_control_node_vectorAny(const boolean_T x_data[], const
  int32_T x_size[2])
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x_size[1] - 1)) {
    if (!x_data[b_k]) {
      b_k++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

static void proc_co_genrand_uint32_vector_b(uint32_T mt[625], uint32_T u[2])
{
  for (proc_control_node_B.b_j_k = 0; proc_control_node_B.b_j_k < 2;
       proc_control_node_B.b_j_k++) {
    proc_control_node_B.mti = mt[624] + 1U;
    if (mt[624] + 1U >= 625U) {
      for (proc_control_node_B.b_kk = 0; proc_control_node_B.b_kk < 227;
           proc_control_node_B.b_kk++) {
        proc_control_node_B.y_cq = (mt[proc_control_node_B.b_kk + 1] &
          2147483647U) | (mt[proc_control_node_B.b_kk] & 2147483648U);
        if ((proc_control_node_B.y_cq & 1U) == 0U) {
          proc_control_node_B.y_cq >>= 1U;
        } else {
          proc_control_node_B.y_cq = proc_control_node_B.y_cq >> 1U ^
            2567483615U;
        }

        mt[proc_control_node_B.b_kk] = mt[proc_control_node_B.b_kk + 397] ^
          proc_control_node_B.y_cq;
      }

      for (proc_control_node_B.b_kk = 0; proc_control_node_B.b_kk < 396;
           proc_control_node_B.b_kk++) {
        proc_control_node_B.y_cq = (mt[proc_control_node_B.b_kk + 227] &
          2147483648U) | (mt[proc_control_node_B.b_kk + 228] & 2147483647U);
        if ((proc_control_node_B.y_cq & 1U) == 0U) {
          proc_control_node_B.y_cq >>= 1U;
        } else {
          proc_control_node_B.y_cq = proc_control_node_B.y_cq >> 1U ^
            2567483615U;
        }

        mt[proc_control_node_B.b_kk + 227] = mt[proc_control_node_B.b_kk] ^
          proc_control_node_B.y_cq;
      }

      proc_control_node_B.y_cq = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((proc_control_node_B.y_cq & 1U) == 0U) {
        proc_control_node_B.y_cq >>= 1U;
      } else {
        proc_control_node_B.y_cq = proc_control_node_B.y_cq >> 1U ^ 2567483615U;
      }

      mt[623] = mt[396] ^ proc_control_node_B.y_cq;
      proc_control_node_B.mti = 1U;
    }

    proc_control_node_B.y_cq = mt[static_cast<int32_T>(proc_control_node_B.mti)
      - 1];
    mt[624] = proc_control_node_B.mti;
    proc_control_node_B.y_cq ^= proc_control_node_B.y_cq >> 11U;
    proc_control_node_B.y_cq ^= proc_control_node_B.y_cq << 7U & 2636928640U;
    proc_control_node_B.y_cq ^= proc_control_node_B.y_cq << 15U & 4022730752U;
    u[proc_control_node_B.b_j_k] = proc_control_node_B.y_cq >> 18U ^
      proc_control_node_B.y_cq;
  }
}

static real_T proc_control_node_genrandu_b(uint32_T mt[625])
{
  real_T r;
  int32_T exitg1;
  boolean_T exitg2;

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  do {
    exitg1 = 0;
    proc_co_genrand_uint32_vector_b(mt, proc_control_node_B.b_u);
    r = (static_cast<real_T>(proc_control_node_B.b_u[0] >> 5U) * 6.7108864E+7 +
         static_cast<real_T>(proc_control_node_B.b_u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (r == 0.0) {
      if ((mt[624] >= 1U) && (mt[624] < 625U)) {
        proc_control_node_B.b_isvalid = false;
        proc_control_node_B.k_n = 0;
        exitg2 = false;
        while ((!exitg2) && (proc_control_node_B.k_n + 1 < 625)) {
          if (mt[proc_control_node_B.k_n] == 0U) {
            proc_control_node_B.k_n++;
          } else {
            proc_control_node_B.b_isvalid = true;
            exitg2 = true;
          }
        }
      } else {
        proc_control_node_B.b_isvalid = false;
      }

      if (!proc_control_node_B.b_isvalid) {
        proc_control_node_B.r_j = 67U;
        mt[0] = 67U;
        for (proc_control_node_B.k_n = 0; proc_control_node_B.k_n < 623;
             proc_control_node_B.k_n++) {
          proc_control_node_B.r_j = ((proc_control_node_B.r_j >> 30U ^
            proc_control_node_B.r_j) * 1812433253U + proc_control_node_B.k_n) +
            1U;
          mt[proc_control_node_B.k_n + 1] = proc_control_node_B.r_j;
        }

        mt[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

static real_T proc_contr_eml_rand_mt19937ar_b(uint32_T state[625])
{
  real_T r;
  static const real_T tmp[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  const real_T *fitab;
  int32_T exitg1;
  proc_control_node_B.xi[0] = 0.0;
  proc_control_node_B.xi[1] = 0.215241895984875;
  proc_control_node_B.xi[2] = 0.286174591792068;
  proc_control_node_B.xi[3] = 0.335737519214422;
  proc_control_node_B.xi[4] = 0.375121332878378;
  proc_control_node_B.xi[5] = 0.408389134611989;
  proc_control_node_B.xi[6] = 0.43751840220787;
  proc_control_node_B.xi[7] = 0.46363433679088;
  proc_control_node_B.xi[8] = 0.487443966139235;
  proc_control_node_B.xi[9] = 0.50942332960209;
  proc_control_node_B.xi[10] = 0.529909720661557;
  proc_control_node_B.xi[11] = 0.549151702327164;
  proc_control_node_B.xi[12] = 0.567338257053817;
  proc_control_node_B.xi[13] = 0.584616766106378;
  proc_control_node_B.xi[14] = 0.601104617755991;
  proc_control_node_B.xi[15] = 0.61689699000775;
  proc_control_node_B.xi[16] = 0.63207223638606;
  proc_control_node_B.xi[17] = 0.646695714894993;
  proc_control_node_B.xi[18] = 0.660822574244419;
  proc_control_node_B.xi[19] = 0.674499822837293;
  proc_control_node_B.xi[20] = 0.687767892795788;
  proc_control_node_B.xi[21] = 0.700661841106814;
  proc_control_node_B.xi[22] = 0.713212285190975;
  proc_control_node_B.xi[23] = 0.725446140909999;
  proc_control_node_B.xi[24] = 0.737387211434295;
  proc_control_node_B.xi[25] = 0.749056662017815;
  proc_control_node_B.xi[26] = 0.760473406430107;
  proc_control_node_B.xi[27] = 0.771654424224568;
  proc_control_node_B.xi[28] = 0.782615023307232;
  proc_control_node_B.xi[29] = 0.793369058840623;
  proc_control_node_B.xi[30] = 0.80392911698997;
  proc_control_node_B.xi[31] = 0.814306670135215;
  proc_control_node_B.xi[32] = 0.824512208752291;
  proc_control_node_B.xi[33] = 0.834555354086381;
  proc_control_node_B.xi[34] = 0.844444954909153;
  proc_control_node_B.xi[35] = 0.854189171008163;
  proc_control_node_B.xi[36] = 0.863795545553308;
  proc_control_node_B.xi[37] = 0.87327106808886;
  proc_control_node_B.xi[38] = 0.882622229585165;
  proc_control_node_B.xi[39] = 0.891855070732941;
  proc_control_node_B.xi[40] = 0.900975224461221;
  proc_control_node_B.xi[41] = 0.909987953496718;
  proc_control_node_B.xi[42] = 0.91889818364959;
  proc_control_node_B.xi[43] = 0.927710533401999;
  proc_control_node_B.xi[44] = 0.936429340286575;
  proc_control_node_B.xi[45] = 0.945058684468165;
  proc_control_node_B.xi[46] = 0.953602409881086;
  proc_control_node_B.xi[47] = 0.96206414322304;
  proc_control_node_B.xi[48] = 0.970447311064224;
  proc_control_node_B.xi[49] = 0.978755155294224;
  proc_control_node_B.xi[50] = 0.986990747099062;
  proc_control_node_B.xi[51] = 0.99515699963509;
  proc_control_node_B.xi[52] = 1.00325667954467;
  proc_control_node_B.xi[53] = 1.01129241744;
  proc_control_node_B.xi[54] = 1.01926671746548;
  proc_control_node_B.xi[55] = 1.02718196603564;
  proc_control_node_B.xi[56] = 1.03504043983344;
  proc_control_node_B.xi[57] = 1.04284431314415;
  proc_control_node_B.xi[58] = 1.05059566459093;
  proc_control_node_B.xi[59] = 1.05829648333067;
  proc_control_node_B.xi[60] = 1.06594867476212;
  proc_control_node_B.xi[61] = 1.07355406579244;
  proc_control_node_B.xi[62] = 1.0811144097034;
  proc_control_node_B.xi[63] = 1.08863139065398;
  proc_control_node_B.xi[64] = 1.09610662785202;
  proc_control_node_B.xi[65] = 1.10354167942464;
  proc_control_node_B.xi[66] = 1.11093804601357;
  proc_control_node_B.xi[67] = 1.11829717411934;
  proc_control_node_B.xi[68] = 1.12562045921553;
  proc_control_node_B.xi[69] = 1.13290924865253;
  proc_control_node_B.xi[70] = 1.14016484436815;
  proc_control_node_B.xi[71] = 1.14738850542085;
  proc_control_node_B.xi[72] = 1.15458145035993;
  proc_control_node_B.xi[73] = 1.16174485944561;
  proc_control_node_B.xi[74] = 1.16887987673083;
  proc_control_node_B.xi[75] = 1.17598761201545;
  proc_control_node_B.xi[76] = 1.18306914268269;
  proc_control_node_B.xi[77] = 1.19012551542669;
  proc_control_node_B.xi[78] = 1.19715774787944;
  proc_control_node_B.xi[79] = 1.20416683014438;
  proc_control_node_B.xi[80] = 1.2111537262437;
  proc_control_node_B.xi[81] = 1.21811937548548;
  proc_control_node_B.xi[82] = 1.22506469375653;
  proc_control_node_B.xi[83] = 1.23199057474614;
  proc_control_node_B.xi[84] = 1.23889789110569;
  proc_control_node_B.xi[85] = 1.24578749554863;
  proc_control_node_B.xi[86] = 1.2526602218949;
  proc_control_node_B.xi[87] = 1.25951688606371;
  proc_control_node_B.xi[88] = 1.26635828701823;
  proc_control_node_B.xi[89] = 1.27318520766536;
  proc_control_node_B.xi[90] = 1.27999841571382;
  proc_control_node_B.xi[91] = 1.28679866449324;
  proc_control_node_B.xi[92] = 1.29358669373695;
  proc_control_node_B.xi[93] = 1.30036323033084;
  proc_control_node_B.xi[94] = 1.30712898903073;
  proc_control_node_B.xi[95] = 1.31388467315022;
  proc_control_node_B.xi[96] = 1.32063097522106;
  proc_control_node_B.xi[97] = 1.32736857762793;
  proc_control_node_B.xi[98] = 1.33409815321936;
  proc_control_node_B.xi[99] = 1.3408203658964;
  proc_control_node_B.xi[100] = 1.34753587118059;
  proc_control_node_B.xi[101] = 1.35424531676263;
  proc_control_node_B.xi[102] = 1.36094934303328;
  proc_control_node_B.xi[103] = 1.36764858359748;
  proc_control_node_B.xi[104] = 1.37434366577317;
  proc_control_node_B.xi[105] = 1.38103521107586;
  proc_control_node_B.xi[106] = 1.38772383568998;
  proc_control_node_B.xi[107] = 1.39441015092814;
  proc_control_node_B.xi[108] = 1.40109476367925;
  proc_control_node_B.xi[109] = 1.4077782768464;
  proc_control_node_B.xi[110] = 1.41446128977547;
  proc_control_node_B.xi[111] = 1.42114439867531;
  proc_control_node_B.xi[112] = 1.42782819703026;
  proc_control_node_B.xi[113] = 1.43451327600589;
  proc_control_node_B.xi[114] = 1.44120022484872;
  proc_control_node_B.xi[115] = 1.44788963128058;
  proc_control_node_B.xi[116] = 1.45458208188841;
  proc_control_node_B.xi[117] = 1.46127816251028;
  proc_control_node_B.xi[118] = 1.46797845861808;
  proc_control_node_B.xi[119] = 1.47468355569786;
  proc_control_node_B.xi[120] = 1.48139403962819;
  proc_control_node_B.xi[121] = 1.48811049705745;
  proc_control_node_B.xi[122] = 1.49483351578049;
  proc_control_node_B.xi[123] = 1.50156368511546;
  proc_control_node_B.xi[124] = 1.50830159628131;
  proc_control_node_B.xi[125] = 1.51504784277671;
  proc_control_node_B.xi[126] = 1.521803020761;
  proc_control_node_B.xi[127] = 1.52856772943771;
  proc_control_node_B.xi[128] = 1.53534257144151;
  proc_control_node_B.xi[129] = 1.542128153229;
  proc_control_node_B.xi[130] = 1.54892508547417;
  proc_control_node_B.xi[131] = 1.55573398346918;
  proc_control_node_B.xi[132] = 1.56255546753104;
  proc_control_node_B.xi[133] = 1.56939016341512;
  proc_control_node_B.xi[134] = 1.57623870273591;
  proc_control_node_B.xi[135] = 1.58310172339603;
  proc_control_node_B.xi[136] = 1.58997987002419;
  proc_control_node_B.xi[137] = 1.59687379442279;
  proc_control_node_B.xi[138] = 1.60378415602609;
  proc_control_node_B.xi[139] = 1.61071162236983;
  proc_control_node_B.xi[140] = 1.61765686957301;
  proc_control_node_B.xi[141] = 1.62462058283303;
  proc_control_node_B.xi[142] = 1.63160345693487;
  proc_control_node_B.xi[143] = 1.63860619677555;
  proc_control_node_B.xi[144] = 1.64562951790478;
  proc_control_node_B.xi[145] = 1.65267414708306;
  proc_control_node_B.xi[146] = 1.65974082285818;
  proc_control_node_B.xi[147] = 1.66683029616166;
  proc_control_node_B.xi[148] = 1.67394333092612;
  proc_control_node_B.xi[149] = 1.68108070472517;
  proc_control_node_B.xi[150] = 1.68824320943719;
  proc_control_node_B.xi[151] = 1.69543165193456;
  proc_control_node_B.xi[152] = 1.70264685479992;
  proc_control_node_B.xi[153] = 1.7098896570713;
  proc_control_node_B.xi[154] = 1.71716091501782;
  proc_control_node_B.xi[155] = 1.72446150294804;
  proc_control_node_B.xi[156] = 1.73179231405296;
  proc_control_node_B.xi[157] = 1.73915426128591;
  proc_control_node_B.xi[158] = 1.74654827828172;
  proc_control_node_B.xi[159] = 1.75397532031767;
  proc_control_node_B.xi[160] = 1.76143636531891;
  proc_control_node_B.xi[161] = 1.76893241491127;
  proc_control_node_B.xi[162] = 1.77646449552452;
  proc_control_node_B.xi[163] = 1.78403365954944;
  proc_control_node_B.xi[164] = 1.79164098655216;
  proc_control_node_B.xi[165] = 1.79928758454972;
  proc_control_node_B.xi[166] = 1.80697459135082;
  proc_control_node_B.xi[167] = 1.81470317596628;
  proc_control_node_B.xi[168] = 1.82247454009388;
  proc_control_node_B.xi[169] = 1.83028991968276;
  proc_control_node_B.xi[170] = 1.83815058658281;
  proc_control_node_B.xi[171] = 1.84605785028518;
  proc_control_node_B.xi[172] = 1.8540130597602;
  proc_control_node_B.xi[173] = 1.86201760539967;
  proc_control_node_B.xi[174] = 1.87007292107127;
  proc_control_node_B.xi[175] = 1.878180486293;
  proc_control_node_B.xi[176] = 1.88634182853678;
  proc_control_node_B.xi[177] = 1.8945585256707;
  proc_control_node_B.xi[178] = 1.90283220855043;
  proc_control_node_B.xi[179] = 1.91116456377125;
  proc_control_node_B.xi[180] = 1.91955733659319;
  proc_control_node_B.xi[181] = 1.92801233405266;
  proc_control_node_B.xi[182] = 1.93653142827569;
  proc_control_node_B.xi[183] = 1.94511656000868;
  proc_control_node_B.xi[184] = 1.95376974238465;
  proc_control_node_B.xi[185] = 1.96249306494436;
  proc_control_node_B.xi[186] = 1.97128869793366;
  proc_control_node_B.xi[187] = 1.98015889690048;
  proc_control_node_B.xi[188] = 1.98910600761744;
  proc_control_node_B.xi[189] = 1.99813247135842;
  proc_control_node_B.xi[190] = 2.00724083056053;
  proc_control_node_B.xi[191] = 2.0164337349062;
  proc_control_node_B.xi[192] = 2.02571394786385;
  proc_control_node_B.xi[193] = 2.03508435372962;
  proc_control_node_B.xi[194] = 2.04454796521753;
  proc_control_node_B.xi[195] = 2.05410793165065;
  proc_control_node_B.xi[196] = 2.06376754781173;
  proc_control_node_B.xi[197] = 2.07353026351874;
  proc_control_node_B.xi[198] = 2.0833996939983;
  proc_control_node_B.xi[199] = 2.09337963113879;
  proc_control_node_B.xi[200] = 2.10347405571488;
  proc_control_node_B.xi[201] = 2.11368715068665;
  proc_control_node_B.xi[202] = 2.12402331568952;
  proc_control_node_B.xi[203] = 2.13448718284602;
  proc_control_node_B.xi[204] = 2.14508363404789;
  proc_control_node_B.xi[205] = 2.15581781987674;
  proc_control_node_B.xi[206] = 2.16669518035431;
  proc_control_node_B.xi[207] = 2.17772146774029;
  proc_control_node_B.xi[208] = 2.18890277162636;
  proc_control_node_B.xi[209] = 2.20024554661128;
  proc_control_node_B.xi[210] = 2.21175664288416;
  proc_control_node_B.xi[211] = 2.22344334009251;
  proc_control_node_B.xi[212] = 2.23531338492992;
  proc_control_node_B.xi[213] = 2.24737503294739;
  proc_control_node_B.xi[214] = 2.25963709517379;
  proc_control_node_B.xi[215] = 2.27210899022838;
  proc_control_node_B.xi[216] = 2.28480080272449;
  proc_control_node_B.xi[217] = 2.29772334890286;
  proc_control_node_B.xi[218] = 2.31088825060137;
  proc_control_node_B.xi[219] = 2.32430801887113;
  proc_control_node_B.xi[220] = 2.33799614879653;
  proc_control_node_B.xi[221] = 2.35196722737914;
  proc_control_node_B.xi[222] = 2.36623705671729;
  proc_control_node_B.xi[223] = 2.38082279517208;
  proc_control_node_B.xi[224] = 2.39574311978193;
  proc_control_node_B.xi[225] = 2.41101841390112;
  proc_control_node_B.xi[226] = 2.42667098493715;
  proc_control_node_B.xi[227] = 2.44272531820036;
  proc_control_node_B.xi[228] = 2.4592083743347;
  proc_control_node_B.xi[229] = 2.47614993967052;
  proc_control_node_B.xi[230] = 2.49358304127105;
  proc_control_node_B.xi[231] = 2.51154444162669;
  proc_control_node_B.xi[232] = 2.53007523215985;
  proc_control_node_B.xi[233] = 2.54922155032478;
  proc_control_node_B.xi[234] = 2.56903545268184;
  proc_control_node_B.xi[235] = 2.58957598670829;
  proc_control_node_B.xi[236] = 2.61091051848882;
  proc_control_node_B.xi[237] = 2.63311639363158;
  proc_control_node_B.xi[238] = 2.65628303757674;
  proc_control_node_B.xi[239] = 2.68051464328574;
  proc_control_node_B.xi[240] = 2.70593365612306;
  proc_control_node_B.xi[241] = 2.73268535904401;
  proc_control_node_B.xi[242] = 2.76094400527999;
  proc_control_node_B.xi[243] = 2.79092117400193;
  proc_control_node_B.xi[244] = 2.82287739682644;
  proc_control_node_B.xi[245] = 2.85713873087322;
  proc_control_node_B.xi[246] = 2.89412105361341;
  proc_control_node_B.xi[247] = 2.93436686720889;
  proc_control_node_B.xi[248] = 2.97860327988184;
  proc_control_node_B.xi[249] = 3.02783779176959;
  proc_control_node_B.xi[250] = 3.08352613200214;
  proc_control_node_B.xi[251] = 3.147889289518;
  proc_control_node_B.xi[252] = 3.2245750520478;
  proc_control_node_B.xi[253] = 3.32024473383983;
  proc_control_node_B.xi[254] = 3.44927829856143;
  proc_control_node_B.xi[255] = 3.65415288536101;
  proc_control_node_B.xi[256] = 3.91075795952492;
  fitab = &tmp[0];
  do {
    exitg1 = 0;
    proc_co_genrand_uint32_vector_b(state, proc_control_node_B.u32);
    proc_control_node_B.i_c = static_cast<int32_T>((proc_control_node_B.u32[1] >>
      24U) + 1U);
    r = ((static_cast<real_T>(proc_control_node_B.u32[0] >> 3U) * 1.6777216E+7 +
          static_cast<real_T>(static_cast<int32_T>(proc_control_node_B.u32[1]) &
           16777215)) * 2.2204460492503131E-16 - 1.0) *
      proc_control_node_B.xi[proc_control_node_B.i_c];
    if (fabs(r) <= proc_control_node_B.xi[proc_control_node_B.i_c - 1]) {
      exitg1 = 1;
    } else if (proc_control_node_B.i_c < 256) {
      proc_control_node_B.x_k = proc_control_node_genrandu_b(state);
      if ((fitab[proc_control_node_B.i_c - 1] - fitab[proc_control_node_B.i_c]) *
          proc_control_node_B.x_k + fitab[proc_control_node_B.i_c] < exp(-0.5 *
           r * r)) {
        exitg1 = 1;
      }
    } else {
      do {
        proc_control_node_B.x_k = proc_control_node_genrandu_b(state);
        proc_control_node_B.x_k = log(proc_control_node_B.x_k) *
          0.273661237329758;
        proc_control_node_B.d_u = proc_control_node_genrandu_b(state);
      } while (!(-2.0 * log(proc_control_node_B.d_u) > proc_control_node_B.x_k *
                 proc_control_node_B.x_k));

      if (r < 0.0) {
        r = proc_control_node_B.x_k - 3.65415288536101;
      } else {
        r = 3.65415288536101 - proc_control_node_B.x_k;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

static void IMUSensorBase_stepRandomStream(fusion_simulink_imuSensor_pro_T *obj,
  real_T whiteNoise[27])
{
  for (proc_control_node_B.b_colIdx = 0; proc_control_node_B.b_colIdx < 27;
       proc_control_node_B.b_colIdx++) {
    whiteNoise[proc_control_node_B.b_colIdx] = proc_contr_eml_rand_mt19937ar_b
      (obj->pStreamState);
  }
}

static void proc_control_node_filter(real_T b, real_T a[2], const real_T x[3],
  const real_T zi[3], real_T y[3], real_T zf[3])
{
  if ((!rtIsInf(a[0])) && (!rtIsNaN(a[0])) && (!(a[0] == 0.0)) && (a[0] != 1.0))
  {
    b /= a[0];
    a[1] /= a[0];
  }

  y[0] = x[0] * b + zi[0];
  zf[0] = -y[0] * a[1];
  y[1] = x[1] * b + zi[1];
  zf[1] = -y[1] * a[1];
  y[2] = x[2] * b + zi[2];
  zf[2] = -y[2] * a[1];
}

static void proc_control__SystemCore_step_b(h_fusion_internal_Acceleromet_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[9], const real_T
  varargin_3[9], real_T varargout_1[3])
{
  static const int8_T tmp[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  if (obj->isInitialized != 1) {
    obj->isInitialized = 1;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
         proc_control_node_B.k_c++) {
      proc_control_node_B.b_I_c[proc_control_node_B.k_c] = 0;
    }

    proc_control_node_B.b_I_c[0] = 1;
    proc_control_node_B.b_I_c[4] = 1;
    proc_control_node_B.b_I_c[8] = 1;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
         proc_control_node_B.k_c++) {
      proc_control_node_B.a_j[proc_control_node_B.k_c] =
        tmp[proc_control_node_B.k_c];
    }

    proc_control_node_B.temperatureDrift_f[0] = obj->AxesMisalignment[0] / 100.0;
    proc_control_node_B.temperatureDrift_f[1] = obj->AxesMisalignment[1] / 100.0;
    proc_control_node_B.temperatureDrift_f[2] = obj->AxesMisalignment[2] / 100.0;
    proc_control_node_B.nx_f = 0;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
         proc_control_node_B.k_c++) {
      proc_control_node_B.c_j[proc_control_node_B.nx_f] =
        proc_control_node_B.a_j[proc_control_node_B.nx_f] *
        proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
      proc_control_node_B.c_j[proc_control_node_B.nx_f + 1] =
        proc_control_node_B.a_j[proc_control_node_B.nx_f + 1] *
        proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
      proc_control_node_B.c_j[proc_control_node_B.nx_f + 2] =
        proc_control_node_B.a_j[proc_control_node_B.nx_f + 2] *
        proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
      proc_control_node_B.nx_f += 3;
    }

    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
         proc_control_node_B.k_c++) {
      obj->pGain[proc_control_node_B.k_c] = static_cast<real_T>
        (proc_control_node_B.b_I_c[proc_control_node_B.k_c]) +
        proc_control_node_B.c_j[proc_control_node_B.k_c];
    }

    obj->pBiasInstFilterNum = 1.0;
    obj->pBiasInstFilterDen[0] = 1.0;
    obj->pBiasInstFilterDen[1] = -0.5;
    obj->pBiasInstFilterStates[0] = 0.0;
    obj->pBiasInstFilterStates[1] = 0.0;
    obj->pBiasInstFilterStates[2] = 0.0;
    obj->pStdDevBiasInst[0] = obj->BiasInstability[0];
    obj->pStdDevBiasInst[1] = obj->BiasInstability[1];
    obj->pStdDevBiasInst[2] = obj->BiasInstability[2];
    obj->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj->NoiseDensity[0];
    obj->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj->NoiseDensity[1];
    obj->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj->NoiseDensity[2];
    obj->pRandWalkFilterStates[0] = 0.0;
    obj->pRandWalkFilterStates[1] = 0.0;
    obj->pRandWalkFilterStates[2] = 0.0;
    obj->pStdDevRandWalk[0] = obj->RandomWalk[0] / 5.4772255750516612;
    obj->pStdDevRandWalk[1] = obj->RandomWalk[1] / 5.4772255750516612;
    obj->pStdDevRandWalk[2] = obj->RandomWalk[2] / 5.4772255750516612;
    obj->pRefFrame = &obj->_pobj0;
    obj->TunablePropsChanged = false;
    obj->pBiasInstFilterStates[0] = 0.0;
    obj->pBiasInstFilterStates[1] = 0.0;
    obj->pBiasInstFilterStates[2] = 0.0;
    obj->pRandWalkFilterStates[0] = 0.0;
    obj->pRandWalkFilterStates[1] = 0.0;
    obj->pRandWalkFilterStates[2] = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    proc_control_node_B.flag_i = obj->tunablePropertyChanged[3];
    if (proc_control_node_B.flag_i) {
      for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
           proc_control_node_B.k_c++) {
        proc_control_node_B.b_I_c[proc_control_node_B.k_c] = 0;
      }

      proc_control_node_B.b_I_c[0] = 1;
      proc_control_node_B.b_I_c[4] = 1;
      proc_control_node_B.b_I_c[8] = 1;
      for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
           proc_control_node_B.k_c++) {
        proc_control_node_B.a_j[proc_control_node_B.k_c] =
          tmp[proc_control_node_B.k_c];
      }

      proc_control_node_B.temperatureDrift_f[0] = obj->AxesMisalignment[0] /
        100.0;
      proc_control_node_B.temperatureDrift_f[1] = obj->AxesMisalignment[1] /
        100.0;
      proc_control_node_B.temperatureDrift_f[2] = obj->AxesMisalignment[2] /
        100.0;
      proc_control_node_B.nx_f = 0;
      for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
           proc_control_node_B.k_c++) {
        proc_control_node_B.c_j[proc_control_node_B.nx_f] =
          proc_control_node_B.a_j[proc_control_node_B.nx_f] *
          proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
        proc_control_node_B.c_j[proc_control_node_B.nx_f + 1] =
          proc_control_node_B.a_j[proc_control_node_B.nx_f + 1] *
          proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
        proc_control_node_B.c_j[proc_control_node_B.nx_f + 2] =
          proc_control_node_B.a_j[proc_control_node_B.nx_f + 2] *
          proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c];
        proc_control_node_B.nx_f += 3;
      }

      for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
           proc_control_node_B.k_c++) {
        obj->pGain[proc_control_node_B.k_c] = static_cast<real_T>
          (proc_control_node_B.b_I_c[proc_control_node_B.k_c]) +
          proc_control_node_B.c_j[proc_control_node_B.k_c];
      }
    }

    proc_control_node_B.flag_i = obj->tunablePropertyChanged[4];
    if (proc_control_node_B.flag_i) {
      obj->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj->NoiseDensity[0];
      obj->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj->NoiseDensity[1];
      obj->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj->NoiseDensity[2];
    }

    proc_control_node_B.flag_i = obj->tunablePropertyChanged[5];
    if (proc_control_node_B.flag_i) {
      obj->pStdDevBiasInst[0] = obj->BiasInstability[0];
      obj->pStdDevBiasInst[1] = obj->BiasInstability[1];
      obj->pStdDevBiasInst[2] = obj->BiasInstability[2];
    }

    proc_control_node_B.flag_i = obj->tunablePropertyChanged[6];
    if (proc_control_node_B.flag_i) {
      obj->pStdDevRandWalk[0] = obj->RandomWalk[0] / 5.4772255750516612;
      obj->pStdDevRandWalk[1] = obj->RandomWalk[1] / 5.4772255750516612;
      obj->pStdDevRandWalk[2] = obj->RandomWalk[2] / 5.4772255750516612;
    }

    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 10;
         proc_control_node_B.k_c++) {
      obj->tunablePropertyChanged[proc_control_node_B.k_c] = false;
    }
  }

  for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 9;
       proc_control_node_B.k_c++) {
    proc_control_node_B.a_j[proc_control_node_B.k_c] = obj->
      pGain[proc_control_node_B.k_c];
  }

  proc_control_node_B.B_idx_0 = -varargin_1[0];
  proc_control_node_B.B_idx_1 = -varargin_1[1];
  proc_control_node_B.B_idx_2 = -varargin_1[2] + 9.81;
  for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
       proc_control_node_B.k_c++) {
    proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c] = 0.0;
    proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c] +=
      varargin_2[proc_control_node_B.k_c] * proc_control_node_B.B_idx_0;
    proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c] +=
      varargin_2[proc_control_node_B.k_c + 3] * proc_control_node_B.B_idx_1;
    proc_control_node_B.temperatureDrift_f[proc_control_node_B.k_c] +=
      varargin_2[proc_control_node_B.k_c + 6] * proc_control_node_B.B_idx_2;
  }

  for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
       proc_control_node_B.k_c++) {
    proc_control_node_B.y_c[proc_control_node_B.k_c] = 0.0;
    proc_control_node_B.y_c[proc_control_node_B.k_c] +=
      proc_control_node_B.a_j[proc_control_node_B.k_c] *
      proc_control_node_B.temperatureDrift_f[0];
    proc_control_node_B.y_c[proc_control_node_B.k_c] +=
      proc_control_node_B.a_j[proc_control_node_B.k_c + 3] *
      proc_control_node_B.temperatureDrift_f[1];
    proc_control_node_B.y_c[proc_control_node_B.k_c] +=
      proc_control_node_B.a_j[proc_control_node_B.k_c + 6] *
      proc_control_node_B.temperatureDrift_f[2];
  }

  proc_control_node_B.temperatureDrift_f[0] = obj->ConstantBias[0];
  proc_control_node_B.temperatureDrift_f[1] = obj->ConstantBias[1];
  proc_control_node_B.temperatureDrift_f[2] = obj->ConstantBias[2];
  proc_control_node_B.B_idx_0 = proc_control_node_B.y_c[0] +
    proc_control_node_B.temperatureDrift_f[0];
  proc_control_node_B.B_idx_1 = proc_control_node_B.y_c[1] +
    proc_control_node_B.temperatureDrift_f[1];
  proc_control_node_B.B_idx_2 = proc_control_node_B.y_c[2] +
    proc_control_node_B.temperatureDrift_f[2];
  proc_control_node_B.temperatureDrift_f[0] = obj->pStdDevBiasInst[0];
  proc_control_node_B.temperatureDrift_f[1] = obj->pStdDevBiasInst[1];
  proc_control_node_B.temperatureDrift_f[2] = obj->pStdDevBiasInst[2];
  proc_control_node_B.a_m[0] = varargin_3[0] *
    proc_control_node_B.temperatureDrift_f[0];
  proc_control_node_B.a_m[1] = varargin_3[1] *
    proc_control_node_B.temperatureDrift_f[1];
  proc_control_node_B.a_m[2] = varargin_3[2] *
    proc_control_node_B.temperatureDrift_f[2];
  for (proc_control_node_B.i23 = 0; proc_control_node_B.i23 < 2;
       proc_control_node_B.i23++) {
    proc_control_node_B.obj_a[proc_control_node_B.i23] = obj->
      pBiasInstFilterDen[proc_control_node_B.i23];
  }

  proc_control_node_filter(obj->pBiasInstFilterNum, proc_control_node_B.obj_a,
    proc_control_node_B.a_m, obj->pBiasInstFilterStates, proc_control_node_B.y_c,
    proc_control_node_B.temperatureDrift_f);
  obj->pBiasInstFilterStates[0] = proc_control_node_B.temperatureDrift_f[0];
  obj->pBiasInstFilterStates[1] = proc_control_node_B.temperatureDrift_f[1];
  obj->pBiasInstFilterStates[2] = proc_control_node_B.temperatureDrift_f[2];
  proc_control_node_B.temperatureDrift_f[0] = obj->pStdDevWhiteNoise[0];
  proc_control_node_B.temperatureDrift_f[1] = obj->pStdDevWhiteNoise[1];
  proc_control_node_B.temperatureDrift_f[2] = obj->pStdDevWhiteNoise[2];
  proc_control_node_B.whiteNoiseDrift_idx_0 =
    proc_control_node_B.temperatureDrift_f[0] * varargin_3[3];
  proc_control_node_B.whiteNoiseDrift_idx_1 =
    proc_control_node_B.temperatureDrift_f[1] * varargin_3[4];
  proc_control_node_B.whiteNoiseDrift_idx_2 =
    proc_control_node_B.temperatureDrift_f[2] * varargin_3[5];
  proc_control_node_B.temperatureDrift_f[0] = obj->pStdDevRandWalk[0];
  proc_control_node_B.temperatureDrift_f[1] = obj->pStdDevRandWalk[1];
  proc_control_node_B.temperatureDrift_f[2] = obj->pStdDevRandWalk[2];
  proc_control_node_B.x_idx_0 = obj->pRandWalkFilterStates[0];
  proc_control_node_B.x_idx_2 = obj->pRandWalkFilterStates[1];
  proc_control_node_B.x_idx_4 = obj->pRandWalkFilterStates[2];
  proc_control_node_B.x_idx_0 += proc_control_node_B.temperatureDrift_f[0] *
    varargin_3[6];
  proc_control_node_B.x_idx_2 += proc_control_node_B.temperatureDrift_f[1] *
    varargin_3[7];
  proc_control_node_B.x_idx_4 += proc_control_node_B.temperatureDrift_f[2] *
    varargin_3[8];
  obj->pRandWalkFilterStates[0] = proc_control_node_B.x_idx_0;
  obj->pRandWalkFilterStates[1] = proc_control_node_B.x_idx_2;
  obj->pRandWalkFilterStates[2] = proc_control_node_B.x_idx_4;
  proc_control_node_B.obj_c = obj->Temperature - 25.0;
  proc_control_node_B.a_m[0] = proc_control_node_B.obj_c * obj->TemperatureBias
    [0];
  proc_control_node_B.a_m[1] = proc_control_node_B.obj_c * obj->TemperatureBias
    [1];
  proc_control_node_B.a_m[2] = proc_control_node_B.obj_c * obj->TemperatureBias
    [2];
  proc_control_node_B.temperatureDrift_f[0] = proc_control_node_B.a_m[0];
  proc_control_node_B.temperatureDrift_f[1] = proc_control_node_B.a_m[1];
  proc_control_node_B.temperatureDrift_f[2] = proc_control_node_B.a_m[2];
  proc_control_node_B.obj_c = (obj->Temperature - 25.0) * 0.01;
  proc_control_node_B.a_m[0] = proc_control_node_B.obj_c *
    obj->TemperatureScaleFactor[0] + 1.0;
  proc_control_node_B.a_m[1] = proc_control_node_B.obj_c *
    obj->TemperatureScaleFactor[1] + 1.0;
  proc_control_node_B.a_m[2] = proc_control_node_B.obj_c *
    obj->TemperatureScaleFactor[2] + 1.0;
  varargout_1[0] = ((((proc_control_node_B.whiteNoiseDrift_idx_0 +
                       proc_control_node_B.y_c[0]) + proc_control_node_B.x_idx_0)
                     + proc_control_node_B.temperatureDrift_f[0]) +
                    proc_control_node_B.B_idx_0) * proc_control_node_B.a_m[0];
  varargout_1[1] = ((((proc_control_node_B.whiteNoiseDrift_idx_1 +
                       proc_control_node_B.y_c[1]) + proc_control_node_B.x_idx_2)
                     + proc_control_node_B.temperatureDrift_f[1]) +
                    proc_control_node_B.B_idx_1) * proc_control_node_B.a_m[1];
  varargout_1[2] = ((((proc_control_node_B.whiteNoiseDrift_idx_2 +
                       proc_control_node_B.y_c[2]) + proc_control_node_B.x_idx_4)
                     + proc_control_node_B.temperatureDrift_f[2]) +
                    proc_control_node_B.B_idx_2) * proc_control_node_B.a_m[2];
  proc_control_node_B.B_idx_0 = obj->MeasurementRange;
  if (!rtIsInf(proc_control_node_B.B_idx_0)) {
    proc_control_node_B.B_idx_0 = obj->MeasurementRange;
    proc_control_node_B.B_idx_1 = fabs(varargout_1[0]);
    proc_control_node_B.d_j[0] = (proc_control_node_B.B_idx_1 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.B_idx_2 = fabs(varargout_1[1]);
    proc_control_node_B.d_j[1] = (proc_control_node_B.B_idx_2 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.whiteNoiseDrift_idx_0 = fabs(varargout_1[2]);
    proc_control_node_B.d_j[2] = (proc_control_node_B.whiteNoiseDrift_idx_0 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.nx_f = 0;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
         proc_control_node_B.k_c++) {
      if (proc_control_node_B.d_j[proc_control_node_B.k_c]) {
        proc_control_node_B.b_data_m[proc_control_node_B.nx_f] =
          static_cast<int8_T>(proc_control_node_B.k_c + 1);
        proc_control_node_B.nx_f++;
      }
    }

    proc_control_node_B.d_j[0] = (proc_control_node_B.B_idx_1 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.d_j[1] = (proc_control_node_B.B_idx_2 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.d_j[2] = (proc_control_node_B.whiteNoiseDrift_idx_0 >
      proc_control_node_B.B_idx_0);
    proc_control_node_B.nx_f = 0;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
         proc_control_node_B.k_c++) {
      if (proc_control_node_B.d_j[proc_control_node_B.k_c]) {
        proc_control_node_B.nx_f++;
      }
    }

    proc_control_node_B.f_size_idx_1_n = proc_control_node_B.nx_f;
    proc_control_node_B.nx_f = 0;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c < 3;
         proc_control_node_B.k_c++) {
      if (proc_control_node_B.d_j[proc_control_node_B.k_c]) {
        proc_control_node_B.f_data_o[proc_control_node_B.nx_f] =
          static_cast<int8_T>(proc_control_node_B.k_c + 1);
        proc_control_node_B.nx_f++;
      }
    }

    proc_control_node_B.nx_f = proc_control_node_B.f_size_idx_1_n - 1;
    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c <=
         proc_control_node_B.nx_f; proc_control_node_B.k_c++) {
      proc_control_node_B.b_x_data_tmp_h = proc_control_node_B.k_c;
      proc_control_node_B.temperatureDrift_f[proc_control_node_B.b_x_data_tmp_h]
        =
        varargout_1[proc_control_node_B.f_data_o[proc_control_node_B.b_x_data_tmp_h]
        - 1];
    }

    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c <=
         proc_control_node_B.nx_f; proc_control_node_B.k_c++) {
      proc_control_node_B.b_x_data_tmp_h = proc_control_node_B.k_c;
      proc_control_node_B.B_idx_1 =
        proc_control_node_B.temperatureDrift_f[proc_control_node_B.b_x_data_tmp_h];
      if (proc_control_node_B.B_idx_1 < 0.0) {
        proc_control_node_B.B_idx_1 = -1.0;
      } else if (proc_control_node_B.B_idx_1 > 0.0) {
        proc_control_node_B.B_idx_1 = 1.0;
      } else if (proc_control_node_B.B_idx_1 == 0.0) {
        proc_control_node_B.B_idx_1 = 0.0;
      } else {
        proc_control_node_B.B_idx_1 = (rtNaN);
      }

      proc_control_node_B.temperatureDrift_f[proc_control_node_B.b_x_data_tmp_h]
        = proc_control_node_B.B_idx_1;
    }

    for (proc_control_node_B.k_c = 0; proc_control_node_B.k_c <
         proc_control_node_B.f_size_idx_1_n; proc_control_node_B.k_c++) {
      proc_control_node_B.nx_f = proc_control_node_B.k_c;
      varargout_1[proc_control_node_B.b_data_m[proc_control_node_B.nx_f] - 1] =
        proc_control_node_B.temperatureDrift_f[proc_control_node_B.nx_f] *
        proc_control_node_B.B_idx_0;
    }
  }

  if (obj->Resolution != 0.0) {
    proc_control_node_B.B_idx_0 = obj->Resolution;
    varargout_1[0] = rt_roundd_snf(varargout_1[0] / proc_control_node_B.B_idx_0);
    varargout_1[1] = rt_roundd_snf(varargout_1[1] / proc_control_node_B.B_idx_0);
    varargout_1[2] = rt_roundd_snf(varargout_1[2] / proc_control_node_B.B_idx_0);
    varargout_1[0] *= proc_control_node_B.B_idx_0;
    varargout_1[1] *= proc_control_node_B.B_idx_0;
    varargout_1[2] *= proc_control_node_B.B_idx_0;
  }
}

static void proc_control_SystemCore_step_b4(h_fusion_internal_GyroscopeSi_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[9], const real_T varargin_4[9], real_T varargout_1[3])
{
  static const int8_T tmp[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  if (obj->isInitialized != 1) {
    obj->isInitialized = 1;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
         proc_control_node_B.k_h++) {
      proc_control_node_B.b_I_a[proc_control_node_B.k_h] = 0;
    }

    proc_control_node_B.b_I_a[0] = 1;
    proc_control_node_B.b_I_a[4] = 1;
    proc_control_node_B.b_I_a[8] = 1;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
         proc_control_node_B.k_h++) {
      proc_control_node_B.a_d[proc_control_node_B.k_h] =
        tmp[proc_control_node_B.k_h];
    }

    proc_control_node_B.B_p[0] = obj->AxesMisalignment[0] / 100.0;
    proc_control_node_B.B_p[1] = obj->AxesMisalignment[1] / 100.0;
    proc_control_node_B.B_p[2] = obj->AxesMisalignment[2] / 100.0;
    proc_control_node_B.k_h = 0;
    for (proc_control_node_B.nx_k = 0; proc_control_node_B.nx_k < 3;
         proc_control_node_B.nx_k++) {
      proc_control_node_B.c_o[proc_control_node_B.k_h] = static_cast<real_T>
        (proc_control_node_B.a_d[proc_control_node_B.k_h]) *
        proc_control_node_B.B_p[proc_control_node_B.nx_k];
      proc_control_node_B.c_o[proc_control_node_B.k_h + 1] = static_cast<real_T>
        (proc_control_node_B.a_d[proc_control_node_B.k_h + 1]) *
        proc_control_node_B.B_p[proc_control_node_B.nx_k];
      proc_control_node_B.c_o[proc_control_node_B.k_h + 2] = static_cast<real_T>
        (proc_control_node_B.a_d[proc_control_node_B.k_h + 2]) *
        proc_control_node_B.B_p[proc_control_node_B.nx_k];
      proc_control_node_B.k_h += 3;
    }

    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
         proc_control_node_B.k_h++) {
      obj->pGain[proc_control_node_B.k_h] = static_cast<real_T>
        (proc_control_node_B.b_I_a[proc_control_node_B.k_h]) +
        proc_control_node_B.c_o[proc_control_node_B.k_h];
    }

    obj->pBiasInstFilterNum = 1.0;
    obj->pBiasInstFilterDen[0] = 1.0;
    obj->pBiasInstFilterDen[1] = -0.5;
    obj->pBiasInstFilterStates[0] = 0.0;
    obj->pStdDevBiasInst[0] = obj->BiasInstability[0];
    obj->pBiasInstFilterStates[1] = 0.0;
    obj->pStdDevBiasInst[1] = obj->BiasInstability[1];
    obj->pBiasInstFilterStates[2] = 0.0;
    obj->pStdDevBiasInst[2] = obj->BiasInstability[2];
    obj->TunablePropsChanged = false;
    obj->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj->NoiseDensity[0];
    obj->pRandWalkFilterStates[0] = 0.0;
    obj->pStdDevRandWalk[0] = obj->RandomWalk[0] / 5.4772255750516612;
    obj->pBiasInstFilterStates[0] = 0.0;
    obj->pRandWalkFilterStates[0] = 0.0;
    obj->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj->NoiseDensity[1];
    obj->pRandWalkFilterStates[1] = 0.0;
    obj->pStdDevRandWalk[1] = obj->RandomWalk[1] / 5.4772255750516612;
    obj->pBiasInstFilterStates[1] = 0.0;
    obj->pRandWalkFilterStates[1] = 0.0;
    obj->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj->NoiseDensity[2];
    obj->pRandWalkFilterStates[2] = 0.0;
    obj->pStdDevRandWalk[2] = obj->RandomWalk[2] / 5.4772255750516612;
    obj->pBiasInstFilterStates[2] = 0.0;
    obj->pRandWalkFilterStates[2] = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    if (obj->tunablePropertyChanged[4]) {
      for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
           proc_control_node_B.k_h++) {
        proc_control_node_B.b_I_a[proc_control_node_B.k_h] = 0;
      }

      proc_control_node_B.b_I_a[0] = 1;
      proc_control_node_B.b_I_a[4] = 1;
      proc_control_node_B.b_I_a[8] = 1;
      for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
           proc_control_node_B.k_h++) {
        proc_control_node_B.a_d[proc_control_node_B.k_h] =
          tmp[proc_control_node_B.k_h];
      }

      proc_control_node_B.B_p[0] = obj->AxesMisalignment[0] / 100.0;
      proc_control_node_B.B_p[1] = obj->AxesMisalignment[1] / 100.0;
      proc_control_node_B.B_p[2] = obj->AxesMisalignment[2] / 100.0;
      proc_control_node_B.k_h = 0;
      for (proc_control_node_B.nx_k = 0; proc_control_node_B.nx_k < 3;
           proc_control_node_B.nx_k++) {
        proc_control_node_B.c_o[proc_control_node_B.k_h] = static_cast<real_T>
          (proc_control_node_B.a_d[proc_control_node_B.k_h]) *
          proc_control_node_B.B_p[proc_control_node_B.nx_k];
        proc_control_node_B.c_o[proc_control_node_B.k_h + 1] =
          static_cast<real_T>(proc_control_node_B.a_d[proc_control_node_B.k_h +
                              1]) *
          proc_control_node_B.B_p[proc_control_node_B.nx_k];
        proc_control_node_B.c_o[proc_control_node_B.k_h + 2] =
          static_cast<real_T>(proc_control_node_B.a_d[proc_control_node_B.k_h +
                              2]) *
          proc_control_node_B.B_p[proc_control_node_B.nx_k];
        proc_control_node_B.k_h += 3;
      }

      for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 9;
           proc_control_node_B.k_h++) {
        obj->pGain[proc_control_node_B.k_h] = static_cast<real_T>
          (proc_control_node_B.b_I_a[proc_control_node_B.k_h]) +
          proc_control_node_B.c_o[proc_control_node_B.k_h];
      }
    }

    if (obj->tunablePropertyChanged[5]) {
      obj->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj->NoiseDensity[0];
      obj->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj->NoiseDensity[1];
      obj->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj->NoiseDensity[2];
    }

    if (obj->tunablePropertyChanged[6]) {
      obj->pStdDevBiasInst[0] = obj->BiasInstability[0];
      obj->pStdDevBiasInst[1] = obj->BiasInstability[1];
      obj->pStdDevBiasInst[2] = obj->BiasInstability[2];
    }

    if (obj->tunablePropertyChanged[7]) {
      obj->pStdDevRandWalk[0] = obj->RandomWalk[0] / 5.4772255750516612;
      obj->pStdDevRandWalk[1] = obj->RandomWalk[1] / 5.4772255750516612;
      obj->pStdDevRandWalk[2] = obj->RandomWalk[2] / 5.4772255750516612;
    }

    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 11;
         proc_control_node_B.k_h++) {
      obj->tunablePropertyChanged[proc_control_node_B.k_h] = false;
    }
  }

  for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 3;
       proc_control_node_B.k_h++) {
    obj->pAcceleration[proc_control_node_B.k_h] =
      varargin_2[proc_control_node_B.k_h];
    proc_control_node_B.varargin_3[proc_control_node_B.k_h] = 0.0;
    proc_control_node_B.varargin_3[proc_control_node_B.k_h] +=
      varargin_3[proc_control_node_B.k_h] * varargin_1[0];
    proc_control_node_B.varargin_3[proc_control_node_B.k_h] +=
      varargin_3[proc_control_node_B.k_h + 3] * varargin_1[1];
    proc_control_node_B.varargin_3[proc_control_node_B.k_h] +=
      varargin_3[proc_control_node_B.k_h + 6] * varargin_1[2];
  }

  for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 3;
       proc_control_node_B.k_h++) {
    proc_control_node_B.y_e[proc_control_node_B.k_h] = 0.0;
    proc_control_node_B.y_e[proc_control_node_B.k_h] += obj->
      pGain[proc_control_node_B.k_h] * proc_control_node_B.varargin_3[0];
    proc_control_node_B.y_e[proc_control_node_B.k_h] += obj->
      pGain[proc_control_node_B.k_h + 3] * proc_control_node_B.varargin_3[1];
    proc_control_node_B.y_e[proc_control_node_B.k_h] += obj->
      pGain[proc_control_node_B.k_h + 6] * proc_control_node_B.varargin_3[2];
    proc_control_node_B.B_p[proc_control_node_B.k_h] =
      proc_control_node_B.y_e[proc_control_node_B.k_h] + obj->
      ConstantBias[proc_control_node_B.k_h];
    proc_control_node_B.c_o4[proc_control_node_B.k_h] =
      varargin_4[proc_control_node_B.k_h] * obj->
      pStdDevBiasInst[proc_control_node_B.k_h];
  }

  for (proc_control_node_B.i24 = 0; proc_control_node_B.i24 < 2;
       proc_control_node_B.i24++) {
    proc_control_node_B.obj_g[proc_control_node_B.i24] = obj->
      pBiasInstFilterDen[proc_control_node_B.i24];
  }

  for (proc_control_node_B.i25 = 0; proc_control_node_B.i25 < 3;
       proc_control_node_B.i25++) {
    proc_control_node_B.varargin_3[proc_control_node_B.i25] =
      obj->pBiasInstFilterStates[proc_control_node_B.i25];
  }

  proc_control_node_filter(obj->pBiasInstFilterNum, proc_control_node_B.obj_g,
    proc_control_node_B.c_o4, proc_control_node_B.varargin_3,
    proc_control_node_B.y_e, obj->pBiasInstFilterStates);
  proc_control_node_B.whiteNoiseDrift_idx_0_n = obj->pStdDevWhiteNoise[0] *
    varargin_4[3];
  proc_control_node_B.whiteNoiseDrift_idx_1_l = obj->pStdDevWhiteNoise[1] *
    varargin_4[4];
  proc_control_node_B.whiteNoiseDrift_idx_2_c = obj->pStdDevWhiteNoise[2] *
    varargin_4[5];
  proc_control_node_B.x_idx_1 = obj->pStdDevRandWalk[0] * varargin_4[6] +
    obj->pRandWalkFilterStates[0];
  proc_control_node_B.x_idx_3 = obj->pStdDevRandWalk[1] * varargin_4[7] +
    obj->pRandWalkFilterStates[1];
  proc_control_node_B.x_idx_5 = obj->pStdDevRandWalk[2] * varargin_4[8] +
    obj->pRandWalkFilterStates[2];
  proc_control_node_B.obj_tmp_tmp = obj->Temperature - 25.0;
  obj->pRandWalkFilterStates[0] = proc_control_node_B.x_idx_1;
  proc_control_node_B.c_o4[0] = proc_control_node_B.obj_tmp_tmp *
    obj->TemperatureBias[0];
  obj->pRandWalkFilterStates[1] = proc_control_node_B.x_idx_3;
  proc_control_node_B.c_o4[1] = proc_control_node_B.obj_tmp_tmp *
    obj->TemperatureBias[1];
  obj->pRandWalkFilterStates[2] = proc_control_node_B.x_idx_5;
  proc_control_node_B.temperatureDrift_idx_0 = proc_control_node_B.c_o4[0];
  proc_control_node_B.temperatureDrift_idx_1 = proc_control_node_B.c_o4[1];
  proc_control_node_B.obj_gs = (obj->Temperature - 25.0) * 0.01;
  varargout_1[0] = ((((proc_control_node_B.whiteNoiseDrift_idx_0_n +
                       proc_control_node_B.y_e[0]) + proc_control_node_B.x_idx_1)
                     + (obj->pAcceleration[0] * obj->AccelerationBias[0] +
                        proc_control_node_B.temperatureDrift_idx_0)) +
                    proc_control_node_B.B_p[0]) * (proc_control_node_B.obj_gs *
    obj->TemperatureScaleFactor[0] + 1.0);
  varargout_1[1] = ((((proc_control_node_B.whiteNoiseDrift_idx_1_l +
                       proc_control_node_B.y_e[1]) + proc_control_node_B.x_idx_3)
                     + (obj->pAcceleration[1] * obj->AccelerationBias[1] +
                        proc_control_node_B.temperatureDrift_idx_1)) +
                    proc_control_node_B.B_p[1]) * (proc_control_node_B.obj_gs *
    obj->TemperatureScaleFactor[1] + 1.0);
  varargout_1[2] = ((((proc_control_node_B.whiteNoiseDrift_idx_2_c +
                       proc_control_node_B.y_e[2]) + proc_control_node_B.x_idx_5)
                     + (proc_control_node_B.obj_tmp_tmp * obj->TemperatureBias[2]
                        + obj->pAcceleration[2] * obj->AccelerationBias[2])) +
                    proc_control_node_B.B_p[2]) * (proc_control_node_B.obj_gs *
    obj->TemperatureScaleFactor[2] + 1.0);
  if (!rtIsInf(obj->MeasurementRange)) {
    proc_control_node_B.whiteNoiseDrift_idx_0_n = fabs(varargout_1[0]);
    proc_control_node_B.d_e[0] = (proc_control_node_B.whiteNoiseDrift_idx_0_n >
      obj->MeasurementRange);
    proc_control_node_B.whiteNoiseDrift_idx_1_l = fabs(varargout_1[1]);
    proc_control_node_B.d_e[1] = (proc_control_node_B.whiteNoiseDrift_idx_1_l >
      obj->MeasurementRange);
    proc_control_node_B.whiteNoiseDrift_idx_2_c = fabs(varargout_1[2]);
    proc_control_node_B.d_e[2] = (proc_control_node_B.whiteNoiseDrift_idx_2_c >
      obj->MeasurementRange);
    proc_control_node_B.nx_k = 0;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 3;
         proc_control_node_B.k_h++) {
      if (proc_control_node_B.d_e[proc_control_node_B.k_h]) {
        proc_control_node_B.b_data_a[proc_control_node_B.nx_k] =
          static_cast<int8_T>(proc_control_node_B.k_h + 1);
        proc_control_node_B.nx_k++;
      }
    }

    proc_control_node_B.d_e[0] = (proc_control_node_B.whiteNoiseDrift_idx_0_n >
      obj->MeasurementRange);
    proc_control_node_B.d_e[1] = (proc_control_node_B.whiteNoiseDrift_idx_1_l >
      obj->MeasurementRange);
    proc_control_node_B.d_e[2] = (proc_control_node_B.whiteNoiseDrift_idx_2_c >
      obj->MeasurementRange);
    proc_control_node_B.nx_k = 0;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 3;
         proc_control_node_B.k_h++) {
      if (proc_control_node_B.d_e[proc_control_node_B.k_h]) {
        proc_control_node_B.nx_k++;
      }
    }

    proc_control_node_B.f_size_idx_1_b = proc_control_node_B.nx_k;
    proc_control_node_B.nx_k = 0;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h < 3;
         proc_control_node_B.k_h++) {
      if (proc_control_node_B.d_e[proc_control_node_B.k_h]) {
        proc_control_node_B.f_data_j[proc_control_node_B.nx_k] =
          static_cast<int8_T>(proc_control_node_B.k_h + 1);
        proc_control_node_B.nx_k++;
      }
    }

    proc_control_node_B.nx_k = proc_control_node_B.f_size_idx_1_b - 1;
    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h <=
         proc_control_node_B.nx_k; proc_control_node_B.k_h++) {
      proc_control_node_B.b_x_data_tmp_o = proc_control_node_B.k_h;
      proc_control_node_B.B_p[proc_control_node_B.b_x_data_tmp_o] =
        varargout_1[proc_control_node_B.f_data_j[proc_control_node_B.b_x_data_tmp_o]
        - 1];
    }

    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h <=
         proc_control_node_B.nx_k; proc_control_node_B.k_h++) {
      proc_control_node_B.b_x_data_tmp_o = proc_control_node_B.k_h;
      proc_control_node_B.whiteNoiseDrift_idx_0_n =
        proc_control_node_B.B_p[proc_control_node_B.b_x_data_tmp_o];
      if (proc_control_node_B.whiteNoiseDrift_idx_0_n < 0.0) {
        proc_control_node_B.whiteNoiseDrift_idx_0_n = -1.0;
      } else if (proc_control_node_B.whiteNoiseDrift_idx_0_n > 0.0) {
        proc_control_node_B.whiteNoiseDrift_idx_0_n = 1.0;
      } else if (proc_control_node_B.whiteNoiseDrift_idx_0_n == 0.0) {
        proc_control_node_B.whiteNoiseDrift_idx_0_n = 0.0;
      } else {
        proc_control_node_B.whiteNoiseDrift_idx_0_n = (rtNaN);
      }

      proc_control_node_B.B_p[proc_control_node_B.b_x_data_tmp_o] =
        proc_control_node_B.whiteNoiseDrift_idx_0_n;
    }

    for (proc_control_node_B.k_h = 0; proc_control_node_B.k_h <
         proc_control_node_B.f_size_idx_1_b; proc_control_node_B.k_h++) {
      proc_control_node_B.nx_k = proc_control_node_B.k_h;
      varargout_1[proc_control_node_B.b_data_a[proc_control_node_B.nx_k] - 1] =
        proc_control_node_B.B_p[proc_control_node_B.nx_k] *
        obj->MeasurementRange;
    }
  }

  if (obj->Resolution != 0.0) {
    proc_control_node_B.whiteNoiseDrift_idx_0_n = varargout_1[1] /
      obj->Resolution;
    proc_control_node_B.whiteNoiseDrift_idx_1_l = varargout_1[2] /
      obj->Resolution;
    varargout_1[0] = rt_roundd_snf(varargout_1[0] / obj->Resolution);
    varargout_1[1] = rt_roundd_snf(proc_control_node_B.whiteNoiseDrift_idx_0_n);
    varargout_1[2] = rt_roundd_snf(proc_control_node_B.whiteNoiseDrift_idx_1_l);
    varargout_1[0] *= obj->Resolution;
    varargout_1[1] *= obj->Resolution;
    varargout_1[2] *= obj->Resolution;
  }
}

static void proc_control_no_SystemCore_step(fusion_simulink_imuSensor_pro_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[4], real_T varargout_1[3], real_T varargout_2[3], real_T
  varargout_3[3])
{
  h_fusion_internal_Acceleromet_T *obj_0;
  h_fusion_internal_GyroscopeSi_T *obj_1;
  h_fusion_internal_Magnetomete_T *obj_2;
  static const int8_T tmp[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  static const int32_T tmp_0[2] = { 1, 9 };

  static const int32_T tmp_1[2] = { 1, 10 };

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    proc_control_node_B.tb = obj->AccelParamsMeasurementRange;
    proc_control_node_B.tc = obj->AccelParamsResolution;
    proc_control_node_B.magneticfield[0] = obj->AccelParamsConstantBias[0];
    proc_control_node_B.magneticfield[1] = obj->AccelParamsConstantBias[1];
    proc_control_node_B.magneticfield[2] = obj->AccelParamsConstantBias[2];
    proc_control_node_B.val[0] = obj->AccelParamsAxesMisalignment[0];
    proc_control_node_B.val[1] = obj->AccelParamsAxesMisalignment[1];
    proc_control_node_B.val[2] = obj->AccelParamsAxesMisalignment[2];
    proc_control_node_B.whiteNoiseDrift[0] = obj->AccelParamsNoiseDensity[0];
    proc_control_node_B.whiteNoiseDrift[1] = obj->AccelParamsNoiseDensity[1];
    proc_control_node_B.whiteNoiseDrift[2] = obj->AccelParamsNoiseDensity[2];
    proc_control_node_B.val_p[0] = obj->AccelParamsBiasInstability[0];
    proc_control_node_B.val_p[1] = obj->AccelParamsBiasInstability[1];
    proc_control_node_B.val_p[2] = obj->AccelParamsBiasInstability[2];
    proc_control_node_B.temperatureDrift[0] = obj->AccelParamsRandomWalk[0];
    proc_control_node_B.temperatureDrift[1] = obj->AccelParamsRandomWalk[1];
    proc_control_node_B.temperatureDrift[2] = obj->AccelParamsRandomWalk[2];
    proc_control_node_B.val_a[0] = obj->AccelParamsTemperatureBias[0];
    proc_control_node_B.val_a[1] = obj->AccelParamsTemperatureBias[1];
    proc_control_node_B.val_a[2] = obj->AccelParamsTemperatureBias[2];
    proc_control_node_B.val_e[0] = obj->AccelParamsTemperatureScaleFactor[0];
    proc_control_node_B.val_e[1] = obj->AccelParamsTemperatureScaleFactor[1];
    proc_control_node_B.val_e[2] = obj->AccelParamsTemperatureScaleFactor[2];
    proc_control_node_B.aasq = obj->GyroParamsMeasurementRange;
    proc_control_node_B.n = obj->GyroParamsResolution;
    proc_control_node_B.val_ax[0] = obj->GyroParamsConstantBias[0];
    proc_control_node_B.val_ax[1] = obj->GyroParamsConstantBias[1];
    proc_control_node_B.val_ax[2] = obj->GyroParamsConstantBias[2];
    proc_control_node_B.val_as[0] = obj->GyroParamsAxesMisalignment[0];
    proc_control_node_B.val_as[1] = obj->GyroParamsAxesMisalignment[1];
    proc_control_node_B.val_as[2] = obj->GyroParamsAxesMisalignment[2];
    proc_control_node_B.val_i[0] = obj->GyroParamsNoiseDensity[0];
    proc_control_node_B.val_i[1] = obj->GyroParamsNoiseDensity[1];
    proc_control_node_B.val_i[2] = obj->GyroParamsNoiseDensity[2];
    proc_control_node_B.val_l[0] = obj->GyroParamsBiasInstability[0];
    proc_control_node_B.val_l[1] = obj->GyroParamsBiasInstability[1];
    proc_control_node_B.val_l[2] = obj->GyroParamsBiasInstability[2];
    proc_control_node_B.val_o[0] = obj->GyroParamsRandomWalk[0];
    proc_control_node_B.val_o[1] = obj->GyroParamsRandomWalk[1];
    proc_control_node_B.val_o[2] = obj->GyroParamsRandomWalk[2];
    proc_control_node_B.val_o2[0] = obj->GyroParamsTemperatureBias[0];
    proc_control_node_B.val_o2[1] = obj->GyroParamsTemperatureBias[1];
    proc_control_node_B.val_o2[2] = obj->GyroParamsTemperatureBias[2];
    proc_control_node_B.val_ip[0] = obj->GyroParamsTemperatureScaleFactor[0];
    proc_control_node_B.val_ip[1] = obj->GyroParamsTemperatureScaleFactor[1];
    proc_control_node_B.val_ip[2] = obj->GyroParamsTemperatureScaleFactor[2];
    proc_control_node_B.val_f[0] = obj->GyroParamsAccelerationBias[0];
    proc_control_node_B.val_f[1] = obj->GyroParamsAccelerationBias[1];
    proc_control_node_B.val_f[2] = obj->GyroParamsAccelerationBias[2];
    proc_control_node_B.ab2 = obj->MagParamsMeasurementRange;
    proc_control_node_B.ac2 = obj->MagParamsResolution;
    proc_control_node_B.val_iz[0] = obj->MagParamsConstantBias[0];
    proc_control_node_B.val_iz[1] = obj->MagParamsConstantBias[1];
    proc_control_node_B.val_iz[2] = obj->MagParamsConstantBias[2];
    proc_control_node_B.val_ff[0] = obj->MagParamsAxesMisalignment[0];
    proc_control_node_B.val_ff[1] = obj->MagParamsAxesMisalignment[1];
    proc_control_node_B.val_ff[2] = obj->MagParamsAxesMisalignment[2];
    proc_control_node_B.val_g[0] = obj->MagParamsNoiseDensity[0];
    proc_control_node_B.val_g[1] = obj->MagParamsNoiseDensity[1];
    proc_control_node_B.val_g[2] = obj->MagParamsNoiseDensity[2];
    proc_control_node_B.val_c[0] = obj->MagParamsBiasInstability[0];
    proc_control_node_B.val_c[1] = obj->MagParamsBiasInstability[1];
    proc_control_node_B.val_c[2] = obj->MagParamsBiasInstability[2];
    proc_control_node_B.val_o3[0] = obj->MagParamsRandomWalk[0];
    proc_control_node_B.val_o3[1] = obj->MagParamsRandomWalk[1];
    proc_control_node_B.val_o3[2] = obj->MagParamsRandomWalk[2];
    proc_control_node_B.val_lm[0] = obj->MagParamsTemperatureBias[0];
    proc_control_node_B.val_lm[1] = obj->MagParamsTemperatureBias[1];
    proc_control_node_B.val_lm[2] = obj->MagParamsTemperatureBias[2];
    proc_control_node_B.val_m[0] = obj->MagParamsTemperatureScaleFactor[0];
    proc_control_node_B.val_m[1] = obj->MagParamsTemperatureScaleFactor[1];
    proc_control_node_B.val_m[2] = obj->MagParamsTemperatureScaleFactor[2];
    proc_control_node_B.flag_o = obj->tunablePropertyChanged[31];
    if (proc_control_node_B.flag_o) {
      obj_0 = obj->pAccel;
      proc_control_node_B.flag_o = (obj_0->isInitialized == 1);
      if (proc_control_node_B.flag_o) {
        obj_0->TunablePropsChanged = true;
        obj_0->tunablePropertyChanged[9] = true;
      }

      obj->pAccel->Temperature = obj->Temperature;
      IMUSensorParameters_updateSyste(proc_control_node_B.tb,
        proc_control_node_B.tc, proc_control_node_B.magneticfield,
        proc_control_node_B.val, proc_control_node_B.whiteNoiseDrift,
        proc_control_node_B.val_p, proc_control_node_B.temperatureDrift,
        proc_control_node_B.val_a, proc_control_node_B.val_e, obj->pAccel);
      obj_1 = obj->pGyro;
      proc_control_node_B.flag_o = (obj_1->isInitialized == 1);
      if (proc_control_node_B.flag_o) {
        obj_1->TunablePropsChanged = true;
        obj_1->tunablePropertyChanged[10] = true;
      }

      obj->pGyro->Temperature = obj->Temperature;
      IMUSensorParameters_updateSys_b(proc_control_node_B.aasq,
        proc_control_node_B.n, proc_control_node_B.val_ax,
        proc_control_node_B.val_as, proc_control_node_B.val_i,
        proc_control_node_B.val_l, proc_control_node_B.val_o,
        proc_control_node_B.val_o2, proc_control_node_B.val_ip,
        proc_control_node_B.val_f, obj->pGyro);
      obj_2 = obj->pMag;
      proc_control_node_B.flag_o = (obj_2->isInitialized == 1);
      if (proc_control_node_B.flag_o) {
        obj_2->TunablePropsChanged = true;
        obj_2->tunablePropertyChanged[9] = true;
      }

      obj->pMag->Temperature = obj->Temperature;
      IMUSensorParameters_updateSy_b4(proc_control_node_B.ab2,
        proc_control_node_B.ac2, proc_control_node_B.val_iz,
        proc_control_node_B.val_ff, proc_control_node_B.val_g,
        proc_control_node_B.val_c, proc_control_node_B.val_o3,
        proc_control_node_B.val_lm, proc_control_node_B.val_m, obj->pMag);
    }

    proc_control_node_B.flag_h[0] = obj->tunablePropertyChanged[3];
    proc_control_node_B.flag_h[1] = obj->tunablePropertyChanged[4];
    proc_control_node_B.flag_h[2] = obj->tunablePropertyChanged[5];
    proc_control_node_B.flag_h[3] = obj->tunablePropertyChanged[6];
    proc_control_node_B.flag_h[4] = obj->tunablePropertyChanged[7];
    proc_control_node_B.flag_h[5] = obj->tunablePropertyChanged[8];
    proc_control_node_B.flag_h[6] = obj->tunablePropertyChanged[9];
    proc_control_node_B.flag_h[7] = obj->tunablePropertyChanged[10];
    proc_control_node_B.flag_h[8] = obj->tunablePropertyChanged[11];
    if (proc_control_node_vectorAny(proc_control_node_B.flag_h, tmp_0)) {
      IMUSensorParameters_updateSyste(proc_control_node_B.tb,
        proc_control_node_B.tc, proc_control_node_B.magneticfield,
        proc_control_node_B.val, proc_control_node_B.whiteNoiseDrift,
        proc_control_node_B.val_p, proc_control_node_B.temperatureDrift,
        proc_control_node_B.val_a, proc_control_node_B.val_e, obj->pAccel);
    }

    proc_control_node_B.flag[0] = obj->tunablePropertyChanged[12];
    proc_control_node_B.flag[1] = obj->tunablePropertyChanged[13];
    proc_control_node_B.flag[2] = obj->tunablePropertyChanged[14];
    proc_control_node_B.flag[3] = obj->tunablePropertyChanged[15];
    proc_control_node_B.flag[4] = obj->tunablePropertyChanged[16];
    proc_control_node_B.flag[5] = obj->tunablePropertyChanged[17];
    proc_control_node_B.flag[6] = obj->tunablePropertyChanged[18];
    proc_control_node_B.flag[7] = obj->tunablePropertyChanged[19];
    proc_control_node_B.flag[8] = obj->tunablePropertyChanged[20];
    proc_control_node_B.flag[9] = obj->tunablePropertyChanged[21];
    if (proc_control_node_vectorAny(proc_control_node_B.flag, tmp_1)) {
      IMUSensorParameters_updateSys_b(proc_control_node_B.aasq,
        proc_control_node_B.n, proc_control_node_B.val_ax,
        proc_control_node_B.val_as, proc_control_node_B.val_i,
        proc_control_node_B.val_l, proc_control_node_B.val_o,
        proc_control_node_B.val_o2, proc_control_node_B.val_ip,
        proc_control_node_B.val_f, obj->pGyro);
    }

    proc_control_node_B.flag_h[0] = obj->tunablePropertyChanged[22];
    proc_control_node_B.flag_h[1] = obj->tunablePropertyChanged[23];
    proc_control_node_B.flag_h[2] = obj->tunablePropertyChanged[24];
    proc_control_node_B.flag_h[3] = obj->tunablePropertyChanged[25];
    proc_control_node_B.flag_h[4] = obj->tunablePropertyChanged[26];
    proc_control_node_B.flag_h[5] = obj->tunablePropertyChanged[27];
    proc_control_node_B.flag_h[6] = obj->tunablePropertyChanged[28];
    proc_control_node_B.flag_h[7] = obj->tunablePropertyChanged[29];
    proc_control_node_B.flag_h[8] = obj->tunablePropertyChanged[30];
    if (proc_control_node_vectorAny(proc_control_node_B.flag_h, tmp_0)) {
      IMUSensorParameters_updateSy_b4(proc_control_node_B.ab2,
        proc_control_node_B.ac2, proc_control_node_B.val_iz,
        proc_control_node_B.val_ff, proc_control_node_B.val_g,
        proc_control_node_B.val_c, proc_control_node_B.val_o3,
        proc_control_node_B.val_lm, proc_control_node_B.val_m, obj->pMag);
    }

    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 32;
         proc_control_node_B.b_jcol++) {
      obj->tunablePropertyChanged[proc_control_node_B.b_jcol] = false;
    }
  }

  proc_control_node_B.n = sqrt(((varargin_3[0] * varargin_3[0] + varargin_3[1] *
    varargin_3[1]) + varargin_3[2] * varargin_3[2]) + varargin_3[3] *
    varargin_3[3]);
  proc_control_node_B.aasq = varargin_3[0] / proc_control_node_B.n;
  proc_control_node_B.tb = varargin_3[1] / proc_control_node_B.n;
  proc_control_node_B.tc = varargin_3[2] / proc_control_node_B.n;
  proc_control_node_B.n = varargin_3[3] / proc_control_node_B.n;
  proc_control_node_B.ab2 = proc_control_node_B.aasq * proc_control_node_B.tb *
    2.0;
  proc_control_node_B.ac2 = proc_control_node_B.aasq * proc_control_node_B.tc *
    2.0;
  proc_control_node_B.ad2 = proc_control_node_B.aasq * proc_control_node_B.n *
    2.0;
  proc_control_node_B.bc2 = proc_control_node_B.tb * proc_control_node_B.tc *
    2.0;
  proc_control_node_B.bd2 = proc_control_node_B.tb * proc_control_node_B.n * 2.0;
  proc_control_node_B.cd2 = proc_control_node_B.tc * proc_control_node_B.n * 2.0;
  proc_control_node_B.aasq = proc_control_node_B.aasq * proc_control_node_B.aasq
    * 2.0 - 1.0;
  proc_control_node_B.rmat[0] = proc_control_node_B.tb * proc_control_node_B.tb *
    2.0 + proc_control_node_B.aasq;
  proc_control_node_B.rmat[3] = proc_control_node_B.bc2 +
    proc_control_node_B.ad2;
  proc_control_node_B.rmat[6] = proc_control_node_B.bd2 -
    proc_control_node_B.ac2;
  proc_control_node_B.rmat[1] = proc_control_node_B.bc2 -
    proc_control_node_B.ad2;
  proc_control_node_B.rmat[4] = proc_control_node_B.tc * proc_control_node_B.tc *
    2.0 + proc_control_node_B.aasq;
  proc_control_node_B.rmat[7] = proc_control_node_B.cd2 +
    proc_control_node_B.ab2;
  proc_control_node_B.rmat[2] = proc_control_node_B.bd2 +
    proc_control_node_B.ac2;
  proc_control_node_B.rmat[5] = proc_control_node_B.cd2 -
    proc_control_node_B.ab2;
  proc_control_node_B.rmat[8] = proc_control_node_B.n * proc_control_node_B.n *
    2.0 + proc_control_node_B.aasq;
  IMUSensorBase_stepRandomStream(obj, proc_control_node_B.randNums);
  proc_control__SystemCore_step_b(obj->pAccel, varargin_1,
    proc_control_node_B.rmat, &proc_control_node_B.randNums[0], varargout_1);
  proc_control_SystemCore_step_b4(obj->pGyro, varargin_2, varargin_1,
    proc_control_node_B.rmat, &proc_control_node_B.randNums[9], varargout_2);
  proc_control_node_B.val_p[0] = obj->MagneticField[0];
  proc_control_node_B.val_p[1] = obj->MagneticField[1];
  proc_control_node_B.val_p[2] = obj->MagneticField[2];
  proc_control_node_B.magneticfield[0] = proc_control_node_B.val_p[0];
  proc_control_node_B.magneticfield[1] = proc_control_node_B.val_p[1];
  proc_control_node_B.magneticfield[2] = proc_control_node_B.val_p[2];
  obj_2 = obj->pMag;
  if (obj_2->isInitialized != 1) {
    obj_2->isInitialized = 1;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
         proc_control_node_B.b_jcol++) {
      proc_control_node_B.b_I_e[proc_control_node_B.b_jcol] = 0;
    }

    proc_control_node_B.b_I_e[0] = 1;
    proc_control_node_B.b_I_e[4] = 1;
    proc_control_node_B.b_I_e[8] = 1;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
         proc_control_node_B.b_jcol++) {
      proc_control_node_B.a_a[proc_control_node_B.b_jcol] =
        tmp[proc_control_node_B.b_jcol];
    }

    proc_control_node_B.val_p[0] = obj_2->AxesMisalignment[0] / 100.0;
    proc_control_node_B.val_p[1] = obj_2->AxesMisalignment[1] / 100.0;
    proc_control_node_B.val_p[2] = obj_2->AxesMisalignment[2] / 100.0;
    proc_control_node_B.nx = 0;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
         proc_control_node_B.b_jcol++) {
      proc_control_node_B.c[proc_control_node_B.nx] =
        proc_control_node_B.a_a[proc_control_node_B.nx] *
        proc_control_node_B.val_p[proc_control_node_B.b_jcol];
      proc_control_node_B.c[proc_control_node_B.nx + 1] =
        proc_control_node_B.a_a[proc_control_node_B.nx + 1] *
        proc_control_node_B.val_p[proc_control_node_B.b_jcol];
      proc_control_node_B.c[proc_control_node_B.nx + 2] =
        proc_control_node_B.a_a[proc_control_node_B.nx + 2] *
        proc_control_node_B.val_p[proc_control_node_B.b_jcol];
      proc_control_node_B.nx += 3;
    }

    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
         proc_control_node_B.b_jcol++) {
      obj_2->pGain[proc_control_node_B.b_jcol] = static_cast<real_T>
        (proc_control_node_B.b_I_e[proc_control_node_B.b_jcol]) +
        proc_control_node_B.c[proc_control_node_B.b_jcol];
    }

    obj_2->pBiasInstFilterNum = 1.0;
    obj_2->pBiasInstFilterDen[0] = 1.0;
    obj_2->pBiasInstFilterDen[1] = -0.5;
    obj_2->pBiasInstFilterStates[0] = 0.0;
    obj_2->pBiasInstFilterStates[1] = 0.0;
    obj_2->pBiasInstFilterStates[2] = 0.0;
    obj_2->pStdDevBiasInst[0] = obj_2->BiasInstability[0];
    obj_2->pStdDevBiasInst[1] = obj_2->BiasInstability[1];
    obj_2->pStdDevBiasInst[2] = obj_2->BiasInstability[2];
    obj_2->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj_2->NoiseDensity[0];
    obj_2->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj_2->NoiseDensity[1];
    obj_2->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj_2->NoiseDensity[2];
    obj_2->pRandWalkFilterStates[0] = 0.0;
    obj_2->pRandWalkFilterStates[1] = 0.0;
    obj_2->pRandWalkFilterStates[2] = 0.0;
    obj_2->pStdDevRandWalk[0] = obj_2->RandomWalk[0] / 5.4772255750516612;
    obj_2->pStdDevRandWalk[1] = obj_2->RandomWalk[1] / 5.4772255750516612;
    obj_2->pStdDevRandWalk[2] = obj_2->RandomWalk[2] / 5.4772255750516612;
    obj_2->TunablePropsChanged = false;
    obj_2->pBiasInstFilterStates[0] = 0.0;
    obj_2->pBiasInstFilterStates[1] = 0.0;
    obj_2->pBiasInstFilterStates[2] = 0.0;
    obj_2->pRandWalkFilterStates[0] = 0.0;
    obj_2->pRandWalkFilterStates[1] = 0.0;
    obj_2->pRandWalkFilterStates[2] = 0.0;
  }

  if (obj_2->TunablePropsChanged) {
    obj_2->TunablePropsChanged = false;
    proc_control_node_B.flag_o = obj_2->tunablePropertyChanged[3];
    if (proc_control_node_B.flag_o) {
      for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
           proc_control_node_B.b_jcol++) {
        proc_control_node_B.b_I_e[proc_control_node_B.b_jcol] = 0;
      }

      proc_control_node_B.b_I_e[0] = 1;
      proc_control_node_B.b_I_e[4] = 1;
      proc_control_node_B.b_I_e[8] = 1;
      for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
           proc_control_node_B.b_jcol++) {
        proc_control_node_B.a_a[proc_control_node_B.b_jcol] =
          tmp[proc_control_node_B.b_jcol];
      }

      proc_control_node_B.val_p[0] = obj_2->AxesMisalignment[0] / 100.0;
      proc_control_node_B.val_p[1] = obj_2->AxesMisalignment[1] / 100.0;
      proc_control_node_B.val_p[2] = obj_2->AxesMisalignment[2] / 100.0;
      proc_control_node_B.nx = 0;
      for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
           proc_control_node_B.b_jcol++) {
        proc_control_node_B.c[proc_control_node_B.nx] =
          proc_control_node_B.a_a[proc_control_node_B.nx] *
          proc_control_node_B.val_p[proc_control_node_B.b_jcol];
        proc_control_node_B.c[proc_control_node_B.nx + 1] =
          proc_control_node_B.a_a[proc_control_node_B.nx + 1] *
          proc_control_node_B.val_p[proc_control_node_B.b_jcol];
        proc_control_node_B.c[proc_control_node_B.nx + 2] =
          proc_control_node_B.a_a[proc_control_node_B.nx + 2] *
          proc_control_node_B.val_p[proc_control_node_B.b_jcol];
        proc_control_node_B.nx += 3;
      }

      for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
           proc_control_node_B.b_jcol++) {
        obj_2->pGain[proc_control_node_B.b_jcol] = static_cast<real_T>
          (proc_control_node_B.b_I_e[proc_control_node_B.b_jcol]) +
          proc_control_node_B.c[proc_control_node_B.b_jcol];
      }
    }

    proc_control_node_B.flag_o = obj_2->tunablePropertyChanged[4];
    if (proc_control_node_B.flag_o) {
      obj_2->pStdDevWhiteNoise[0] = 5.4772255750516612 * obj_2->NoiseDensity[0];
      obj_2->pStdDevWhiteNoise[1] = 5.4772255750516612 * obj_2->NoiseDensity[1];
      obj_2->pStdDevWhiteNoise[2] = 5.4772255750516612 * obj_2->NoiseDensity[2];
    }

    proc_control_node_B.flag_o = obj_2->tunablePropertyChanged[5];
    if (proc_control_node_B.flag_o) {
      obj_2->pStdDevBiasInst[0] = obj_2->BiasInstability[0];
      obj_2->pStdDevBiasInst[1] = obj_2->BiasInstability[1];
      obj_2->pStdDevBiasInst[2] = obj_2->BiasInstability[2];
    }

    proc_control_node_B.flag_o = obj_2->tunablePropertyChanged[6];
    if (proc_control_node_B.flag_o) {
      obj_2->pStdDevRandWalk[0] = obj_2->RandomWalk[0] / 5.4772255750516612;
      obj_2->pStdDevRandWalk[1] = obj_2->RandomWalk[1] / 5.4772255750516612;
      obj_2->pStdDevRandWalk[2] = obj_2->RandomWalk[2] / 5.4772255750516612;
    }

    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 10;
         proc_control_node_B.b_jcol++) {
      obj_2->tunablePropertyChanged[proc_control_node_B.b_jcol] = false;
    }
  }

  for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 9;
       proc_control_node_B.b_jcol++) {
    proc_control_node_B.a_a[proc_control_node_B.b_jcol] = obj_2->
      pGain[proc_control_node_B.b_jcol];
  }

  for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
       proc_control_node_B.b_jcol++) {
    proc_control_node_B.whiteNoiseDrift[proc_control_node_B.b_jcol] = 0.0;
    proc_control_node_B.whiteNoiseDrift[proc_control_node_B.b_jcol] +=
      proc_control_node_B.rmat[proc_control_node_B.b_jcol] *
      proc_control_node_B.magneticfield[0];
    proc_control_node_B.whiteNoiseDrift[proc_control_node_B.b_jcol] +=
      proc_control_node_B.rmat[proc_control_node_B.b_jcol + 3] *
      proc_control_node_B.magneticfield[1];
    proc_control_node_B.whiteNoiseDrift[proc_control_node_B.b_jcol] +=
      proc_control_node_B.rmat[proc_control_node_B.b_jcol + 6] *
      proc_control_node_B.magneticfield[2];
  }

  for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
       proc_control_node_B.b_jcol++) {
    proc_control_node_B.val[proc_control_node_B.b_jcol] = 0.0;
    proc_control_node_B.val[proc_control_node_B.b_jcol] +=
      proc_control_node_B.a_a[proc_control_node_B.b_jcol] *
      proc_control_node_B.whiteNoiseDrift[0];
    proc_control_node_B.val[proc_control_node_B.b_jcol] +=
      proc_control_node_B.a_a[proc_control_node_B.b_jcol + 3] *
      proc_control_node_B.whiteNoiseDrift[1];
    proc_control_node_B.val[proc_control_node_B.b_jcol] +=
      proc_control_node_B.a_a[proc_control_node_B.b_jcol + 6] *
      proc_control_node_B.whiteNoiseDrift[2];
  }

  proc_control_node_B.val_p[0] = obj_2->ConstantBias[0];
  proc_control_node_B.val_p[1] = obj_2->ConstantBias[1];
  proc_control_node_B.val_p[2] = obj_2->ConstantBias[2];
  proc_control_node_B.magneticfield[0] = proc_control_node_B.val[0] +
    proc_control_node_B.val_p[0];
  proc_control_node_B.magneticfield[1] = proc_control_node_B.val[1] +
    proc_control_node_B.val_p[1];
  proc_control_node_B.magneticfield[2] = proc_control_node_B.val[2] +
    proc_control_node_B.val_p[2];
  proc_control_node_B.val_p[0] = obj_2->pStdDevBiasInst[0];
  proc_control_node_B.val_p[1] = obj_2->pStdDevBiasInst[1];
  proc_control_node_B.val_p[2] = obj_2->pStdDevBiasInst[2];
  proc_control_node_B.temperatureDrift[0] = proc_control_node_B.val_p[0] *
    proc_control_node_B.randNums[18];
  proc_control_node_B.temperatureDrift[1] = proc_control_node_B.val_p[1] *
    proc_control_node_B.randNums[19];
  proc_control_node_B.temperatureDrift[2] = proc_control_node_B.val_p[2] *
    proc_control_node_B.randNums[20];
  for (proc_control_node_B.i21 = 0; proc_control_node_B.i21 < 2;
       proc_control_node_B.i21++) {
    proc_control_node_B.obj_b[proc_control_node_B.i21] =
      obj_2->pBiasInstFilterDen[proc_control_node_B.i21];
  }

  proc_control_node_filter(obj_2->pBiasInstFilterNum, proc_control_node_B.obj_b,
    proc_control_node_B.temperatureDrift, obj_2->pBiasInstFilterStates,
    proc_control_node_B.val, proc_control_node_B.val_p);
  obj_2->pBiasInstFilterStates[0] = proc_control_node_B.val_p[0];
  obj_2->pBiasInstFilterStates[1] = proc_control_node_B.val_p[1];
  obj_2->pBiasInstFilterStates[2] = proc_control_node_B.val_p[2];
  proc_control_node_B.val_p[0] = obj_2->pStdDevWhiteNoise[0];
  proc_control_node_B.val_p[1] = obj_2->pStdDevWhiteNoise[1];
  proc_control_node_B.val_p[2] = obj_2->pStdDevWhiteNoise[2];
  proc_control_node_B.whiteNoiseDrift[0] = proc_control_node_B.val_p[0] *
    proc_control_node_B.randNums[21];
  proc_control_node_B.whiteNoiseDrift[1] = proc_control_node_B.val_p[1] *
    proc_control_node_B.randNums[22];
  proc_control_node_B.whiteNoiseDrift[2] = proc_control_node_B.val_p[2] *
    proc_control_node_B.randNums[23];
  proc_control_node_B.val_p[0] = obj_2->pStdDevRandWalk[0];
  proc_control_node_B.val_p[1] = obj_2->pStdDevRandWalk[1];
  proc_control_node_B.val_p[2] = obj_2->pStdDevRandWalk[2];
  proc_control_node_B.tb = obj_2->pRandWalkFilterStates[0];
  proc_control_node_B.tc = obj_2->pRandWalkFilterStates[1];
  proc_control_node_B.aasq = obj_2->pRandWalkFilterStates[2];
  proc_control_node_B.tb += proc_control_node_B.val_p[0] *
    proc_control_node_B.randNums[24];
  proc_control_node_B.tc += proc_control_node_B.val_p[1] *
    proc_control_node_B.randNums[25];
  proc_control_node_B.n = proc_control_node_B.val_p[2] *
    proc_control_node_B.randNums[26] + proc_control_node_B.aasq;
  obj_2->pRandWalkFilterStates[0] = proc_control_node_B.tb;
  obj_2->pRandWalkFilterStates[1] = proc_control_node_B.tc;
  obj_2->pRandWalkFilterStates[2] = proc_control_node_B.n;
  proc_control_node_B.aasq = obj_2->Temperature - 25.0;
  proc_control_node_B.val_p[0] = proc_control_node_B.aasq *
    obj_2->TemperatureBias[0];
  proc_control_node_B.val_p[1] = proc_control_node_B.aasq *
    obj_2->TemperatureBias[1];
  proc_control_node_B.val_p[2] = proc_control_node_B.aasq *
    obj_2->TemperatureBias[2];
  proc_control_node_B.temperatureDrift[0] = proc_control_node_B.val_p[0];
  proc_control_node_B.temperatureDrift[1] = proc_control_node_B.val_p[1];
  proc_control_node_B.temperatureDrift[2] = proc_control_node_B.val_p[2];
  proc_control_node_B.aasq = (obj_2->Temperature - 25.0) * 0.01;
  proc_control_node_B.val_p[0] = proc_control_node_B.aasq *
    obj_2->TemperatureScaleFactor[0] + 1.0;
  proc_control_node_B.val_p[1] = proc_control_node_B.aasq *
    obj_2->TemperatureScaleFactor[1] + 1.0;
  proc_control_node_B.val_p[2] = proc_control_node_B.aasq *
    obj_2->TemperatureScaleFactor[2] + 1.0;
  varargout_3[0] = ((((proc_control_node_B.whiteNoiseDrift[0] +
                       proc_control_node_B.val[0]) + proc_control_node_B.tb) +
                     proc_control_node_B.temperatureDrift[0]) +
                    proc_control_node_B.magneticfield[0]) *
    proc_control_node_B.val_p[0];
  varargout_3[1] = ((((proc_control_node_B.whiteNoiseDrift[1] +
                       proc_control_node_B.val[1]) + proc_control_node_B.tc) +
                     proc_control_node_B.temperatureDrift[1]) +
                    proc_control_node_B.magneticfield[1]) *
    proc_control_node_B.val_p[1];
  varargout_3[2] = ((((proc_control_node_B.whiteNoiseDrift[2] +
                       proc_control_node_B.val[2]) + proc_control_node_B.n) +
                     proc_control_node_B.temperatureDrift[2]) +
                    proc_control_node_B.magneticfield[2]) *
    proc_control_node_B.val_p[2];
  proc_control_node_B.tb = obj_2->MeasurementRange;
  if (!rtIsInf(proc_control_node_B.tb)) {
    proc_control_node_B.tb = obj_2->MeasurementRange;
    proc_control_node_B.aasq = fabs(varargout_3[0]);
    proc_control_node_B.d_g[0] = (proc_control_node_B.aasq >
      proc_control_node_B.tb);
    proc_control_node_B.ab2 = fabs(varargout_3[1]);
    proc_control_node_B.d_g[1] = (proc_control_node_B.ab2 >
      proc_control_node_B.tb);
    proc_control_node_B.ac2 = fabs(varargout_3[2]);
    proc_control_node_B.d_g[2] = (proc_control_node_B.ac2 >
      proc_control_node_B.tb);
    proc_control_node_B.nx = 0;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
         proc_control_node_B.b_jcol++) {
      if (proc_control_node_B.d_g[proc_control_node_B.b_jcol]) {
        proc_control_node_B.b_data[proc_control_node_B.nx] = static_cast<int8_T>
          (proc_control_node_B.b_jcol + 1);
        proc_control_node_B.nx++;
      }
    }

    proc_control_node_B.d_g[0] = (proc_control_node_B.aasq >
      proc_control_node_B.tb);
    proc_control_node_B.d_g[1] = (proc_control_node_B.ab2 >
      proc_control_node_B.tb);
    proc_control_node_B.d_g[2] = (proc_control_node_B.ac2 >
      proc_control_node_B.tb);
    proc_control_node_B.nx = 0;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
         proc_control_node_B.b_jcol++) {
      if (proc_control_node_B.d_g[proc_control_node_B.b_jcol]) {
        proc_control_node_B.nx++;
      }
    }

    proc_control_node_B.f_size_idx_1 = proc_control_node_B.nx;
    proc_control_node_B.nx = 0;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol < 3;
         proc_control_node_B.b_jcol++) {
      if (proc_control_node_B.d_g[proc_control_node_B.b_jcol]) {
        proc_control_node_B.f_data[proc_control_node_B.nx] = static_cast<int8_T>
          (proc_control_node_B.b_jcol + 1);
        proc_control_node_B.nx++;
      }
    }

    proc_control_node_B.nx = proc_control_node_B.f_size_idx_1 - 1;
    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol <=
         proc_control_node_B.nx; proc_control_node_B.b_jcol++) {
      proc_control_node_B.b_x_data_tmp = proc_control_node_B.b_jcol;
      proc_control_node_B.magneticfield[proc_control_node_B.b_x_data_tmp] =
        varargout_3[proc_control_node_B.f_data[proc_control_node_B.b_x_data_tmp]
        - 1];
    }

    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol <=
         proc_control_node_B.nx; proc_control_node_B.b_jcol++) {
      proc_control_node_B.b_x_data_tmp = proc_control_node_B.b_jcol;
      proc_control_node_B.aasq =
        proc_control_node_B.magneticfield[proc_control_node_B.b_x_data_tmp];
      if (proc_control_node_B.aasq < 0.0) {
        proc_control_node_B.aasq = -1.0;
      } else if (proc_control_node_B.aasq > 0.0) {
        proc_control_node_B.aasq = 1.0;
      } else if (proc_control_node_B.aasq == 0.0) {
        proc_control_node_B.aasq = 0.0;
      } else {
        proc_control_node_B.aasq = (rtNaN);
      }

      proc_control_node_B.magneticfield[proc_control_node_B.b_x_data_tmp] =
        proc_control_node_B.aasq;
    }

    for (proc_control_node_B.b_jcol = 0; proc_control_node_B.b_jcol <
         proc_control_node_B.f_size_idx_1; proc_control_node_B.b_jcol++) {
      proc_control_node_B.nx = proc_control_node_B.b_jcol;
      varargout_3[proc_control_node_B.b_data[proc_control_node_B.nx] - 1] =
        proc_control_node_B.magneticfield[proc_control_node_B.nx] *
        proc_control_node_B.tb;
    }
  }

  if (obj_2->Resolution != 0.0) {
    proc_control_node_B.tb = obj_2->Resolution;
    varargout_3[0] = rt_roundd_snf(varargout_3[0] / proc_control_node_B.tb);
    varargout_3[1] = rt_roundd_snf(varargout_3[1] / proc_control_node_B.tb);
    varargout_3[2] = rt_roundd_snf(varargout_3[2] / proc_control_node_B.tb);
    varargout_3[0] *= proc_control_node_B.tb;
    varargout_3[1] *= proc_control_node_B.tb;
    varargout_3[2] *= proc_control_node_B.tb;
  }
}

static void IMUFusionCommon_computeAngularV(const real_T gfast[3], const real_T
  offset[3], real_T av[3])
{
  av[0] = gfast[0] - offset[0];
  av[1] = gfast[1] - offset[1];
  av[2] = gfast[2] - offset[2];
}

static void proc_control_node_NED_ecompass(const real_T a[3], const real_T m[3],
  real_T R[9])
{
  boolean_T exitg1;
  proc_control_node_B.Reast[0] = a[1] * m[2] - m[1] * a[2];
  proc_control_node_B.Reast[1] = m[0] * a[2] - a[0] * m[2];
  proc_control_node_B.Reast[2] = a[0] * m[1] - m[0] * a[1];
  R[6] = a[0];
  R[3] = proc_control_node_B.Reast[0];
  R[7] = a[1];
  R[4] = proc_control_node_B.Reast[1];
  R[8] = a[2];
  R[5] = proc_control_node_B.Reast[2];
  R[0] = proc_control_node_B.Reast[1] * a[2] - a[1] * proc_control_node_B.Reast
    [2];
  R[1] = a[0] * proc_control_node_B.Reast[2] - proc_control_node_B.Reast[0] * a
    [2];
  R[2] = proc_control_node_B.Reast[0] * a[1] - a[0] * proc_control_node_B.Reast
    [1];
  for (proc_control_node_B.iy_m = 0; proc_control_node_B.iy_m < 9;
       proc_control_node_B.iy_m++) {
    proc_control_node_B.R_o = R[proc_control_node_B.iy_m];
    proc_control_node_B.x[proc_control_node_B.iy_m] = proc_control_node_B.R_o *
      proc_control_node_B.R_o;
  }

  for (proc_control_node_B.iy_m = 0; proc_control_node_B.iy_m < 3;
       proc_control_node_B.iy_m++) {
    proc_control_node_B.xpageoffset = proc_control_node_B.iy_m * 3;
    proc_control_node_B.Reast[proc_control_node_B.iy_m] =
      proc_control_node_B.x[proc_control_node_B.xpageoffset + 2] +
      (proc_control_node_B.x[proc_control_node_B.xpageoffset + 1] +
       proc_control_node_B.x[proc_control_node_B.xpageoffset]);
  }

  proc_control_node_B.Reast[0] = sqrt(proc_control_node_B.Reast[0]);
  proc_control_node_B.Reast[1] = sqrt(proc_control_node_B.Reast[1]);
  proc_control_node_B.Reast[2] = sqrt(proc_control_node_B.Reast[2]);
  memcpy(&proc_control_node_B.x[0], &R[0], 9U * sizeof(real_T));
  proc_control_node_B.iy_m = 0;
  for (proc_control_node_B.xpageoffset = 0; proc_control_node_B.xpageoffset < 3;
       proc_control_node_B.xpageoffset++) {
    R[proc_control_node_B.iy_m] = proc_control_node_B.x[proc_control_node_B.iy_m]
      / proc_control_node_B.Reast[proc_control_node_B.xpageoffset];
    R[proc_control_node_B.iy_m + 1] =
      proc_control_node_B.x[proc_control_node_B.iy_m + 1] /
      proc_control_node_B.Reast[proc_control_node_B.xpageoffset];
    R[proc_control_node_B.iy_m + 2] =
      proc_control_node_B.x[proc_control_node_B.iy_m + 2] /
      proc_control_node_B.Reast[proc_control_node_B.xpageoffset];
    proc_control_node_B.iy_m += 3;
  }

  for (proc_control_node_B.iy_m = 0; proc_control_node_B.iy_m < 9;
       proc_control_node_B.iy_m++) {
    proc_control_node_B.b_a[proc_control_node_B.iy_m] = rtIsNaN
      (R[proc_control_node_B.iy_m]);
  }

  proc_control_node_B.y_j[0] = false;
  proc_control_node_B.y_j[1] = false;
  proc_control_node_B.y_j[2] = false;
  proc_control_node_B.iy_m = 1;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.iy_m <= 3)) {
    if (!proc_control_node_B.b_a[proc_control_node_B.iy_m - 1]) {
      proc_control_node_B.iy_m++;
    } else {
      proc_control_node_B.y_j[0] = true;
      exitg1 = true;
    }
  }

  proc_control_node_B.iy_m = 4;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.iy_m <= 6)) {
    if (!proc_control_node_B.b_a[proc_control_node_B.iy_m - 1]) {
      proc_control_node_B.iy_m++;
    } else {
      proc_control_node_B.y_j[1] = true;
      exitg1 = true;
    }
  }

  proc_control_node_B.iy_m = 7;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.iy_m <= 9)) {
    if (!proc_control_node_B.b_a[proc_control_node_B.iy_m - 1]) {
      proc_control_node_B.iy_m++;
    } else {
      proc_control_node_B.y_j[2] = true;
      exitg1 = true;
    }
  }

  proc_control_node_B.nanPageIdx = false;
  proc_control_node_B.iy_m = 0;
  exitg1 = false;
  while ((!exitg1) && (proc_control_node_B.iy_m < 3)) {
    if (!proc_control_node_B.y_j[proc_control_node_B.iy_m]) {
      proc_control_node_B.iy_m++;
    } else {
      proc_control_node_B.nanPageIdx = true;
      exitg1 = true;
    }
  }

  if (proc_control_node_B.nanPageIdx) {
    memset(&R[0], 0, 9U * sizeof(real_T));
    R[0] = 1.0;
    R[4] = 1.0;
    R[8] = 1.0;
  }
}

static void proc_cont_quaternion_quaternion(const real_T varargin_1[9], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  boolean_T exitg1;
  proc_control_node_B.tr = (varargin_1[0] + varargin_1[4]) + varargin_1[8];
  proc_control_node_B.psquared[0] = (proc_control_node_B.tr * 2.0 + 1.0) -
    proc_control_node_B.tr;
  proc_control_node_B.psquared[1] = (2.0 * varargin_1[0] + 1.0) -
    proc_control_node_B.tr;
  proc_control_node_B.psquared[2] = (2.0 * varargin_1[4] + 1.0) -
    proc_control_node_B.tr;
  proc_control_node_B.psquared[3] = (2.0 * varargin_1[8] + 1.0) -
    proc_control_node_B.tr;
  if (!rtIsNaN(proc_control_node_B.psquared[0])) {
    proc_control_node_B.b_idx = 1;
  } else {
    proc_control_node_B.b_idx = 0;
    proc_control_node_B.b_k_l = 2;
    exitg1 = false;
    while ((!exitg1) && (proc_control_node_B.b_k_l < 5)) {
      if (!rtIsNaN(proc_control_node_B.psquared[proc_control_node_B.b_k_l - 1]))
      {
        proc_control_node_B.b_idx = proc_control_node_B.b_k_l;
        exitg1 = true;
      } else {
        proc_control_node_B.b_k_l++;
      }
    }
  }

  if (proc_control_node_B.b_idx == 0) {
    proc_control_node_B.tr = proc_control_node_B.psquared[0];
    proc_control_node_B.b_idx = 1;
  } else {
    proc_control_node_B.tr =
      proc_control_node_B.psquared[proc_control_node_B.b_idx - 1];
    proc_control_node_B.b_m = proc_control_node_B.b_idx;
    for (proc_control_node_B.b_k_l = proc_control_node_B.b_m + 1;
         proc_control_node_B.b_k_l < 5; proc_control_node_B.b_k_l++) {
      proc_control_node_B.d4 =
        proc_control_node_B.psquared[proc_control_node_B.b_k_l - 1];
      if (proc_control_node_B.tr < proc_control_node_B.d4) {
        proc_control_node_B.tr = proc_control_node_B.d4;
        proc_control_node_B.b_idx = proc_control_node_B.b_k_l;
      }
    }
  }

  switch (proc_control_node_B.b_idx) {
   case 1:
    proc_control_node_B.tr = sqrt(proc_control_node_B.tr);
    *obj_a = 0.5 * proc_control_node_B.tr;
    proc_control_node_B.tr = 0.5 / proc_control_node_B.tr;
    *obj_b = (varargin_1[7] - varargin_1[5]) * proc_control_node_B.tr;
    *obj_c = (varargin_1[2] - varargin_1[6]) * proc_control_node_B.tr;
    *obj_d = (varargin_1[3] - varargin_1[1]) * proc_control_node_B.tr;
    break;

   case 2:
    proc_control_node_B.tr = sqrt(proc_control_node_B.tr);
    *obj_b = 0.5 * proc_control_node_B.tr;
    proc_control_node_B.tr = 0.5 / proc_control_node_B.tr;
    *obj_a = (varargin_1[7] - varargin_1[5]) * proc_control_node_B.tr;
    *obj_c = (varargin_1[1] + varargin_1[3]) * proc_control_node_B.tr;
    *obj_d = (varargin_1[2] + varargin_1[6]) * proc_control_node_B.tr;
    break;

   case 3:
    proc_control_node_B.tr = sqrt(proc_control_node_B.tr);
    *obj_c = 0.5 * proc_control_node_B.tr;
    proc_control_node_B.tr = 0.5 / proc_control_node_B.tr;
    *obj_a = (varargin_1[2] - varargin_1[6]) * proc_control_node_B.tr;
    *obj_b = (varargin_1[1] + varargin_1[3]) * proc_control_node_B.tr;
    *obj_d = (varargin_1[5] + varargin_1[7]) * proc_control_node_B.tr;
    break;

   default:
    proc_control_node_B.tr = sqrt(proc_control_node_B.tr);
    *obj_d = 0.5 * proc_control_node_B.tr;
    proc_control_node_B.tr = 0.5 / proc_control_node_B.tr;
    *obj_a = (varargin_1[3] - varargin_1[1]) * proc_control_node_B.tr;
    *obj_b = (varargin_1[2] + varargin_1[6]) * proc_control_node_B.tr;
    *obj_c = (varargin_1[5] + varargin_1[7]) * proc_control_node_B.tr;
    break;
  }

  if (*obj_a < 0.0) {
    *obj_a = -*obj_a;
    *obj_b = -*obj_b;
    *obj_c = -*obj_c;
    *obj_d = -*obj_d;
  }
}

static void proc_co_quaternion_quaternion_b(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  *obj_a = 1.0;
  *obj_b = 0.0;
  *obj_c = 0.0;
  *obj_d = 0.0;
  proc_control_node_B.theta = sqrt((varargin_1[0] * varargin_1[0] + varargin_1[1]
    * varargin_1[1]) + varargin_1[2] * varargin_1[2]);
  proc_control_node_B.st = sin(proc_control_node_B.theta / 2.0);
  if (proc_control_node_B.theta != 0.0) {
    *obj_a = cos(proc_control_node_B.theta / 2.0);
    *obj_b = varargin_1[0] / proc_control_node_B.theta * proc_control_node_B.st;
    *obj_c = varargin_1[1] / proc_control_node_B.theta * proc_control_node_B.st;
    *obj_d = varargin_1[2] / proc_control_node_B.theta * proc_control_node_B.st;
  }
}

static void IMUFusionCommon_predictOrientat(const
  fusion_simulink_ahrsfilter_pr_T *obj, const real_T gfast[3], const real_T
  offset[3], real_T qorient_a, real_T qorient_b, real_T qorient_c, real_T
  qorient_d, real_T *b_qorient_a, real_T *b_qorient_b, real_T *b_qorient_c,
  real_T *b_qorient_d)
{
  proc_control_node_B.c_p[0] = (gfast[0] - offset[0]) * obj->pSensorPeriod;
  proc_control_node_B.c_p[1] = (gfast[1] - offset[1]) * obj->pSensorPeriod;
  proc_control_node_B.c_p[2] = (gfast[2] - offset[2]) * obj->pSensorPeriod;
  proc_co_quaternion_quaternion_b(proc_control_node_B.c_p,
    &proc_control_node_B.deltaq_a, &proc_control_node_B.deltaq_b,
    &proc_control_node_B.deltaq_c, &proc_control_node_B.deltaq_d);
  *b_qorient_a = ((qorient_a * proc_control_node_B.deltaq_a - qorient_b *
                   proc_control_node_B.deltaq_b) - qorient_c *
                  proc_control_node_B.deltaq_c) - qorient_d *
    proc_control_node_B.deltaq_d;
  *b_qorient_b = ((qorient_a * proc_control_node_B.deltaq_b + qorient_b *
                   proc_control_node_B.deltaq_a) + qorient_c *
                  proc_control_node_B.deltaq_d) - qorient_d *
    proc_control_node_B.deltaq_c;
  *b_qorient_c = ((qorient_a * proc_control_node_B.deltaq_c - qorient_b *
                   proc_control_node_B.deltaq_d) + qorient_c *
                  proc_control_node_B.deltaq_a) + qorient_d *
    proc_control_node_B.deltaq_b;
  *b_qorient_d = ((qorient_a * proc_control_node_B.deltaq_d + qorient_b *
                   proc_control_node_B.deltaq_c) - qorient_c *
                  proc_control_node_B.deltaq_b) + qorient_d *
    proc_control_node_B.deltaq_a;
  if (*b_qorient_a < 0.0) {
    *b_qorient_a = -*b_qorient_a;
    *b_qorient_b = -*b_qorient_b;
    *b_qorient_c = -*b_qorient_c;
    *b_qorient_d = -*b_qorient_d;
  }
}

static void proc_cont_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9])
{
  proc_control_node_B.n_c = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d *
    q_d);
  q_a /= proc_control_node_B.n_c;
  q_b /= proc_control_node_B.n_c;
  q_c /= proc_control_node_B.n_c;
  q_d /= proc_control_node_B.n_c;
  proc_control_node_B.n_c = q_a * q_b * 2.0;
  proc_control_node_B.ac2_p = q_a * q_c * 2.0;
  proc_control_node_B.ad2_o = q_a * q_d * 2.0;
  proc_control_node_B.bc2_l = q_b * q_c * 2.0;
  proc_control_node_B.bd2_k = q_b * q_d * 2.0;
  proc_control_node_B.cd2_j = q_c * q_d * 2.0;
  proc_control_node_B.aasq_f = q_a * q_a * 2.0 - 1.0;
  r[0] = q_b * q_b * 2.0 + proc_control_node_B.aasq_f;
  r[3] = proc_control_node_B.bc2_l + proc_control_node_B.ad2_o;
  r[6] = proc_control_node_B.bd2_k - proc_control_node_B.ac2_p;
  r[1] = proc_control_node_B.bc2_l - proc_control_node_B.ad2_o;
  r[4] = q_c * q_c * 2.0 + proc_control_node_B.aasq_f;
  r[7] = proc_control_node_B.cd2_j + proc_control_node_B.n_c;
  r[2] = proc_control_node_B.bd2_k + proc_control_node_B.ac2_p;
  r[5] = proc_control_node_B.cd2_j - proc_control_node_B.n_c;
  r[8] = q_d * q_d * 2.0 + proc_control_node_B.aasq_f;
}

static void proc_control_node_mrdiv(const real_T A[72], const real_T B[36],
  real_T Y[72])
{
  memcpy(&proc_control_node_B.c_A_b[0], &B[0], 36U * sizeof(real_T));
  for (proc_control_node_B.jp = 0; proc_control_node_B.jp < 6;
       proc_control_node_B.jp++) {
    proc_control_node_B.b_ipiv[proc_control_node_B.jp] = static_cast<int8_T>
      (proc_control_node_B.jp + 1);
  }

  for (proc_control_node_B.jp = 0; proc_control_node_B.jp < 5;
       proc_control_node_B.jp++) {
    proc_control_node_B.jBcol = proc_control_node_B.jp * 7 + 2;
    proc_control_node_B.jj = proc_control_node_B.jp * 7;
    proc_control_node_B.c_e = 6 - proc_control_node_B.jp;
    proc_control_node_B.iy_b = 1;
    proc_control_node_B.smax_o = fabs
      (proc_control_node_B.c_A_b[proc_control_node_B.jj]);
    for (proc_control_node_B.jA_a = 2; proc_control_node_B.jA_a <=
         proc_control_node_B.c_e; proc_control_node_B.jA_a++) {
      proc_control_node_B.s_k = fabs(proc_control_node_B.c_A_b
        [(proc_control_node_B.jBcol + proc_control_node_B.jA_a) - 3]);
      if (proc_control_node_B.s_k > proc_control_node_B.smax_o) {
        proc_control_node_B.iy_b = proc_control_node_B.jA_a;
        proc_control_node_B.smax_o = proc_control_node_B.s_k;
      }
    }

    if (proc_control_node_B.c_A_b[(proc_control_node_B.jBcol +
         proc_control_node_B.iy_b) - 3] != 0.0) {
      if (proc_control_node_B.iy_b - 1 != 0) {
        proc_control_node_B.c_e = proc_control_node_B.jp +
          proc_control_node_B.iy_b;
        proc_control_node_B.b_ipiv[proc_control_node_B.jp] = static_cast<int8_T>
          (proc_control_node_B.c_e);
        for (proc_control_node_B.jA_a = 0; proc_control_node_B.jA_a < 6;
             proc_control_node_B.jA_a++) {
          proc_control_node_B.iy_b = proc_control_node_B.jA_a * 6 +
            proc_control_node_B.jp;
          proc_control_node_B.smax_o =
            proc_control_node_B.c_A_b[proc_control_node_B.iy_b];
          proc_control_node_B.kBcol = (proc_control_node_B.jA_a * 6 +
            proc_control_node_B.c_e) - 1;
          proc_control_node_B.c_A_b[proc_control_node_B.iy_b] =
            proc_control_node_B.c_A_b[proc_control_node_B.kBcol];
          proc_control_node_B.c_A_b[proc_control_node_B.kBcol] =
            proc_control_node_B.smax_o;
        }
      }

      proc_control_node_B.iy_b = proc_control_node_B.jBcol -
        proc_control_node_B.jp;
      for (proc_control_node_B.jA_a = proc_control_node_B.jBcol;
           proc_control_node_B.jA_a <= proc_control_node_B.iy_b + 4;
           proc_control_node_B.jA_a++) {
        proc_control_node_B.c_A_b[proc_control_node_B.jA_a - 1] /=
          proc_control_node_B.c_A_b[proc_control_node_B.jj];
      }
    }

    proc_control_node_B.c_e = 5 - proc_control_node_B.jp;
    proc_control_node_B.jA_a = proc_control_node_B.jj;
    proc_control_node_B.jj += 6;
    for (proc_control_node_B.jp1j = 0; proc_control_node_B.jp1j <
         proc_control_node_B.c_e; proc_control_node_B.jp1j++) {
      proc_control_node_B.smax_o =
        proc_control_node_B.c_A_b[proc_control_node_B.jp1j * 6 +
        proc_control_node_B.jj];
      if (proc_control_node_B.smax_o != 0.0) {
        proc_control_node_B.iy_b = proc_control_node_B.jA_a + 8;
        proc_control_node_B.kBcol = proc_control_node_B.jA_a -
          proc_control_node_B.jp;
        for (proc_control_node_B.ijA_i = proc_control_node_B.iy_b;
             proc_control_node_B.ijA_i <= proc_control_node_B.kBcol + 12;
             proc_control_node_B.ijA_i++) {
          proc_control_node_B.c_A_b[proc_control_node_B.ijA_i - 1] +=
            proc_control_node_B.c_A_b[((proc_control_node_B.jBcol +
            proc_control_node_B.ijA_i) - proc_control_node_B.jA_a) - 9] *
            -proc_control_node_B.smax_o;
        }
      }

      proc_control_node_B.jA_a += 6;
    }
  }

  memcpy(&Y[0], &A[0], 72U * sizeof(real_T));
  for (proc_control_node_B.jp = 0; proc_control_node_B.jp < 6;
       proc_control_node_B.jp++) {
    proc_control_node_B.jBcol = 12 * proc_control_node_B.jp - 1;
    proc_control_node_B.jj = 6 * proc_control_node_B.jp - 1;
    proc_control_node_B.iy_b = proc_control_node_B.jp - 1;
    for (proc_control_node_B.jp1j = 0; proc_control_node_B.jp1j <=
         proc_control_node_B.iy_b; proc_control_node_B.jp1j++) {
      proc_control_node_B.kBcol = 12 * proc_control_node_B.jp1j - 1;
      if (proc_control_node_B.c_A_b[(proc_control_node_B.jp1j +
           proc_control_node_B.jj) + 1] != 0.0) {
        for (proc_control_node_B.c_e = 0; proc_control_node_B.c_e < 12;
             proc_control_node_B.c_e++) {
          proc_control_node_B.ijA_i = (proc_control_node_B.c_e +
            proc_control_node_B.jBcol) + 1;
          Y[proc_control_node_B.ijA_i] -= proc_control_node_B.c_A_b
            [(proc_control_node_B.jp1j + proc_control_node_B.jj) + 1] * Y
            [(proc_control_node_B.c_e + proc_control_node_B.kBcol) + 1];
        }
      }
    }

    proc_control_node_B.smax_o = 1.0 / proc_control_node_B.c_A_b
      [(proc_control_node_B.jp + proc_control_node_B.jj) + 1];
    for (proc_control_node_B.jp1j = 0; proc_control_node_B.jp1j < 12;
         proc_control_node_B.jp1j++) {
      proc_control_node_B.ijA_i = (proc_control_node_B.jp1j +
        proc_control_node_B.jBcol) + 1;
      Y[proc_control_node_B.ijA_i] *= proc_control_node_B.smax_o;
    }
  }

  for (proc_control_node_B.jp1j = 5; proc_control_node_B.jp1j >= 0;
       proc_control_node_B.jp1j--) {
    proc_control_node_B.jBcol = 12 * proc_control_node_B.jp1j - 1;
    proc_control_node_B.jj = 6 * proc_control_node_B.jp1j - 1;
    for (proc_control_node_B.jA_a = proc_control_node_B.jp1j + 2;
         proc_control_node_B.jA_a < 7; proc_control_node_B.jA_a++) {
      proc_control_node_B.kBcol = (proc_control_node_B.jA_a - 1) * 12 - 1;
      proc_control_node_B.smax_o =
        proc_control_node_B.c_A_b[proc_control_node_B.jA_a +
        proc_control_node_B.jj];
      if (proc_control_node_B.smax_o != 0.0) {
        for (proc_control_node_B.c_e = 0; proc_control_node_B.c_e < 12;
             proc_control_node_B.c_e++) {
          proc_control_node_B.ijA_i = (proc_control_node_B.c_e +
            proc_control_node_B.jBcol) + 1;
          Y[proc_control_node_B.ijA_i] -= Y[(proc_control_node_B.c_e +
            proc_control_node_B.kBcol) + 1] * proc_control_node_B.smax_o;
        }
      }
    }
  }

  for (proc_control_node_B.jp1j = 4; proc_control_node_B.jp1j >= 0;
       proc_control_node_B.jp1j--) {
    proc_control_node_B.b_ipiv_i =
      proc_control_node_B.b_ipiv[proc_control_node_B.jp1j];
    if (proc_control_node_B.jp1j + 1 != proc_control_node_B.b_ipiv_i) {
      for (proc_control_node_B.c_e = 0; proc_control_node_B.c_e < 12;
           proc_control_node_B.c_e++) {
        proc_control_node_B.iy_b = 12 * proc_control_node_B.jp1j +
          proc_control_node_B.c_e;
        proc_control_node_B.smax_o = Y[proc_control_node_B.iy_b];
        proc_control_node_B.ijA_i = 12 * (proc_control_node_B.b_ipiv_i - 1) +
          proc_control_node_B.c_e;
        Y[proc_control_node_B.iy_b] = Y[proc_control_node_B.ijA_i];
        Y[proc_control_node_B.ijA_i] = proc_control_node_B.smax_o;
      }
    }
  }
}

static void proc_contro_ahrsfilter_stepImpl(fusion_simulink_ahrsfilter_pr_T *obj,
  const real_T accelIn[3], const real_T gyroIn[3], const real_T magIn[3], real_T
  orientOut[4], real_T av[3])
{
  static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T tmp_0[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  IMUFusionCommon_computeAngularV(gyroIn, obj->pGyroOffset, av);
  if (obj->pFirstTime) {
    obj->pFirstTime = false;
    proc_control_node_NED_ecompass(accelIn, magIn, proc_control_node_B.Rprior);
    proc_cont_quaternion_quaternion(proc_control_node_B.Rprior,
      &obj->pOrientPost.a, &obj->pOrientPost.b, &obj->pOrientPost.c,
      &obj->pOrientPost.d);
  }

  for (proc_control_node_B.i16 = 0; proc_control_node_B.i16 < 3;
       proc_control_node_B.i16++) {
    proc_control_node_B.gravityAccelGyroDiff[proc_control_node_B.i16] =
      obj->pGyroOffset[proc_control_node_B.i16];
  }

  IMUFusionCommon_predictOrientat(obj, gyroIn,
    proc_control_node_B.gravityAccelGyroDiff, obj->pOrientPost.a,
    obj->pOrientPost.b, obj->pOrientPost.c, obj->pOrientPost.d,
    &proc_control_node_B.s_i, &proc_control_node_B.scale,
    &proc_control_node_B.absxk, &proc_control_node_B.t);
  obj->pOrientPrior.d = proc_control_node_B.t;
  obj->pOrientPrior.c = proc_control_node_B.absxk;
  obj->pOrientPrior.b = proc_control_node_B.scale;
  obj->pOrientPrior.a = proc_control_node_B.s_i;
  proc_cont_quaternionBase_rotmat(obj->pOrientPrior.a, obj->pOrientPrior.b,
    obj->pOrientPrior.c, obj->pOrientPrior.d, proc_control_node_B.Rprior);
  for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 3;
       proc_control_node_B.b_i_e++) {
    obj->pLinAccelPrior[proc_control_node_B.b_i_e] =
      obj->LinearAccelerationDecayFactor * obj->
      pLinAccelPost[proc_control_node_B.b_i_e];
    proc_control_node_B.s_i =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 6];
    proc_control_node_B.gravityAccelGyroDiff[proc_control_node_B.b_i_e] =
      (accelIn[proc_control_node_B.b_i_e] + obj->
       pLinAccelPrior[proc_control_node_B.b_i_e]) - proc_control_node_B.s_i;
    proc_control_node_B.offDiag[proc_control_node_B.b_i_e] = 0.0;
    proc_control_node_B.offDiag[proc_control_node_B.b_i_e] +=
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e] * obj->pMagVec[0];
    proc_control_node_B.offDiag[proc_control_node_B.b_i_e] +=
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 3] * obj->pMagVec[1];
    proc_control_node_B.offDiag[proc_control_node_B.b_i_e] +=
      proc_control_node_B.s_i * obj->pMagVec[2];
  }

  memset(&proc_control_node_B.h1[0], 0, 9U * sizeof(real_T));
  proc_control_node_B.h1[3] = proc_control_node_B.Rprior[8];
  proc_control_node_B.h1[6] = -proc_control_node_B.Rprior[7];
  proc_control_node_B.h1[7] = proc_control_node_B.Rprior[6];
  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 3;
       proc_control_node_B.aoffset++) {
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e] =
      proc_control_node_B.h1[proc_control_node_B.b_i_e];
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e + 1] =
      proc_control_node_B.h1[proc_control_node_B.b_i_e + 1] -
      proc_control_node_B.h1[proc_control_node_B.aoffset + 3];
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e + 2] =
      proc_control_node_B.h1[proc_control_node_B.b_i_e + 2] -
      proc_control_node_B.h1[proc_control_node_B.aoffset + 6];
    proc_control_node_B.b_i_e += 3;
  }

  for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 9;
       proc_control_node_B.b_i_e++) {
    proc_control_node_B.h1[proc_control_node_B.b_i_e] =
      proc_control_node_B.h1_f[proc_control_node_B.b_i_e];
    proc_control_node_B.Rprior[proc_control_node_B.b_i_e] = 0.0;
  }

  proc_control_node_B.Rprior[3] = proc_control_node_B.offDiag[2];
  proc_control_node_B.Rprior[6] = -proc_control_node_B.offDiag[1];
  proc_control_node_B.Rprior[7] = proc_control_node_B.offDiag[0];
  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 3;
       proc_control_node_B.aoffset++) {
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e] =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e];
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e + 1] =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 1] -
      proc_control_node_B.Rprior[proc_control_node_B.aoffset + 3];
    proc_control_node_B.h1_f[proc_control_node_B.b_i_e + 2] =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 2] -
      proc_control_node_B.Rprior[proc_control_node_B.aoffset + 6];
    proc_control_node_B.b_i_e += 3;
  }

  memcpy(&proc_control_node_B.Rprior[0], &proc_control_node_B.h1_f[0], 9U *
         sizeof(real_T));
  proc_control_node_B.b_i_e = 0;
  proc_control_node_B.aoffset = 0;
  for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 3;
       proc_control_node_B.i13++) {
    proc_control_node_B.s_i =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e];
    proc_control_node_B.scale = proc_control_node_B.h1[proc_control_node_B.b_i_e];
    proc_control_node_B.H[proc_control_node_B.aoffset] =
      proc_control_node_B.scale;
    proc_control_node_B.H[proc_control_node_B.aoffset + 18] =
      -proc_control_node_B.scale * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 36] =
      tmp[proc_control_node_B.b_i_e];
    proc_control_node_B.H[proc_control_node_B.aoffset + 54] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 3] =
      proc_control_node_B.s_i;
    proc_control_node_B.H[proc_control_node_B.aoffset + 21] =
      -proc_control_node_B.s_i * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 39] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 57] =
      tmp_0[proc_control_node_B.b_i_e];
    proc_control_node_B.s_i =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 1];
    proc_control_node_B.scale = proc_control_node_B.h1[proc_control_node_B.b_i_e
      + 1];
    proc_control_node_B.H[proc_control_node_B.aoffset + 1] =
      proc_control_node_B.scale;
    proc_control_node_B.H[proc_control_node_B.aoffset + 19] =
      -proc_control_node_B.scale * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 37] =
      tmp[proc_control_node_B.b_i_e + 1];
    proc_control_node_B.H[proc_control_node_B.aoffset + 55] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 4] =
      proc_control_node_B.s_i;
    proc_control_node_B.H[proc_control_node_B.aoffset + 22] =
      -proc_control_node_B.s_i * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 40] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 58] =
      tmp_0[proc_control_node_B.b_i_e + 1];
    proc_control_node_B.s_i =
      proc_control_node_B.Rprior[proc_control_node_B.b_i_e + 2];
    proc_control_node_B.scale = proc_control_node_B.h1[proc_control_node_B.b_i_e
      + 2];
    proc_control_node_B.H[proc_control_node_B.aoffset + 2] =
      proc_control_node_B.scale;
    proc_control_node_B.H[proc_control_node_B.aoffset + 20] =
      -proc_control_node_B.scale * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 38] =
      tmp[proc_control_node_B.b_i_e + 2];
    proc_control_node_B.H[proc_control_node_B.aoffset + 56] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 5] =
      proc_control_node_B.s_i;
    proc_control_node_B.H[proc_control_node_B.aoffset + 23] =
      -proc_control_node_B.s_i * obj->pKalmanPeriod;
    proc_control_node_B.H[proc_control_node_B.aoffset + 41] = 0.0;
    proc_control_node_B.H[proc_control_node_B.aoffset + 59] =
      tmp_0[proc_control_node_B.b_i_e + 2];
    proc_control_node_B.b_i_e += 3;
    proc_control_node_B.aoffset += 6;
  }

  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 6;
       proc_control_node_B.aoffset++) {
    proc_control_node_B.i13 = 0;
    for (proc_control_node_B.obj_tmp = 0; proc_control_node_B.obj_tmp < 12;
         proc_control_node_B.obj_tmp++) {
      proc_control_node_B.K[proc_control_node_B.obj_tmp +
        proc_control_node_B.b_i_e] =
        proc_control_node_B.H[proc_control_node_B.i13 +
        proc_control_node_B.aoffset];
      proc_control_node_B.i13 += 6;
    }

    proc_control_node_B.b_i_e += 12;
  }

  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 12;
       proc_control_node_B.aoffset++) {
    for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
         proc_control_node_B.i13++) {
      proc_control_node_B.H_l[proc_control_node_B.i13 +
        proc_control_node_B.b_i_e] = 0.0;
    }

    proc_control_node_B.b_i_e += 6;
  }

  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
       proc_control_node_B.i13++) {
    proc_control_node_B.obj_tmp = 0;
    proc_control_node_B.i15 = 0;
    for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 12;
         proc_control_node_B.aoffset++) {
      proc_control_node_B.Ppost_tmp = 0;
      for (proc_control_node_B.i14 = 0; proc_control_node_B.i14 < 12;
           proc_control_node_B.i14++) {
        proc_control_node_B.H_tmp = proc_control_node_B.obj_tmp +
          proc_control_node_B.i13;
        proc_control_node_B.H_l[proc_control_node_B.H_tmp] +=
          proc_control_node_B.H[proc_control_node_B.Ppost_tmp +
          proc_control_node_B.i13] * obj->pQw[proc_control_node_B.i14 +
          proc_control_node_B.i15];
        proc_control_node_B.Ppost_tmp += 6;
      }

      proc_control_node_B.obj[proc_control_node_B.aoffset +
        proc_control_node_B.b_i_e] = 0.0;
      proc_control_node_B.obj_tmp += 6;
      proc_control_node_B.i15 += 12;
    }

    proc_control_node_B.b_i_e += 12;
  }

  for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 6;
       proc_control_node_B.b_i_e++) {
    for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 12;
         proc_control_node_B.aoffset++) {
      for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 12;
           proc_control_node_B.i13++) {
        proc_control_node_B.obj_tmp = 12 * proc_control_node_B.b_i_e +
          proc_control_node_B.aoffset;
        proc_control_node_B.obj[proc_control_node_B.obj_tmp] += obj->pQw[12 *
          proc_control_node_B.i13 + proc_control_node_B.aoffset] *
          proc_control_node_B.K[12 * proc_control_node_B.b_i_e +
          proc_control_node_B.i13];
      }
    }

    for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 6;
         proc_control_node_B.aoffset++) {
      proc_control_node_B.s_i = 0.0;
      for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 12;
           proc_control_node_B.i13++) {
        proc_control_node_B.s_i += proc_control_node_B.H_l[6 *
          proc_control_node_B.i13 + proc_control_node_B.aoffset] *
          proc_control_node_B.K[12 * proc_control_node_B.b_i_e +
          proc_control_node_B.i13];
      }

      proc_control_node_B.H_o[proc_control_node_B.b_i_e + 6 *
        proc_control_node_B.aoffset] = obj->pQv[6 * proc_control_node_B.b_i_e +
        proc_control_node_B.aoffset] + proc_control_node_B.s_i;
    }
  }

  proc_control_node_mrdiv(proc_control_node_B.obj, proc_control_node_B.H_o,
    proc_control_node_B.K);
  proc_control_node_B.ze[0] = proc_control_node_B.gravityAccelGyroDiff[0];
  proc_control_node_B.ze[3] = magIn[0] - proc_control_node_B.offDiag[0];
  proc_control_node_B.ze[1] = proc_control_node_B.gravityAccelGyroDiff[1];
  proc_control_node_B.ze[4] = magIn[1] - proc_control_node_B.offDiag[1];
  proc_control_node_B.ze[2] = proc_control_node_B.gravityAccelGyroDiff[2];
  proc_control_node_B.ze[5] = magIn[2] - proc_control_node_B.offDiag[2];
  for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 3;
       proc_control_node_B.b_i_e++) {
    proc_control_node_B.offDiag[proc_control_node_B.b_i_e] = 0.0;
    proc_control_node_B.aoffset = 0;
    for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
         proc_control_node_B.i13++) {
      proc_control_node_B.offDiag[proc_control_node_B.b_i_e] +=
        proc_control_node_B.K[(proc_control_node_B.aoffset +
        proc_control_node_B.b_i_e) + 9] *
        proc_control_node_B.ze[proc_control_node_B.i13];
      proc_control_node_B.aoffset += 12;
    }
  }

  proc_control_node_B.scale = 3.3121686421112381E-170;
  proc_control_node_B.absxk = fabs(proc_control_node_B.offDiag[0]);
  if (proc_control_node_B.absxk > 3.3121686421112381E-170) {
    proc_control_node_B.s_i = 1.0;
    proc_control_node_B.scale = proc_control_node_B.absxk;
  } else {
    proc_control_node_B.t = proc_control_node_B.absxk / 3.3121686421112381E-170;
    proc_control_node_B.s_i = proc_control_node_B.t * proc_control_node_B.t;
  }

  proc_control_node_B.absxk = fabs(proc_control_node_B.offDiag[1]);
  if (proc_control_node_B.absxk > proc_control_node_B.scale) {
    proc_control_node_B.t = proc_control_node_B.scale /
      proc_control_node_B.absxk;
    proc_control_node_B.s_i = proc_control_node_B.s_i * proc_control_node_B.t *
      proc_control_node_B.t + 1.0;
    proc_control_node_B.scale = proc_control_node_B.absxk;
  } else {
    proc_control_node_B.t = proc_control_node_B.absxk /
      proc_control_node_B.scale;
    proc_control_node_B.s_i += proc_control_node_B.t * proc_control_node_B.t;
  }

  proc_control_node_B.absxk = fabs(proc_control_node_B.offDiag[2]);
  if (proc_control_node_B.absxk > proc_control_node_B.scale) {
    proc_control_node_B.t = proc_control_node_B.scale /
      proc_control_node_B.absxk;
    proc_control_node_B.s_i = proc_control_node_B.s_i * proc_control_node_B.t *
      proc_control_node_B.t + 1.0;
    proc_control_node_B.scale = proc_control_node_B.absxk;
  } else {
    proc_control_node_B.t = proc_control_node_B.absxk /
      proc_control_node_B.scale;
    proc_control_node_B.s_i += proc_control_node_B.t * proc_control_node_B.t;
  }

  proc_control_node_B.s_i = proc_control_node_B.scale * sqrt
    (proc_control_node_B.s_i);
  proc_control_node_B.isJamming = (proc_control_node_B.s_i *
    proc_control_node_B.s_i > obj->ExpectedMagneticFieldStrength *
    obj->ExpectedMagneticFieldStrength * 4.0);
  if (proc_control_node_B.isJamming) {
    for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 9;
         proc_control_node_B.b_i_e++) {
      proc_control_node_B.h1[proc_control_node_B.b_i_e] = 0.0;
      proc_control_node_B.h1[proc_control_node_B.b_i_e] +=
        proc_control_node_B.K[proc_control_node_B.b_i_e] *
        proc_control_node_B.gravityAccelGyroDiff[0];
      proc_control_node_B.h1[proc_control_node_B.b_i_e] +=
        proc_control_node_B.K[proc_control_node_B.b_i_e + 12] *
        proc_control_node_B.gravityAccelGyroDiff[1];
      proc_control_node_B.h1[proc_control_node_B.b_i_e] +=
        proc_control_node_B.K[proc_control_node_B.b_i_e + 24] *
        proc_control_node_B.gravityAccelGyroDiff[2];
    }

    proc_control_node_B.gravityAccelGyroDiff[0] = proc_control_node_B.h1[0];
    proc_control_node_B.gyroOffsetErr_idx_0 = proc_control_node_B.h1[3];
    proc_control_node_B.linAccelErr_idx_0 = proc_control_node_B.h1[6];
    proc_control_node_B.gravityAccelGyroDiff[1] = proc_control_node_B.h1[1];
    proc_control_node_B.gyroOffsetErr_idx_1 = proc_control_node_B.h1[4];
    proc_control_node_B.linAccelErr_idx_1 = proc_control_node_B.h1[7];
    proc_control_node_B.gravityAccelGyroDiff[2] = proc_control_node_B.h1[2];
    proc_control_node_B.gyroOffsetErr_idx_2 = proc_control_node_B.h1[5];
    proc_control_node_B.linAccelErr_idx_2 = proc_control_node_B.h1[8];
  } else {
    memset(&proc_control_node_B.xe_post[0], 0, 12U * sizeof(real_T));
    proc_control_node_B.aoffset = 0;
    for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
         proc_control_node_B.i13++) {
      for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 12;
           proc_control_node_B.b_i_e++) {
        proc_control_node_B.xe_post[proc_control_node_B.b_i_e] +=
          proc_control_node_B.K[proc_control_node_B.b_i_e +
          proc_control_node_B.aoffset] *
          proc_control_node_B.ze[proc_control_node_B.i13];
      }

      proc_control_node_B.aoffset += 12;
    }

    proc_control_node_B.gravityAccelGyroDiff[0] = proc_control_node_B.xe_post[0];
    proc_control_node_B.gyroOffsetErr_idx_0 = proc_control_node_B.xe_post[3];
    proc_control_node_B.linAccelErr_idx_0 = proc_control_node_B.xe_post[6];
    proc_control_node_B.gravityAccelGyroDiff[1] = proc_control_node_B.xe_post[1];
    proc_control_node_B.gyroOffsetErr_idx_1 = proc_control_node_B.xe_post[4];
    proc_control_node_B.linAccelErr_idx_1 = proc_control_node_B.xe_post[7];
    proc_control_node_B.gravityAccelGyroDiff[2] = proc_control_node_B.xe_post[2];
    proc_control_node_B.gyroOffsetErr_idx_2 = proc_control_node_B.xe_post[5];
    proc_control_node_B.linAccelErr_idx_2 = proc_control_node_B.xe_post[8];
  }

  proc_co_quaternion_quaternion_b(proc_control_node_B.gravityAccelGyroDiff,
    &proc_control_node_B.s_i, &proc_control_node_B.scale,
    &proc_control_node_B.absxk, &proc_control_node_B.t);
  proc_control_node_B.x_a = obj->pOrientPrior.a;
  proc_control_node_B.x_b = obj->pOrientPrior.b;
  proc_control_node_B.x_c = obj->pOrientPrior.c;
  proc_control_node_B.x_d = obj->pOrientPrior.d;
  obj->pOrientPost.a = ((obj->pOrientPrior.a * proc_control_node_B.s_i -
    obj->pOrientPrior.b * -proc_control_node_B.scale) - obj->pOrientPrior.c *
                        -proc_control_node_B.absxk) - obj->pOrientPrior.d *
    -proc_control_node_B.t;
  obj->pOrientPost.b = ((proc_control_node_B.x_a * -proc_control_node_B.scale +
    proc_control_node_B.x_b * proc_control_node_B.s_i) + proc_control_node_B.x_c
                        * -proc_control_node_B.t) - proc_control_node_B.x_d *
    -proc_control_node_B.absxk;
  obj->pOrientPost.c = ((proc_control_node_B.x_a * -proc_control_node_B.absxk -
    proc_control_node_B.x_b * -proc_control_node_B.t) + proc_control_node_B.x_c *
                        proc_control_node_B.s_i) + proc_control_node_B.x_d *
    -proc_control_node_B.scale;
  obj->pOrientPost.d = ((proc_control_node_B.x_a * -proc_control_node_B.t +
    proc_control_node_B.x_b * -proc_control_node_B.absxk) -
                        proc_control_node_B.x_c * -proc_control_node_B.scale) +
    proc_control_node_B.x_d * proc_control_node_B.s_i;
  if (obj->pOrientPost.a < 0.0) {
    proc_control_node_B.s_i = obj->pOrientPost.b;
    proc_control_node_B.scale = obj->pOrientPost.c;
    proc_control_node_B.absxk = obj->pOrientPost.d;
    obj->pOrientPost.a = -obj->pOrientPost.a;
    obj->pOrientPost.b = -proc_control_node_B.s_i;
    obj->pOrientPost.c = -proc_control_node_B.scale;
    obj->pOrientPost.d = -proc_control_node_B.absxk;
  }

  proc_control_node_B.s_i = obj->pOrientPost.b;
  proc_control_node_B.scale = obj->pOrientPost.c;
  proc_control_node_B.absxk = obj->pOrientPost.d;
  proc_control_node_B.t = sqrt(((obj->pOrientPost.a * obj->pOrientPost.a +
    obj->pOrientPost.b * obj->pOrientPost.b) + obj->pOrientPost.c *
    obj->pOrientPost.c) + obj->pOrientPost.d * obj->pOrientPost.d);
  obj->pOrientPost.a /= proc_control_node_B.t;
  obj->pOrientPost.b = proc_control_node_B.s_i / proc_control_node_B.t;
  obj->pOrientPost.c = proc_control_node_B.scale / proc_control_node_B.t;
  obj->pOrientPost.d = proc_control_node_B.absxk / proc_control_node_B.t;
  proc_cont_quaternionBase_rotmat(obj->pOrientPost.a, obj->pOrientPost.b,
    obj->pOrientPost.c, obj->pOrientPost.d, proc_control_node_B.h1);
  obj->pGyroOffset[0] -= proc_control_node_B.gyroOffsetErr_idx_0;
  obj->pLinAccelPost[0] = obj->pLinAccelPrior[0] -
    proc_control_node_B.linAccelErr_idx_0;
  obj->pGyroOffset[1] -= proc_control_node_B.gyroOffsetErr_idx_1;
  obj->pLinAccelPost[1] = obj->pLinAccelPrior[1] -
    proc_control_node_B.linAccelErr_idx_1;
  obj->pGyroOffset[2] -= proc_control_node_B.gyroOffsetErr_idx_2;
  obj->pLinAccelPost[2] = obj->pLinAccelPrior[2] -
    proc_control_node_B.linAccelErr_idx_2;
  if (!proc_control_node_B.isJamming) {
    for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 3;
         proc_control_node_B.b_i_e++) {
      proc_control_node_B.aoffset = proc_control_node_B.b_i_e * 3 - 1;
      proc_control_node_B.gravityAccelGyroDiff[proc_control_node_B.b_i_e] =
        (proc_control_node_B.h1[proc_control_node_B.aoffset + 1] *
         proc_control_node_B.offDiag[0] +
         proc_control_node_B.h1[proc_control_node_B.aoffset + 2] *
         proc_control_node_B.offDiag[1]) +
        proc_control_node_B.h1[proc_control_node_B.aoffset + 3] *
        proc_control_node_B.offDiag[2];
    }

    proc_control_node_B.s_i = rt_atan2d_snf(obj->pMagVec[2] -
      proc_control_node_B.gravityAccelGyroDiff[2], obj->pMagVec[0] -
      proc_control_node_B.gravityAccelGyroDiff[0]);
    if (proc_control_node_B.s_i < -1.5707963267948966) {
      proc_control_node_B.s_i = -1.5707963267948966;
    }

    if (proc_control_node_B.s_i > 1.5707963267948966) {
      proc_control_node_B.s_i = 1.5707963267948966;
    }

    obj->pMagVec[0] = 0.0;
    obj->pMagVec[1] = 0.0;
    obj->pMagVec[2] = 0.0;
    obj->pMagVec[0] = cos(proc_control_node_B.s_i);
    obj->pMagVec[2] = sin(proc_control_node_B.s_i);
    obj->pMagVec[0] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[1] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[2] *= obj->ExpectedMagneticFieldStrength;
  }

  proc_control_node_B.b_i_e = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 12;
       proc_control_node_B.aoffset++) {
    for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
         proc_control_node_B.i13++) {
      proc_control_node_B.H_l[proc_control_node_B.i13 +
        proc_control_node_B.b_i_e] = 0.0;
    }

    proc_control_node_B.b_i_e += 6;
  }

  proc_control_node_B.b_i_e = 0;
  proc_control_node_B.obj_tmp = 0;
  for (proc_control_node_B.aoffset = 0; proc_control_node_B.aoffset < 12;
       proc_control_node_B.aoffset++) {
    for (proc_control_node_B.i13 = 0; proc_control_node_B.i13 < 6;
         proc_control_node_B.i13++) {
      proc_control_node_B.i15 = 0;
      for (proc_control_node_B.Ppost_tmp = 0; proc_control_node_B.Ppost_tmp < 12;
           proc_control_node_B.Ppost_tmp++) {
        proc_control_node_B.H_tmp = proc_control_node_B.i13 +
          proc_control_node_B.b_i_e;
        proc_control_node_B.H_l[proc_control_node_B.H_tmp] +=
          proc_control_node_B.H[proc_control_node_B.i15 +
          proc_control_node_B.i13] * obj->pQw[proc_control_node_B.Ppost_tmp +
          proc_control_node_B.obj_tmp];
        proc_control_node_B.i15 += 6;
      }
    }

    proc_control_node_B.b_i_e += 6;
    proc_control_node_B.obj_tmp += 12;
  }

  for (proc_control_node_B.b_i_e = 0; proc_control_node_B.b_i_e < 12;
       proc_control_node_B.b_i_e++) {
    proc_control_node_B.aoffset = 0;
    proc_control_node_B.i13 = 0;
    for (proc_control_node_B.obj_tmp = 0; proc_control_node_B.obj_tmp < 12;
         proc_control_node_B.obj_tmp++) {
      proc_control_node_B.s_i = 0.0;
      proc_control_node_B.i15 = 0;
      for (proc_control_node_B.Ppost_tmp = 0; proc_control_node_B.Ppost_tmp < 6;
           proc_control_node_B.Ppost_tmp++) {
        proc_control_node_B.s_i += proc_control_node_B.K[proc_control_node_B.i15
          + proc_control_node_B.b_i_e] *
          proc_control_node_B.H_l[proc_control_node_B.Ppost_tmp +
          proc_control_node_B.i13];
        proc_control_node_B.i15 += 12;
      }

      proc_control_node_B.Ppost_tmp = proc_control_node_B.aoffset +
        proc_control_node_B.b_i_e;
      proc_control_node_B.Ppost[proc_control_node_B.Ppost_tmp] = obj->
        pQw[proc_control_node_B.Ppost_tmp] - proc_control_node_B.s_i;
      proc_control_node_B.aoffset += 12;
      proc_control_node_B.i13 += 6;
    }
  }

  memset(&obj->pQw[0], 0, 144U * sizeof(real_T));
  proc_control_node_B.s_i = obj->pKalmanPeriod * obj->pKalmanPeriod;
  proc_control_node_B.scale = obj->GyroscopeDriftNoise + obj->GyroscopeNoise;
  obj->pQw[0] = (proc_control_node_B.Ppost[39] + proc_control_node_B.scale) *
    proc_control_node_B.s_i + proc_control_node_B.Ppost[0];
  obj->pQw[39] = proc_control_node_B.Ppost[39] + obj->GyroscopeDriftNoise;
  obj->pQw[13] = (proc_control_node_B.Ppost[52] + proc_control_node_B.scale) *
    proc_control_node_B.s_i + proc_control_node_B.Ppost[13];
  obj->pQw[52] = proc_control_node_B.Ppost[52] + obj->GyroscopeDriftNoise;
  obj->pQw[26] = (proc_control_node_B.Ppost[65] + proc_control_node_B.scale) *
    proc_control_node_B.s_i + proc_control_node_B.Ppost[26];
  obj->pQw[65] = proc_control_node_B.Ppost[65] + obj->GyroscopeDriftNoise;
  proc_control_node_B.offDiag[0] = -obj->pKalmanPeriod * obj->pQw[39];
  proc_control_node_B.offDiag[1] = -obj->pKalmanPeriod * obj->pQw[52];
  proc_control_node_B.offDiag[2] = -obj->pKalmanPeriod * obj->pQw[65];
  obj->pQw[3] = proc_control_node_B.offDiag[0];
  obj->pQw[16] = proc_control_node_B.offDiag[1];
  obj->pQw[29] = proc_control_node_B.offDiag[2];
  obj->pQw[36] = proc_control_node_B.offDiag[0];
  obj->pQw[49] = proc_control_node_B.offDiag[1];
  obj->pQw[62] = proc_control_node_B.offDiag[2];
  proc_control_node_B.s_i = obj->LinearAccelerationDecayFactor *
    obj->LinearAccelerationDecayFactor;
  obj->pQw[78] = proc_control_node_B.s_i * proc_control_node_B.Ppost[78] +
    obj->LinearAccelerationNoise;
  obj->pQw[91] = proc_control_node_B.s_i * proc_control_node_B.Ppost[91] +
    obj->LinearAccelerationNoise;
  obj->pQw[104] = proc_control_node_B.s_i * proc_control_node_B.Ppost[104] +
    obj->LinearAccelerationNoise;
  proc_control_node_B.s_i = obj->MagneticDisturbanceDecayFactor *
    obj->MagneticDisturbanceDecayFactor;
  obj->pQw[117] = proc_control_node_B.s_i * proc_control_node_B.Ppost[117] +
    obj->MagneticDisturbanceNoise;
  obj->pQw[130] = proc_control_node_B.s_i * proc_control_node_B.Ppost[130] +
    obj->MagneticDisturbanceNoise;
  obj->pQw[143] = proc_control_node_B.s_i * proc_control_node_B.Ppost[143] +
    obj->MagneticDisturbanceNoise;
  orientOut[0] = obj->pOrientPost.a;
  orientOut[1] = obj->pOrientPost.b;
  orientOut[2] = obj->pOrientPost.c;
  orientOut[3] = obj->pOrientPost.d;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

static void pro_TrajectoryManager_setupImpl(TrajectoryManager_proc_contro_T
  *b_this)
{
  int32_T i;
  int32_T i_0;
  int32_T tmp;

  //  Perform one-time calculations, such as computing constants
  b_this->generationNumber = 0.0;
  b_this->dummy = 999.0;

  //  Chiffre NULL
  //  Vecteur pose NULL
  b_this->targetReachedCount = 0.0;

  //  Buffer trajectoire
  tmp = 0;
  for (i = 0; i < 13; i++) {
    b_this->emptyArray[i] = b_this->dummy;
    for (i_0 = 0; i_0 < 6001; i_0++) {
      b_this->poseBuffer[i_0 + tmp] = b_this->dummy;
    }

    tmp += 6001;
  }

  b_this->bufferCount = 0.0;
  b_this->done = false;
  b_this->init = 0.0;
}

static void proc_control_n_SystemCore_setup(fusion_simulink_imuSensor_pro_T *obj)
{
  h_fusion_internal_Acceleromet_T *obj_0;
  h_fusion_internal_GyroscopeSi_T *obj_1;
  h_fusion_internal_Magnetomete_T *obj_2;
  real_T val;
  real_T val_0;
  int32_T i;
  boolean_T flag;
  obj->isInitialized = 1;
  obj->pRefFrame = &obj->_pobj3;
  val = obj->AccelParamsMeasurementRange;
  val_0 = obj->AccelParamsResolution;
  proc_control_node_B.val_h[0] = obj->AccelParamsConstantBias[0];
  proc_control_node_B.val_h[1] = obj->AccelParamsConstantBias[1];
  proc_control_node_B.val_h[2] = obj->AccelParamsConstantBias[2];
  proc_control_node_B.val_l5[0] = obj->AccelParamsAxesMisalignment[0];
  proc_control_node_B.val_l5[1] = obj->AccelParamsAxesMisalignment[1];
  proc_control_node_B.val_l5[2] = obj->AccelParamsAxesMisalignment[2];
  proc_control_node_B.val_h2[0] = obj->AccelParamsNoiseDensity[0];
  proc_control_node_B.val_h2[1] = obj->AccelParamsNoiseDensity[1];
  proc_control_node_B.val_h2[2] = obj->AccelParamsNoiseDensity[2];
  proc_control_node_B.val_me[0] = obj->AccelParamsBiasInstability[0];
  proc_control_node_B.val_me[1] = obj->AccelParamsBiasInstability[1];
  proc_control_node_B.val_me[2] = obj->AccelParamsBiasInstability[2];
  proc_control_node_B.val_mc[0] = obj->AccelParamsRandomWalk[0];
  proc_control_node_B.val_mc[1] = obj->AccelParamsRandomWalk[1];
  proc_control_node_B.val_mc[2] = obj->AccelParamsRandomWalk[2];
  proc_control_node_B.val_h3[0] = obj->AccelParamsTemperatureBias[0];
  proc_control_node_B.val_h3[1] = obj->AccelParamsTemperatureBias[1];
  proc_control_node_B.val_h3[2] = obj->AccelParamsTemperatureBias[2];
  proc_control_node_B.val_cs[0] = obj->AccelParamsTemperatureScaleFactor[0];
  proc_control_node_B.val_cs[1] = obj->AccelParamsTemperatureScaleFactor[1];
  proc_control_node_B.val_cs[2] = obj->AccelParamsTemperatureScaleFactor[2];
  obj->_pobj2.isInitialized = 0;
  for (i = 0; i < 10; i++) {
    obj->_pobj2.tunablePropertyChanged[i] = false;
  }

  IMUSensorParameters_updateSyste(val, val_0, proc_control_node_B.val_h,
    proc_control_node_B.val_l5, proc_control_node_B.val_h2,
    proc_control_node_B.val_me, proc_control_node_B.val_mc,
    proc_control_node_B.val_h3, proc_control_node_B.val_cs, &obj->_pobj2);
  obj->pAccel = &obj->_pobj2;
  obj_0 = obj->pAccel;
  flag = (obj_0->isInitialized == 1);
  if (flag) {
    obj_0->TunablePropsChanged = true;
    obj_0->tunablePropertyChanged[9] = true;
  }

  obj->pAccel->Temperature = obj->Temperature;
  val = obj->GyroParamsMeasurementRange;
  val_0 = obj->GyroParamsResolution;
  proc_control_node_B.val_h[0] = obj->GyroParamsConstantBias[0];
  proc_control_node_B.val_h[1] = obj->GyroParamsConstantBias[1];
  proc_control_node_B.val_h[2] = obj->GyroParamsConstantBias[2];
  proc_control_node_B.val_l5[0] = obj->GyroParamsAxesMisalignment[0];
  proc_control_node_B.val_l5[1] = obj->GyroParamsAxesMisalignment[1];
  proc_control_node_B.val_l5[2] = obj->GyroParamsAxesMisalignment[2];
  proc_control_node_B.val_h2[0] = obj->GyroParamsNoiseDensity[0];
  proc_control_node_B.val_h2[1] = obj->GyroParamsNoiseDensity[1];
  proc_control_node_B.val_h2[2] = obj->GyroParamsNoiseDensity[2];
  proc_control_node_B.val_me[0] = obj->GyroParamsBiasInstability[0];
  proc_control_node_B.val_me[1] = obj->GyroParamsBiasInstability[1];
  proc_control_node_B.val_me[2] = obj->GyroParamsBiasInstability[2];
  proc_control_node_B.val_mc[0] = obj->GyroParamsRandomWalk[0];
  proc_control_node_B.val_mc[1] = obj->GyroParamsRandomWalk[1];
  proc_control_node_B.val_mc[2] = obj->GyroParamsRandomWalk[2];
  proc_control_node_B.val_h3[0] = obj->GyroParamsTemperatureBias[0];
  proc_control_node_B.val_h3[1] = obj->GyroParamsTemperatureBias[1];
  proc_control_node_B.val_h3[2] = obj->GyroParamsTemperatureBias[2];
  proc_control_node_B.val_cs[0] = obj->GyroParamsTemperatureScaleFactor[0];
  proc_control_node_B.val_cs[1] = obj->GyroParamsTemperatureScaleFactor[1];
  proc_control_node_B.val_cs[2] = obj->GyroParamsTemperatureScaleFactor[2];
  proc_control_node_B.val_k[0] = obj->GyroParamsAccelerationBias[0];
  proc_control_node_B.val_k[1] = obj->GyroParamsAccelerationBias[1];
  proc_control_node_B.val_k[2] = obj->GyroParamsAccelerationBias[2];
  obj->_pobj1.isInitialized = 0;
  for (i = 0; i < 11; i++) {
    obj->_pobj1.tunablePropertyChanged[i] = false;
  }

  IMUSensorParameters_updateSys_b(val, val_0, proc_control_node_B.val_h,
    proc_control_node_B.val_l5, proc_control_node_B.val_h2,
    proc_control_node_B.val_me, proc_control_node_B.val_mc,
    proc_control_node_B.val_h3, proc_control_node_B.val_cs,
    proc_control_node_B.val_k, &obj->_pobj1);
  obj->pGyro = &obj->_pobj1;
  obj_1 = obj->pGyro;
  flag = (obj_1->isInitialized == 1);
  if (flag) {
    obj_1->TunablePropsChanged = true;
    obj_1->tunablePropertyChanged[10] = true;
  }

  obj->pGyro->Temperature = obj->Temperature;
  val = obj->MagParamsMeasurementRange;
  val_0 = obj->MagParamsResolution;
  proc_control_node_B.val_h[0] = obj->MagParamsConstantBias[0];
  proc_control_node_B.val_h[1] = obj->MagParamsConstantBias[1];
  proc_control_node_B.val_h[2] = obj->MagParamsConstantBias[2];
  proc_control_node_B.val_l5[0] = obj->MagParamsAxesMisalignment[0];
  proc_control_node_B.val_l5[1] = obj->MagParamsAxesMisalignment[1];
  proc_control_node_B.val_l5[2] = obj->MagParamsAxesMisalignment[2];
  proc_control_node_B.val_h2[0] = obj->MagParamsNoiseDensity[0];
  proc_control_node_B.val_h2[1] = obj->MagParamsNoiseDensity[1];
  proc_control_node_B.val_h2[2] = obj->MagParamsNoiseDensity[2];
  proc_control_node_B.val_me[0] = obj->MagParamsBiasInstability[0];
  proc_control_node_B.val_me[1] = obj->MagParamsBiasInstability[1];
  proc_control_node_B.val_me[2] = obj->MagParamsBiasInstability[2];
  proc_control_node_B.val_mc[0] = obj->MagParamsRandomWalk[0];
  proc_control_node_B.val_mc[1] = obj->MagParamsRandomWalk[1];
  proc_control_node_B.val_mc[2] = obj->MagParamsRandomWalk[2];
  proc_control_node_B.val_h3[0] = obj->MagParamsTemperatureBias[0];
  proc_control_node_B.val_h3[1] = obj->MagParamsTemperatureBias[1];
  proc_control_node_B.val_h3[2] = obj->MagParamsTemperatureBias[2];
  proc_control_node_B.val_cs[0] = obj->MagParamsTemperatureScaleFactor[0];
  proc_control_node_B.val_cs[1] = obj->MagParamsTemperatureScaleFactor[1];
  proc_control_node_B.val_cs[2] = obj->MagParamsTemperatureScaleFactor[2];
  obj->_pobj0.isInitialized = 0;
  for (i = 0; i < 10; i++) {
    obj->_pobj0.tunablePropertyChanged[i] = false;
  }

  IMUSensorParameters_updateSy_b4(val, val_0, proc_control_node_B.val_h,
    proc_control_node_B.val_l5, proc_control_node_B.val_h2,
    proc_control_node_B.val_me, proc_control_node_B.val_mc,
    proc_control_node_B.val_h3, proc_control_node_B.val_cs, &obj->_pobj0);
  obj->pMag = &obj->_pobj0;
  obj_2 = obj->pMag;
  flag = (obj_2->isInitialized == 1);
  if (flag) {
    obj_2->TunablePropsChanged = true;
    obj_2->tunablePropertyChanged[9] = true;
  }

  obj->pMag->Temperature = obj->Temperature;
  obj->TunablePropsChanged = false;
}

static void proc_co_IMUSensorBase_resetImpl(fusion_simulink_imuSensor_pro_T *obj)
{
  h_fusion_internal_Acceleromet_T *obj_0;
  h_fusion_internal_GyroscopeSi_T *obj_1;
  h_fusion_internal_Magnetomete_T *obj_2;
  int32_T i;
  uint32_T r;
  boolean_T flag;
  for (i = 0; i < 625; i++) {
    obj->pStreamState[i] = 0U;
  }

  for (i = 0; i < 625; i++) {
    proc_control_node_B.b_state[i] = obj->pStreamState[i];
  }

  r = 67U;
  proc_control_node_B.b_state[0] = 67U;
  for (i = 0; i < 623; i++) {
    r = ((r >> 30U ^ r) * 1812433253U + i) + 1U;
    proc_control_node_B.b_state[i + 1] = r;
  }

  proc_control_node_B.b_state[624] = 624U;
  for (i = 0; i < 625; i++) {
    obj->pStreamState[i] = proc_control_node_B.b_state[i];
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj_0 = obj->pAccel;
    if (obj_0->isInitialized == 1) {
      obj_0->pBiasInstFilterStates[0] = 0.0;
      obj_0->pBiasInstFilterStates[1] = 0.0;
      obj_0->pBiasInstFilterStates[2] = 0.0;
      obj_0->pRandWalkFilterStates[0] = 0.0;
      obj_0->pRandWalkFilterStates[1] = 0.0;
      obj_0->pRandWalkFilterStates[2] = 0.0;
    }

    obj_1 = obj->pGyro;
    if (obj_1->isInitialized == 1) {
      obj_1->pBiasInstFilterStates[0] = 0.0;
      obj_1->pBiasInstFilterStates[1] = 0.0;
      obj_1->pBiasInstFilterStates[2] = 0.0;
      obj_1->pRandWalkFilterStates[0] = 0.0;
      obj_1->pRandWalkFilterStates[1] = 0.0;
      obj_1->pRandWalkFilterStates[2] = 0.0;
    }

    obj_2 = obj->pMag;
    if (obj_2->isInitialized == 1) {
      obj_2->pBiasInstFilterStates[0] = 0.0;
      obj_2->pBiasInstFilterStates[1] = 0.0;
      obj_2->pBiasInstFilterStates[2] = 0.0;
      obj_2->pRandWalkFilterStates[0] = 0.0;
      obj_2->pRandWalkFilterStates[1] = 0.0;
      obj_2->pRandWalkFilterStates[2] = 0.0;
    }
  }
}

static void proc_c_AHRSFilterBase_resetImpl(fusion_simulink_ahrsfilter_pr_T *obj)
{
  real_T accelMeasNoiseVar;
  real_T magMeasNoiseVar;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  int32_T tmp_1;
  static const int8_T tmp_2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T tmp_3[144] = { 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    7.6154354946677142E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6 };

  obj->pOrientPost.a = 1.0;
  obj->pOrientPost.b = 0.0;
  obj->pOrientPost.c = 0.0;
  obj->pOrientPost.d = 0.0;
  obj->pGyroOffset[0] = 0.0;
  obj->pMagVec[0] = 0.0;
  obj->pGyroOffset[1] = 0.0;
  obj->pMagVec[1] = 0.0;
  obj->pGyroOffset[2] = 0.0;
  obj->pMagVec[2] = 0.0;
  obj->pMagVec[0] = obj->ExpectedMagneticFieldStrength;
  magMeasNoiseVar = obj->pKalmanPeriod * obj->pKalmanPeriod *
    (obj->GyroscopeDriftNoise + obj->GyroscopeNoise);
  accelMeasNoiseVar = magMeasNoiseVar + (obj->AccelerometerNoise +
    obj->LinearAccelerationNoise);
  magMeasNoiseVar += obj->MagnetometerNoise + obj->MagneticDisturbanceNoise;
  memset(&obj->pQv[0], 0, 36U * sizeof(real_T));
  tmp = 0;
  tmp_1 = 0;
  for (i = 0; i < 3; i++) {
    tmp_0 = tmp_2[tmp];
    obj->pQv[tmp_1] = accelMeasNoiseVar * static_cast<real_T>(tmp_0);
    obj->pQv[tmp_1 + 21] = magMeasNoiseVar * static_cast<real_T>(tmp_0);
    tmp_0 = tmp_2[tmp + 1];
    obj->pQv[tmp_1 + 1] = accelMeasNoiseVar * static_cast<real_T>(tmp_0);
    obj->pQv[tmp_1 + 22] = magMeasNoiseVar * static_cast<real_T>(tmp_0);
    tmp_0 = tmp_2[tmp + 2];
    obj->pQv[tmp_1 + 2] = accelMeasNoiseVar * static_cast<real_T>(tmp_0);
    obj->pQv[tmp_1 + 23] = magMeasNoiseVar * static_cast<real_T>(tmp_0);
    tmp += 3;
    tmp_1 += 6;
  }

  memcpy(&obj->pQw[0], &tmp_3[0], 144U * sizeof(real_T));
  obj->pLinAccelPost[0] = 0.0;
  obj->pLinAccelPost[1] = 0.0;
  obj->pLinAccelPost[2] = 0.0;
  obj->pFirstTime = true;
}

// Model step function
void proc_control_node_step(void)
{
  static const int8_T tmp[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const real_T b[96] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.02112443491058583, -0.015284356933675681, -7.0837403672252132E-5,
    0.062952228101239543, 0.019032522297668639, -0.17235611708486639, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.021112545591001931, 0.01555652319878203,
    9.3712054745178266E-5, -0.060884483374622281, 0.01961380565091311,
    -0.17335012146094611, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.021790267284400529,
    -0.01556568704794139, -6.7363334491227155E-5, 0.060331047065513788,
    0.019031465986279989, 0.17628138981294919, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.02177837796481662, 0.015275193084516331, 9.7186123926203244E-5,
    -0.063505664410348023, 0.019612749339524459, 0.1752873854368695, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.001819638864719295, -0.0034249251816346319,
    -0.02095639900015615, -0.26767193546582568, 0.10593667623599359,
    0.00062021813460420567, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0018124211550371481,
    0.003387750973601051, 0.021100316216985739, 0.26476621250220889,
    0.10537885436940329, -0.0006207996116589, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0018538731733468781, 0.0035708122797193449, -0.021822949502860629,
    0.2790736050389333, -0.10793139553633729, -0.00064672437426625525, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001778186846409557, -0.0035336380716857632,
    0.02167903228603104, -0.27616788207531651, -0.1033841350690595,
    0.000647305851320949 };

  static const real_T c[400] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -5.3507944646802133E-7,
    -0.00082885527665445583, 3.5767703372099718E-5, 0.97273031757000594,
    0.00012331667477404165, 0.00081833891139938624, -7.8127500240178673E-6,
    -0.0159410811592156, 0.00065940762693006763, -0.50639739431268649,
    0.0022406893332586339, 0.015680535561612769, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0008312972743433338, 3.57994053924751E-7, -6.9640152050888586E-6,
    0.00011401776367220553, 0.98958868966027158, 0.0015278746097724251,
    0.016439182732016812, 5.0510208979124369E-6, -0.00013558597101872647,
    0.0020750012409153492, -0.20433897615202037, 0.029520293269032327, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.098278010942337485,
    -3.9178382144897418E-8, 3.6029132161403132E-7, -6.06436789451106E-6,
    0.00053833020422606331, -5.2594318222538359E-5, 0.96576373585108377,
    -6.501469973283583E-7, 6.9726400853635038E-6, -0.00010956030438097965,
    0.01050384676545269, -0.0010090517040076735, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -5.2412807532070782E-8, 0.098282301633632746,
    1.8441502946120931E-6, -0.0014060555235525074, 6.3579992794949353E-6,
    2.9037006947561162E-5, -8.7353626988520347E-7, 0.965871899404307,
    3.37744080501975E-5, -0.025940770969944744, 0.00011474217170484383,
    0.000550370407558065, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    5.5679283691304113E-7, 2.13675982442248E-6, 0.098151996206588987,
    0.0001701621474509946, -3.3031211058917491E-5, -3.5454909967586725E-7,
    1.0701277659066495E-5, 3.8828223569474736E-5, 0.963269344584924,
    0.00313741412721166, -0.00064306916783901462, -5.9836515319977714E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.3626778210299829E-6,
    -0.0002609096415248733, 2.5549185479761808E-5, 0.080524239440717682,
    8.8129815925809565E-5, 6.5645541095256E-5, -2.46765149113751E-5,
    -0.0050898445953914779, 0.0004839693975760153, 0.62853107454273693,
    0.00164658411216071, 0.0014407905611376081, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.00011105310406864362, 7.5139108689899532E-7,
    -3.5383450585692382E-6, 6.2663614043591832E-5, 0.0947207216763955,
    5.05027626411221E-5, 0.002443425974762427, 1.35855257573908E-5,
    -7.1271385545840021E-5, 0.0011806504384571687, 0.89283716846365213,
    0.0014765424046636862, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -1.7579023859678809E-5, 7.3022208744976542E-6, -7.9145539611501852E-8,
    6.04943547515576E-5, 5.1076936306352412E-9, 0.090686828613835188,
    -0.0003382219781509901, 0.00013925482166517804, -1.4036611182737413E-6,
    0.00108110898961926, -1.5542767454520077E-7, 0.81970707638081142, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  static const int8_T e[240] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const real_T d[580] = { 0.00010457289515071081, -7.6140436907344992E-5,
    -2.9722529989700309E-7, 0.00027334045385442226, 9.2410661606115357E-5,
    -0.00080729807062752544, 0.0020811258963165397, -0.0015198518822508163,
    -5.4187325385026086E-6, 0.0050812968577928453, 0.0018195984185641386,
    -0.015626890734703563, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.00010452260811007788, 7.73822380159891E-5, 4.0895178855073891E-7,
    -0.00026505057394957484, 9.4846033226395586E-5, -0.00081217965533840052,
    0.0020802066892867438, 0.0015435645239729925, 7.6230909936765859E-6,
    -0.0049339197726492251, 0.0018639285362635647, -0.015724237716895111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00010765559640120996,
    -7.7420972482068683E-5, -2.8334614165253273E-7, 0.00026273201367427607,
    9.2409765908284348E-5, 0.00082588277646687257, 0.00214043734178217,
    -0.0015442719533714851, -5.1725830412882343E-6, 0.0048917109023479885,
    0.0018196256747468771, 0.015989723790283406, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.00010760530936057697, 7.6101702441265482E-5,
    4.2283094679520943E-7, -0.00027565901412972092, 9.4845137528564658E-5,
    0.00082100119175599826, 0.0021395181347523729, 0.0015191444528523249,
    7.8692404908909619E-6, -0.0051235057280940794, 0.0018639557924463046,
    0.015892376808091871, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -8.6092969231234346E-6, -1.4570098512002395E-5, -0.00010373386893130586,
    -0.0011602056015333115, 0.00051036199308609608, 2.4867445508465246E-6,
    -0.00016672353260978483, -0.00026673191970221443, -0.0020641330563732877,
    -0.021546142444249704, 0.010010499422843657, 4.4027924612916461E-5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -8.5994040071684147E-6, 1.4417507544110492E-5,
    0.0001044171455658332, 0.0011480658129707181, 0.00050924167407041061,
    -2.2181030758940477E-6, -0.00016675680427690799, 0.00026399571028698309,
    0.0020774354952666318, 0.021325501856665617, 0.010003243818971342,
    -3.3409491327564989E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    8.7701538831285644E-6, 1.5187533127514722E-5, -0.00010750923380206453,
    0.0012093730943430337, -0.00051990427888273967, -2.5892181037974276E-6,
    0.00016982759486804377, 0.00027800213105636613, -0.0021344467507693698,
    0.022456641856402997, -0.010197003437006922, -4.5766358519135951E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.4385470471632426E-6,
    -1.5034942159622821E-5, 0.0001068259571675372, -0.0011972333057804398,
    -0.0004996993882737667, 2.3205766288449452E-6, 0.00016365274201864824,
    -0.00027526592164113479, 0.0021211443118760256, -0.022236001268818903,
    -0.00981673980480807, 3.5147925233784378E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T f[348] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T g[64] = { 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40 };

  static const real_T n[20] = { 0.0, 0.0, 0.31, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T h[64] = { 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0,
    248.0, 249.0, 250.0, 251.0, 252.0, 253.0, 254.0, 255.0, 256.0, 257.0, 258.0,
    259.0, 260.0, 261.0, 262.0, 263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0,
    270.0, 271.0, 272.0, 321.0, 322.0, 323.0, 324.0, 325.0, 326.0, 327.0, 328.0,
    329.0, 330.0, 331.0, 332.0, 333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0,
    340.0, 341.0, 342.0, 343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0,
    351.0, 352.0 };

  static const real_T l[12] = { 0.0, 0.0, 0.31, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const int8_T tmp_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T o[512] = { -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0 };

  static const real_T q[1089] = { 0.019866645888167122, 0.00759146623023797,
    -0.0042281561361558447, -0.006503335794085, -0.00049718458263957733,
    0.0015427057394322133, 0.00052956915690802685, -0.0015750903137006624,
    0.0081018251881511457, 0.0061547560914029034, -0.0032850965329207426,
    -0.005232165629668991, -0.000452713146885375, 0.0012915947571914136,
    0.00048106155079355071, -0.0013199431610995893, 0.0064512902008103789,
    0.004830856017361003, -0.0024444324535672825, -0.0040648666370166628,
    -0.00039479492521815807, 0.0010396233328705865, 0.00041864021205021464,
    -0.0010634686197026433, 0.0049442113450179946, 0.003640828366852623,
    -0.0017172683671222819, -0.0030206513452876579, -0.00032706308966284708,
    0.00079684681599981842, 0.00034616367290566383, -0.00081594739924263486, 0.0,
    0.00759146623023797, 0.020026092402441211, -0.0066600067280669448,
    -0.0042253805558637152, 0.0016407071097489555, -0.00057393104751808828,
    -0.0016961096868821147, 0.000629333624651247, 0.0061591102727890949,
    0.0082279139141163311, -0.005355709381867804, -0.0032869057405405726,
    0.0013550791727029153, -0.00049735445973701157, -0.0014013258248841115,
    0.00054360111191820691, 0.0048377200358050987, 0.0065479247790686586,
    -0.0041592869371263486, -0.0024490821938627926, 0.0010772565377498223,
    -0.00041646179611231081, -0.0011144360451084718, 0.00045364130347095997,
    0.0036486140445015562, 0.0050154495800020732, -0.0030900732994302515,
    -0.0017232377639297368, 0.00081637237798699478, -0.00033376006452602146,
    -0.00084488541202255916, 0.00036227309856158574, 0.0, -0.0042281561361558447,
    -0.0066600067280669448, 0.020367912569914104, 0.0079360619780030079,
    -0.00041912190131718175, 0.0018008408556748838, 0.000452194680739009,
    -0.0018339136350967104, -0.0032960703607159748, -0.0053622777398963225,
    0.0085035565681809387, 0.0064373491890005931, -0.00039738550062804433,
    0.001457279125983616, 0.00042602403126143024, -0.0014859176566170014,
    -0.00246163966839957, -0.0041695507876774963, 0.0067638752050897116,
    0.0050559640858117878, -0.0003559771332579123, 0.0011378280402140524,
    0.00037981658148550661, -0.0011616674884416466, -0.0017367456993936071,
    -0.0031016794552865623, 0.0051785950384438438, 0.0038136612825508918,
    -0.00030012462182707727, 0.000848813562748073, 0.00031903138500366751,
    -0.00086772032592466312, 0.0, -0.006503335794085, -0.0042253805558637152,
    0.0079360619780030079, 0.0202140172162243, 0.0017187697910713516,
    -0.0003157959312754172, -0.0017734841630511319, 0.0003705103032551977,
    -0.0052387852760780312, -0.0032891199171829, 0.0064329437192338808,
    0.0083826090781290146, 0.0014104068189602457, -0.00033167009094480811,
    -0.0014563633444162317, 0.00037762661640079384, -0.0040752098334048536,
    -0.0024524820259698441, 0.00504902072153065, 0.0066717485289656629,
    0.0011160743297100679, -0.00031825708876884428, -0.0011532596756731797,
    0.00035544243473195592, -0.0030323429999100497, -0.0017270582421371138,
    0.0038057901061358773, 0.0051110748639088145, 0.00084331084582276426,
    -0.00028179331777776636, -0.00087201769992455527, 0.000310500171879557, 0.0,
    -0.00049718458263957733, 0.0016407071097489555, -0.00041912190131718175,
    0.0017187697910713516, 0.017713375948900323, -0.0013804722512317188,
    -0.0074794312807732024, 0.0011465275831045989, -0.00045267928243857209,
    0.0013833775935568867, -0.00038613186081997558, 0.0014499250151754827,
    0.0064607290414595286, -0.0013129049956114229, -0.0062932402866751856,
    0.0011454162408270814, -0.00039480008643631096, 0.001126746708726074,
    -0.00033978336525822386, 0.0011817634299041608, 0.0052200961685162492,
    -0.0011872490665946448, -0.0051056872619431315, 0.0010728401600215286,
    -0.00032726845020371109, 0.00087913003827091432, -0.00028354391649424349,
    0.00092285457198038187, 0.0040332955100120006, -0.0010149129394430032,
    -0.0039596306726482318, 0.00094124810207923439, 0.0, 0.0015427057394322133,
    -0.00057393104751808828, 0.0018008408556748838, -0.0003157959312754172,
    -0.0013804722512317188, 0.017735612802606528, 0.0010311660853752156,
    -0.0073863066367500186, 0.0013031676899779279, -0.00051377862898472953,
    0.0015141628051452681, -0.00030278351381738837, -0.0013124525942048739,
    0.00647186304126629, 0.0010506891648363822, -0.0062100996118977965,
    0.0010630961400653232, -0.0004419674094392151, 0.0012304580373893761,
    -0.00027460551211516134, -0.001186466449303696, 0.0052231554347213693,
    0.00099781307864630947, -0.0050345020640639821, 0.00083059342215819514,
    -0.00036227393256199532, 0.00095830990237221088, -0.00023455745234797904,
    -0.0010139523346355593, 0.0040311591644687176, 0.00088442998819836206,
    -0.003901636818031518, 0.0, 0.00052956915690802685, -0.0016961096868821149,
    0.00045219468073900916, -0.0017734841630511321, -0.0074794312807732015,
    0.0010311660853752147, 0.018191792522561041, -0.0017435273271630557,
    0.00048098250357288643, -0.0014304051764555555, 0.00041491708606601022,
    -0.0014964705939624315, -0.0062921118843744734, 0.00105047417116836,
    0.0068670602520442443, -0.0016254225388381326, 0.00041862238147813934,
    -0.0011652920928193148, 0.00036392261112110368, -0.0012199918631763504,
    -0.005103850804485676, 0.00099748320117552412, 0.0055527988572473732,
    -0.0014464312539372221, 0.0003464166570059381, -0.00090937990660269231,
    0.00030288310850594554, -0.00095291345510268471, -0.003957488221935355,
    0.0008840632294988104, 0.00429366048985211, -0.0012202354974155661, 0.0,
    -0.0015750903137006626, 0.00062933362465124689, -0.0018339136350967106,
    0.00037051030325519743, 0.0011465275831045981, -0.0073863066367500195,
    -0.0017435273271630557, 0.017983306380808476, -0.001331470911112242,
    0.0005608062118833975, -0.001542948030391302, 0.00034932909260433642,
    0.0011438354371198192, -0.006209432216823226, -0.0016245091302054416,
    0.0066901059099088462, -0.0010869184351071516, 0.00048051279353245551,
    -0.0012545972832522555, 0.00031283394538735053, 0.001070221085273122,
    -0.0050333895693022469, -0.0014449246739505507, 0.0054080931579796737,
    -0.00084974162896042215, 0.00039252380089377327, -0.00097764909438391272,
    0.00026461633547028178, 0.00093814504655891453, -0.0039003094545245224,
    -0.0012184598054022417, 0.0041806242133678485, 0.0, 0.0081018251881511457,
    0.0061591102727890949, -0.0032960703607159748, -0.0052387852760780312,
    -0.00045267928243857209, 0.0013031676899779279, 0.00048098250357288665,
    -0.001331470911112242, 0.01670171473187803, 0.005023722477393292,
    -0.0025582276272207195, -0.00423621988170546, -0.00041541672039432459,
    0.0010996998708221106, 0.0004404323809149672, -0.0011247155313427529,
    0.0053771455645719429, 0.0039683806977202632, -0.001900424184519414,
    -0.0033091890513710981, -0.00036513136163699827, 0.00089265118274388779,
    0.00038638117533400674, -0.00091390099644089642, 0.0041530053520155456,
    0.0030105746024400837, -0.0013303481983805454, -0.0024727789479560103,
    -0.00030465747079058513, 0.00069000506929258647, 0.0003218389502764372,
    -0.00070718654877843833, 0.0, 0.0061547560914029034, 0.0082279139141163311,
    -0.0053622777398963225, -0.0032891199171829, 0.0013833775935568867,
    -0.00051377862898472953, -0.0014304051764555557, 0.00056080621188339761,
    0.005023722477393292, 0.016801845455304103, -0.0043339700952962,
    -0.0025558471173853996, 0.0011517012978203927, -0.00045036319524829031,
    -0.001191308521574448, 0.00048997041900234524, 0.0039712142227148941,
    0.0054542324525482322, -0.0033841984737836917, -0.0019011802439503564,
    0.00092341649297447822, -0.00038133874476831543, -0.0009555595047384209,
    0.00041348175653225752, 0.0030148885015261776, 0.0042101121030223426,
    -0.0025281744029548962, -0.001332950801458733, 0.00070584101965614273,
    -0.00030871067710370244, -0.00073072420200215554, 0.00033359385944971493,
    0.0, -0.0032850965329207426, -0.005355709381867804, 0.0085035565681809387,
    0.0064329437192338808, -0.00038613186081997558, 0.0015141628051452681,
    0.00041491708606601017, -0.0015429480303913025, -0.0025582276272207195,
    -0.0043339700952962, 0.017025633053368433, 0.0052498905852929522,
    -0.000367679919484282, 0.001235078367497994, 0.000392857902607932,
    -0.0012602563506216441, -0.0019074894525096062, -0.0033883984479936933,
    0.0056308147887326916, 0.0041499057932486063, -0.00033118607935381564,
    0.00097262038843646463, 0.00035236172422061906, -0.00099379603330326761,
    -0.0013410988028372732, -0.0025345661211514676, 0.0043445195269987509,
    0.0031510522086845585, -0.00028077807539729824, 0.00073192039826569,
    0.00029773893681393131, -0.00074888125968232291, 0.0, -0.005232165629668991,
    -0.0032869057405405726, 0.0064373491890005931, 0.0083826090781290146,
    0.0014499250151754827, -0.00030278351381738837, -0.0014964705939624315,
    0.00034932909260433642, -0.00423621988170546, -0.0025558471173853996,
    0.0052498905852929522, 0.016930263349613017, 0.0011994380987304352,
    -0.0003149846985724059, -0.0012388829998814827, 0.00035442959972345321,
    -0.0033134207943666585, -0.0019025466931657275, 0.0041470404994684157,
    0.00555791460066935, 0.00095736177525766037, -0.00030136953907573805,
    -0.00098957895585180858, 0.00033358671966988572, -0.0024792156533266448,
    -0.0013350286205692106, 0.0031466933224244022, 0.0042908803551818383,
    0.00072972041504942961, -0.00026679534813059825, -0.00075482421546466138,
    0.00029189914854582986, 0.0, -0.000452713146885375, 0.0013550791727029153,
    -0.00039738550062804433, 0.0014104068189602457, 0.0064607290414595286,
    -0.0013124525942048739, -0.0062921118843744742, 0.0011438354371198192,
    -0.00041541672039432459, 0.0011517012978203927, -0.000367679919484282,
    0.0011994380987304352, 0.015463199074670829, -0.0012506931977276353,
    -0.0053449248103517458, 0.0011324189334085538, -0.00036545184901293096,
    0.00094594889186967312, -0.00032550938115952991, 0.00098589135972307384,
    0.0044579606000274986, -0.0011349006024233411, -0.0043794593237663935,
    0.0010563993261622365, -0.0003055234722935035, 0.0007440933593500967,
    -0.00027341187214300396, 0.00077620495950059623, 0.0034783682965683609,
    -0.0009735447062356532, -0.0034298421042831557, 0.00092501851395044926, 0.0,
    0.0012915947571914136, -0.00049735445973701157, 0.001457279125983616,
    -0.00033167009094480811, -0.0013129049956114229, 0.00647186304126629,
    0.0010504741711683597, -0.006209432216823226, 0.0010996998708221106,
    -0.00045036319524829031, 0.001235078367497994, -0.0003149846985724059,
    -0.0012506931977276353, 0.015466004539223399, 0.0010552319848764597,
    -0.0052705433263722182, 0.00090461526770665177, -0.00039196306964124178,
    0.0010120399019803584, -0.00028453843536753454, -0.0011345416334921682,
    0.004454977827356146, 0.00099481789767497434, -0.004315254091538951,
    0.00071248652683604074, -0.00032486996664207707, 0.00079458607842282792,
    -0.0002427704150552893, -0.0009729536697887063, 0.0034720462122760009,
    0.0008780304815156569, -0.0033771230240029503, 0.0, 0.00048106155079355071,
    -0.0014013258248841112, 0.00042602403126143013, -0.0014563633444162314,
    -0.0062932402866751865, 0.0010506891648363829, 0.0068670602520442443,
    -0.0016245091302054416, 0.0004404323809149672, -0.001191308521574448,
    0.000392857902607932, -0.0012388829998814831, -0.0053449248103517458,
    0.0010552319848764597, 0.015811826053336635, -0.0015221332278613476,
    0.00038672125002648294, -0.00097871664378206056, 0.00034684682899424726,
    -0.001018591064814296, -0.0043786699237955886, 0.00099468660341247087,
    0.004746415706820723, -0.0013624323864376059, 0.00032278683757558217,
    -0.00077004256997772785, 0.00029068069021252383, -0.00080214871734078587,
    -0.0034286028763061849, 0.0008778348336312082, 0.0037064247216440152,
    -0.0011556566789690387, 0.0, -0.001319943161099589, 0.00054360111191820723,
    -0.001485917656617001, 0.00037762661640079384, 0.0011454162408270812,
    -0.0062100996118977956, -0.0016254225388381326, 0.0066901059099088462,
    -0.0011247155313427529, 0.00048997041900234514, -0.0012602563506216441,
    0.000354429599723453, 0.0011324189334085541, -0.0052705433263722191,
    -0.0015221332278613476, 0.015660257620825013, -0.00092588466872020353,
    0.00042473082155362874, -0.0010333773498150756, 0.000317238140458756,
    0.0010552509572602587, -0.0043147638283452753, -0.0013617742807293044,
    0.00462128715181432, -0.00072974989211811942, 0.00035081917726970769,
    -0.00081185489649234768, 0.00026871417289547873, 0.00092318824952653021,
    -0.003376336339671555, -0.0011546130988765162, 0.003607761189021539, 0.0,
    0.0064512902008103789, 0.0048377200358050987, -0.00246163966839957,
    -0.0040752098334048536, -0.00039480008643631096, 0.0010630961400653232,
    0.00041862238147813928, -0.0010869184351071513, 0.0053771455645719429,
    0.0039712142227148941, -0.0019074894525096062, -0.0033134207943666585,
    -0.00036545184901293096, 0.00090461526770665177, 0.00038672125002648294,
    -0.00092588466872020364, 0.014353939165938908, 0.0031605068978619822,
    -0.0014100006589018383, -0.002603432926978766, -0.0003243665777079561,
    0.00074086147966658151, 0.00034263224389549933, -0.00075912714585412463,
    0.0033947033923118781, 0.0024168332019874079, -0.00097985223440646713,
    -0.0019577224247309395, -0.00027333205952141372, 0.0005781811396680796,
    0.00028826743095268921, -0.0005931165110993552, 0.0, 0.004830856017361003,
    0.0065479247790686586, -0.0041695507876774963, -0.0024524820259698441,
    0.001126746708726074, -0.0004419674094392151, -0.001165292092819315,
    0.0004805127935324554, 0.0039683806977202632, 0.0054542324525482322,
    -0.0033883984479936933, -0.0019025466931657275, 0.00094594889186967312,
    -0.00039196306964124178, -0.00097871664378206078, 0.0004247308215536289,
    0.0031605068978619822, 0.014413623487391638, -0.00266126903909295,
    -0.0014081524495632993, 0.000765266343721233, -0.00033600728360332196,
    -0.00079212559855087864, 0.00036286653843296726, 0.0024185729869500737,
    0.0034391915366132355, -0.0020006782923504946, -0.000980059742687335,
    0.00059062006921040144, -0.00027534156660509251, -0.00061163482449975895,
    0.00029635632189444958, 0.0, -0.0024444324535672825, -0.0041592869371263486,
    0.0067638752050897116, 0.00504902072153065, -0.00033978336525822386,
    0.0012304580373893761, 0.00036392261112110368, -0.0012545972832522553,
    -0.001900424184519414, -0.0033841984737836917, 0.0056308147887326916,
    0.0041470404994684157, -0.00032550938115952991, 0.0010120399019803584,
    0.00034684682899424743, -0.0010333773498150758, -0.0014100006589018383,
    -0.00266126903909295, 0.014554220172634792, 0.0033029517924436794,
    -0.0002955625618818256, 0.0008041103032152162, 0.00031371157117033655,
    -0.00082225931250372742, -0.000984188179644883, -0.002003258091363834,
    0.0035472299850082115, 0.0025281600732892616, -0.0002527633246569157,
    0.00061097461786159589, 0.00026746981749240824, -0.00062568111069708811, 0.0,
    -0.0040648666370166628, -0.0024490821938627926, 0.0050559640858117878,
    0.0066717485289656629, 0.0011817634299041608, -0.00027460551211516134,
    -0.0012199918631763504, 0.00031283394538735059, -0.0033091890513710981,
    -0.0019011802439503564, 0.0041499057932486063, 0.00555791460066935,
    0.00098589135972307384, -0.00028453843536753454, -0.0010185910648142958,
    0.00031723814045875608, -0.002603432926978766, -0.0014081524495632993,
    0.0033029517924436794, 0.014498232269859149, 0.00079407035954736358,
    -0.00027275846005468674, -0.0008210462712760411, 0.0002997343717833642,
    -0.0019603185850066897, -0.000980899756738009, 0.0025264039270641849,
    0.0035058227553328675, 0.00061118880407489925, -0.00024254808841157579,
    -0.00063243243796003981, 0.00026379172229671613, 0.0,
    -0.00039479492521815807, 0.0010772565377498223, -0.0003559771332579123,
    0.0011160743297100679, 0.0052200961685162492, -0.001186466449303696,
    -0.0051038508044856752, 0.0010702210852731218, -0.00036513136163699827,
    0.00092341649297447822, -0.00033118607935381564, 0.00095736177525766037,
    0.0044579606000274986, -0.0011345416334921682, -0.0043786699237955886,
    0.0010552509572602582, -0.0003243665777079561, 0.000765266343721233,
    -0.0002955625618818256, 0.00079407035954736358, 0.013677869977380895,
    -0.001036024977969782, -0.0036274864054677064, 0.00098564140605659459,
    -0.00027409399627415708, 0.00060769183074135152, -0.00025061587863193905,
    0.00063116994838356938, 0.0029028125638056773, -0.00089520419488189613,
    -0.0028737680576011574, 0.00086615968867737611, 0.0, 0.0010396233328705865,
    -0.00041646179611231081, 0.0011378280402140524, -0.00031825708876884428,
    -0.0011872490665946448, 0.0052231554347213693, 0.00099748320117552455,
    -0.0050333895693022469, 0.00089265118274388779, -0.00038133874476831543,
    0.00097262038843646463, -0.00030136953907573805, -0.0011349006024233411,
    0.004454977827356146, 0.00099468660341247087, -0.0043147638283452744,
    0.00074086147966658151, -0.00033600728360332196, 0.0008041103032152162,
    -0.00027275846005468674, -0.001036024977969782, 0.013670873037227894,
    0.00093693645749082309, -0.0035717845167489329, 0.00058904521586262862,
    -0.00028207916088014289, 0.00063727631602813843, -0.00023384806071463256,
    -0.0008949428332404452, 0.0028938267821706251, 0.00082867747727940664,
    -0.002827561426209586, 0.0, 0.0004186402120502147, -0.0011144360451084715,
    0.00037981658148550639, -0.0011532596756731795, -0.0051056872619431332,
    0.00099781307864630969, 0.0055527988572473732, -0.0014449246739505507,
    0.00038638117533400679, -0.0009555595047384209, 0.00035236172422061884,
    -0.00098957895585180837, -0.0043794593237663944, 0.00099481789767497521,
    0.004746415706820723, -0.0013617742807293044, 0.00034263224389549922,
    -0.00079212559855087864, 0.00031371157117033644, -0.00082104627127604142,
    -0.0036274864054677068, 0.000936936457490823, 0.013919327933217658,
    -0.0012287779852407728, 0.00028909154401548403, -0.000629187043951323,
    0.00026547974907927105, -0.00065279883888753583, -0.0028732482684981709,
    0.00082860120194047345, 0.0030960228977929133, -0.001051375831235215, 0.0,
    -0.0010634686197026431, 0.00045364130347095997, -0.0011616674884416466,
    0.00035544243473195608, 0.0010728401600215288, -0.0050345020640639813,
    -0.0014464312539372221, 0.0054080931579796737, -0.00091390099644089642,
    0.00041348175653225762, -0.00099379603330326739, 0.00033358671966988578,
    0.0010563993261622361, -0.004315254091538951, -0.0013624323864376059,
    0.00462128715181432, -0.00075912714585412463, 0.00036286653843296726,
    -0.00082225931250372709, 0.00029973437178336415, 0.00098564140605659481,
    -0.0035717845167489333, -0.0012287779852407728, 0.013814921095933111,
    -0.0006040427636039554, 0.00030357437409011395, -0.00065214018647547032,
    0.00025547695121859871, 0.00086537853793293906, -0.0028272237892292018,
    -0.0010509323174711623, 0.0030127775687674241, 0.0, 0.0049442113450179946,
    0.0036486140445015562, -0.0017367456993936071, -0.0030323429999100497,
    -0.00032726845020371109, 0.00083059342215819514, 0.00034641665700593815,
    -0.00084974162896042226, 0.0041530053520155456, 0.0030148885015261776,
    -0.0013410988028372732, -0.0024792156533266448, -0.0003055234722935035,
    0.00071248652683604074, 0.00032278683757558222, -0.00072974989211811931,
    0.0033947033923118781, 0.0024185729869500737, -0.000984188179644883,
    -0.0019603185850066897, -0.00027409399627415708, 0.00058904521586262862,
    0.00028909154401548408, -0.00060404276360395551, 0.012677923534000247,
    0.0018672243630625789, -0.00067318037461868156, -0.0014838795455563497,
    -0.0002337655865632675, 0.00046434822949252151, 0.00024618348805900025,
    -0.00047676613098825426, 0.0, 0.003640828366852623, 0.0050154495800020732,
    -0.0031016794552865623, -0.0017270582421371138, 0.00087913003827091432,
    -0.00036227393256199532, -0.00090937990660269231, 0.00039252380089377321,
    0.0030105746024400837, 0.0042101121030223426, -0.0025345661211514676,
    -0.0013350286205692106, 0.0007440933593500967, -0.00032486996664207707,
    -0.00077004256997772775, 0.00035081917726970769, 0.0024168332019874079,
    0.0034391915366132355, -0.002003258091363834, -0.000980899756738009,
    0.00060769183074135152, -0.00028207916088014289, -0.000629187043951323,
    0.000303574374090114, 0.0018672243630625789, 0.012711355453639142,
    -0.0015160192903928876, -0.000671888199816327, 0.00047374965253025919,
    -0.00023435899533103696, -0.00049075801757620058, 0.0002513673603769781, 0.0,
    -0.0017172683671222819, -0.0030900732994302515, 0.0051785950384438438,
    0.0038057901061358773, -0.00028354391649424349, 0.00095830990237221088,
    0.00030288310850594538, -0.000977649094383913, -0.0013303481983805454,
    -0.0025281744029548962, 0.0043445195269987509, 0.0031466933224244022,
    -0.00027341187214300396, 0.00079458607842282792, 0.00029068069021252394,
    -0.00081185489649234757, -0.00097985223440646713, -0.0020006782923504946,
    0.0035472299850082115, 0.0025264039270641849, -0.00025061587863193905,
    0.00063727631602813843, 0.0002654797490792711, -0.00065214018647547032,
    -0.00067318037461868156, -0.0015160192903928876, 0.012795403983684134,
    0.0019525650679099269, -0.00021673402974571048, 0.00048907177065744616,
    0.00022893399639321339, -0.00050127173730494916, 0.0, -0.0030206513452876579,
    -0.0017232377639297368, 0.0038136612825508918, 0.0051110748639088145,
    0.00092285457198038187, -0.00023455745234797904, -0.00095291345510268492,
    0.00026461633547028205, -0.0024727789479560103, -0.001332950801458733,
    0.0031510522086845585, 0.0042908803551818383, 0.00077620495950059623,
    -0.0002427704150552893, -0.000802148717340786, 0.00026871417289547883,
    -0.0019577224247309395, -0.000980059742687335, 0.0025281600732892616,
    0.0035058227553328675, 0.00063116994838356938, -0.00023384806071463256,
    -0.00065279883888753594, 0.00025547695121859866, -0.0014838795455563497,
    -0.000671888199816327, 0.0019525650679099269, 0.012764556413649953,
    0.00049078120934781613, -0.00020963545416611206, -0.000508007509241987,
    0.000226861754060283, 0.0, -0.00032706308966284708, 0.00081637237798699478,
    -0.00030012462182707727, 0.00084331084582276426, 0.0040332955100120006,
    -0.0010139523346355593, -0.003957488221935355, 0.0009381450465589141,
    -0.00030465747079058513, 0.00070584101965614273, -0.00028077807539729824,
    0.00072972041504942961, 0.0034783682965683609, -0.0009729536697887063,
    -0.0034286028763061841, 0.00092318824952652978, -0.00027333205952141372,
    0.00059062006921040144, -0.0002527633246569157, 0.00061118880407489925,
    0.0029028125638056773, -0.0008949428332404452, -0.0028732482684981713,
    0.00086537853793293863, -0.0002337655865632675, 0.00047374965253025919,
    -0.00021673402974571048, 0.00049078120934781613, 0.012320930409864067,
    -0.000781067528292359, -0.0023059832810429439, 0.00076612039947123616, 0.0,
    0.00079684681599981842, -0.00033376006452602146, 0.000848813562748073,
    -0.00028179331777776636, -0.0010149129394430032, 0.0040311591644687176,
    0.00088406322949881051, -0.003900309454524522, 0.00069000506929258647,
    -0.00030871067710370244, 0.00073192039826569, -0.00026679534813059825,
    -0.0009735447062356532, 0.0034720462122760009, 0.00087783483363120809,
    -0.0033763363396715541, 0.0005781811396680796, -0.00027534156660509251,
    0.00061097461786159589, -0.00024254808841157579, -0.00089520419488189613,
    0.0028938267821706251, 0.00082860120194047334, -0.0028272237892292009,
    0.00046434822949252151, -0.00023435899533103696, 0.00048907177065744616,
    -0.00020963545416611206, -0.000781067528292359, 0.012310859434555897,
    0.00073754727779795257, -0.0022673391840614876, 0.0, 0.00034616367290566372,
    -0.00084488541202255927, 0.00031903138500366746, -0.00087201769992455538,
    -0.00395963067264823, 0.00088442998819836293, 0.00429366048985211,
    -0.0012184598054022417, 0.00032183895027643726, -0.00073072420200215543,
    0.0002977389368139312, -0.00075482421546466116, -0.0034298421042831561,
    0.00087803048151565734, 0.0037064247216440152, -0.0011546130988765162,
    0.00028826743095268921, -0.00061163482449975895, 0.00026746981749240818,
    -0.00063243243796003981, -0.0028737680576011574, 0.00082867747727940729,
    0.0030960228977929133, -0.0010509323174711623, 0.00024618348805900019,
    -0.00049075801757620058, 0.00022893399639321336, -0.00050800750924198722,
    -0.0023059832810429439, 0.0007375472777979529, 0.012477645536404897,
    -0.00090920953315990524, 0.0, -0.00081594739924263486,
    0.00036227309856158568, -0.00086772032592466312, 0.000310500171879557,
    0.000941248102079235, -0.0039016368180315184, -0.0012202354974155661,
    0.0041806242133678485, -0.00070718654877843833, 0.00033359385944971482,
    -0.000748881259682323, 0.00029189914854582997, 0.00092501851395044915,
    -0.0033771230240029512, -0.0011556566789690387, 0.003607761189021539,
    -0.0005931165110993552, 0.00029635632189444963, -0.00062568111069708822,
    0.00026379172229671613, 0.000866159688677376, -0.002827561426209586,
    -0.001051375831235215, 0.0030127775687674241, -0.00047676613098825431,
    0.0002513673603769781, -0.00050127173730494894, 0.00022686175406028296,
    0.00076612039947123616, -0.002267339184061488, -0.00090920953315990524,
    0.012410428317750157, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100000.0 };

  static const real_T r[2112] = { -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T s[12] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T t[2560] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const real_T u[640] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  boolean_T exitg1;
  if (rtmIsMajorTimeStep(proc_control_node_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&proc_control_node_M->solverInfo,
                          ((proc_control_node_M->Timing.clockTick0+1)*
      proc_control_node_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(proc_control_node_M)) {
    proc_control_node_M->Timing.t[0] = rtsiGetT(&proc_control_node_M->solverInfo);
  }

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.ModlePhysique_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_k);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_d);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.Plotvalues_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_pz);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.ROSOutput_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.SendTargetReached_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.Subsystem2.Subsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_b);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_g);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_h);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_o);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IDLE_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_l);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_i);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_b);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.SubsystemManual_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.SubsystemAuto_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.Pretraitement_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.Subsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_p);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.singleWptsTrajectory_SubsysRanB);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_d);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_kg);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e);

  // Reset subsysRan breadcrumbs
  srClearBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Outputs for Atomic SubSystem: '<S12>/Subscribe2'
    // MATLABSystem: '<S226>/SourceBlock' incorporates:
    //   Inport: '<S232>/In1'

    proc_control_node_B.SourceBlock_o1_d =
      Sub_proc_control_node_204.getLatestMessage
      (&proc_control_node_B.b_varargout_2_o4);

    // Outputs for Enabled SubSystem: '<S226>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S232>/Enable'

    if (proc_control_node_B.SourceBlock_o1_d) {
      proc_control_node_B.In1_b = proc_control_node_B.b_varargout_2_o4;
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_k);
    }

    // End of MATLABSystem: '<S226>/SourceBlock'
    // End of Outputs for SubSystem: '<S226>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S12>/Subscribe2'

    // SignalConversion generated from: '<S12>/Bus Selector3'
    proc_control_node_B.Data = proc_control_node_B.In1_b.Data;
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // Outputs for Atomic SubSystem: '<S3>/Subscribe'
    // MATLABSystem: '<S59>/SourceBlock' incorporates:
    //   Inport: '<S61>/In1'

    proc_control_node_B.SourceBlock_o1_h =
      Sub_proc_control_node_31_5.getLatestMessage(&proc_control_node_B.msg_m);

    // Outputs for Enabled SubSystem: '<S59>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S61>/Enable'

    if (proc_control_node_B.SourceBlock_o1_h) {
      proc_control_node_B.In1 = proc_control_node_B.msg_m;
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_pz);
    }

    // End of MATLABSystem: '<S59>/SourceBlock'
    // End of Outputs for SubSystem: '<S59>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe'

    // SignalConversion generated from: '<S3>/Bus Selector3'
    proc_control_node_B.Z = proc_control_node_B.In1.AngularVelocity.Z;

    // SignalConversion generated from: '<S3>/Bus Selector3'
    proc_control_node_B.Y = proc_control_node_B.In1.AngularVelocity.Y;

    // SignalConversion generated from: '<S3>/Bus Selector3'
    proc_control_node_B.X = proc_control_node_B.In1.AngularVelocity.X;

    // Outputs for Atomic SubSystem: '<S3>/Subscribe1'
    // MATLABSystem: '<S60>/SourceBlock' incorporates:
    //   Inport: '<S62>/In1'

    proc_control_node_B.SourceBlock_o1_n =
      Sub_proc_control_node_31_6.getLatestMessage(&proc_control_node_B.msg_f);

    // Outputs for Enabled SubSystem: '<S60>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S62>/Enable'

    if (proc_control_node_B.SourceBlock_o1_n) {
      proc_control_node_B.In1_f = proc_control_node_B.msg_f;
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g);
    }

    // End of MATLABSystem: '<S60>/SourceBlock'
    // End of Outputs for SubSystem: '<S60>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/Subscribe1'

    // MATLAB Function: '<S10>/MATLAB Function1' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Delay: '<S10>/Delay'
    //   SignalConversion generated from: '<S3>/Bus Selector1'

    proc_control_node_B.rtb_y_a_idx_0 = proc_control_node_B.In1_f.XVelBtm;
    if (proc_control_node_B.In1_f.XVelBtm <
        -proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_0 = proc_control_node_DW.Delay_DSTATE[0];
    } else if (proc_control_node_B.In1_f.XVelBtm >
               proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_0 = proc_control_node_DW.Delay_DSTATE[0];
    }

    proc_control_node_B.rtb_y_a_idx_1 = proc_control_node_B.In1_f.YVelBtm;
    if (proc_control_node_B.In1_f.YVelBtm <
        -proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_1 = proc_control_node_DW.Delay_DSTATE[1];
    } else if (proc_control_node_B.In1_f.YVelBtm >
               proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_1 = proc_control_node_DW.Delay_DSTATE[1];
    }

    // SignalConversion generated from: '<S3>/Bus Selector1'
    proc_control_node_B.rtb_y_a_idx_2 = proc_control_node_B.In1_f.ZVelBtm;

    // MATLAB Function: '<S10>/MATLAB Function1' incorporates:
    //   Constant: '<S10>/Constant1'
    //   Delay: '<S10>/Delay'
    //   SignalConversion generated from: '<S3>/Bus Selector1'

    if (proc_control_node_B.In1_f.ZVelBtm <
        -proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_2 = proc_control_node_DW.Delay_DSTATE[2];
    } else if (proc_control_node_B.In1_f.ZVelBtm >
               proc_control_node_P.Constant1_Value_n) {
      proc_control_node_B.rtb_y_a_idx_2 = proc_control_node_DW.Delay_DSTATE[2];
    }

    // Outputs for Enabled SubSystem: '<S155>/Subsystem2'
    // Delay: '<S155>/Delay'
    proc_control_node_Subsystem2(proc_control_node_M,
      proc_control_node_DW.Delay_DSTATE_c, &proc_control_node_B.q0,
      &proc_control_node_B.q1, &proc_control_node_B.q2, &proc_control_node_B.q3,
      &proc_control_node_DW.Subsystem2_p, &proc_control_node_P.Subsystem2_p);

    // End of Outputs for SubSystem: '<S155>/Subsystem2'

    // Sqrt: '<S176>/sqrt' incorporates:
    //   Product: '<S177>/Product'
    //   Product: '<S177>/Product1'
    //   Product: '<S177>/Product2'
    //   Product: '<S177>/Product3'
    //   Sum: '<S177>/Sum'

    proc_control_node_B.Merge_a = sqrt(((proc_control_node_B.q0 *
      proc_control_node_B.q0 + proc_control_node_B.q1 * proc_control_node_B.q1)
      + proc_control_node_B.q2 * proc_control_node_B.q2) +
      proc_control_node_B.q3 * proc_control_node_B.q3);

    // Product: '<S172>/Product1'
    proc_control_node_B.fcn2 = proc_control_node_B.q1 /
      proc_control_node_B.Merge_a;

    // Product: '<S172>/Product3'
    proc_control_node_B.fcn4_g = proc_control_node_B.q3 /
      proc_control_node_B.Merge_a;

    // Product: '<S172>/Product'
    proc_control_node_B.Product3_gb = proc_control_node_B.q0 /
      proc_control_node_B.Merge_a;

    // Product: '<S172>/Product2'
    proc_control_node_B.Merge_a = proc_control_node_B.q2 /
      proc_control_node_B.Merge_a;

    // Product: '<S175>/Product6' incorporates:
    //   Product: '<S174>/Product6'

    proc_control_node_B.fcn5_e = proc_control_node_B.fcn2 *
      proc_control_node_B.fcn2;

    // Sum: '<S175>/Sum' incorporates:
    //   Constant: '<S175>/Constant'
    //   Gain: '<S175>/Gain'
    //   Gain: '<S175>/Gain1'
    //   Gain: '<S175>/Gain2'
    //   Product: '<S175>/Product'
    //   Product: '<S175>/Product1'
    //   Product: '<S175>/Product2'
    //   Product: '<S175>/Product3'
    //   Product: '<S175>/Product4'
    //   Product: '<S175>/Product5'
    //   Product: '<S175>/Product6'
    //   Product: '<S175>/Product7'
    //   Product: '<S175>/Product8'
    //   Sum: '<S175>/Sum1'
    //   Sum: '<S175>/Sum2'
    //   Sum: '<S175>/Sum3'

    proc_control_node_B.Sum = ((proc_control_node_B.fcn2 *
      proc_control_node_B.fcn4_g + proc_control_node_B.Product3_gb *
      proc_control_node_B.Merge_a) * proc_control_node_P.Gain_Gain_h *
      proc_control_node_B.rtb_y_a_idx_0 + (proc_control_node_B.Merge_a *
      proc_control_node_B.fcn4_g - proc_control_node_B.Product3_gb *
      proc_control_node_B.fcn2) * proc_control_node_P.Gain1_Gain_k *
      proc_control_node_B.rtb_y_a_idx_1) +
      ((proc_control_node_P.Constant_Value_ic - proc_control_node_B.fcn5_e) -
       proc_control_node_B.Merge_a * proc_control_node_B.Merge_a) *
      proc_control_node_P.Gain2_Gain_by * proc_control_node_B.rtb_y_a_idx_2;

    // Product: '<S174>/Product7' incorporates:
    //   Product: '<S173>/Product7'

    proc_control_node_B.Product1_fh = proc_control_node_B.fcn4_g *
      proc_control_node_B.fcn4_g;

    // Sum: '<S174>/Sum' incorporates:
    //   Constant: '<S174>/Constant'
    //   Gain: '<S174>/Gain'
    //   Gain: '<S174>/Gain1'
    //   Gain: '<S174>/Gain2'
    //   Product: '<S174>/Product'
    //   Product: '<S174>/Product1'
    //   Product: '<S174>/Product2'
    //   Product: '<S174>/Product3'
    //   Product: '<S174>/Product4'
    //   Product: '<S174>/Product5'
    //   Product: '<S174>/Product7'
    //   Product: '<S174>/Product8'
    //   Sum: '<S174>/Sum1'
    //   Sum: '<S174>/Sum2'
    //   Sum: '<S174>/Sum3'

    proc_control_node_B.Sum_c = (((proc_control_node_P.Constant_Value_pg -
      proc_control_node_B.fcn5_e) - proc_control_node_B.Product1_fh) *
      proc_control_node_P.Gain2_Gain_lp * proc_control_node_B.rtb_y_a_idx_1 +
      (proc_control_node_B.fcn2 * proc_control_node_B.Merge_a -
       proc_control_node_B.Product3_gb * proc_control_node_B.fcn4_g) *
      proc_control_node_P.Gain_Gain_n * proc_control_node_B.rtb_y_a_idx_0) +
      (proc_control_node_B.Product3_gb * proc_control_node_B.fcn2 +
       proc_control_node_B.Merge_a * proc_control_node_B.fcn4_g) *
      proc_control_node_P.Gain1_Gain_f * proc_control_node_B.rtb_y_a_idx_2;

    // Sum: '<S173>/Sum' incorporates:
    //   Constant: '<S173>/Constant'
    //   Gain: '<S173>/Gain'
    //   Gain: '<S173>/Gain1'
    //   Gain: '<S173>/Gain2'
    //   Product: '<S173>/Product'
    //   Product: '<S173>/Product1'
    //   Product: '<S173>/Product2'
    //   Product: '<S173>/Product3'
    //   Product: '<S173>/Product4'
    //   Product: '<S173>/Product5'
    //   Product: '<S173>/Product6'
    //   Product: '<S173>/Product8'
    //   Sum: '<S173>/Sum1'
    //   Sum: '<S173>/Sum2'
    //   Sum: '<S173>/Sum3'

    proc_control_node_B.Sum_f = (((proc_control_node_P.Constant_Value_l4 -
      proc_control_node_B.Merge_a * proc_control_node_B.Merge_a) -
      proc_control_node_B.Product1_fh) * proc_control_node_P.Gain2_Gain_a *
      proc_control_node_B.rtb_y_a_idx_0 + (proc_control_node_B.fcn2 *
      proc_control_node_B.Merge_a + proc_control_node_B.Product3_gb *
      proc_control_node_B.fcn4_g) * proc_control_node_P.Gain_Gain_l *
      proc_control_node_B.rtb_y_a_idx_1) + (proc_control_node_B.fcn2 *
      proc_control_node_B.fcn4_g - proc_control_node_B.Product3_gb *
      proc_control_node_B.Merge_a) * proc_control_node_P.Gain1_Gain_fe *
      proc_control_node_B.rtb_y_a_idx_2;

    // MATLAB Function: '<S3>/Quaternion Normalise' incorporates:
    //   SignalConversion generated from: '<S58>/ SFunction '

    proc_control_node_B.fcn2 = 3.3121686421112381E-170;
    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1.Orientation.W);
    if (proc_control_node_B.fcn4_g > 3.3121686421112381E-170) {
      proc_control_node_B.Merge_a = 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        3.3121686421112381E-170;
      proc_control_node_B.Merge_a = proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1.Orientation.X);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1.Orientation.Y);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1.Orientation.Z);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.Merge_a = proc_control_node_B.fcn2 * sqrt
      (proc_control_node_B.Merge_a);
    proc_control_node_B.fcn2 = proc_control_node_B.In1.Orientation.W /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[0] = rtIsNaN(proc_control_node_B.fcn2);
    proc_control_node_B.TmpSignalConversionAtSFun_a[0] =
      proc_control_node_B.fcn2;
    proc_control_node_B.fcn2 = proc_control_node_B.In1.Orientation.X /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[1] = rtIsNaN(proc_control_node_B.fcn2);
    proc_control_node_B.TmpSignalConversionAtSFun_a[1] =
      proc_control_node_B.fcn2;
    proc_control_node_B.fcn2 = proc_control_node_B.In1.Orientation.Y /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[2] = rtIsNaN(proc_control_node_B.fcn2);
    proc_control_node_B.TmpSignalConversionAtSFun_a[2] =
      proc_control_node_B.fcn2;
    proc_control_node_B.fcn2 = proc_control_node_B.In1.Orientation.Z /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[3] = rtIsNaN(proc_control_node_B.fcn2);
    proc_control_node_B.TmpSignalConversionAtSFun_a[3] =
      proc_control_node_B.fcn2;
    proc_control_node_B.y_ft = true;
    proc_control_node_B.ibmat = 0;
    exitg1 = false;
    while ((!exitg1) && (proc_control_node_B.ibmat < 4)) {
      if (!proc_control_node_B.b_e[proc_control_node_B.ibmat]) {
        proc_control_node_B.y_ft = false;
        exitg1 = true;
      } else {
        proc_control_node_B.ibmat++;
      }
    }

    if (proc_control_node_B.y_ft) {
      proc_control_node_B.TmpSignalConversionAtSFun_a[0] = 1.0;
      proc_control_node_B.TmpSignalConversionAtSFun_a[1] = 0.0;
      proc_control_node_B.TmpSignalConversionAtSFun_a[2] = 0.0;
      proc_control_node_B.TmpSignalConversionAtSFun_a[3] = 0.0;
    }

    // End of MATLAB Function: '<S3>/Quaternion Normalise'

    // UnaryMinus: '<S157>/Unary Minus'
    proc_control_node_B.fcn5_e =
      -proc_control_node_B.TmpSignalConversionAtSFun_a[1];

    // UnaryMinus: '<S157>/Unary Minus1'
    proc_control_node_B.Product1_fh =
      -proc_control_node_B.TmpSignalConversionAtSFun_a[2];

    // UnaryMinus: '<S157>/Unary Minus2'
    proc_control_node_B.Product2_ei =
      -proc_control_node_B.TmpSignalConversionAtSFun_a[3];

    // Gain: '<S10>/Gain' incorporates:
    //   UnaryMinus: '<S157>/Unary Minus'
    //   UnaryMinus: '<S157>/Unary Minus1'
    //   UnaryMinus: '<S157>/Unary Minus2'

    proc_control_node_B.qW2S[0] = proc_control_node_P.Gain_Gain_m3 *
      proc_control_node_B.TmpSignalConversionAtSFun_a[0];
    proc_control_node_B.qW2S[1] = proc_control_node_P.Gain_Gain_m3 *
      -proc_control_node_B.TmpSignalConversionAtSFun_a[1];
    proc_control_node_B.qW2S[2] = proc_control_node_P.Gain_Gain_m3 *
      -proc_control_node_B.TmpSignalConversionAtSFun_a[2];
    proc_control_node_B.qW2S[3] = proc_control_node_P.Gain_Gain_m3 *
      -proc_control_node_B.TmpSignalConversionAtSFun_a[3];

    // Sqrt: '<S170>/sqrt' incorporates:
    //   Product: '<S171>/Product'
    //   Product: '<S171>/Product1'
    //   Product: '<S171>/Product2'
    //   Product: '<S171>/Product3'
    //   Sum: '<S171>/Sum'

    proc_control_node_B.Product3_gb = sqrt(((proc_control_node_B.qW2S[0] *
      proc_control_node_B.qW2S[0] + proc_control_node_B.qW2S[1] *
      proc_control_node_B.qW2S[1]) + proc_control_node_B.qW2S[2] *
      proc_control_node_B.qW2S[2]) + proc_control_node_B.qW2S[3] *
      proc_control_node_B.qW2S[3]);

    // Product: '<S166>/Product2'
    proc_control_node_B.fcn4_g = proc_control_node_B.qW2S[2] /
      proc_control_node_B.Product3_gb;

    // Product: '<S166>/Product3'
    proc_control_node_B.fcn2 = proc_control_node_B.qW2S[3] /
      proc_control_node_B.Product3_gb;

    // Product: '<S166>/Product1'
    proc_control_node_B.Merge_a = proc_control_node_B.qW2S[1] /
      proc_control_node_B.Product3_gb;

    // Product: '<S166>/Product'
    proc_control_node_B.Product3_gb = proc_control_node_B.qW2S[0] /
      proc_control_node_B.Product3_gb;

    // Product: '<S167>/Product' incorporates:
    //   Product: '<S168>/Product'

    proc_control_node_B.t15 = proc_control_node_B.Merge_a *
      proc_control_node_B.fcn4_g;

    // Product: '<S167>/Product2' incorporates:
    //   Product: '<S169>/Product1'

    proc_control_node_B.t25 = proc_control_node_B.Product3_gb *
      proc_control_node_B.fcn4_g;

    // Product: '<S167>/Product6' incorporates:
    //   Product: '<S169>/Product7'

    proc_control_node_B.t29 = proc_control_node_B.fcn4_g *
      proc_control_node_B.fcn4_g;

    // Product: '<S167>/Product7' incorporates:
    //   Product: '<S168>/Product7'

    proc_control_node_B.rtb_Sum_tmp = proc_control_node_B.fcn2 *
      proc_control_node_B.fcn2;

    // Product: '<S167>/Product1' incorporates:
    //   Product: '<S168>/Product1'

    proc_control_node_B.t9 = proc_control_node_B.Product3_gb *
      proc_control_node_B.fcn2;

    // Product: '<S167>/Product3' incorporates:
    //   Product: '<S169>/Product'

    proc_control_node_B.t10 = proc_control_node_B.Merge_a *
      proc_control_node_B.fcn2;

    // Sum: '<S167>/Sum' incorporates:
    //   Constant: '<S167>/Constant'
    //   Gain: '<S167>/Gain'
    //   Gain: '<S167>/Gain1'
    //   Gain: '<S167>/Gain2'
    //   Product: '<S167>/Product'
    //   Product: '<S167>/Product1'
    //   Product: '<S167>/Product2'
    //   Product: '<S167>/Product3'
    //   Product: '<S167>/Product4'
    //   Product: '<S167>/Product5'
    //   Product: '<S167>/Product6'
    //   Product: '<S167>/Product7'
    //   Product: '<S167>/Product8'
    //   Sum: '<S167>/Sum1'
    //   Sum: '<S167>/Sum2'
    //   Sum: '<S167>/Sum3'

    proc_control_node_B.Sum_l = (((proc_control_node_P.Constant_Value_g0 -
      proc_control_node_B.t29) - proc_control_node_B.rtb_Sum_tmp) *
      proc_control_node_P.Gain2_Gain_f * proc_control_node_B.Sum_f +
      (proc_control_node_B.t15 + proc_control_node_B.t9) *
      proc_control_node_P.Gain_Gain_p * proc_control_node_B.Sum_c) +
      (proc_control_node_B.t10 - proc_control_node_B.t25) *
      proc_control_node_P.Gain1_Gain_gc * proc_control_node_B.Sum;

    // Product: '<S168>/Product2' incorporates:
    //   Product: '<S169>/Product2'

    proc_control_node_B.t65 = proc_control_node_B.Product3_gb *
      proc_control_node_B.Merge_a;

    // Product: '<S168>/Product6' incorporates:
    //   Product: '<S169>/Product6'

    proc_control_node_B.t70 = proc_control_node_B.Merge_a *
      proc_control_node_B.Merge_a;

    // Product: '<S168>/Product3' incorporates:
    //   Product: '<S169>/Product3'

    proc_control_node_B.Merge_a = proc_control_node_B.fcn4_g *
      proc_control_node_B.fcn2;

    // Sum: '<S168>/Sum' incorporates:
    //   Constant: '<S168>/Constant'
    //   Gain: '<S168>/Gain'
    //   Gain: '<S168>/Gain1'
    //   Gain: '<S168>/Gain2'
    //   Product: '<S168>/Product2'
    //   Product: '<S168>/Product3'
    //   Product: '<S168>/Product4'
    //   Product: '<S168>/Product5'
    //   Product: '<S168>/Product6'
    //   Product: '<S168>/Product8'
    //   Sum: '<S168>/Sum1'
    //   Sum: '<S168>/Sum2'
    //   Sum: '<S168>/Sum3'

    proc_control_node_B.Sum_p_n = (((proc_control_node_P.Constant_Value_h3 -
      proc_control_node_B.t70) - proc_control_node_B.rtb_Sum_tmp) *
      proc_control_node_P.Gain2_Gain_ah * proc_control_node_B.Sum_c +
      (proc_control_node_B.t15 - proc_control_node_B.t9) *
      proc_control_node_P.Gain_Gain_i * proc_control_node_B.Sum_f) +
      (proc_control_node_B.t65 + proc_control_node_B.Merge_a) *
      proc_control_node_P.Gain1_Gain_kt * proc_control_node_B.Sum;

    // Sum: '<S169>/Sum' incorporates:
    //   Constant: '<S169>/Constant'
    //   Gain: '<S169>/Gain'
    //   Gain: '<S169>/Gain1'
    //   Gain: '<S169>/Gain2'
    //   Product: '<S169>/Product4'
    //   Product: '<S169>/Product5'
    //   Product: '<S169>/Product8'
    //   Sum: '<S169>/Sum1'
    //   Sum: '<S169>/Sum2'
    //   Sum: '<S169>/Sum3'

    proc_control_node_B.Sum_a = ((proc_control_node_B.t10 +
      proc_control_node_B.t25) * proc_control_node_P.Gain_Gain_o *
      proc_control_node_B.Sum_f + (proc_control_node_B.Merge_a -
      proc_control_node_B.t65) * proc_control_node_P.Gain1_Gain_l *
      proc_control_node_B.Sum_c) + ((proc_control_node_P.Constant_Value_bb -
      proc_control_node_B.t70) - proc_control_node_B.t29) *
      proc_control_node_P.Gain2_Gain_n * proc_control_node_B.Sum;
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Outputs for Atomic SubSystem: '<S12>/Subscribe'
    // MATLABSystem: '<S224>/SourceBlock' incorporates:
    //   Inport: '<S230>/In1'

    proc_control_node_B.SourceBlock_o1_a =
      Sub_proc_control_node_202.getLatestMessage
      (&proc_control_node_B.b_varargout_2_n);

    // Outputs for Enabled SubSystem: '<S224>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S230>/Enable'

    if (proc_control_node_B.SourceBlock_o1_a) {
      proc_control_node_B.In1_n = proc_control_node_B.b_varargout_2_n;
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_d);
    }

    // End of Outputs for SubSystem: '<S224>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S12>/Subscribe'

    // Outputs for Atomic SubSystem: '<S12>/Subscribe3'
    // MATLABSystem: '<S227>/SourceBlock'
    proc_control_node_B.y_ft = Sub_proc_control_node_205.getLatestMessage
      (&proc_control_node_B.b_varargout_2_j);

    // Outputs for Enabled SubSystem: '<S227>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S233>/Enable'

    if (proc_control_node_B.y_ft) {
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e);
    }

    // End of Outputs for SubSystem: '<S227>/Enabled Subsystem'

    // Outputs for Atomic SubSystem: '<S12>/Subscribe'
    // Logic: '<S12>/OR' incorporates:
    //   MATLABSystem: '<S224>/SourceBlock'
    //   MATLABSystem: '<S227>/SourceBlock'

    proc_control_node_B.OR = (proc_control_node_B.y_ft ||
      proc_control_node_B.SourceBlock_o1_a);

    // End of Outputs for SubSystem: '<S12>/Subscribe'
    // End of Outputs for SubSystem: '<S12>/Subscribe3'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
    if (proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[0] =
        proc_control_node_B.In1_n.Position.X;
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[1] =
        proc_control_node_B.In1_n.Position.Y;
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[2] =
        proc_control_node_B.In1_n.Position.Z;
    }

    if (proc_control_node_B.OR &&
        (proc_control_node_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[0] =
        proc_control_node_B.In1_n.Position.X;
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[1] =
        proc_control_node_B.In1_n.Position.Y;
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[2] =
        proc_control_node_B.In1_n.Position.Z;
    }

    // DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
    proc_control_node_B.WorldPosition[0] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_l +
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[0];
    proc_control_node_B.WorldPosition[1] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_p_n +
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[1];
    proc_control_node_B.WorldPosition[2] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_a +
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[2];

    // Sum: '<S165>/Sum' incorporates:
    //   Product: '<S165>/Product'
    //   Product: '<S165>/Product1'
    //   Product: '<S165>/Product2'
    //   Product: '<S165>/Product3'
    //   Sum: '<S187>/Sum'

    proc_control_node_B.Merge_a =
      ((proc_control_node_B.TmpSignalConversionAtSFun_a[0] *
        proc_control_node_B.TmpSignalConversionAtSFun_a[0] +
        proc_control_node_B.fcn5_e * proc_control_node_B.fcn5_e) +
       proc_control_node_B.Product1_fh * proc_control_node_B.Product1_fh) +
      proc_control_node_B.Product2_ei * proc_control_node_B.Product2_ei;

    // Product: '<S158>/Divide3' incorporates:
    //   Sum: '<S165>/Sum'
    //   UnaryMinus: '<S164>/Unary Minus2'

    proc_control_node_B.Divide3 = -proc_control_node_B.Product2_ei /
      proc_control_node_B.Merge_a;

    // Product: '<S158>/Divide2' incorporates:
    //   Sum: '<S165>/Sum'
    //   UnaryMinus: '<S164>/Unary Minus1'

    proc_control_node_B.Divide2 = -proc_control_node_B.Product1_fh /
      proc_control_node_B.Merge_a;

    // Product: '<S158>/Divide1' incorporates:
    //   Sum: '<S165>/Sum'
    //   UnaryMinus: '<S164>/Unary Minus'

    proc_control_node_B.Divide1 = -proc_control_node_B.fcn5_e /
      proc_control_node_B.Merge_a;

    // Product: '<S158>/Divide' incorporates:
    //   Sum: '<S165>/Sum'

    proc_control_node_B.Divide =
      proc_control_node_B.TmpSignalConversionAtSFun_a[0] /
      proc_control_node_B.Merge_a;

    // DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
    if (proc_control_node_B.OR &&
        (proc_control_node_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        proc_control_node_P.DiscreteTimeIntegrator1_IC;
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        proc_control_node_P.DiscreteTimeIntegrator1_IC;
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[2] =
        proc_control_node_P.DiscreteTimeIntegrator1_IC;
    }

    // DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
    proc_control_node_B.BodyPosition[0] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum_f +
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[0];
    proc_control_node_B.BodyPosition[1] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum_c +
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[1];
    proc_control_node_B.BodyPosition[2] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum +
      proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[2];

    // Sqrt: '<S186>/sqrt'
    proc_control_node_B.Product3_gb = sqrt(proc_control_node_B.Merge_a);

    // Fcn: '<S178>/fcn3' incorporates:
    //   Product: '<S181>/Product'
    //   Product: '<S181>/Product1'
    //   Product: '<S181>/Product2'
    //   Product: '<S181>/Product3'

    proc_control_node_B.Merge_a = (proc_control_node_B.fcn5_e /
      proc_control_node_B.Product3_gb * (proc_control_node_B.Product2_ei /
      proc_control_node_B.Product3_gb) +
      proc_control_node_B.TmpSignalConversionAtSFun_a[0] /
      proc_control_node_B.Product3_gb * (proc_control_node_B.Product1_fh /
      proc_control_node_B.Product3_gb)) * 2.0;

    // If: '<S182>/If'
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      if (proc_control_node_B.Merge_a > 1.0) {
        proc_control_node_B.rtAction = 0;
      } else if (proc_control_node_B.Merge_a < -1.0) {
        proc_control_node_B.rtAction = 1;
      } else {
        proc_control_node_B.rtAction = 2;
      }

      proc_control_node_DW.If_ActiveSubsystem = proc_control_node_B.rtAction;
    } else {
      proc_control_node_B.rtAction = proc_control_node_DW.If_ActiveSubsystem;
    }

    switch (proc_control_node_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S182>/If Action Subsystem' incorporates:
      //   ActionPort: '<S183>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_l);
      }

      // End of Outputs for SubSystem: '<S182>/If Action Subsystem'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S182>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S184>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_i);
      }

      // End of Outputs for SubSystem: '<S182>/If Action Subsystem1'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S182>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S185>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_b);
      }

      // End of Outputs for SubSystem: '<S182>/If Action Subsystem2'
      break;
    }

    // End of If: '<S182>/If'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Logic: '<S12>/OR1'
    proc_control_node_B.OR1 = (proc_control_node_B.SourceBlock_o1_d ||
      proc_control_node_B.OR);
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // Gain: '<S194>/Gain'
    proc_control_node_B.Merge_a = 2.0 * proc_control_node_P.zeta_l *
      (6.2831853071795862 * proc_control_node_P.wn_l);
    for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
         proc_control_node_B.i++) {
      // DiscreteIntegrator: '<S198>/Integrator' incorporates:
      //   Constant: '<S194>/Constant'
      //   Constant: '<S194>/Constant3'

      if ((proc_control_node_P.Constant_Value_as != 0.0) ||
          (proc_control_node_DW.Integrator_PrevResetState != 0)) {
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
          proc_control_node_P.Constant3_Value;
        if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] >=
            proc_control_node_P.Integrator_UpperSat) {
          proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
            proc_control_node_P.Integrator_UpperSat;
        } else if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i]
                   <= proc_control_node_P.Integrator_LowerSat) {
          proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
            proc_control_node_P.Integrator_LowerSat;
        }
      }

      if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] >=
          proc_control_node_P.Integrator_UpperSat) {
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
          proc_control_node_P.Integrator_UpperSat;
      } else if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] <=
                 proc_control_node_P.Integrator_LowerSat) {
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
          proc_control_node_P.Integrator_LowerSat;
      }

      proc_control_node_B.Product3_gb =
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i];

      // End of DiscreteIntegrator: '<S198>/Integrator'

      // Saturate: '<S198>/Saturation'
      if (proc_control_node_B.Product3_gb >
          proc_control_node_P.Saturation_UpperSat) {
        proc_control_node_B.Product3_gb =
          proc_control_node_P.Saturation_UpperSat;
      } else if (proc_control_node_B.Product3_gb <
                 proc_control_node_P.Saturation_LowerSat) {
        proc_control_node_B.Product3_gb =
          proc_control_node_P.Saturation_LowerSat;
      }

      // Gain: '<S194>/Gain3' incorporates:
      //   Saturate: '<S198>/Saturation'

      proc_control_node_B.Gain3[proc_control_node_B.i] =
        proc_control_node_P.Gain3_Gain * proc_control_node_B.Product3_gb;

      // DiscreteIntegrator: '<S199>/Integrator' incorporates:
      //   Constant: '<S194>/Constant1'
      //   Constant: '<S194>/Constant2'

      if ((proc_control_node_P.Constant1_Value_d != 0.0) ||
          (proc_control_node_DW.Integrator_PrevResetState_h != 0)) {
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
          proc_control_node_P.Constant2_Value;
        if (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] >=
            proc_control_node_P.Integrator_UpperSat_f) {
          proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
            proc_control_node_P.Integrator_UpperSat_f;
        } else if
            (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] <=
             proc_control_node_P.Integrator_LowerSat_p) {
          proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
            proc_control_node_P.Integrator_LowerSat_p;
        }
      }

      if (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] >=
          proc_control_node_P.Integrator_UpperSat_f) {
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
          proc_control_node_P.Integrator_UpperSat_f;
      } else if (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i]
                 <= proc_control_node_P.Integrator_LowerSat_p) {
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
          proc_control_node_P.Integrator_LowerSat_p;
      }

      proc_control_node_B.Product3_gb =
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i];

      // End of DiscreteIntegrator: '<S199>/Integrator'

      // Saturate: '<S199>/Saturation'
      if (proc_control_node_B.Product3_gb >
          proc_control_node_P.Saturation_UpperSat_m) {
        proc_control_node_B.Product3_gb =
          proc_control_node_P.Saturation_UpperSat_m;
      } else if (proc_control_node_B.Product3_gb <
                 proc_control_node_P.Saturation_LowerSat_c) {
        proc_control_node_B.Product3_gb =
          proc_control_node_P.Saturation_LowerSat_c;
      }

      // Gain: '<S194>/Gain'
      proc_control_node_B.Gain_k[proc_control_node_B.i] =
        proc_control_node_B.Merge_a * proc_control_node_B.Product3_gb;

      // Saturate: '<S199>/Saturation'
      proc_control_node_B.Saturation[proc_control_node_B.i] =
        proc_control_node_B.Product3_gb;
    }

    // Outputs for Atomic SubSystem: '<S189>/Subscribe2'
    // MATLABSystem: '<S195>/SourceBlock' incorporates:
    //   Inport: '<S200>/In1'

    proc_control_node_B.y_ft = Sub_proc_control_node_184_1122.getLatestMessage
      (&proc_control_node_B.msg_ff);

    // Outputs for Enabled SubSystem: '<S195>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S200>/Enable'

    if (proc_control_node_B.y_ft) {
      proc_control_node_B.In1_o = proc_control_node_B.msg_ff;
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n);
    }

    // End of MATLABSystem: '<S195>/SourceBlock'
    // End of Outputs for SubSystem: '<S195>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S189>/Subscribe2'

    // Sum: '<S194>/Sum' incorporates:
    //   Gain: '<S189>/Gain'

    proc_control_node_B.Sum_aw[0] = (proc_control_node_B.In1_o.Linear.X -
      proc_control_node_B.Gain3[0]) - proc_control_node_B.Gain_k[0];
    proc_control_node_B.Sum_aw[1] = (proc_control_node_B.In1_o.Linear.Y -
      proc_control_node_B.Gain3[1]) - proc_control_node_B.Gain_k[1];
    proc_control_node_B.Sum_aw[2] = (proc_control_node_B.In1_o.Linear.Z -
      proc_control_node_B.Gain3[2]) - proc_control_node_B.Gain_k[2];
    proc_control_node_B.Sum_aw[3] = (proc_control_node_P.Gain_Gain_ga *
      proc_control_node_B.In1_o.Angular.X - proc_control_node_B.Gain3[3]) -
      proc_control_node_B.Gain_k[3];
    proc_control_node_B.Sum_aw[4] = (proc_control_node_P.Gain_Gain_ga *
      proc_control_node_B.In1_o.Angular.Y - proc_control_node_B.Gain3[4]) -
      proc_control_node_B.Gain_k[4];
    proc_control_node_B.Sum_aw[5] = (proc_control_node_P.Gain_Gain_ga *
      proc_control_node_B.In1_o.Angular.Z - proc_control_node_B.Gain3[5]) -
      proc_control_node_B.Gain_k[5];

    // MultiPortSwitch: '<S194>/Multiport Switch' incorporates:
    //   Constant: '<S194>/Constant4'

    switch (static_cast<int32_T>
            (proc_control_node_P.SecondOrderFilter_FilterType)) {
     case 1:
      // MultiPortSwitch: '<S194>/Multiport Switch'
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.MultiportSwitch[proc_control_node_B.i] =
          proc_control_node_B.Gain3[proc_control_node_B.i];
      }
      break;

     case 2:
      // MultiPortSwitch: '<S194>/Multiport Switch'
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.MultiportSwitch[proc_control_node_B.i] =
          proc_control_node_B.Sum_aw[proc_control_node_B.i];
      }
      break;

     case 3:
      // MultiPortSwitch: '<S194>/Multiport Switch'
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.MultiportSwitch[proc_control_node_B.i] =
          proc_control_node_B.Gain_k[proc_control_node_B.i];
      }
      break;

     default:
      // MultiPortSwitch: '<S194>/Multiport Switch' incorporates:
      //   Sum: '<S194>/Sum1'

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.MultiportSwitch[proc_control_node_B.i] =
          proc_control_node_B.Sum_aw[proc_control_node_B.i] +
          proc_control_node_B.Gain3[proc_control_node_B.i];
      }
      break;
    }

    // End of MultiPortSwitch: '<S194>/Multiport Switch'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // SwitchCase: '<S11>/Switch Case' incorporates:
    //   Constant: '<S205>/Constant1'
    //   Delay: '<S208>/Delay'
    //   Logic: '<S192>/OR'
    //   MATLABSystem: '<S206>/SourceBlock'

    proc_control_node_B.rtPrevAction =
      proc_control_node_DW.SwitchCase_ActiveSubsystem;
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      switch (proc_control_node_B.Data) {
       case 19:
       case 20:
       case 21:
        proc_control_node_B.rtAction = 0;
        break;

       case 10:
        proc_control_node_B.rtAction = 1;
        break;

       case 11:
        proc_control_node_B.rtAction = 2;
        break;

       default:
        proc_control_node_B.rtAction = 3;
        break;
      }

      proc_control_node_DW.SwitchCase_ActiveSubsystem =
        proc_control_node_B.rtAction;
    } else {
      proc_control_node_B.rtAction =
        proc_control_node_DW.SwitchCase_ActiveSubsystem;
    }

    switch (proc_control_node_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S11>/SubsystemManual' incorporates:
      //   ActionPort: '<S191>/Action Port'

      // SignalConversion generated from: '<S191>/Transpose' incorporates:
      //   Constant: '<S191>/Constant7'

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 7;
           proc_control_node_B.i++) {
        proc_control_node_B.TmpSignalConversionAtTran_a[proc_control_node_B.i] =
          proc_control_node_P.Constant7_Value[proc_control_node_B.i];
      }

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.TmpSignalConversionAtTran_a[proc_control_node_B.i +
          7] = proc_control_node_B.MultiportSwitch[proc_control_node_B.i];
      }

      // MATLAB Function: '<S191>/MATLAB Function1' incorporates:
      //   Math: '<S191>/Transpose'

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 13;
           proc_control_node_B.i++) {
        proc_control_node_B.ibmat = proc_control_node_B.i * 10;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 10;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.y_n[proc_control_node_B.ibmat +
            proc_control_node_B.ixlast] =
            proc_control_node_B.TmpSignalConversionAtTran_a[proc_control_node_B.i];
        }
      }

      // End of MATLAB Function: '<S191>/MATLAB Function1'

      // Merge: '<S11>/Merge' incorporates:
      //   SignalConversion generated from: '<S191>/Output'

      memcpy(&proc_control_node_B.Quaternion[0], &proc_control_node_B.y_n[0],
             130U * sizeof(real_T));
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.SubsystemManual_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S11>/SubsystemManual'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S11>/SubsystemAuto' incorporates:
      //   ActionPort: '<S190>/Action Port'

      // Merge: '<S11>/Merge' incorporates:
      //   Constant: '<S190>/Constant'
      //   MATLAB Function: '<S190>/MATLAB Function1'

      proc_control_no_MATLABFunction1(proc_control_node_P.Constant_Value_f,
        proc_control_node_B.Quaternion,
        &proc_control_node_B.sf_MATLABFunction1_n);

      // Merge: '<S11>/Merge1' incorporates:
      //   SignalConversion generated from: '<S190>/isReached'

      proc_control_node_B.Merge1 = false;
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.SubsystemAuto_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S11>/SubsystemAuto'
      break;

     case 2:
      if (proc_control_node_B.rtAction != proc_control_node_B.rtPrevAction) {
        // InitializeConditions for IfAction SubSystem: '<S11>/singleWpts Trajectory' incorporates:
        //   ActionPort: '<S192>/Action Port'

        // InitializeConditions for SwitchCase: '<S11>/Switch Case' incorporates:
        //   Delay: '<S192>/Delay1'
        //   Delay: '<S208>/Delay'

        proc_control_node_DW.Delay_DSTATE_n =
          proc_control_node_P.Delay_InitialCondition;
        proc_control_node_DW.Delay1_DSTATE_c =
          proc_control_node_P.Delay1_InitialCondition_k;

        // End of InitializeConditions for SubSystem: '<S11>/singleWpts Trajectory' 

        // SystemReset for IfAction SubSystem: '<S11>/singleWpts Trajectory' incorporates:
        //   ActionPort: '<S192>/Action Port'

        // SystemReset for Resettable SubSystem: '<S192>/Trajectory generator'
        // SystemReset for SwitchCase: '<S11>/Switch Case' incorporates:
        //   DiscreteIntegrator: '<S209>/Discrete-Time Integrator'

        //         %%
        //  Initialize / reset discrete-state properties
        proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b =
          proc_control_node_P.DiscreteTimeIntegrator_IC;

        // End of SystemReset for SubSystem: '<S192>/Trajectory generator'
        // End of SystemReset for SubSystem: '<S11>/singleWpts Trajectory'
        //  Fonction reset
        //  Initialize / reset discrete-state properties
      }

      // Outputs for IfAction SubSystem: '<S11>/singleWpts Trajectory' incorporates:
      //   ActionPort: '<S192>/Action Port'

      // Outputs for Enabled SubSystem: '<S208>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S211>/Enable'

      if (proc_control_node_DW.Delay_DSTATE_n > 0.0) {
        // Math: '<S211>/Transpose' incorporates:
        //   SignalConversion generated from: '<S211>/Transpose'

        proc_control_node_B.Transpose[0] = proc_control_node_B.WorldPosition[0];
        proc_control_node_B.Transpose[1] = proc_control_node_B.WorldPosition[1];
        proc_control_node_B.Transpose[2] = proc_control_node_B.WorldPosition[2];
        proc_control_node_B.Transpose[3] = proc_control_node_B.Divide;
        proc_control_node_B.Transpose[4] = proc_control_node_B.Divide1;
        proc_control_node_B.Transpose[5] = proc_control_node_B.Divide2;
        proc_control_node_B.Transpose[6] = proc_control_node_B.Divide3;

        // Update for IfAction SubSystem: '<S216>/If Action Subsystem2' incorporates:
        //   ActionPort: '<S219>/Action Port'

        // Update for If: '<S216>/If'
        srUpdateBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanBC);

        // End of Update for SubSystem: '<S216>/If Action Subsystem2'
        srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_p);
      }

      // End of Outputs for SubSystem: '<S208>/Enabled Subsystem'

      // Outputs for Atomic SubSystem: '<S192>/Subscribe'
      // MATLABSystem: '<S206>/SourceBlock' incorporates:
      //   Delay: '<S208>/Delay'

      proc_control_node_B.y_ft = Sub_proc_control_node_184_1168.getLatestMessage
        (&proc_control_node_B.b_varargout_2_o);

      // Outputs for Enabled SubSystem: '<S192>/Subsystem1' incorporates:
      //   EnablePort: '<S207>/Enable'

      // Outputs for Enabled SubSystem: '<S206>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S210>/Enable'

      if (proc_control_node_B.y_ft) {
        srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o);

        // DataTypeConversion: '<S207>/Data Type Conversion'
        proc_control_node_B.DataTypeConversion[0] =
          proc_control_node_B.b_varargout_2_o.Position.X;
        proc_control_node_B.DataTypeConversion[1] =
          proc_control_node_B.b_varargout_2_o.Position.Y;
        proc_control_node_B.DataTypeConversion[2] =
          proc_control_node_B.b_varargout_2_o.Position.Z;
        proc_control_node_B.DataTypeConversion[3] =
          proc_control_node_B.b_varargout_2_o.Orientation.Z;
        proc_control_node_B.DataTypeConversion[4] =
          proc_control_node_B.b_varargout_2_o.Orientation.Y;
        proc_control_node_B.DataTypeConversion[5] =
          proc_control_node_B.b_varargout_2_o.Orientation.X;

        // DataTypeConversion: '<S207>/Data Type Conversion1'
        proc_control_node_B.DataTypeConversion1[0] =
          proc_control_node_B.b_varargout_2_o.Frame;
        proc_control_node_B.DataTypeConversion1[1] =
          proc_control_node_B.b_varargout_2_o.Speed;

        // DataTypeConversion: '<S207>/Data Type Conversion2'
        proc_control_node_B.DataTypeConversion2 =
          proc_control_node_B.b_varargout_2_o.Fine;
        srUpdateBC(proc_control_node_DW.Subsystem1_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S206>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S192>/Subsystem1'
      // End of Outputs for SubSystem: '<S192>/Subscribe'

      // SignalConversion generated from: '<S192>/MATLAB System1' incorporates:
      //   MATLABSystem: '<S206>/SourceBlock'

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.TmpSignalConversionAtMATLAB[proc_control_node_B.i] =
          proc_control_node_B.DataTypeConversion[proc_control_node_B.i];
      }

      proc_control_node_B.TmpSignalConversionAtMATLAB[6] =
        proc_control_node_B.DataTypeConversion1[0];
      proc_control_node_B.TmpSignalConversionAtMATLAB[7] =
        proc_control_node_B.DataTypeConversion1[1];
      proc_control_node_B.TmpSignalConversionAtMATLAB[8] =
        proc_control_node_B.DataTypeConversion2;

      // MATLABSystem: '<S192>/MATLAB System1' incorporates:
      //   Constant: '<S192>/Constant'
      //   Delay: '<S192>/Delay1'
      //   MATLABSystem: '<S206>/SourceBlock'
      //   Math: '<S211>/Transpose'
      //   SignalConversion generated from: '<S192>/MATLAB System1'

      //  Main appeller à chaque exécution
      //  Suppression du buffer.
      //  ======================================================================== 
      //  Sous Routines
      // ==========================================================================         
      //  Fonction qui interprete les message ROS
      if (proc_control_node_P.Constant_Value_ha == 1.0) {
        //  supprimer le buffer de way points
        proc_control_node_B.ibmat = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
             proc_control_node_B.i++) {
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.ibmat + 1] =
            999.0;
          proc_control_node_B.ibmat += 2;
        }

        proc_control_node_DW.obj_a.i = 2.0;
      }

      // Outputs for Atomic SubSystem: '<S192>/Subscribe'
      //  Ajout d'un waypoint provenant de ROS.
      if (proc_control_node_B.y_ft && (proc_control_node_DW.obj_a.i <= 2.0)) {
        // this.poseList(this.i-1,:) = this.processWpt(waypoint.').';
        //  Fonction qui interprete les waypoints reçu par ROS
        //  Determiner le quaternion en fonction des angles d'euler.
        //  Orde de rotation : ZYX.
        //  Reel
        proc_control_node_B.twpt[7] = proc_control_node_B.DataTypeConversion1[1];

        //  Pre calculs
        proc_control_node_B.Merge_a = 0.017453292519943295 *
          proc_control_node_B.TmpSignalConversionAtMATLAB[3] / 2.0;
        proc_control_node_B.c_c[0] = proc_control_node_B.Merge_a;
        proc_control_node_B.s[0] = proc_control_node_B.Merge_a;
        proc_control_node_B.Merge_a = 0.017453292519943295 *
          proc_control_node_B.TmpSignalConversionAtMATLAB[4] / 2.0;
        proc_control_node_B.c_c[1] = proc_control_node_B.Merge_a;
        proc_control_node_B.s[1] = proc_control_node_B.Merge_a;
        proc_control_node_B.Merge_a = 0.017453292519943295 *
          proc_control_node_B.TmpSignalConversionAtMATLAB[5] / 2.0;
        proc_control_node_B.c_c[0] = cos(proc_control_node_B.c_c[0]);
        proc_control_node_B.c_c[1] = cos(proc_control_node_B.c_c[1]);
        proc_control_node_B.c_c[2] = cos(proc_control_node_B.Merge_a);
        proc_control_node_B.s[0] = sin(proc_control_node_B.s[0]);
        proc_control_node_B.s[1] = sin(proc_control_node_B.s[1]);
        proc_control_node_B.s[2] = sin(proc_control_node_B.Merge_a);
        proc_control_node_B.Merge_a = proc_control_node_B.c_c[0] *
          proc_control_node_B.c_c[1];
        proc_control_node_B.fcn2 = proc_control_node_B.s[0] *
          proc_control_node_B.s[1];
        proc_control_node_B.TmpSignalConversionAtSFun_a[0] =
          proc_control_node_B.Merge_a * proc_control_node_B.c_c[2] +
          proc_control_node_B.fcn2 * proc_control_node_B.s[2];
        proc_control_node_B.TmpSignalConversionAtSFun_a[1] =
          proc_control_node_B.Merge_a * proc_control_node_B.s[2] -
          proc_control_node_B.fcn2 * proc_control_node_B.c_c[2];
        proc_control_node_B.Merge_a = proc_control_node_B.s[0] *
          proc_control_node_B.c_c[1];
        proc_control_node_B.fcn2 = proc_control_node_B.c_c[0] *
          proc_control_node_B.s[1];
        proc_control_node_B.TmpSignalConversionAtSFun_a[2] =
          proc_control_node_B.fcn2 * proc_control_node_B.c_c[2] +
          proc_control_node_B.Merge_a * proc_control_node_B.s[2];
        proc_control_node_B.TmpSignalConversionAtSFun_a[3] =
          proc_control_node_B.Merge_a * proc_control_node_B.c_c[2] -
          proc_control_node_B.fcn2 * proc_control_node_B.s[2];

        //  rp = quatrotate(quatinv(lq),wpt(1:3)) + lp;
        // rp = rotatepoint(quatinv(lq),wpt(1:3)) + lp;
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        proc_control_node_B.fcn2 = 0.0;
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 3;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.fcn2 += proc_control_node_DW.obj_a.poseList
            [(((proc_control_node_B.ibmat + 4) << 1) + static_cast<int32_T>
              (proc_control_node_DW.obj_a.i - 1.0)) - 1] *
            proc_control_node_B.TmpSignalConversionAtMATLAB[proc_control_node_B.ibmat];
        }

        proc_control_node_B.Merge_a = 2.0 * proc_control_node_B.fcn2;
        proc_control_node_B.fcn2 = 0.0;
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 3;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.fcn4_g = proc_control_node_DW.obj_a.poseList
            [(((proc_control_node_B.ibmat + 4) << 1) + static_cast<int32_T>
              (proc_control_node_DW.obj_a.i - 1.0)) - 1];
          proc_control_node_B.fcn2 += proc_control_node_B.fcn4_g *
            proc_control_node_B.fcn4_g;
        }

        proc_control_node_B.fcn5_e = proc_control_node_DW.obj_a.poseList[
          static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 5];
        proc_control_node_B.fcn4_g = proc_control_node_B.fcn5_e *
          proc_control_node_B.fcn5_e - proc_control_node_B.fcn2;
        proc_control_node_B.Product3_gb = proc_control_node_B.fcn5_e * 2.0;

        //  Prendre le quaternion le plus cours
        proc_control_node_B.fcn2 = 0.0;
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 4;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.fcn2 += proc_control_node_DW.obj_a.poseList
            [(((proc_control_node_B.ibmat + 3) << 1) + static_cast<int32_T>
              (proc_control_node_DW.obj_a.i - 1.0)) - 1] *
            proc_control_node_B.TmpSignalConversionAtSFun_a[proc_control_node_B.ibmat];
        }

        if (proc_control_node_B.fcn2 > 1.0) {
          proc_control_node_B.b_q[0] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[0];
          proc_control_node_B.b_q[1] =
            -proc_control_node_B.TmpSignalConversionAtSFun_a[1];
          proc_control_node_B.b_q[2] =
            -proc_control_node_B.TmpSignalConversionAtSFun_a[2];
          proc_control_node_B.b_q[3] =
            -proc_control_node_B.TmpSignalConversionAtSFun_a[3];
          proc_control_node_B.dv11[0] = proc_control_node_B.fcn5_e;
          proc_control_node_B.dv11[1] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 7];
          proc_control_node_B.dv11[2] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 9];
          proc_control_node_B.dv11[3] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 11];
          proc_control_node_quatmultiply(proc_control_node_B.dv11,
            proc_control_node_B.b_q, proc_control_node_B.rq);

          // rq= quatmultiply(lq,quatconj(q));
          //  rq= quatmultiply(quatinv(lq),quatconj(q));
        } else {
          proc_control_node_B.dv11[0] = proc_control_node_B.fcn5_e;
          proc_control_node_B.dv11[1] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 7];
          proc_control_node_B.dv11[2] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 9];
          proc_control_node_B.dv11[3] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 11];
          proc_control_node_quatmultiply(proc_control_node_B.dv11,
            proc_control_node_B.TmpSignalConversionAtSFun_a,
            proc_control_node_B.rq);

          // rq = quatmultiply(lq,quatinv(quatinv(q)));
          //  rq = quatmultiply(quatinv(lq),q);
        }

        //  transformer le point en fonction du frame
        proc_control_node_B.rtb_Sum_tmp = rt_roundd_snf
          (proc_control_node_B.DataTypeConversion1[0]);
        if (proc_control_node_B.rtb_Sum_tmp < 256.0) {
          if (proc_control_node_B.rtb_Sum_tmp >= 0.0) {
            proc_control_node_B.u_m = static_cast<uint8_T>
              (proc_control_node_B.rtb_Sum_tmp);
          } else {
            proc_control_node_B.u_m = 0U;
          }
        } else {
          proc_control_node_B.u_m = MAX_uint8_T;
        }

        switch (proc_control_node_B.u_m) {
         case 0U:
          //  position et angle absolue
          proc_control_node_B.twpt[0] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[0];
          proc_control_node_B.twpt[1] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[1];
          proc_control_node_B.twpt[2] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[2];
          proc_control_node_B.twpt[3] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[0];
          proc_control_node_B.twpt[4] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[1];
          proc_control_node_B.twpt[5] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[2];
          proc_control_node_B.twpt[6] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[3];
          break;

         case 1U:
          //  position et angle relatif
          proc_control_node_B.fcn2 = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 11];
          proc_control_node_B.fcn5_e = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 7];
          proc_control_node_B.Product1_fh = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 9];
          proc_control_node_B.twpt[0] = ((proc_control_node_B.Product1_fh *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2] -
            proc_control_node_B.fcn2 *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.fcn5_e *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) - 1];
          proc_control_node_B.twpt[1] = ((proc_control_node_B.fcn2 *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0] -
            proc_control_node_B.fcn5_e *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.Product1_fh *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) + 1];
          proc_control_node_B.twpt[2] = ((proc_control_node_B.fcn5_e *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1] -
            proc_control_node_B.Product1_fh *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.fcn2 *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) + 3];
          proc_control_node_B.twpt[3] = proc_control_node_B.rq[0];
          proc_control_node_B.twpt[4] = proc_control_node_B.rq[1];
          proc_control_node_B.twpt[5] = proc_control_node_B.rq[2];
          proc_control_node_B.twpt[6] = proc_control_node_B.rq[3];
          break;

         case 2U:
          //  position relatif et angle absolue
          proc_control_node_B.fcn5_e = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 11];
          proc_control_node_B.Product1_fh = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 7];
          proc_control_node_B.Product2_ei = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 9];
          proc_control_node_B.twpt[0] = ((proc_control_node_B.Product2_ei *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2] -
            proc_control_node_B.fcn5_e *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.Product1_fh *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) - 1];
          proc_control_node_B.twpt[1] = ((proc_control_node_B.fcn5_e *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0] -
            proc_control_node_B.Product1_fh *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.Product2_ei *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) + 1];
          proc_control_node_B.twpt[2] = ((proc_control_node_B.Product1_fh *
            proc_control_node_B.TmpSignalConversionAtMATLAB[1] -
            proc_control_node_B.Product2_ei *
            proc_control_node_B.TmpSignalConversionAtMATLAB[0]) *
            proc_control_node_B.Product3_gb + (proc_control_node_B.fcn5_e *
            proc_control_node_B.Merge_a + proc_control_node_B.fcn4_g *
            proc_control_node_B.TmpSignalConversionAtMATLAB[2])) +
            proc_control_node_DW.obj_a.poseList[static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) + 3];
          proc_control_node_B.twpt[3] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[0];
          proc_control_node_B.twpt[4] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[1];
          proc_control_node_B.twpt[5] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[2];
          proc_control_node_B.twpt[6] =
            proc_control_node_B.TmpSignalConversionAtSFun_a[3];
          break;

         case 3U:
          //  position absolue et angle relatif
          proc_control_node_B.twpt[0] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[0];
          proc_control_node_B.twpt[1] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[1];
          proc_control_node_B.twpt[2] =
            proc_control_node_B.TmpSignalConversionAtMATLAB[2];
          proc_control_node_B.twpt[3] = proc_control_node_B.rq[0];
          proc_control_node_B.twpt[4] = proc_control_node_B.rq[1];
          proc_control_node_B.twpt[5] = proc_control_node_B.rq[2];
          proc_control_node_B.twpt[6] = proc_control_node_B.rq[3];
          break;

         default:
          //  retourne le point précédent
          proc_control_node_B.twpt[0] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) - 1];
          proc_control_node_B.twpt[1] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 1];
          proc_control_node_B.twpt[2] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 3];
          proc_control_node_B.twpt[3] = proc_control_node_B.fcn5_e;
          proc_control_node_B.twpt[4] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 7];
          proc_control_node_B.twpt[5] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 9];
          proc_control_node_B.twpt[6] = proc_control_node_DW.obj_a.poseList[
            static_cast<int32_T>(proc_control_node_DW.obj_a.i - 1.0) + 11];
          break;
        }

        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
             proc_control_node_B.ibmat++) {
          proc_control_node_DW.obj_a.poseList[(static_cast<int32_T>
            (proc_control_node_DW.obj_a.i) + (proc_control_node_B.ibmat << 1)) -
            1] = proc_control_node_B.twpt[proc_control_node_B.ibmat];
        }

        proc_control_node_DW.obj_a.i++;
      }

      // End of Outputs for SubSystem: '<S192>/Subscribe'
      if (proc_control_node_DW.Delay1_DSTATE_c) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.i = proc_control_node_B.ibmat << 1;
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.i] =
            proc_control_node_DW.obj_a.poseList[(static_cast<int32_T>
            (proc_control_node_DW.obj_a.i - 1.0) + proc_control_node_B.i) - 1];
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.i + 1] = 999.0;
        }

        proc_control_node_DW.obj_a.i = 2.0;
      }

      if (proc_control_node_B.OR1) {
        proc_control_node_B.ibmat = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
             proc_control_node_B.i++) {
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.ibmat + 1] =
            999.0;
          proc_control_node_B.ibmat += 2;
        }

        proc_control_node_DW.obj_a.poseList[14] = 0.0;
        proc_control_node_B.ibmat = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 7;
             proc_control_node_B.i++) {
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.ibmat] =
            proc_control_node_B.Transpose[proc_control_node_B.i];
          proc_control_node_DW.obj_a.poseList[proc_control_node_B.ibmat + 1] =
            proc_control_node_B.Transpose[proc_control_node_B.i];
          proc_control_node_B.ibmat += 2;
        }

        proc_control_node_DW.obj_a.poseList[15] = 1.0;
        proc_control_node_DW.obj_a.i = 2.0;
      }

      // Outputs for Enabled SubSystem: '<S192>/Pre-traitement' incorporates:
      //   EnablePort: '<S205>/Enable'

      // Outputs for Atomic SubSystem: '<S192>/Subscribe'
      if (proc_control_node_B.y_ft || proc_control_node_B.OR1) {
        // Math: '<S205>/Transpose' incorporates:
        //   MATLABSystem: '<S192>/MATLAB System1'
        //   Selector: '<S205>/Selector'
        //   Selector: '<S205>/Selector1'

        proc_control_node_B.ibmat = 0;
        proc_control_node_B.i = 0;
        proc_control_node_B.ixlast = 0;
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             2; proc_control_node_B.dCoefs_tmp++) {
          proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
          for (proc_control_node_B.L_tmp_tmp = 0; proc_control_node_B.L_tmp_tmp <
               8; proc_control_node_B.L_tmp_tmp++) {
            proc_control_node_B.Transpose_i[proc_control_node_B.L_tmp_tmp +
              proc_control_node_B.i] =
              proc_control_node_DW.obj_a.poseList[proc_control_node_B.LastPcov_PreviousInput_tmp
              + proc_control_node_B.dCoefs_tmp];
            proc_control_node_B.LastPcov_PreviousInput_tmp += 2;
          }

          proc_control_node_B.Selector1[proc_control_node_B.ibmat] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 3];
          proc_control_node_B.Selector1[proc_control_node_B.ibmat + 1] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 4];
          proc_control_node_B.Selector1[proc_control_node_B.ibmat + 2] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 5];
          proc_control_node_B.Selector1[proc_control_node_B.ibmat + 3] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 6];
          proc_control_node_B.Selector[proc_control_node_B.ixlast] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i];
          proc_control_node_B.Selector[proc_control_node_B.ixlast + 1] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 1];
          proc_control_node_B.Selector[proc_control_node_B.ixlast + 2] =
            proc_control_node_B.Transpose_i[proc_control_node_B.i + 2];
          proc_control_node_B.ibmat += 4;
          proc_control_node_B.i += 8;
          proc_control_node_B.ixlast += 3;
        }

        // Selector: '<S205>/Selector2' incorporates:
        //   Math: '<S205>/Transpose'

        proc_control_node_B.MatrixConcatenate[1] =
          proc_control_node_B.Transpose_i[15];
        proc_control_node_B.MatrixConcatenate[0] =
          proc_control_node_P.Constant1_Value_o;
        srUpdateBC(proc_control_node_DW.Pretraitement_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S192>/Pre-traitement'

      // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
      //   ResetPort: '<S209>/Reset'

      if (proc_control_node_B.y_ft &&
          (proc_control_node_PrevZCX.Trajectorygenerator_Reset_ZCE != 1)) {
        // InitializeConditions for DiscreteIntegrator: '<S209>/Discrete-Time Integrator' 
        proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b =
          proc_control_node_P.DiscreteTimeIntegrator_IC;
      }

      proc_control_node_PrevZCX.Trajectorygenerator_Reset_ZCE =
        proc_control_node_B.y_ft;

      // End of Outputs for SubSystem: '<S192>/Subscribe'

      // DiscreteIntegrator: '<S209>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S205>/Constant1'
      //   Constant: '<S209>/Constant'
      //   Logic: '<S192>/OR'
      //   MATLABSystem: '<S206>/SourceBlock'

      proc_control_node_B.fcn4_g =
        proc_control_node_P.DiscreteTimeIntegrator_gainval *
        proc_control_node_P.Constant_Value_ep;

      // DiscreteIntegrator: '<S209>/Discrete-Time Integrator'
      proc_control_node_B.Merge_a = proc_control_node_B.fcn4_g +
        proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b;

      // MATLABSystem: '<S209>/Rotation Trajectory' incorporates:
      //   Concatenate: '<S205>/Matrix Concatenate'
      //   Selector: '<S205>/Selector1'
      //   Selector: '<S209>/Selector1'
      //   Selector: '<S209>/Selector2'

      proc_contro_SystemCore_step_b4n(&proc_control_node_DW.obj_j,
        proc_control_node_B.Merge_a, &proc_control_node_B.Selector1[0],
        &proc_control_node_B.Selector1[4], proc_control_node_B.MatrixConcatenate,
        proc_control_node_B.RotationTrajectory_o1,
        proc_control_node_B.RotationTrajectory_o2, proc_control_node_B.s);

      // MATLABSystem: '<S209>/Polynomial Trajectory1' incorporates:
      //   Concatenate: '<S205>/Matrix Concatenate'
      //   Selector: '<S205>/Selector'
      //   TransferFcn: '<S20>/Transfer Fcn'
      //   TransferFcn: '<S21>/Transfer Fcn'
      //   TransferFcn: '<S22>/Transfer Fcn'
      //   TransferFcn: '<S23>/Transfer Fcn'
      //   TransferFcn: '<S24>/Transfer Fcn'
      //   TransferFcn: '<S25>/Transfer Fcn'
      //   TransferFcn: '<S26>/Transfer Fcn'
      //   TransferFcn: '<S27>/Transfer Fcn'

      proc_control_node_B.SourceBlock_o1_d = false;
      proc_control_node_B.OR1 = true;
      proc_control_node_B.ibmat = 0;
      exitg1 = false;
      while ((!exitg1) && (proc_control_node_B.ibmat < 6)) {
        if (!(proc_control_node_DW.obj_jo.VelocityBoundaryCondition[proc_control_node_B.ibmat]
              ==
              proc_control_node_P.PolynomialTrajectory1_VelocityB[proc_control_node_B.ibmat]))
        {
          proc_control_node_B.OR1 = false;
          exitg1 = true;
        } else {
          proc_control_node_B.ibmat++;
        }
      }

      if (proc_control_node_B.OR1) {
        proc_control_node_B.SourceBlock_o1_d = true;
      }

      if (!proc_control_node_B.SourceBlock_o1_d) {
        if (proc_control_node_DW.obj_jo.isInitialized == 1) {
          proc_control_node_DW.obj_jo.TunablePropsChanged = true;
        }

        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_DW.obj_jo.VelocityBoundaryCondition[proc_control_node_B.ibmat]
            =
            proc_control_node_P.PolynomialTrajectory1_VelocityB[proc_control_node_B.ibmat];
        }
      }

      if (proc_control_node_DW.obj_jo.TunablePropsChanged) {
        proc_control_node_DW.obj_jo.TunablePropsChanged = false;
      }

      proc_control_node_cubicpolytraj(proc_control_node_B.Selector,
        proc_control_node_B.MatrixConcatenate,
        proc_control_node_B.MatrixConcatenate,
        proc_control_node_DW.obj_jo.VelocityBoundaryCondition,
        proc_control_node_B.Gain3, proc_control_node_B.Gain_k,
        proc_control_node_B.a__4,
        proc_control_node_B.TmpSignalConversionAtSFun_a,
        proc_control_node_B.pp_coefs);
      proc_control_node_B.rq[0] =
        proc_control_node_B.TmpSignalConversionAtSFun_a[0];
      proc_control_node_B.rq[1] =
        proc_control_node_B.TmpSignalConversionAtSFun_a[1];
      proc_control_node_B.rq[3] =
        proc_control_node_B.TmpSignalConversionAtSFun_a[3];
      proc_control_node_B.fcn2 = 0.01;
      if (proc_control_node_B.Merge_a >
          proc_control_node_B.TmpSignalConversionAtSFun_a[2]) {
        proc_control_node_B.ibmat = 1;
        proc_control_node_B.i = 1;
      } else {
        proc_control_node_B.ibmat = 0;
        proc_control_node_B.i = 0;
      }

      if ((proc_control_node_B.ibmat != 0) && (proc_control_node_B.i != 0)) {
        proc_control_node_B.Product3_gb = (proc_control_node_B.Merge_a -
          proc_control_node_B.TmpSignalConversionAtSFun_a[2]) / 2.0;
        if (proc_control_node_B.Product3_gb < 0.01) {
          proc_control_node_B.fcn2 = proc_control_node_B.Product3_gb;
        }
      }

      proc_control_node_B.rq[2] =
        proc_control_node_B.TmpSignalConversionAtSFun_a[2] +
        proc_control_node_B.fcn2;
      memset(&proc_control_node_B.dCoefs[0], 0, 36U * sizeof(real_T));
      proc_control_node_B.ixlast = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 3;
           proc_control_node_B.i++) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 9;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.dCoefs_tmp = proc_control_node_B.ibmat +
            proc_control_node_B.ixlast;
          proc_control_node_B.dCoefs[proc_control_node_B.dCoefs_tmp + 9] =
            proc_control_node_B.pp_coefs[proc_control_node_B.dCoefs_tmp] *
            static_cast<real_T>(3 - proc_control_node_B.i);
        }

        proc_control_node_B.ixlast += 9;
      }

      // Update for DiscreteIntegrator: '<S209>/Discrete-Time Integrator'
      proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b =
        proc_control_node_B.fcn4_g + proc_control_node_B.Merge_a;

      // End of Outputs for SubSystem: '<S192>/Trajectory generator'

      // MATLABSystem: '<S192>/MATLAB System' incorporates:
      //   Constant: '<S192>/Constant1'
      //   MATLAB Function: '<S192>/MATLAB Function2'
      //   MATLABSystem: '<S209>/Polynomial Trajectory1'
      //   Math: '<S211>/Transpose'
      //   SignalConversion generated from: '<S192>/Transpose'

      if (proc_control_node_DW.obj.linearConvergence !=
          proc_control_node_P.MATLABSystem_linearConvergence) {
        proc_control_node_DW.obj.linearConvergence =
          proc_control_node_P.MATLABSystem_linearConvergence;
      }

      if (proc_control_node_DW.obj.quaternionConvergence !=
          proc_control_node_P.MATLABSystem_quaternionConverge) {
        proc_control_node_DW.obj.quaternionConvergence =
          proc_control_node_P.MATLABSystem_quaternionConverge;
      }

      if (proc_control_node_DW.obj.TargetThreshold !=
          proc_control_node_P.MATLABSystem_TargetThreshold) {
        proc_control_node_DW.obj.TargetThreshold =
          proc_control_node_P.MATLABSystem_TargetThreshold;
      }

      //  Main execute a chaque iteration.
      //  Implement algorithm. Calculate y as a function of input u and
      //
      if (proc_control_node_DW.obj.init == 0.0) {
        //  Conditions Initiales
        proc_control_node_B.ibmat = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 7;
             proc_control_node_B.i++) {
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat] =
            proc_control_node_B.Transpose[proc_control_node_B.i];
          proc_control_node_B.ibmat += 6001;
        }

        proc_control_node_DW.obj.poseBuffer[42007] = 0.0;
        proc_control_node_DW.obj.poseBuffer[48008] = 0.0;
        proc_control_node_DW.obj.poseBuffer[54009] = 0.0;
        proc_control_node_DW.obj.poseBuffer[60010] = 0.0;
        proc_control_node_DW.obj.poseBuffer[66011] = 0.0;
        proc_control_node_DW.obj.poseBuffer[72012] = 0.0;

        // InitCond;
        proc_control_node_DW.obj.bufferCount = 1.0;
        proc_control_node_DW.obj.init = 1.0;
      }

      // this.BufferReset(reset,mp);
      //  Fonction qui traites les nouveau poses.
      //  Insertion des nouveaux points.
      if (proc_control_node_P.Constant1_Value_i[0] == 1.0) {
        // if new == this.generationNumber %new>
        if (proc_control_node_P.Constant1_Value_i[1] +
            proc_control_node_DW.obj.bufferCount < 6001.0) {
          // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
          //   ResetPort: '<S209>/Reset'

          // MATLABSystem: '<S209>/Polynomial Trajectory1'
          proc_control_node_ppval_b
            (proc_control_node_B.TmpSignalConversionAtSFun_a,
             proc_control_node_B.pp_coefs, proc_control_node_B.Merge_a,
             proc_control_node_B.Gain_d);
          proc_control_node_ppval_b(proc_control_node_B.rq,
            proc_control_node_B.dCoefs, proc_control_node_B.Merge_a,
            proc_control_node_B.b_varargout_2_p);

          // End of Outputs for SubSystem: '<S192>/Trajectory generator'
          proc_control_node_B.ibmat = static_cast<int32_T>
            (proc_control_node_P.Constant1_Value_i[1] +
             proc_control_node_DW.obj.bufferCount) - 1;

          // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
          //   ResetPort: '<S209>/Reset'

          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat] =
            proc_control_node_B.Gain_d[0];
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 6001] =
            proc_control_node_B.Gain_d[1];
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 12002]
            = proc_control_node_B.Gain_d[2];

          // End of Outputs for SubSystem: '<S192>/Trajectory generator'
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 18003]
            = proc_control_node_B.RotationTrajectory_o1[0];
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 24004]
            = proc_control_node_B.RotationTrajectory_o1[1];
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 30005]
            = proc_control_node_B.RotationTrajectory_o1[2];
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 36006]
            = proc_control_node_B.RotationTrajectory_o1[3];

          // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
          //   ResetPort: '<S209>/Reset'

          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 42007]
            = proc_control_node_B.b_varargout_2_p[0];

          // End of Outputs for SubSystem: '<S192>/Trajectory generator'
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 60010]
            = proc_control_node_B.RotationTrajectory_o2[0];

          // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
          //   ResetPort: '<S209>/Reset'

          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 48008]
            = proc_control_node_B.b_varargout_2_p[1];

          // End of Outputs for SubSystem: '<S192>/Trajectory generator'
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 66011]
            = proc_control_node_B.RotationTrajectory_o2[1];

          // Outputs for Resettable SubSystem: '<S192>/Trajectory generator' incorporates:
          //   ResetPort: '<S209>/Reset'

          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 54009]
            = proc_control_node_B.b_varargout_2_p[2];

          // End of Outputs for SubSystem: '<S192>/Trajectory generator'
          proc_control_node_DW.obj.poseBuffer[proc_control_node_B.ibmat + 72012]
            = proc_control_node_B.RotationTrajectory_o2[2];

          // this.poseBuffer(this.bufferCount:count + this.bufferCount,:) = pose(1:count+1,:) 
          proc_control_node_DW.obj.bufferCount +=
            proc_control_node_P.Constant1_Value_i[1];
          proc_control_node_DW.obj.generationNumber++;
        } else {
          printf("%s\n", "Problem");
          fflush(stdout);
        }
      }

      TrajectoryManager_SendCurrentPo(&proc_control_node_DW.obj,
        proc_control_node_B.y_n);

      // Merge: '<S11>/Merge1' incorporates:
      //   MATLABSystem: '<S192>/MATLAB System'

      //  Fonction qui verifie le target reached
      proc_control_node_B.Merge1 = false;

      // MATLABSystem: '<S192>/MATLAB System' incorporates:
      //   MATLAB Function: '<S192>/MATLAB Function'
      //   SignalConversion generated from: '<S203>/ SFunction '

      //  vérifier le traget reached si la trajectoire est terminé
      if (proc_control_node_DW.obj.done) {
        //  calcule de l'erreur de langle en 3D avec le quaternion
        proc_control_node_B.qRel[0] = ((proc_control_node_DW.obj.poseBuffer
          [18003] * proc_control_node_B.Divide -
          -proc_control_node_DW.obj.poseBuffer[24004] *
          proc_control_node_B.Divide1) - -proc_control_node_DW.obj.poseBuffer
          [30005] * proc_control_node_B.Divide2) -
          -proc_control_node_DW.obj.poseBuffer[36006] *
          proc_control_node_B.Divide3;
        proc_control_node_B.qRel[1] = (proc_control_node_DW.obj.poseBuffer[18003]
          * proc_control_node_B.Divide1 + -proc_control_node_DW.obj.poseBuffer
          [24004] * proc_control_node_B.Divide) +
          (-proc_control_node_DW.obj.poseBuffer[30005] *
           proc_control_node_B.Divide3 - -proc_control_node_DW.obj.poseBuffer
           [36006] * proc_control_node_B.Divide2);
        proc_control_node_B.qRel[2] = (proc_control_node_DW.obj.poseBuffer[18003]
          * proc_control_node_B.Divide2 + -proc_control_node_DW.obj.poseBuffer
          [30005] * proc_control_node_B.Divide) +
          (-proc_control_node_DW.obj.poseBuffer[36006] *
           proc_control_node_B.Divide1 - -proc_control_node_DW.obj.poseBuffer
           [24004] * proc_control_node_B.Divide3);
        proc_control_node_B.qRel[3] = (proc_control_node_DW.obj.poseBuffer[18003]
          * proc_control_node_B.Divide3 + proc_control_node_B.Divide *
          -proc_control_node_DW.obj.poseBuffer[36006]) +
          (-proc_control_node_DW.obj.poseBuffer[24004] *
           proc_control_node_B.Divide2 - -proc_control_node_DW.obj.poseBuffer
           [30005] * proc_control_node_B.Divide1);

        //  vérifier si le sub est dans la zone de convergence (sphérique / conique) 
        proc_control_node_B.s[0] = proc_control_node_DW.obj.poseBuffer[0] -
          proc_control_node_B.WorldPosition[0];
        proc_control_node_B.s[1] = proc_control_node_DW.obj.poseBuffer[6001] -
          proc_control_node_B.WorldPosition[1];
        proc_control_node_B.s[2] = proc_control_node_DW.obj.poseBuffer[12002] -
          proc_control_node_B.WorldPosition[2];
        if ((proc_control_node_norm_b(proc_control_node_B.s) <
             proc_control_node_DW.obj.linearConvergence) && (2.0 * rt_atan2d_snf
             (proc_control_node_norm_b(&proc_control_node_B.qRel[1]),
              proc_control_node_B.qRel[0]) <
             proc_control_node_DW.obj.quaternionConvergence)) {
          proc_control_node_DW.obj.targetReachedCount++;

          // Merge: '<S11>/Merge1'
          proc_control_node_B.Merge1 =
            (proc_control_node_DW.obj.targetReachedCount * 0.1 >=
             proc_control_node_DW.obj.TargetThreshold);
        }
      } else {
        proc_control_node_DW.obj.targetReachedCount = 0.0;
      }

      // Merge: '<S11>/Merge' incorporates:
      //   MATLABSystem: '<S192>/MATLAB System'
      //   SignalConversion generated from: '<S192>/MATLAB System'

      memcpy(&proc_control_node_B.Quaternion[0], &proc_control_node_B.y_n[0],
             130U * sizeof(real_T));

      // Update for Delay: '<S208>/Delay' incorporates:
      //   Constant: '<S208>/Constant6'

      proc_control_node_DW.Delay_DSTATE_n = proc_control_node_P.Constant6_Value;

      // Outputs for Atomic SubSystem: '<S192>/Subscribe'
      // Update for Delay: '<S192>/Delay1' incorporates:
      //   MATLABSystem: '<S206>/SourceBlock'

      proc_control_node_DW.Delay1_DSTATE_c = proc_control_node_B.y_ft;

      // End of Outputs for SubSystem: '<S192>/Subscribe'
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.singleWptsTrajectory_SubsysRanB);
      }

      // End of Outputs for SubSystem: '<S11>/singleWpts Trajectory'
      break;

     case 3:
      // Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
      //   ActionPort: '<S188>/Action Port'

      // Merge: '<S11>/Merge' incorporates:
      //   Constant: '<S188>/Constant'
      //   MATLAB Function: '<S188>/MATLAB Function1'

      proc_control_no_MATLABFunction1(proc_control_node_P.Constant_Value_m5h,
        proc_control_node_B.Quaternion,
        &proc_control_node_B.sf_MATLABFunction1_p);
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S11>/If Action Subsystem'
      break;
    }

    // End of SwitchCase: '<S11>/Switch Case'

    // SwitchCase: '<S9>/Switch Case' incorporates:
    //   MATLAB Function: '<S144>/FixedHorizonOptimizer'
    //   Memory: '<S116>/Memory'

    proc_control_node_B.rtPrevAction =
      proc_control_node_DW.SwitchCase_ActiveSubsystem_l;
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      switch (proc_control_node_B.Data) {
       case 10:
       case 11:
       case 19:
        proc_control_node_B.rtAction = 0;
        break;

       case 20:
       case 21:
        proc_control_node_B.rtAction = 1;
        break;

       default:
        proc_control_node_B.rtAction = 2;
        break;
      }

      proc_control_node_DW.SwitchCase_ActiveSubsystem_l =
        proc_control_node_B.rtAction;
    } else {
      proc_control_node_B.rtAction =
        proc_control_node_DW.SwitchCase_ActiveSubsystem_l;
    }

    switch (proc_control_node_B.rtAction) {
     case 0:
      if (proc_control_node_B.rtAction != proc_control_node_B.rtPrevAction) {
        // InitializeConditions for IfAction SubSystem: '<S9>/Quaternion Non linear MPC' incorporates:
        //   ActionPort: '<S110>/Action Port'

        // InitializeConditions for SwitchCase: '<S9>/Switch Case' incorporates:
        //   Delay: '<S110>/Delay1'
        //   DiscretePulseGenerator: '<S110>/Pulse Generator'
        //   Memory: '<S116>/LastPcov'
        //   Memory: '<S116>/Memory'
        //   Memory: '<S116>/last_x'
        //   UnitDelay: '<S116>/last_mv'

        memcpy(&proc_control_node_DW.LastPcov_PreviousInput[0],
               &proc_control_node_P.LastPcov_InitialCondition[0], 400U * sizeof
               (real_T));
        memcpy(&proc_control_node_DW.Memory_PreviousInput_o[0],
               &proc_control_node_P.Memory_InitialCondition[0], sizeof(boolean_T)
               << 6U);
        memcpy(&proc_control_node_DW.last_mv_DSTATE[0],
               &proc_control_node_P.last_mv_InitialCondition[0], sizeof(real_T) <<
               3U);
        memcpy(&proc_control_node_DW.last_x_PreviousInput[0],
               &proc_control_node_P.last_x_InitialCondition[0], 20U * sizeof
               (real_T));
        memcpy(&proc_control_node_DW.Delay1_DSTATE[0],
               &proc_control_node_P.Delay1_InitialCondition[0], sizeof(real_T) <<
               3U);
        proc_control_node_DW.clockTickCounter = 0;

        // End of InitializeConditions for SubSystem: '<S9>/Quaternion Non linear MPC' 
      }

      // Outputs for IfAction SubSystem: '<S9>/Quaternion Non linear MPC' incorporates:
      //   ActionPort: '<S110>/Action Port'

      // Sqrt: '<S153>/sqrt' incorporates:
      //   Product: '<S154>/Product'
      //   Product: '<S154>/Product1'
      //   Product: '<S154>/Product2'
      //   Product: '<S154>/Product3'
      //   Sum: '<S154>/Sum'

      proc_control_node_B.Merge_a = sqrt(((proc_control_node_B.Divide *
        proc_control_node_B.Divide + proc_control_node_B.Divide1 *
        proc_control_node_B.Divide1) + proc_control_node_B.Divide2 *
        proc_control_node_B.Divide2) + proc_control_node_B.Divide3 *
        proc_control_node_B.Divide3);

      // Product: '<S148>/Product'
      proc_control_node_B.fcn2 = proc_control_node_B.Divide /
        proc_control_node_B.Merge_a;

      // Product: '<S148>/Product1'
      proc_control_node_B.fcn4_g = proc_control_node_B.Divide1 /
        proc_control_node_B.Merge_a;

      // Product: '<S148>/Product2'
      proc_control_node_B.Product3_gb = proc_control_node_B.Divide2 /
        proc_control_node_B.Merge_a;

      // Product: '<S148>/Product3'
      proc_control_node_B.Merge_a = proc_control_node_B.Divide3 /
        proc_control_node_B.Merge_a;

      // Trigonometry: '<S147>/Trigonometric Function1' incorporates:
      //   Fcn: '<S146>/fcn1'
      //   Fcn: '<S146>/fcn2'

      proc_control_node_B.s[0] = rt_atan2d_snf((proc_control_node_B.fcn4_g *
        proc_control_node_B.Product3_gb + proc_control_node_B.fcn2 *
        proc_control_node_B.Merge_a) * 2.0, ((proc_control_node_B.fcn2 *
        proc_control_node_B.fcn2 + proc_control_node_B.fcn4_g *
        proc_control_node_B.fcn4_g) - proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb) - proc_control_node_B.Merge_a *
        proc_control_node_B.Merge_a);

      // Fcn: '<S146>/fcn3'
      proc_control_node_B.fcn5_e = (proc_control_node_B.fcn4_g *
        proc_control_node_B.Merge_a - proc_control_node_B.fcn2 *
        proc_control_node_B.Product3_gb) * -2.0;

      // If: '<S149>/If' incorporates:
      //   Constant: '<S150>/Constant'
      //   Constant: '<S151>/Constant'

      if (proc_control_node_B.fcn5_e > 1.0) {
        // Outputs for IfAction SubSystem: '<S149>/If Action Subsystem' incorporates:
        //   ActionPort: '<S150>/Action Port'

        proc_control_node_B.fcn5_e = proc_control_node_P.Constant_Value_kr;

        // End of Outputs for SubSystem: '<S149>/If Action Subsystem'

        // Update for IfAction SubSystem: '<S149>/If Action Subsystem' incorporates:
        //   ActionPort: '<S150>/Action Port'

        // Update for If: '<S149>/If' incorporates:
        //   Constant: '<S150>/Constant'

        srUpdateBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_c);

        // End of Update for SubSystem: '<S149>/If Action Subsystem'
      } else if (proc_control_node_B.fcn5_e < -1.0) {
        // Outputs for IfAction SubSystem: '<S149>/If Action Subsystem1' incorporates:
        //   ActionPort: '<S151>/Action Port'

        proc_control_node_B.fcn5_e = proc_control_node_P.Constant_Value_b;

        // End of Outputs for SubSystem: '<S149>/If Action Subsystem1'

        // Update for IfAction SubSystem: '<S149>/If Action Subsystem1' incorporates:
        //   ActionPort: '<S151>/Action Port'

        // Update for If: '<S149>/If' incorporates:
        //   Constant: '<S151>/Constant'

        srUpdateBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_h);

        // End of Update for SubSystem: '<S149>/If Action Subsystem1'
      } else {
        // Update for IfAction SubSystem: '<S149>/If Action Subsystem2' incorporates:
        //   ActionPort: '<S152>/Action Port'

        // Update for If: '<S149>/If'
        srUpdateBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_o);

        // End of Update for SubSystem: '<S149>/If Action Subsystem2'
      }

      // End of If: '<S149>/If'

      // Trigonometry: '<S147>/trigFcn'
      if (proc_control_node_B.fcn5_e > 1.0) {
        proc_control_node_B.fcn5_e = 1.0;
      } else if (proc_control_node_B.fcn5_e < -1.0) {
        proc_control_node_B.fcn5_e = -1.0;
      }

      proc_control_node_B.s[1] = asin(proc_control_node_B.fcn5_e);

      // End of Trigonometry: '<S147>/trigFcn'

      // Trigonometry: '<S147>/Trigonometric Function3' incorporates:
      //   Fcn: '<S146>/fcn4'
      //   Fcn: '<S146>/fcn5'

      proc_control_node_B.s[2] = rt_atan2d_snf((proc_control_node_B.Product3_gb *
        proc_control_node_B.Merge_a + proc_control_node_B.fcn2 *
        proc_control_node_B.fcn4_g) * 2.0, ((proc_control_node_B.fcn2 *
        proc_control_node_B.fcn2 - proc_control_node_B.fcn4_g *
        proc_control_node_B.fcn4_g) - proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb) + proc_control_node_B.Merge_a *
        proc_control_node_B.Merge_a);

      // SignalConversion generated from: '<S115>/ SFunction ' incorporates:
      //   MATLAB Function: '<S110>/MATLAB Function2'

      proc_control_node_B.TmpSignalConversionAtSFun_k[0] =
        proc_control_node_B.WorldPosition[0];
      proc_control_node_B.TmpSignalConversionAtSFun_k[3] =
        proc_control_node_B.s[0];
      proc_control_node_B.TmpSignalConversionAtSFun_k[1] =
        proc_control_node_B.WorldPosition[1];
      proc_control_node_B.TmpSignalConversionAtSFun_k[4] =
        proc_control_node_B.s[1];
      proc_control_node_B.TmpSignalConversionAtSFun_k[2] =
        proc_control_node_B.WorldPosition[2];
      proc_control_node_B.TmpSignalConversionAtSFun_k[5] =
        proc_control_node_B.s[2];
      proc_control_node_B.TmpSignalConversionAtSFun_k[6] =
        proc_control_node_B.Sum_f;
      proc_control_node_B.TmpSignalConversionAtSFun_k[7] =
        proc_control_node_B.Sum_c;
      proc_control_node_B.TmpSignalConversionAtSFun_k[8] =
        proc_control_node_B.Sum;
      proc_control_node_B.TmpSignalConversionAtSFun_k[9] = proc_control_node_B.X;
      proc_control_node_B.TmpSignalConversionAtSFun_k[10] =
        proc_control_node_B.Y;
      proc_control_node_B.TmpSignalConversionAtSFun_k[11] =
        proc_control_node_B.Z;

      // MATLAB Function: '<S110>/MATLAB Function2' incorporates:
      //   Constant: '<S110>/Constant3'

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 144;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.C[proc_control_node_B.ibmat] =
          tmp[proc_control_node_B.ibmat];
      }

      proc_contr_AUVEULJacobianMatrix
        (proc_control_node_B.TmpSignalConversionAtSFun_k,
         proc_control_node_B.Kinv_n);
      proc_control_node_B.ibmat = 0;
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
           proc_control_node_B.ixlast++) {
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             12; proc_control_node_B.dCoefs_tmp++) {
          proc_control_node_B.Kinv[proc_control_node_B.dCoefs_tmp +
            proc_control_node_B.ibmat] =
            proc_control_node_B.Kinv_n[proc_control_node_B.dCoefs_tmp +
            proc_control_node_B.i] * proc_control_node_P.MPC.Ts;
        }

        proc_control_node_B.ibmat += 20;
        proc_control_node_B.i += 12;
      }

      proc_control_node_B.ibmat = 0;
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 8;
           proc_control_node_B.ixlast++) {
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             12; proc_control_node_B.dCoefs_tmp++) {
          proc_control_node_B.Kinv[(proc_control_node_B.dCoefs_tmp +
            proc_control_node_B.ibmat) + 240] = b[proc_control_node_B.dCoefs_tmp
            + proc_control_node_B.i] * proc_control_node_P.MPC.Ts;
        }

        proc_control_node_B.ibmat += 20;
        proc_control_node_B.i += 12;
      }

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
           proc_control_node_B.i++) {
        memset(&proc_control_node_B.Kinv[proc_control_node_B.ibmat + 12], 0,
               sizeof(real_T) << 3U);
        proc_control_node_B.ibmat += 20;
      }

      proc_control_node_expm(proc_control_node_B.Kinv, proc_control_node_B.M);
      proc_control_node_B.ibmat = 0;
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
           proc_control_node_B.ixlast++) {
        memcpy(&proc_control_node_B.A[proc_control_node_B.ibmat],
               &proc_control_node_B.M[proc_control_node_B.i], 12U * sizeof
               (real_T));
        proc_control_node_B.ibmat += 12;
        proc_control_node_B.i += 20;
      }

      proc_control_node_B.ibmat = 0;
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 8;
           proc_control_node_B.ixlast++) {
        memcpy(&proc_control_node_B.B[proc_control_node_B.ibmat],
               &proc_control_node_B.M[proc_control_node_B.i + 240], 12U * sizeof
               (real_T));
        proc_control_node_B.ibmat += 12;
        proc_control_node_B.i += 20;
      }

      // MATLAB Function: '<S144>/FixedHorizonOptimizer'
      memset(&proc_control_node_B.Bu[0], 0, 1760U * sizeof(real_T));
      memset(&proc_control_node_B.Bv[0], 0, 220U * sizeof(real_T));
      memset(&proc_control_node_B.Dv[0], 0, 132U * sizeof(real_T));
      memset(&proc_control_node_B.Dvm[0], 0, 132U * sizeof(real_T));
      memset(&proc_control_node_B.Cm[0], 0, 2640U * sizeof(real_T));
      memcpy(&proc_control_node_B.M[0], &c[0], 400U * sizeof(real_T));
      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 240;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.b_C[proc_control_node_B.ibmat] =
          e[proc_control_node_B.ibmat];
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.u_scale[proc_control_node_B.ibmat] =
          static_cast<real_T>(proc_control_node_B.ibmat) + 1.0;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.dv7[proc_control_node_B.ibmat] = static_cast<real_T>
          (proc_control_node_B.ibmat) + 1.0;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_u_n[proc_control_node_B.ibmat] = 1.0;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.dv8[proc_control_node_B.ibmat] = 1.0;
      }

      memcpy(&proc_control_node_B.rtb_B_d[0], &proc_control_node_B.B[0], 96U *
             sizeof(real_T));
      memcpy(&proc_control_node_B.d[0], &d[0], 580U * sizeof(real_T));

      // MATLAB Function: '<S144>/FixedHorizonOptimizer'
      proc_control_no_mpc_plantupdate(proc_control_node_B.A,
        proc_control_node_B.rtb_B_d, proc_control_node_B.C,
        proc_control_node_B.M, proc_control_node_B.d, proc_control_node_B.b_C, f,
        proc_control_node_B.u_scale, proc_control_node_B.dv7,
        proc_control_node_B.rtb_u_n, proc_control_node_B.dv8,
        &proc_control_node_B.Bu[0], &proc_control_node_B.Bv[0],
        proc_control_node_B.L, &proc_control_node_B.Dv[0],
        &proc_control_node_B.Dvm[0], proc_control_node_B.Kinv,
        proc_control_node_B.Kinv_n, proc_control_node_B.Nk);
      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
           proc_control_node_B.i++) {
        memcpy(&proc_control_node_B.Cm[proc_control_node_B.ibmat],
               &proc_control_node_B.L[proc_control_node_B.ibmat], 12U * sizeof
               (real_T));
        proc_control_node_B.ibmat += 12;
      }

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 64;
           proc_control_node_B.i++) {
        proc_control_node_B.b_Mlim[proc_control_node_B.i] =
          g[proc_control_node_B.i];
      }

      memset(&proc_control_node_B.b_utarget[0], 0, 80U * sizeof(real_T));
      memcpy(&proc_control_node_B.b_xoff[0], &n[0], 20U * sizeof(real_T));

      // MATLAB Function: '<S110>/MATLAB Function2' incorporates:
      //   Delay: '<S110>/Delay1'
      //   MATLAB Function: '<S144>/FixedHorizonOptimizer'

      memset(&proc_control_node_B.y_innov[0], 0, 12U * sizeof(real_T));
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
           proc_control_node_B.ixlast++) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.y_innov[proc_control_node_B.ibmat] +=
            proc_control_node_B.C[proc_control_node_B.ibmat +
            proc_control_node_B.i] *
            proc_control_node_B.TmpSignalConversionAtSFun_k[proc_control_node_B.ixlast];
        }

        proc_control_node_B.dv7[proc_control_node_B.ixlast] = 0.0;
        proc_control_node_B.i += 12;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 12;
             proc_control_node_B.i++) {
          proc_control_node_B.dv7[proc_control_node_B.i] += 0.0 *
            proc_control_node_DW.Delay1_DSTATE[proc_control_node_B.ibmat];
        }
      }

      memset(&proc_control_node_B.rtb_A_b[0], 0, 12U * sizeof(real_T));
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
           proc_control_node_B.ixlast++) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.rtb_A_b[proc_control_node_B.ibmat] +=
            proc_control_node_B.A[proc_control_node_B.ibmat +
            proc_control_node_B.i] *
            proc_control_node_B.TmpSignalConversionAtSFun_k[proc_control_node_B.ixlast];
        }

        proc_control_node_B.rtb_B_da[proc_control_node_B.ixlast] = 0.0;
        proc_control_node_B.i += 12;
      }

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
           proc_control_node_B.i++) {
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_B_da[proc_control_node_B.ixlast] +=
            proc_control_node_B.B[proc_control_node_B.ixlast +
            proc_control_node_B.ibmat] *
            proc_control_node_DW.Delay1_DSTATE[proc_control_node_B.i];
        }

        proc_control_node_B.u_scale[proc_control_node_B.i] = 1.0;
        proc_control_node_B.rtb_u_n[proc_control_node_B.i] = 0.0;
        proc_control_node_B.dv10[proc_control_node_B.i] = static_cast<real_T>
          (proc_control_node_B.i) + 1.0;
        proc_control_node_B.ibmat += 12;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_C_e[proc_control_node_B.ibmat] =
          proc_control_node_B.y_innov[proc_control_node_B.ibmat] +
          proc_control_node_B.dv7[proc_control_node_B.ibmat];
        proc_control_node_B.dv8[proc_control_node_B.ibmat] = 1.0;
        proc_control_node_B.dv9[proc_control_node_B.ibmat] = static_cast<real_T>
          (proc_control_node_B.ibmat) + 1.0;
        proc_control_node_B.rtb_A_bj[proc_control_node_B.ibmat] =
          (proc_control_node_B.rtb_A_b[proc_control_node_B.ibmat] +
           proc_control_node_B.rtb_B_da[proc_control_node_B.ibmat]) -
          proc_control_node_B.TmpSignalConversionAtSFun_k[proc_control_node_B.ibmat];
      }

      // MATLAB Function: '<S144>/FixedHorizonOptimizer' incorporates:
      //   Constant: '<S110>/Constant4'
      //   Delay: '<S110>/Delay1'
      //   DiscretePulseGenerator: '<S110>/Pulse Generator'
      //   Lookup_n-D: '<S15>/ PWM to N'
      //   Lookup_n-D: '<S15>/N to RPM'
      //   Lookup_n-D: '<S9>/N to PWM'
      //   MATLAB Function: '<S110>/MATLAB Function2'
      //   Memory: '<S116>/LastPcov'
      //   Memory: '<S116>/last_x'
      //   TransferFcn: '<S20>/Transfer Fcn'
      //   TransferFcn: '<S21>/Transfer Fcn'
      //   TransferFcn: '<S22>/Transfer Fcn'
      //   TransferFcn: '<S23>/Transfer Fcn'
      //   TransferFcn: '<S24>/Transfer Fcn'
      //   TransferFcn: '<S25>/Transfer Fcn'
      //   TransferFcn: '<S26>/Transfer Fcn'
      //   TransferFcn: '<S27>/Transfer Fcn'
      //   Trigonometry: '<S33>/sincos'

      proc_cont_mpc_updateFromNominal(proc_control_node_B.b_Mlim, h,
        proc_control_node_DW.Delay1_DSTATE, proc_control_node_B.u_scale,
        proc_control_node_B.rtb_u_n, proc_control_node_B.dv10,
        proc_control_node_B.b_utarget, proc_control_node_B.rtb_C_e,
        proc_control_node_B.dv8, l, proc_control_node_B.dv9,
        proc_control_node_B.TmpSignalConversionAtSFun_k,
        proc_control_node_B.b_xoff, proc_control_node_B.rtb_A_bj,
        proc_control_node_B.Bv, proc_control_node_B.twpt,
        proc_control_node_B.y_innov, proc_control_node_B.rtb_A_b);
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 11;
           proc_control_node_B.i++) {
        proc_control_node_B.vseq[proc_control_node_B.i] = 1.0;
      }

      proc_control_node_B.ixlast = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 10;
           proc_control_node_B.i++) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
             proc_control_node_B.ibmat++) {
          // Outputs for Enabled SubSystem: '<Root>/Modèle Physique' incorporates:
          //   EnablePort: '<S1>/Enable'

          proc_control_node_B.rseq[proc_control_node_B.ibmat +
            proc_control_node_B.ixlast] =
            proc_control_node_P.Constant4_Value[proc_control_node_B.ibmat] -
            proc_control_node_B.y_innov[proc_control_node_B.ibmat];

          // End of Outputs for SubSystem: '<Root>/Modèle Physique'
        }

        proc_control_node_B.ixlast += 12;
      }

      memset(&proc_control_node_B.C[0], 0, 144U * sizeof(real_T));
      proc_control_node_B.ixlast = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 12;
           proc_control_node_B.i++) {
        proc_control_node_B.C[proc_control_node_B.ixlast] = 1.0;
        proc_control_node_B.ixlast += 13;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        memset(&proc_control_node_B.L[proc_control_node_B.ibmat * 12], 0, 12U *
               sizeof(real_T));
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.i = 0; proc_control_node_B.i < 12;
               proc_control_node_B.i++) {
            proc_control_node_B.dCoefs_tmp = 12 * proc_control_node_B.ibmat +
              proc_control_node_B.i;
            proc_control_node_B.L[proc_control_node_B.dCoefs_tmp] +=
              proc_control_node_B.Cm[12 * proc_control_node_B.ixlast +
              proc_control_node_B.i] *
              proc_control_node_DW.LastPcov_PreviousInput[20 *
              proc_control_node_B.ibmat + proc_control_node_B.ixlast];
          }
        }
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_Sum_tmp = 0.0;
          proc_control_node_B.dCoefs_tmp = 0;
          for (proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
               proc_control_node_B.LastPcov_PreviousInput_tmp < 20;
               proc_control_node_B.LastPcov_PreviousInput_tmp++) {
            proc_control_node_B.rtb_Sum_tmp +=
              proc_control_node_B.L[proc_control_node_B.dCoefs_tmp +
              proc_control_node_B.ibmat] *
              proc_control_node_B.Cm[proc_control_node_B.dCoefs_tmp +
              proc_control_node_B.ixlast];
            proc_control_node_B.dCoefs_tmp += 12;
          }

          proc_control_node_B.dCoefs_tmp = proc_control_node_B.i +
            proc_control_node_B.ibmat;
          proc_control_node_B.A[proc_control_node_B.dCoefs_tmp] =
            proc_control_node_B.Kinv_n[proc_control_node_B.dCoefs_tmp] +
            proc_control_node_B.rtb_Sum_tmp;
          proc_control_node_B.i += 12;
        }
      }

      proc_control_node_mrdiv_c(proc_control_node_B.C, proc_control_node_B.A,
        proc_control_node_B.Kinv_n);
      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        memset(&proc_control_node_B.L_tmp[proc_control_node_B.ibmat * 20], 0,
               20U * sizeof(real_T));
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
               proc_control_node_B.i++) {
            proc_control_node_B.L_tmp_tmp = 20 * proc_control_node_B.ibmat +
              proc_control_node_B.i;
            proc_control_node_B.L_tmp[proc_control_node_B.L_tmp_tmp] +=
              proc_control_node_B.M[20 * proc_control_node_B.ixlast +
              proc_control_node_B.i] *
              proc_control_node_DW.LastPcov_PreviousInput[20 *
              proc_control_node_B.ibmat + proc_control_node_B.ixlast];
          }
        }
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_Sum_tmp = 0.0;
          proc_control_node_B.dCoefs_tmp = 0;
          proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
          for (proc_control_node_B.L_tmp_tmp = 0; proc_control_node_B.L_tmp_tmp <
               20; proc_control_node_B.L_tmp_tmp++) {
            proc_control_node_B.rtb_Sum_tmp +=
              proc_control_node_B.L_tmp[proc_control_node_B.dCoefs_tmp +
              proc_control_node_B.ibmat] *
              proc_control_node_B.Cm[proc_control_node_B.LastPcov_PreviousInput_tmp
              + proc_control_node_B.ixlast];
            proc_control_node_B.dCoefs_tmp += 20;
            proc_control_node_B.LastPcov_PreviousInput_tmp += 12;
          }

          proc_control_node_B.L_tmp_tmp = proc_control_node_B.i +
            proc_control_node_B.ibmat;
          proc_control_node_B.L_tmp_g[proc_control_node_B.L_tmp_tmp] =
            proc_control_node_B.Nk[proc_control_node_B.L_tmp_tmp] +
            proc_control_node_B.rtb_Sum_tmp;
          proc_control_node_B.i += 20;
        }
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        memset(&proc_control_node_B.L[proc_control_node_B.ibmat * 20], 0, 20U *
               sizeof(real_T));
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
               proc_control_node_B.i++) {
            proc_control_node_B.dCoefs_tmp = 20 * proc_control_node_B.ibmat +
              proc_control_node_B.i;
            proc_control_node_B.L[proc_control_node_B.dCoefs_tmp] +=
              proc_control_node_B.L_tmp_g[20 * proc_control_node_B.ixlast +
              proc_control_node_B.i] * proc_control_node_B.Kinv_n[12 *
              proc_control_node_B.ibmat + proc_control_node_B.ixlast];
          }
        }
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_Sum_tmp = 0.0;
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 8;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_Sum_tmp +=
            proc_control_node_B.Bu[proc_control_node_B.i +
            proc_control_node_B.ibmat] * 0.0;
          proc_control_node_B.i += 20;
        }

        proc_control_node_B.xk[proc_control_node_B.ibmat] =
          (proc_control_node_DW.last_x_PreviousInput[proc_control_node_B.ibmat]
           - proc_control_node_B.b_xoff[proc_control_node_B.ibmat]) +
          proc_control_node_B.rtb_Sum_tmp;
      }

      // DataTypeConversion: '<S116>/mo or x Conversion' incorporates:
      //   MATLAB Function: '<S144>/FixedHorizonOptimizer'

      proc_control_node_B.dv7[0] = proc_control_node_B.WorldPosition[0] -
        proc_control_node_B.rtb_A_b[0];
      proc_control_node_B.dv7[3] = proc_control_node_B.s[0] -
        proc_control_node_B.rtb_A_b[3];
      proc_control_node_B.dv7[1] = proc_control_node_B.WorldPosition[1] -
        proc_control_node_B.rtb_A_b[1];
      proc_control_node_B.dv7[4] = proc_control_node_B.s[1] -
        proc_control_node_B.rtb_A_b[4];
      proc_control_node_B.dv7[2] = proc_control_node_B.WorldPosition[2] -
        proc_control_node_B.rtb_A_b[2];
      proc_control_node_B.dv7[5] = proc_control_node_B.s[2] -
        proc_control_node_B.rtb_A_b[5];
      proc_control_node_B.dv7[6] = proc_control_node_B.Sum_f -
        proc_control_node_B.rtb_A_b[6];
      proc_control_node_B.dv7[7] = proc_control_node_B.Sum_c -
        proc_control_node_B.rtb_A_b[7];
      proc_control_node_B.dv7[8] = proc_control_node_B.Sum -
        proc_control_node_B.rtb_A_b[8];
      proc_control_node_B.dv7[9] = proc_control_node_B.X -
        proc_control_node_B.rtb_A_b[9];
      proc_control_node_B.dv7[10] = proc_control_node_B.Y -
        proc_control_node_B.rtb_A_b[10];
      proc_control_node_B.dv7[11] = proc_control_node_B.Z -
        proc_control_node_B.rtb_A_b[11];

      // MATLAB Function: '<S144>/FixedHorizonOptimizer' incorporates:
      //   Memory: '<S116>/LastPcov'
      //   UnitDelay: '<S116>/last_mv'

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 12;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_Sum_tmp = 0.0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
             proc_control_node_B.i++) {
          proc_control_node_B.rtb_Sum_tmp += proc_control_node_B.Cm[12 *
            proc_control_node_B.i + proc_control_node_B.ibmat] *
            proc_control_node_B.xk[proc_control_node_B.i];
          proc_control_node_B.Nk[proc_control_node_B.i + 20 *
            proc_control_node_B.ibmat] = 0.0;
        }

        proc_control_node_B.y_innov[proc_control_node_B.ibmat] =
          proc_control_node_B.dv7[proc_control_node_B.ibmat] -
          (proc_control_node_B.rtb_Sum_tmp +
           proc_control_node_B.Dvm[proc_control_node_B.ibmat]);
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
             proc_control_node_B.i++) {
          for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
               proc_control_node_B.ixlast++) {
            proc_control_node_B.dCoefs_tmp = 20 * proc_control_node_B.ibmat +
              proc_control_node_B.ixlast;
            proc_control_node_B.Nk[proc_control_node_B.dCoefs_tmp] +=
              proc_control_node_DW.LastPcov_PreviousInput[20 *
              proc_control_node_B.i + proc_control_node_B.ixlast] *
              proc_control_node_B.Cm[12 * proc_control_node_B.i +
              proc_control_node_B.ibmat];
          }

          proc_control_node_B.dv3[proc_control_node_B.i + 20 *
            proc_control_node_B.ibmat] = 0.0;
        }
      }

      proc_control_node_B.ibmat = 0;
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
           proc_control_node_B.ixlast++) {
        proc_control_node_B.dCoefs_tmp = 0;
        for (proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
             proc_control_node_B.LastPcov_PreviousInput_tmp < 12;
             proc_control_node_B.LastPcov_PreviousInput_tmp++) {
          for (proc_control_node_B.L_tmp_tmp = 0; proc_control_node_B.L_tmp_tmp <
               20; proc_control_node_B.L_tmp_tmp++) {
            proc_control_node_B.i_f = proc_control_node_B.L_tmp_tmp +
              proc_control_node_B.ibmat;
            proc_control_node_B.dv3[proc_control_node_B.i_f] +=
              proc_control_node_B.Nk[proc_control_node_B.L_tmp_tmp +
              proc_control_node_B.dCoefs_tmp] *
              proc_control_node_B.Kinv_n[proc_control_node_B.LastPcov_PreviousInput_tmp
              + proc_control_node_B.i];
          }

          proc_control_node_B.dCoefs_tmp += 20;
        }

        proc_control_node_B.ibmat += 20;
        proc_control_node_B.i += 12;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_Sum_tmp = 0.0;
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_Sum_tmp +=
            proc_control_node_B.dv3[proc_control_node_B.i +
            proc_control_node_B.ibmat] *
            proc_control_node_B.y_innov[proc_control_node_B.ixlast];
          proc_control_node_B.i += 20;
        }

        proc_control_node_B.xk_l[proc_control_node_B.ibmat] =
          proc_control_node_B.xk[proc_control_node_B.ibmat] +
          proc_control_node_B.rtb_Sum_tmp;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.u_scale[proc_control_node_B.ibmat] =
          proc_control_node_DW.last_mv_DSTATE[proc_control_node_B.ibmat] -
          proc_control_node_B.twpt[proc_control_node_B.ibmat];
      }

      memset(&proc_control_node_B.dv1[0], 0, 1280U * sizeof(real_T));
      memset(&proc_control_node_B.dv2[0], 0, 704U * sizeof(real_T));
      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_u_n[proc_control_node_B.ibmat] =
          0.010000000000000002;
        proc_control_node_B.dv10[proc_control_node_B.ibmat] = 0.0;
      }

      memcpy(&proc_control_node_B.bv[0],
             &proc_control_node_DW.Memory_PreviousInput_o[0], sizeof(boolean_T) <<
             6);
      memcpy(&proc_control_node_B.o[0], &o[0], sizeof(real_T) << 9);
      memcpy(&proc_control_node_B.q[0], &q[0], 1089U * sizeof(real_T));
      memcpy(&proc_control_node_B.r[0], &r[0], 2112U * sizeof(real_T));

      // Update for Memory: '<S116>/Memory' incorporates:
      //   MATLAB Function: '<S144>/FixedHorizonOptimizer'

      proc_control_mpcblock_optimizer(proc_control_node_B.rseq,
        proc_control_node_B.vseq, proc_control_node_B.xk_l,
        proc_control_node_B.u_scale, proc_control_node_B.bv,
        proc_control_node_B.b_Mlim, proc_control_node_B.dv1,
        proc_control_node_B.o, proc_control_node_B.dv2,
        proc_control_node_B.b_utarget, proc_control_node_B.twpt,
        proc_control_node_B.q, proc_control_node_B.r, s,
        proc_control_node_B.rtb_u_n, t, proc_control_node_B.dv10, u,
        proc_control_node_B.M, proc_control_node_B.Bu, proc_control_node_B.Bv,
        proc_control_node_B.b_C, proc_control_node_B.Dv, h,
        proc_control_node_B.u, proc_control_node_B.useq,
        &proc_control_node_B.status, proc_control_node_DW.Memory_PreviousInput_o);

      // MATLAB Function: '<S144>/FixedHorizonOptimizer'
      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
           proc_control_node_B.i++) {
        memset(&proc_control_node_B.L_tmp_b[proc_control_node_B.ibmat], 0, 20U *
               sizeof(real_T));
        proc_control_node_B.ibmat += 20;
      }

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
           20; proc_control_node_B.dCoefs_tmp++) {
        proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
             proc_control_node_B.i++) {
          for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
               proc_control_node_B.ixlast++) {
            proc_control_node_B.L_tmp_tmp = proc_control_node_B.ixlast +
              proc_control_node_B.LastPcov_PreviousInput_tmp;
            proc_control_node_B.L_tmp_b[proc_control_node_B.L_tmp_tmp] +=
              proc_control_node_B.L_tmp[proc_control_node_B.ixlast +
              proc_control_node_B.ibmat] *
              proc_control_node_B.M[proc_control_node_B.i +
              proc_control_node_B.ibmat];
          }

          proc_control_node_B.L_tmp_p[proc_control_node_B.i +
            proc_control_node_B.ibmat] = 0.0;
          proc_control_node_B.LastPcov_PreviousInput_tmp += 20;
        }

        proc_control_node_B.ibmat += 20;
      }

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 12;
           proc_control_node_B.i++) {
        proc_control_node_B.ixlast = 0;
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             20; proc_control_node_B.dCoefs_tmp++) {
          for (proc_control_node_B.LastPcov_PreviousInput_tmp = 0;
               proc_control_node_B.LastPcov_PreviousInput_tmp < 20;
               proc_control_node_B.LastPcov_PreviousInput_tmp++) {
            proc_control_node_B.L_tmp_tmp =
              proc_control_node_B.LastPcov_PreviousInput_tmp +
              proc_control_node_B.ixlast;
            proc_control_node_B.L_tmp_p[proc_control_node_B.L_tmp_tmp] +=
              proc_control_node_B.L_tmp_g[proc_control_node_B.LastPcov_PreviousInput_tmp
              + proc_control_node_B.ibmat] *
              proc_control_node_B.L[proc_control_node_B.dCoefs_tmp +
              proc_control_node_B.ibmat];
          }

          proc_control_node_B.ixlast += 20;
        }

        proc_control_node_B.ibmat += 20;
      }

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 400;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.L_tmp[proc_control_node_B.ibmat] =
          (proc_control_node_B.L_tmp_b[proc_control_node_B.ibmat] -
           proc_control_node_B.L_tmp_p[proc_control_node_B.ibmat]) +
          proc_control_node_B.Kinv[proc_control_node_B.ibmat];
      }

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
           proc_control_node_B.i++) {
        // Gain: '<S116>/u_scale'
        proc_control_node_B.Merge_a =
          proc_control_node_P.u_scale_Gain[proc_control_node_B.i] *
          proc_control_node_B.u[proc_control_node_B.i];

        // Merge: '<S9>/Merge' incorporates:
        //   Gain: '<S116>/u_scale'
        //   SignalConversion generated from: '<S110>/mv'

        proc_control_node_B.Merge[proc_control_node_B.i] =
          proc_control_node_B.Merge_a;
        proc_control_node_B.u_scale[proc_control_node_B.i] =
          proc_control_node_B.Merge_a;
      }

      // DiscretePulseGenerator: '<S110>/Pulse Generator' incorporates:
      //   Gain: '<S116>/u_scale'

      proc_control_node_B.PulseGenerator =
        (proc_control_node_DW.clockTickCounter <
         proc_control_node_P.PulseGenerator_Duty) &&
        (proc_control_node_DW.clockTickCounter >= 0) ?
        proc_control_node_P.PulseGenerator_Amp : 0.0;

      // DiscretePulseGenerator: '<S110>/Pulse Generator'
      if (proc_control_node_DW.clockTickCounter >=
          proc_control_node_P.PulseGenerator_Period - 1.0) {
        proc_control_node_DW.clockTickCounter = 0;
      } else {
        proc_control_node_DW.clockTickCounter++;
      }

      // Update for Memory: '<S116>/LastPcov' incorporates:
      //   MATLAB Function: '<S144>/FixedHorizonOptimizer'

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 20;
           proc_control_node_B.i++) {
        proc_control_node_B.ixlast = 0;
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             20; proc_control_node_B.dCoefs_tmp++) {
          proc_control_node_B.LastPcov_PreviousInput_tmp =
            proc_control_node_B.dCoefs_tmp + proc_control_node_B.ibmat;
          proc_control_node_DW.LastPcov_PreviousInput[proc_control_node_B.LastPcov_PreviousInput_tmp]
            =
            (proc_control_node_B.L_tmp[proc_control_node_B.LastPcov_PreviousInput_tmp]
             + proc_control_node_B.L_tmp[proc_control_node_B.ixlast +
             proc_control_node_B.i]) * 0.5;
          proc_control_node_B.ixlast += 20;
        }

        proc_control_node_B.ibmat += 20;
      }

      // End of Update for Memory: '<S116>/LastPcov'
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
           proc_control_node_B.i++) {
        proc_control_node_B.Merge_a =
          proc_control_node_B.u[proc_control_node_B.i];

        // Update for UnitDelay: '<S116>/last_mv'
        proc_control_node_DW.last_mv_DSTATE[proc_control_node_B.i] =
          proc_control_node_B.Merge_a;

        // MATLAB Function: '<S144>/FixedHorizonOptimizer' incorporates:
        //   UnitDelay: '<S116>/last_mv'

        proc_control_node_B.rtb_u_n[proc_control_node_B.i] =
          proc_control_node_B.Merge_a -
          proc_control_node_B.twpt[proc_control_node_B.i];
      }

      // MATLAB Function: '<S144>/FixedHorizonOptimizer' incorporates:
      //   UnitDelay: '<S116>/last_mv'

      memset(&proc_control_node_B.xk_l[0], 0, 20U * sizeof(real_T));
      proc_control_node_B.i = 0;
      for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
           proc_control_node_B.ixlast++) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.xk_l[proc_control_node_B.ibmat] +=
            proc_control_node_B.M[proc_control_node_B.ibmat +
            proc_control_node_B.i] *
            proc_control_node_B.xk[proc_control_node_B.ixlast];
        }

        proc_control_node_B.Bu_h[proc_control_node_B.ixlast] = 0.0;
        proc_control_node_B.i += 20;
      }

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
           proc_control_node_B.i++) {
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 20;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.Bu_h[proc_control_node_B.ixlast] +=
            proc_control_node_B.Bu[proc_control_node_B.ixlast +
            proc_control_node_B.ibmat] *
            proc_control_node_B.rtb_u_n[proc_control_node_B.i];
        }

        proc_control_node_B.ibmat += 20;
      }

      // Update for Memory: '<S116>/last_x' incorporates:
      //   MATLAB Function: '<S144>/FixedHorizonOptimizer'

      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 20;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.rtb_Sum_tmp = 0.0;
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 12;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.rtb_Sum_tmp +=
            proc_control_node_B.L[proc_control_node_B.i +
            proc_control_node_B.ibmat] *
            proc_control_node_B.y_innov[proc_control_node_B.ixlast];
          proc_control_node_B.i += 20;
        }

        proc_control_node_DW.last_x_PreviousInput[proc_control_node_B.ibmat] =
          (((proc_control_node_B.xk_l[proc_control_node_B.ibmat] +
             proc_control_node_B.Bu_h[proc_control_node_B.ibmat]) +
            proc_control_node_B.Bv[proc_control_node_B.ibmat]) +
           proc_control_node_B.rtb_Sum_tmp) +
          proc_control_node_B.b_xoff[proc_control_node_B.ibmat];
      }

      // End of Update for Memory: '<S116>/last_x'

      // Update for Delay: '<S110>/Delay1'
      memcpy(&proc_control_node_DW.Delay1_DSTATE[0],
             &proc_control_node_B.u_scale[0], sizeof(real_T) << 3U);
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa);
      }

      // End of Outputs for SubSystem: '<S9>/Quaternion Non linear MPC'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S9>/JoyStick OpenLoop' incorporates:
      //   ActionPort: '<S109>/Action Port'

      // SampleTimeMath: '<S111>/TSamp' incorporates:
      //   Merge: '<S11>/Merge'
      //   Selector: '<S109>/Selector'
      //
      //  About '<S111>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )

      proc_control_node_B.ibmat = 0;
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_B.Gain3[proc_control_node_B.i] =
          proc_control_node_B.Quaternion[proc_control_node_B.ibmat + 70] *
          proc_control_node_P.TSamp_WtEt;
        proc_control_node_B.ibmat += 10;
      }

      // End of SampleTimeMath: '<S111>/TSamp'

      // MATLABSystem: '<S109>/MATLAB System' incorporates:
      //   Merge: '<S11>/Merge'
      //   Selector: '<S109>/Selector'

      if (proc_control_node_DW.obj_m.k != proc_control_node_P.MATLABSystem_k) {
        proc_control_node_DW.obj_m.k = proc_control_node_P.MATLABSystem_k;
      }

      proc_control_node_B.SourceBlock_o1_d = false;
      proc_control_node_B.OR1 = true;
      proc_control_node_B.ibmat = 0;
      exitg1 = false;
      while ((!exitg1) && (proc_control_node_B.ibmat < 48)) {
        if (!(proc_control_node_DW.obj_m.binv[proc_control_node_B.ibmat] ==
              proc_control_node_P.binv[proc_control_node_B.ibmat])) {
          proc_control_node_B.OR1 = false;
          exitg1 = true;
        } else {
          proc_control_node_B.ibmat++;
        }
      }

      if (proc_control_node_B.OR1) {
        proc_control_node_B.SourceBlock_o1_d = true;
      }

      if (!proc_control_node_B.SourceBlock_o1_d) {
        memcpy(&proc_control_node_DW.obj_m.binv[0], &proc_control_node_P.binv[0],
               48U * sizeof(real_T));
      }

      if (proc_control_node_DW.obj_m.mass != proc_control_node_P.physics.mass) {
        proc_control_node_DW.obj_m.mass = proc_control_node_P.physics.mass;
      }

      if (proc_control_node_DW.obj_m.volume !=
          proc_control_node_P.physics.volume) {
        proc_control_node_DW.obj_m.volume = proc_control_node_P.physics.volume;
      }

      if (proc_control_node_DW.obj_m.height !=
          proc_control_node_P.physics.height) {
        proc_control_node_DW.obj_m.height = proc_control_node_P.physics.height;
      }

      proc_control_node_B.SourceBlock_o1_d = false;
      proc_control_node_B.OR1 = true;
      proc_control_node_B.ibmat = 0;
      exitg1 = false;
      while ((!exitg1) && (proc_control_node_B.ibmat < 9)) {
        if (!(proc_control_node_DW.obj_m.I[proc_control_node_B.ibmat] ==
              proc_control_node_P.physics.I[proc_control_node_B.ibmat])) {
          proc_control_node_B.OR1 = false;
          exitg1 = true;
        } else {
          proc_control_node_B.ibmat++;
        }
      }

      if (proc_control_node_B.OR1) {
        proc_control_node_B.SourceBlock_o1_d = true;
      }

      if (!proc_control_node_B.SourceBlock_o1_d) {
        memcpy(&proc_control_node_DW.obj_m.I[0], &proc_control_node_P.physics.I
               [0], 9U * sizeof(real_T));
      }

      if (!proc_control_node_isequal(proc_control_node_DW.obj_m.RG,
           proc_control_node_P.physics.RG)) {
        proc_control_node_DW.obj_m.RG[0] = proc_control_node_P.physics.RG[0];
        proc_control_node_DW.obj_m.RG[1] = proc_control_node_P.physics.RG[1];
        proc_control_node_DW.obj_m.RG[2] = proc_control_node_P.physics.RG[2];
      }

      if (!proc_control_node_isequal(proc_control_node_DW.obj_m.RB,
           proc_control_node_P.physics.RB)) {
        proc_control_node_DW.obj_m.RB[0] = proc_control_node_P.physics.RB[0];
        proc_control_node_DW.obj_m.RB[1] = proc_control_node_P.physics.RB[1];
        proc_control_node_DW.obj_m.RB[2] = proc_control_node_P.physics.RB[2];
      }

      if (!proc_control_node_isequal_b4(proc_control_node_DW.obj_m.AddedMass,
           proc_control_node_P.physics.AddedMass)) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_DW.obj_m.AddedMass[proc_control_node_B.ibmat] =
            proc_control_node_P.physics.AddedMass[proc_control_node_B.ibmat];
        }
      }

      if (!proc_control_node_isequal_b4(proc_control_node_DW.obj_m.CDL,
           proc_control_node_P.physics.CDL)) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_DW.obj_m.CDL[proc_control_node_B.ibmat] =
            proc_control_node_P.physics.CDL[proc_control_node_B.ibmat];
        }
      }

      if (!proc_control_node_isequal_b4(proc_control_node_DW.obj_m.CDQ,
           proc_control_node_P.physics.CDQ)) {
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_DW.obj_m.CDQ[proc_control_node_B.ibmat] =
            proc_control_node_P.physics.CDQ[proc_control_node_B.ibmat];
        }
      }

      if (!proc_control_node_isequal(proc_control_node_DW.obj_m.AF,
           proc_control_node_P.physics.AF)) {
        proc_control_node_DW.obj_m.AF[0] = proc_control_node_P.physics.AF[0];
        proc_control_node_DW.obj_m.AF[1] = proc_control_node_P.physics.AF[1];
        proc_control_node_DW.obj_m.AF[2] = proc_control_node_P.physics.AF[2];
      }

      if (proc_control_node_DW.obj_m.g != proc_control_node_P.physics.g) {
        proc_control_node_DW.obj_m.g = proc_control_node_P.physics.g;
      }

      if (proc_control_node_DW.obj_m.rho != proc_control_node_P.physics.rho) {
        proc_control_node_DW.obj_m.rho = proc_control_node_P.physics.rho;
      }

      //  Implement algorithm. Calculate y as a function of input u and
      //  discrete states.
      switch (proc_control_node_B.Data) {
       case 20U:
        //  Open loop avec modèle physique
        //  Construire le vecteur constantes
        proc_control_node_B.constValues[0] = proc_control_node_DW.obj_m.mass;
        proc_control_node_B.constValues[1] = proc_control_node_DW.obj_m.volume;
        proc_control_node_B.constValues[6] = proc_control_node_DW.obj_m.I[0];
        proc_control_node_B.constValues[9] = proc_control_node_DW.obj_m.I[1];
        proc_control_node_B.constValues[12] = proc_control_node_DW.obj_m.I[2];
        proc_control_node_B.constValues[15] = proc_control_node_DW.obj_m.RG[0];
        proc_control_node_B.constValues[18] = proc_control_node_DW.obj_m.RB[0];
        proc_control_node_B.constValues[7] = proc_control_node_DW.obj_m.I[3];
        proc_control_node_B.constValues[10] = proc_control_node_DW.obj_m.I[4];
        proc_control_node_B.constValues[13] = proc_control_node_DW.obj_m.I[5];
        proc_control_node_B.constValues[16] = proc_control_node_DW.obj_m.RG[1];
        proc_control_node_B.constValues[19] = proc_control_node_DW.obj_m.RB[1];
        proc_control_node_B.constValues[8] = proc_control_node_DW.obj_m.I[6];
        proc_control_node_B.constValues[11] = proc_control_node_DW.obj_m.I[7];
        proc_control_node_B.constValues[14] = proc_control_node_DW.obj_m.I[8];
        proc_control_node_B.constValues[17] = proc_control_node_DW.obj_m.RG[2];
        proc_control_node_B.constValues[20] = proc_control_node_DW.obj_m.RB[2];
        proc_control_node_B.constValues[39] = proc_control_node_DW.obj_m.rho;
        proc_control_node_B.constValues[40] = proc_control_node_DW.obj_m.g;

        // construire le vecteur state avec la imu et spaceNAV
        proc_control_node_B.TmpSignalConversionAtTran_a[3] = 1.0;
        proc_control_node_B.TmpSignalConversionAtTran_a[4] = 0.0;
        proc_control_node_B.TmpSignalConversionAtTran_a[5] = 0.0;
        proc_control_node_B.TmpSignalConversionAtTran_a[6] = 0.0;
        proc_control_node_B.ibmat = 0;
        for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
             proc_control_node_B.i++) {
          proc_control_node_B.constValues[proc_control_node_B.i + 21] =
            proc_control_node_DW.obj_m.CDL[proc_control_node_B.i];
          proc_control_node_B.constValues[proc_control_node_B.i + 27] =
            proc_control_node_DW.obj_m.CDQ[proc_control_node_B.i];
          proc_control_node_B.constValues[proc_control_node_B.i + 33] =
            proc_control_node_DW.obj_m.AddedMass[proc_control_node_B.i];
          proc_control_node_B.TmpSignalConversionAtTran_a[proc_control_node_B.i
            + 7] = proc_control_node_B.Quaternion[proc_control_node_B.ibmat + 70];
          proc_control_node_B.ibmat += 10;
        }

        // [0;0;0;mo(4:7);ref.'];;
        //  Déterminer les matrices du modèle physique
        // AUVMODELMATRICES
        //     [M,C,D,GQ] = AUVMODELMATRICES(IN1,IN2)
        //     This function was generated by the Symbolic Math Toolbox version 8.7. 
        //     07-Sep-2021 21:49:26
        proc_control_node_B.Merge_a = proc_control_node_B.constValues[6] *
          proc_control_node_B.TmpSignalConversionAtTran_a[10];
        proc_control_node_B.fcn2 = proc_control_node_B.constValues[9] *
          proc_control_node_B.TmpSignalConversionAtTran_a[10];
        proc_control_node_B.fcn4_g =
          proc_control_node_B.TmpSignalConversionAtTran_a[10] *
          proc_control_node_B.constValues[12];
        proc_control_node_B.Product3_gb = proc_control_node_B.constValues[7] *
          proc_control_node_B.TmpSignalConversionAtTran_a[11];
        proc_control_node_B.fcn5_e = proc_control_node_B.constValues[10] *
          proc_control_node_B.TmpSignalConversionAtTran_a[11];
        proc_control_node_B.Product1_fh =
          proc_control_node_B.TmpSignalConversionAtTran_a[11] *
          proc_control_node_B.constValues[13];
        proc_control_node_B.Product2_ei = proc_control_node_B.constValues[8] *
          proc_control_node_B.TmpSignalConversionAtTran_a[12];
        proc_control_node_B.t9 = proc_control_node_B.constValues[11] *
          proc_control_node_B.TmpSignalConversionAtTran_a[12];
        proc_control_node_B.t10 =
          proc_control_node_B.TmpSignalConversionAtTran_a[12] *
          proc_control_node_B.constValues[14];
        proc_control_node_B.t11 =
          proc_control_node_B.TmpSignalConversionAtTran_a[10] *
          proc_control_node_B.constValues[36];
        proc_control_node_B.t12 =
          proc_control_node_B.TmpSignalConversionAtTran_a[11] *
          proc_control_node_B.constValues[37];
        proc_control_node_B.t13 = proc_control_node_B.constValues[0] *
          proc_control_node_B.constValues[15];
        proc_control_node_B.t14 = proc_control_node_B.constValues[0] *
          proc_control_node_B.constValues[16];
        proc_control_node_B.t15 = proc_control_node_B.constValues[0] *
          proc_control_node_B.constValues[17];
        proc_control_node_B.t16 =
          proc_control_node_B.TmpSignalConversionAtTran_a[12] *
          proc_control_node_B.constValues[38];
        proc_control_node_B.t17 =
          proc_control_node_B.TmpSignalConversionAtTran_a[10] *
          proc_control_node_B.constValues[15];
        proc_control_node_B.t21 =
          proc_control_node_B.TmpSignalConversionAtTran_a[11] *
          proc_control_node_B.constValues[16];
        proc_control_node_B.t25 =
          proc_control_node_B.TmpSignalConversionAtTran_a[12] *
          proc_control_node_B.constValues[17];
        proc_control_node_B.t26 =
          proc_control_node_B.TmpSignalConversionAtTran_a[7] *
          proc_control_node_B.constValues[33];
        proc_control_node_B.t27 =
          proc_control_node_B.TmpSignalConversionAtTran_a[8] *
          proc_control_node_B.constValues[34];
        proc_control_node_B.t28 =
          proc_control_node_B.TmpSignalConversionAtTran_a[9] *
          proc_control_node_B.constValues[35];
        proc_control_node_B.t29 = proc_control_node_B.constValues[1] *
          proc_control_node_B.constValues[39];
        proc_control_node_B.t65_tmp =
          proc_control_node_B.TmpSignalConversionAtTran_a[5] *
          proc_control_node_B.TmpSignalConversionAtTran_a[6];
        proc_control_node_B.t65_tmp_o =
          proc_control_node_B.TmpSignalConversionAtTran_a[3] *
          proc_control_node_B.TmpSignalConversionAtTran_a[4];
        proc_control_node_B.t65 = proc_control_node_B.t65_tmp * 2.0 +
          proc_control_node_B.t65_tmp_o * 2.0;
        proc_control_node_B.t56 =
          (proc_control_node_B.TmpSignalConversionAtTran_a[11] *
           proc_control_node_B.constValues[17] +
           proc_control_node_B.TmpSignalConversionAtTran_a[7]) *
          proc_control_node_B.constValues[0];
        proc_control_node_B.t57 =
          (proc_control_node_B.TmpSignalConversionAtTran_a[10] *
           proc_control_node_B.constValues[16] +
           proc_control_node_B.TmpSignalConversionAtTran_a[9]) *
          proc_control_node_B.constValues[0];
        proc_control_node_B.t58 =
          (proc_control_node_B.TmpSignalConversionAtTran_a[12] *
           proc_control_node_B.constValues[15] +
           proc_control_node_B.TmpSignalConversionAtTran_a[8]) *
          proc_control_node_B.constValues[0];
        proc_control_node_B.t62 = (proc_control_node_B.t17 +
          proc_control_node_B.t21) * proc_control_node_B.constValues[0];
        proc_control_node_B.t17 = (proc_control_node_B.t17 +
          proc_control_node_B.t25) * proc_control_node_B.constValues[0];
        proc_control_node_B.t21 = (proc_control_node_B.t21 +
          proc_control_node_B.t25) * proc_control_node_B.constValues[0];
        proc_control_node_B.t25_tmp =
          proc_control_node_B.TmpSignalConversionAtTran_a[4] *
          proc_control_node_B.TmpSignalConversionAtTran_a[6];
        proc_control_node_B.t25_tmp_m =
          proc_control_node_B.TmpSignalConversionAtTran_a[3] *
          proc_control_node_B.TmpSignalConversionAtTran_a[5];
        proc_control_node_B.t25 = proc_control_node_B.t25_tmp * 2.0 +
          -(proc_control_node_B.t25_tmp_m * 2.0);
        proc_control_node_B.t70 =
          (proc_control_node_B.TmpSignalConversionAtTran_a[4] *
           proc_control_node_B.TmpSignalConversionAtTran_a[4] * 2.0 +
           proc_control_node_B.TmpSignalConversionAtTran_a[5] *
           proc_control_node_B.TmpSignalConversionAtTran_a[5] * 2.0) - 1.0;

        //  CAlculer la comande
        proc_control_node_B.pp_coefs[0] = -proc_control_node_B.constValues[33] +
          proc_control_node_B.constValues[0];
        proc_control_node_B.pp_coefs[1] = 0.0;
        proc_control_node_B.pp_coefs[2] = 0.0;
        proc_control_node_B.pp_coefs[3] = 0.0;
        proc_control_node_B.pp_coefs[4] = proc_control_node_B.t15;
        proc_control_node_B.pp_coefs[5] = -proc_control_node_B.t14;
        proc_control_node_B.pp_coefs[6] = 0.0;
        proc_control_node_B.pp_coefs[7] = -proc_control_node_B.constValues[34] +
          proc_control_node_B.constValues[0];
        proc_control_node_B.pp_coefs[8] = 0.0;
        proc_control_node_B.pp_coefs[9] = -proc_control_node_B.t15;
        proc_control_node_B.pp_coefs[10] = 0.0;
        proc_control_node_B.pp_coefs[11] = proc_control_node_B.t13;
        proc_control_node_B.pp_coefs[12] = 0.0;
        proc_control_node_B.pp_coefs[13] = 0.0;
        proc_control_node_B.pp_coefs[14] = -proc_control_node_B.constValues[35]
          + proc_control_node_B.constValues[0];
        proc_control_node_B.pp_coefs[15] = proc_control_node_B.t14;
        proc_control_node_B.pp_coefs[16] = -proc_control_node_B.t13;
        proc_control_node_B.pp_coefs[17] = 0.0;
        proc_control_node_B.pp_coefs[18] = 0.0;
        proc_control_node_B.pp_coefs[19] = -proc_control_node_B.t15;
        proc_control_node_B.pp_coefs[20] = proc_control_node_B.t14;
        proc_control_node_B.pp_coefs[21] = proc_control_node_B.constValues[6] -
          proc_control_node_B.constValues[36];
        proc_control_node_B.pp_coefs[22] = proc_control_node_B.constValues[9];
        proc_control_node_B.pp_coefs[23] = proc_control_node_B.constValues[12];
        proc_control_node_B.pp_coefs[24] = proc_control_node_B.t15;
        proc_control_node_B.pp_coefs[25] = 0.0;
        proc_control_node_B.pp_coefs[26] = -proc_control_node_B.t13;
        proc_control_node_B.pp_coefs[27] = proc_control_node_B.constValues[7];
        proc_control_node_B.pp_coefs[28] = proc_control_node_B.constValues[10] -
          proc_control_node_B.constValues[37];
        proc_control_node_B.pp_coefs[29] = proc_control_node_B.constValues[13];
        proc_control_node_B.pp_coefs[30] = -proc_control_node_B.t14;
        proc_control_node_B.pp_coefs[31] = proc_control_node_B.t13;
        proc_control_node_B.pp_coefs[32] = 0.0;
        proc_control_node_B.pp_coefs[33] = proc_control_node_B.constValues[8];
        proc_control_node_B.pp_coefs[34] = proc_control_node_B.constValues[11];
        proc_control_node_B.pp_coefs[35] = proc_control_node_B.constValues[14] -
          proc_control_node_B.constValues[38];

        // Sum: '<S111>/Diff' incorporates:
        //   Merge: '<S11>/Merge'
        //   SampleTimeMath: '<S111>/TSamp'
        //   Selector: '<S109>/Selector'
        //   UnitDelay: '<S111>/UD'
        //
        //  About '<S111>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        //  Block description for '<S111>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S111>/UD':
        //
        //   Store in Global RAM

        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.rtb_Gain3_m[proc_control_node_B.ibmat] =
            proc_control_node_B.Gain3[proc_control_node_B.ibmat] -
            proc_control_node_DW.UD_DSTATE[proc_control_node_B.ibmat];
        }

        // End of Sum: '<S111>/Diff'
        proc_control_node_B.dCoefs[0] = 0.0;
        proc_control_node_B.dCoefs[1] = 0.0;
        proc_control_node_B.dCoefs[2] = 0.0;
        proc_control_node_B.dCoefs[3] = -proc_control_node_B.t21;
        proc_control_node_B.rtb_Sum_tmp =
          proc_control_node_B.TmpSignalConversionAtTran_a[11] *
          proc_control_node_B.constValues[15] -
          proc_control_node_B.TmpSignalConversionAtTran_a[9];
        proc_control_node_B.dCoefs[4] = proc_control_node_B.rtb_Sum_tmp *
          proc_control_node_B.constValues[0] + proc_control_node_B.t28;
        proc_control_node_B.dCoefs[5] = -proc_control_node_B.t27 +
          proc_control_node_B.t58;
        proc_control_node_B.dCoefs[6] = 0.0;
        proc_control_node_B.dCoefs[7] = 0.0;
        proc_control_node_B.dCoefs[8] = 0.0;
        proc_control_node_B.dCoefs[9] = -proc_control_node_B.t28 +
          proc_control_node_B.t57;
        proc_control_node_B.dCoefs[10] = -proc_control_node_B.t17;
        proc_control_node_B.d1 =
          proc_control_node_B.TmpSignalConversionAtTran_a[12] *
          proc_control_node_B.constValues[16] -
          proc_control_node_B.TmpSignalConversionAtTran_a[7];
        proc_control_node_B.dCoefs[11] = proc_control_node_B.d1 *
          proc_control_node_B.constValues[0] + proc_control_node_B.t26;
        proc_control_node_B.dCoefs[12] = 0.0;
        proc_control_node_B.dCoefs[13] = 0.0;
        proc_control_node_B.dCoefs[14] = 0.0;
        proc_control_node_B.d_p =
          proc_control_node_B.TmpSignalConversionAtTran_a[10] *
          proc_control_node_B.constValues[17] -
          proc_control_node_B.TmpSignalConversionAtTran_a[8];
        proc_control_node_B.dCoefs[15] = proc_control_node_B.d_p *
          proc_control_node_B.constValues[0] + proc_control_node_B.t27;
        proc_control_node_B.dCoefs[16] = -proc_control_node_B.t26 +
          proc_control_node_B.t56;
        proc_control_node_B.dCoefs[17] = -proc_control_node_B.t62;
        proc_control_node_B.dCoefs[18] = proc_control_node_B.t21;
        proc_control_node_B.dCoefs[19] = proc_control_node_B.t28 -
          proc_control_node_B.t57;
        proc_control_node_B.dCoefs[20] = proc_control_node_B.d_p *
          -proc_control_node_B.constValues[0] + -proc_control_node_B.t27;
        proc_control_node_B.dCoefs[21] = 0.0;
        proc_control_node_B.dCoefs[22] = ((-proc_control_node_B.fcn4_g -
          proc_control_node_B.Product1_fh) - proc_control_node_B.t10) +
          proc_control_node_B.t16;
        proc_control_node_B.dCoefs[23] = ((proc_control_node_B.fcn2 +
          proc_control_node_B.fcn5_e) + proc_control_node_B.t9) -
          proc_control_node_B.t12;
        proc_control_node_B.dCoefs[24] = proc_control_node_B.rtb_Sum_tmp *
          -proc_control_node_B.constValues[0] + -proc_control_node_B.t28;
        proc_control_node_B.dCoefs[25] = proc_control_node_B.t17;
        proc_control_node_B.dCoefs[26] = proc_control_node_B.t26 -
          proc_control_node_B.t56;
        proc_control_node_B.dCoefs[27] = ((proc_control_node_B.fcn4_g +
          proc_control_node_B.Product1_fh) + proc_control_node_B.t10) -
          proc_control_node_B.t16;
        proc_control_node_B.dCoefs[28] = 0.0;
        proc_control_node_B.dCoefs[29] = ((-proc_control_node_B.Merge_a -
          proc_control_node_B.Product3_gb) - proc_control_node_B.Product2_ei) +
          proc_control_node_B.t11;
        proc_control_node_B.dCoefs[30] = proc_control_node_B.t27 -
          proc_control_node_B.t58;
        proc_control_node_B.dCoefs[31] = proc_control_node_B.d1 *
          -proc_control_node_B.constValues[0] + -proc_control_node_B.t26;
        proc_control_node_B.dCoefs[32] = proc_control_node_B.t62;
        proc_control_node_B.dCoefs[33] = ((-proc_control_node_B.fcn2 -
          proc_control_node_B.fcn5_e) - proc_control_node_B.t9) +
          proc_control_node_B.t12;
        proc_control_node_B.dCoefs[34] = ((proc_control_node_B.Merge_a +
          proc_control_node_B.Product3_gb) + proc_control_node_B.Product2_ei) -
          proc_control_node_B.t11;
        proc_control_node_B.dCoefs[35] = 0.0;
        proc_control_node_B.constValues_l[0] = proc_control_node_B.constValues
          [27] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[7]) +
          proc_control_node_B.constValues[21];
        proc_control_node_B.constValues_l[1] = 0.0;
        proc_control_node_B.constValues_l[2] = 0.0;
        proc_control_node_B.constValues_l[3] = 0.0;
        proc_control_node_B.constValues_l[4] = 0.0;
        proc_control_node_B.constValues_l[5] = 0.0;
        proc_control_node_B.constValues_l[6] = 0.0;
        proc_control_node_B.constValues_l[7] = proc_control_node_B.constValues
          [28] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[8]) +
          proc_control_node_B.constValues[22];
        proc_control_node_B.constValues_l[8] = 0.0;
        proc_control_node_B.constValues_l[9] = 0.0;
        proc_control_node_B.constValues_l[10] = 0.0;
        proc_control_node_B.constValues_l[11] = 0.0;
        proc_control_node_B.constValues_l[12] = 0.0;
        proc_control_node_B.constValues_l[13] = 0.0;
        proc_control_node_B.constValues_l[14] = proc_control_node_B.constValues
          [29] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[9]) +
          proc_control_node_B.constValues[23];
        proc_control_node_B.constValues_l[15] = 0.0;
        proc_control_node_B.constValues_l[16] = 0.0;
        proc_control_node_B.constValues_l[17] = 0.0;
        proc_control_node_B.constValues_l[18] = 0.0;
        proc_control_node_B.constValues_l[19] = 0.0;
        proc_control_node_B.constValues_l[20] = 0.0;
        proc_control_node_B.constValues_l[21] = proc_control_node_B.constValues
          [30] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[10]) +
          proc_control_node_B.constValues[24];
        proc_control_node_B.constValues_l[22] = 0.0;
        proc_control_node_B.constValues_l[23] = 0.0;
        proc_control_node_B.constValues_l[24] = 0.0;
        proc_control_node_B.constValues_l[25] = 0.0;
        proc_control_node_B.constValues_l[26] = 0.0;
        proc_control_node_B.constValues_l[27] = 0.0;
        proc_control_node_B.constValues_l[28] = proc_control_node_B.constValues
          [31] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[11]) +
          proc_control_node_B.constValues[25];
        proc_control_node_B.constValues_l[29] = 0.0;
        proc_control_node_B.constValues_l[30] = 0.0;
        proc_control_node_B.constValues_l[31] = 0.0;
        proc_control_node_B.constValues_l[32] = 0.0;
        proc_control_node_B.constValues_l[33] = 0.0;
        proc_control_node_B.constValues_l[34] = 0.0;
        proc_control_node_B.constValues_l[35] = proc_control_node_B.constValues
          [32] * fabs(proc_control_node_B.TmpSignalConversionAtTran_a[12]) +
          proc_control_node_B.constValues[26];
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 36;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.dv5[proc_control_node_B.ibmat] =
            proc_control_node_B.dCoefs[proc_control_node_B.ibmat] +
            proc_control_node_B.constValues_l[proc_control_node_B.ibmat];
        }

        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.a__4[proc_control_node_B.ibmat] = 0.0;
        }

        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 6;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
               proc_control_node_B.ibmat++) {
            proc_control_node_B.a__4[proc_control_node_B.ibmat] +=
              proc_control_node_B.pp_coefs[proc_control_node_B.ibmat +
              proc_control_node_B.i] *
              proc_control_node_B.rtb_Gain3_m[proc_control_node_B.ixlast];
          }

          proc_control_node_B.Gain_k[proc_control_node_B.ixlast] = 0.0;
          proc_control_node_B.i += 6;
        }

        proc_control_node_B.ibmat = 0;
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 6;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.dCoefs_tmp = 0;
               proc_control_node_B.dCoefs_tmp < 6;
               proc_control_node_B.dCoefs_tmp++) {
            proc_control_node_B.Gain_k[proc_control_node_B.dCoefs_tmp] +=
              proc_control_node_B.dv5[proc_control_node_B.dCoefs_tmp +
              proc_control_node_B.ibmat] *
              proc_control_node_B.Quaternion[proc_control_node_B.i + 70];
          }

          proc_control_node_B.ibmat += 6;
          proc_control_node_B.i += 10;
        }

        proc_control_node_B.Merge_a = proc_control_node_B.constValues[40] *
          (proc_control_node_B.constValues[0] + -proc_control_node_B.t29);
        proc_control_node_B.rtb_Gain3_m[0] = (proc_control_node_B.t25_tmp -
          proc_control_node_B.t25_tmp_m) * proc_control_node_B.Merge_a * -2.0;
        proc_control_node_B.rtb_Gain3_m[1] = (proc_control_node_B.t65_tmp +
          proc_control_node_B.t65_tmp_o) * proc_control_node_B.Merge_a * -2.0;
        proc_control_node_B.rtb_Gain3_m[2] = proc_control_node_B.Merge_a *
          proc_control_node_B.t70;
        proc_control_node_B.Merge_a = proc_control_node_B.constValues[20] *
          proc_control_node_B.constValues[40];
        proc_control_node_B.fcn2 = proc_control_node_B.constValues[40] *
          proc_control_node_B.t14;
        proc_control_node_B.fcn4_g = proc_control_node_B.constValues[19] *
          proc_control_node_B.constValues[40] * -proc_control_node_B.t29;
        proc_control_node_B.rtb_Gain3_m[3] = ((proc_control_node_B.constValues
          [40] * proc_control_node_B.t15 * proc_control_node_B.t65 +
          proc_control_node_B.fcn2 * proc_control_node_B.t70) +
          proc_control_node_B.Merge_a * -proc_control_node_B.t29 *
          proc_control_node_B.t65) + proc_control_node_B.fcn4_g *
          proc_control_node_B.t70;
        proc_control_node_B.Product3_gb = proc_control_node_B.constValues[40] *
          -proc_control_node_B.t13;
        proc_control_node_B.fcn5_e = proc_control_node_B.constValues[18] *
          proc_control_node_B.constValues[40] * proc_control_node_B.t29;
        proc_control_node_B.rtb_Gain3_m[4] = ((proc_control_node_B.Product3_gb *
          proc_control_node_B.t70 + proc_control_node_B.constValues[40] *
          -proc_control_node_B.t15 * proc_control_node_B.t25) +
          proc_control_node_B.fcn5_e * proc_control_node_B.t70) +
          proc_control_node_B.Merge_a * proc_control_node_B.t29 *
          proc_control_node_B.t25;
        proc_control_node_B.rtb_Gain3_m[5] = ((proc_control_node_B.fcn2 *
          proc_control_node_B.t25 + proc_control_node_B.Product3_gb *
          proc_control_node_B.t65) + proc_control_node_B.fcn5_e *
          proc_control_node_B.t65) + proc_control_node_B.fcn4_g *
          proc_control_node_B.t25;
        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 6;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.constValues_c[proc_control_node_B.ibmat] =
            (proc_control_node_B.a__4[proc_control_node_B.ibmat] +
             proc_control_node_B.Gain_k[proc_control_node_B.ibmat]) +
            proc_control_node_B.rtb_Gain3_m[proc_control_node_B.ibmat];
        }

        // MATLABSystem: '<S109>/MATLAB System' incorporates:
        //   Merge: '<S11>/Merge'
        //   Selector: '<S109>/Selector'

        memset(&proc_control_node_B.MATLABSystem[0], 0, sizeof(real_T) << 3U);
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 6;
             proc_control_node_B.ixlast++) {
          for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
               proc_control_node_B.ibmat++) {
            proc_control_node_B.MATLABSystem[proc_control_node_B.ibmat] +=
              proc_control_node_DW.obj_m.binv[proc_control_node_B.ibmat +
              proc_control_node_B.i] *
              proc_control_node_B.constValues_c[proc_control_node_B.ixlast];
          }

          proc_control_node_B.i += 8;
        }
        break;

       case 21U:
        //  Open loop matrice b invese directe
        memset(&proc_control_node_B.u_scale[0], 0, sizeof(real_T) << 3U);
        proc_control_node_B.i = 0;
        proc_control_node_B.ixlast = 0;
        for (proc_control_node_B.dCoefs_tmp = 0; proc_control_node_B.dCoefs_tmp <
             6; proc_control_node_B.dCoefs_tmp++) {
          for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
               proc_control_node_B.ibmat++) {
            proc_control_node_B.u_scale[proc_control_node_B.ibmat] +=
              proc_control_node_DW.obj_m.binv[proc_control_node_B.ibmat +
              proc_control_node_B.i] *
              proc_control_node_B.Quaternion[proc_control_node_B.ixlast + 70];
          }

          proc_control_node_B.i += 8;
          proc_control_node_B.ixlast += 10;
        }

        // MATLABSystem: '<S109>/MATLAB System' incorporates:
        //   Merge: '<S11>/Merge'
        //   Selector: '<S109>/Selector'

        for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
             proc_control_node_B.ibmat++) {
          proc_control_node_B.MATLABSystem[proc_control_node_B.ibmat] =
            proc_control_node_B.u_scale[proc_control_node_B.ibmat] *
            proc_control_node_DW.obj_m.k;
        }
        break;

       default:
        // MATLABSystem: '<S109>/MATLAB System'
        memset(&proc_control_node_B.MATLABSystem[0], 0, sizeof(real_T) << 3U);
        break;
      }

      // End of MATLABSystem: '<S109>/MATLAB System'
      // Merge: '<S9>/Merge' incorporates:
      //   MATLABSystem: '<S109>/MATLAB System'
      //   SignalConversion generated from: '<S109>/Out1'

      memcpy(&proc_control_node_B.Merge[0], &proc_control_node_B.MATLABSystem[0],
             sizeof(real_T) << 3U);

      // Update for UnitDelay: '<S111>/UD' incorporates:
      //   SampleTimeMath: '<S111>/TSamp'
      //
      //  About '<S111>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      //  Block description for '<S111>/UD':
      //
      //   Store in Global RAM

      for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
           proc_control_node_B.i++) {
        proc_control_node_DW.UD_DSTATE[proc_control_node_B.i] =
          proc_control_node_B.Gain3[proc_control_node_B.i];
      }

      // End of Update for UnitDelay: '<S111>/UD'
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S9>/JoyStick OpenLoop'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S9>/IDLE' incorporates:
      //   ActionPort: '<S108>/Action Port'

      // Merge: '<S9>/Merge' incorporates:
      //   Constant: '<S108>/Constant1'
      //   SignalConversion generated from: '<S108>/Out1'

      memcpy(&proc_control_node_B.Merge[0],
             &proc_control_node_P.Constant1_Value[0], sizeof(real_T) << 3U);
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IDLE_SubsysRanBC);
      }

      // End of Outputs for SubSystem: '<S9>/IDLE'
      break;
    }

    // End of SwitchCase: '<S9>/Switch Case'

    // Saturate: '<S9>/Saturation'
    for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
         proc_control_node_B.ibmat++) {
      proc_control_node_B.Product3_gb =
        proc_control_node_B.Merge[proc_control_node_B.ibmat];
      if (proc_control_node_B.Product3_gb > proc_control_node_P.MPC.tmax) {
        proc_control_node_B.twpt[proc_control_node_B.ibmat] =
          proc_control_node_P.MPC.tmax;
      } else if (proc_control_node_B.Product3_gb < proc_control_node_P.MPC.tmin)
      {
        proc_control_node_B.twpt[proc_control_node_B.ibmat] =
          proc_control_node_P.MPC.tmin;
      } else {
        proc_control_node_B.twpt[proc_control_node_B.ibmat] =
          proc_control_node_B.Product3_gb;
      }
    }

    // End of Saturate: '<S9>/Saturation'

    // Lookup_n-D: '<S9>/N to PWM'
    for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
         proc_control_node_B.ibmat++) {
      proc_control_node_B.bpIdx = plook_u32d_binckpang
        (proc_control_node_B.twpt[proc_control_node_B.ibmat],
         proc_control_node_P.N, 200U,
         &proc_control_node_DW.m_bpIndex[proc_control_node_B.ibmat]);
      proc_control_node_B.NtoPWM[proc_control_node_B.ibmat] =
        proc_control_node_P.PWM[proc_control_node_B.bpIdx];
    }

    // MATLAB Function: '<S12>/Quaternion Normalise' incorporates:
    //   SignalConversion generated from: '<S223>/ SFunction '

    proc_control_node_B.fcn2 = 3.3121686421112381E-170;
    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1_n.Orientation.W);
    if (proc_control_node_B.fcn4_g > 3.3121686421112381E-170) {
      proc_control_node_B.Merge_a = 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        3.3121686421112381E-170;
      proc_control_node_B.Merge_a = proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1_n.Orientation.X);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1_n.Orientation.Y);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_B.In1_n.Orientation.Z);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.Merge_a = proc_control_node_B.fcn2 * sqrt
      (proc_control_node_B.Merge_a);
    proc_control_node_B.y[0] = proc_control_node_B.In1_n.Orientation.W /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[0] = rtIsNaN(proc_control_node_B.y[0]);
    proc_control_node_B.y[1] = proc_control_node_B.In1_n.Orientation.X /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[1] = rtIsNaN(proc_control_node_B.y[1]);
    proc_control_node_B.y[2] = proc_control_node_B.In1_n.Orientation.Y /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[2] = rtIsNaN(proc_control_node_B.y[2]);
    proc_control_node_B.y[3] = proc_control_node_B.In1_n.Orientation.Z /
      proc_control_node_B.Merge_a;
    proc_control_node_B.b_e[3] = rtIsNaN(proc_control_node_B.y[3]);
    proc_control_node_B.y_ft = true;
    proc_control_node_B.ibmat = 0;
    exitg1 = false;
    while ((!exitg1) && (proc_control_node_B.ibmat < 4)) {
      if (!proc_control_node_B.b_e[proc_control_node_B.ibmat]) {
        proc_control_node_B.y_ft = false;
        exitg1 = true;
      } else {
        proc_control_node_B.ibmat++;
      }
    }

    if (proc_control_node_B.y_ft) {
      proc_control_node_B.y[0] = 1.0;
      proc_control_node_B.y[1] = 0.0;
      proc_control_node_B.y[2] = 0.0;
      proc_control_node_B.y[3] = 0.0;
    }

    // End of MATLAB Function: '<S12>/Quaternion Normalise'

    // Outputs for Atomic SubSystem: '<S12>/Subscribe1'
    // MATLABSystem: '<S225>/SourceBlock'
    proc_control_node_B.y_ft = Sub_proc_control_node_203.getLatestMessage
      (&proc_control_node_B.b_varargout_2_j);

    // Outputs for Enabled SubSystem: '<S225>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S231>/Enable'

    // Switch: '<S229>/Reset' incorporates:
    //   MATLABSystem: '<S225>/SourceBlock'

    if (proc_control_node_B.y_ft) {
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC_kg);

      // Switch: '<S229>/Reset' incorporates:
      //   Constant: '<S229>/Initial Condition'

      proc_control_node_B.Reset =
        proc_control_node_P.MinMaxRunningResettable_vinit;
    } else {
      // Switch: '<S229>/Reset' incorporates:
      //   Memory: '<S229>/Memory'
      //   MinMax: '<S222>/MinMax'

      proc_control_node_B.Reset = (proc_control_node_B.SourceBlock_o1_a ||
        proc_control_node_DW.Memory_PreviousInput);
    }

    // End of Switch: '<S229>/Reset'
    // End of Outputs for SubSystem: '<S225>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S12>/Subscribe1'

    // Outputs for Enabled SubSystem: '<Root>/Modèle Physique' incorporates:
    //   EnablePort: '<S1>/Enable'

    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      proc_control_node_DW.ModlePhysique_MODE = proc_control_node_B.Reset;
    }

    // End of Outputs for SubSystem: '<Root>/Modèle Physique'
  }

  // Outputs for Enabled SubSystem: '<Root>/Modèle Physique' incorporates:
  //   EnablePort: '<S1>/Enable'

  if (proc_control_node_DW.ModlePhysique_MODE) {
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
      // MATLAB Function: '<S1>/MATLAB Function'
      for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
           proc_control_node_B.i++) {
        proc_control_node_B.rtb_y_f_h =
          proc_control_node_B.NtoPWM[proc_control_node_B.i];
        if (proc_control_node_B.rtb_y_f_h < 1100) {
          proc_control_node_B.rtb_y_f_h = 1500U;
        } else if (proc_control_node_B.rtb_y_f_h > 1900) {
          proc_control_node_B.rtb_y_f_h = 1500U;
        }

        proc_control_node_B.y_f[proc_control_node_B.i] =
          proc_control_node_B.rtb_y_f_h;
      }

      // End of MATLAB Function: '<S1>/MATLAB Function'

      // Lookup_n-D: '<S15>/ PWM to N'
      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.bpIdx = plook_u32u16_binckpan
          (proc_control_node_B.y_f[proc_control_node_B.ibmat],
           proc_control_node_P.PWM, 200U,
           &proc_control_node_DW.m_bpIndex_m[proc_control_node_B.ibmat]);
        proc_control_node_B.PWMtoN[proc_control_node_B.ibmat] =
          proc_control_node_P.N[proc_control_node_B.bpIdx];
      }

      // Lookup_n-D: '<S15>/N to RPM'
      for (proc_control_node_B.ibmat = 0; proc_control_node_B.ibmat < 8;
           proc_control_node_B.ibmat++) {
        proc_control_node_B.bpIdx = plook_u32d_binckpan
          (proc_control_node_B.PWMtoN[proc_control_node_B.ibmat],
           proc_control_node_P.N, 200U,
           &proc_control_node_DW.m_bpIndex_c[proc_control_node_B.ibmat]);
        proc_control_node_B.Merge_a =
          proc_control_node_P.RPM[proc_control_node_B.bpIdx];
        if (proc_control_node_B.Merge_a < 0.0) {
          proc_control_node_B.rtb_Sum_tmp = ceil(proc_control_node_B.Merge_a);
        } else {
          proc_control_node_B.rtb_Sum_tmp = floor(proc_control_node_B.Merge_a);
        }

        if (rtIsNaN(proc_control_node_B.rtb_Sum_tmp) || rtIsInf
            (proc_control_node_B.rtb_Sum_tmp)) {
          proc_control_node_B.rtb_Sum_tmp = 0.0;
        } else {
          proc_control_node_B.rtb_Sum_tmp = fmod(proc_control_node_B.rtb_Sum_tmp,
            65536.0);
        }

        proc_control_node_B.NtoRPM[proc_control_node_B.ibmat] =
          static_cast<uint16_T>(proc_control_node_B.rtb_Sum_tmp < 0.0 ?
          static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>(-proc_control_node_B.rtb_Sum_tmp)))) :
          static_cast<int32_T>(static_cast<uint16_T>
          (proc_control_node_B.rtb_Sum_tmp)));
      }
    }

    // Integrator: '<S1>/Integrator1'
    proc_control_node_B.SourceBlock_o1_a = rtsiGetIsOkayToUpdateMode
      (&proc_control_node_M->solverInfo);
    if (proc_control_node_B.SourceBlock_o1_a) {
      proc_control_node_B.SourceBlock_o1_a = (proc_control_node_B.OR &&
        (proc_control_node_PrevZCX.Integrator1_Reset_ZCE != 1));
      proc_control_node_PrevZCX.Integrator1_Reset_ZCE = proc_control_node_B.OR;

      // evaluate zero-crossings
      if (proc_control_node_B.SourceBlock_o1_a ||
          (proc_control_node_DW.Integrator1_IWORK != 0)) {
        proc_control_node_X.Integrator1_CSTATE[0] = proc_control_node_B.y[0];
        proc_control_node_X.Integrator1_CSTATE[1] = proc_control_node_B.y[1];
        proc_control_node_X.Integrator1_CSTATE[2] = proc_control_node_B.y[2];
        proc_control_node_X.Integrator1_CSTATE[3] = proc_control_node_B.y[3];
      }
    }

    // MATLAB Function: '<S1>/Quaternion Normalise' incorporates:
    //   Integrator: '<S1>/Integrator1'

    proc_control_node_B.fcn2 = 3.3121686421112381E-170;
    proc_control_node_B.fcn4_g = fabs(proc_control_node_X.Integrator1_CSTATE[0]);
    if (proc_control_node_B.fcn4_g > 3.3121686421112381E-170) {
      proc_control_node_B.Merge_a = 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        3.3121686421112381E-170;
      proc_control_node_B.Merge_a = proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_X.Integrator1_CSTATE[1]);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_X.Integrator1_CSTATE[2]);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.fcn4_g = fabs(proc_control_node_X.Integrator1_CSTATE[3]);
    if (proc_control_node_B.fcn4_g > proc_control_node_B.fcn2) {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn2 /
        proc_control_node_B.fcn4_g;
      proc_control_node_B.Merge_a = proc_control_node_B.Merge_a *
        proc_control_node_B.Product3_gb * proc_control_node_B.Product3_gb + 1.0;
      proc_control_node_B.fcn2 = proc_control_node_B.fcn4_g;
    } else {
      proc_control_node_B.Product3_gb = proc_control_node_B.fcn4_g /
        proc_control_node_B.fcn2;
      proc_control_node_B.Merge_a += proc_control_node_B.Product3_gb *
        proc_control_node_B.Product3_gb;
    }

    proc_control_node_B.Merge_a = proc_control_node_B.fcn2 * sqrt
      (proc_control_node_B.Merge_a);
    proc_control_node_B.y_gh[0] = proc_control_node_X.Integrator1_CSTATE[0] /
      proc_control_node_B.Merge_a;
    proc_control_node_B.y_gh[1] = proc_control_node_X.Integrator1_CSTATE[1] /
      proc_control_node_B.Merge_a;
    proc_control_node_B.y_gh[2] = proc_control_node_X.Integrator1_CSTATE[2] /
      proc_control_node_B.Merge_a;
    proc_control_node_B.y_gh[3] = proc_control_node_X.Integrator1_CSTATE[3] /
      proc_control_node_B.Merge_a;

    // End of MATLAB Function: '<S1>/Quaternion Normalise'

    // TransferFcn: '<S20>/Transfer Fcn'
    proc_control_node_B.Product3_gb = proc_control_node_P.TransferFcn_C *
      proc_control_node_X.TransferFcn_CSTATE;

    // TransferFcn: '<S21>/Transfer Fcn'
    proc_control_node_B.fcn5_e = proc_control_node_P.TransferFcn_C_m *
      proc_control_node_X.TransferFcn_CSTATE_o;

    // TransferFcn: '<S22>/Transfer Fcn'
    proc_control_node_B.Product1_fh = proc_control_node_P.TransferFcn_C_l *
      proc_control_node_X.TransferFcn_CSTATE_p;

    // TransferFcn: '<S23>/Transfer Fcn'
    proc_control_node_B.Product2_ei = proc_control_node_P.TransferFcn_C_f *
      proc_control_node_X.TransferFcn_CSTATE_a;

    // TransferFcn: '<S24>/Transfer Fcn'
    proc_control_node_B.t15 = proc_control_node_P.TransferFcn_C_n *
      proc_control_node_X.TransferFcn_CSTATE_f;

    // TransferFcn: '<S25>/Transfer Fcn'
    proc_control_node_B.t25 = proc_control_node_P.TransferFcn_C_nr *
      proc_control_node_X.TransferFcn_CSTATE_e;

    // TransferFcn: '<S26>/Transfer Fcn'
    proc_control_node_B.t29 = proc_control_node_P.TransferFcn_C_h *
      proc_control_node_X.TransferFcn_CSTATE_ft;

    // TransferFcn: '<S27>/Transfer Fcn'
    proc_control_node_B.t65 = proc_control_node_P.TransferFcn_C_fa *
      proc_control_node_X.TransferFcn_CSTATE_fu;
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[5] == 0) {
      // UniformRandomNumber: '<S16>/X Drift'
      proc_control_node_B.XDrift = proc_control_node_DW.XDrift_NextOutput;

      // UniformRandomNumber: '<S16>/Y Drift'
      proc_control_node_B.YDrift = proc_control_node_DW.YDrift_NextOutput;
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Constant: '<S16>/Z Drift'
      proc_control_node_B.ZDrift = proc_control_node_P.ZDrift_Value;
    }

    // Sin: '<S16>/X Wave' incorporates:
    //   Sin: '<S16>/Pitch Wave'
    //   Sin: '<S16>/Roll Wave'
    //   Sin: '<S16>/Y Wave'
    //   Sin: '<S16>/Yaw Wave'
    //   Sin: '<S16>/Z Wave'

    proc_control_node_B.fcn4_g = proc_control_node_M->Timing.t[0];

    // Sin: '<S16>/X Wave'
    proc_control_node_B.XWave = sin(proc_control_node_P.wfX *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpX) *
      proc_control_node_P.waX + proc_control_node_P.XWave_Bias;

    // Sin: '<S16>/Y Wave'
    proc_control_node_B.YWave = sin(proc_control_node_P.wfY *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpY) *
      proc_control_node_P.waY + proc_control_node_P.YWave_Bias;

    // Sin: '<S16>/Z Wave'
    proc_control_node_B.ZWave = sin(proc_control_node_P.wfZ *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpZ) *
      proc_control_node_P.waZ + proc_control_node_P.ZWave_Bias;

    // Sum: '<S16>/Sum2'
    proc_control_node_B.t70 = proc_control_node_B.XDrift;
    proc_control_node_B.t13 = proc_control_node_B.YDrift;
    proc_control_node_B.rtb_Sum_tmp = proc_control_node_B.ZDrift;
    proc_control_node_B.t14 = proc_control_node_B.XWave;
    proc_control_node_B.t65_tmp = proc_control_node_B.YWave;
    proc_control_node_B.t65_tmp_o = proc_control_node_B.ZWave;

    // Sin: '<S16>/Roll Wave'
    proc_control_node_B.Merge_a = sin(proc_control_node_P.wfPhi *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpPhi) *
      proc_control_node_P.waPhi + proc_control_node_P.RollWave_Bias;

    // Sin: '<S16>/Pitch Wave'
    proc_control_node_B.fcn2 = sin(proc_control_node_P.wfTheta *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpTheta) *
      proc_control_node_P.waTheta + proc_control_node_P.PitchWave_Bias;

    // Sin: '<S16>/Yaw Wave'
    proc_control_node_B.fcn4_g = sin(proc_control_node_P.wfPsi *
      proc_control_node_B.fcn4_g + proc_control_node_P.wpPsi) *
      proc_control_node_P.waPsi + proc_control_node_P.YawWave_Bias;

    // SignalConversion generated from: '<S1>/Integrator'
    proc_control_node_B.c_c[0] = proc_control_node_B.In1_n.Position.X;
    proc_control_node_B.c_c[1] = proc_control_node_B.In1_n.Position.Y;
    proc_control_node_B.c_c[2] = proc_control_node_B.In1_n.Position.Z;

    // Integrator: '<S1>/Integrator'
    proc_control_node_B.SourceBlock_o1_a = rtsiGetIsOkayToUpdateMode
      (&proc_control_node_M->solverInfo);
    if (proc_control_node_B.SourceBlock_o1_a) {
      proc_control_node_B.SourceBlock_o1_a = (proc_control_node_B.OR &&
        (proc_control_node_PrevZCX.Integrator_Reset_ZCE != 1));
      proc_control_node_PrevZCX.Integrator_Reset_ZCE = proc_control_node_B.OR;

      // evaluate zero-crossings
      if (proc_control_node_B.SourceBlock_o1_a ||
          (proc_control_node_DW.Integrator_IWORK != 0)) {
        proc_control_node_X.Integrator_CSTATE[0] = proc_control_node_B.c_c[0];
        proc_control_node_X.Integrator_CSTATE[1] = proc_control_node_B.c_c[1];
        proc_control_node_X.Integrator_CSTATE[2] = proc_control_node_B.c_c[2];
      }
    }

    // Integrator: '<S1>/Integrator'
    proc_control_node_B.WorldPosition_d[0] =
      proc_control_node_X.Integrator_CSTATE[0];
    proc_control_node_B.WorldPosition_d[1] =
      proc_control_node_X.Integrator_CSTATE[1];
    proc_control_node_B.WorldPosition_d[2] =
      proc_control_node_X.Integrator_CSTATE[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Constant: '<S1>/Initial Body velocity '
      proc_control_node_B.InitialBodyvelocity[0] =
        proc_control_node_P.InitialBodyvelocity_Value[0];
      proc_control_node_B.InitialBodyvelocity[1] =
        proc_control_node_P.InitialBodyvelocity_Value[1];
      proc_control_node_B.InitialBodyvelocity[2] =
        proc_control_node_P.InitialBodyvelocity_Value[2];
    }

    // Integrator: '<S1>/Integrator2'
    proc_control_node_B.SourceBlock_o1_a = rtsiGetIsOkayToUpdateMode
      (&proc_control_node_M->solverInfo);
    if (proc_control_node_B.SourceBlock_o1_a) {
      proc_control_node_B.SourceBlock_o1_a = (proc_control_node_B.OR &&
        (proc_control_node_PrevZCX.Integrator2_Reset_ZCE != 1));
      proc_control_node_PrevZCX.Integrator2_Reset_ZCE = proc_control_node_B.OR;

      // evaluate zero-crossings
      if (proc_control_node_B.SourceBlock_o1_a ||
          (proc_control_node_DW.Integrator2_IWORK != 0)) {
        proc_control_node_X.Integrator2_CSTATE[0] =
          proc_control_node_B.InitialBodyvelocity[0];
        proc_control_node_X.Integrator2_CSTATE[1] =
          proc_control_node_B.InitialBodyvelocity[1];
        proc_control_node_X.Integrator2_CSTATE[2] =
          proc_control_node_B.InitialBodyvelocity[2];
      }
    }

    // Integrator: '<S1>/Integrator2'
    proc_control_node_B.BodyVelocity_c[0] =
      proc_control_node_X.Integrator2_CSTATE[0];
    proc_control_node_B.BodyVelocity_c[1] =
      proc_control_node_X.Integrator2_CSTATE[1];
    proc_control_node_B.BodyVelocity_c[2] =
      proc_control_node_X.Integrator2_CSTATE[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Constant: '<S1>/Initial Angular Rates'
      proc_control_node_B.InitialAngularRates[0] =
        proc_control_node_P.InitialAngularRates_Value[0];
      proc_control_node_B.InitialAngularRates[1] =
        proc_control_node_P.InitialAngularRates_Value[1];
      proc_control_node_B.InitialAngularRates[2] =
        proc_control_node_P.InitialAngularRates_Value[2];
    }

    // Integrator: '<S1>/Integrator3'
    proc_control_node_B.SourceBlock_o1_a = rtsiGetIsOkayToUpdateMode
      (&proc_control_node_M->solverInfo);
    if (proc_control_node_B.SourceBlock_o1_a) {
      proc_control_node_B.SourceBlock_o1_a = (proc_control_node_B.OR &&
        (proc_control_node_PrevZCX.Integrator3_Reset_ZCE != 1));
      proc_control_node_PrevZCX.Integrator3_Reset_ZCE = proc_control_node_B.OR;

      // evaluate zero-crossings
      if (proc_control_node_B.SourceBlock_o1_a ||
          (proc_control_node_DW.Integrator3_IWORK != 0)) {
        proc_control_node_X.Integrator3_CSTATE[0] =
          proc_control_node_B.InitialAngularRates[0];
        proc_control_node_X.Integrator3_CSTATE[1] =
          proc_control_node_B.InitialAngularRates[1];
        proc_control_node_X.Integrator3_CSTATE[2] =
          proc_control_node_B.InitialAngularRates[2];
      }
    }

    // Integrator: '<S1>/Integrator3'
    proc_control_node_B.AngularRate_e[0] =
      proc_control_node_X.Integrator3_CSTATE[0];
    proc_control_node_B.AngularRate_e[1] =
      proc_control_node_X.Integrator3_CSTATE[1];
    proc_control_node_B.AngularRate_e[2] =
      proc_control_node_X.Integrator3_CSTATE[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'

      proc_control_node_B.dv6[0] = proc_control_node_B.WorldPosition_d[0];
      proc_control_node_B.dv6[1] = proc_control_node_B.WorldPosition_d[1];
      proc_control_node_B.dv6[2] = proc_control_node_B.WorldPosition_d[2];
      proc_control_node_B.dv6[3] = proc_control_node_B.y_gh[0];
      proc_control_node_B.dv6[4] = proc_control_node_B.y_gh[1];
      proc_control_node_B.dv6[5] = proc_control_node_B.y_gh[2];
      proc_control_node_B.dv6[6] = proc_control_node_B.y_gh[3];
      proc_control_node_B.dv6[7] = proc_control_node_B.BodyVelocity_c[0];
      proc_control_node_B.dv6[10] = proc_control_node_B.AngularRate_e[0];

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'
      //   Sum: '<S16>/Sum2'

      proc_control_node_B.Gain3[0] = proc_control_node_B.t70 +
        proc_control_node_B.t14;

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'

      proc_control_node_B.dv6[8] = proc_control_node_B.BodyVelocity_c[1];
      proc_control_node_B.dv6[11] = proc_control_node_B.AngularRate_e[1];

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'
      //   Sum: '<S16>/Sum2'

      proc_control_node_B.Gain3[1] = proc_control_node_B.t13 +
        proc_control_node_B.t65_tmp;

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'

      proc_control_node_B.dv6[9] = proc_control_node_B.BodyVelocity_c[2];
      proc_control_node_B.dv6[12] = proc_control_node_B.AngularRate_e[2];

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'
      //   Sum: '<S16>/Sum2'

      proc_control_node_B.Gain3[2] = proc_control_node_B.rtb_Sum_tmp +
        proc_control_node_B.t65_tmp_o;
      proc_control_node_B.Gain3[3] = proc_control_node_B.Merge_a;
      proc_control_node_B.Gain3[4] = proc_control_node_B.fcn2;
      proc_control_node_B.Gain3[5] = proc_control_node_B.fcn4_g;

      // SignalConversion generated from: '<S13>/ SFunction ' incorporates:
      //   MATLAB Function: '<S1>/AUV State Equation'

      proc_control_node_B.twpt[0] = proc_control_node_B.Product3_gb;
      proc_control_node_B.twpt[1] = proc_control_node_B.fcn5_e;
      proc_control_node_B.twpt[2] = proc_control_node_B.Product1_fh;
      proc_control_node_B.twpt[3] = proc_control_node_B.Product2_ei;
      proc_control_node_B.twpt[4] = proc_control_node_B.t15;
      proc_control_node_B.twpt[5] = proc_control_node_B.t25;
      proc_control_node_B.twpt[6] = proc_control_node_B.t29;
      proc_control_node_B.twpt[7] = proc_control_node_B.t65;

      // MATLAB Function: '<S1>/AUV State Equation'
      proc_con_AUVQuatPerturbedSimFcn(proc_control_node_B.dv6,
        proc_control_node_B.Gain3, proc_control_node_B.twpt,
        proc_control_node_B.TmpSignalConversionAtTran_a);
      proc_control_node_B.Position_dot[0] =
        proc_control_node_B.TmpSignalConversionAtTran_a[0];
      proc_control_node_B.Position_dot[1] =
        proc_control_node_B.TmpSignalConversionAtTran_a[1];
      proc_control_node_B.Position_dot[2] =
        proc_control_node_B.TmpSignalConversionAtTran_a[2];
      proc_control_node_B.Quaternion_dot[0] =
        proc_control_node_B.TmpSignalConversionAtTran_a[3];
      proc_control_node_B.Quaternion_dot[1] =
        proc_control_node_B.TmpSignalConversionAtTran_a[4];
      proc_control_node_B.Quaternion_dot[2] =
        proc_control_node_B.TmpSignalConversionAtTran_a[5];
      proc_control_node_B.Quaternion_dot[3] =
        proc_control_node_B.TmpSignalConversionAtTran_a[6];
      proc_control_node_B.BodyVelocity_dot[0] =
        proc_control_node_B.TmpSignalConversionAtTran_a[7];
      proc_control_node_B.AngularRates_dot[0] =
        proc_control_node_B.TmpSignalConversionAtTran_a[10];
      proc_control_node_B.BodyVelocity_dot[1] =
        proc_control_node_B.TmpSignalConversionAtTran_a[8];
      proc_control_node_B.AngularRates_dot[1] =
        proc_control_node_B.TmpSignalConversionAtTran_a[11];
      proc_control_node_B.BodyVelocity_dot[2] =
        proc_control_node_B.TmpSignalConversionAtTran_a[9];
      proc_control_node_B.AngularRates_dot[2] =
        proc_control_node_B.TmpSignalConversionAtTran_a[12];
    }

    // Product: '<S44>/Product' incorporates:
    //   Product: '<S35>/Product'

    proc_control_node_B.Merge_a = proc_control_node_B.y_gh[0] *
      proc_control_node_B.y_gh[0];

    // Sum: '<S44>/Sum' incorporates:
    //   Product: '<S44>/Product'
    //   Product: '<S44>/Product1'
    //   Product: '<S44>/Product2'
    //   Product: '<S44>/Product3'

    proc_control_node_B.Product3_gb = ((proc_control_node_B.Merge_a +
      proc_control_node_B.y_gh[1] * proc_control_node_B.y_gh[1]) +
      proc_control_node_B.y_gh[2] * proc_control_node_B.y_gh[2]) +
      proc_control_node_B.y_gh[3] * proc_control_node_B.y_gh[3];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Math: '<S19>/Transpose2' incorporates:
      //   Product: '<S42>/Divide'
      //   Product: '<S42>/Divide1'
      //   Product: '<S42>/Divide2'
      //   Product: '<S42>/Divide3'
      //   UnaryMinus: '<S43>/Unary Minus'
      //   UnaryMinus: '<S43>/Unary Minus1'
      //   UnaryMinus: '<S43>/Unary Minus2'

      proc_control_node_B.Transpose2[0] = proc_control_node_B.y_gh[0] /
        proc_control_node_B.Product3_gb;
      proc_control_node_B.Transpose2[1] = -proc_control_node_B.y_gh[1] /
        proc_control_node_B.Product3_gb;
      proc_control_node_B.Transpose2[2] = -proc_control_node_B.y_gh[2] /
        proc_control_node_B.Product3_gb;
      proc_control_node_B.Transpose2[3] = -proc_control_node_B.y_gh[3] /
        proc_control_node_B.Product3_gb;

      // RandomNumber: '<S28>/White Noise'
      proc_control_node_B.Product_h = proc_control_node_DW.NextOutput;

      // Gain: '<S28>/Output' incorporates:
      //   RandomNumber: '<S28>/White Noise'

      proc_control_node_B.Output = sqrt
        (proc_control_node_P.BandLimitedWhiteNoise_Cov) / 0.12909944487358055 *
        proc_control_node_DW.NextOutput;

      // Math: '<S19>/Transpose'
      proc_control_node_B.Transpose_k[0] = proc_control_node_B.BodyVelocity_dot
        [0];
      proc_control_node_B.Transpose_k[1] = proc_control_node_B.BodyVelocity_dot
        [1];
      proc_control_node_B.Transpose_k[2] = proc_control_node_B.BodyVelocity_dot
        [2];
    }

    // Sum: '<S35>/Sum' incorporates:
    //   Product: '<S35>/Product1'
    //   Product: '<S35>/Product2'
    //   Product: '<S35>/Product3'
    //   UnaryMinus: '<S31>/Unary Minus'
    //   UnaryMinus: '<S31>/Unary Minus1'
    //   UnaryMinus: '<S31>/Unary Minus2'

    proc_control_node_B.Product3_gb = ((proc_control_node_B.Merge_a +
      -proc_control_node_B.y_gh[1] * -proc_control_node_B.y_gh[1]) +
      -proc_control_node_B.y_gh[2] * -proc_control_node_B.y_gh[2]) +
      -proc_control_node_B.y_gh[3] * -proc_control_node_B.y_gh[3];

    // Sum: '<S18>/Sum1' incorporates:
    //   Product: '<S30>/Divide'
    //   Product: '<S30>/Divide1'
    //   Product: '<S30>/Divide2'
    //   Product: '<S30>/Divide3'
    //   UnaryMinus: '<S31>/Unary Minus'
    //   UnaryMinus: '<S31>/Unary Minus1'
    //   UnaryMinus: '<S31>/Unary Minus2'

    proc_control_node_B.Quaternion_k[0] = proc_control_node_B.y_gh[0] /
      proc_control_node_B.Product3_gb + proc_control_node_B.Output;
    proc_control_node_B.Quaternion_k[1] = proc_control_node_B.y_gh[1] /
      proc_control_node_B.Product3_gb + proc_control_node_B.Output;
    proc_control_node_B.Quaternion_k[2] = proc_control_node_B.y_gh[2] /
      proc_control_node_B.Product3_gb + proc_control_node_B.Output;
    proc_control_node_B.Quaternion_k[3] = proc_control_node_B.y_gh[3] /
      proc_control_node_B.Product3_gb + proc_control_node_B.Output;

    // Gain: '<S19>/Gain'
    proc_control_node_B.Gain_d[0] = proc_control_node_P.Gain_Gain *
      proc_control_node_B.AngularRate_e[0];
    proc_control_node_B.Gain_d[1] = proc_control_node_P.Gain_Gain *
      proc_control_node_B.AngularRate_e[1];
    proc_control_node_B.Gain_d[2] = proc_control_node_P.Gain_Gain *
      proc_control_node_B.AngularRate_e[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // MATLABSystem: '<S19>/IMU' incorporates:
      //   Math: '<S19>/Transpose'
      //   Math: '<S19>/Transpose2'
      //   ZeroOrderHold: '<S19>/Zero-Order Hold1'

      if (proc_control_node_DW.obj_c.Temperature !=
          proc_control_node_P.IMU_Temperature) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[31] = true;
        }

        proc_control_node_DW.obj_c.Temperature =
          proc_control_node_P.IMU_Temperature;
      }

      if (!proc_control_node_isequal(proc_control_node_DW.obj_c.MagneticFieldNED,
           proc_control_node_P.IMU_MagneticFieldNED)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[0] = true;
        }

        imuSensor_set_MagneticFieldNED(&proc_control_node_DW.obj_c,
          proc_control_node_P.IMU_MagneticFieldNED);
      }

      if (proc_control_node_DW.obj_c.AccelParamsMeasurementRange !=
          proc_control_node_P.IMU_AccelParamsMeasurementRange) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[3] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsMeasurementRange =
          proc_control_node_P.IMU_AccelParamsMeasurementRange;
      }

      if (proc_control_node_DW.obj_c.AccelParamsResolution !=
          proc_control_node_P.IMU_AccelParamsResolution) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[4] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsResolution =
          proc_control_node_P.IMU_AccelParamsResolution;
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsConstantBias,
           proc_control_node_P.IMU_AccelParamsConstantBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[5] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsConstantBias[0] =
          proc_control_node_P.IMU_AccelParamsConstantBias[0];
        proc_control_node_DW.obj_c.AccelParamsConstantBias[1] =
          proc_control_node_P.IMU_AccelParamsConstantBias[1];
        proc_control_node_DW.obj_c.AccelParamsConstantBias[2] =
          proc_control_node_P.IMU_AccelParamsConstantBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsAxesMisalignment,
           proc_control_node_P.IMU_AccelParamsAxesMisalignment)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[6] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[0] =
          proc_control_node_P.IMU_AccelParamsAxesMisalignment[0];
        proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[1] =
          proc_control_node_P.IMU_AccelParamsAxesMisalignment[1];
        proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[2] =
          proc_control_node_P.IMU_AccelParamsAxesMisalignment[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsNoiseDensity,
           proc_control_node_P.IMU_AccelParamsNoiseDensity)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[7] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsNoiseDensity[0] =
          proc_control_node_P.IMU_AccelParamsNoiseDensity[0];
        proc_control_node_DW.obj_c.AccelParamsNoiseDensity[1] =
          proc_control_node_P.IMU_AccelParamsNoiseDensity[1];
        proc_control_node_DW.obj_c.AccelParamsNoiseDensity[2] =
          proc_control_node_P.IMU_AccelParamsNoiseDensity[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsBiasInstability,
           proc_control_node_P.IMU_AccelParamsBiasInstability)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[8] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsBiasInstability[0] =
          proc_control_node_P.IMU_AccelParamsBiasInstability[0];
        proc_control_node_DW.obj_c.AccelParamsBiasInstability[1] =
          proc_control_node_P.IMU_AccelParamsBiasInstability[1];
        proc_control_node_DW.obj_c.AccelParamsBiasInstability[2] =
          proc_control_node_P.IMU_AccelParamsBiasInstability[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsRandomWalk,
           proc_control_node_P.IMU_AccelParamsRandomWalk)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[9] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsRandomWalk[0] =
          proc_control_node_P.IMU_AccelParamsRandomWalk[0];
        proc_control_node_DW.obj_c.AccelParamsRandomWalk[1] =
          proc_control_node_P.IMU_AccelParamsRandomWalk[1];
        proc_control_node_DW.obj_c.AccelParamsRandomWalk[2] =
          proc_control_node_P.IMU_AccelParamsRandomWalk[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsTemperatureBias,
           proc_control_node_P.IMU_AccelParamsTemperatureBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[10] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsTemperatureBias[0] =
          proc_control_node_P.IMU_AccelParamsTemperatureBias[0];
        proc_control_node_DW.obj_c.AccelParamsTemperatureBias[1] =
          proc_control_node_P.IMU_AccelParamsTemperatureBias[1];
        proc_control_node_DW.obj_c.AccelParamsTemperatureBias[2] =
          proc_control_node_P.IMU_AccelParamsTemperatureBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor,
           proc_control_node_P.IMU_AccelParamsTemperatureScale)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[11] = true;
        }

        proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[0] =
          proc_control_node_P.IMU_AccelParamsTemperatureScale[0];
        proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[1] =
          proc_control_node_P.IMU_AccelParamsTemperatureScale[1];
        proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[2] =
          proc_control_node_P.IMU_AccelParamsTemperatureScale[2];
      }

      if (proc_control_node_DW.obj_c.GyroParamsMeasurementRange !=
          proc_control_node_P.IMU_GyroParamsMeasurementRange) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[12] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsMeasurementRange =
          proc_control_node_P.IMU_GyroParamsMeasurementRange;
      }

      if (proc_control_node_DW.obj_c.GyroParamsResolution !=
          proc_control_node_P.IMU_GyroParamsResolution) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[13] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsResolution =
          proc_control_node_P.IMU_GyroParamsResolution;
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsConstantBias,
           proc_control_node_P.IMU_GyroParamsConstantBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[14] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsConstantBias[0] =
          proc_control_node_P.IMU_GyroParamsConstantBias[0];
        proc_control_node_DW.obj_c.GyroParamsConstantBias[1] =
          proc_control_node_P.IMU_GyroParamsConstantBias[1];
        proc_control_node_DW.obj_c.GyroParamsConstantBias[2] =
          proc_control_node_P.IMU_GyroParamsConstantBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsAxesMisalignment,
           proc_control_node_P.IMU_GyroParamsAxesMisalignment)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[15] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[0] =
          proc_control_node_P.IMU_GyroParamsAxesMisalignment[0];
        proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[1] =
          proc_control_node_P.IMU_GyroParamsAxesMisalignment[1];
        proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[2] =
          proc_control_node_P.IMU_GyroParamsAxesMisalignment[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsAccelerationBias,
           proc_control_node_P.IMU_GyroParamsAccelerationBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[21] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsAccelerationBias[0] =
          proc_control_node_P.IMU_GyroParamsAccelerationBias[0];
        proc_control_node_DW.obj_c.GyroParamsAccelerationBias[1] =
          proc_control_node_P.IMU_GyroParamsAccelerationBias[1];
        proc_control_node_DW.obj_c.GyroParamsAccelerationBias[2] =
          proc_control_node_P.IMU_GyroParamsAccelerationBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsNoiseDensity,
           proc_control_node_P.IMU_GyroParamsNoiseDensity)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[16] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsNoiseDensity[0] =
          proc_control_node_P.IMU_GyroParamsNoiseDensity[0];
        proc_control_node_DW.obj_c.GyroParamsNoiseDensity[1] =
          proc_control_node_P.IMU_GyroParamsNoiseDensity[1];
        proc_control_node_DW.obj_c.GyroParamsNoiseDensity[2] =
          proc_control_node_P.IMU_GyroParamsNoiseDensity[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsBiasInstability,
           proc_control_node_P.IMU_GyroParamsBiasInstability)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[17] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsBiasInstability[0] =
          proc_control_node_P.IMU_GyroParamsBiasInstability[0];
        proc_control_node_DW.obj_c.GyroParamsBiasInstability[1] =
          proc_control_node_P.IMU_GyroParamsBiasInstability[1];
        proc_control_node_DW.obj_c.GyroParamsBiasInstability[2] =
          proc_control_node_P.IMU_GyroParamsBiasInstability[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsRandomWalk,
           proc_control_node_P.IMU_GyroParamsRandomWalk)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[18] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsRandomWalk[0] =
          proc_control_node_P.IMU_GyroParamsRandomWalk[0];
        proc_control_node_DW.obj_c.GyroParamsRandomWalk[1] =
          proc_control_node_P.IMU_GyroParamsRandomWalk[1];
        proc_control_node_DW.obj_c.GyroParamsRandomWalk[2] =
          proc_control_node_P.IMU_GyroParamsRandomWalk[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsTemperatureBias,
           proc_control_node_P.IMU_GyroParamsTemperatureBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[19] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsTemperatureBias[0] =
          proc_control_node_P.IMU_GyroParamsTemperatureBias[0];
        proc_control_node_DW.obj_c.GyroParamsTemperatureBias[1] =
          proc_control_node_P.IMU_GyroParamsTemperatureBias[1];
        proc_control_node_DW.obj_c.GyroParamsTemperatureBias[2] =
          proc_control_node_P.IMU_GyroParamsTemperatureBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor,
           proc_control_node_P.IMU_GyroParamsTemperatureScaleF)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[20] = true;
        }

        proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[0] =
          proc_control_node_P.IMU_GyroParamsTemperatureScaleF[0];
        proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[1] =
          proc_control_node_P.IMU_GyroParamsTemperatureScaleF[1];
        proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[2] =
          proc_control_node_P.IMU_GyroParamsTemperatureScaleF[2];
      }

      if (proc_control_node_DW.obj_c.MagParamsMeasurementRange !=
          proc_control_node_P.IMU_MagParamsMeasurementRange) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[22] = true;
        }

        proc_control_node_DW.obj_c.MagParamsMeasurementRange =
          proc_control_node_P.IMU_MagParamsMeasurementRange;
      }

      if (proc_control_node_DW.obj_c.MagParamsResolution !=
          proc_control_node_P.IMU_MagParamsResolution) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[23] = true;
        }

        proc_control_node_DW.obj_c.MagParamsResolution =
          proc_control_node_P.IMU_MagParamsResolution;
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsConstantBias,
           proc_control_node_P.IMU_MagParamsConstantBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[24] = true;
        }

        proc_control_node_DW.obj_c.MagParamsConstantBias[0] =
          proc_control_node_P.IMU_MagParamsConstantBias[0];
        proc_control_node_DW.obj_c.MagParamsConstantBias[1] =
          proc_control_node_P.IMU_MagParamsConstantBias[1];
        proc_control_node_DW.obj_c.MagParamsConstantBias[2] =
          proc_control_node_P.IMU_MagParamsConstantBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsAxesMisalignment,
           proc_control_node_P.IMU_MagParamsAxesMisalignment)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[25] = true;
        }

        proc_control_node_DW.obj_c.MagParamsAxesMisalignment[0] =
          proc_control_node_P.IMU_MagParamsAxesMisalignment[0];
        proc_control_node_DW.obj_c.MagParamsAxesMisalignment[1] =
          proc_control_node_P.IMU_MagParamsAxesMisalignment[1];
        proc_control_node_DW.obj_c.MagParamsAxesMisalignment[2] =
          proc_control_node_P.IMU_MagParamsAxesMisalignment[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsNoiseDensity,
           proc_control_node_P.IMU_MagParamsNoiseDensity)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[26] = true;
        }

        proc_control_node_DW.obj_c.MagParamsNoiseDensity[0] =
          proc_control_node_P.IMU_MagParamsNoiseDensity[0];
        proc_control_node_DW.obj_c.MagParamsNoiseDensity[1] =
          proc_control_node_P.IMU_MagParamsNoiseDensity[1];
        proc_control_node_DW.obj_c.MagParamsNoiseDensity[2] =
          proc_control_node_P.IMU_MagParamsNoiseDensity[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsBiasInstability,
           proc_control_node_P.IMU_MagParamsBiasInstability)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[27] = true;
        }

        proc_control_node_DW.obj_c.MagParamsBiasInstability[0] =
          proc_control_node_P.IMU_MagParamsBiasInstability[0];
        proc_control_node_DW.obj_c.MagParamsBiasInstability[1] =
          proc_control_node_P.IMU_MagParamsBiasInstability[1];
        proc_control_node_DW.obj_c.MagParamsBiasInstability[2] =
          proc_control_node_P.IMU_MagParamsBiasInstability[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsRandomWalk,
           proc_control_node_P.IMU_MagParamsRandomWalk)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[28] = true;
        }

        proc_control_node_DW.obj_c.MagParamsRandomWalk[0] =
          proc_control_node_P.IMU_MagParamsRandomWalk[0];
        proc_control_node_DW.obj_c.MagParamsRandomWalk[1] =
          proc_control_node_P.IMU_MagParamsRandomWalk[1];
        proc_control_node_DW.obj_c.MagParamsRandomWalk[2] =
          proc_control_node_P.IMU_MagParamsRandomWalk[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsTemperatureBias,
           proc_control_node_P.IMU_MagParamsTemperatureBias)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[29] = true;
        }

        proc_control_node_DW.obj_c.MagParamsTemperatureBias[0] =
          proc_control_node_P.IMU_MagParamsTemperatureBias[0];
        proc_control_node_DW.obj_c.MagParamsTemperatureBias[1] =
          proc_control_node_P.IMU_MagParamsTemperatureBias[1];
        proc_control_node_DW.obj_c.MagParamsTemperatureBias[2] =
          proc_control_node_P.IMU_MagParamsTemperatureBias[2];
      }

      if (!proc_control_node_isequal
          (proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor,
           proc_control_node_P.IMU_MagParamsTemperatureScaleFa)) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_c.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_c.TunablePropsChanged = true;
          proc_control_node_DW.obj_c.tunablePropertyChanged[30] = true;
        }

        proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[0] =
          proc_control_node_P.IMU_MagParamsTemperatureScaleFa[0];
        proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[1] =
          proc_control_node_P.IMU_MagParamsTemperatureScaleFa[1];
        proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[2] =
          proc_control_node_P.IMU_MagParamsTemperatureScaleFa[2];
      }

      proc_control_no_SystemCore_step(&proc_control_node_DW.obj_c,
        proc_control_node_B.Transpose_k, proc_control_node_B.Gain_d,
        proc_control_node_B.Transpose2, proc_control_node_B.c_c,
        proc_control_node_B.b_varargout_2_p, proc_control_node_B.s);

      // MATLABSystem: '<S19>/AHRS' incorporates:
      //   MATLABSystem: '<S19>/IMU'

      if (proc_control_node_DW.obj_l.AccelerometerNoise !=
          proc_control_node_P.AHRS_AccelerometerNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.AccelerometerNoise =
          proc_control_node_P.AHRS_AccelerometerNoise;
      }

      if (proc_control_node_DW.obj_l.GyroscopeNoise !=
          proc_control_node_P.AHRS_GyroscopeNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.GyroscopeNoise =
          proc_control_node_P.AHRS_GyroscopeNoise;
      }

      if (proc_control_node_DW.obj_l.MagnetometerNoise !=
          proc_control_node_P.AHRS_MagnetometerNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.MagnetometerNoise =
          proc_control_node_P.AHRS_MagnetometerNoise;
      }

      if (proc_control_node_DW.obj_l.GyroscopeDriftNoise !=
          proc_control_node_P.AHRS_GyroscopeDriftNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.GyroscopeDriftNoise =
          proc_control_node_P.AHRS_GyroscopeDriftNoise;
      }

      if (proc_control_node_DW.obj_l.LinearAccelerationNoise !=
          proc_control_node_P.AHRS_LinearAccelerationNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.LinearAccelerationNoise =
          proc_control_node_P.AHRS_LinearAccelerationNoise;
      }

      if (proc_control_node_DW.obj_l.MagneticDisturbanceNoise !=
          proc_control_node_P.AHRS_MagneticDisturbanceNoise) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.MagneticDisturbanceNoise =
          proc_control_node_P.AHRS_MagneticDisturbanceNoise;
      }

      if (proc_control_node_DW.obj_l.LinearAccelerationDecayFactor !=
          proc_control_node_P.AHRS_LinearAccelerationDecayFac) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.LinearAccelerationDecayFactor =
          proc_control_node_P.AHRS_LinearAccelerationDecayFac;
      }

      if (proc_control_node_DW.obj_l.MagneticDisturbanceDecayFactor !=
          proc_control_node_P.AHRS_MagneticDisturbanceDecayFa) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.MagneticDisturbanceDecayFactor =
          proc_control_node_P.AHRS_MagneticDisturbanceDecayFa;
      }

      if (proc_control_node_DW.obj_l.ExpectedMagneticFieldStrength !=
          proc_control_node_P.AHRS_ExpectedMagneticFieldStren) {
        proc_control_node_B.SourceBlock_o1_a =
          (proc_control_node_DW.obj_l.isInitialized == 1);
        if (proc_control_node_B.SourceBlock_o1_a) {
          proc_control_node_DW.obj_l.TunablePropsChanged = true;
        }

        proc_control_node_DW.obj_l.ExpectedMagneticFieldStrength =
          proc_control_node_P.AHRS_ExpectedMagneticFieldStren;
      }

      if (proc_control_node_DW.obj_l.TunablePropsChanged) {
        proc_control_node_DW.obj_l.TunablePropsChanged = false;
        proc_control_node_DW.obj_l.pSensorPeriod = 0.016666666666666666;
        proc_control_node_DW.obj_l.pKalmanPeriod =
          proc_control_node_DW.obj_l.pSensorPeriod;
        proc_control_node_B.fcn4_g = proc_control_node_DW.obj_l.pKalmanPeriod;
        proc_control_node_B.Merge_a =
          proc_control_node_DW.obj_l.GyroscopeDriftNoise +
          proc_control_node_DW.obj_l.GyroscopeNoise;
        proc_control_node_B.rtb_sincos_o1_idx_0 = proc_control_node_B.fcn4_g *
          proc_control_node_B.fcn4_g * proc_control_node_B.Merge_a;
        proc_control_node_B.Product_h = proc_control_node_B.rtb_sincos_o1_idx_0
          + (proc_control_node_DW.obj_l.AccelerometerNoise +
             proc_control_node_DW.obj_l.LinearAccelerationNoise);
        proc_control_node_B.Product3_gb =
          proc_control_node_B.rtb_sincos_o1_idx_0 +
          (proc_control_node_DW.obj_l.MagnetometerNoise +
           proc_control_node_DW.obj_l.MagneticDisturbanceNoise);
        memset(&proc_control_node_B.pp_coefs[0], 0, 36U * sizeof(real_T));
        proc_control_node_B.ibmat = 0;
        proc_control_node_B.i = 0;
        for (proc_control_node_B.ixlast = 0; proc_control_node_B.ixlast < 3;
             proc_control_node_B.ixlast++) {
          proc_control_node_B.dCoefs_tmp = tmp_0[proc_control_node_B.ibmat];
          proc_control_node_B.pp_coefs[proc_control_node_B.i] =
            proc_control_node_B.Product_h * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.pp_coefs[proc_control_node_B.i + 21] =
            proc_control_node_B.Product3_gb * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.dCoefs_tmp = tmp_0[proc_control_node_B.ibmat + 1];
          proc_control_node_B.pp_coefs[proc_control_node_B.i + 1] =
            proc_control_node_B.Product_h * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.pp_coefs[proc_control_node_B.i + 22] =
            proc_control_node_B.Product3_gb * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.dCoefs_tmp = tmp_0[proc_control_node_B.ibmat + 2];
          proc_control_node_B.pp_coefs[proc_control_node_B.i + 2] =
            proc_control_node_B.Product_h * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.pp_coefs[proc_control_node_B.i + 23] =
            proc_control_node_B.Product3_gb * static_cast<real_T>
            (proc_control_node_B.dCoefs_tmp);
          proc_control_node_B.ibmat += 3;
          proc_control_node_B.i += 6;
        }

        memcpy(&proc_control_node_DW.obj_l.pQv[0],
               &proc_control_node_B.pp_coefs[0], 36U * sizeof(real_T));
      }

      proc_contro_ahrsfilter_stepImpl(&proc_control_node_DW.obj_l,
        proc_control_node_B.c_c, proc_control_node_B.b_varargout_2_p,
        proc_control_node_B.s, proc_control_node_B.Transpose2,
        proc_control_node_B.Transpose_k);

      // MATLABSystem: '<S19>/AHRS'
      proc_control_node_B.AHRS_o1[0] = proc_control_node_B.Transpose2[0];
      proc_control_node_B.AHRS_o1[1] = proc_control_node_B.Transpose2[1];
      proc_control_node_B.AHRS_o1[2] = proc_control_node_B.Transpose2[2];
      proc_control_node_B.AHRS_o1[3] = proc_control_node_B.Transpose2[3];

      // Gain: '<S29>/Output' incorporates:
      //   RandomNumber: '<S29>/White Noise'

      proc_control_node_B.Output_i = sqrt
        (proc_control_node_P.BandLimitedWhiteNoise1_Cov) / 0.12909944487358055 *
        proc_control_node_DW.NextOutput_b;

      // Gain: '<S33>/1//2' incorporates:
      //   Constant: '<S18>/ y devant Z haut'

      proc_control_node_B.Product_h = proc_control_node_P.u2_Gain *
        proc_control_node_P.ydevantZhaut_Value[0];

      // Trigonometry: '<S33>/sincos'
      proc_control_node_B.rtb_sincos_o1_idx_0 = sin
        (proc_control_node_B.Product_h);
      proc_control_node_B.Product3_gb = cos(proc_control_node_B.Product_h);

      // Gain: '<S33>/1//2' incorporates:
      //   Constant: '<S18>/ y devant Z haut'

      proc_control_node_B.Product_h = proc_control_node_P.u2_Gain *
        proc_control_node_P.ydevantZhaut_Value[1];

      // Trigonometry: '<S33>/sincos'
      proc_control_node_B.fcn5_e = sin(proc_control_node_B.Product_h);
      proc_control_node_B.rtb_sincos_o2_idx_1 = cos
        (proc_control_node_B.Product_h);

      // Gain: '<S33>/1//2' incorporates:
      //   Constant: '<S18>/ y devant Z haut'

      proc_control_node_B.Product_h = proc_control_node_P.u2_Gain *
        proc_control_node_P.ydevantZhaut_Value[2];

      // Trigonometry: '<S33>/sincos'
      proc_control_node_B.rtb_sincos_o1_idx_2 = sin
        (proc_control_node_B.Product_h);
      proc_control_node_B.fcn2 = cos(proc_control_node_B.Product_h);

      // Fcn: '<S33>/q0' incorporates:
      //   Fcn: '<S33>/q3'

      proc_control_node_B.Merge_a = proc_control_node_B.Product3_gb *
        proc_control_node_B.rtb_sincos_o2_idx_1;
      proc_control_node_B.fcn4_g = proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.fcn5_e;
      proc_control_node_B.Product_h = proc_control_node_B.Merge_a *
        proc_control_node_B.fcn2 - proc_control_node_B.fcn4_g *
        proc_control_node_B.rtb_sincos_o1_idx_2;

      // Fcn: '<S33>/q1' incorporates:
      //   Fcn: '<S33>/q2'

      proc_control_node_B.Product3_gb *= proc_control_node_B.fcn5_e;
      proc_control_node_B.rtb_sincos_o2_idx_1 *=
        proc_control_node_B.rtb_sincos_o1_idx_0;
      proc_control_node_B.rtb_sincos_o1_idx_0 = proc_control_node_B.Product3_gb *
        proc_control_node_B.rtb_sincos_o1_idx_2 +
        proc_control_node_B.rtb_sincos_o2_idx_1 * proc_control_node_B.fcn2;

      // Fcn: '<S33>/q2'
      proc_control_node_B.rtb_sincos_o2_idx_1 = proc_control_node_B.Product3_gb *
        proc_control_node_B.fcn2 - proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o1_idx_2;

      // Fcn: '<S33>/q3'
      proc_control_node_B.rtb_sincos_o1_idx_2 = proc_control_node_B.Merge_a *
        proc_control_node_B.rtb_sincos_o1_idx_2 + proc_control_node_B.fcn4_g *
        proc_control_node_B.fcn2;

      // Sqrt: '<S40>/sqrt' incorporates:
      //   Product: '<S41>/Product'
      //   Product: '<S41>/Product1'
      //   Product: '<S41>/Product2'
      //   Product: '<S41>/Product3'
      //   Sum: '<S41>/Sum'

      proc_control_node_B.Product3_gb = sqrt(((proc_control_node_B.Product_h *
        proc_control_node_B.Product_h + proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o1_idx_0) +
        proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o2_idx_1) +
        proc_control_node_B.rtb_sincos_o1_idx_2 *
        proc_control_node_B.rtb_sincos_o1_idx_2);

      // Product: '<S36>/Product'
      proc_control_node_B.Product_h /= proc_control_node_B.Product3_gb;

      // Product: '<S36>/Product3'
      proc_control_node_B.rtb_sincos_o1_idx_2 /= proc_control_node_B.Product3_gb;

      // Product: '<S36>/Product1'
      proc_control_node_B.rtb_sincos_o1_idx_0 /= proc_control_node_B.Product3_gb;

      // Product: '<S36>/Product2'
      proc_control_node_B.rtb_sincos_o2_idx_1 /= proc_control_node_B.Product3_gb;

      // Gain: '<S37>/Gain' incorporates:
      //   Product: '<S37>/Product'
      //   Product: '<S37>/Product1'
      //   Sum: '<S37>/Sum1'

      proc_control_node_B.Gain_c = (proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o2_idx_1 + proc_control_node_B.Product_h *
        proc_control_node_B.rtb_sincos_o1_idx_2) *
        proc_control_node_P.Gain_Gain_j;

      // Gain: '<S37>/Gain1' incorporates:
      //   Product: '<S37>/Product2'
      //   Product: '<S37>/Product3'
      //   Sum: '<S37>/Sum2'

      proc_control_node_B.Gain1 = (proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o1_idx_2 - proc_control_node_B.Product_h *
        proc_control_node_B.rtb_sincos_o2_idx_1) *
        proc_control_node_P.Gain1_Gain;

      // Gain: '<S37>/Gain2' incorporates:
      //   Constant: '<S37>/Constant'
      //   Product: '<S37>/Product6'
      //   Product: '<S37>/Product7'
      //   Sum: '<S37>/Sum3'

      proc_control_node_B.Gain2 = ((proc_control_node_P.Constant_Value_k -
        proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o2_idx_1) -
        proc_control_node_B.rtb_sincos_o1_idx_2 *
        proc_control_node_B.rtb_sincos_o1_idx_2) *
        proc_control_node_P.Gain2_Gain;
    }

    // Sum: '<S18>/Sum3'
    proc_control_node_B.AngularRate_d[0] = proc_control_node_B.Output_i +
      proc_control_node_B.AngularRate_e[0];
    proc_control_node_B.AngularRate_d[1] = proc_control_node_B.Output_i +
      proc_control_node_B.AngularRate_e[1];
    proc_control_node_B.AngularRate_d[2] = proc_control_node_B.Output_i +
      proc_control_node_B.AngularRate_e[2];

    // Sum: '<S37>/Sum' incorporates:
    //   Product: '<S37>/Product4'
    //   Product: '<S37>/Product5'
    //   Product: '<S37>/Product8'

    proc_control_node_B.Sum_d = (proc_control_node_B.BodyVelocity_c[0] *
      proc_control_node_B.Gain2 + proc_control_node_B.Gain_c *
      proc_control_node_B.BodyVelocity_c[1]) + proc_control_node_B.Gain1 *
      proc_control_node_B.BodyVelocity_c[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Gain: '<S38>/Gain' incorporates:
      //   Product: '<S38>/Product'
      //   Product: '<S38>/Product1'
      //   Sum: '<S38>/Sum1'

      proc_control_node_B.Gain_cr = (proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o2_idx_1 - proc_control_node_B.Product_h *
        proc_control_node_B.rtb_sincos_o1_idx_2) *
        proc_control_node_P.Gain_Gain_e;

      // Product: '<S38>/Product3' incorporates:
      //   Product: '<S39>/Product3'

      proc_control_node_B.Merge_a = proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o1_idx_2;

      // Product: '<S38>/Product2' incorporates:
      //   Product: '<S39>/Product2'

      proc_control_node_B.fcn4_g = proc_control_node_B.Product_h *
        proc_control_node_B.rtb_sincos_o1_idx_0;

      // Gain: '<S38>/Gain1' incorporates:
      //   Product: '<S38>/Product2'
      //   Product: '<S38>/Product3'
      //   Sum: '<S38>/Sum2'

      proc_control_node_B.Gain1_d = (proc_control_node_B.fcn4_g +
        proc_control_node_B.Merge_a) * proc_control_node_P.Gain1_Gain_e;

      // Product: '<S38>/Product6' incorporates:
      //   Product: '<S39>/Product6'

      proc_control_node_B.Product3_gb = proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o1_idx_0;

      // Gain: '<S38>/Gain2' incorporates:
      //   Constant: '<S38>/Constant'
      //   Product: '<S38>/Product6'
      //   Product: '<S38>/Product7'
      //   Sum: '<S38>/Sum3'

      proc_control_node_B.Gain2_n = ((proc_control_node_P.Constant_Value_gp -
        proc_control_node_B.Product3_gb) -
        proc_control_node_B.rtb_sincos_o1_idx_2 *
        proc_control_node_B.rtb_sincos_o1_idx_2) *
        proc_control_node_P.Gain2_Gain_l;

      // Gain: '<S39>/Gain' incorporates:
      //   Product: '<S39>/Product'
      //   Product: '<S39>/Product1'
      //   Sum: '<S39>/Sum1'

      proc_control_node_B.Gain_l = (proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o1_idx_2 + proc_control_node_B.Product_h *
        proc_control_node_B.rtb_sincos_o2_idx_1) *
        proc_control_node_P.Gain_Gain_m;

      // Gain: '<S39>/Gain1' incorporates:
      //   Sum: '<S39>/Sum2'

      proc_control_node_B.Gain1_o = (proc_control_node_B.Merge_a -
        proc_control_node_B.fcn4_g) * proc_control_node_P.Gain1_Gain_g;

      // Gain: '<S39>/Gain2' incorporates:
      //   Constant: '<S39>/Constant'
      //   Product: '<S39>/Product7'
      //   Sum: '<S39>/Sum3'

      proc_control_node_B.Gain2_i = ((proc_control_node_P.Constant_Value_i -
        proc_control_node_B.Product3_gb) -
        proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o2_idx_1) *
        proc_control_node_P.Gain2_Gain_b;
    }

    // Sum: '<S38>/Sum' incorporates:
    //   Product: '<S38>/Product4'
    //   Product: '<S38>/Product5'
    //   Product: '<S38>/Product8'

    proc_control_node_B.Sum_i = (proc_control_node_B.BodyVelocity_c[0] *
      proc_control_node_B.Gain_cr + proc_control_node_B.Gain2_n *
      proc_control_node_B.BodyVelocity_c[1]) + proc_control_node_B.Gain1_d *
      proc_control_node_B.BodyVelocity_c[2];

    // Sum: '<S39>/Sum' incorporates:
    //   Product: '<S39>/Product4'
    //   Product: '<S39>/Product5'
    //   Product: '<S39>/Product8'

    proc_control_node_B.Sum_p = (proc_control_node_B.BodyVelocity_c[0] *
      proc_control_node_B.Gain_l + proc_control_node_B.Gain1_o *
      proc_control_node_B.BodyVelocity_c[1]) + proc_control_node_B.Gain2_i *
      proc_control_node_B.BodyVelocity_c[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[5] == 0) {
    }

    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      srUpdateBC(proc_control_node_DW.ModlePhysique_SubsysRanBC);
    }
  }

  // End of Outputs for SubSystem: '<Root>/Modèle Physique'
  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // Outputs for Enabled SubSystem: '<S85>/Subsystem2'
    // Delay: '<S85>/Delay'
    proc_control_node_Subsystem2(proc_control_node_M,
      proc_control_node_DW.Delay_DSTATE_d, &proc_control_node_B.q0_c,
      &proc_control_node_B.q1_p, &proc_control_node_B.q2_k,
      &proc_control_node_B.q3_d, &proc_control_node_DW.Subsystem2,
      &proc_control_node_P.Subsystem2);

    // End of Outputs for SubSystem: '<S85>/Subsystem2'

    // Sum: '<S93>/Sum' incorporates:
    //   Product: '<S93>/Product'
    //   Product: '<S93>/Product1'
    //   Product: '<S93>/Product2'
    //   Product: '<S93>/Product3'

    proc_control_node_B.fcn5_e = ((proc_control_node_B.qW2S[0] *
      proc_control_node_B.q0_c - proc_control_node_B.qW2S[1] *
      proc_control_node_B.q1_p) - proc_control_node_B.qW2S[2] *
      proc_control_node_B.q2_k) - proc_control_node_B.qW2S[3] *
      proc_control_node_B.q3_d;

    // Sum: '<S94>/Sum' incorporates:
    //   Product: '<S94>/Product'
    //   Product: '<S94>/Product1'
    //   Product: '<S94>/Product2'
    //   Product: '<S94>/Product3'

    proc_control_node_B.Product1_fh = ((proc_control_node_B.qW2S[0] *
      proc_control_node_B.q1_p + proc_control_node_B.qW2S[1] *
      proc_control_node_B.q0_c) + proc_control_node_B.qW2S[2] *
      proc_control_node_B.q3_d) - proc_control_node_B.qW2S[3] *
      proc_control_node_B.q2_k;

    // Sum: '<S95>/Sum' incorporates:
    //   Product: '<S95>/Product'
    //   Product: '<S95>/Product1'
    //   Product: '<S95>/Product2'
    //   Product: '<S95>/Product3'

    proc_control_node_B.Product2_ei = ((proc_control_node_B.qW2S[0] *
      proc_control_node_B.q2_k - proc_control_node_B.qW2S[1] *
      proc_control_node_B.q3_d) + proc_control_node_B.qW2S[2] *
      proc_control_node_B.q0_c) + proc_control_node_B.qW2S[3] *
      proc_control_node_B.q1_p;

    // Sum: '<S96>/Sum' incorporates:
    //   Product: '<S96>/Product'
    //   Product: '<S96>/Product1'
    //   Product: '<S96>/Product2'
    //   Product: '<S96>/Product3'

    proc_control_node_B.Product3_gb = ((proc_control_node_B.qW2S[0] *
      proc_control_node_B.q3_d + proc_control_node_B.qW2S[1] *
      proc_control_node_B.q2_k) - proc_control_node_B.qW2S[2] *
      proc_control_node_B.q1_p) + proc_control_node_B.qW2S[3] *
      proc_control_node_B.q0_c;

    // Sqrt: '<S103>/sqrt' incorporates:
    //   Product: '<S104>/Product'
    //   Product: '<S104>/Product1'
    //   Product: '<S104>/Product2'
    //   Product: '<S104>/Product3'
    //   Sum: '<S104>/Sum'

    proc_control_node_B.fcn4_g = sqrt(((proc_control_node_B.fcn5_e *
      proc_control_node_B.fcn5_e + proc_control_node_B.Product1_fh *
      proc_control_node_B.Product1_fh) + proc_control_node_B.Product2_ei *
      proc_control_node_B.Product2_ei) + proc_control_node_B.Product3_gb *
      proc_control_node_B.Product3_gb);

    // Fcn: '<S89>/fcn3' incorporates:
    //   Product: '<S98>/Product'
    //   Product: '<S98>/Product1'
    //   Product: '<S98>/Product2'
    //   Product: '<S98>/Product3'

    proc_control_node_B.rtb_sincos_o1_idx_0 = (proc_control_node_B.Product1_fh /
      proc_control_node_B.fcn4_g * (proc_control_node_B.Product3_gb /
      proc_control_node_B.fcn4_g) + proc_control_node_B.fcn5_e /
      proc_control_node_B.fcn4_g * (proc_control_node_B.Product2_ei /
      proc_control_node_B.fcn4_g)) * 2.0;

    // If: '<S99>/If'
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      if (proc_control_node_B.rtb_sincos_o1_idx_0 > 1.0) {
        proc_control_node_B.rtAction = 0;
      } else if (proc_control_node_B.rtb_sincos_o1_idx_0 < -1.0) {
        proc_control_node_B.rtAction = 1;
      } else {
        proc_control_node_B.rtAction = 2;
      }

      proc_control_node_DW.If_ActiveSubsystem_l = proc_control_node_B.rtAction;
    } else {
      proc_control_node_B.rtAction = proc_control_node_DW.If_ActiveSubsystem_l;
    }

    switch (proc_control_node_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S99>/If Action Subsystem' incorporates:
      //   ActionPort: '<S100>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_m);
      }

      // End of Outputs for SubSystem: '<S99>/If Action Subsystem'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S99>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S101>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_b);
      }

      // End of Outputs for SubSystem: '<S99>/If Action Subsystem1'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S99>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S102>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_g);
      }

      // End of Outputs for SubSystem: '<S99>/If Action Subsystem2'
      break;
    }

    // End of If: '<S99>/If'
  }

  // Outputs for Enabled SubSystem: '<Root>/ROS Output' incorporates:
  //   EnablePort: '<S4>/Enable'

  if ((rtmIsMajorTimeStep(proc_control_node_M) &&
       proc_control_node_M->Timing.TaskCounters.TID[3] == 0) &&
      rtmIsMajorTimeStep(proc_control_node_M)) {
    proc_control_node_DW.ROSOutput_MODE = proc_control_node_B.Reset;
  }

  if (proc_control_node_DW.ROSOutput_MODE) {
    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.Quaternion_l[0] = proc_control_node_B.y_gh[0];
    proc_control_node_B.Quaternion_l[1] = proc_control_node_B.y_gh[1];
    proc_control_node_B.Quaternion_l[2] = proc_control_node_B.y_gh[2];
    proc_control_node_B.Quaternion_l[3] = proc_control_node_B.y_gh[3];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.WorldPosition_o[0] =
      proc_control_node_B.WorldPosition_d[0];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.BodyVelocity[0] = proc_control_node_B.BodyVelocity_c[0];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.AngularRate[0] = proc_control_node_B.AngularRate_e[0];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.WorldPosition_o[1] =
      proc_control_node_B.WorldPosition_d[1];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.BodyVelocity[1] = proc_control_node_B.BodyVelocity_c[1];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.AngularRate[1] = proc_control_node_B.AngularRate_e[1];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.WorldPosition_o[2] =
      proc_control_node_B.WorldPosition_d[2];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.BodyVelocity[2] = proc_control_node_B.BodyVelocity_c[2];

    // SignalConversion generated from: '<S4>/Output'
    proc_control_node_B.AngularRate[2] = proc_control_node_B.AngularRate_e[2];
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
      // MATLAB Function: '<S63>/MATLAB Function' incorporates:
      //   Constant: '<S65>/Constant'
      //   SignalConversion generated from: '<S66>/ SFunction '

      proc_control_node_B.msg_f = proc_control_node_P.Constant_Value_h;
      proc_control_node_B.msg_f.XVelBtm = proc_control_node_B.Sum_d;
      proc_control_node_B.msg_f.YVelBtm = proc_control_node_B.Sum_i;
      proc_control_node_B.msg_f.ZVelBtm = proc_control_node_B.Sum_p;

      // Outputs for Atomic SubSystem: '<S63>/Publish'
      // MATLABSystem: '<S67>/SinkBlock'
      Pub_proc_control_node_41.publish(&proc_control_node_B.msg_f);

      // End of Outputs for SubSystem: '<S63>/Publish'

      // MATLAB Function: '<S64>/MATLAB Function' incorporates:
      //   Constant: '<S68>/Constant'

      proc_control_node_B.msg_m = proc_control_node_P.Constant_Value_g;
      proc_control_node_B.msg_m.AngularVelocity.X =
        proc_control_node_B.AngularRate_d[0];
      proc_control_node_B.msg_m.AngularVelocity.Y =
        proc_control_node_B.AngularRate_d[1];
      proc_control_node_B.msg_m.AngularVelocity.Z =
        proc_control_node_B.AngularRate_d[2];
      proc_control_node_B.msg_m.Orientation.X =
        proc_control_node_B.Quaternion_k[1];
      proc_control_node_B.msg_m.Orientation.Y =
        proc_control_node_B.Quaternion_k[2];
      proc_control_node_B.msg_m.Orientation.Z =
        proc_control_node_B.Quaternion_k[3];
      proc_control_node_B.msg_m.Orientation.W =
        proc_control_node_B.Quaternion_k[0];

      // Outputs for Atomic SubSystem: '<S64>/Publish'
      // MATLABSystem: '<S70>/SinkBlock'
      Pub_proc_control_node_47.publish(&proc_control_node_B.msg_m);

      // End of Outputs for SubSystem: '<S64>/Publish'
    }

    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      srUpdateBC(proc_control_node_DW.ROSOutput_SubsysRanBC);
    }
  }

  // End of Outputs for SubSystem: '<Root>/ROS Output'

  // Outputs for Enabled SubSystem: '<Root>/Plot values' incorporates:
  //   EnablePort: '<S2>/Enable'

  if ((rtmIsMajorTimeStep(proc_control_node_M) &&
       proc_control_node_M->Timing.TaskCounters.TID[3] == 0) &&
      rtmIsMajorTimeStep(proc_control_node_M)) {
    if (proc_control_node_B.Reset) {
      proc_control_node_DW.Plotvalues_MODE = true;
    } else if (proc_control_node_DW.Plotvalues_MODE) {
      // Disable for If: '<S51>/If'
      proc_control_node_DW.If_ActiveSubsystem_j = -1;
      proc_control_node_DW.Plotvalues_MODE = false;
    }
  }

  if (proc_control_node_DW.Plotvalues_MODE) {
    // Sum: '<S48>/Sum' incorporates:
    //   Product: '<S48>/Product'
    //   Product: '<S48>/Product1'
    //   Product: '<S48>/Product2'
    //   Product: '<S48>/Product3'

    proc_control_node_B.Product3_gb = ((proc_control_node_B.Quaternion_l[0] *
      proc_control_node_B.Quaternion_l[0] + proc_control_node_B.Quaternion_l[1] *
      proc_control_node_B.Quaternion_l[1]) + proc_control_node_B.Quaternion_l[2]
      * proc_control_node_B.Quaternion_l[2]) + proc_control_node_B.Quaternion_l
      [3] * proc_control_node_B.Quaternion_l[3];

    // Product: '<S45>/Divide'
    proc_control_node_B.rtb_sincos_o1_idx_0 = proc_control_node_B.Quaternion_l[0]
      / proc_control_node_B.Product3_gb;

    // Product: '<S45>/Divide1' incorporates:
    //   UnaryMinus: '<S47>/Unary Minus'

    proc_control_node_B.rtb_sincos_o2_idx_1 = -proc_control_node_B.Quaternion_l
      [1] / proc_control_node_B.Product3_gb;

    // Product: '<S45>/Divide2' incorporates:
    //   UnaryMinus: '<S47>/Unary Minus1'

    proc_control_node_B.rtb_sincos_o1_idx_2 = -proc_control_node_B.Quaternion_l
      [2] / proc_control_node_B.Product3_gb;

    // Product: '<S45>/Divide3' incorporates:
    //   UnaryMinus: '<S47>/Unary Minus2'

    proc_control_node_B.Product_h = -proc_control_node_B.Quaternion_l[3] /
      proc_control_node_B.Product3_gb;

    // Sqrt: '<S55>/sqrt' incorporates:
    //   Product: '<S56>/Product'
    //   Product: '<S56>/Product1'
    //   Product: '<S56>/Product2'
    //   Product: '<S56>/Product3'
    //   Sum: '<S56>/Sum'

    proc_control_node_B.Product3_gb = sqrt
      (((proc_control_node_B.rtb_sincos_o1_idx_0 *
         proc_control_node_B.rtb_sincos_o1_idx_0 +
         proc_control_node_B.rtb_sincos_o2_idx_1 *
         proc_control_node_B.rtb_sincos_o2_idx_1) +
        proc_control_node_B.rtb_sincos_o1_idx_2 *
        proc_control_node_B.rtb_sincos_o1_idx_2) + proc_control_node_B.Product_h
       * proc_control_node_B.Product_h);

    // Product: '<S50>/Product'
    proc_control_node_B.rtb_sincos_o1_idx_0 /= proc_control_node_B.Product3_gb;

    // Product: '<S50>/Product1'
    proc_control_node_B.rtb_sincos_o2_idx_1 /= proc_control_node_B.Product3_gb;

    // Product: '<S50>/Product2'
    proc_control_node_B.rtb_sincos_o1_idx_2 /= proc_control_node_B.Product3_gb;

    // Product: '<S50>/Product3'
    proc_control_node_B.Product_h /= proc_control_node_B.Product3_gb;

    // Fcn: '<S46>/fcn2' incorporates:
    //   Fcn: '<S46>/fcn5'

    proc_control_node_B.Merge_a = proc_control_node_B.rtb_sincos_o1_idx_0 *
      proc_control_node_B.rtb_sincos_o1_idx_0;
    proc_control_node_B.fcn2 = proc_control_node_B.rtb_sincos_o2_idx_1 *
      proc_control_node_B.rtb_sincos_o2_idx_1;
    proc_control_node_B.fcn4_g = proc_control_node_B.rtb_sincos_o1_idx_2 *
      proc_control_node_B.rtb_sincos_o1_idx_2;
    proc_control_node_B.fcn5_e = proc_control_node_B.Product_h *
      proc_control_node_B.Product_h;

    // Trigonometry: '<S49>/Trigonometric Function1' incorporates:
    //   Fcn: '<S46>/fcn1'
    //   Fcn: '<S46>/fcn2'

    proc_control_node_B.VectorConcatenate[0] = rt_atan2d_snf
      ((proc_control_node_B.rtb_sincos_o2_idx_1 *
        proc_control_node_B.rtb_sincos_o1_idx_2 +
        proc_control_node_B.rtb_sincos_o1_idx_0 * proc_control_node_B.Product_h)
       * 2.0, ((proc_control_node_B.Merge_a + proc_control_node_B.fcn2) -
               proc_control_node_B.fcn4_g) - proc_control_node_B.fcn5_e);

    // Fcn: '<S46>/fcn3'
    proc_control_node_B.Product3_gb = (proc_control_node_B.rtb_sincos_o2_idx_1 *
      proc_control_node_B.Product_h - proc_control_node_B.rtb_sincos_o1_idx_0 *
      proc_control_node_B.rtb_sincos_o1_idx_2) * -2.0;

    // If: '<S51>/If'
    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      if (proc_control_node_B.Product3_gb > 1.0) {
        proc_control_node_B.rtAction = 0;
      } else if (proc_control_node_B.Product3_gb < -1.0) {
        proc_control_node_B.rtAction = 1;
      } else {
        proc_control_node_B.rtAction = 2;
      }

      proc_control_node_DW.If_ActiveSubsystem_j = proc_control_node_B.rtAction;
    } else {
      proc_control_node_B.rtAction = proc_control_node_DW.If_ActiveSubsystem_j;
    }

    switch (proc_control_node_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
      //   ActionPort: '<S52>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M) &&
          proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
        // Merge: '<S51>/Merge' incorporates:
        //   Constant: '<S52>/Constant'

        proc_control_node_B.Merge_f = proc_control_node_P.Constant_Value_g4;
      }

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem_SubsysRanBC_f);
      }

      // End of Outputs for SubSystem: '<S51>/If Action Subsystem'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S53>/Action Port'

      if (rtmIsMajorTimeStep(proc_control_node_M) &&
          proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
        // Merge: '<S51>/Merge' incorporates:
        //   Constant: '<S53>/Constant'

        proc_control_node_B.Merge_f = proc_control_node_P.Constant_Value_m5;
      }

      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem1_SubsysRanB_k);
      }

      // End of Outputs for SubSystem: '<S51>/If Action Subsystem1'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S51>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S54>/Action Port'

      // Merge: '<S51>/Merge' incorporates:
      //   Inport: '<S54>/In'

      proc_control_node_B.Merge_f = proc_control_node_B.Product3_gb;
      if (rtmIsMajorTimeStep(proc_control_node_M)) {
        srUpdateBC(proc_control_node_DW.IfActionSubsystem2_SubsysRanB_d);
      }

      // End of Outputs for SubSystem: '<S51>/If Action Subsystem2'
      break;
    }

    // End of If: '<S51>/If'

    // Trigonometry: '<S49>/Trigonometric Function3' incorporates:
    //   Fcn: '<S46>/fcn4'
    //   Fcn: '<S46>/fcn5'

    proc_control_node_B.VectorConcatenate[2] = rt_atan2d_snf
      ((proc_control_node_B.rtb_sincos_o1_idx_2 * proc_control_node_B.Product_h
        + proc_control_node_B.rtb_sincos_o1_idx_0 *
        proc_control_node_B.rtb_sincos_o2_idx_1) * 2.0,
       ((proc_control_node_B.Merge_a - proc_control_node_B.fcn2) -
        proc_control_node_B.fcn4_g) + proc_control_node_B.fcn5_e);

    // Trigonometry: '<S49>/trigFcn'
    if (proc_control_node_B.Merge_f > 1.0) {
      proc_control_node_B.rtb_Sum_tmp = 1.0;
    } else if (proc_control_node_B.Merge_f < -1.0) {
      proc_control_node_B.rtb_Sum_tmp = -1.0;
    } else {
      proc_control_node_B.rtb_Sum_tmp = proc_control_node_B.Merge_f;
    }

    proc_control_node_B.VectorConcatenate[1] = asin
      (proc_control_node_B.rtb_Sum_tmp);

    // End of Trigonometry: '<S49>/trigFcn'
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
    }

    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      srUpdateBC(proc_control_node_DW.Plotvalues_SubsysRanBC);
    }
  }

  // End of Outputs for SubSystem: '<Root>/Plot values'
  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // MATLAB Function: '<S5>/MATLAB Function3' incorporates:
    //   Constant: '<S71>/Constant'

    proc_control_node_B.msg = proc_control_node_P.Constant_Value;
    for (proc_control_node_B.i = 0; proc_control_node_B.i < 8;
         proc_control_node_B.i++) {
      proc_control_node_B.msg.Data[proc_control_node_B.i] =
        proc_control_node_B.NtoPWM[proc_control_node_B.i];
    }

    proc_control_node_B.msg.Data_SL_Info.CurrentLength = 8U;

    // End of MATLAB Function: '<S5>/MATLAB Function3'

    // Outputs for Atomic SubSystem: '<S5>/Publish2'
    // MATLABSystem: '<S75>/SinkBlock'
    Pub_proc_control_node_104.publish(&proc_control_node_B.msg);

    // End of Outputs for SubSystem: '<S5>/Publish2'

    // DataTypeConversion: '<S5>/Data Type Conversion2'
    proc_control_node_B.Product_h = fabs(proc_control_node_B.status);
    if (proc_control_node_B.Product_h < 4.503599627370496E+15) {
      if (proc_control_node_B.Product_h >= 0.5) {
        proc_control_node_B.rtb_Sum_tmp = floor(proc_control_node_B.status + 0.5);
      } else {
        proc_control_node_B.rtb_Sum_tmp = proc_control_node_B.status * 0.0;
      }
    } else {
      proc_control_node_B.rtb_Sum_tmp = proc_control_node_B.status;
    }

    if (rtIsNaN(proc_control_node_B.rtb_Sum_tmp) || rtIsInf
        (proc_control_node_B.rtb_Sum_tmp)) {
      proc_control_node_B.rtb_Sum_tmp = 0.0;
    } else {
      proc_control_node_B.rtb_Sum_tmp = fmod(proc_control_node_B.rtb_Sum_tmp,
        256.0);
    }

    // BusAssignment: '<S5>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion2'

    proc_control_node_B.BusAssignment.Data = static_cast<int8_T>
      (proc_control_node_B.rtb_Sum_tmp < 0.0 ? static_cast<int32_T>(static_cast<
        int8_T>(-static_cast<int8_T>(static_cast<uint8_T>
          (-proc_control_node_B.rtb_Sum_tmp)))) : static_cast<int32_T>(
        static_cast<int8_T>(static_cast<uint8_T>(proc_control_node_B.rtb_Sum_tmp))));

    // Outputs for Atomic SubSystem: '<S5>/Publish3'
    // MATLABSystem: '<S76>/SinkBlock'
    Pub_proc_control_node_105.publish(&proc_control_node_B.BusAssignment);

    // End of Outputs for SubSystem: '<S5>/Publish3'

    // BusAssignment: '<S5>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion3'
    //   Delay: '<S5>/Delay'
    //   Sum: '<S5>/Sum'

    proc_control_node_B.BusAssignment1.Data =
      (proc_control_node_DW.Delay_DSTATE_d1 - proc_control_node_B.PulseGenerator
       != 0.0);

    // Outputs for Atomic SubSystem: '<S5>/Publish4'
    // MATLABSystem: '<S77>/SinkBlock'
    Pub_proc_control_node_106.publish(&proc_control_node_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S5>/Publish4'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // MATLAB Function: '<S3>/MATLAB Function'
    proc_control_node_B.y_g = (proc_control_node_B.SourceBlock_o1_h +
      proc_control_node_B.SourceBlock_o1_n >= 2);

    // BusAssignment: '<S6>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S6>/Cast To Boolean'

    proc_control_node_B.BusAssignment_e.Data = (proc_control_node_B.y_g != 0.0);

    // Outputs for Atomic SubSystem: '<S6>/Publish'
    // MATLABSystem: '<S79>/SinkBlock'
    Pub_proc_control_node_116.publish(&proc_control_node_B.BusAssignment_e);

    // End of Outputs for SubSystem: '<S6>/Publish'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Outputs for Triggered SubSystem: '<Root>/Send Target Reached ' incorporates:
    //   TriggerPort: '<S7>/Trigger'

    if (rtmIsMajorTimeStep(proc_control_node_M)) {
      if (((proc_control_node_PrevZCX.SendTargetReached_Trig_ZCE == 1) !=
           proc_control_node_B.Merge1) &&
          (proc_control_node_PrevZCX.SendTargetReached_Trig_ZCE != 3)) {
        // BusAssignment: '<S7>/Bus Assignment'
        proc_control_node_B.BusAssignment_a.Data = proc_control_node_B.Merge1;

        // Outputs for Atomic SubSystem: '<S7>/Publish'
        // MATLABSystem: '<S81>/SinkBlock'
        Pub_proc_control_node_122.publish(&proc_control_node_B.BusAssignment_a);

        // End of Outputs for SubSystem: '<S7>/Publish'
        proc_control_node_DW.SendTargetReached_SubsysRanBC = 4;
      }

      proc_control_node_PrevZCX.SendTargetReached_Trig_ZCE =
        proc_control_node_B.Merge1;
    }

    // End of Outputs for SubSystem: '<Root>/Send Target Reached '
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[4] == 0) {
    // MATLAB Function: '<S82>/MATLAB Function1' incorporates:
    //   Constant: '<S82>/Constant'

    proc_control_node_B.msg_i.X = proc_control_node_P.Constant_Value_j[0];
    proc_control_node_B.msg_i.Y = proc_control_node_P.Constant_Value_j[1];
    proc_control_node_B.msg_i.Z = proc_control_node_P.Constant_Value_j[2];

    // Outputs for Atomic SubSystem: '<S82>/Publish'
    // MATLABSystem: '<S87>/SinkBlock'
    Pub_proc_control_node_140.publish(&proc_control_node_B.msg_i);

    // End of Outputs for SubSystem: '<S82>/Publish'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // MATLAB Function: '<S83>/MATLAB Function1' incorporates:
    //   Constant: '<S105>/Constant'
    //   Constant: '<S83>/Constant'

    proc_control_node_B.msg_ff = proc_control_node_P.Constant_Value_m;
    proc_control_node_B.msg_ff.Linear.X = proc_control_node_P.Constant_Value_oo
      [0];
    proc_control_node_B.msg_ff.Linear.Y = proc_control_node_P.Constant_Value_oo
      [1];
    proc_control_node_B.msg_ff.Linear.Z = proc_control_node_P.Constant_Value_oo
      [2];

    // Outputs for Atomic SubSystem: '<S83>/Publish'
    // MATLABSystem: '<S107>/SinkBlock'
    Pub_proc_control_node_151.publish(&proc_control_node_B.msg_ff);

    // End of Outputs for SubSystem: '<S83>/Publish'
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Outputs for Atomic SubSystem: '<S12>/Subscribe4'
    // MATLABSystem: '<S228>/SourceBlock'
    proc_control_node_B.y_ft = Sub_proc_control_node_206.getLatestMessage
      (&proc_control_node_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S228>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S234>/Enable'

    if (proc_control_node_B.y_ft) {
      srUpdateBC(proc_control_node_DW.EnabledSubsystem_SubsysRanBC);
    }

    // End of MATLABSystem: '<S228>/SourceBlock'
    // End of Outputs for SubSystem: '<S228>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S12>/Subscribe4'

    // Update for Memory: '<S229>/Memory'
    proc_control_node_DW.Memory_PreviousInput = proc_control_node_B.Reset;
  }

  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
    // Update for Delay: '<S10>/Delay'
    proc_control_node_DW.Delay_DSTATE[0] = proc_control_node_B.rtb_y_a_idx_0;
    proc_control_node_DW.Delay_DSTATE[1] = proc_control_node_B.rtb_y_a_idx_1;
    proc_control_node_DW.Delay_DSTATE[2] = proc_control_node_B.rtb_y_a_idx_2;

    // Update for Delay: '<S155>/Delay' incorporates:
    //   Constant: '<S155>/Constant6'

    proc_control_node_DW.Delay_DSTATE_c = proc_control_node_P.Constant6_Value_o;

    // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
    proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
    proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[0] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_l + proc_control_node_B.WorldPosition[0];
    proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[1] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_p_n + proc_control_node_B.WorldPosition[1];
    proc_control_node_DW.DiscreteTimeIntegrator_DSTATE[2] =
      proc_control_node_P.DiscreteTimeIntegrator_gainva_o *
      proc_control_node_B.Sum_a + proc_control_node_B.WorldPosition[2];
    proc_control_node_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
      (proc_control_node_B.OR);

    // Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
    //   DiscreteIntegrator: '<S10>/Discrete-Time Integrator'

    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum_f + proc_control_node_B.BodyPosition[0];
    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum_c + proc_control_node_B.BodyPosition[1];
    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[2] =
      proc_control_node_P.DiscreteTimeIntegrator1_gainval *
      proc_control_node_B.Sum + proc_control_node_B.BodyPosition[2];
    proc_control_node_DW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>
      (proc_control_node_B.OR);

    // Update for DiscreteIntegrator: '<S198>/Integrator' incorporates:
    //   Constant: '<S194>/Constant'

    if (proc_control_node_P.Constant_Value_as > 0.0) {
      proc_control_node_DW.Integrator_PrevResetState = 1;
    } else if (proc_control_node_P.Constant_Value_as < 0.0) {
      proc_control_node_DW.Integrator_PrevResetState = -1;
    } else if (proc_control_node_P.Constant_Value_as == 0.0) {
      proc_control_node_DW.Integrator_PrevResetState = 0;
    } else {
      proc_control_node_DW.Integrator_PrevResetState = 2;
    }

    for (proc_control_node_B.i = 0; proc_control_node_B.i < 6;
         proc_control_node_B.i++) {
      proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] +=
        proc_control_node_P.Integrator_gainval *
        proc_control_node_B.Saturation[proc_control_node_B.i];
      if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] >=
          proc_control_node_P.Integrator_UpperSat) {
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
          proc_control_node_P.Integrator_UpperSat;
      } else if (proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] <=
                 proc_control_node_P.Integrator_LowerSat) {
        proc_control_node_DW.Integrator_DSTATE[proc_control_node_B.i] =
          proc_control_node_P.Integrator_LowerSat;
      }

      // Update for DiscreteIntegrator: '<S199>/Integrator' incorporates:
      //   DiscreteIntegrator: '<S198>/Integrator'

      proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] +=
        proc_control_node_P.Integrator_gainval_e *
        proc_control_node_B.Sum_aw[proc_control_node_B.i];
      if (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] >=
          proc_control_node_P.Integrator_UpperSat_f) {
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
          proc_control_node_P.Integrator_UpperSat_f;
      } else if (proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i]
                 <= proc_control_node_P.Integrator_LowerSat_p) {
        proc_control_node_DW.Integrator_DSTATE_l[proc_control_node_B.i] =
          proc_control_node_P.Integrator_LowerSat_p;
      }
    }

    // End of Update for DiscreteIntegrator: '<S198>/Integrator'

    // Update for DiscreteIntegrator: '<S199>/Integrator' incorporates:
    //   Constant: '<S194>/Constant1'

    if (proc_control_node_P.Constant1_Value_d > 0.0) {
      proc_control_node_DW.Integrator_PrevResetState_h = 1;
    } else if (proc_control_node_P.Constant1_Value_d < 0.0) {
      proc_control_node_DW.Integrator_PrevResetState_h = -1;
    } else if (proc_control_node_P.Constant1_Value_d == 0.0) {
      proc_control_node_DW.Integrator_PrevResetState_h = 0;
    } else {
      proc_control_node_DW.Integrator_PrevResetState_h = 2;
    }

    // Update for Delay: '<S85>/Delay' incorporates:
    //   Constant: '<S85>/Constant6'

    proc_control_node_DW.Delay_DSTATE_d = proc_control_node_P.Constant6_Value_i;
  }

  // Update for Enabled SubSystem: '<Root>/Modèle Physique' incorporates:
  //   EnablePort: '<S1>/Enable'

  if (proc_control_node_DW.ModlePhysique_MODE) {
    // Update for Integrator: '<S1>/Integrator1'
    proc_control_node_DW.Integrator1_IWORK = 0;
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[5] == 0) {
      // Update for UniformRandomNumber: '<S16>/X Drift'
      proc_control_node_DW.XDrift_NextOutput = (proc_control_node_P.dMaxX -
        proc_control_node_P.dMinX) * rt_urand_Upu32_Yd_f_pw_snf
        (&proc_control_node_DW.RandSeed) + proc_control_node_P.dMinX;

      // Update for UniformRandomNumber: '<S16>/Y Drift'
      proc_control_node_DW.YDrift_NextOutput = (proc_control_node_P.dMaxY -
        proc_control_node_P.dMinY) * rt_urand_Upu32_Yd_f_pw_snf
        (&proc_control_node_DW.RandSeed_a) + proc_control_node_P.dMinY;
    }

    // Update for Integrator: '<S1>/Integrator'
    proc_control_node_DW.Integrator_IWORK = 0;

    // Update for Integrator: '<S1>/Integrator2'
    proc_control_node_DW.Integrator2_IWORK = 0;

    // Update for Integrator: '<S1>/Integrator3'
    proc_control_node_DW.Integrator3_IWORK = 0;
    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
      // Update for RandomNumber: '<S28>/White Noise'
      proc_control_node_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
        (&proc_control_node_DW.RandSeed_j) *
        proc_control_node_P.WhiteNoise_StdDev +
        proc_control_node_P.WhiteNoise_Mean;

      // Update for RandomNumber: '<S29>/White Noise'
      proc_control_node_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
        (&proc_control_node_DW.RandSeed_d) *
        proc_control_node_P.WhiteNoise_StdDev_d +
        proc_control_node_P.WhiteNoise_Mean_e;
    }
  }

  // End of Update for SubSystem: '<Root>/Modèle Physique'
  if (rtmIsMajorTimeStep(proc_control_node_M) &&
      proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
    // Update for Delay: '<S5>/Delay'
    proc_control_node_DW.Delay_DSTATE_d1 = proc_control_node_B.PulseGenerator;
  }

  if (rtmIsMajorTimeStep(proc_control_node_M)) {
    // External mode
    rtExtModeUploadCheckTrigger(6);

    {                                  // Sample time: [0.0s, 0.0s]
      rtExtModeUpload(0, (real_T)proc_control_node_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[1] == 0) {
                                  // Sample time: [0.016666666666666666s, 0.0s]
      rtExtModeUpload(1, (real_T)((proc_control_node_M->Timing.clockTick1) *
        0.016666666666666666));
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {// Sample time: [0.05s, 0.0s] 
      rtExtModeUpload(2, (real_T)((proc_control_node_M->Timing.clockTick2) *
        0.05));
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {// Sample time: [0.1s, 0.0s] 
      rtExtModeUpload(3, (real_T)((proc_control_node_M->Timing.clockTick3) * 0.1));
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[4] == 0) {// Sample time: [1.0s, 0.0s] 
      rtExtModeUpload(4, (real_T)((proc_control_node_M->Timing.clockTick4) * 1.0));
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[5] == 0) {// Sample time: [5.0s, 0.0s] 
      rtExtModeUpload(5, (real_T)((proc_control_node_M->Timing.clockTick5) * 5.0));
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(proc_control_node_M)) {
    // signal main to stop simulation
    {                                  // Sample time: [0.0s, 0.0s]
      if ((rtmGetTFinal(proc_control_node_M)!=-1) &&
          !((rtmGetTFinal(proc_control_node_M)-
             ((proc_control_node_M->Timing.clockTick1) * 0.016666666666666666)) >
            ((proc_control_node_M->Timing.clockTick1) * 0.016666666666666666) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(proc_control_node_M, "Simulation finished");
      }

      if (rtmGetStopRequested(proc_control_node_M)) {
        rtmSetErrorStatus(proc_control_node_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&proc_control_node_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++proc_control_node_M->Timing.clockTick0;
    proc_control_node_M->Timing.t[0] = rtsiGetSolverStopTime
      (&proc_control_node_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.016666666666666666s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.016666666666666666, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      proc_control_node_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[2] == 0) {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick2" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick2" ensures timer will not overflow during the
      //  application lifespan selected.

      proc_control_node_M->Timing.clockTick2++;
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[3] == 0) {
      // Update absolute timer for sample time: [0.1s, 0.0s]
      // The "clockTick3" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.1, which is the step size
      //  of the task. Size of "clockTick3" ensures timer will not overflow during the
      //  application lifespan selected.

      proc_control_node_M->Timing.clockTick3++;
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[4] == 0) {
      // Update absolute timer for sample time: [1.0s, 0.0s]
      // The "clockTick4" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 1.0, which is the step size
      //  of the task. Size of "clockTick4" ensures timer will not overflow during the
      //  application lifespan selected.

      proc_control_node_M->Timing.clockTick4++;
    }

    if (rtmIsMajorTimeStep(proc_control_node_M) &&
        proc_control_node_M->Timing.TaskCounters.TID[5] == 0) {
      // Update absolute timer for sample time: [5.0s, 0.0s]
      // The "clockTick5" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 5.0, which is the step size
      //  of the task. Size of "clockTick5" ensures timer will not overflow during the
      //  application lifespan selected.

      proc_control_node_M->Timing.clockTick5++;
    }

    rate_scheduler();
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void proc_control_node_derivatives(void)
{
  XDot_proc_control_node_T *_rtXdot;
  _rtXdot = ((XDot_proc_control_node_T *) proc_control_node_M->derivs);

  // Derivatives for Enabled SubSystem: '<Root>/Modèle Physique'
  if (proc_control_node_DW.ModlePhysique_MODE) {
    // Derivatives for Integrator: '<S1>/Integrator1'
    _rtXdot->Integrator1_CSTATE[0] = proc_control_node_B.Quaternion_dot[0];
    _rtXdot->Integrator1_CSTATE[1] = proc_control_node_B.Quaternion_dot[1];
    _rtXdot->Integrator1_CSTATE[2] = proc_control_node_B.Quaternion_dot[2];
    _rtXdot->Integrator1_CSTATE[3] = proc_control_node_B.Quaternion_dot[3];

    // Derivatives for TransferFcn: '<S20>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE = 0.0;
    _rtXdot->TransferFcn_CSTATE += proc_control_node_P.TransferFcn_A *
      proc_control_node_X.TransferFcn_CSTATE;
    _rtXdot->TransferFcn_CSTATE += proc_control_node_B.PWMtoN[0];

    // Derivatives for TransferFcn: '<S21>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_o = 0.0;
    _rtXdot->TransferFcn_CSTATE_o += proc_control_node_P.TransferFcn_A_j *
      proc_control_node_X.TransferFcn_CSTATE_o;
    _rtXdot->TransferFcn_CSTATE_o += proc_control_node_B.PWMtoN[1];

    // Derivatives for TransferFcn: '<S22>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_p = 0.0;
    _rtXdot->TransferFcn_CSTATE_p += proc_control_node_P.TransferFcn_A_h *
      proc_control_node_X.TransferFcn_CSTATE_p;
    _rtXdot->TransferFcn_CSTATE_p += proc_control_node_B.PWMtoN[2];

    // Derivatives for TransferFcn: '<S23>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_a = 0.0;
    _rtXdot->TransferFcn_CSTATE_a += proc_control_node_P.TransferFcn_A_i *
      proc_control_node_X.TransferFcn_CSTATE_a;
    _rtXdot->TransferFcn_CSTATE_a += proc_control_node_B.PWMtoN[3];

    // Derivatives for TransferFcn: '<S24>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_f = 0.0;
    _rtXdot->TransferFcn_CSTATE_f += proc_control_node_P.TransferFcn_A_jp *
      proc_control_node_X.TransferFcn_CSTATE_f;
    _rtXdot->TransferFcn_CSTATE_f += proc_control_node_B.PWMtoN[4];

    // Derivatives for TransferFcn: '<S25>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_e = 0.0;
    _rtXdot->TransferFcn_CSTATE_e += proc_control_node_P.TransferFcn_A_l *
      proc_control_node_X.TransferFcn_CSTATE_e;
    _rtXdot->TransferFcn_CSTATE_e += proc_control_node_B.PWMtoN[5];

    // Derivatives for TransferFcn: '<S26>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_ft = 0.0;
    _rtXdot->TransferFcn_CSTATE_ft += proc_control_node_P.TransferFcn_A_p *
      proc_control_node_X.TransferFcn_CSTATE_ft;
    _rtXdot->TransferFcn_CSTATE_ft += proc_control_node_B.PWMtoN[6];

    // Derivatives for TransferFcn: '<S27>/Transfer Fcn'
    _rtXdot->TransferFcn_CSTATE_fu = 0.0;
    _rtXdot->TransferFcn_CSTATE_fu += proc_control_node_P.TransferFcn_A_n *
      proc_control_node_X.TransferFcn_CSTATE_fu;
    _rtXdot->TransferFcn_CSTATE_fu += proc_control_node_B.PWMtoN[7];

    // Derivatives for Integrator: '<S1>/Integrator'
    _rtXdot->Integrator_CSTATE[0] = proc_control_node_B.Position_dot[0];

    // Derivatives for Integrator: '<S1>/Integrator2'
    _rtXdot->Integrator2_CSTATE[0] = proc_control_node_B.BodyVelocity_dot[0];

    // Derivatives for Integrator: '<S1>/Integrator3'
    _rtXdot->Integrator3_CSTATE[0] = proc_control_node_B.AngularRates_dot[0];

    // Derivatives for Integrator: '<S1>/Integrator'
    _rtXdot->Integrator_CSTATE[1] = proc_control_node_B.Position_dot[1];

    // Derivatives for Integrator: '<S1>/Integrator2'
    _rtXdot->Integrator2_CSTATE[1] = proc_control_node_B.BodyVelocity_dot[1];

    // Derivatives for Integrator: '<S1>/Integrator3'
    _rtXdot->Integrator3_CSTATE[1] = proc_control_node_B.AngularRates_dot[1];

    // Derivatives for Integrator: '<S1>/Integrator'
    _rtXdot->Integrator_CSTATE[2] = proc_control_node_B.Position_dot[2];

    // Derivatives for Integrator: '<S1>/Integrator2'
    _rtXdot->Integrator2_CSTATE[2] = proc_control_node_B.BodyVelocity_dot[2];

    // Derivatives for Integrator: '<S1>/Integrator3'
    _rtXdot->Integrator3_CSTATE[2] = proc_control_node_B.AngularRates_dot[2];
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_proc_control_node_T *) proc_control_node_M->derivs)
             ->Integrator1_CSTATE[0]);
      for (i=0; i < 21; i++) {
        dx[i] = 0.0;
      }
    }
  }

  // End of Derivatives for SubSystem: '<Root>/Modèle Physique'
}

// Model initialize function
void proc_control_node_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  proc_control_node_P.IMU_AccelParamsMeasurementRange = rtInf;
  proc_control_node_P.IMU_GyroParamsMeasurementRange = rtInf;
  proc_control_node_P.IMU_MagParamsMeasurementRange = rtInf;
  proc_control_node_P.Integrator_UpperSat = rtInf;
  proc_control_node_P.Integrator_LowerSat = rtMinusInf;
  proc_control_node_P.Saturation_UpperSat = rtInf;
  proc_control_node_P.Saturation_LowerSat = rtMinusInf;
  proc_control_node_P.Integrator_UpperSat_f = rtInf;
  proc_control_node_P.Integrator_LowerSat_p = rtMinusInf;
  proc_control_node_P.Saturation_UpperSat_m = rtInf;
  proc_control_node_P.Saturation_LowerSat_c = rtMinusInf;

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&proc_control_node_M->solverInfo,
                          &proc_control_node_M->Timing.simTimeStep);
    rtsiSetTPtr(&proc_control_node_M->solverInfo, &rtmGetTPtr
                (proc_control_node_M));
    rtsiSetStepSizePtr(&proc_control_node_M->solverInfo,
                       &proc_control_node_M->Timing.stepSize0);
    rtsiSetdXPtr(&proc_control_node_M->solverInfo, &proc_control_node_M->derivs);
    rtsiSetContStatesPtr(&proc_control_node_M->solverInfo, (real_T **)
                         &proc_control_node_M->contStates);
    rtsiSetNumContStatesPtr(&proc_control_node_M->solverInfo,
      &proc_control_node_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&proc_control_node_M->solverInfo,
      &proc_control_node_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&proc_control_node_M->solverInfo,
      &proc_control_node_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&proc_control_node_M->solverInfo,
      &proc_control_node_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&proc_control_node_M->solverInfo, (&rtmGetErrorStatus
      (proc_control_node_M)));
    rtsiSetRTModelPtr(&proc_control_node_M->solverInfo, proc_control_node_M);
  }

  rtsiSetSimTimeStep(&proc_control_node_M->solverInfo, MAJOR_TIME_STEP);
  proc_control_node_M->intgData.y = proc_control_node_M->odeY;
  proc_control_node_M->intgData.f[0] = proc_control_node_M->odeF[0];
  proc_control_node_M->intgData.f[1] = proc_control_node_M->odeF[1];
  proc_control_node_M->intgData.f[2] = proc_control_node_M->odeF[2];
  proc_control_node_M->contStates = ((X_proc_control_node_T *)
    &proc_control_node_X);
  rtsiSetSolverData(&proc_control_node_M->solverInfo, static_cast<void *>
                    (&proc_control_node_M->intgData));
  rtsiSetSolverName(&proc_control_node_M->solverInfo,"ode3");
  rtmSetTPtr(proc_control_node_M, &proc_control_node_M->Timing.tArray[0]);
  rtmSetTFinal(proc_control_node_M, -1);
  proc_control_node_M->Timing.stepSize0 = 0.016666666666666666;
  rtmSetFirstInitCond(proc_control_node_M, 1);

  // External mode info
  proc_control_node_M->Sizes.checksums[0] = (2204037515U);
  proc_control_node_M->Sizes.checksums[1] = (3238934813U);
  proc_control_node_M->Sizes.checksums[2] = (3948677549U);
  proc_control_node_M->Sizes.checksums[3] = (2960805777U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[116];
    proc_control_node_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &proc_control_node_DW.ModlePhysique_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[8] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem1_SubsysRanB_k;
    systemRan[9] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem2_SubsysRanB_d;
    systemRan[10] = (sysRanDType *)&proc_control_node_DW.Plotvalues_SubsysRanBC;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_pz;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&proc_control_node_DW.ROSOutput_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = (sysRanDType *)
      &proc_control_node_DW.SendTargetReached_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &proc_control_node_DW.SendTargetReached_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &proc_control_node_DW.SendTargetReached_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &proc_control_node_DW.SendTargetReached_SubsysRanBC;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = (sysRanDType *)
      &proc_control_node_DW.Subsystem2.Subsystem2_SubsysRanBC;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[51] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem1_SubsysRanB_b;
    systemRan[52] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem2_SubsysRanB_g;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = (sysRanDType *)&proc_control_node_DW.IDLE_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa;
    systemRan[61] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC_c;
    systemRan[62] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem1_SubsysRanB_h;
    systemRan[63] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem2_SubsysRanB_o;
    systemRan[64] = (sysRanDType *)
      &proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa;
    systemRan[65] = (sysRanDType *)
      &proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa;
    systemRan[66] = (sysRanDType *)
      &proc_control_node_DW.Subsystem2_p.Subsystem2_SubsysRanBC;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC_l;
    systemRan[69] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem1_SubsysRanB_i;
    systemRan[70] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem2_SubsysRanB_b;
    systemRan[71] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = (sysRanDType *)
      &proc_control_node_DW.SubsystemAuto_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &proc_control_node_DW.SubsystemAuto_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &proc_control_node_DW.SubsystemManual_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &proc_control_node_DW.SubsystemManual_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[82] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[83] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[84] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[85] = (sysRanDType *)
      &proc_control_node_DW.Pretraitement_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o;
    systemRan[87] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[88] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[89] = (sysRanDType *)&proc_control_node_DW.Subsystem1_SubsysRanBC;
    systemRan[90] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[91] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[92] = (sysRanDType *)
      &proc_control_node_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[93] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_p;
    systemRan[94] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[95] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[96] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[97] = (sysRanDType *)
      &proc_control_node_DW.singleWptsTrajectory_SubsysRanB;
    systemRan[98] = &rtAlwaysEnabled;
    systemRan[99] = &rtAlwaysEnabled;
    systemRan[100] = &rtAlwaysEnabled;
    systemRan[101] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_d;
    systemRan[102] = &rtAlwaysEnabled;
    systemRan[103] = &rtAlwaysEnabled;
    systemRan[104] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_kg;
    systemRan[105] = &rtAlwaysEnabled;
    systemRan[106] = &rtAlwaysEnabled;
    systemRan[107] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[108] = &rtAlwaysEnabled;
    systemRan[109] = &rtAlwaysEnabled;
    systemRan[110] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e;
    systemRan[111] = &rtAlwaysEnabled;
    systemRan[112] = &rtAlwaysEnabled;
    systemRan[113] = (sysRanDType *)
      &proc_control_node_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[114] = &rtAlwaysEnabled;
    systemRan[115] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(proc_control_node_M->extModeInfo,
      &proc_control_node_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(proc_control_node_M->extModeInfo,
                        proc_control_node_M->Sizes.checksums);
    rteiSetTPtr(proc_control_node_M->extModeInfo, rtmGetTPtr(proc_control_node_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    proc_control_node_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 50;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    int32_T i;
    int32_T t;
    uint32_T tseed;
    boolean_T flag;
    static const char_T tmp[22] = { '/', 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 's', 'e', 't', '_', 'm', 'o', 'd', 'e' };

    static const char_T tmp_0[22] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'i', 'm', 'u', '/', 'i', 'm', 'u', '_', 'i', 'n', 'f', 'o' };

    static const char_T tmp_1[26] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'd', 'v', 'l', '/', 'd', 'v', 'l', '_', 'v', 'e', 'l', 'o', 'c',
      'i', 't', 'y' };

    static const char_T tmp_2[18] = { '/', 'i', 'n', 'i', 't', 'i', 'a', 'l',
      '_', 'c', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n' };

    static const char_T tmp_3[19] = { '/', 'p', 'r', 'o', 'c', '_', 'n', 'a',
      'v', '/', 'r', 'e', 's', 'e', 't', '_', 'p', 'o', 's' };

    static const char_T tmp_4[15] = { '/', 's', 'p', 'a', 'c', 'e', 'n', 'a',
      'v', '/', 't', 'w', 'i', 's', 't' };

    static const char_T tmp_5[21] = { 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 'a', 'd', 'd', '_', 'p', 'o', 's', 'e' };

    static const real_T tmp_6[33] = { 0.0, 1.0, 0.0, 0.1, 1.0, 0.0, 0.2, 1.0,
      0.0, 0.30000000000000004, 1.0, 0.0, 0.4, 1.0, 0.0, 0.5, 1.0, 0.0, 0.6, 1.0,
      0.0, 0.7, 1.0, 0.0, 0.8, 1.0, 0.0, 0.9, 1.0, 0.0, 1.0, 1.0, 0.0 };

    static const char_T tmp_7[18] = { '/', 'p', 'r', 'o', 'c', '_', 'c', 'o',
      'n', 't', 'r', 'o', 'l', '/', 'k', 'i', 'l', 'l' };

    static const char_T tmp_8[28] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'd', 'v', 'l', '/', 'd', 'v', 'l', '_', 'v', 'e', 'l', 'o', 'c',
      'i', 't', 'y', '_', '2' };

    static const char_T tmp_9[24] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'i', 'm', 'u', '/', 'i', 'm', 'u', '_', 'i', 'n', 'f', 'o', '_',
      '2' };

    static const char_T tmp_a[31] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 't', 'h', 'r', 'u', 's', 't', 'e', 'r', '/', 't', 'h', 'r', 'u',
      's', 't', 'e', 'r', '_', 'p', 'w', 'm' };

    static const char_T tmp_b[23] = { 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 'm', 'p', 'c', '_', 's', 't', 'a', 't', 'u', 's'
    };

    static const char_T tmp_c[26] = { 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 'i', 's', '_', 'm', 'p', 'c', '_', 'a', 'c', 't',
      'i', 'v', 'e' };

    static const char_T tmp_d[22] = { 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 's', 'e', 'n', 's', 'o', 'r', '_', 'o', 'n' };

    static const char_T tmp_e[27] = { 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n',
      't', 'r', 'o', 'l', '/', 't', 'a', 'r', 'g', 'e', 't', '_', 'r', 'e', 'a',
      'c', 'h', 'e', 'd' };

    static const char_T tmp_f[24] = { '/', 'p', 'r', 'o', 'v', 'i', 'd', 'e',
      'r', '_', 'd', 'v', 'l', '/', 's', 'e', 't', '_', 'a', 'n', 'g', 'l', 'e',
      's' };

    static const char_T tmp_g[22] = { '/', 'p', 'r', 'o', 'c', '_', 'n', 'a',
      'v', '/', 'd', 'v', 'l', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y' };

    static const char_T tmp_h[13] = { '/', 's', 'p', 'a', 'c', 'e', 'n', 'a',
      'v', '/', 'j', 'o', 'y' };

    // Start for If: '<S182>/If'
    proc_control_node_DW.If_ActiveSubsystem = -1;

    // Start for Constant: '<S194>/Constant3'
    proc_control_node_B.Constant3 = proc_control_node_P.Constant3_Value;

    // Start for Constant: '<S194>/Constant2'
    proc_control_node_B.Constant2 = proc_control_node_P.Constant2_Value;

    // Start for SwitchCase: '<S11>/Switch Case'
    proc_control_node_DW.SwitchCase_ActiveSubsystem = -1;

    // Start for SwitchCase: '<S9>/Switch Case'
    proc_control_node_DW.SwitchCase_ActiveSubsystem_l = -1;

    // Start for If: '<S99>/If'
    proc_control_node_DW.If_ActiveSubsystem_l = -1;
    proc_control_node_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    proc_control_node_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    proc_control_node_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    proc_control_node_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    proc_control_node_PrevZCX.SendTargetReached_Trig_ZCE = UNINITIALIZED_ZCSIG;
    proc_control_node_PrevZCX.Trajectorygenerator_Reset_ZCE = POS_ZCSIG;

    // InitializeConditions for Delay: '<S155>/Delay'
    proc_control_node_DW.Delay_DSTATE_c =
      proc_control_node_P.Delay_InitialCondition_a;

    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' 
    proc_control_node_DW.DiscreteTimeIntegrator_PrevRese = 2;
    proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for Delay: '<S10>/Delay'
    proc_control_node_DW.Delay_DSTATE[0] =
      proc_control_node_P.Delay_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' 
    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      proc_control_node_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for Delay: '<S10>/Delay'
    proc_control_node_DW.Delay_DSTATE[1] =
      proc_control_node_P.Delay_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' 
    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      proc_control_node_P.DiscreteTimeIntegrator1_IC;

    // InitializeConditions for Delay: '<S10>/Delay'
    proc_control_node_DW.Delay_DSTATE[2] =
      proc_control_node_P.Delay_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' 
    proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE[2] =
      proc_control_node_P.DiscreteTimeIntegrator1_IC;
    proc_control_node_DW.DiscreteTimeIntegrator1_PrevRes = 2;
    for (i = 0; i < 6; i++) {
      // InitializeConditions for DiscreteIntegrator: '<S198>/Integrator'
      proc_control_node_DW.Integrator_DSTATE[i] = proc_control_node_B.Constant3;
      if (proc_control_node_DW.Integrator_DSTATE[i] >=
          proc_control_node_P.Integrator_UpperSat) {
        proc_control_node_DW.Integrator_DSTATE[i] =
          proc_control_node_P.Integrator_UpperSat;
      } else if (proc_control_node_DW.Integrator_DSTATE[i] <=
                 proc_control_node_P.Integrator_LowerSat) {
        proc_control_node_DW.Integrator_DSTATE[i] =
          proc_control_node_P.Integrator_LowerSat;
      }

      // End of InitializeConditions for DiscreteIntegrator: '<S198>/Integrator' 

      // InitializeConditions for DiscreteIntegrator: '<S199>/Integrator'
      proc_control_node_DW.Integrator_DSTATE_l[i] =
        proc_control_node_B.Constant2;
      if (proc_control_node_DW.Integrator_DSTATE_l[i] >=
          proc_control_node_P.Integrator_UpperSat_f) {
        proc_control_node_DW.Integrator_DSTATE_l[i] =
          proc_control_node_P.Integrator_UpperSat_f;
      } else if (proc_control_node_DW.Integrator_DSTATE_l[i] <=
                 proc_control_node_P.Integrator_LowerSat_p) {
        proc_control_node_DW.Integrator_DSTATE_l[i] =
          proc_control_node_P.Integrator_LowerSat_p;
      }

      // End of InitializeConditions for DiscreteIntegrator: '<S199>/Integrator' 
    }

    // InitializeConditions for Memory: '<S229>/Memory'
    proc_control_node_DW.Memory_PreviousInput =
      proc_control_node_P.MinMaxRunningResettable_vinit;

    // InitializeConditions for Delay: '<S85>/Delay'
    proc_control_node_DW.Delay_DSTATE_d =
      proc_control_node_P.Delay_InitialCondition_j;

    // InitializeConditions for Delay: '<S5>/Delay'
    proc_control_node_DW.Delay_DSTATE_d1 =
      proc_control_node_P.Delay_InitialCondition_f;

    // SystemInitialize for Atomic SubSystem: '<S12>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S226>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S232>/Out1' incorporates:
    //   Inport: '<S232>/In1'

    proc_control_node_B.In1_b = proc_control_node_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S226>/Enabled Subsystem'

    // Start for MATLABSystem: '<S226>/SourceBlock'
    proc_control_node_DW.obj_e.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      proc_control_node_B.b_zeroDelimTopic_p[i] = tmp[i];
    }

    proc_control_node_B.b_zeroDelimTopic_p[22] = '\x00';
    Sub_proc_control_node_204.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_p[0], 1);
    proc_control_node_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S226>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S12>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S59>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S61>/Out1' incorporates:
    //   Inport: '<S61>/In1'

    proc_control_node_B.In1 = proc_control_node_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S59>/Enabled Subsystem'

    // Start for MATLABSystem: '<S59>/SourceBlock'
    proc_control_node_DW.obj_lu.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_lu.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      proc_control_node_B.b_zeroDelimTopic_p[i] = tmp_0[i];
    }

    proc_control_node_B.b_zeroDelimTopic_p[22] = '\x00';
    Sub_proc_control_node_31_5.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_p[0], 1);
    proc_control_node_DW.obj_lu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S59>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S3>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S60>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S62>/Out1' incorporates:
    //   Inport: '<S62>/In1'

    proc_control_node_B.In1_f = proc_control_node_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S60>/Enabled Subsystem'

    // Start for MATLABSystem: '<S60>/SourceBlock'
    proc_control_node_DW.obj_mm.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_mm.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      proc_control_node_B.b_zeroDelimTopic_j[i] = tmp_1[i];
    }

    proc_control_node_B.b_zeroDelimTopic_j[26] = '\x00';
    Sub_proc_control_node_31_6.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_j[0], 1);
    proc_control_node_DW.obj_mm.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S60>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/Subscribe1'

    // SystemInitialize for Enabled SubSystem: '<S155>/Subsystem2'
    proc_control_no_Subsystem2_Init(&proc_control_node_B.q0,
      &proc_control_node_B.q1, &proc_control_node_B.q2, &proc_control_node_B.q3,
      &proc_control_node_P.Subsystem2_p);

    // End of SystemInitialize for SubSystem: '<S155>/Subsystem2'

    // SystemInitialize for Atomic SubSystem: '<S12>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S224>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S230>/Out1' incorporates:
    //   Inport: '<S230>/In1'

    proc_control_node_B.In1_n = proc_control_node_P.Out1_Y0_jt;

    // End of SystemInitialize for SubSystem: '<S224>/Enabled Subsystem'

    // Start for MATLABSystem: '<S224>/SourceBlock'
    proc_control_node_DW.obj_g.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      proc_control_node_B.b_zeroDelimTopic_e[i] = tmp_2[i];
    }

    proc_control_node_B.b_zeroDelimTopic_e[18] = '\x00';
    Sub_proc_control_node_202.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_e[0], 1);
    proc_control_node_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S224>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S12>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<S12>/Subscribe3'
    // Start for MATLABSystem: '<S227>/SourceBlock'
    proc_control_node_DW.obj_f.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 19; i++) {
      proc_control_node_B.b_zeroDelimTopic_jd[i] = tmp_3[i];
    }

    proc_control_node_B.b_zeroDelimTopic_jd[19] = '\x00';
    Sub_proc_control_node_205.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_jd[0], 1);
    proc_control_node_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S227>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S12>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<S189>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S195>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S200>/Out1' incorporates:
    //   Inport: '<S200>/In1'

    proc_control_node_B.In1_o = proc_control_node_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S195>/Enabled Subsystem'

    // Start for MATLABSystem: '<S195>/SourceBlock'
    proc_control_node_DW.obj_cs.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_cs.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      proc_control_node_B.b_zeroDelimTopic_o[i] = tmp_4[i];
    }

    proc_control_node_B.b_zeroDelimTopic_o[15] = '\x00';
    Sub_proc_control_node_184_1122.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_o[0], 2);
    proc_control_node_DW.obj_cs.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S195>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S189>/Subscribe2'
    // InitializeConditions for Delay: '<S208>/Delay'
    proc_control_node_DW.Delay_DSTATE_n =
      proc_control_node_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S192>/Delay1'
    proc_control_node_DW.Delay1_DSTATE_c =
      proc_control_node_P.Delay1_InitialCondition_k;

    // SystemInitialize for Enabled SubSystem: '<S208>/Enabled Subsystem'
    for (i = 0; i < 7; i++) {
      // SystemInitialize for Math: '<S211>/Transpose' incorporates:
      //   Outport: '<S211>/y'

      proc_control_node_B.Transpose[i] = proc_control_node_P.y_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S208>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S192>/Subscribe'
    // Start for MATLABSystem: '<S206>/SourceBlock'
    proc_control_node_DW.obj_h.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      proc_control_node_B.b_zeroDelimTopic_p4[i] = tmp_5[i];
    }

    proc_control_node_B.b_zeroDelimTopic_p4[21] = '\x00';
    Sub_proc_control_node_184_1168.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_p4[0], 1);
    proc_control_node_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S206>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S192>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<S192>/Subsystem1'
    // SystemInitialize for DataTypeConversion: '<S207>/Data Type Conversion1' incorporates:
    //   Outport: '<S207>/Out1'

    proc_control_node_B.DataTypeConversion1[0] = proc_control_node_P.Out1_Y0_i;
    proc_control_node_B.DataTypeConversion1[1] = proc_control_node_P.Out1_Y0_i;

    // SystemInitialize for DataTypeConversion: '<S207>/Data Type Conversion2' incorporates:
    //   Outport: '<S207>/Out1'

    proc_control_node_B.DataTypeConversion2 = proc_control_node_P.Out1_Y0_i;

    // SystemInitialize for Enabled SubSystem: '<S192>/Pre-traitement'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for DataTypeConversion: '<S207>/Data Type Conversion' incorporates:
      //   Outport: '<S207>/Out1'

      proc_control_node_B.DataTypeConversion[i] = proc_control_node_P.Out1_Y0_i;

      // SystemInitialize for Selector: '<S205>/Selector' incorporates:
      //   DataTypeConversion: '<S207>/Data Type Conversion'
      //   Outport: '<S205>/linWpts'
      //   Outport: '<S207>/Out1'

      proc_control_node_B.Selector[i] = proc_control_node_P.linWpts_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S192>/Subsystem1'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Selector: '<S205>/Selector1' incorporates:
      //   Outport: '<S205>/RotWpts'

      proc_control_node_B.Selector1[i] = proc_control_node_P.RotWpts_Y0;
    }

    // SystemInitialize for Concatenate: '<S205>/Matrix Concatenate' incorporates:
    //   Outport: '<S205>/time'

    proc_control_node_B.MatrixConcatenate[0] = proc_control_node_P.time_Y0;
    proc_control_node_B.MatrixConcatenate[1] = proc_control_node_P.time_Y0;

    // End of SystemInitialize for SubSystem: '<S192>/Pre-traitement'
    // InitializeConditions for DiscreteIntegrator: '<S209>/Discrete-Time Integrator' 
    proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b =
      proc_control_node_P.DiscreteTimeIntegrator_IC;

    // Start for MATLABSystem: '<S209>/Rotation Trajectory'
    memcpy(&proc_control_node_DW.obj_j.TimeScaling[0], &tmp_6[0], 33U * sizeof
           (real_T));
    proc_control_node_DW.obj_j.isInitialized = 1;
    proc_control_node_DW.obj_j.TunablePropsChanged = false;

    // Start for MATLABSystem: '<S209>/Polynomial Trajectory1'
    memset(&proc_control_node_DW.obj_jo.AccelerationBoundaryCondition[0], 0, 10U
           * sizeof(real_T));
    proc_control_node_DW.obj_jo.isInitialized = 0;
    for (i = 0; i < 6; i++) {
      proc_control_node_DW.obj_jo.VelocityBoundaryCondition[i] =
        proc_control_node_P.PolynomialTrajectory1_VelocityB[i];
    }

    proc_control_node_DW.obj_jo.isInitialized = 1;
    proc_control_node_DW.obj_jo.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S209>/Polynomial Trajectory1'
    // End of SystemInitialize for SubSystem: '<S192>/Trajectory generator'

    // Start for MATLABSystem: '<S192>/MATLAB System1'
    // ========================================================================== 
    //  Fonctions Principales
    // ========================================================================== 
    //  Fonction appeler a l'initialisation
    //  Perform one-time calculations, such as computing constants
    for (i = 0; i < 16; i++) {
      proc_control_node_DW.obj_a.poseList[i] = 999.0;
    }

    proc_control_node_DW.obj_a.poseList[0] = 0.0;
    proc_control_node_DW.obj_a.poseList[2] = 0.0;
    proc_control_node_DW.obj_a.poseList[4] = 0.0;
    proc_control_node_DW.obj_a.poseList[6] = 1.0;
    proc_control_node_DW.obj_a.poseList[8] = 0.0;
    proc_control_node_DW.obj_a.poseList[10] = 0.0;
    proc_control_node_DW.obj_a.poseList[12] = 0.0;
    proc_control_node_DW.obj_a.poseList[14] = 0.0;

    // initCond(1,1:7);
    proc_control_node_DW.obj_a.i = 2.0;

    // End of Start for MATLABSystem: '<S192>/MATLAB System1'

    // Start for MATLABSystem: '<S192>/MATLAB System'
    //         %%
    //  Initialize / reset discrete-state properties
    proc_control_node_DW.obj.linearConvergence =
      proc_control_node_P.MATLABSystem_linearConvergence;
    proc_control_node_DW.obj.quaternionConvergence =
      proc_control_node_P.MATLABSystem_quaternionConverge;
    proc_control_node_DW.obj.TargetThreshold =
      proc_control_node_P.MATLABSystem_TargetThreshold;
    proc_control_node_DW.obj.isInitialized = 1;
    pro_TrajectoryManager_setupImpl(&proc_control_node_DW.obj);

    // End of SystemInitialize for SubSystem: '<S11>/singleWpts Trajectory'

    // SystemInitialize for IfAction SubSystem: '<S9>/Quaternion Non linear MPC' 
    // InitializeConditions for Memory: '<S116>/LastPcov'
    //  Fonction reset
    //  Initialize / reset discrete-state properties
    memcpy(&proc_control_node_DW.LastPcov_PreviousInput[0],
           &proc_control_node_P.LastPcov_InitialCondition[0], 400U * sizeof
           (real_T));

    // InitializeConditions for Memory: '<S116>/Memory'
    memcpy(&proc_control_node_DW.Memory_PreviousInput_o[0],
           &proc_control_node_P.Memory_InitialCondition[0], sizeof(boolean_T) <<
           6U);

    // InitializeConditions for UnitDelay: '<S116>/last_mv'
    memcpy(&proc_control_node_DW.last_mv_DSTATE[0],
           &proc_control_node_P.last_mv_InitialCondition[0], sizeof(real_T) <<
           3U);

    // InitializeConditions for Memory: '<S116>/last_x'
    memcpy(&proc_control_node_DW.last_x_PreviousInput[0],
           &proc_control_node_P.last_x_InitialCondition[0], 20U * sizeof(real_T));

    // InitializeConditions for Delay: '<S110>/Delay1'
    memcpy(&proc_control_node_DW.Delay1_DSTATE[0],
           &proc_control_node_P.Delay1_InitialCondition[0], sizeof(real_T) << 3U);

    // SystemInitialize for Outport: '<S110>/Output'
    proc_control_node_B.status = proc_control_node_P.Output_Y0_n;

    // SystemInitialize for DiscretePulseGenerator: '<S110>/Pulse Generator' incorporates:
    //   Outport: '<S110>/isActive'

    proc_control_node_B.PulseGenerator = proc_control_node_P.isActive_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Quaternion Non linear MPC'
    // InitializeConditions for UnitDelay: '<S111>/UD'
    //
    //  Block description for '<S111>/UD':
    //
    //   Store in Global RAM

    for (i = 0; i < 6; i++) {
      proc_control_node_DW.UD_DSTATE[i] =
        proc_control_node_P.DiscreteDerivative_ICPrevScaled;
    }

    // End of InitializeConditions for UnitDelay: '<S111>/UD'

    // Start for MATLABSystem: '<S109>/MATLAB System'
    proc_control_node_DW.obj_m.k = proc_control_node_P.MATLABSystem_k;
    memcpy(&proc_control_node_DW.obj_m.binv[0], &proc_control_node_P.binv[0],
           48U * sizeof(real_T));
    proc_control_node_DW.obj_m.mass = proc_control_node_P.physics.mass;
    proc_control_node_DW.obj_m.volume = proc_control_node_P.physics.volume;
    proc_control_node_DW.obj_m.height = proc_control_node_P.physics.height;
    memcpy(&proc_control_node_DW.obj_m.I[0], &proc_control_node_P.physics.I[0],
           9U * sizeof(real_T));
    proc_control_node_DW.obj_m.RG[0] = proc_control_node_P.physics.RG[0];
    proc_control_node_DW.obj_m.RB[0] = proc_control_node_P.physics.RB[0];
    proc_control_node_DW.obj_m.RG[1] = proc_control_node_P.physics.RG[1];
    proc_control_node_DW.obj_m.RB[1] = proc_control_node_P.physics.RB[1];
    proc_control_node_DW.obj_m.RG[2] = proc_control_node_P.physics.RG[2];
    proc_control_node_DW.obj_m.RB[2] = proc_control_node_P.physics.RB[2];
    for (i = 0; i < 6; i++) {
      proc_control_node_DW.obj_m.AddedMass[i] =
        proc_control_node_P.physics.AddedMass[i];
      proc_control_node_DW.obj_m.CDL[i] = proc_control_node_P.physics.CDL[i];
      proc_control_node_DW.obj_m.CDQ[i] = proc_control_node_P.physics.CDQ[i];
    }

    proc_control_node_DW.obj_m.AF[0] = proc_control_node_P.physics.AF[0];
    proc_control_node_DW.obj_m.AF[1] = proc_control_node_P.physics.AF[1];
    proc_control_node_DW.obj_m.AF[2] = proc_control_node_P.physics.AF[2];
    proc_control_node_DW.obj_m.g = proc_control_node_P.physics.g;
    proc_control_node_DW.obj_m.rho = proc_control_node_P.physics.rho;
    proc_control_node_DW.obj_m.isInitialized = 1;

    // End of Start for MATLABSystem: '<S109>/MATLAB System'
    // End of SystemInitialize for SubSystem: '<S9>/JoyStick OpenLoop'

    // SystemInitialize for Atomic SubSystem: '<S12>/Subscribe1'
    // Start for MATLABSystem: '<S225>/SourceBlock'
    //  Perform one-time calculations, such as computing constants
    // [M,C,D,Gq] = AUVModelMatrices(in1,in2)
    //  Initialize / reset discrete-state properties
    proc_control_node_DW.obj_o.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      proc_control_node_B.b_zeroDelimTopic_e[i] = tmp_7[i];
    }

    proc_control_node_B.b_zeroDelimTopic_e[18] = '\x00';
    Sub_proc_control_node_203.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_e[0], 1);
    proc_control_node_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S225>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S12>/Subscribe1'
    // Start for Constant: '<S1>/Initial Body velocity '
    proc_control_node_B.InitialBodyvelocity[0] =
      proc_control_node_P.InitialBodyvelocity_Value[0];

    // Start for Constant: '<S1>/Initial Angular Rates'
    proc_control_node_B.InitialAngularRates[0] =
      proc_control_node_P.InitialAngularRates_Value[0];

    // Start for Constant: '<S1>/Initial Body velocity '
    proc_control_node_B.InitialBodyvelocity[1] =
      proc_control_node_P.InitialBodyvelocity_Value[1];

    // Start for Constant: '<S1>/Initial Angular Rates'
    proc_control_node_B.InitialAngularRates[1] =
      proc_control_node_P.InitialAngularRates_Value[1];

    // Start for Constant: '<S1>/Initial Body velocity '
    proc_control_node_B.InitialBodyvelocity[2] =
      proc_control_node_P.InitialBodyvelocity_Value[2];

    // Start for Constant: '<S1>/Initial Angular Rates'
    proc_control_node_B.InitialAngularRates[2] =
      proc_control_node_P.InitialAngularRates_Value[2];

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    if (rtmIsFirstInitCond(proc_control_node_M)) {
      proc_control_node_X.Integrator1_CSTATE[0] = 0.0;
      proc_control_node_X.Integrator1_CSTATE[1] = 0.0;
      proc_control_node_X.Integrator1_CSTATE[2] = 0.0;
      proc_control_node_X.Integrator1_CSTATE[3] = 0.0;
    }

    proc_control_node_DW.Integrator1_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S1>/Integrator1'

    // InitializeConditions for TransferFcn: '<S20>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE = 0.0;

    // InitializeConditions for TransferFcn: '<S21>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_o = 0.0;

    // InitializeConditions for TransferFcn: '<S22>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_p = 0.0;

    // InitializeConditions for TransferFcn: '<S23>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_a = 0.0;

    // InitializeConditions for TransferFcn: '<S24>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_f = 0.0;

    // InitializeConditions for TransferFcn: '<S25>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_e = 0.0;

    // InitializeConditions for TransferFcn: '<S26>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_ft = 0.0;

    // InitializeConditions for TransferFcn: '<S27>/Transfer Fcn'
    proc_control_node_X.TransferFcn_CSTATE_fu = 0.0;

    // InitializeConditions for UniformRandomNumber: '<S16>/X Drift'
    proc_control_node_B.Constant3 = floor(proc_control_node_P.dSeedX);
    if (rtIsNaN(proc_control_node_B.Constant3) || rtIsInf
        (proc_control_node_B.Constant3)) {
      proc_control_node_B.Constant3 = 0.0;
    } else {
      proc_control_node_B.Constant3 = fmod(proc_control_node_B.Constant3,
        4.294967296E+9);
    }

    tseed = proc_control_node_B.Constant3 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-proc_control_node_B.Constant3)))
      : static_cast<uint32_T>(proc_control_node_B.Constant3);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    proc_control_node_DW.RandSeed = tseed;
    proc_control_node_DW.XDrift_NextOutput = (proc_control_node_P.dMaxX -
      proc_control_node_P.dMinX) * rt_urand_Upu32_Yd_f_pw_snf
      (&proc_control_node_DW.RandSeed) + proc_control_node_P.dMinX;

    // End of InitializeConditions for UniformRandomNumber: '<S16>/X Drift'

    // InitializeConditions for UniformRandomNumber: '<S16>/Y Drift'
    proc_control_node_B.Constant3 = floor(proc_control_node_P.dSeedY);
    if (rtIsNaN(proc_control_node_B.Constant3) || rtIsInf
        (proc_control_node_B.Constant3)) {
      proc_control_node_B.Constant3 = 0.0;
    } else {
      proc_control_node_B.Constant3 = fmod(proc_control_node_B.Constant3,
        4.294967296E+9);
    }

    tseed = proc_control_node_B.Constant3 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-proc_control_node_B.Constant3)))
      : static_cast<uint32_T>(proc_control_node_B.Constant3);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    proc_control_node_DW.RandSeed_a = tseed;
    proc_control_node_DW.YDrift_NextOutput = (proc_control_node_P.dMaxY -
      proc_control_node_P.dMinY) * rt_urand_Upu32_Yd_f_pw_snf
      (&proc_control_node_DW.RandSeed_a) + proc_control_node_P.dMinY;

    // End of InitializeConditions for UniformRandomNumber: '<S16>/Y Drift'

    // InitializeConditions for Integrator: '<S1>/Integrator' incorporates:
    //   Integrator: '<S1>/Integrator2'

    if (rtmIsFirstInitCond(proc_control_node_M)) {
      proc_control_node_X.Integrator_CSTATE[0] = 0.0;
      proc_control_node_X.Integrator_CSTATE[1] = 0.0;
      proc_control_node_X.Integrator_CSTATE[2] = 0.0;
      proc_control_node_X.Integrator2_CSTATE[0] = 0.0;
      proc_control_node_X.Integrator2_CSTATE[1] = 0.0;
      proc_control_node_X.Integrator2_CSTATE[2] = 0.0;
    }

    proc_control_node_DW.Integrator_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S1>/Integrator'

    // InitializeConditions for Integrator: '<S1>/Integrator2'
    proc_control_node_DW.Integrator2_IWORK = 1;

    // InitializeConditions for Integrator: '<S1>/Integrator3'
    if (rtmIsFirstInitCond(proc_control_node_M)) {
      proc_control_node_X.Integrator3_CSTATE[0] = 0.0;
      proc_control_node_X.Integrator3_CSTATE[1] = 0.0;
      proc_control_node_X.Integrator3_CSTATE[2] = 0.0;
    }

    proc_control_node_DW.Integrator3_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S1>/Integrator3'

    // InitializeConditions for RandomNumber: '<S28>/White Noise'
    proc_control_node_B.Constant3 = floor
      (proc_control_node_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(proc_control_node_B.Constant3) || rtIsInf
        (proc_control_node_B.Constant3)) {
      proc_control_node_B.Constant3 = 0.0;
    } else {
      proc_control_node_B.Constant3 = fmod(proc_control_node_B.Constant3,
        4.294967296E+9);
    }

    tseed = proc_control_node_B.Constant3 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-proc_control_node_B.Constant3)))
      : static_cast<uint32_T>(proc_control_node_B.Constant3);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    proc_control_node_DW.RandSeed_j = tseed;
    proc_control_node_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&proc_control_node_DW.RandSeed_j) * proc_control_node_P.WhiteNoise_StdDev
      + proc_control_node_P.WhiteNoise_Mean;

    // End of InitializeConditions for RandomNumber: '<S28>/White Noise'

    // InitializeConditions for RandomNumber: '<S29>/White Noise'
    proc_control_node_B.Constant3 = floor
      (proc_control_node_P.BandLimitedWhiteNoise1_seed);
    if (rtIsNaN(proc_control_node_B.Constant3) || rtIsInf
        (proc_control_node_B.Constant3)) {
      proc_control_node_B.Constant3 = 0.0;
    } else {
      proc_control_node_B.Constant3 = fmod(proc_control_node_B.Constant3,
        4.294967296E+9);
    }

    tseed = proc_control_node_B.Constant3 < 0.0 ? static_cast<uint32_T>(-
      static_cast<int32_T>(static_cast<uint32_T>(-proc_control_node_B.Constant3)))
      : static_cast<uint32_T>(proc_control_node_B.Constant3);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    tseed = ((((tseed - (static_cast<uint32_T>(i) << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    proc_control_node_DW.RandSeed_d = tseed;
    proc_control_node_DW.NextOutput_b = rt_nrand_Upu32_Yd_f_pw_snf
      (&proc_control_node_DW.RandSeed_d) *
      proc_control_node_P.WhiteNoise_StdDev_d +
      proc_control_node_P.WhiteNoise_Mean_e;

    // End of InitializeConditions for RandomNumber: '<S29>/White Noise'

    // Start for MATLABSystem: '<S19>/IMU'
    proc_control_node_DW.obj_c.MagneticFieldNED[0] = 27.555;
    proc_control_node_DW.obj_c.MagneticFieldNED[1] = -2.4169;
    proc_control_node_DW.obj_c.MagneticFieldNED[2] = -16.0849;
    proc_control_node_DW.obj_c.isInitialized = 0;
    for (i = 0; i < 32; i++) {
      proc_control_node_DW.obj_c.tunablePropertyChanged[i] = false;
    }

    proc_control_node_B.Constant3 = proc_control_node_DW.obj_c.MagneticFieldNED
      [0];
    proc_control_node_B.Constant2 = proc_control_node_DW.obj_c.MagneticFieldNED
      [1];
    proc_control_node_B.mf_idx_2 = proc_control_node_DW.obj_c.MagneticFieldNED[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[2] = true;
    }

    proc_control_node_DW.obj_c.MagneticField[0] = proc_control_node_B.Constant3;
    proc_control_node_DW.obj_c.MagneticField[1] = proc_control_node_B.Constant2;
    proc_control_node_DW.obj_c.MagneticField[2] = proc_control_node_B.mf_idx_2;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[31] = true;
    }

    proc_control_node_DW.obj_c.Temperature = proc_control_node_P.IMU_Temperature;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[0] = true;
    }

    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[2] = true;
    }

    proc_control_node_DW.obj_c.MagneticField[0] =
      proc_control_node_P.IMU_MagneticFieldNED[0];
    proc_control_node_DW.obj_c.MagneticField[1] =
      proc_control_node_P.IMU_MagneticFieldNED[1];
    proc_control_node_DW.obj_c.MagneticField[2] =
      proc_control_node_P.IMU_MagneticFieldNED[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[3] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsMeasurementRange =
      proc_control_node_P.IMU_AccelParamsMeasurementRange;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[4] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsResolution =
      proc_control_node_P.IMU_AccelParamsResolution;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[5] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsConstantBias[0] =
      proc_control_node_P.IMU_AccelParamsConstantBias[0];
    proc_control_node_DW.obj_c.AccelParamsConstantBias[1] =
      proc_control_node_P.IMU_AccelParamsConstantBias[1];
    proc_control_node_DW.obj_c.AccelParamsConstantBias[2] =
      proc_control_node_P.IMU_AccelParamsConstantBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[6] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[0] =
      proc_control_node_P.IMU_AccelParamsAxesMisalignment[0];
    proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[1] =
      proc_control_node_P.IMU_AccelParamsAxesMisalignment[1];
    proc_control_node_DW.obj_c.AccelParamsAxesMisalignment[2] =
      proc_control_node_P.IMU_AccelParamsAxesMisalignment[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[7] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsNoiseDensity[0] =
      proc_control_node_P.IMU_AccelParamsNoiseDensity[0];
    proc_control_node_DW.obj_c.AccelParamsNoiseDensity[1] =
      proc_control_node_P.IMU_AccelParamsNoiseDensity[1];
    proc_control_node_DW.obj_c.AccelParamsNoiseDensity[2] =
      proc_control_node_P.IMU_AccelParamsNoiseDensity[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[8] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsBiasInstability[0] =
      proc_control_node_P.IMU_AccelParamsBiasInstability[0];
    proc_control_node_DW.obj_c.AccelParamsBiasInstability[1] =
      proc_control_node_P.IMU_AccelParamsBiasInstability[1];
    proc_control_node_DW.obj_c.AccelParamsBiasInstability[2] =
      proc_control_node_P.IMU_AccelParamsBiasInstability[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[9] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsRandomWalk[0] =
      proc_control_node_P.IMU_AccelParamsRandomWalk[0];
    proc_control_node_DW.obj_c.AccelParamsRandomWalk[1] =
      proc_control_node_P.IMU_AccelParamsRandomWalk[1];
    proc_control_node_DW.obj_c.AccelParamsRandomWalk[2] =
      proc_control_node_P.IMU_AccelParamsRandomWalk[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[10] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsTemperatureBias[0] =
      proc_control_node_P.IMU_AccelParamsTemperatureBias[0];
    proc_control_node_DW.obj_c.AccelParamsTemperatureBias[1] =
      proc_control_node_P.IMU_AccelParamsTemperatureBias[1];
    proc_control_node_DW.obj_c.AccelParamsTemperatureBias[2] =
      proc_control_node_P.IMU_AccelParamsTemperatureBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[11] = true;
    }

    proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[0] =
      proc_control_node_P.IMU_AccelParamsTemperatureScale[0];
    proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[1] =
      proc_control_node_P.IMU_AccelParamsTemperatureScale[1];
    proc_control_node_DW.obj_c.AccelParamsTemperatureScaleFactor[2] =
      proc_control_node_P.IMU_AccelParamsTemperatureScale[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[12] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsMeasurementRange =
      proc_control_node_P.IMU_GyroParamsMeasurementRange;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[13] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsResolution =
      proc_control_node_P.IMU_GyroParamsResolution;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[14] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsConstantBias[0] =
      proc_control_node_P.IMU_GyroParamsConstantBias[0];
    proc_control_node_DW.obj_c.GyroParamsConstantBias[1] =
      proc_control_node_P.IMU_GyroParamsConstantBias[1];
    proc_control_node_DW.obj_c.GyroParamsConstantBias[2] =
      proc_control_node_P.IMU_GyroParamsConstantBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[15] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[0] =
      proc_control_node_P.IMU_GyroParamsAxesMisalignment[0];
    proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[1] =
      proc_control_node_P.IMU_GyroParamsAxesMisalignment[1];
    proc_control_node_DW.obj_c.GyroParamsAxesMisalignment[2] =
      proc_control_node_P.IMU_GyroParamsAxesMisalignment[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[21] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsAccelerationBias[0] =
      proc_control_node_P.IMU_GyroParamsAccelerationBias[0];
    proc_control_node_DW.obj_c.GyroParamsAccelerationBias[1] =
      proc_control_node_P.IMU_GyroParamsAccelerationBias[1];
    proc_control_node_DW.obj_c.GyroParamsAccelerationBias[2] =
      proc_control_node_P.IMU_GyroParamsAccelerationBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[16] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsNoiseDensity[0] =
      proc_control_node_P.IMU_GyroParamsNoiseDensity[0];
    proc_control_node_DW.obj_c.GyroParamsNoiseDensity[1] =
      proc_control_node_P.IMU_GyroParamsNoiseDensity[1];
    proc_control_node_DW.obj_c.GyroParamsNoiseDensity[2] =
      proc_control_node_P.IMU_GyroParamsNoiseDensity[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[17] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsBiasInstability[0] =
      proc_control_node_P.IMU_GyroParamsBiasInstability[0];
    proc_control_node_DW.obj_c.GyroParamsBiasInstability[1] =
      proc_control_node_P.IMU_GyroParamsBiasInstability[1];
    proc_control_node_DW.obj_c.GyroParamsBiasInstability[2] =
      proc_control_node_P.IMU_GyroParamsBiasInstability[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[18] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsRandomWalk[0] =
      proc_control_node_P.IMU_GyroParamsRandomWalk[0];
    proc_control_node_DW.obj_c.GyroParamsRandomWalk[1] =
      proc_control_node_P.IMU_GyroParamsRandomWalk[1];
    proc_control_node_DW.obj_c.GyroParamsRandomWalk[2] =
      proc_control_node_P.IMU_GyroParamsRandomWalk[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[19] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsTemperatureBias[0] =
      proc_control_node_P.IMU_GyroParamsTemperatureBias[0];
    proc_control_node_DW.obj_c.GyroParamsTemperatureBias[1] =
      proc_control_node_P.IMU_GyroParamsTemperatureBias[1];
    proc_control_node_DW.obj_c.GyroParamsTemperatureBias[2] =
      proc_control_node_P.IMU_GyroParamsTemperatureBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[20] = true;
    }

    proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[0] =
      proc_control_node_P.IMU_GyroParamsTemperatureScaleF[0];
    proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[1] =
      proc_control_node_P.IMU_GyroParamsTemperatureScaleF[1];
    proc_control_node_DW.obj_c.GyroParamsTemperatureScaleFactor[2] =
      proc_control_node_P.IMU_GyroParamsTemperatureScaleF[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[22] = true;
    }

    proc_control_node_DW.obj_c.MagParamsMeasurementRange =
      proc_control_node_P.IMU_MagParamsMeasurementRange;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[23] = true;
    }

    proc_control_node_DW.obj_c.MagParamsResolution =
      proc_control_node_P.IMU_MagParamsResolution;
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[24] = true;
    }

    proc_control_node_DW.obj_c.MagParamsConstantBias[0] =
      proc_control_node_P.IMU_MagParamsConstantBias[0];
    proc_control_node_DW.obj_c.MagParamsConstantBias[1] =
      proc_control_node_P.IMU_MagParamsConstantBias[1];
    proc_control_node_DW.obj_c.MagParamsConstantBias[2] =
      proc_control_node_P.IMU_MagParamsConstantBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[25] = true;
    }

    proc_control_node_DW.obj_c.MagParamsAxesMisalignment[0] =
      proc_control_node_P.IMU_MagParamsAxesMisalignment[0];
    proc_control_node_DW.obj_c.MagParamsAxesMisalignment[1] =
      proc_control_node_P.IMU_MagParamsAxesMisalignment[1];
    proc_control_node_DW.obj_c.MagParamsAxesMisalignment[2] =
      proc_control_node_P.IMU_MagParamsAxesMisalignment[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[26] = true;
    }

    proc_control_node_DW.obj_c.MagParamsNoiseDensity[0] =
      proc_control_node_P.IMU_MagParamsNoiseDensity[0];
    proc_control_node_DW.obj_c.MagParamsNoiseDensity[1] =
      proc_control_node_P.IMU_MagParamsNoiseDensity[1];
    proc_control_node_DW.obj_c.MagParamsNoiseDensity[2] =
      proc_control_node_P.IMU_MagParamsNoiseDensity[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[27] = true;
    }

    proc_control_node_DW.obj_c.MagParamsBiasInstability[0] =
      proc_control_node_P.IMU_MagParamsBiasInstability[0];
    proc_control_node_DW.obj_c.MagParamsBiasInstability[1] =
      proc_control_node_P.IMU_MagParamsBiasInstability[1];
    proc_control_node_DW.obj_c.MagParamsBiasInstability[2] =
      proc_control_node_P.IMU_MagParamsBiasInstability[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[28] = true;
    }

    proc_control_node_DW.obj_c.MagParamsRandomWalk[0] =
      proc_control_node_P.IMU_MagParamsRandomWalk[0];
    proc_control_node_DW.obj_c.MagParamsRandomWalk[1] =
      proc_control_node_P.IMU_MagParamsRandomWalk[1];
    proc_control_node_DW.obj_c.MagParamsRandomWalk[2] =
      proc_control_node_P.IMU_MagParamsRandomWalk[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[29] = true;
    }

    proc_control_node_DW.obj_c.MagParamsTemperatureBias[0] =
      proc_control_node_P.IMU_MagParamsTemperatureBias[0];
    proc_control_node_DW.obj_c.MagParamsTemperatureBias[1] =
      proc_control_node_P.IMU_MagParamsTemperatureBias[1];
    proc_control_node_DW.obj_c.MagParamsTemperatureBias[2] =
      proc_control_node_P.IMU_MagParamsTemperatureBias[2];
    flag = (proc_control_node_DW.obj_c.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_c.TunablePropsChanged = true;
      proc_control_node_DW.obj_c.tunablePropertyChanged[30] = true;
    }

    proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[0] =
      proc_control_node_P.IMU_MagParamsTemperatureScaleFa[0];
    proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[1] =
      proc_control_node_P.IMU_MagParamsTemperatureScaleFa[1];
    proc_control_node_DW.obj_c.MagParamsTemperatureScaleFactor[2] =
      proc_control_node_P.IMU_MagParamsTemperatureScaleFa[2];
    proc_control_n_SystemCore_setup(&proc_control_node_DW.obj_c);

    // End of Start for MATLABSystem: '<S19>/IMU'

    // InitializeConditions for MATLABSystem: '<S19>/IMU'
    proc_co_IMUSensorBase_resetImpl(&proc_control_node_DW.obj_c);

    // Start for MATLABSystem: '<S19>/AHRS' incorporates:
    //   MATLABSystem: '<S19>/IMU'

    proc_control_node_DW.obj_l.isInitialized = 0;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.AccelerometerNoise =
      proc_control_node_P.AHRS_AccelerometerNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.GyroscopeNoise =
      proc_control_node_P.AHRS_GyroscopeNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.MagnetometerNoise =
      proc_control_node_P.AHRS_MagnetometerNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.GyroscopeDriftNoise =
      proc_control_node_P.AHRS_GyroscopeDriftNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.LinearAccelerationNoise =
      proc_control_node_P.AHRS_LinearAccelerationNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.MagneticDisturbanceNoise =
      proc_control_node_P.AHRS_MagneticDisturbanceNoise;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.LinearAccelerationDecayFactor =
      proc_control_node_P.AHRS_LinearAccelerationDecayFac;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.MagneticDisturbanceDecayFactor =
      proc_control_node_P.AHRS_MagneticDisturbanceDecayFa;
    flag = (proc_control_node_DW.obj_l.isInitialized == 1);
    if (flag) {
      proc_control_node_DW.obj_l.TunablePropsChanged = true;
    }

    proc_control_node_DW.obj_l.ExpectedMagneticFieldStrength =
      proc_control_node_P.AHRS_ExpectedMagneticFieldStren;
    proc_control_node_DW.obj_l.isInitialized = 1;
    proc_control_node_DW.obj_l.pInputPrototype[0] =
      proc_control_node_B.rtb_Transpose_k_idx_0;
    proc_control_node_DW.obj_l.pInputPrototype[1] =
      proc_control_node_B.rtb_Transpose_k_idx_0;
    proc_control_node_DW.obj_l.pInputPrototype[2] =
      proc_control_node_B.rtb_Transpose_k_idx_0;
    proc_control_node_DW.obj_l.pSensorPeriod = 0.016666666666666666;
    proc_control_node_DW.obj_l.pKalmanPeriod =
      proc_control_node_DW.obj_l.pSensorPeriod;
    proc_control_node_DW.obj_l.pRefSys = &proc_control_node_DW.obj_l._pobj0;
    proc_control_node_DW.obj_l.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S19>/AHRS'

    // InitializeConditions for MATLABSystem: '<S19>/AHRS'
    proc_c_AHRSFilterBase_resetImpl(&proc_control_node_DW.obj_l);

    // SystemInitialize for Outport: '<S1>/Clean Output'
    proc_control_node_B.y_gh[0] = proc_control_node_P.CleanOutput_Y0.Quaternion
      [0];
    proc_control_node_B.y_gh[1] = proc_control_node_P.CleanOutput_Y0.Quaternion
      [1];
    proc_control_node_B.y_gh[2] = proc_control_node_P.CleanOutput_Y0.Quaternion
      [2];
    proc_control_node_B.y_gh[3] = proc_control_node_P.CleanOutput_Y0.Quaternion
      [3];

    // SystemInitialize for Sum: '<S18>/Sum1' incorporates:
    //   Outport: '<S1>/Sensors Output'

    proc_control_node_B.Quaternion_k[0] =
      proc_control_node_P.SensorsOutput_Y0.Quaternion[0];
    proc_control_node_B.Quaternion_k[1] =
      proc_control_node_P.SensorsOutput_Y0.Quaternion[1];
    proc_control_node_B.Quaternion_k[2] =
      proc_control_node_P.SensorsOutput_Y0.Quaternion[2];
    proc_control_node_B.Quaternion_k[3] =
      proc_control_node_P.SensorsOutput_Y0.Quaternion[3];

    // End of SystemInitialize for SubSystem: '<Root>/Modèle Physique'

    // SystemInitialize for Enabled SubSystem: '<S85>/Subsystem2'
    proc_control_no_Subsystem2_Init(&proc_control_node_B.q0_c,
      &proc_control_node_B.q1_p, &proc_control_node_B.q2_k,
      &proc_control_node_B.q3_d, &proc_control_node_P.Subsystem2);

    // End of SystemInitialize for SubSystem: '<S85>/Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<Root>/ROS Output'
    // SystemInitialize for Atomic SubSystem: '<S63>/Publish'
    // Start for MATLABSystem: '<S67>/SinkBlock'
    proc_control_node_DW.obj_k.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 28; i++) {
      proc_control_node_B.b_zeroDelimTopic_m[i] = tmp_8[i];
    }

    proc_control_node_B.b_zeroDelimTopic_m[28] = '\x00';
    Pub_proc_control_node_41.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_m[0], 1);
    proc_control_node_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S67>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S63>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S64>/Publish'
    // Start for MATLABSystem: '<S70>/SinkBlock'
    proc_control_node_DW.obj_ab.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_ab.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      proc_control_node_B.b_zeroDelimTopic_h[i] = tmp_9[i];
    }

    proc_control_node_B.b_zeroDelimTopic_h[24] = '\x00';
    Pub_proc_control_node_47.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_h[0], 1);
    proc_control_node_DW.obj_ab.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S70>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S64>/Publish'

    // SystemInitialize for SignalConversion generated from: '<S4>/Output' incorporates:
    //   Outport: '<S4>/Output'

    proc_control_node_B.Quaternion_l[0] =
      proc_control_node_P.Output_Y0.Quaternion[0];
    proc_control_node_B.Quaternion_l[1] =
      proc_control_node_P.Output_Y0.Quaternion[1];
    proc_control_node_B.Quaternion_l[2] =
      proc_control_node_P.Output_Y0.Quaternion[2];
    proc_control_node_B.Quaternion_l[3] =
      proc_control_node_P.Output_Y0.Quaternion[3];

    // End of SystemInitialize for SubSystem: '<Root>/ROS Output'
    // Start for If: '<S51>/If'
    proc_control_node_DW.If_ActiveSubsystem_j = -1;

    // End of SystemInitialize for SubSystem: '<Root>/Plot values'

    // SystemInitialize for Atomic SubSystem: '<S5>/Publish2'
    // Start for MATLABSystem: '<S75>/SinkBlock'
    proc_control_node_DW.obj_p.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 31; i++) {
      proc_control_node_B.b_zeroDelimTopic[i] = tmp_a[i];
    }

    proc_control_node_B.b_zeroDelimTopic[31] = '\x00';
    Pub_proc_control_node_104.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic[0], 1);
    proc_control_node_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S75>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<S5>/Publish3'
    // Start for MATLABSystem: '<S76>/SinkBlock'
    proc_control_node_DW.obj_mj.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_mj.isInitialized = 1;
    for (i = 0; i < 23; i++) {
      proc_control_node_B.b_zeroDelimTopic_c[i] = tmp_b[i];
    }

    proc_control_node_B.b_zeroDelimTopic_c[23] = '\x00';
    Pub_proc_control_node_105.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_c[0], 1);
    proc_control_node_DW.obj_mj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S76>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<S5>/Publish4'
    // Start for MATLABSystem: '<S77>/SinkBlock'
    proc_control_node_DW.obj_lfp.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_lfp.isInitialized = 1;
    for (i = 0; i < 26; i++) {
      proc_control_node_B.b_zeroDelimTopic_j[i] = tmp_c[i];
    }

    proc_control_node_B.b_zeroDelimTopic_j[26] = '\x00';
    Pub_proc_control_node_106.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_j[0], 1);
    proc_control_node_DW.obj_lfp.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S77>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S5>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<S6>/Publish'
    // Start for MATLABSystem: '<S79>/SinkBlock'
    proc_control_node_DW.obj_eb.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_eb.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      proc_control_node_B.b_zeroDelimTopic_p[i] = tmp_d[i];
    }

    proc_control_node_B.b_zeroDelimTopic_p[22] = '\x00';
    Pub_proc_control_node_116.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_p[0], 1);
    proc_control_node_DW.obj_eb.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S79>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S6>/Publish'

    // SystemInitialize for Merge: '<S11>/Merge1'
    proc_control_node_B.Merge1 = proc_control_node_P.Merge1_InitialOutput;

    // SystemInitialize for Triggered SubSystem: '<Root>/Send Target Reached '
    // SystemInitialize for Atomic SubSystem: '<S7>/Publish'
    // Start for MATLABSystem: '<S81>/SinkBlock'
    proc_control_node_DW.obj_lf.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_lf.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      proc_control_node_B.b_zeroDelimTopic_m3[i] = tmp_e[i];
    }

    proc_control_node_B.b_zeroDelimTopic_m3[27] = '\x00';
    Pub_proc_control_node_122.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_m3[0], 1);
    proc_control_node_DW.obj_lf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S81>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S7>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Send Target Reached '

    // SystemInitialize for Atomic SubSystem: '<S82>/Publish'
    // Start for MATLABSystem: '<S87>/SinkBlock'
    proc_control_node_DW.obj_lj.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_lj.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      proc_control_node_B.b_zeroDelimTopic_h[i] = tmp_f[i];
    }

    proc_control_node_B.b_zeroDelimTopic_h[24] = '\x00';
    Pub_proc_control_node_140.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_h[0], 1);
    proc_control_node_DW.obj_lj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S87>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S82>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S83>/Publish'
    // Start for MATLABSystem: '<S107>/SinkBlock'
    proc_control_node_DW.obj_le.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_le.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      proc_control_node_B.b_zeroDelimTopic_p[i] = tmp_g[i];
    }

    proc_control_node_B.b_zeroDelimTopic_p[22] = '\x00';
    Pub_proc_control_node_151.createPublisher
      (&proc_control_node_B.b_zeroDelimTopic_p[0], 1);
    proc_control_node_DW.obj_le.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S107>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S83>/Publish'

    // SystemInitialize for Atomic SubSystem: '<S12>/Subscribe4'
    // Start for MATLABSystem: '<S228>/SourceBlock'
    proc_control_node_DW.obj_a4.matlabCodegenIsDeleted = false;
    proc_control_node_DW.obj_a4.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      proc_control_node_B.b_zeroDelimTopic_ex[i] = tmp_h[i];
    }

    proc_control_node_B.b_zeroDelimTopic_ex[13] = '\x00';
    Sub_proc_control_node_206.createSubscriber
      (&proc_control_node_B.b_zeroDelimTopic_ex[0], 1);
    proc_control_node_DW.obj_a4.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S228>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S12>/Subscribe4'
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(proc_control_node_M)) {
    rtmSetFirstInitCond(proc_control_node_M, 0);
  }
}

// Model terminate function
void proc_control_node_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S12>/Subscribe2'
  // Terminate for MATLABSystem: '<S226>/SourceBlock'
  if (!proc_control_node_DW.obj_e.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S226>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S3>/Subscribe'
  // Terminate for MATLABSystem: '<S59>/SourceBlock'
  if (!proc_control_node_DW.obj_lu.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_lu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S59>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe'

  // Terminate for Atomic SubSystem: '<S3>/Subscribe1'
  // Terminate for MATLABSystem: '<S60>/SourceBlock'
  if (!proc_control_node_DW.obj_mm.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_mm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S60>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S12>/Subscribe'
  // Terminate for MATLABSystem: '<S224>/SourceBlock'
  if (!proc_control_node_DW.obj_g.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S224>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/Subscribe'

  // Terminate for Atomic SubSystem: '<S12>/Subscribe3'
  // Terminate for MATLABSystem: '<S227>/SourceBlock'
  if (!proc_control_node_DW.obj_f.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S227>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/Subscribe3'

  // Terminate for Atomic SubSystem: '<S189>/Subscribe2'
  // Terminate for MATLABSystem: '<S195>/SourceBlock'
  if (!proc_control_node_DW.obj_cs.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_cs.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S195>/SourceBlock'
  // End of Terminate for SubSystem: '<S189>/Subscribe2'

  // Terminate for IfAction SubSystem: '<S11>/singleWpts Trajectory'
  // Terminate for Atomic SubSystem: '<S192>/Subscribe'
  // Terminate for MATLABSystem: '<S206>/SourceBlock'
  if (!proc_control_node_DW.obj_h.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S206>/SourceBlock'
  // End of Terminate for SubSystem: '<S192>/Subscribe'
  // End of Terminate for SubSystem: '<S11>/singleWpts Trajectory'

  // Terminate for Atomic SubSystem: '<S12>/Subscribe1'
  // Terminate for MATLABSystem: '<S225>/SourceBlock'
  if (!proc_control_node_DW.obj_o.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S225>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/Subscribe1'

  // Terminate for Enabled SubSystem: '<Root>/ROS Output'
  // Terminate for Atomic SubSystem: '<S63>/Publish'
  // Terminate for MATLABSystem: '<S67>/SinkBlock'
  if (!proc_control_node_DW.obj_k.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S67>/SinkBlock'
  // End of Terminate for SubSystem: '<S63>/Publish'

  // Terminate for Atomic SubSystem: '<S64>/Publish'
  // Terminate for MATLABSystem: '<S70>/SinkBlock'
  if (!proc_control_node_DW.obj_ab.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_ab.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/SinkBlock'
  // End of Terminate for SubSystem: '<S64>/Publish'
  // End of Terminate for SubSystem: '<Root>/ROS Output'

  // Terminate for Atomic SubSystem: '<S5>/Publish2'
  // Terminate for MATLABSystem: '<S75>/SinkBlock'
  if (!proc_control_node_DW.obj_p.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S75>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish2'

  // Terminate for Atomic SubSystem: '<S5>/Publish3'
  // Terminate for MATLABSystem: '<S76>/SinkBlock'
  if (!proc_control_node_DW.obj_mj.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_mj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S76>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish3'

  // Terminate for Atomic SubSystem: '<S5>/Publish4'
  // Terminate for MATLABSystem: '<S77>/SinkBlock'
  if (!proc_control_node_DW.obj_lfp.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_lfp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S77>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish4'

  // Terminate for Atomic SubSystem: '<S6>/Publish'
  // Terminate for MATLABSystem: '<S79>/SinkBlock'
  if (!proc_control_node_DW.obj_eb.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_eb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S79>/SinkBlock'
  // End of Terminate for SubSystem: '<S6>/Publish'

  // Terminate for Triggered SubSystem: '<Root>/Send Target Reached '
  // Terminate for Atomic SubSystem: '<S7>/Publish'
  // Terminate for MATLABSystem: '<S81>/SinkBlock'
  if (!proc_control_node_DW.obj_lf.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_lf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/SinkBlock'
  // End of Terminate for SubSystem: '<S7>/Publish'
  // End of Terminate for SubSystem: '<Root>/Send Target Reached '

  // Terminate for Atomic SubSystem: '<S82>/Publish'
  // Terminate for MATLABSystem: '<S87>/SinkBlock'
  if (!proc_control_node_DW.obj_lj.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_lj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S87>/SinkBlock'
  // End of Terminate for SubSystem: '<S82>/Publish'

  // Terminate for Atomic SubSystem: '<S83>/Publish'
  // Terminate for MATLABSystem: '<S107>/SinkBlock'
  if (!proc_control_node_DW.obj_le.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_le.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S107>/SinkBlock'
  // End of Terminate for SubSystem: '<S83>/Publish'

  // Terminate for Atomic SubSystem: '<S12>/Subscribe4'
  // Terminate for MATLABSystem: '<S228>/SourceBlock'
  if (!proc_control_node_DW.obj_a4.matlabCodegenIsDeleted) {
    proc_control_node_DW.obj_a4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S228>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/Subscribe4'
}

//
// File trailer for generated code.
//
// [EOF]
//
