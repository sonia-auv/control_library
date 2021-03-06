/**
 * \file	DynamicModel.h
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

#ifndef CONTROL_LIBRARY_DYNAMICMODEL_H
#define CONTROL_LIBRARY_DYNAMICMODEL_H

#include <memory>
#include <eigen3/Eigen/Eigen>

#include "control_library/ControlType.h"

namespace control
{
    class DynamicModel {
    public:
        DynamicModel(std::shared_ptr<DynamicModelParam> &auvDynamicParameters);
        ~DynamicModel() = default;

        Eigen::VectorXd Update(Eigen::VectorXd &acceleration, Eigen::VectorXd &velocity, Eigen::Vector3d &orientation);

    private:
        Eigen::VectorXd ComputeDamping(Eigen::VectorXd &velocity);
        Eigen::VectorXd ComputeGravity(Eigen::Vector3d &orientation);

        std::shared_ptr<DynamicModelParam> auvDynamicParameters_;

    };
}

#endif //CONTROL_LIBRARY_DYNAMICMODEL_H
