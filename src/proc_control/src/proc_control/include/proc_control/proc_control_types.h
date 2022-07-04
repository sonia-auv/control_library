//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_types.h
//
// Code generated for Simulink model 'proc_control'.
//
// Model version                  : 3.63
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jul  4 00:42:11 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LLP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_proc_control_types_h_
#define RTW_HEADER_proc_control_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
struct SL_Bus_proc_control_std_msgs_MultiArrayDimension
{
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
struct SL_Bus_proc_control_std_msgs_MultiArrayLayout
{
  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_proc_control_std_msgs_MultiArrayDimension Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
  uint32_T DataOffset;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Int16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Int16MultiArray_

// MsgType=std_msgs/Int16MultiArray
struct SL_Bus_proc_control_std_msgs_Int16MultiArray
{
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_proc_control_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  int16_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_proc_control_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_proc_control_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_proc_control_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_proc_control_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_proc_control_geometry_msgs_Quaternion
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
struct SL_Bus_proc_control_sensor_msgs_Imu
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_std_msgs_Header Header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_proc_control_geometry_msgs_Quaternion Orientation;
  real_T OrientationCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 AngularVelocity;
  real_T AngularVelocityCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 LinearAcceleration;
  real_T LinearAccelerationCovariance[9];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_BodyVelocityDVL_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_BodyVelocityDVL_

// MsgType=sonia_common/BodyVelocityDVL
struct SL_Bus_proc_control_sonia_common_BodyVelocityDVL
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_std_msgs_Header Header;
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

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Float32_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Float32_

// MsgType=std_msgs/Float32
struct SL_Bus_proc_control_std_msgs_Float32
{
  real32_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_PingMsg_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_PingMsg_

// MsgType=sonia_common/PingMsg
struct SL_Bus_proc_control_sonia_common_PingMsg
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_std_msgs_Header Header;
  real_T X;
  real_T Y;
  real_T Z;
  uint16_T Frequency;
  real_T Heading;
  real_T Elevation;
  uint16_T Debug;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_proc_control_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_proc_control_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_proc_control_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_proc_control_geometry_msgs_Quaternion Orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Int8MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Int8MultiArray_

// MsgType=std_msgs/Int8MultiArray
struct SL_Bus_proc_control_std_msgs_Int8MultiArray
{
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_proc_control_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  int8_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_UInt16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_UInt16MultiArray_

// MsgType=std_msgs/UInt16MultiArray
struct SL_Bus_proc_control_std_msgs_UInt16MultiArray
{
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_proc_control_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  uint16_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_MpcGains_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_MpcGains_

// MsgType=sonia_common/MpcGains
struct SL_Bus_proc_control_sonia_common_MpcGains
{
  // IsVarLen=1:VarLenCategory=data:VarLenElem=OV_SL_Info:TruncateAction=warn
  real_T OV[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=OV
  SL_Bus_ROSVariableLengthArrayInfo OV_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=MV_SL_Info:TruncateAction=warn
  real_T MV[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=MV
  SL_Bus_ROSVariableLengthArrayInfo MV_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=MVR_SL_Info:TruncateAction=warn
  real_T MVR[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=MVR
  SL_Bus_ROSVariableLengthArrayInfo MVR_SL_Info;
  real_T MaxThrust;
  real_T MinThrust;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_MpcInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_MpcInfo_

// MsgType=sonia_common/MpcInfo
struct SL_Bus_proc_control_sonia_common_MpcInfo
{
  boolean_T IsMpcAlive;
  boolean_T TargetReached;
  boolean_T IsTrajectoryDone;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=ThrustersStatus_SL_Info:TruncateAction=warn 
  boolean_T ThrustersStatus[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ThrustersStatus
  SL_Bus_ROSVariableLengthArrayInfo ThrustersStatus_SL_Info;
  int8_T MpcStatus;
  uint8_T MpcMode;

  // MsgType=sonia_common/MpcGains
  SL_Bus_proc_control_sonia_common_MpcGains CurrentGains;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Bool_

// MsgType=std_msgs/Bool
struct SL_Bus_proc_control_std_msgs_Bool
{
  boolean_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
struct SL_Bus_proc_control_geometry_msgs_PoseWithCovariance
{
  // MsgType=geometry_msgs/Pose
  SL_Bus_proc_control_geometry_msgs_Pose Pose;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_proc_control_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
struct SL_Bus_proc_control_geometry_msgs_TwistWithCovariance
{
  // MsgType=geometry_msgs/Twist
  SL_Bus_proc_control_geometry_msgs_Twist Twist;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
struct SL_Bus_proc_control_nav_msgs_Odometry
{
  // MsgType=std_msgs/Header
  SL_Bus_proc_control_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_proc_control_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_proc_control_geometry_msgs_TwistWithCovariance Twist;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Float64MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_Float64MultiArray_

// MsgType=std_msgs/Float64MultiArray
struct SL_Bus_proc_control_std_msgs_Float64MultiArray
{
  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_proc_control_std_msgs_MultiArrayLayout Layout;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  real_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Transform_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_geometry_msgs_Transform_

// MsgType=geometry_msgs/Transform
struct SL_Bus_proc_control_geometry_msgs_Transform
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 Translation;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_proc_control_geometry_msgs_Quaternion Rotation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_ros_time_Duration_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_ros_time_Duration_

// MsgType=ros_time/Duration
struct SL_Bus_proc_control_ros_time_Duration
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w_

// MsgType=trajectory_msgs/MultiDOFJointTrajectoryPoint
struct SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w
{
  // MsgType=geometry_msgs/Transform:IsVarLen=1:VarLenCategory=data:VarLenElem=Transforms_SL_Info:TruncateAction=warn 
  SL_Bus_proc_control_geometry_msgs_Transform Transforms[2000];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Transforms
  SL_Bus_ROSVariableLengthArrayInfo Transforms_SL_Info;

  // MsgType=geometry_msgs/Twist:IsVarLen=1:VarLenCategory=data:VarLenElem=Velocities_SL_Info:TruncateAction=warn 
  SL_Bus_proc_control_geometry_msgs_Twist Velocities[2000];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Velocities
  SL_Bus_ROSVariableLengthArrayInfo Velocities_SL_Info;

  // MsgType=geometry_msgs/Twist:IsVarLen=1:VarLenCategory=data:VarLenElem=Accelerations_SL_Info:TruncateAction=warn 
  SL_Bus_proc_control_geometry_msgs_Twist Accelerations[2000];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Accelerations
  SL_Bus_ROSVariableLengthArrayInfo Accelerations_SL_Info;

  // MsgType=ros_time/Duration
  SL_Bus_proc_control_ros_time_Duration TimeFromStart;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_AddPose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_sonia_common_AddPose_

// MsgType=sonia_common/AddPose
struct SL_Bus_proc_control_sonia_common_AddPose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_proc_control_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_proc_control_geometry_msgs_Vector3 Orientation;
  uint8_T Frame;
  uint8_T Speed;
  real_T Fine;
  boolean_T Rotation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_proc_control_std_msgs_UInt8_

// MsgType=std_msgs/UInt8
struct SL_Bus_proc_control_std_msgs_UInt8
{
  uint8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Defaut_
#define DEFINED_TYPEDEF_FOR_Defaut_

struct Defaut
{
  real_T OV[13];
  real_T MV[8];
  real_T MVR[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_C10_
#define DEFINED_TYPEDEF_FOR_C10_

struct C10
{
  real_T OV[13];
  real_T MV[8];
  real_T MVR[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_C11_
#define DEFINED_TYPEDEF_FOR_C11_

struct C11
{
  real_T OV[13];
  real_T MV[8];
  real_T MVR[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_C19_
#define DEFINED_TYPEDEF_FOR_C19_

struct C19
{
  real_T OV[13];
  real_T MV[8];
  real_T MVR[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_NoDvl_
#define DEFINED_TYPEDEF_FOR_NoDvl_

struct NoDvl
{
  real_T MV[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Gains_
#define DEFINED_TYPEDEF_FOR_Gains_

struct Gains
{
  Defaut defaut;
  C10 c10;
  C11 c11;
  C19 c19;
  NoDvl noDvl;
  real_T p;
  real_T m;
  real_T tmax;
  real_T tmin;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_TargetReached_
#define DEFINED_TYPEDEF_FOR_TargetReached_

struct TargetReached
{
  real_T linearTol;
  real_T angularTol;
  real_T timeInTol;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_mpcParams_
#define DEFINED_TYPEDEF_FOR_mpcParams_

struct mpcParams
{
  Gains gains;
  TargetReached targetReached;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qfomatEQOl7mLQ02Mpt2VE_
#define DEFINED_TYPEDEF_FOR_struct_qfomatEQOl7mLQ02Mpt2VE_

struct struct_qfomatEQOl7mLQ02Mpt2VE
{
  real_T T[48];
  real_T tau;
  real_T b0;
  real_T a1;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_PHAFHl5XyXX1OaeSBzWbKD_
#define DEFINED_TYPEDEF_FOR_struct_PHAFHl5XyXX1OaeSBzWbKD_

struct struct_PHAFHl5XyXX1OaeSBzWbKD
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
  real_T DepthPose[3];
  real_T hydroPose[3];
  real_T sonarPose[3];
  real_T dvlRotation[3];
  struct_qfomatEQOl7mLQ02Mpt2VE thruster;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BYV1v0JTV2y829hAXU8EsH_
#define DEFINED_TYPEDEF_FOR_struct_BYV1v0JTV2y829hAXU8EsH_

struct struct_BYV1v0JTV2y829hAXU8EsH
{
  real_T sampletime;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SqczGJVM1s2EbgKSygGASD_
#define DEFINED_TYPEDEF_FOR_struct_SqczGJVM1s2EbgKSygGASD_

struct struct_SqczGJVM1s2EbgKSygGASD
{
  real_T sampletime;
  struct_BYV1v0JTV2y829hAXU8EsH imuDepth;
  struct_BYV1v0JTV2y829hAXU8EsH dvl;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_km1VGdrSgDw9o5zbPZirGD_
#define DEFINED_TYPEDEF_FOR_struct_km1VGdrSgDw9o5zbPZirGD_

struct struct_km1VGdrSgDw9o5zbPZirGD
{
  real_T sampletime;
  struct_SqczGJVM1s2EbgKSygGASD procNav;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ufqIMyHD2vQ8RfLYE7OdnG_
#define DEFINED_TYPEDEF_FOR_struct_ufqIMyHD2vQ8RfLYE7OdnG_

struct struct_ufqIMyHD2vQ8RfLYE7OdnG
{
  real_T adapQMpcMode[4];
  real_T openLoopMode[2];
  real_T LtvQMpcMode;
  real_T rosGains;
  real_T NlmpcMode;
  real_T adapEMpcMode;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Fcl3OWFFDL64qkAOtsVYAC_
#define DEFINED_TYPEDEF_FOR_struct_Fcl3OWFFDL64qkAOtsVYAC_

struct struct_Fcl3OWFFDL64qkAOtsVYAC
{
  real_T trajMode;
  real_T singleWpts[5];
  real_T SpaceMouseMode[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_x7JWpgYpPywnYpZFC6VmZH_
#define DEFINED_TYPEDEF_FOR_struct_x7JWpgYpPywnYpZFC6VmZH_

struct struct_x7JWpgYpPywnYpZFC6VmZH
{
  real_T init;
  struct_ufqIMyHD2vQ8RfLYE7OdnG control;
  struct_Fcl3OWFFDL64qkAOtsVYAC traj;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_
#define DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_

struct struct_WTmPWsEMvOzNnnAVv5fQNC
{
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_
#define DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_

struct struct_WHjMt45Sk148iktWsfFxl
{
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_
#define DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_

struct struct_lnQ9KXdSZFplhcBp5LBCc
{
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T DiscreteConstraintTolerance;
  boolean_T RoundingAtRootNode;
  int32_T MaxPendingNodes;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hZWlT12TcLzIbjyXO4CjGF_
#define DEFINED_TYPEDEF_FOR_struct_hZWlT12TcLzIbjyXO4CjGF_

struct struct_hZWlT12TcLzIbjyXO4CjGF
{
  real_T World_Position[3];
  real_T Quaternion[4];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ORe84o0x5GBDisGKnu34DG_
#define DEFINED_TYPEDEF_FOR_struct_ORe84o0x5GBDisGKnu34DG_

struct struct_ORe84o0x5GBDisGKnu34DG
{
  real_T Body_Velocity[3];
  real_T Linear_Acceleration[3];
  real_T Angular_Rate[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_rlScCGcQggJ5TYrxrqGJfF_
#define DEFINED_TYPEDEF_FOR_struct_rlScCGcQggJ5TYrxrqGJfF_

struct struct_rlScCGcQggJ5TYrxrqGJfF
{
  struct_hZWlT12TcLzIbjyXO4CjGF x;
  struct_ORe84o0x5GBDisGKnu34DG v;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ovWlOQLLs0y1mSxaL5ZDmG_
#define DEFINED_TYPEDEF_FOR_struct_ovWlOQLLs0y1mSxaL5ZDmG_

struct struct_ovWlOQLLs0y1mSxaL5ZDmG
{
  real_T Pressure_Depth;
  real_T Quaternion[4];
  real_T DVL_Velocity[3];
  real_T Angular_Rate[3];
  real_T Linear_Acceleration[3];
  real_T Hydro_Angles[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_dhOFexlPAOq1XLxIBHN1J_
#define DEFINED_TYPEDEF_FOR_struct_dhOFexlPAOq1XLxIBHN1J_

struct struct_dhOFexlPAOq1XLxIBHN1J
{
  real_T WorldPosition[3];
  real_T qS2W[4];
  real_T qW2S[4];
  real_T Body_Velocity[3];
  real_T Angular_Rate[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eJsqWOClzwG18rBvtrhWOG_
#define DEFINED_TYPEDEF_FOR_struct_eJsqWOClzwG18rBvtrhWOG_

struct struct_eJsqWOClzwG18rBvtrhWOG
{
  real_T mvmin[8];
  real_T mvmax[8];
  real_T ywt[13];
  real_T mvwt[8];
  real_T dmwwt[8];
  boolean_T thrustersStatus[8];
  boolean_T kill;
  real_T p;
  real_T m;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TOFpsJJYcOBczOpEd57stD_
#define DEFINED_TYPEDEF_FOR_struct_TOFpsJJYcOBczOpEd57stD_

struct struct_TOFpsJJYcOBczOpEd57stD
{
  real_T Body_Velocity[3];
  real_T error[3];
  real_T enable;
};

#endif

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros_internal_block_Curr_T
#define struct_ros_slros_internal_block_Curr_T

struct ros_slros_internal_block_Curr_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_Curr_T

#ifndef struct_String2DoubleArray_proc_contr_T
#define struct_String2DoubleArray_proc_contr_T

struct String2DoubleArray_proc_contr_T
{
  real_T lastMsg[128];
  real_T lastValues[13];
};

#endif                                // struct_String2DoubleArray_proc_contr_T

#ifndef struct_String2DoubleArray_proc_con_o_T
#define struct_String2DoubleArray_proc_con_o_T

struct String2DoubleArray_proc_con_o_T
{
  real_T lastMsg[128];
  real_T lastValues[8];
};

#endif                                // struct_String2DoubleArray_proc_con_o_T

#ifndef struct_AuvDifferentialEquation_proc__T
#define struct_AuvDifferentialEquation_proc__T

struct AuvDifferentialEquation_proc__T
{
  int32_T isInitialized;
};

#endif                                // struct_AuvDifferentialEquation_proc__T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_fixed_system_DivideByConstant_T
#define struct_fixed_system_DivideByConstant_T

struct fixed_system_DivideByConstant_T
{
  int32_T isInitialized;
};

#endif                                // struct_fixed_system_DivideByConstant_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_sG8JZ69axY52WWR6RKyApQC_proc__T
#define struct_sG8JZ69axY52WWR6RKyApQC_proc__T

struct sG8JZ69axY52WWR6RKyApQC_proc__T
{
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
};

#endif                                // struct_sG8JZ69axY52WWR6RKyApQC_proc__T

#ifndef struct_s7RdrPWkr8UPAUyTdDJkLaG_proc__T
#define struct_s7RdrPWkr8UPAUyTdDJkLaG_proc__T

struct s7RdrPWkr8UPAUyTdDJkLaG_proc__T
{
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

#endif                                // struct_s7RdrPWkr8UPAUyTdDJkLaG_proc__T

#ifndef struct_quaternion_proc_control_T
#define struct_quaternion_proc_control_T

struct quaternion_proc_control_T
{
  real_T a;
  real_T b;
  real_T c;
  real_T d;
};

#endif                                 // struct_quaternion_proc_control_T

#ifndef struct_TrimPlant_proc_control_T
#define struct_TrimPlant_proc_control_T

struct TrimPlant_proc_control_T
{
  real_T qkm[4];
  real_T qkt[4];
  real_T xl[13];
};

#endif                                 // struct_TrimPlant_proc_control_T

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

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_somzaGboVhDG7PNQS6E98jD_proc__T
#define struct_somzaGboVhDG7PNQS6E98jD_proc__T

struct somzaGboVhDG7PNQS6E98jD_proc__T
{
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
};

#endif                                // struct_somzaGboVhDG7PNQS6E98jD_proc__T

#ifndef struct_mpcManager_proc_control_T
#define struct_mpcManager_proc_control_T

struct mpcManager_proc_control_T
{
  int32_T isInitialized;
  real_T init;
  real_T currentFaultCount[8];
  boolean_T isThrusterFault[8];
  real_T rosOV[13];
  real_T rosMV[8];
  real_T rosMVR[8];
  real_T gainsList[600];
};

#endif                                 // struct_mpcManager_proc_control_T

#ifndef struct_MultiTrajectoryManager_proc_c_T
#define struct_MultiTrajectoryManager_proc_c_T

struct MultiTrajectoryManager_proc_c_T
{
  int32_T isInitialized;
  real_T poseBuffer[78000];
  real_T bufferCount;
  boolean_T done;
  real_T targetReachedCount;
  real_T initialPose[7];
  boolean_T init;
  real_T dummy;
  real_T emptyArray[13];
};

#endif                                // struct_MultiTrajectoryManager_proc_c_T

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

#ifndef struct_AddPose_proc_control_T
#define struct_AddPose_proc_control_T

struct AddPose_proc_control_T
{
  real_T i;
  real_T poseList[18];
  real_T initcond[7];
};

#endif                                 // struct_AddPose_proc_control_T

#ifndef struct_cell_wrap_proc_control_T
#define struct_cell_wrap_proc_control_T

struct cell_wrap_proc_control_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_proc_control_T

#ifndef struct_robotics_slcore_internal_bloc_T
#define struct_robotics_slcore_internal_bloc_T

struct robotics_slcore_internal_bloc_T
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_T inputVarSize[4];
  real_T TimeScaling[33];
};

#endif                                // struct_robotics_slcore_internal_bloc_T

#ifndef struct_robotics_slcore_internal_bl_p_T
#define struct_robotics_slcore_internal_bl_p_T

struct robotics_slcore_internal_bl_p_T
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_proc_control_T inputVarSize[3];
  real_T VelocityBoundaryCondition[6];
  real_T AccelerationBoundaryCondition[10];
};

#endif                                // struct_robotics_slcore_internal_bl_p_T

#ifndef struct_rosCommandManager_proc_contro_T
#define struct_rosCommandManager_proc_contro_T

struct rosCommandManager_proc_contro_T
{
  int32_T isInitialized;
  real_T initial_mode;
  real_T m_initCond[7];
  real_T m_mode;
  real_T m_killStatus;
  real_T m_simulation;
  real_T m_reset;
  real_T m_trajClear;
  real_T m_notDryRun;
};

#endif                                // struct_rosCommandManager_proc_contro_T

#ifndef struct_emxArray_real_T_proc_control_T
#define struct_emxArray_real_T_proc_control_T

struct emxArray_real_T_proc_control_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 // struct_emxArray_real_T_proc_control_T

#ifndef struct_emxArray_boolean_T_proc_contr_T
#define struct_emxArray_boolean_T_proc_contr_T

struct emxArray_boolean_T_proc_contr_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                // struct_emxArray_boolean_T_proc_contr_T

#ifndef struct_emxArray_int32_T_proc_control_T
#define struct_emxArray_int32_T_proc_control_T

struct emxArray_int32_T_proc_control_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                // struct_emxArray_int32_T_proc_control_T

#ifndef struct_emxArray_real_T_980x260_proc__T
#define struct_emxArray_real_T_980x260_proc__T

struct emxArray_real_T_980x260_proc__T
{
  real_T data[254800];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_980x260_proc__T

#ifndef struct_emxArray_real_T_980x130_proc__T
#define struct_emxArray_real_T_980x130_proc__T

struct emxArray_real_T_980x130_proc__T
{
  real_T data[127400];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_980x130_proc__T

#ifndef struct_emxArray_real_T_1829x980_proc_T
#define struct_emxArray_real_T_1829x980_proc_T

struct emxArray_real_T_1829x980_proc_T
{
  real_T data[1792420];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_1829x980_proc_T

#ifndef struct_emxArray_real_T_1829x1829_pro_T
#define struct_emxArray_real_T_1829x1829_pro_T

struct emxArray_real_T_1829x1829_pro_T
{
  real_T data[3345241];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_1829x1829_pro_T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_s_8RbNZtrzTH63iHAPCwMh6G_proc_T
#define struct_s_8RbNZtrzTH63iHAPCwMh6G_proc_T

struct s_8RbNZtrzTH63iHAPCwMh6G_proc_T
{
  emxArray_real_T_1829x1829_pro_T FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
};

#endif                                // struct_s_8RbNZtrzTH63iHAPCwMh6G_proc_T

#ifndef struct_s_qYIvDqP9yRqtt40IDZ89JG_proc_T
#define struct_s_qYIvDqP9yRqtt40IDZ89JG_proc_T

struct s_qYIvDqP9yRqtt40IDZ89JG_proc_T
{
  real_T x[13];
  real_T lastMV[8];
  real_T ref[130];
  real_T OutputWeights[130];
  real_T MVWeights[80];
  real_T MVRateWeights[80];
  real_T ECRWeight;
  real_T OutputMin[130];
  real_T OutputMax[130];
  real_T StateMin[130];
  real_T StateMax[130];
  real_T MVMin[80];
  real_T MVMax[80];
  real_T MVRateMin[80];
  real_T MVRateMax[80];
  real_T MVScaledTarget[80];
};

#endif                                // struct_s_qYIvDqP9yRqtt40IDZ89JG_proc_T

#ifndef struct_s6FZHgorTEIlMmVIrDGGTjF_proc__T
#define struct_s6FZHgorTEIlMmVIrDGGTjF_proc__T

struct s6FZHgorTEIlMmVIrDGGTjF_proc__T
{
  real_T Ts;
  real_T CurrentStates[13];
  real_T LastMV[8];
  real_T References[130];
  real_T MVTarget[80];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[8];
};

#endif                                // struct_s6FZHgorTEIlMmVIrDGGTjF_proc__T

#ifndef struct_s_LRhiFHI8WqJfZ5r22AQmGF_proc_T
#define struct_s_LRhiFHI8WqJfZ5r22AQmGF_proc_T

struct s_LRhiFHI8WqJfZ5r22AQmGF_proc_T
{
  s_qYIvDqP9yRqtt40IDZ89JG_proc_T runtimedata;
  s6FZHgorTEIlMmVIrDGGTjF_proc__T userdata;
};

#endif                                // struct_s_LRhiFHI8WqJfZ5r22AQmGF_proc_T

#ifndef struct_anonymous_function_proc_contr_T
#define struct_anonymous_function_proc_contr_T

struct anonymous_function_proc_contr_T
{
  s_LRhiFHI8WqJfZ5r22AQmGF_proc_T workspace;
};

#endif                                // struct_anonymous_function_proc_contr_T

#ifndef struct_s_lkFpKxHZB0M4xOcTLHVN2_proc__T
#define struct_s_lkFpKxHZB0M4xOcTLHVN2_proc__T

struct s_lkFpKxHZB0M4xOcTLHVN2_proc__T
{
  anonymous_function_proc_contr_T objfun;
  anonymous_function_proc_contr_T nonlcon;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
};

#endif                                // struct_s_lkFpKxHZB0M4xOcTLHVN2_proc__T

#ifndef struct_emxArray_real_T_580_proc_cont_T
#define struct_emxArray_real_T_580_proc_cont_T

struct emxArray_real_T_580_proc_cont_T
{
  real_T data[580];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_580_proc_cont_T

#ifndef struct_emxArray_real_T_980_proc_cont_T
#define struct_emxArray_real_T_980_proc_cont_T

struct emxArray_real_T_980_proc_cont_T
{
  real_T data[980];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_980_proc_cont_T

#ifndef struct_emxArray_real_T_1829_proc_con_T
#define struct_emxArray_real_T_1829_proc_con_T

struct emxArray_real_T_1829_proc_con_T
{
  real_T data[1829];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_1829_proc_con_T

#ifndef struct_emxArray_int32_T_1829_proc_co_T
#define struct_emxArray_int32_T_1829_proc_co_T

struct emxArray_int32_T_1829_proc_co_T
{
  int32_T data[1829];
  int32_T size;
};

#endif                                // struct_emxArray_int32_T_1829_proc_co_T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_s_VA2YLuOkHrWNKQO7FEpyoH_proc_T
#define struct_s_VA2YLuOkHrWNKQO7FEpyoH_proc_T

struct s_VA2YLuOkHrWNKQO7FEpyoH_proc_T
{
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[139];
  real_T xstarsqp_old[139];
  emxArray_real_T_580_proc_cont_T cIneq;
  emxArray_real_T_580_proc_cont_T cIneq_old;
  real_T cEq[130];
  real_T cEq_old[130];
  emxArray_real_T_980_proc_cont_T grad;
  emxArray_real_T_980_proc_cont_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_1829_proc_con_T lambdasqp;
  emxArray_real_T_1829_proc_con_T lambdaStopTest;
  emxArray_real_T_1829_proc_con_T lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T_980_proc_cont_T delta_x;
  emxArray_real_T_980_proc_cont_T socDirection;
  emxArray_int32_T_1829_proc_co_T workingset_old;
  emxArray_real_T_980x260_proc__T JacCineqTrans_old;
  emxArray_real_T_980x130_proc__T JacCeqTrans_old;
  emxArray_real_T_980_proc_cont_T gradLag;
  emxArray_real_T_980_proc_cont_T delta_gradLag;
  emxArray_real_T_980_proc_cont_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_1829_proc_con_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_980_proc_cont_T searchDir;
};

#endif                                // struct_s_VA2YLuOkHrWNKQO7FEpyoH_proc_T

#ifndef struct_emxArray_real_T_568400_proc_c_T
#define struct_emxArray_real_T_568400_proc_c_T

struct emxArray_real_T_568400_proc_c_T
{
  real_T data[568400];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_568400_proc_c_T

#ifndef struct_emxArray_real_T_127400_proc_c_T
#define struct_emxArray_real_T_127400_proc_c_T

struct emxArray_real_T_127400_proc_c_T
{
  real_T data[127400];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_127400_proc_c_T

#ifndef struct_emxArray_int32_T_980_proc_con_T
#define struct_emxArray_int32_T_980_proc_con_T

struct emxArray_int32_T_980_proc_con_T
{
  int32_T data[980];
  int32_T size;
};

#endif                                // struct_emxArray_int32_T_980_proc_con_T

#ifndef struct_emxArray_real_T_1792420_proc__T
#define struct_emxArray_real_T_1792420_proc__T

struct emxArray_real_T_1792420_proc__T
{
  real_T data[1792420];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_1792420_proc__T

#ifndef struct_emxArray_boolean_T_1829_proc__T
#define struct_emxArray_boolean_T_1829_proc__T

struct emxArray_boolean_T_1829_proc__T
{
  boolean_T data[1829];
  int32_T size;
};

#endif                                // struct_emxArray_boolean_T_1829_proc__T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_s_gnTVUZmGpKWoq4tCE9AGn_proc__T
#define struct_s_gnTVUZmGpKWoq4tCE9AGn_proc__T

struct s_gnTVUZmGpKWoq4tCE9AGn_proc__T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_568400_proc_c_T Aineq;
  emxArray_real_T_580_proc_cont_T bineq;
  emxArray_real_T_127400_proc_c_T Aeq;
  real_T beq[130];
  emxArray_real_T_980_proc_cont_T lb;
  emxArray_real_T_980_proc_cont_T ub;
  emxArray_int32_T_980_proc_con_T indexLB;
  emxArray_int32_T_980_proc_con_T indexUB;
  emxArray_int32_T_980_proc_con_T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[130];
  emxArray_real_T_1792420_proc__T ATwset;
  emxArray_real_T_1829_proc_con_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_1829_proc_con_T maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T_1829_proc__T isActiveConstr;
  emxArray_int32_T_1829_proc_co_T Wid;
  emxArray_int32_T_1829_proc_co_T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_s_gnTVUZmGpKWoq4tCE9AGn_proc__T

#ifndef struct_emxArray_real_T_260_proc_cont_T
#define struct_emxArray_real_T_260_proc_cont_T

struct emxArray_real_T_260_proc_cont_T
{
  real_T data[260];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_260_proc_cont_T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_s_IDHIEhzA2KtfYk7ehxTmaH_proc_T
#define struct_s_IDHIEhzA2KtfYk7ehxTmaH_proc_T

struct s_IDHIEhzA2KtfYk7ehxTmaH_proc_T
{
  anonymous_function_proc_contr_T objfun;
  anonymous_function_proc_contr_T nonlin;
  real_T f_1;
  emxArray_real_T_260_proc_cont_T cIneq_1;
  real_T cEq_1[130];
  real_T f_2;
  emxArray_real_T_260_proc_cont_T cIneq_2;
  real_T cEq_2[130];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[139];
  boolean_T hasUB[139];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                // struct_s_IDHIEhzA2KtfYk7ehxTmaH_proc_T

#ifndef struct_s_j0X3urodUv3ospvkLXsspC_proc_T
#define struct_s_j0X3urodUv3ospvkLXsspC_proc_T

struct s_j0X3urodUv3ospvkLXsspC_proc_T
{
  emxArray_real_T_1829x980_proc_T workspace_double;
  emxArray_int32_T_1829_proc_co_T workspace_int;
  emxArray_int32_T_1829_proc_co_T workspace_sort;
};

#endif                                // struct_s_j0X3urodUv3ospvkLXsspC_proc_T

#ifndef struct_s_Ref0liQlfQOPmAop9i3aPH_proc_T
#define struct_s_Ref0liQlfQOPmAop9i3aPH_proc_T

struct s_Ref0liQlfQOPmAop9i3aPH_proc_T
{
  int32_T ldq;
  emxArray_real_T_1829x1829_pro_T QR;
  emxArray_real_T_1829x1829_pro_T Q;
  emxArray_int32_T_1829_proc_co_T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_1829_proc_con_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_s_Ref0liQlfQOPmAop9i3aPH_proc_T

#ifndef struct_emxArray_real_T_979_proc_cont_T
#define struct_emxArray_real_T_979_proc_cont_T

struct emxArray_real_T_979_proc_cont_T
{
  real_T data[979];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_979_proc_cont_T

// Custom Type definition for MATLAB Function: '<S203>/NLMPC'
#ifndef struct_s_wbACub5hw4pAYPfHb1hrsB_proc_T
#define struct_s_wbACub5hw4pAYPfHb1hrsB_proc_T

struct s_wbACub5hw4pAYPfHb1hrsB_proc_T
{
  emxArray_real_T_980_proc_cont_T grad;
  emxArray_real_T_979_proc_cont_T Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_s_wbACub5hw4pAYPfHb1hrsB_proc_T

#ifndef struct_ros_slros_internal_block_GetP_T
#define struct_ros_slros_internal_block_GetP_T

struct ros_slros_internal_block_GetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_GetP_T
#endif                                 // RTW_HEADER_proc_control_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
