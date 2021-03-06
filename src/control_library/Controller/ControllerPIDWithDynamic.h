/**
 * \file	ControllerPIDWithDynamic.h
 * \author	Olivier Lavoie <olavoie9507@gmail.com>
 *
 * \copyright Copyright (c) 2018 S.O.N.I.A. AUV All rights reserved.
 *
 * \section LICENSE
 *
 * This file is part of S.O.N.I.A. software.
 *
 * S.O.N.I.A. AUV software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S.O.N.I.A. AUV software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S.O.N.I.A. AUV software. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONTROL_LIBRARY_CONTROLLERPIDWITHDYNAMIC_H
#define CONTROL_LIBRARY_CONTROLLERPIDWITHDYNAMIC_H

#include <eigen3/Eigen/Eigen>
#include <memory>

#include "control_library/toolbox/DynamicModel.h"
#include "control_library/toolbox/TransferFunction.h"
#include "ControllerIF.h"
#include "control_library/ControlType.h"

namespace control
{
    class ControllerPIDWithDynamic : public ControllerIF
    {
    public:
        ControllerPIDWithDynamic(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientPosition,
                   std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientVelocity,
                   std::shared_ptr<DynamicModelParam> &dynamicModelParam, int filterOrderPosition, int filterOrderVelocity);
        virtual ~ControllerPIDWithDynamic() = default;

        Eigen::VectorXd Update(ControllerCMD &controllerCMD) override;
        void Exit() override;

    private:

        Eigen::VectorXd positionCommand_;
        Eigen::VectorXd velocityCommand_;
        Eigen::VectorXd accelerationCommand_;

        Eigen::VectorXd computedWrench_;

        TransferFunction transferFunctionPosition_;
        TransferFunction transferFunctionVelocity_;

        DynamicModel     dynamicModel_;

    };
}

#endif //CONTROL_LIBRARY_CONTROLLERPIDWITHDYNAMIC_H
