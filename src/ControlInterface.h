//
// Created by olavoie on 5/12/18.
//

#ifndef CONTROL_LIBRARY_CONTROLINTERFACE_H
#define CONTROL_LIBRARY_CONTROLINTERFACE_H

#include <memory>

#include "ControlType.h"
#include "Controller/ControllerPIDWithDynamic.h"
#include "Controller/ControllerPID.h"
#include "toolbox/TrajectoryGenerator.h"

namespace control
{
    class ControlInterface
    {
    public:
        ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientPosition,
                         std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientVelocity,
                         std::shared_ptr<DynamicModelParam> &dynamicModelParam, int filterOrderPosition, int filterOrderVelocity);

        ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder);
        ~ControlInterface() = default;

        TrajectoryResultType GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType);
        Eigen::VectorXd Process(ControllerCMD command);

    private:
        std::shared_ptr<ControllerIF>        pAuvController_;
        std::shared_ptr<TrajectoryGenerator> pTrajectoryGenerator_;

        Eigen::VectorXd computedWrench_;
    };

}



#endif //CONTROL_LIBRARY_CONTROLINTERFACE_H
