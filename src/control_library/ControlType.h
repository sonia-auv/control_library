/**
 * \file	ControlType.h
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

#ifndef CONTROL_LIBRARY_CONTROLTYPE_H
#define CONTROL_LIBRARY_CONTROLTYPE_H

#include <eigen3/Eigen/Eigen>


namespace control
{
    const int CARTESIAN_SPACE   = 6;
    const int POSITION_SPACE    = 3;
    const int ORIENTATION_SPACE = 3;

    const double DEGREE_TO_RAD = M_PI / 180.0;
    const double RAD_TO_DEGREE = 180.0 / M_PI;

    struct dragParameters
    {
        Eigen::VectorXd constDragCoefficient;
        Eigen::VectorXd quadDragCoefficient;
    };

    struct DynamicModelParam
    {
        dragParameters  auvDamping;
        Eigen::MatrixXd auvAddedMass;
        Eigen::Vector3d auvBuoyancyCenter;
        double          resultingForce;
        double          buoyancyForce;
    };

    struct ControllerCMD
    {
        Eigen::VectorXd errorPose;
        Eigen::VectorXd errorVelocity;
        Eigen::VectorXd acceleration;
        Eigen::VectorXd velocity;
        Eigen::Vector3d orientation;
    };

    struct TransferFunctionCoefficient
    {
        Eigen::ArrayXXd numeratorFactor;
        Eigen::ArrayXXd denominatorFactor;
    };

    struct TrajectoryGeneratorType
    {
        double          time;
        Eigen::VectorXd startPose;
        Eigen::VectorXd endPose;
    };

    struct TrajectoryResultList
    {
        std::vector<Eigen::VectorXd> pose;
        std::vector<Eigen::VectorXd> twist;
        std::vector<Eigen::VectorXd> accel;
    };

    struct TrajectoryResult
    {
        Eigen::VectorXd pose;
        Eigen::VectorXd twist;
        Eigen::VectorXd accel;
    };


    enum ControlType
    {
        PID = 0,
        PIDWithDynamic
    };
}

#endif //CONTROL_LIBRARY_CONTROLTYPE_H
