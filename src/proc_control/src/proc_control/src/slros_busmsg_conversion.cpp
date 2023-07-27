#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_proc_control_geometry_msgs_Point and geometry_msgs::Point

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_proc_control_geometry_msgs_Point const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_proc_control_geometry_msgs_Pose and geometry_msgs::Pose

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_proc_control_geometry_msgs_Pose const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBus(&msgPtr->position, &busPtr->Position);
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_proc_control_geometry_msgs_PoseWithCovariance and geometry_msgs::PoseWithCovariance

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_proc_control_geometry_msgs_PoseWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_proc_control_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_proc_control_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_proc_control_geometry_msgs_Transform and geometry_msgs::Transform

void convertFromBus(geometry_msgs::Transform* msgPtr, SL_Bus_proc_control_geometry_msgs_Transform const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertFromBus(&msgPtr->rotation, &busPtr->Rotation);
  convertFromBus(&msgPtr->translation, &busPtr->Translation);
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Transform* busPtr, geometry_msgs::Transform const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertToBus(&busPtr->Rotation, &msgPtr->rotation);
  convertToBus(&busPtr->Translation, &msgPtr->translation);
}


// Conversions between SL_Bus_proc_control_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_proc_control_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_proc_control_geometry_msgs_TwistWithCovariance and geometry_msgs::TwistWithCovariance

