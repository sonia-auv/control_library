#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "proc_control_node";

// For Block proc_control_node/ROS Input/Real System/Subscribe
SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Sub_proc_control_node_31_5;

// For Block proc_control_node/ROS Input/Real System/Subscribe1
SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Sub_proc_control_node_31_1235;

// For Block proc_control_node/ROS Input/Real System/Subscribe2
SimulinkSubscriber<std_msgs::Float32, SL_Bus_proc_control_node_std_msgs_Float32> Sub_proc_control_node_31_1302;

// For Block proc_control_node/ROS Input/Simulation/Subscribe
SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Sub_proc_control_node_31_1241;

// For Block proc_control_node/ROS Input/Simulation/Subscribe1
SimulinkSubscriber<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Sub_proc_control_node_31_1242;

// For Block proc_control_node/ROS Input/Simulation/Subscribe2
SimulinkSubscriber<std_msgs::Float32, SL_Bus_proc_control_node_std_msgs_Float32> Sub_proc_control_node_31_1305;

// For Block proc_control_node/Subsystem Trajectory/Subsystem/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_proc_control_node_geometry_msgs_Twist> Sub_proc_control_node_184_1122;

// For Block proc_control_node/Subsystem Trajectory/singleWpts Trajectory/Subscribe
SimulinkSubscriber<sonia_common::AddPose, SL_Bus_proc_control_node_sonia_common_AddPose> Sub_proc_control_node_184_1168;

// For Block proc_control_node/Subsystem1/Subscribe
SimulinkSubscriber<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Sub_proc_control_node_185_11;

// For Block proc_control_node/Subsystem1/Subscribe1
SimulinkSubscriber<sonia_common::KillSwitchMsg, SL_Bus_proc_control_node_sonia_common_KillSwitchMsg> Sub_proc_control_node_185_12;

// For Block proc_control_node/Subsystem1/Subscribe2
SimulinkSubscriber<std_msgs::UInt8, SL_Bus_proc_control_node_std_msgs_UInt8> Sub_proc_control_node_185_13;

// For Block proc_control_node/Subsystem1/Subscribe3
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_185_14;

// For Block proc_control_node/Subsystem1/Subscribe4
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_185_268;

// For Block proc_control_node/Subsystem1/Subscribe5
SimulinkSubscriber<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Sub_proc_control_node_185_270;

// For Block proc_control_node/ROS Output/Send DVL msg/Publish
SimulinkPublisher<sonia_common::BodyVelocityDVL, SL_Bus_proc_control_node_sonia_common_BodyVelocityDVL> Pub_proc_control_node_41;

// For Block proc_control_node/ROS Output/Send Depth msg/Publish
SimulinkPublisher<std_msgs::Float32, SL_Bus_proc_control_node_std_msgs_Float32> Pub_proc_control_node_243;

// For Block proc_control_node/ROS Output/Send IMU msg/Publish
SimulinkPublisher<sensor_msgs::Imu, SL_Bus_proc_control_node_sensor_msgs_Imu> Pub_proc_control_node_47;

// For Block proc_control_node/ROS Output/Send to Gazebo/Publish
SimulinkPublisher<gazebo_msgs::ModelState, SL_Bus_proc_control_node_gazebo_msgs_ModelState> Pub_proc_control_node_63;

// For Block proc_control_node/ROS Output/Send to Unity/Publish
SimulinkPublisher<geometry_msgs::Pose, SL_Bus_proc_control_node_geometry_msgs_Pose> Pub_proc_control_node_75;

// For Block proc_control_node/Send Data to ROS/Publish1
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_122;

// For Block proc_control_node/Send Data to ROS/Publish2
SimulinkPublisher<std_msgs::UInt16MultiArray, SL_Bus_proc_control_node_std_msgs_UInt16MultiArray> Pub_proc_control_node_104;

// For Block proc_control_node/Send Data to ROS/Publish3
SimulinkPublisher<std_msgs::Int8, SL_Bus_proc_control_node_std_msgs_Int8> Pub_proc_control_node_105;

// For Block proc_control_node/Send Data to ROS/Publish4
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_106;

// For Block proc_control_node/Sensor Manager/Send Sensor ON/Publish
SimulinkPublisher<std_msgs::Bool, SL_Bus_proc_control_node_std_msgs_Bool> Pub_proc_control_node_116;

// For Block proc_control_node/Sensor Manager/Send To Telemetry /Publish
SimulinkPublisher<nav_msgs::Odometry, SL_Bus_proc_control_node_nav_msgs_Odometry> Pub_proc_control_node_163;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

