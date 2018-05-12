/**
 * \file	ControllerPIDWithDynamic.cc
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

#include "ControllerPIDWithDynamic.h"


namespace control
{
    ControllerPIDWithDynamic::ControllerPIDWithDynamic(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientPosition,
                           std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficientVelocity,
                           std::shared_ptr<DynamicModelParam> &dynamicModelParam, int filterOrderPosition, int filterOrderVelocity):
        transferFunctionPosition_(CARTESIAN_SPACE, transferFunctionCoefficientPosition, filterOrderPosition),
        transferFunctionVelocity_(CARTESIAN_SPACE, transferFunctionCoefficientVelocity, filterOrderVelocity),
        dynamicModel_(dynamicModelParam)
    {
        positionCommand_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        velocityCommand_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    }

    Eigen::VectorXd ControllerPIDWithDynamic::Update(ControllerCMD &controllerCMD)
    {
        positionCommand_ = transferFunctionPosition_.Update(controllerCMD.errorPose);
        velocityCommand_ = transferFunctionVelocity_.Update(controllerCMD.errorVelocity);

        accelerationCommand_ = controllerCMD.acceleration.array() + positionCommand_.array() + velocityCommand_.array();

        computedWrench_ = dynamicModel_.Update(accelerationCommand_, controllerCMD.velocity, controllerCMD.orientation);

        return computedWrench_;
    }
}