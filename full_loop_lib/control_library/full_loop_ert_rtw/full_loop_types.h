//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop_types.h
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
#ifndef RTW_HEADER_full_loop_types_h_
#define RTW_HEADER_full_loop_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_full_loop_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_full_loop_ros_time_Time Stamp;
} SL_Bus_full_loop_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_BodyVelocityDVL_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_BodyVelocityDVL_

// MsgType=sonia_common/BodyVelocityDVL
typedef struct {
  real_T XVelBtm;
  real_T YVelBtm;
  real_T ZVelBtm;
  real_T EVelBtm;

  // MsgType=std_msgs/Header
  SL_Bus_full_loop_std_msgs_Header Header;
} SL_Bus_full_loop_sonia_common_BodyVelocityDVL;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_full_loop_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_full_loop_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
typedef struct {
  real_T OrientationCovariance[9];
  real_T AngularVelocityCovariance[9];
  real_T LinearAccelerationCovariance[9];

  // MsgType=std_msgs/Header
  SL_Bus_full_loop_std_msgs_Header Header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_full_loop_geometry_msgs_Quaternion Orientation;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_full_loop_geometry_msgs_Vector3 AngularVelocity;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_full_loop_geometry_msgs_Vector3 LinearAcceleration;
} SL_Bus_full_loop_sensor_msgs_Imu;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_full_loop_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_full_loop_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_full_loop_geometry_msgs_Quaternion Orientation;
} SL_Bus_full_loop_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_full_loop_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_full_loop_geometry_msgs_Vector3 Angular;
} SL_Bus_full_loop_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_gazebo_msgs_ModelState_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_gazebo_msgs_ModelState_

