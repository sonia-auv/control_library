#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block proc_control_node/ROS Input/Subscribe
extern SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Sub_proc_control_node_1050_5;

// For Block proc_control_node/ROS Input/Subscribe1
extern SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Sub_proc_control_node_1050_6;

// For Block proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_proc_control_node_geometry_msgs_Twist> Sub_proc_control_node_644_1122;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe
extern SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_644_945;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe1
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_644_944;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe2
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_644_946;

// For Block proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe
extern SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_644_1168;

// For Block proc_control_node/Subsystem1/Subscribe
extern SimulinkSubscriber<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Sub_proc_control_node_796;

// For Block proc_control_node/Subsystem1/Subscribe1
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_819;

// For Block proc_control_node/Subsystem1/Subscribe2
extern SimulinkSubscriber<std_msgs::UInt8, SL_Bus_proc_control_node_std_msgs_UInt8> Sub_proc_control_node_854;

// For Block proc_control_node/Subsystem1/Subscribe3
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_1123;

// For Block proc_control_node/ROS Output/Send DVL msg/Publish
extern SimulinkPublisher<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Pub_proc_control_node_945;

// For Block proc_control_node/ROS Output/Send IMU msg/Publish
extern SimulinkPublisher<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Pub_proc_control_node_951;

// For Block proc_control_node/ROS Output/Send to Unity/Publish
extern SimulinkPublisher<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Pub_proc_control_node_973;

// For Block proc_control_node/Send Data to ROS/Publish
extern SimulinkPublisher<std_msgs::Int8MultiArray, SL_Bus_proc_control_node_std_msgs_Int8MultiArray> Pub_proc_control_node_1007;

// For Block proc_control_node/Send Data to ROS/Publish1
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_1014;

// For Block proc_control_node/Send Data to ROS/Publish2
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_1024;

// For Block proc_control_node/Send Data to ROS/Publish3
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_proc_control_node_std_msgs_Int8> Pub_proc_control_node_1028;

// For Block proc_control_node/Send Data to ROS/Publish4
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_1038;

// For Block proc_control_node/Send Sensor ON/Publish
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_1121;

// For Block proc_control_node/Send Target Reached /Publish
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_794;

// For Block proc_control_node/Send To Telemetry /Publish
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_proc_control_node_nav_msgs_Odometry> Pub_proc_control_node_1157;

// For Block proc_control_node/Send To Telemetry /Send to Gazebo/Publish
extern SimulinkPublisher<gazebo_msgs::ModelState, SL_Bus_proc_control_node_gazebo_msgs_ModelState> Pub_proc_control_node_1173;

void slros_node_init(int argc, char** argv);

#endif
