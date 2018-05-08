/**
 * \file	TrajectoryGenerator.h
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

#ifndef CONTROL_LIBRARY_TRAJECTORYGENERATOR_H
#define CONTROL_LIBRARY_TRAJECTORYGENERATOR_H

#include <eigen3/Eigen/Eigen>
#include <vector>

#include "Transformation.h"
#include "ControlType.h"


namespace control
{
    class TrajectoryGenerator {
    public:
        TrajectoryGenerator(double timeStamp);
        ~TrajectoryGenerator() = default;

        void GenerateTrajectory(double trajectoryTime, Eigen::VectorXd &startPose, Eigen::VectorXd &endPose);
        std::vector<Eigen::VectorXd> GetPoseTrajectory() { return poseTrajectory_;}
        std::vector<Eigen::VectorXd> GetTwistTrajectory() { return twistTrajectory_;}
        std::vector<Eigen::VectorXd> GetAccelerationTrajectory() { return accelerationTrajectory_;}


    private:
        Eigen::VectorXd PoseTrajectory(double time);
        Eigen::VectorXd TwistTrajectory(double time);
        Eigen::VectorXd AccelerationTrajectory(double time);
        Eigen::VectorXd TranslationPositionTrajectory(double time);
        Eigen::VectorXd TranslationSpeedTrajectory(double time);
        Eigen::VectorXd TranslationAccelerationTrajectory(double time);
        Eigen::Vector3d Interpolation(double time);

        double responseTime_;
        double timeStamp_;

        Eigen::VectorXd startPosition_;
        Eigen::VectorXd endPosition_;
        Eigen::Quaterniond startOrientation_;
        Eigen::Quaterniond endOrientation_;

        std::vector<Eigen::VectorXd> poseTrajectory_;
        std::vector<Eigen::VectorXd> twistTrajectory_;
        std::vector<Eigen::VectorXd> accelerationTrajectory_;

    };
}



#endif //CONTROL_LIBRARY_TRAJECTORYGENERATOR_H
