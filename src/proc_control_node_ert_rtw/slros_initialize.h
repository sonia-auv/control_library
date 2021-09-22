#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block proc_control_node/ROS Input/Subscribe
extern SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Sub_proc_control_node_31_5;

// For Block proc_control_node/ROS Input/Subscribe1
extern SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Sub_proc_control_node_31_6;

// For Block proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_proc_control_node_geometry_msgs_Twist> Sub_proc_control_node_184_1122;

// For Block proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe
extern SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_184_1168;

// For Block proc_control_node/Subsystem1/Subscribe
extern SimulinkSubscriber<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Sub_proc_control_node_202;

// For Block proc_control_node/Subsystem1/Subscribe1
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_203;

// For Block proc_control_node/Subsystem1/Subscribe2
extern SimulinkSubscriber<std_msgs::UInt8, SL_Bus_proc_control_node_std_msgs_UInt8> Sub_proc_control_node_204;

// For Block proc_control_node/Subsystem1/Subscribe3
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_205;

// For Block proc_control_node/Subsystem1/Subscribe4
extern SimulinkSubscriber<sensor_msgs::Joy, SL_Bus_proc_control_node_sensor_msgs_Joy> Sub_proc_control_node_206;

// For Block proc_control_node/ROS Output/Send DVL msg/Publish
extern SimulinkPublisher<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Pub_proc_control_node_41;

// For Block proc_control_node/ROS Output/Send IMU msg/Publish
extern SimulinkPublisher<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Pub_proc_control_node_47;

// For Block proc_control_node/Send Data to ROS/Publish2
extern SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_104;

// For Block proc_control_node/Send Data to ROS/Publish3
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_proc_control_node_std_msgs_Int8> Pub_proc_control_node_105;

// For Block proc_control_node/Send Data to ROS/Publish4
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_106;

// For Block proc_control_node/Send Sensor ON/Publish
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_116;

// For Block proc_control_node/Send Target Reached /Publish
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_122;

// For Block proc_control_node/Sensor Manager/Send Attitude To DVL/Publish
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_proc_control_node_geometry_msgs_Vector3> Pub_proc_control_node_140;

// For Block proc_control_node/Sensor Manager/Send DVL velocity To IMU/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_proc_control_node_geometry_msgs_Twist> Pub_proc_control_node_151;

void slros_node_init(int argc, char** argv);

#endif