void convertFromBus(geometry_msgs::TwistWithCovariance* msgPtr, SL_Bus_proc_control_geometry_msgs_TwistWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_TwistWithCovariance* busPtr, geometry_msgs::TwistWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_proc_control_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_proc_control_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_proc_control_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_proc_control_nav_msgs_Odometry and nav_msgs::Odometry

void convertFromBus(nav_msgs::Odometry* msgPtr, SL_Bus_proc_control_nav_msgs_Odometry const* busPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertFromBusVariablePrimitiveArray(msgPtr->child_frame_id, busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_proc_control_nav_msgs_Odometry* busPtr, nav_msgs::Odometry const* msgPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertToBusVariablePrimitiveArray(busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info, msgPtr->child_frame_id, slros::EnabledWarning(rosMessageType, "child_frame_id"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_proc_control_ros_time_Duration and ros::Duration

void convertFromBus(ros::Duration* msgPtr, SL_Bus_proc_control_ros_time_Duration const* busPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_proc_control_ros_time_Duration* busPtr, ros::Duration const* msgPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_proc_control_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_proc_control_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_proc_control_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_proc_control_sensor_msgs_Imu and sensor_msgs::Imu

void convertFromBus(sensor_msgs::Imu* msgPtr, SL_Bus_proc_control_sensor_msgs_Imu const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertFromBus(&msgPtr->angular_velocity, &busPtr->AngularVelocity);
  convertFromBusFixedPrimitiveArray(msgPtr->angular_velocity_covariance, busPtr->AngularVelocityCovariance);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->linear_acceleration, &busPtr->LinearAcceleration);
  convertFromBusFixedPrimitiveArray(msgPtr->linear_acceleration_covariance, busPtr->LinearAccelerationCovariance);
  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBusFixedPrimitiveArray(msgPtr->orientation_covariance, busPtr->OrientationCovariance);
}

void convertToBus(SL_Bus_proc_control_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertToBus(&busPtr->AngularVelocity, &msgPtr->angular_velocity);
  convertToBusFixedPrimitiveArray(busPtr->AngularVelocityCovariance, msgPtr->angular_velocity_covariance, slros::NoopWarning());
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->LinearAcceleration, &msgPtr->linear_acceleration);
  convertToBusFixedPrimitiveArray(busPtr->LinearAccelerationCovariance, msgPtr->linear_acceleration_covariance, slros::NoopWarning());
  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBusFixedPrimitiveArray(busPtr->OrientationCovariance, msgPtr->orientation_covariance, slros::NoopWarning());
}


// Conversions between SL_Bus_proc_control_sonia_common_AddPose and sonia_common::AddPose

void convertFromBus(sonia_common::AddPose* msgPtr, SL_Bus_proc_control_sonia_common_AddPose const* busPtr)
{
  const std::string rosMessageType("sonia_common/AddPose");

  msgPtr->fine =  busPtr->Fine;
  msgPtr->frame =  busPtr->Frame;
  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBus(&msgPtr->position, &busPtr->Position);
  msgPtr->rotation =  busPtr->Rotation;
  msgPtr->speed =  busPtr->Speed;
}

void convertToBus(SL_Bus_proc_control_sonia_common_AddPose* busPtr, sonia_common::AddPose const* msgPtr)
{
  const std::string rosMessageType("sonia_common/AddPose");

  busPtr->Fine =  msgPtr->fine;
  busPtr->Frame =  msgPtr->frame;
  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBus(&busPtr->Position, &msgPtr->position);
  busPtr->Rotation =  msgPtr->rotation;
  busPtr->Speed =  msgPtr->speed;
}


// Conversions between SL_Bus_proc_control_sonia_common_BodyVelocityDVL and sonia_common::BodyVelocityDVL

void convertFromBus(sonia_common::BodyVelocityDVL* msgPtr, SL_Bus_proc_control_sonia_common_BodyVelocityDVL const* busPtr)
{
  const std::string rosMessageType("sonia_common/BodyVelocityDVL");

  msgPtr->eVelBtm =  busPtr->EVelBtm;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->velocity1 =  busPtr->Velocity1;
  msgPtr->velocity2 =  busPtr->Velocity2;
  msgPtr->velocity3 =  busPtr->Velocity3;
  msgPtr->velocity4 =  busPtr->Velocity4;
  msgPtr->xVelBtm =  busPtr->XVelBtm;
  msgPtr->yVelBtm =  busPtr->YVelBtm;
  msgPtr->zVelBtm =  busPtr->ZVelBtm;
}

void convertToBus(SL_Bus_proc_control_sonia_common_BodyVelocityDVL* busPtr, sonia_common::BodyVelocityDVL const* msgPtr)
{
  const std::string rosMessageType("sonia_common/BodyVelocityDVL");

  busPtr->EVelBtm =  msgPtr->eVelBtm;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->Velocity1 =  msgPtr->velocity1;
  busPtr->Velocity2 =  msgPtr->velocity2;
  busPtr->Velocity3 =  msgPtr->velocity3;
  busPtr->Velocity4 =  msgPtr->velocity4;
  busPtr->XVelBtm =  msgPtr->xVelBtm;
  busPtr->YVelBtm =  msgPtr->yVelBtm;
  busPtr->ZVelBtm =  msgPtr->zVelBtm;
}


// Conversions between SL_Bus_proc_control_sonia_common_MpcGains and sonia_common::MpcGains

void convertFromBus(sonia_common::MpcGains* msgPtr, SL_Bus_proc_control_sonia_common_MpcGains const* busPtr)
{
  const std::string rosMessageType("sonia_common/MpcGains");

  convertFromBusVariablePrimitiveArray(msgPtr->MV, busPtr->MV, busPtr->MV_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->MVR, busPtr->MVR, busPtr->MVR_SL_Info);
  msgPtr->max_thrust =  busPtr->MaxThrust;
  msgPtr->min_thrust =  busPtr->MinThrust;
  convertFromBusVariablePrimitiveArray(msgPtr->OV, busPtr->OV, busPtr->OV_SL_Info);
}

void convertToBus(SL_Bus_proc_control_sonia_common_MpcGains* busPtr, sonia_common::MpcGains const* msgPtr)
{
  const std::string rosMessageType("sonia_common/MpcGains");

  convertToBusVariablePrimitiveArray(busPtr->MV, busPtr->MV_SL_Info, msgPtr->MV, slros::EnabledWarning(rosMessageType, "MV"));
  convertToBusVariablePrimitiveArray(busPtr->MVR, busPtr->MVR_SL_Info, msgPtr->MVR, slros::EnabledWarning(rosMessageType, "MVR"));
  busPtr->MaxThrust =  msgPtr->max_thrust;
  busPtr->MinThrust =  msgPtr->min_thrust;
  convertToBusVariablePrimitiveArray(busPtr->OV, busPtr->OV_SL_Info, msgPtr->OV, slros::EnabledWarning(rosMessageType, "OV"));
}


// Conversions between SL_Bus_proc_control_sonia_common_MpcInfo and sonia_common::MpcInfo

void convertFromBus(sonia_common::MpcInfo* msgPtr, SL_Bus_proc_control_sonia_common_MpcInfo const* busPtr)
{
  const std::string rosMessageType("sonia_common/MpcInfo");

  convertFromBus(&msgPtr->currentGains, &busPtr->CurrentGains);
  msgPtr->is_mpc_alive =  busPtr->IsMpcAlive;
  msgPtr->is_trajectory_done =  busPtr->IsTrajectoryDone;
  msgPtr->mpc_mode =  busPtr->MpcMode;
  msgPtr->mpc_status =  busPtr->MpcStatus;
  msgPtr->target_reached =  busPtr->TargetReached;
  convertFromBusVariablePrimitiveArray(msgPtr->thrusters_status, busPtr->ThrustersStatus, busPtr->ThrustersStatus_SL_Info);
}

void convertToBus(SL_Bus_proc_control_sonia_common_MpcInfo* busPtr, sonia_common::MpcInfo const* msgPtr)
{
  const std::string rosMessageType("sonia_common/MpcInfo");

  convertToBus(&busPtr->CurrentGains, &msgPtr->currentGains);
  busPtr->IsMpcAlive =  msgPtr->is_mpc_alive;
  busPtr->IsTrajectoryDone =  msgPtr->is_trajectory_done;
  busPtr->MpcMode =  msgPtr->mpc_mode;
  busPtr->MpcStatus =  msgPtr->mpc_status;
  busPtr->TargetReached =  msgPtr->target_reached;
  convertToBusVariablePrimitiveArray(busPtr->ThrustersStatus, busPtr->ThrustersStatus_SL_Info, msgPtr->thrusters_status, slros::EnabledWarning(rosMessageType, "thrusters_status"));
}


// Conversions between SL_Bus_proc_control_sonia_common_PingAngles and sonia_common::PingAngles

void convertFromBus(sonia_common::PingAngles* msgPtr, SL_Bus_proc_control_sonia_common_PingAngles const* busPtr)
{
  const std::string rosMessageType("sonia_common/PingAngles");

  msgPtr->elevation =  busPtr->Elevation;
  msgPtr->frequency =  busPtr->Frequency;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->heading =  busPtr->Heading;
  msgPtr->snr =  busPtr->Snr;
}

void convertToBus(SL_Bus_proc_control_sonia_common_PingAngles* busPtr, sonia_common::PingAngles const* msgPtr)
{
  const std::string rosMessageType("sonia_common/PingAngles");

  busPtr->Elevation =  msgPtr->elevation;
  busPtr->Frequency =  msgPtr->frequency;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->Heading =  msgPtr->heading;
  busPtr->Snr =  msgPtr->snr;
}


// Conversions between SL_Bus_proc_control_std_msgs_Bool and std_msgs::Bool

void convertFromBus(std_msgs::Bool* msgPtr, SL_Bus_proc_control_std_msgs_Bool const* busPtr)
{
  const std::string rosMessageType("std_msgs/Bool");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_proc_control_std_msgs_Bool* busPtr, std_msgs::Bool const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Bool");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_proc_control_std_msgs_Float32 and std_msgs::Float32

void convertFromBus(std_msgs::Float32* msgPtr, SL_Bus_proc_control_std_msgs_Float32 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float32");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_proc_control_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float32");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_proc_control_std_msgs_Float64MultiArray and std_msgs::Float64MultiArray

void convertFromBus(std_msgs::Float64MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Float64MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float64MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_proc_control_std_msgs_Float64MultiArray* busPtr, std_msgs::Float64MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float64MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_proc_control_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_proc_control_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_proc_control_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_proc_control_std_msgs_Int16MultiArray and std_msgs::Int16MultiArray

void convertFromBus(std_msgs::Int16MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Int16MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int16MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_proc_control_std_msgs_Int16MultiArray* busPtr, std_msgs::Int16MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int16MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_proc_control_std_msgs_Int8MultiArray and std_msgs::Int8MultiArray

void convertFromBus(std_msgs::Int8MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_Int8MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int8MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_proc_control_std_msgs_Int8MultiArray* busPtr, std_msgs::Int8MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int8MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_proc_control_std_msgs_MultiArrayDimension and std_msgs::MultiArrayDimension

void convertFromBus(std_msgs::MultiArrayDimension* msgPtr, SL_Bus_proc_control_std_msgs_MultiArrayDimension const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertFromBusVariablePrimitiveArray(msgPtr->label, busPtr->Label, busPtr->Label_SL_Info);
  msgPtr->size =  busPtr->Size;
  msgPtr->stride =  busPtr->Stride;
}

void convertToBus(SL_Bus_proc_control_std_msgs_MultiArrayDimension* busPtr, std_msgs::MultiArrayDimension const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayDimension");

  convertToBusVariablePrimitiveArray(busPtr->Label, busPtr->Label_SL_Info, msgPtr->label, slros::EnabledWarning(rosMessageType, "label"));
  busPtr->Size =  msgPtr->size;
  busPtr->Stride =  msgPtr->stride;
}


// Conversions between SL_Bus_proc_control_std_msgs_MultiArrayLayout and std_msgs::MultiArrayLayout

void convertFromBus(std_msgs::MultiArrayLayout* msgPtr, SL_Bus_proc_control_std_msgs_MultiArrayLayout const* busPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  msgPtr->data_offset =  busPtr->DataOffset;
  convertFromBusVariableNestedArray(msgPtr->dim, busPtr->Dim, busPtr->Dim_SL_Info);
}

void convertToBus(SL_Bus_proc_control_std_msgs_MultiArrayLayout* busPtr, std_msgs::MultiArrayLayout const* msgPtr)
{
  const std::string rosMessageType("std_msgs/MultiArrayLayout");

  busPtr->DataOffset =  msgPtr->data_offset;
  convertToBusVariableNestedArray(busPtr->Dim, busPtr->Dim_SL_Info, msgPtr->dim, slros::EnabledWarning(rosMessageType, "dim"));
}


// Conversions between SL_Bus_proc_control_std_msgs_UInt16MultiArray and std_msgs::UInt16MultiArray

void convertFromBus(std_msgs::UInt16MultiArray* msgPtr, SL_Bus_proc_control_std_msgs_UInt16MultiArray const* busPtr)
{
  const std::string rosMessageType("std_msgs/UInt16MultiArray");

  convertFromBusVariablePrimitiveArray(msgPtr->data, busPtr->Data, busPtr->Data_SL_Info);
  convertFromBus(&msgPtr->layout, &busPtr->Layout);
}

void convertToBus(SL_Bus_proc_control_std_msgs_UInt16MultiArray* busPtr, std_msgs::UInt16MultiArray const* msgPtr)
{
  const std::string rosMessageType("std_msgs/UInt16MultiArray");

  convertToBusVariablePrimitiveArray(busPtr->Data, busPtr->Data_SL_Info, msgPtr->data, slros::EnabledWarning(rosMessageType, "data"));
  convertToBus(&busPtr->Layout, &msgPtr->layout);
}


// Conversions between SL_Bus_proc_control_std_msgs_UInt8 and std_msgs::UInt8

void convertFromBus(std_msgs::UInt8* msgPtr, SL_Bus_proc_control_std_msgs_UInt8 const* busPtr)
{
  const std::string rosMessageType("std_msgs/UInt8");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_proc_control_std_msgs_UInt8* busPtr, std_msgs::UInt8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/UInt8");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w and trajectory_msgs::MultiDOFJointTrajectoryPoint

void convertFromBus(trajectory_msgs::MultiDOFJointTrajectoryPoint* msgPtr, SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w const* busPtr)
{
  const std::string rosMessageType("trajectory_msgs/MultiDOFJointTrajectoryPoint");

  convertFromBusVariableNestedArray(msgPtr->accelerations, busPtr->Accelerations, busPtr->Accelerations_SL_Info);
  convertFromBus(&msgPtr->time_from_start, &busPtr->TimeFromStart);
  convertFromBusVariableNestedArray(msgPtr->transforms, busPtr->Transforms, busPtr->Transforms_SL_Info);
  convertFromBusVariableNestedArray(msgPtr->velocities, busPtr->Velocities, busPtr->Velocities_SL_Info);
}

void convertToBus(SL_Bus_proc_control_MultiDOFJointTrajectoryPo_2ndf9w* busPtr, trajectory_msgs::MultiDOFJointTrajectoryPoint const* msgPtr)
{
  const std::string rosMessageType("trajectory_msgs/MultiDOFJointTrajectoryPoint");

  convertToBusVariableNestedArray(busPtr->Accelerations, busPtr->Accelerations_SL_Info, msgPtr->accelerations, slros::EnabledWarning(rosMessageType, "accelerations"));
  convertToBus(&busPtr->TimeFromStart, &msgPtr->time_from_start);
  convertToBusVariableNestedArray(busPtr->Transforms, busPtr->Transforms_SL_Info, msgPtr->transforms, slros::EnabledWarning(rosMessageType, "transforms"));
  convertToBusVariableNestedArray(busPtr->Velocities, busPtr->Velocities_SL_Info, msgPtr->velocities, slros::EnabledWarning(rosMessageType, "velocities"));
}

