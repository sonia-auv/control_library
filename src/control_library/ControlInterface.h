//
// Created by olavoie on 5/12/18.
//

#ifndef CONTROL_LIBRARY_CONTROLINTERFACE_H
#define CONTROL_LIBRARY_CONTROLINTERFACE_H

#include <memory>

#include "ControlType.h"
#include "control_library/Controller/ControllerPIDWithDynamic.h"
#include "control_library/Controller/ControllerPID.h"
#include "control_library/toolbox/TrajectoryGenerator.h"

namespace control
{
    class ControlInterface
    {
    public:
        ControlInterface();

        ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientPosition,
                         std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientVelocity,
                         std::shared_ptr<DynamicModelParam> &dynamicModelParam, int filterOrderPosition, int filterOrderVelocity);

        ControlInterface(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder);
        ~ControlInterface() = default;

        void GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType);
        TrajectoryResult GetTrajetory();
        bool IsTrajectoryComputed() {return isTrajectoryComputed_;}
        void ResetTrajectory();
        Eigen::VectorXd Process(ControllerCMD command);

    private:
        std::shared_ptr<ControllerIF>        pAuvController_;
        std::shared_ptr<TrajectoryGenerator> pTrajectoryGenerator_;
        TrajectoryResultList                 trajectoryResultList_;

        Eigen::VectorXd  computedWrench_;
        TrajectoryResult trajectoryResult_;

        bool isTrajectoryComputed_;
        unsigned int i_;
    };

}

#endif //CONTROL_LIBRARY_CONTROLINTERFACE_H
