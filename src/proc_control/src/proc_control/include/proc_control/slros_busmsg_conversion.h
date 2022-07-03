#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistWithCovariance.h>
#include <geometry_msgs/Vector3.h>
#include <nav_msgs/Odometry.h>
#include <ros/duration.h>
#include <ros/time.h>
#include <sensor_msgs/Imu.h>
#include <sonia_common/AddPose.h>
#include <sonia_common/BodyVelocityDVL.h>
#include <sonia_common/MpcGains.h>
#include <sonia_common/MpcInfo.h>
#include <sonia_common/PingMsg.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/UInt8.h>
#include <trajectory_msgs/MultiDOFJointTrajectoryPoint.h>
#include "proc_control_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_proc_control_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_proc_control_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_proc_control_geometry_msgs_PoseWithCovariance const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_proc_control_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(geometry_msgs::Transform* msgPtr, SL_Bus_proc_control_geometry_msgs_Transform const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Transform* busPtr, geometry_msgs::Transform const* msgPtr);

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_proc_control_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::TwistWithCovariance* msgPtr, SL_Bus_proc_control_geometry_msgs_TwistWithCovariance const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_TwistWithCovariance* busPtr, geometry_msgs::TwistWithCovariance const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_proc_control_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_proc_control_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(nav_msgs::Odometry* msgPtr, SL_Bus_proc_control_nav_msgs_Odometry const* busPtr);
void convertToBus(SL_Bus_proc_control_nav_msgs_Odometry* busPtr, nav_msgs::Odometry const* msgPtr);

void convertFromBus(ros::Duration* msgPtr, SL_Bus_proc_control_ros_time_Duration const* busPtr);
void convertToBus(SL_Bus_proc_control_ros_time_Duration* busPtr, ros::Duration const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_proc_control_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_proc_control_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sensor_msgs::Imu* msgPtr, SL_Bus_proc_control_sensor_msgs_Imu const* busPtr);
void convertToBus(SL_Bus_proc_control_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr);

void convertFromBus(sonia_common::AddPose* msgPtr, SL_Bus_proc_control_sonia_common_AddPose const* busPtr);
void convertToBus(SL_Bus_proc_control_sonia_common_AddPose* busPtr, sonia_common::AddPose const* msgPtr);

void convertFromBus(sonia_common::BodyVelocityDVL* msgPtr, SL_Bus_proc_control_sonia_common_BodyVelocityDVL const* busPtr);
void convertToBus(SL_Bus_proc_control_sonia_common_BodyVelocityDVL* busPtr, sonia_common::BodyVelocityDVL const* msgPtr);

void convertFromBus(sonia_common::MpcGains* msgPtr, SL_Bus_proc_control_sonia_common_MpcGains const* busPtr);
void convertToBus(SL_Bus_proc_control_sonia_common_MpcGains* busPtr, sonia_common::MpcGains const* msgPtr);

void convertFromBus(sonia_common::MpcInfo* msgPtr, SL_Bus_proc_control_sonia_common_MpcInfo const* busPtr);
void convertToBus(SL_Bus_proc_control_sonia_common_MpcInfo* busPtr, sonia_common::MpcInfo const* msgPtr);

void convertFromBus(sonia_common::PingMsg* msgPtr, SL_Bus_proc_control_sonia_common_PingMsg const* busPtr);
void convertToBus(SL_Bus_proc_control_sonia_common_PingMsg* busPtr, sonia_common::PingMsg const* msgPtr);

void convertFromBus(std_msgs::Bool* msgPtr, SL_Bus_proc_control_std_msgs_Bool const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Bool* busPtr, std_msgs::Bool const* msgPtr);

void convertFromBus(std_msgs::Float32* msgPtr, SL_Bus_proc_control_std_msgs_Float32 const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr);

void convertFromBus(std_msgs::Float64MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Float64MultiArray const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Float64MultiArray* busPtr, std_msgs::Float64MultiArray const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_proc_control_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);

void convertFromBus(std_msgs::Int16MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Int16MultiArray const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Int16MultiArray* busPtr, std_msgs::Int16MultiArray const* msgPtr);

void convertFromBus(std_msgs::Int8MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Int8MultiArray const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_Int8MultiArray* busPtr, std_msgs::Int8MultiArray const* msgPtr);

void convertFromBus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_proc_control_std_msgs_MultiArrayDimension const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr);

void convertFromBus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_proc_control_std_msgs_MultiArrayLayout const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr);

void convertFromBus(std_msgs::UInt16MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_UInt16MultiArray const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_UInt16MultiArray* busPtr, std_msgs::UInt16MultiArray const* msgPtr);

void convertFromBus(std_msgs::UInt8* msgPtr, SL_Bus_proc_control_std_msgs_UInt8 const* busPtr);
void convertToBus(SL_Bus_proc_control_std_msgs_UInt8* busPtr, std_msgs::UInt8 const* msgPtr);

void convertFromBus(trajectory_msgs::MultiDOFJointTrajectoryPoint* msgPtr, SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w const* busPtr);
void convertToBus(SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w* busPtr, trajectory_msgs::MultiDOFJointTrajectoryPoint const* msgPtr);


#endif
