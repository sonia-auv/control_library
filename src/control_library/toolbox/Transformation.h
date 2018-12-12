
/**
 * \file	Transformation.h
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

#ifndef CONTROL_LIBRARY_TRANSFORMATION_H
#define CONTROL_LIBRARY_TRANSFORMATION_H

#include <eigen3/Eigen/Eigen>

namespace control
{
    Eigen::Quaterniond EulerToQuaternion(Eigen::Vector3d &eulerAngle);
    Eigen::Matrix3d    EulerToRotationMatrix(Eigen::Vector3d &eulerAngle);
    Eigen::Matrix3d    EulerToRotationMatrix(Eigen::VectorXd &pose);
    Eigen::Matrix3d    EulerToRotationMatrix(double & roll, double & pitch, double & yaw);
    Eigen::Affine3d    HomogeneousMatrix(Eigen::Vector3d &eulerAngle, Eigen::Vector3d &translation);
    Eigen::Affine3d    HomogeneousMatrix(Eigen::VectorXd &pose);

}

#endif //CONTROL_LIBRARY_TRANSFORMATION_H
