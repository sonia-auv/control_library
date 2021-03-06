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

#include "ControllerPID.h"


namespace control
{
    ControllerPID::ControllerPID(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder):
            transferFunction_(CARTESIAN_SPACE, transferFunctionCoefficient, filterOrder)
    {
        positionCommand_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    }

    Eigen::VectorXd ControllerPID::Update(ControllerCMD &controllerCMD)
    {
        positionCommand_ = transferFunction_.Update(controllerCMD.errorPose);

        computedWrench_ = positionCommand_;

        return computedWrench_;
    }
    
    void ControllerPID::Exit() 
    {
        positionCommand_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        transferFunction_.SetZero();
    }
}
