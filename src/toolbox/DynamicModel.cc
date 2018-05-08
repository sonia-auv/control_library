/**
 * \file	DynamicModel.cc
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

#include "DynamicModel.h"


namespace control
{
    DynamicModel::DynamicModel(std::shared_ptr<DynamicModelParam> &auvDynamicParameters): auvDynamicParameters_(auvDynamicParameters) {}

    Eigen::VectorXd DynamicModel::Update(Eigen::VectorXd &acceleration, Eigen::VectorXd &velocity, Eigen::Vector3d &orientation)
    {
        Eigen::VectorXd damping = ComputeDamping(velocity).array() * velocity.array();
        Eigen::VectorXd wrench;

        wrench = auvDynamicParameters_->auvAddedMass * acceleration + damping + ComputeGravity(orientation);

        return wrench;
    }

    Eigen::VectorXd DynamicModel::ComputeDamping(Eigen::VectorXd &velocity)
    {
        return auvDynamicParameters_->auvDamping.constDragCoefficient.array() +  auvDynamicParameters_->auvDamping.quadDragCoefficient.array() * (velocity.array() * velocity.array());
    }

    Eigen::VectorXd DynamicModel::ComputeGravity(Eigen::Vector3d &orientation)
    {
        Eigen::VectorXd gravityVector = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

        gravityVector[0] = auvDynamicParameters_->resultingForce  * sin(orientation[1]);
        gravityVector[1] = -auvDynamicParameters_->resultingForce * sin(orientation[0]) * cos(orientation[1]);
        gravityVector[2] = -auvDynamicParameters_->resultingForce * cos(orientation[0]) * cos(orientation[1]);

        gravityVector[3] = auvDynamicParameters_->buoyancyForce  * cos(orientation[1]) * (auvDynamicParameters_->auvBuoyancyCenter[2] * sin(orientation[0]) - auvDynamicParameters_->auvBuoyancyCenter[1] * cos(orientation[0]));
        gravityVector[4] = auvDynamicParameters_->buoyancyForce  * (auvDynamicParameters_->auvBuoyancyCenter[0] * cos(orientation[0]) * cos(orientation[1]) - auvDynamicParameters_->auvBuoyancyCenter[2] * sin(orientation[1]));
        gravityVector[5] = -auvDynamicParameters_->buoyancyForce * (auvDynamicParameters_->auvBuoyancyCenter[0] * sin(orientation[0]) * cos(orientation[1]) - auvDynamicParameters_->auvBuoyancyCenter[1] * sin(orientation[1]));
        return gravityVector;
    }

}