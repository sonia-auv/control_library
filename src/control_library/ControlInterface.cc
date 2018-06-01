//
// Created by olavoie on 5/12/18.
//

#include "ControlInterface.h"

namespace control
{
    ControlInterface::ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientPosition,
                                       std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientVelocity,
                                       std::shared_ptr<DynamicModelParam> &dynamicModelParam, int filterOrderPosition, int filterOrderVelocity):
            pAuvController_(nullptr),
            pTrajectoryGenerator_(nullptr),
            isTrajectoryComputed_(false)
    {
        pAuvController_       = std::make_shared<ControllerPIDWithDynamic>(transferFunctionCoefficientPosition, transferFunctionCoefficientVelocity, dynamicModelParam, filterOrderPosition, filterOrderVelocity);
        pTrajectoryGenerator_ = std::make_shared<TrajectoryGenerator>(0.02);
    }

    ControlInterface::ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder):
            pAuvController_(nullptr),
            pTrajectoryGenerator_(nullptr),
            isTrajectoryComputed_(false)
    {
        pAuvController_       = std::make_shared<ControllerPID>(transferFunctionCoefficient, filterOrder);
        pTrajectoryGenerator_ = std::make_shared<TrajectoryGenerator>(0.02);
    }

    void ControlInterface::GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType)
    {
        ResetTrajectory();

        pTrajectoryGenerator_->GenerateTrajectory(trajectoryGeneratorType.time, trajectoryGeneratorType.startPose, trajectoryGeneratorType.endPose);
        trajectoryResultList_.pose  = pTrajectoryGenerator_->GetPoseTrajectory();
        trajectoryResultList_.twist = pTrajectoryGenerator_->GetTwistTrajectory();
        trajectoryResultList_.accel = pTrajectoryGenerator_->GetAccelerationTrajectory();

        isTrajectoryComputed_ = true;
        i_ = 0;
    }

    TrajectoryResult ControlInterface::GetTrajetory()
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

    void ControlInterface::ResetTrajectory()
    {
        pTrajectoryGenerator_->SetZero();
        trajectoryResultList_.pose.clear();
        trajectoryResultList_.twist.clear();
        trajectoryResultList_.accel.clear();
        isTrajectoryComputed_ = false;
    }

    Eigen::VectorXd ControlInterface::Process(ControllerCMD command)
    {
        computedWrench_ = pAuvController_->Update(command);
        return computedWrench_;
    }

}