// MsgType=gazebo_msgs/ModelState
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ModelName_SL_Info:TruncateAction=warn 
  uint8_T ModelName[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ModelName
  SL_Bus_ROSVariableLengthArrayInfo ModelName_SL_Info;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ReferenceFrame_SL_Info:TruncateAction=warn 
  uint8_T ReferenceFrame[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ReferenceFrame
  SL_Bus_ROSVariableLengthArrayInfo ReferenceFrame_SL_Info;

  // MsgType=geometry_msgs/Pose
  SL_Bus_full_loop_geometry_msgs_Pose Pose;

  // MsgType=geometry_msgs/Twist
  SL_Bus_full_loop_geometry_msgs_Twist Twist;
} SL_Bus_full_loop_gazebo_msgs_ModelState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_MultiArrayDimension_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_MultiArrayDimension_

// MsgType=std_msgs/MultiArrayDimension
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_full_loop_std_msgs_MultiArrayDimension;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
typedef struct {
  uint32_T DataOffset;

  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_full_loop_std_msgs_MultiArrayDimension Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_full_loop_std_msgs_MultiArrayLayout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_UInt16MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_UInt16MultiArray_

// MsgType=std_msgs/UInt16MultiArray
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  uint16_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_full_loop_std_msgs_MultiArrayLayout Layout;
} SL_Bus_full_loop_std_msgs_UInt16MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_Bool_

// MsgType=std_msgs/Bool
typedef struct {
  boolean_T Data;
} SL_Bus_full_loop_std_msgs_Bool;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_AddPose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_sonia_common_AddPose_

// MsgType=sonia_common/AddPose
typedef struct {
  uint8_T Frame;
  uint8_T Speed;
  real_T Fine;

  // MsgType=geometry_msgs/Point
  SL_Bus_full_loop_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_full_loop_geometry_msgs_Vector3 Orientation;
} SL_Bus_full_loop_sonia_common_AddPose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_full_loop_std_msgs_UInt8_

// MsgType=std_msgs/UInt8
typedef struct {
  uint8_T Data;
} SL_Bus_full_loop_std_msgs_UInt8;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_1fm5Wrpoboi65a9NVeWLRE_
#define DEFINED_TYPEDEF_FOR_struct_1fm5Wrpoboi65a9NVeWLRE_

typedef struct {
  real_T World_Position[3];
  real_T Quaternion[4];
  real_T Body_Velocity[3];
  real_T Angular_Rate[3];
} struct_1fm5Wrpoboi65a9NVeWLRE;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_rkSooZHJZnr3Dpfu1LNqfH

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_s7RdrPWkr8UPAUyTdDJkLaG
#define struct_tag_s7RdrPWkr8UPAUyTdDJkLaG

struct tag_s7RdrPWkr8UPAUyTdDJkLaG
{
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

#endif                                 //struct_tag_s7RdrPWkr8UPAUyTdDJkLaG

#ifndef typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T
#define typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T

typedef struct tag_s7RdrPWkr8UPAUyTdDJkLaG s7RdrPWkr8UPAUyTdDJkLaG_full__T;

#endif                                 //typedef_s7RdrPWkr8UPAUyTdDJkLaG_full__T

#ifndef struct_tag_RhTkp3Gut0EwSiwcL7uw6D
#define struct_tag_RhTkp3Gut0EwSiwcL7uw6D

struct tag_RhTkp3Gut0EwSiwcL7uw6D
{
  real_T f1[13];
};

#endif                                 //struct_tag_RhTkp3Gut0EwSiwcL7uw6D

#ifndef typedef_cell_wrap_9_full_loop_T
#define typedef_cell_wrap_9_full_loop_T

typedef struct tag_RhTkp3Gut0EwSiwcL7uw6D cell_wrap_9_full_loop_T;

#endif                                 //typedef_cell_wrap_9_full_loop_T

#ifndef struct_tag_ii06m7FsRP2esHZwHuB8N
#define struct_tag_ii06m7FsRP2esHZwHuB8N

struct tag_ii06m7FsRP2esHZwHuB8N
{
  real_T f1[8];
};

#endif                                 //struct_tag_ii06m7FsRP2esHZwHuB8N

#ifndef typedef_cell_wrap_10_full_loop_T
#define typedef_cell_wrap_10_full_loop_T

typedef struct tag_ii06m7FsRP2esHZwHuB8N cell_wrap_10_full_loop_T;

#endif                                 //typedef_cell_wrap_10_full_loop_T

#ifndef struct_tag_9SewJ4y3IXNs5GrZti8qkG
#define struct_tag_9SewJ4y3IXNs5GrZti8qkG

struct tag_9SewJ4y3IXNs5GrZti8qkG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_9SewJ4y3IXNs5GrZti8qkG

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct tag_9SewJ4y3IXNs5GrZti8qkG ros_slros_internal_block_Subs_T;

#endif                                 //typedef_ros_slros_internal_block_Subs_T

#ifndef struct_tag_w39vnWYBn84tMm6zGpZhfH
#define struct_tag_w39vnWYBn84tMm6zGpZhfH

struct tag_w39vnWYBn84tMm6zGpZhfH
{
  real_T a[21];
  real_T b[21];
  real_T c[21];
  real_T d[21];
};

#endif                                 //struct_tag_w39vnWYBn84tMm6zGpZhfH

#ifndef typedef_c_matlabshared_rotations_inte_T
#define typedef_c_matlabshared_rotations_inte_T

typedef struct tag_w39vnWYBn84tMm6zGpZhfH c_matlabshared_rotations_inte_T;

#endif                                 //typedef_c_matlabshared_rotations_inte_T

#ifndef struct_emxArray_real_T_759x759
#define struct_emxArray_real_T_759x759

struct emxArray_real_T_759x759
{
  real_T data[576081];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_759x759

#ifndef typedef_emxArray_real_T_759x759_full__T
#define typedef_emxArray_real_T_759x759_full__T

typedef struct emxArray_real_T_759x759 emxArray_real_T_759x759_full__T;

#endif                                 //typedef_emxArray_real_T_759x759_full__T

#ifndef struct_emxArray_real_T_406x52
#define struct_emxArray_real_T_406x52

struct emxArray_real_T_406x52
{
  real_T data[21112];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_406x52

#ifndef typedef_emxArray_real_T_406x52_full_l_T
#define typedef_emxArray_real_T_406x52_full_l_T

typedef struct emxArray_real_T_406x52 emxArray_real_T_406x52_full_l_T;

#endif                                 //typedef_emxArray_real_T_406x52_full_l_T

#ifndef struct_emxArray_real_T_759x406
#define struct_emxArray_real_T_759x406

struct emxArray_real_T_759x406
{
  real_T data[308154];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_759x406

#ifndef typedef_emxArray_real_T_759x406_full__T
#define typedef_emxArray_real_T_759x406_full__T

typedef struct emxArray_real_T_759x406 emxArray_real_T_759x406_full__T;

#endif                                 //typedef_emxArray_real_T_759x406_full__T

#ifndef struct_emxArray_real_T_406x232
#define struct_emxArray_real_T_406x232

struct emxArray_real_T_406x232
{
  real_T data[94192];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_406x232

#ifndef typedef_emxArray_real_T_406x232_full__T
#define typedef_emxArray_real_T_406x232_full__T

typedef struct emxArray_real_T_406x232 emxArray_real_T_406x232_full__T;

#endif                                 //typedef_emxArray_real_T_406x232_full__T

#ifndef struct_emxArray_real_T_232x1
#define struct_emxArray_real_T_232x1

struct emxArray_real_T_232x1
{
  real_T data[232];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_232x1

#ifndef typedef_emxArray_real_T_232x1_full_lo_T
#define typedef_emxArray_real_T_232x1_full_lo_T

typedef struct emxArray_real_T_232x1 emxArray_real_T_232x1_full_lo_T;

#endif                                 //typedef_emxArray_real_T_232x1_full_lo_T

#ifndef struct_emxArray_real_T_128x104
#define struct_emxArray_real_T_128x104

struct emxArray_real_T_128x104
{
  real_T data[13312];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_128x104

#ifndef typedef_emxArray_real_T_128x104_full__T
#define typedef_emxArray_real_T_128x104_full__T

typedef struct emxArray_real_T_128x104 emxArray_real_T_128x104_full__T;

#endif                                 //typedef_emxArray_real_T_128x104_full__T

#ifndef struct_tag_9tkLnhOtrSFV4oOGWpGqDF
#define struct_tag_9tkLnhOtrSFV4oOGWpGqDF

struct tag_9tkLnhOtrSFV4oOGWpGqDF
{
  emxArray_real_T_128x104_full__T f1;
};

#endif                                 //struct_tag_9tkLnhOtrSFV4oOGWpGqDF

#ifndef typedef_cell_wrap_15_full_loop_T
#define typedef_cell_wrap_15_full_loop_T

typedef struct tag_9tkLnhOtrSFV4oOGWpGqDF cell_wrap_15_full_loop_T;

#endif                                 //typedef_cell_wrap_15_full_loop_T

#ifndef struct_emxArray_real_T_42x3
#define struct_emxArray_real_T_42x3

struct emxArray_real_T_42x3
{
  real_T data[126];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_42x3

#ifndef typedef_emxArray_real_T_42x3_full_loo_T
#define typedef_emxArray_real_T_42x3_full_loo_T

typedef struct emxArray_real_T_42x3 emxArray_real_T_42x3_full_loo_T;

#endif                                 //typedef_emxArray_real_T_42x3_full_loo_T

#ifndef struct_tag_nLWsDI5AtRIk14xkFAWVFE
#define struct_tag_nLWsDI5AtRIk14xkFAWVFE

struct tag_nLWsDI5AtRIk14xkFAWVFE
{
  emxArray_real_T_42x3_full_loo_T f1;
};

#endif                                 //struct_tag_nLWsDI5AtRIk14xkFAWVFE

#ifndef typedef_f_cell_wrap_full_loop_T
#define typedef_f_cell_wrap_full_loop_T

typedef struct tag_nLWsDI5AtRIk14xkFAWVFE f_cell_wrap_full_loop_T;

#endif                                 //typedef_f_cell_wrap_full_loop_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_s6ICcRyulWOFjNCN0ll7VsE
#define struct_tag_s6ICcRyulWOFjNCN0ll7VsE

struct tag_s6ICcRyulWOFjNCN0ll7VsE
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

#endif                                 //struct_tag_s6ICcRyulWOFjNCN0ll7VsE

#ifndef typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T
#define typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T

typedef struct tag_s6ICcRyulWOFjNCN0ll7VsE s6ICcRyulWOFjNCN0ll7VsE_full__T;

#endif                                 //typedef_s6ICcRyulWOFjNCN0ll7VsE_full__T

#ifndef struct_tag_a5SYZcWNC5KFUTosoMMbl
#define struct_tag_a5SYZcWNC5KFUTosoMMbl

struct tag_a5SYZcWNC5KFUTosoMMbl
{
  emxArray_real_T_759x759_full__T FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
};

#endif                                 //struct_tag_a5SYZcWNC5KFUTosoMMbl

#ifndef typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T
#define typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T

typedef struct tag_a5SYZcWNC5KFUTosoMMbl s_a5SYZcWNC5KFUTosoMMbl_full__T;

#endif                                 //typedef_s_a5SYZcWNC5KFUTosoMMbl_full__T

#ifndef struct_tag_EKSta9ChStpLuknQGIFVcC
#define struct_tag_EKSta9ChStpLuknQGIFVcC

struct tag_EKSta9ChStpLuknQGIFVcC
{
  int32_T isInitialized;
  real_T Config10[29];
  real_T Config19[29];
  real_T Tmin[8];
  real_T Tmax[8];
  real_T MecConst[41];
};

#endif                                 //struct_tag_EKSta9ChStpLuknQGIFVcC

#ifndef typedef_mpcManager_full_loop_T
#define typedef_mpcManager_full_loop_T

typedef struct tag_EKSta9ChStpLuknQGIFVcC mpcManager_full_loop_T;

#endif                                 //typedef_mpcManager_full_loop_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_s1TgE9KstXgkd2qJxO1bF4F
#define struct_tag_s1TgE9KstXgkd2qJxO1bF4F

struct tag_s1TgE9KstXgkd2qJxO1bF4F
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

#endif                                 //struct_tag_s1TgE9KstXgkd2qJxO1bF4F

#ifndef typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T
#define typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T

typedef struct tag_s1TgE9KstXgkd2qJxO1bF4F s1TgE9KstXgkd2qJxO1bF4F_full__T;

#endif                                 //typedef_s1TgE9KstXgkd2qJxO1bF4F_full__T

#ifndef struct_tag_sscAEMcz7TPKHyH2uh3imDC
#define struct_tag_sscAEMcz7TPKHyH2uh3imDC

struct tag_sscAEMcz7TPKHyH2uh3imDC
{
  real_T MVopt[40];
  real_T Xopt[65];
  real_T Yopt[65];
  real_T Topt[5];
  real_T Slack;
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
};

#endif                                 //struct_tag_sscAEMcz7TPKHyH2uh3imDC

#ifndef typedef_sscAEMcz7TPKHyH2uh3imDC_full__T
#define typedef_sscAEMcz7TPKHyH2uh3imDC_full__T

typedef struct tag_sscAEMcz7TPKHyH2uh3imDC sscAEMcz7TPKHyH2uh3imDC_full__T;

#endif                                 //typedef_sscAEMcz7TPKHyH2uh3imDC_full__T

#ifndef struct_tag_EgsT5RXKJefjusDDs30idH
#define struct_tag_EgsT5RXKJefjusDDs30idH

struct tag_EgsT5RXKJefjusDDs30idH
{
  real_T f1[52];
};

#endif                                 //struct_tag_EgsT5RXKJefjusDDs30idH

#ifndef typedef_cell_wrap_11_full_loop_T
#define typedef_cell_wrap_11_full_loop_T

typedef struct tag_EgsT5RXKJefjusDDs30idH cell_wrap_11_full_loop_T;

#endif                                 //typedef_cell_wrap_11_full_loop_T

#ifndef struct_tag_KqfOiSNcAC3p1Yi4ERFj2
#define struct_tag_KqfOiSNcAC3p1Yi4ERFj2

struct tag_KqfOiSNcAC3p1Yi4ERFj2
{
  real_T f1[32];
};

#endif                                 //struct_tag_KqfOiSNcAC3p1Yi4ERFj2

#ifndef typedef_cell_wrap_13_full_loop_T
#define typedef_cell_wrap_13_full_loop_T

typedef struct tag_KqfOiSNcAC3p1Yi4ERFj2 cell_wrap_13_full_loop_T;

#endif                                 //typedef_cell_wrap_13_full_loop_T

#ifndef struct_tag_pKAJGb23pJDz9Dmjs8ehMB
#define struct_tag_pKAJGb23pJDz9Dmjs8ehMB

struct tag_pKAJGb23pJDz9Dmjs8ehMB
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

#endif                                 //struct_tag_pKAJGb23pJDz9Dmjs8ehMB

#ifndef typedef_OpenLoopController_full_loop_T
#define typedef_OpenLoopController_full_loop_T

typedef struct tag_pKAJGb23pJDz9Dmjs8ehMB OpenLoopController_full_loop_T;

#endif                                 //typedef_OpenLoopController_full_loop_T

#ifndef struct_tag_6H4JrUjkWPrBy6FZW4fMiE
#define struct_tag_6H4JrUjkWPrBy6FZW4fMiE

struct tag_6H4JrUjkWPrBy6FZW4fMiE
{
  real_T tcount[3];
  real_T lastAngle[3];
};

#endif                                 //struct_tag_6H4JrUjkWPrBy6FZW4fMiE

#ifndef typedef_DiscontinuityCheck_full_loop_T
#define typedef_DiscontinuityCheck_full_loop_T

typedef struct tag_6H4JrUjkWPrBy6FZW4fMiE DiscontinuityCheck_full_loop_T;

#endif                                 //typedef_DiscontinuityCheck_full_loop_T

#ifndef struct_tag_1ZMx2raDbazxECuXK2PYAC
#define struct_tag_1ZMx2raDbazxECuXK2PYAC

struct tag_1ZMx2raDbazxECuXK2PYAC
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
  real_T dummy;
  real_T emptyArray[13];
};

#endif                                 //struct_tag_1ZMx2raDbazxECuXK2PYAC

#ifndef typedef_TrajectoryManager_full_loop_T
#define typedef_TrajectoryManager_full_loop_T

typedef struct tag_1ZMx2raDbazxECuXK2PYAC TrajectoryManager_full_loop_T;

#endif                                 //typedef_TrajectoryManager_full_loop_T

#ifndef struct_tag_sCXoxZ5eAHJ4jc1Rc8eoNH
#define struct_tag_sCXoxZ5eAHJ4jc1Rc8eoNH

struct tag_sCXoxZ5eAHJ4jc1Rc8eoNH
{
  real_T i;
  real_T poseList[160];
};

#endif                                 //struct_tag_sCXoxZ5eAHJ4jc1Rc8eoNH

#ifndef typedef_AddPose_full_loop_T
#define typedef_AddPose_full_loop_T

typedef struct tag_sCXoxZ5eAHJ4jc1Rc8eoNH AddPose_full_loop_T;

#endif                                 //typedef_AddPose_full_loop_T

#ifndef struct_tag_sNwBqDHDI8zOGXFxo0o9rRC
#define struct_tag_sNwBqDHDI8zOGXFxo0o9rRC

struct tag_sNwBqDHDI8zOGXFxo0o9rRC
{
  real_T breaks[21];
  real_T coefs[80];
};

#endif                                 //struct_tag_sNwBqDHDI8zOGXFxo0o9rRC

#ifndef typedef_sNwBqDHDI8zOGXFxo0o9rRC_full__T
#define typedef_sNwBqDHDI8zOGXFxo0o9rRC_full__T

typedef struct tag_sNwBqDHDI8zOGXFxo0o9rRC sNwBqDHDI8zOGXFxo0o9rRC_full__T;

#endif                                 //typedef_sNwBqDHDI8zOGXFxo0o9rRC_full__T

#ifndef struct_tag_sxqf8zTOpserqZ3ZVpwSQqE
#define struct_tag_sxqf8zTOpserqZ3ZVpwSQqE

struct tag_sxqf8zTOpserqZ3ZVpwSQqE
{
  real_T breaks[21];
  real_T coefs[80];
};

#endif                                 //struct_tag_sxqf8zTOpserqZ3ZVpwSQqE

#ifndef typedef_sxqf8zTOpserqZ3ZVpwSQqE_full__T
#define typedef_sxqf8zTOpserqZ3ZVpwSQqE_full__T

typedef struct tag_sxqf8zTOpserqZ3ZVpwSQqE sxqf8zTOpserqZ3ZVpwSQqE_full__T;

#endif                                 //typedef_sxqf8zTOpserqZ3ZVpwSQqE_full__T

#ifndef struct_tag_f8bArac4feJCkee9WJiqFH
#define struct_tag_f8bArac4feJCkee9WJiqFH

struct tag_f8bArac4feJCkee9WJiqFH
{
  real_T f1[63];
};

#endif                                 //struct_tag_f8bArac4feJCkee9WJiqFH

#ifndef typedef_d_cell_wrap_full_loop_T
#define typedef_d_cell_wrap_full_loop_T

typedef struct tag_f8bArac4feJCkee9WJiqFH d_cell_wrap_full_loop_T;

#endif                                 //typedef_d_cell_wrap_full_loop_T

#ifndef struct_tag_bosTWLER3KLpITT64W1zY
#define struct_tag_bosTWLER3KLpITT64W1zY

struct tag_bosTWLER3KLpITT64W1zY
{
  int32_T isInitialized;
  real_T avanceRapide[7];
  real_T avancePrecision[7];
  real_T accRapide[7];
  real_T accPrecision;
  real_T Ts;
  real_T computeCount;
};

#endif                                 //struct_tag_bosTWLER3KLpITT64W1zY

#ifndef typedef_TrajectoryGenerator_full_loop_T
#define typedef_TrajectoryGenerator_full_loop_T

typedef struct tag_bosTWLER3KLpITT64W1zY TrajectoryGenerator_full_loop_T;

#endif                                 //typedef_TrajectoryGenerator_full_loop_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_A0rUWcsbMx3S06V1NlippE
#define struct_tag_A0rUWcsbMx3S06V1NlippE

struct tag_A0rUWcsbMx3S06V1NlippE
{
  real_T x[13];
  real_T lastMV[8];
  real_T ref[52];
  real_T OutputWeights[52];
  real_T MVWeights[32];
  real_T MVRateWeights[32];
  real_T ECRWeight;
  real_T OutputMin[52];
  real_T OutputMax[52];
  real_T StateMin[52];
  real_T StateMax[52];
  real_T MVMin[32];
  real_T MVMax[32];
  real_T MVRateMin[32];
  real_T MVRateMax[32];
  real_T MVScaledTarget[32];
};

#endif                                 //struct_tag_A0rUWcsbMx3S06V1NlippE

#ifndef typedef_s_A0rUWcsbMx3S06V1NlippE_full_T
#define typedef_s_A0rUWcsbMx3S06V1NlippE_full_T

typedef struct tag_A0rUWcsbMx3S06V1NlippE s_A0rUWcsbMx3S06V1NlippE_full_T;

#endif                                 //typedef_s_A0rUWcsbMx3S06V1NlippE_full_T

#ifndef struct_tag_sACkMJ1zT2VJOHR6eMwwEPC
#define struct_tag_sACkMJ1zT2VJOHR6eMwwEPC

struct tag_sACkMJ1zT2VJOHR6eMwwEPC
{
  real_T Ts;
  real_T CurrentStates[13];
  real_T LastMV[8];
  real_T References[52];
  real_T MVTarget[32];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[8];
};

#endif                                 //struct_tag_sACkMJ1zT2VJOHR6eMwwEPC

#ifndef typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T
#define typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T

typedef struct tag_sACkMJ1zT2VJOHR6eMwwEPC sACkMJ1zT2VJOHR6eMwwEPC_full__T;

#endif                                 //typedef_sACkMJ1zT2VJOHR6eMwwEPC_full__T

#ifndef struct_tag_R7ZAVntqljawiTPtjAALbB
#define struct_tag_R7ZAVntqljawiTPtjAALbB

struct tag_R7ZAVntqljawiTPtjAALbB
{
  s_A0rUWcsbMx3S06V1NlippE_full_T f1;
  sACkMJ1zT2VJOHR6eMwwEPC_full__T f2;
};

#endif                                 //struct_tag_R7ZAVntqljawiTPtjAALbB

#ifndef typedef_cell_2_full_loop_T
#define typedef_cell_2_full_loop_T

typedef struct tag_R7ZAVntqljawiTPtjAALbB cell_2_full_loop_T;

#endif                                 //typedef_cell_2_full_loop_T

#ifndef struct_tag_jOlDPQLs8I9qK3Cs0kmL3D
#define struct_tag_jOlDPQLs8I9qK3Cs0kmL3D

struct tag_jOlDPQLs8I9qK3Cs0kmL3D
{
  cell_2_full_loop_T tunableEnvironment;
};

#endif                                 //struct_tag_jOlDPQLs8I9qK3Cs0kmL3D

#ifndef typedef_c_coder_internal_anonymous_fu_T
#define typedef_c_coder_internal_anonymous_fu_T

typedef struct tag_jOlDPQLs8I9qK3Cs0kmL3D c_coder_internal_anonymous_fu_T;

#endif                                 //typedef_c_coder_internal_anonymous_fu_T

#ifndef struct_tag_siHoaqeHIV5TpidUajpsGD
#define struct_tag_siHoaqeHIV5TpidUajpsGD

struct tag_siHoaqeHIV5TpidUajpsGD
{
  c_coder_internal_anonymous_fu_T objfun;
  c_coder_internal_anonymous_fu_T nonlcon;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
};

#endif                                 //struct_tag_siHoaqeHIV5TpidUajpsGD

#ifndef typedef_s_siHoaqeHIV5TpidUajpsGD_full_T
#define typedef_s_siHoaqeHIV5TpidUajpsGD_full_T

typedef struct tag_siHoaqeHIV5TpidUajpsGD s_siHoaqeHIV5TpidUajpsGD_full_T;

#endif                                 //typedef_s_siHoaqeHIV5TpidUajpsGD_full_T

#ifndef struct_tag_VE7ZJxeWEXGwc3tZK77MuF
#define struct_tag_VE7ZJxeWEXGwc3tZK77MuF

struct tag_VE7ZJxeWEXGwc3tZK77MuF
{
  int32_T isInitialized;
  real_T SampleRate;
  real_T Waypoints[63];
  real_T TimeOfArrival[21];
  real_T Velocities[63];
  real_T Course[21];
  c_matlabshared_rotations_inte_T Quaternions;
  char_T ReferenceFrame[3];
  real_T HorizontalCumulativeDistance[21];
  sNwBqDHDI8zOGXFxo0o9rRC_full__T HorizontalDistancePiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T HorizontalSpeedPiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T HorizontalAccelerationPiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T HorizontalJerkPiecewisePolynomial;
  real_T HorizontalCurvatureInitial[20];
  real_T HorizontalCurvatureFinal[20];
  creal_T HorizontalInitialPosition[21];
  real_T HorizontalPiecewiseLength[20];
  sNwBqDHDI8zOGXFxo0o9rRC_full__T VerticalDistancePiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T VerticalSpeedPiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T VerticalAccelerationPiecewisePolynomial;
  sxqf8zTOpserqZ3ZVpwSQqE_full__T VerticalJerkPiecewisePolynomial;
  real_T PathDuration;
  real_T SegmentTimes[20];
  real_T RadianSlewAngles[20];
  real_T AxesOfRotation[60];
  real_T RadianAngularVelocities[63];
  real_T CurrentTime;
  boolean_T IsDoneStatus;
};

#endif                                 //struct_tag_VE7ZJxeWEXGwc3tZK77MuF

#ifndef typedef_waypointTrajectory_full_loop_T
#define typedef_waypointTrajectory_full_loop_T

typedef struct tag_VE7ZJxeWEXGwc3tZK77MuF waypointTrajectory_full_loop_T;

#endif                                 //typedef_waypointTrajectory_full_loop_T

#ifndef struct_emxArray_real_T_232
#define struct_emxArray_real_T_232

struct emxArray_real_T_232
{
  real_T data[232];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_232

#ifndef typedef_emxArray_real_T_232_full_loop_T
#define typedef_emxArray_real_T_232_full_loop_T

typedef struct emxArray_real_T_232 emxArray_real_T_232_full_loop_T;

#endif                                 //typedef_emxArray_real_T_232_full_loop_T

#ifndef struct_emxArray_real_T_406
#define struct_emxArray_real_T_406

struct emxArray_real_T_406
{
  real_T data[406];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_406

#ifndef typedef_emxArray_real_T_406_full_loop_T
#define typedef_emxArray_real_T_406_full_loop_T

typedef struct emxArray_real_T_406 emxArray_real_T_406_full_loop_T;

#endif                                 //typedef_emxArray_real_T_406_full_loop_T

#ifndef struct_emxArray_real_T_759
#define struct_emxArray_real_T_759

struct emxArray_real_T_759
{
  real_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_759

#ifndef typedef_emxArray_real_T_759_full_loop_T
#define typedef_emxArray_real_T_759_full_loop_T

typedef struct emxArray_real_T_759 emxArray_real_T_759_full_loop_T;

#endif                                 //typedef_emxArray_real_T_759_full_loop_T

#ifndef struct_emxArray_int32_T_759
#define struct_emxArray_int32_T_759

struct emxArray_int32_T_759
{
  int32_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_int32_T_759

#ifndef typedef_emxArray_int32_T_759_full_loo_T
#define typedef_emxArray_int32_T_759_full_loo_T

typedef struct emxArray_int32_T_759 emxArray_int32_T_759_full_loo_T;

#endif                                 //typedef_emxArray_int32_T_759_full_loo_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_i4ZL8C3jdkCeOA2IrFHlEF
#define struct_tag_i4ZL8C3jdkCeOA2IrFHlEF

struct tag_i4ZL8C3jdkCeOA2IrFHlEF
{
  emxArray_real_T_759x406_full__T workspace_double;
  emxArray_int32_T_759_full_loo_T workspace_int;
  emxArray_int32_T_759_full_loo_T workspace_sort;
};

#endif                                 //struct_tag_i4ZL8C3jdkCeOA2IrFHlEF

#ifndef typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T
#define typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T

typedef struct tag_i4ZL8C3jdkCeOA2IrFHlEF s_i4ZL8C3jdkCeOA2IrFHlEF_full_T;

#endif                                 //typedef_s_i4ZL8C3jdkCeOA2IrFHlEF_full_T

#ifndef struct_emxArray_int32_T_406
#define struct_emxArray_int32_T_406

struct emxArray_int32_T_406
{
  int32_T data[406];
  int32_T size;
};

#endif                                 //struct_emxArray_int32_T_406

#ifndef typedef_emxArray_int32_T_406_full_loo_T
#define typedef_emxArray_int32_T_406_full_loo_T

typedef struct emxArray_int32_T_406 emxArray_int32_T_406_full_loo_T;

#endif                                 //typedef_emxArray_int32_T_406_full_loo_T

#ifndef struct_emxArray_boolean_T_759
#define struct_emxArray_boolean_T_759

struct emxArray_boolean_T_759
{
  boolean_T data[759];
  int32_T size;
};

#endif                                 //struct_emxArray_boolean_T_759

#ifndef typedef_emxArray_boolean_T_759_full_l_T
#define typedef_emxArray_boolean_T_759_full_l_T

typedef struct emxArray_boolean_T_759 emxArray_boolean_T_759_full_l_T;

#endif                                 //typedef_emxArray_boolean_T_759_full_l_T

#ifndef struct_emxArray_real_T_104
#define struct_emxArray_real_T_104

struct emxArray_real_T_104
{
  real_T data[104];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_104

#ifndef typedef_emxArray_real_T_104_full_loop_T
#define typedef_emxArray_real_T_104_full_loop_T

typedef struct emxArray_real_T_104 emxArray_real_T_104_full_loop_T;

#endif                                 //typedef_emxArray_real_T_104_full_loop_T

#ifndef struct_emxArray_real_T_405
#define struct_emxArray_real_T_405

struct emxArray_real_T_405
{
  real_T data[405];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_405

#ifndef typedef_emxArray_real_T_405_full_loop_T
#define typedef_emxArray_real_T_405_full_loop_T

typedef struct emxArray_real_T_405 emxArray_real_T_405_full_loop_T;

#endif                                 //typedef_emxArray_real_T_405_full_loop_T

#ifndef struct_emxArray_real_T_42
#define struct_emxArray_real_T_42

struct emxArray_real_T_42
{
  real_T data[42];
  int32_T size;
};

#endif                                 //struct_emxArray_real_T_42

#ifndef typedef_emxArray_real_T_42_full_loop_T
#define typedef_emxArray_real_T_42_full_loop_T

typedef struct emxArray_real_T_42 emxArray_real_T_42_full_loop_T;

#endif                                 //typedef_emxArray_real_T_42_full_loop_T

#ifndef struct_tag_Vp5UUXfA6uW8EaACAYs4i
#define struct_tag_Vp5UUXfA6uW8EaACAYs4i

struct tag_Vp5UUXfA6uW8EaACAYs4i
{
  emxArray_real_T_42_full_loop_T f1;
};

#endif                                 //struct_tag_Vp5UUXfA6uW8EaACAYs4i

#ifndef typedef_h_cell_wrap_full_loop_T
#define typedef_h_cell_wrap_full_loop_T

typedef struct tag_Vp5UUXfA6uW8EaACAYs4i h_cell_wrap_full_loop_T;

#endif                                 //typedef_h_cell_wrap_full_loop_T

// Custom Type definition for MATLAB Function: '<S60>/NLMPC'
#ifndef struct_tag_ZxHOyfVSozxr6pSGbgUCkF
#define struct_tag_ZxHOyfVSozxr6pSGbgUCkF

struct tag_ZxHOyfVSozxr6pSGbgUCkF
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
  real_T xstarsqp[69];
  real_T xstarsqp_old[69];
  emxArray_real_T_232_full_loop_T cIneq;
  emxArray_real_T_232_full_loop_T cIneq_old;
  real_T cEq[52];
  real_T cEq_old[52];
  emxArray_real_T_406_full_loop_T grad;
  emxArray_real_T_406_full_loop_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_759_full_loop_T lambdasqp;
  emxArray_real_T_759_full_loop_T lambdasqp_old;
  real_T steplength;
  emxArray_real_T_406_full_loop_T delta_x;
  emxArray_real_T_406_full_loop_T socDirection;
  emxArray_real_T_759_full_loop_T lambda_old;
  emxArray_int32_T_759_full_loo_T workingset_old;
  emxArray_real_T_759x759_full__T JacCineqTrans_old;
  emxArray_real_T_406x52_full_l_T JacCeqTrans_old;
  emxArray_real_T_406_full_loop_T gradLag;
  emxArray_real_T_406_full_loop_T delta_gradLag;
  emxArray_real_T_406_full_loop_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_759_full_loop_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_406_full_loop_T searchDir;
};

#endif                                 //struct_tag_ZxHOyfVSozxr6pSGbgUCkF

#ifndef typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T
#define typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T

typedef struct tag_ZxHOyfVSozxr6pSGbgUCkF s_ZxHOyfVSozxr6pSGbgUCkF_full_T;

#endif                                 //typedef_s_ZxHOyfVSozxr6pSGbgUCkF_full_T

#ifndef struct_tag_Mspqy2ajbjhxqxIYYuZUwC
#define struct_tag_Mspqy2ajbjhxqxIYYuZUwC

struct tag_Mspqy2ajbjhxqxIYYuZUwC
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_406x232_full__T Aineq;
  emxArray_real_T_232x1_full_lo_T bineq;
  emxArray_real_T_406x52_full_l_T Aeq;
  real_T beq[52];
  emxArray_real_T_406_full_loop_T lb;
  emxArray_real_T_406_full_loop_T ub;
  emxArray_int32_T_406_full_loo_T indexLB;
  emxArray_int32_T_406_full_loo_T indexUB;
  emxArray_int32_T_406_full_loo_T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[52];
  emxArray_real_T_759x759_full__T ATwset;
  emxArray_real_T_759_full_loop_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_759_full_loop_T maxConstrWorkspace;
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
  emxArray_boolean_T_759_full_l_T isActiveConstr;
  emxArray_int32_T_759_full_loo_T Wid;
  emxArray_int32_T_759_full_loo_T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 //struct_tag_Mspqy2ajbjhxqxIYYuZUwC

#ifndef typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T
#define typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T

typedef struct tag_Mspqy2ajbjhxqxIYYuZUwC s_Mspqy2ajbjhxqxIYYuZUwC_full_T;

#endif                                 //typedef_s_Mspqy2ajbjhxqxIYYuZUwC_full_T

#ifndef struct_tag_3RW6EhlAOINzvAvYfuaanB
#define struct_tag_3RW6EhlAOINzvAvYfuaanB

struct tag_3RW6EhlAOINzvAvYfuaanB
{
  int32_T ldq;
  emxArray_real_T_759x759_full__T QR;
  emxArray_real_T_759x759_full__T Q;
  emxArray_int32_T_759_full_loo_T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_759_full_loop_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 //struct_tag_3RW6EhlAOINzvAvYfuaanB

#ifndef typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T
#define typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T

typedef struct tag_3RW6EhlAOINzvAvYfuaanB s_3RW6EhlAOINzvAvYfuaanB_full_T;

#endif                                 //typedef_s_3RW6EhlAOINzvAvYfuaanB_full_T

#ifndef struct_tag_BtE36YuCWnavoi0lGdvGZF
#define struct_tag_BtE36YuCWnavoi0lGdvGZF

struct tag_BtE36YuCWnavoi0lGdvGZF
{
  emxArray_real_T_406_full_loop_T grad;
  emxArray_real_T_405_full_loop_T Hx;
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

#endif                                 //struct_tag_BtE36YuCWnavoi0lGdvGZF

#ifndef typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T
#define typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T

typedef struct tag_BtE36YuCWnavoi0lGdvGZF s_BtE36YuCWnavoi0lGdvGZF_full_T;

#endif                                 //typedef_s_BtE36YuCWnavoi0lGdvGZF_full_T

#ifndef struct_tag_CWBQhEwNbz3J2I47jPePeB
#define struct_tag_CWBQhEwNbz3J2I47jPePeB

struct tag_CWBQhEwNbz3J2I47jPePeB
{
  c_coder_internal_anonymous_fu_T objfun;
  c_coder_internal_anonymous_fu_T nonlin;
  real_T f_1;
  emxArray_real_T_104_full_loop_T cIneq_1;
  real_T cEq_1[52];
  real_T f_2;
  emxArray_real_T_104_full_loop_T cIneq_2;
  real_T cEq_2[52];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T hasLB[69];
  boolean_T hasUB[69];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 //struct_tag_CWBQhEwNbz3J2I47jPePeB

#ifndef typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T
#define typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T

typedef struct tag_CWBQhEwNbz3J2I47jPePeB s_CWBQhEwNbz3J2I47jPePeB_full_T;

#endif                                 //typedef_s_CWBQhEwNbz3J2I47jPePeB_full_T
#endif                                 // RTW_HEADER_full_loop_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
