//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node_types.h
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
#ifndef RTW_HEADER_proc_control_node_types_h_
#define RTW_HEADER_proc_control_node_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_proc_control_node_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_proc_control_node_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_proc_control_node_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_proc_control_node_geometry_msgs_Quaternion
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_proc_control_node_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
struct SL_Bus_proc_control_node_sensor_msgs_Imu
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_node_std_msgs_Header Header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_proc_control_node_geometry_msgs_Quaternion Orientation;
  real_T OrientationCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_node_geometry_msgs_Vector3 AngularVelocity;
  real_T AngularVelocityCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_node_geometry_msgs_Vector3 LinearAcceleration;
  real_T LinearAccelerationCovariance[9];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL_

// MsgType=sonia_common/BodyVelocityDVL
struct SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_node_std_msgs_Header Header;
  real_T XVelBtm;
  real_T YVelBtm;
  real_T ZVelBtm;
  real_T EVelBtm;
  real_T Velocity1;
  real_T Velocity2;
  real_T Velocity3;
  real_T Velocity4;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
struct SL_Bus_proc_control_node_std_msgs_MultiArrayDimension
{
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
struct SL_Bus_proc_control_node_std_msgs_MultiArrayLayout
{
  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_proc_control_node_std_msgs_MultiArrayDimension Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
  uint32_T DataOffset;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_UInt16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_UInt16MultiArray_

// MsgType=std_msgs/UInt16MultiArray
struct SL_Bus_proc_control_node_std_msgs_UInt16MultiArray
{
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_proc_control_node_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  uint16_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Int8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Int8_

// MsgType=std_msgs/Int8
struct SL_Bus_proc_control_node_std_msgs_Int8
{
  int8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_Bool_

// MsgType=std_msgs/Bool
struct SL_Bus_proc_control_node_std_msgs_Bool
{
  boolean_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_proc_control_node_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_node_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_node_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_proc_control_node_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sonia_common_AddPose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sonia_common_AddPose_

// MsgType=sonia_common/AddPose
struct SL_Bus_proc_control_node_sonia_common_AddPose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_proc_control_node_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_node_geometry_msgs_Vector3 Orientation;
  uint8_T Frame;
  uint8_T Speed;
  real_T Fine;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_proc_control_node_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_proc_control_node_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_proc_control_node_geometry_msgs_Quaternion Orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_std_msgs_UInt8_

// MsgType=std_msgs/UInt8
struct SL_Bus_proc_control_node_std_msgs_UInt8
{
  uint8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_node_sensor_msgs_Joy_

// MsgType=sensor_msgs/Joy
struct SL_Bus_proc_control_node_sensor_msgs_Joy
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_node_std_msgs_Header Header;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Axes_SL_Info:TruncateAction=warn
  real32_T Axes[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Axes
  SL_Bus_ROSVariableLengthArrayInfo Axes_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Buttons_SL_Info:TruncateAction=warn 
  int32_T Buttons[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Buttons
  SL_Bus_ROSVariableLengthArrayInfo Buttons_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XEwOoQFSJ0yXWTYDIQhbTC_
#define DEFINED_TYPEDEF_FOR_struct_XEwOoQFSJ0yXWTYDIQhbTC_

struct struct_XEwOoQFSJ0yXWTYDIQhbTC
{
  real_T mass;
  real_T volume;
  real_T rho;
  real_T g;
  real_T dvlCenterDist;
  real_T height;
  real_T I[9];
  real_T RG[3];
  real_T RB[3];
  real_T CDL[6];
  real_T CDQ[6];
  real_T AF[3];
  real_T AddedMass[6];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tPdF4cj4QxksKOpHPnjYAD_
#define DEFINED_TYPEDEF_FOR_struct_tPdF4cj4QxksKOpHPnjYAD_

struct struct_tPdF4cj4QxksKOpHPnjYAD
{
  real_T OV[13];
  real_T MV[8];
  real_T MVR[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tms366ZdLAbQ6I7by2QYMH_
#define DEFINED_TYPEDEF_FOR_struct_tms366ZdLAbQ6I7by2QYMH_

struct struct_tms366ZdLAbQ6I7by2QYMH
{
  struct_tPdF4cj4QxksKOpHPnjYAD defaut;
  struct_tPdF4cj4QxksKOpHPnjYAD c10;
  struct_tPdF4cj4QxksKOpHPnjYAD c19;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ItE4fzFYlf4Io3uBaGCY9F_
#define DEFINED_TYPEDEF_FOR_struct_ItE4fzFYlf4Io3uBaGCY9F_

struct struct_ItE4fzFYlf4Io3uBaGCY9F
{
  real_T nx;
  real_T ny;
  real_T nu;
  real_T Ts;
  real_T p;
  real_T m;
  real_T tmax;
  real_T tmin;
  struct_tms366ZdLAbQ6I7by2QYMH gains;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_
#define DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_

struct struct_qYRJtcce7MM7XuQ3AAWdMD
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_
#define DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_

struct struct_SmvKLCDySlKdToNTroAGyF
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aH4cViuPz8aZIf26PeppuD_
#define DEFINED_TYPEDEF_FOR_struct_aH4cViuPz8aZIf26PeppuD_

struct struct_aH4cViuPz8aZIf26PeppuD
{
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T DiscreteConstraintTolerance;
  boolean_T RoundingAtRootNode;
  real_T MaxPendingNodes;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OiyVcB1FUG5CFSJbxuJtpE_
#define DEFINED_TYPEDEF_FOR_struct_OiyVcB1FUG5CFSJbxuJtpE_

struct struct_OiyVcB1FUG5CFSJbxuJtpE
{
  real_T World_Position[3];
  real_T Quaternion[4];
  real_T Linear_Acceleration[3];
  real_T Body_Velocity[3];
  real_T Angular_Rate[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Ly3A2XJK4hMO23MSCkZ3VD_
#define DEFINED_TYPEDEF_FOR_struct_Ly3A2XJK4hMO23MSCkZ3VD_

struct struct_Ly3A2XJK4hMO23MSCkZ3VD
{
  real_T Quaternion[4];
  real_T Angular_Rate[3];
  real_T DVL_Velocity[3];
};

#endif

#ifndef struct_d_quaternion_proc_control_nod_T
#define struct_d_quaternion_proc_control_nod_T

struct d_quaternion_proc_control_nod_T
{
  real_T a;
  real_T b;
  real_T c;
  real_T d;
};

#endif                                // struct_d_quaternion_proc_control_nod_T

#ifndef struct_c_fusion_internal_frames_NED__T
#define struct_c_fusion_internal_frames_NED__T

struct c_fusion_internal_frames_NED__T
{
  int32_T __dummy;
};

#endif                                // struct_c_fusion_internal_frames_NED__T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_cell_wrap_proc_control_node_T
#define struct_cell_wrap_proc_control_node_T

struct cell_wrap_proc_control_node_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_proc_control_node_T

#ifndef struct_fusion_simulink_ahrsfilter_pr_T
#define struct_fusion_simulink_ahrsfilter_pr_T

struct fusion_simulink_ahrsfilter_pr_T
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_node_T inputVarSize[3];
  real_T AccelerometerNoise;
  real_T GyroscopeNoise;
  real_T GyroscopeDriftNoise;
  real_T LinearAccelerationNoise;
  real_T LinearAccelerationDecayFactor;
  real_T pQw[144];
  real_T pQv[36];
  d_quaternion_proc_control_nod_T pOrientPost;
  d_quaternion_proc_control_nod_T pOrientPrior;
  boolean_T pFirstTime;
  c_fusion_internal_frames_NED__T *pRefSys;
  real_T pSensorPeriod;
  real_T pKalmanPeriod;
  real_T pGyroOffset[3];
  real_T pLinAccelPrior[3];
  real_T pLinAccelPost[3];
  real_T pInputPrototype[3];
  real_T MagnetometerNoise;
  real_T MagneticDisturbanceNoise;
  real_T MagneticDisturbanceDecayFactor;
  real_T ExpectedMagneticFieldStrength;
  real_T pMagVec[3];
  c_fusion_internal_frames_NED__T _pobj0;
};

#endif                                // struct_fusion_simulink_ahrsfilter_pr_T

#ifndef struct_h_fusion_internal_Acceleromet_T
#define struct_h_fusion_internal_Acceleromet_T

struct h_fusion_internal_Acceleromet_T
{
  boolean_T tunablePropertyChanged[10];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T MeasurementRange;
  real_T Resolution;
  real_T ConstantBias[3];
  real_T AxesMisalignment[3];
  real_T NoiseDensity[3];
  real_T BiasInstability[3];
  real_T RandomWalk[3];
  real_T TemperatureBias[3];
  real_T TemperatureScaleFactor[3];
  real_T Temperature;
  real_T pBiasInstFilterNum;
  real_T pBiasInstFilterDen[2];
  real_T pBiasInstFilterStates[3];
  real_T pStdDevBiasInst[3];
  real_T pStdDevWhiteNoise[3];
  real_T pRandWalkFilterStates[3];
  real_T pStdDevRandWalk[3];
  real_T pGain[9];
  c_fusion_internal_frames_NED__T *pRefFrame;
  c_fusion_internal_frames_NED__T _pobj0;
};

#endif                                // struct_h_fusion_internal_Acceleromet_T

#ifndef struct_h_fusion_internal_GyroscopeSi_T
#define struct_h_fusion_internal_GyroscopeSi_T

struct h_fusion_internal_GyroscopeSi_T
{
  boolean_T tunablePropertyChanged[11];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T MeasurementRange;
  real_T Resolution;
  real_T ConstantBias[3];
  real_T AxesMisalignment[3];
  real_T NoiseDensity[3];
  real_T BiasInstability[3];
  real_T RandomWalk[3];
  real_T TemperatureBias[3];
  real_T TemperatureScaleFactor[3];
  real_T Temperature;
  real_T pBiasInstFilterNum;
  real_T pBiasInstFilterDen[2];
  real_T pBiasInstFilterStates[3];
  real_T pStdDevBiasInst[3];
  real_T pStdDevWhiteNoise[3];
  real_T pRandWalkFilterStates[3];
  real_T pStdDevRandWalk[3];
  real_T pGain[9];
  real_T AccelerationBias[3];
  real_T pAcceleration[3];
};

#endif                                // struct_h_fusion_internal_GyroscopeSi_T

#ifndef struct_h_fusion_internal_Magnetomete_T
#define struct_h_fusion_internal_Magnetomete_T

struct h_fusion_internal_Magnetomete_T
{
  boolean_T tunablePropertyChanged[10];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T MeasurementRange;
  real_T Resolution;
  real_T ConstantBias[3];
  real_T AxesMisalignment[3];
  real_T NoiseDensity[3];
  real_T BiasInstability[3];
  real_T RandomWalk[3];
  real_T TemperatureBias[3];
  real_T TemperatureScaleFactor[3];
  real_T Temperature;
  real_T pBiasInstFilterNum;
  real_T pBiasInstFilterDen[2];
  real_T pBiasInstFilterStates[3];
  real_T pStdDevBiasInst[3];
  real_T pStdDevWhiteNoise[3];
  real_T pRandWalkFilterStates[3];
  real_T pStdDevRandWalk[3];
  real_T pGain[9];
};

#endif                                // struct_h_fusion_internal_Magnetomete_T

#ifndef struct_fusion_simulink_imuSensor_pro_T
#define struct_fusion_simulink_imuSensor_pro_T

struct fusion_simulink_imuSensor_pro_T
{
  boolean_T tunablePropertyChanged[32];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_node_T inputVarSize[3];
  real_T Temperature;
  c_fusion_internal_frames_NED__T *pRefFrame;
  uint32_T pStreamState[625];
  h_fusion_internal_Acceleromet_T *pAccel;
  h_fusion_internal_GyroscopeSi_T *pGyro;
  h_fusion_internal_Magnetomete_T *pMag;
  real_T MagneticFieldNED[3];
  real_T MagneticField[3];
  real_T AccelParamsMeasurementRange;
  real_T AccelParamsResolution;
  real_T AccelParamsConstantBias[3];
  real_T AccelParamsAxesMisalignment[3];
  real_T AccelParamsNoiseDensity[3];
  real_T AccelParamsBiasInstability[3];
  real_T AccelParamsRandomWalk[3];
  real_T AccelParamsTemperatureBias[3];
  real_T AccelParamsTemperatureScaleFactor[3];
  real_T GyroParamsMeasurementRange;
  real_T GyroParamsResolution;
  real_T GyroParamsConstantBias[3];
  real_T GyroParamsAxesMisalignment[3];
  real_T GyroParamsNoiseDensity[3];
  real_T GyroParamsBiasInstability[3];
  real_T GyroParamsRandomWalk[3];
  real_T GyroParamsTemperatureBias[3];
  real_T GyroParamsTemperatureScaleFactor[3];
  real_T GyroParamsAccelerationBias[3];
  real_T MagParamsMeasurementRange;
  real_T MagParamsResolution;
  real_T MagParamsConstantBias[3];
  real_T MagParamsAxesMisalignment[3];
  real_T MagParamsNoiseDensity[3];
  real_T MagParamsBiasInstability[3];
  real_T MagParamsRandomWalk[3];
  real_T MagParamsTemperatureBias[3];
  real_T MagParamsTemperatureScaleFactor[3];
  h_fusion_internal_Magnetomete_T _pobj0;
  h_fusion_internal_GyroscopeSi_T _pobj1;
  h_fusion_internal_Acceleromet_T _pobj2;
  c_fusion_internal_frames_NED__T _pobj3;
};

#endif                                // struct_fusion_simulink_imuSensor_pro_T

#ifndef struct_OpenLoopController_proc_contr_T
#define struct_OpenLoopController_proc_contr_T

struct OpenLoopController_proc_contr_T
{
  int32_T isInitialized;
  real_T k;
  real_T binv[48];
  real_T mass;
  real_T volume;
  real_T height;
  real_T I[9];
  real_T RG[3];
  real_T RB[3];
  real_T AddedMass[6];
  real_T CDL[6];
  real_T CDQ[6];
  real_T AF[3];
  real_T g;
  real_T rho;
};

#endif                                // struct_OpenLoopController_proc_contr_T

#ifndef struct_TrajectoryManager_proc_contro_T
#define struct_TrajectoryManager_proc_contro_T

struct TrajectoryManager_proc_contro_T
{
  int32_T isInitialized;
  real_T linearConvergence;
  real_T quaternionConvergence;
  real_T TargetThreshold;
  real_T poseBuffer[78013];
  real_T generationNumber;
  real_T bufferCount;
  boolean_T done;
  real_T targetReachedCount;
  real_T init;
  real_T dummy;
  real_T emptyArray[13];
};

#endif                                // struct_TrajectoryManager_proc_contro_T

#ifndef struct_AddPose_proc_control_node_T
#define struct_AddPose_proc_control_node_T

struct AddPose_proc_control_node_T
{
  real_T i;
  real_T poseList[16];
};

#endif                                 // struct_AddPose_proc_control_node_T

#ifndef struct_robotics_slcore_internal_bloc_T
#define struct_robotics_slcore_internal_bloc_T

struct robotics_slcore_internal_bloc_T
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_node_T inputVarSize[3];
  real_T VelocityBoundaryCondition[6];
  real_T AccelerationBoundaryCondition[10];
};

#endif                                // struct_robotics_slcore_internal_bloc_T

#ifndef struct_robotics_slcore_internal_bl_b_T
#define struct_robotics_slcore_internal_bl_b_T

struct robotics_slcore_internal_bl_b_T
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_node_T inputVarSize[4];
  real_T TimeScaling[33];
};

#endif                                // struct_robotics_slcore_internal_bl_b_T

// Parameters for system: '<S85>/Subsystem2'
typedef struct P_Subsystem2_proc_control_nod_T_ P_Subsystem2_proc_control_nod_T;

// Parameters (default storage)
typedef struct P_proc_control_node_T_ P_proc_control_node_T;

// Forward declaration for rtModel
typedef struct tag_RTM_proc_control_node_T RT_MODEL_proc_control_node_T;

#endif                                 // RTW_HEADER_proc_control_node_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
