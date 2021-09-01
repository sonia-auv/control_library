#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "proc_control_node";

// For Block proc_control_node/ROS Input/Subscribe
SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Sub_proc_control_node_1050_5;

// For Block proc_control_node/ROS Input/Subscribe1
SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Sub_proc_control_node_1050_6;

// For Block proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_proc_control_node_geometry_msgs_Twist> Sub_proc_control_node_644_1122;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe
SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_644_945;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe1
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_644_944;

// For Block proc_control_node/Subsystem Trajectory/SubsystemAuto/Subscribe2
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_644_946;

// For Block proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe
SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_644_1168;

// For Block proc_control_node/Subsystem1/Subscribe
SimulinkSubscriber<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Sub_proc_control_node_796;

// For Block proc_control_node/Subsystem1/Subscribe1
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_819;

// For Block proc_control_node/Subsystem1/Subscribe2
SimulinkSubscriber<std_msgs::UInt8, SL_Bus_proc_control_node_std_msgs_UInt8> Sub_proc_control_node_854;

// For Block proc_control_node/Subsystem1/Subscribe3
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_1123;

// For Block proc_control_node/ROS Output/Send DVL msg/Publish
SimulinkPublisher<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Pub_proc_control_node_945;

// For Block proc_control_node/ROS Output/Send IMU msg/Publish
SimulinkPublisher<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Pub_proc_control_node_951;

// For Block proc_control_node/ROS Output/Send to Unity/Publish
SimulinkPublisher<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Pub_proc_control_node_973;

// For Block proc_control_node/Send Data to ROS/Publish
SimulinkPublisher<std_msgs::Int8MultiArray, SL_Bus_proc_control_node_std_msgs_Int8MultiArray> Pub_proc_control_node_1007;

// For Block proc_control_node/Send Data to ROS/Publish1
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_1014;

// For Block proc_control_node/Send Data to ROS/Publish2
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_1024;

// For Block proc_control_node/Send Data to ROS/Publish3
SimulinkPublisher<std_msgs::Int8, SL_Bus_proc_control_node_std_msgs_Int8> Pub_proc_control_node_1028;

// For Block proc_control_node/Send Data to ROS/Publish4
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_1038;

// For Block proc_control_node/Send Sensor ON/Publish
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_1121;

// For Block proc_control_node/Send Target Reached /Publish
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_794;

// For Block proc_control_node/Send To Telemetry /Publish
SimulinkPublisher<nav_msgs::Odometry, SL_Bus_proc_control_node_nav_msgs_Odometry> Pub_proc_control_node_1157;

// For Block proc_control_node/Send To Telemetry /Send to Gazebo/Publish
SimulinkPublisher<gazebo_msgs::ModelState, SL_Bus_proc_control_node_gazebo_msgs_ModelState> Pub_proc_control_node_1173;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

