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
            pTrajectoryGenerator_(nullptr)
    {
        pAuvController_       = std::make_shared<ControllerPIDWithDynamic>(transferFunctionCoefficientPosition, transferFunctionCoefficientVelocity, dynamicModelParam, filterOrderPosition, filterOrderVelocity);
        pTrajectoryGenerator_ = std::make_shared<TrajectoryGenerator>(0.02);
    }

    ControlInterface::ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder):
            pAuvController_(nullptr),
            pTrajectoryGenerator_(nullptr)
    {
        pAuvController_       = std::make_shared<ControllerPID>(transferFunctionCoefficient, filterOrder);
        pTrajectoryGenerator_ = std::make_shared<TrajectoryGenerator>(0.02);
    }

    TrajectoryResultType ControlInterface::GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType)
    {
        TrajectoryResultType trajectoryResult;

        pTrajectoryGenerator_->SetZero();

        pTrajectoryGenerator_->GenerateTrajectory(trajectoryGeneratorType.time, trajectoryGeneratorType.startPose, trajectoryGeneratorType.endPose);
        trajectoryResult.pose  = pTrajectoryGenerator_->GetPoseTrajectory();
        trajectoryResult.twist = pTrajectoryGenerator_->GetTwistTrajectory();
        trajectoryResult.accel = pTrajectoryGenerator_->GetAccelerationTrajectory();

        return trajectoryResult;
    }

    Eigen::VectorXd ControlInterface::Process(ControllerCMD command)
    {
        computedWrench_ = pAuvController_->Update(command);
        return computedWrench_;
    }

}
