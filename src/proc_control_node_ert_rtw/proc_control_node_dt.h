//
//  proc_control_node_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "proc_control_node".
//
//  Model version              : 1.11
//  Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
//  C++ source code generated on : Wed Sep  8 14:46:24 2021
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(SL_Bus_proc_control_node_ros_time_Time),
  sizeof(SL_Bus_ROSVariableLengthArrayInfo),
  sizeof(SL_Bus_proc_control_node_std_msgs_Header),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Quaternion),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Vector3),
  sizeof(SL_Bus_proc_control_node_sensor_msgs_Imu),
  sizeof(SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL),
  sizeof(SL_Bus_proc_control_node_std_msgs_MultiArrayDimension),
  sizeof(SL_Bus_proc_control_node_std_msgs_MultiArrayLayout),
  sizeof(SL_Bus_proc_control_node_std_msgs_UInt16MultiArray),
  sizeof(SL_Bus_proc_control_node_std_msgs_Int8),
  sizeof(SL_Bus_proc_control_node_std_msgs_Bool),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Twist),
  sizeof(struct_XEwOoQFSJ0yXWTYDIQhbTC),
  sizeof(struct_tPdF4cj4QxksKOpHPnjYAD),
  sizeof(struct_tms366ZdLAbQ6I7by2QYMH),
  sizeof(struct_ItE4fzFYlf4Io3uBaGCY9F),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Point),
  sizeof(SL_Bus_proc_control_node_sonia_common_AddPose),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Pose),
  sizeof(SL_Bus_proc_control_node_std_msgs_UInt8),
  sizeof(SL_Bus_proc_control_node_sensor_msgs_Joy),
  sizeof(struct_qYRJtcce7MM7XuQ3AAWdMD),
  sizeof(struct_SmvKLCDySlKdToNTroAGyF),
  sizeof(struct_aH4cViuPz8aZIf26PeppuD),
  sizeof(fusion_simulink_ahrsfilter_pr_T),
  sizeof(fusion_simulink_imuSensor_pro_T),
  sizeof(struct_OiyVcB1FUG5CFSJbxuJtpE),
  sizeof(struct_Ly3A2XJK4hMO23MSCkZ3VD),
  sizeof(ros_slroscpp_internal_block_S_T),
  sizeof(ros_slroscpp_internal_block_P_T),
  sizeof(OpenLoopController_proc_contr_T),
  sizeof(TrajectoryManager_proc_contro_T),
  sizeof(AddPose_proc_control_node_T),
  sizeof(robotics_slcore_internal_bloc_T),
  sizeof(robotics_slcore_internal_bl_b_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "SL_Bus_proc_control_node_ros_time_Time",
  "SL_Bus_ROSVariableLengthArrayInfo",
  "SL_Bus_proc_control_node_std_msgs_Header",
  "SL_Bus_proc_control_node_geometry_msgs_Quaternion",
  "SL_Bus_proc_control_node_geometry_msgs_Vector3",
  "SL_Bus_proc_control_node_sensor_msgs_Imu",
  "SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL",
  "SL_Bus_proc_control_node_std_msgs_MultiArrayDimension",
  "SL_Bus_proc_control_node_std_msgs_MultiArrayLayout",
  "SL_Bus_proc_control_node_std_msgs_UInt16MultiArray",
  "SL_Bus_proc_control_node_std_msgs_Int8",
  "SL_Bus_proc_control_node_std_msgs_Bool",
  "SL_Bus_proc_control_node_geometry_msgs_Twist",
  "struct_XEwOoQFSJ0yXWTYDIQhbTC",
  "struct_tPdF4cj4QxksKOpHPnjYAD",
  "struct_tms366ZdLAbQ6I7by2QYMH",
  "struct_ItE4fzFYlf4Io3uBaGCY9F",
  "SL_Bus_proc_control_node_geometry_msgs_Point",
  "SL_Bus_proc_control_node_sonia_common_AddPose",
  "SL_Bus_proc_control_node_geometry_msgs_Pose",
  "SL_Bus_proc_control_node_std_msgs_UInt8",
  "SL_Bus_proc_control_node_sensor_msgs_Joy",
  "struct_qYRJtcce7MM7XuQ3AAWdMD",
  "struct_SmvKLCDySlKdToNTroAGyF",
  "struct_aH4cViuPz8aZIf26PeppuD",
  "fusion_simulink_ahrsfilter_pr_T",
  "fusion_simulink_imuSensor_pro_T",
  "struct_OiyVcB1FUG5CFSJbxuJtpE",
  "struct_Ly3A2XJK4hMO23MSCkZ3VD",
  "ros_slroscpp_internal_block_S_T",
  "ros_slroscpp_internal_block_P_T",
  "OpenLoopController_proc_contr_T",
  "TrajectoryManager_proc_contro_T",
  "AddPose_proc_control_node_T",
  "robotics_slcore_internal_bloc_T",
  "robotics_slcore_internal_bl_b_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&proc_control_node_B.In1), 19, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_f), 20, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_n), 33, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_o), 26, 0, 1 },

  { (char_T *)(&proc_control_node_B.MultiportSwitch[0]), 0, 0, 144 },

  { (char_T *)(&proc_control_node_B.y[0]), 0, 0, 8 },

  { (char_T *)(&proc_control_node_B.RotationTrajectory_o2[0]), 0, 0, 16 },

  { (char_T *)(&proc_control_node_B.NtoRPM[0]), 5, 0, 8 },

  { (char_T *)(&proc_control_node_B.DataTypeConversion1[0]), 0, 0, 2 },

  { (char_T *)(&proc_control_node_B.Z), 0, 0, 160 },

  { (char_T *)(&proc_control_node_B.In1_b), 34, 0, 1 },

  { (char_T *)(&proc_control_node_B.Data), 3, 0, 1 },

  { (char_T *)(&proc_control_node_B.OR), 8, 0, 3 }
  ,

  { (char_T *)(&proc_control_node_DW.obj), 46, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_c), 40, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_l), 39, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_m), 45, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_j), 49, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_jo), 48, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_a), 47, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_a4), 43, 0, 9 },

  { (char_T *)(&proc_control_node_DW.obj_le), 44, 0, 9 },

  { (char_T *)(&proc_control_node_DW.Delay_DSTATE[0]), 0, 0, 472 },

  { (char_T *)(&proc_control_node_DW.Scope1_PWORK.LoggedData), 11, 0, 21 },

  { (char_T *)(&proc_control_node_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&proc_control_node_DW.m_bpIndex[0]), 7, 0, 28 },

  { (char_T *)(&proc_control_node_DW.Integrator1_IWORK), 10, 0, 4 },

  { (char_T *)(&proc_control_node_DW.Delay1_DSTATE_c), 8, 0, 1 },

  { (char_T *)(&proc_control_node_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 47
  },

  { (char_T *)(&proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI), 3, 0, 1 },

  { (char_T *)(&proc_control_node_DW.Memory_PreviousInput), 8, 0, 68 },

  { (char_T *)(&proc_control_node_DW.Subsystem2_p.Subsystem2_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&proc_control_node_DW.Subsystem2.Subsystem2_SubsysRanBC), 2, 0, 1
  }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  33U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&proc_control_node_P.MPC), 30, 0, 1 },

  { (char_T *)(&proc_control_node_P.physics), 27, 0, 1 },

  { (char_T *)(&proc_control_node_P.N[0]), 0, 0, 476 },

  { (char_T *)(&proc_control_node_P.PWM[0]), 5, 0, 201 },

  { (char_T *)(&proc_control_node_P.BandLimitedWhiteNoise_Cov), 0, 0, 6 },

  { (char_T *)(&proc_control_node_P.MinMaxRunningResettable_vinit), 8, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value), 23, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0), 35, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_n), 35, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_l), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_l), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_g), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_j), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_a), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_h), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.CleanOutput_Y0), 41, 0, 1 },

  { (char_T *)(&proc_control_node_P.Output_Y0), 41, 0, 1 },

  { (char_T *)(&proc_control_node_P.SensorsOutput_Y0), 42, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_d), 32, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_lq), 32, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_jt), 33, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_a3), 33, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_m), 26, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_p), 26, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_hg), 26, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_o), 18, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_c), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_e), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_m1), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_h), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_ee), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_n), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_a2), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_ly), 24, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_a), 34, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_d), 34, 0, 1 },

  { (char_T *)(&proc_control_node_P.AHRS_AccelerometerNoise), 0, 0, 877 },

  { (char_T *)(&proc_control_node_P.FixedHorizonOptimizer_Ndis), 4, 0, 1 },

  { (char_T *)(&proc_control_node_P.Memory_InitialCondition[0]), 8, 0, 66 },

  { (char_T *)(&proc_control_node_P.Subsystem2_p.Quat_Y0), 0, 0, 5 },

  { (char_T *)(&proc_control_node_P.Subsystem2.Quat_Y0), 0, 0, 5 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  41U,
  rtPTransitions
};

// [EOF] proc_control_node_dt.h
