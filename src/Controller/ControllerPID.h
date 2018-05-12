//
// Created by olavoie on 5/12/18.
//

#ifndef CONTROL_LIBRARY_CONTROLLERPID_H
#define CONTROL_LIBRARY_CONTROLLERPID_H

#include <eigen3/Eigen/Eigen>
#include <memory>

#include "toolbox/TransferFunction.h"
#include "ControllerIF.h"
#include "ControlType.h"


namespace control
{
    class ControllerPID : public ControllerIF
    {
    public:
        ControllerPID(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder);
        virtual ~ControllerPID() = default;

        Eigen::VectorXd Update(ControllerCMD &controllerCMD) override;

    private:

        Eigen::VectorXd  positionCommand_;
        Eigen::VectorXd  computedWrench_;
        TransferFunction transferFunction_;

    };
}




#endif //CONTROL_LIBRARY_CONTROLLERPID_H
