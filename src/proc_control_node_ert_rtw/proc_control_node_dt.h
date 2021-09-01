//
//  proc_control_node_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "proc_control_node".
//
//  Model version              : 3.48
//  Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
//  C++ source code generated on : Sat Aug  7 17:14:08 2021
//
//  Target selection: ert.tlc
//  Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
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
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Point),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Pose),
  sizeof(SL_Bus_proc_control_node_std_msgs_MultiArrayDimension),
  sizeof(SL_Bus_proc_control_node_std_msgs_MultiArrayLayout),
  sizeof(SL_Bus_proc_control_node_std_msgs_Int8MultiArray),
  sizeof(SL_Bus_proc_control_node_std_msgs_UInt16MultiArray),
  sizeof(SL_Bus_proc_control_node_std_msgs_Int8),
  sizeof(SL_Bus_proc_control_node_std_msgs_Bool),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_PoseWithCovariance),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_Twist),
  sizeof(SL_Bus_proc_control_node_geometry_msgs_TwistWithCovariance),
  sizeof(SL_Bus_proc_control_node_nav_msgs_Odometry),
  sizeof(SL_Bus_proc_control_node_gazebo_msgs_ModelState),
  sizeof(struct_XEwOoQFSJ0yXWTYDIQhbTC),
  sizeof(struct_tPdF4cj4QxksKOpHPnjYAD),
  sizeof(struct_tms366ZdLAbQ6I7by2QYMH),
  sizeof(struct_ItE4fzFYlf4Io3uBaGCY9F),
  sizeof(SL_Bus_proc_control_node_sonia_common_AddPose),
  sizeof(SL_Bus_proc_control_node_std_msgs_UInt8),
  sizeof(struct_RoPeIRaOs110XaoEJ1OUdD),
  sizeof(fusion_simulink_ahrsfilter_pr_T),
  sizeof(fusion_simulink_imuSensor_pro_T),
  sizeof(struct_OiyVcB1FUG5CFSJbxuJtpE),
  sizeof(struct_Ly3A2XJK4hMO23MSCkZ3VD),
  sizeof(ros_slroscpp_internal_block_S_T),
  sizeof(ros_slroscpp_internal_block_P_T),
  sizeof(OpenLoopController_proc_contr_T),
  sizeof(mpcManager_proc_control_node_T),
  sizeof(AddPose_proc_control_node_T),
  sizeof(TrajectoryGenerator_proc_cont_T),
  sizeof(TrajectoryManager_proc_contro_T),
  sizeof(AddPose_proc_control_node_b_T),
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
  "SL_Bus_proc_control_node_geometry_msgs_Point",
  "SL_Bus_proc_control_node_geometry_msgs_Pose",
  "SL_Bus_proc_control_node_std_msgs_MultiArrayDimension",
  "SL_Bus_proc_control_node_std_msgs_MultiArrayLayout",
  "SL_Bus_proc_control_node_std_msgs_Int8MultiArray",
  "SL_Bus_proc_control_node_std_msgs_UInt16MultiArray",
  "SL_Bus_proc_control_node_std_msgs_Int8",
  "SL_Bus_proc_control_node_std_msgs_Bool",
  "SL_Bus_proc_control_node_geometry_msgs_PoseWithCovariance",
  "SL_Bus_proc_control_node_geometry_msgs_Twist",
  "SL_Bus_proc_control_node_geometry_msgs_TwistWithCovariance",
  "SL_Bus_proc_control_node_nav_msgs_Odometry",
  "SL_Bus_proc_control_node_gazebo_msgs_ModelState",
  "struct_XEwOoQFSJ0yXWTYDIQhbTC",
  "struct_tPdF4cj4QxksKOpHPnjYAD",
  "struct_tms366ZdLAbQ6I7by2QYMH",
  "struct_ItE4fzFYlf4Io3uBaGCY9F",
  "SL_Bus_proc_control_node_sonia_common_AddPose",
  "SL_Bus_proc_control_node_std_msgs_UInt8",
  "struct_RoPeIRaOs110XaoEJ1OUdD",
  "fusion_simulink_ahrsfilter_pr_T",
  "fusion_simulink_imuSensor_pro_T",
  "struct_OiyVcB1FUG5CFSJbxuJtpE",
  "struct_Ly3A2XJK4hMO23MSCkZ3VD",
  "ros_slroscpp_internal_block_S_T",
  "ros_slroscpp_internal_block_P_T",
  "OpenLoopController_proc_contr_T",
  "mpcManager_proc_control_node_T",
  "AddPose_proc_control_node_T",
  "TrajectoryGenerator_proc_cont_T",
  "TrajectoryManager_proc_contro_T",
  "AddPose_proc_control_node_b_T",
  "robotics_slcore_internal_bloc_T",
  "robotics_slcore_internal_bl_b_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&proc_control_node_B.In1), 19, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_h), 20, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_p), 38, 0, 2 },

  { (char_T *)(&proc_control_node_B.FirstOrderHold1[0]), 0, 0, 16 },

  { (char_T *)(&proc_control_node_B.In1_k), 22, 0, 1 },

  { (char_T *)(&proc_control_node_B.In1_pv), 30, 0, 1 },

  { (char_T *)(&proc_control_node_B.y[0]), 0, 0, 21 },

  { (char_T *)(&proc_control_node_B.WorldPosition_g[0]), 0, 0, 15 },

  { (char_T *)(&proc_control_node_B.DataTypeConversion1_l[0]), 0, 0, 2 },

  { (char_T *)(&proc_control_node_B.Sum), 0, 0, 261 },

  { (char_T *)(&proc_control_node_B.In1_g), 39, 0, 1 },

  { (char_T *)(&proc_control_node_B.NtoRPM[0]), 5, 0, 8 },

  { (char_T *)(&proc_control_node_B.Data), 3, 0, 1 },

  { (char_T *)(&proc_control_node_B.OR), 8, 0, 3 }
  ,

  { (char_T *)(&proc_control_node_DW.obj), 51, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_i), 42, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_c), 41, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_o), 49, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_g), 48, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_m), 47, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_gr), 54, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_k), 53, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_ce), 50, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_or), 52, 0, 1 },

  { (char_T *)(&proc_control_node_DW.obj_b), 45, 0, 11 },

  { (char_T *)(&proc_control_node_DW.obj_d), 46, 0, 12 },

  { (char_T *)(&proc_control_node_DW.Delay_DSTATE[0]), 0, 0, 127 },

  { (char_T *)(&proc_control_node_DW.Scope1_PWORK.LoggedData), 11, 0, 20 },

  { (char_T *)(&proc_control_node_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&proc_control_node_DW.m_bpIndex[0]), 7, 0, 28 },

  { (char_T *)(&proc_control_node_DW.Integrator1_IWORK), 10, 0, 4 },

  { (char_T *)(&proc_control_node_DW.Delay1_DSTATE), 8, 0, 2 },

  { (char_T *)(&proc_control_node_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 38
  },

  { (char_T *)(&proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI), 3, 0, 1 },

  { (char_T *)(&proc_control_node_DW.Memory_PreviousInput), 8, 0, 4 },

  { (char_T *)(&proc_control_node_DW.Subsystem1_e.Subsystem1_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&proc_control_node_DW.Subsystem1.Subsystem1_SubsysRanBC), 2, 0, 1
  }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  37U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&proc_control_node_P.mpc), 37, 0, 1 },

  { (char_T *)(&proc_control_node_P.physics), 34, 0, 1 },

  { (char_T *)(&proc_control_node_P.simulation), 40, 0, 1 },

  { (char_T *)(&proc_control_node_P.Config10[0]), 0, 0, 583 },

  { (char_T *)(&proc_control_node_P.PWM[0]), 5, 0, 201 },

  { (char_T *)(&proc_control_node_P.BandLimitedWhiteNoise_Cov), 0, 0, 6 },

  { (char_T *)(&proc_control_node_P.MinMaxRunningResettable_vinit), 8, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value), 26, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_j), 26, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_p), 25, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_d), 32, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_d5), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_g), 19, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_py), 33, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_a), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_c), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_n), 20, 0, 1 },

  { (char_T *)(&proc_control_node_P.CleanOutput_Y0), 43, 0, 1 },

  { (char_T *)(&proc_control_node_P.Output_Y0), 43, 0, 1 },

  { (char_T *)(&proc_control_node_P.SensorsOutput_Y0), 44, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_h), 38, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_gj), 38, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_e), 38, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_ck), 38, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_g5), 22, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_k), 22, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_o), 22, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_b), 30, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_p3), 30, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_m), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_e), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_mi), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_au), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_h), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_o), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_g5r), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_ki), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_ch), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_m), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_pn), 28, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_k), 27, 0, 1 },

  { (char_T *)(&proc_control_node_P.Out1_Y0_ae), 39, 0, 1 },

  { (char_T *)(&proc_control_node_P.Constant_Value_kv), 39, 0, 1 },

  { (char_T *)(&proc_control_node_P.AHRS_AccelerometerNoise), 0, 0, 377 },

  { (char_T *)(&proc_control_node_P.Delay_InitialCondition_n), 8, 0, 3 },

  { (char_T *)(&proc_control_node_P.Subsystem1_e.Out1_Y0), 0, 0, 1 },

  { (char_T *)(&proc_control_node_P.Subsystem1.Out1_Y0), 0, 0, 1 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  48U,
  rtPTransitions
};

// [EOF] proc_control_node_dt.h
