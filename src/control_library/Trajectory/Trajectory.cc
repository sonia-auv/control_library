//
// Created by olavoie on 5/12/18.
//

#include "Trajectory.h"

namespace control
{
    Trajectory::Trajectory():
        isTrajectoryComputed_(false)
    {
        pTrajectoryGenerator_ = std::make_shared<TrajectoryGenerator>(0.02);
    }

    void Trajectory::GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType)
    {
        ResetTrajectory();

        pTrajectoryGenerator_->GenerateTrajectory(trajectoryGeneratorType.time, trajectoryGeneratorType.startPose, trajectoryGeneratorType.endPose);
        trajectoryResultList_.pose  = pTrajectoryGenerator_->GetPoseTrajectory();
        trajectoryResultList_.twist = pTrajectoryGenerator_->GetTwistTrajectory();
        trajectoryResultList_.accel = pTrajectoryGenerator_->GetAccelerationTrajectory();

        isTrajectoryComputed_ = true;
        i_ = 0;
    }

    TrajectoryResult Trajectory::GetTrajectory()
    {
        if (trajectoryResultList_.pose.size() > i_)
        {
            trajectoryResult_.pose = trajectoryResultList_.pose.at(i_);
        }

        if (trajectoryResultList_.twist.size() > i_)
        {
            trajectoryResult_.twist = trajectoryResultList_.twist.at(i_);
        }

        if (trajectoryResultList_.accel.size() > i_)
        {
            trajectoryResult_.accel = trajectoryResultList_.accel.at(i_);
        }

        i_++;

        return trajectoryResult_;
    }

    void Trajectory::ResetTrajectory()
    {
        pTrajectoryGenerator_->SetZero();
        trajectoryResultList_.pose.clear();
        trajectoryResultList_.twist.clear();
        trajectoryResultList_.accel.clear();
        isTrajectoryComputed_ = false;
    }
}
