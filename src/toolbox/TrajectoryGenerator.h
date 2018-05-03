/**
 * \file	TrajectoryGenerator.h
 * \author	Olivier Lavoie <olavoie9507@gmail.com>
 * \date	10/21/17
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
        Eigen::Vector3d TranslationPositionTrajectory(double time);
        Eigen::Vector3d TranslationSpeedTrajectory(double time);
        Eigen::Vector3d TranslationAccelerationTrajectory(double time);
//        Eigen::Vector3d OrientationPositionTrajectory(double time);
//        Eigen::Vector3d OrientationSpeedTrajectory(double time);
//        Eigen::Vector3d OrientationAccelerationTrajectory(double time);

        double responseTime_;
        double timeStamp_;

        Eigen::VectorXd startPose_;
        Eigen::VectorXd endPose_;

        Eigen::Vector3d startPostion_;
        Eigen::Vector3d endPosition_;

        std::vector<Eigen::VectorXd> poseTrajectory_;
        std::vector<Eigen::VectorXd> twistTrajectory_;
        std::vector<Eigen::VectorXd> accelerationTrajectory_;

    };
}



#endif //CONTROL_LIBRARY_TRAJECTORYGENERATOR_H
