#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "proc_control_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block proc_control/Modle Physique/Sensor Model/Hydrophones Model/Subscribe
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_proc_control_geometry_msgs_Vector3> Sub_proc_control_19_1385;

// For Block proc_control/ROS Input/AUV8/Subscribe
extern SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_sensor_msgs_Imu> Sub_proc_control_31_5;

// For Block proc_control/ROS Input/AUV8/Subscribe1
extern SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_sonia_common_BodyVelocityDVL> Sub_proc_control_31_1235;

// For Block proc_control/ROS Input/AUV8/Subscribe2
extern SimulinkSubscriber<std_msgs::Float32, SL_Bus_proc_control_std_msgs_Float32> Sub_proc_control_31_1302;

// For Block proc_control/ROS Input/AUV8/Subscribe3
extern SimulinkSubscriber<sonia_common::PingMsg, SL_Bus_proc_control_sonia_common_PingMsg> Sub_proc_control_31_1321;

// For Block proc_control/ROS Input/Simulation/Subscribe
extern SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_sensor_msgs_Imu> Sub_proc_control_31_1241;

// For Block proc_control/ROS Input/Simulation/Subscribe depth
extern SimulinkSubscriber<std_msgs::Float32, SL_Bus_proc_control_std_msgs_Float32> Sub_proc_control_31_1305;

// For Block proc_control/ROS Input/Simulation/Subscribe1
extern SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_sonia_common_BodyVelocityDVL> Sub_proc_control_31_1242;

// For Block proc_control/ROS Input/Simulation/Subscribe2
extern SimulinkSubscriber<sonia_common::PingMsg, SL_Bus_proc_control_sonia_common_PingMsg> Sub_proc_control_31_1318;

// For Block proc_control/Subsystem Controller/MPC manager/Subscribe
extern SimulinkSubscriber<std_msgs::Float64MultiArray, SL_Bus_proc_control_std_msgs_Float64MultiArray> Sub_proc_control_182_1620;

// For Block proc_control/Subsystem Controller/MPC manager/Subscribe1
extern SimulinkSubscriber<sonia_common::MpcGains, SL_Bus_proc_control_sonia_common_MpcGains> Sub_proc_control_182_1643;

// For Block proc_control/Subsystem Trajectory/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_proc_control_geometry_msgs_Twist> Sub_proc_control_184_1122;

// For Block proc_control/Subsystem Trajectory/Subsystem1/Subscribe
extern SimulinkSubscriber<trajectory_msgs::MultiDOFJointTrajectoryPoint, SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w> Sub_proc_control_184_1581;

// For Block proc_control/Subsystem Trajectory/singleWpts Trajectory/Subscribe
extern SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_sonia_common_AddPose> Sub_proc_control_184_1168;

// For Block proc_control/Subsystem1/Subscribe1
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_std_msgs_Bool> Sub_proc_control_185_12;

// For Block proc_control/Subsystem1/Subscribe2
extern SimulinkSubscriber<std_msgs::UInt8, SL_Bus_proc_control_std_msgs_UInt8> Sub_proc_control_185_13;

// For Block proc_control/Subsystem1/Subscribe3
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_std_msgs_Bool> Sub_proc_control_185_14;

// For Block proc_control/Subsystem1/Subscribe4
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_std_msgs_Bool> Sub_proc_control_185_268;

// For Block proc_control/Subsystem1/Subscribe5
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_std_msgs_Bool> Sub_proc_control_185_270;

// For Block proc_control/Subsystem1/startSim
extern SimulinkSubscriber<geometry_msgs::Pose, SL_Bus_proc_control_geometry_msgs_Pose> Sub_proc_control_185_11;

// For Block proc_control/Modle Physique/Modele Thruster/Send RPM to unity/Publish2
extern SimulinkPublisher<std_msgs::Int16MultiArray, SL_Bus_proc_control_std_msgs_Int16MultiArray> Pub_proc_control_19_1361;

// For Block proc_control/Modle Physique/Sensor Model/Hydrophones Model/Publish
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_proc_control_geometry_msgs_Vector3> Pub_proc_control_19_1384;

// For Block proc_control/ROS Output/Send DVL msg/Publish
extern SimulinkPublisher<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_sonia_common_BodyVelocityDVL> Pub_proc_control_41;

// For Block proc_control/ROS Output/Send Depth msg/Publish Depth
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_proc_control_std_msgs_Float32> Pub_proc_control_243;

// For Block proc_control/ROS Output/Send IMU msg/Publish imu_info
extern SimulinkPublisher<sensor_msgs::Imu, SL_Bus_proc_control_sensor_msgs_Imu> Pub_proc_control_47;

// For Block proc_control/ROS Output/Send Ping msg/Publish Ping
extern SimulinkPublisher<sonia_common::PingMsg, SL_Bus_proc_control_sonia_common_PingMsg> Pub_proc_control_350;

// For Block proc_control/ROS Output/Send to Unity/Publish
extern SimulinkPublisher<geometry_msgs::Pose, SL_Bus_proc_control_geometry_msgs_Pose> Pub_proc_control_75;

// For Block proc_control/Send Data to ROS/Publish2
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_std_msgs_UInt16MultiArray> Pub_proc_control_104;

// For Block proc_control/Send Data to ROS/Subsystem/Publish5
extern SimulinkPublisher<sonia_common::MpcInfo, SL_Bus_proc_control_sonia_common_MpcInfo> Pub_proc_control_287;

// For Block proc_control/Sensor Manager/Send Sensor ON/Publish
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_std_msgs_Bool> Pub_proc_control_116;

// For Block proc_control/Sensor Manager/Send To Telemetry /Publish
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_proc_control_nav_msgs_Odometry> Pub_proc_control_163;

// For Block proc_control/Subsystem Trajectory/SubsystemAuto/Publish5
extern SimulinkPublisher<geometry_msgs::Pose, SL_Bus_proc_control_geometry_msgs_Pose> Pub_proc_control_184_1596;

void slros_node_init(int argc, char** argv);

#endif
