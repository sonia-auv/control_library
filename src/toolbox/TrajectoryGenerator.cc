/**
 * \file	TrajectoryGenerator.cc
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

#include "TrajectoryGenerator.h"


namespace control
{
    TrajectoryGenerator::TrajectoryGenerator(double timeStamp):
        responseTime_(0.0),
        timeStamp_(timeStamp)
    {
        startPosition_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        endPosition_   = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

    }

    void TrajectoryGenerator::GenerateTrajectory(double trajectoryTime, Eigen::VectorXd &startPose, Eigen::VectorXd &endPose)
    {
        Eigen::Vector3d startOrientation = Eigen::Vector3d(startPose[3], startPose[4], startPose[5]);
        Eigen::Vector3d endOrientation   = Eigen::Vector3d(Eigen::Vector3d(endPose[3], endPose[4], endPose[5]));

        startOrientation_ = EulerToQuaternion(startOrientation);
        endOrientation_   = EulerToQuaternion(endOrientation);

        startPosition_ = startPose;
        endPosition_  << endPose[0], endPose[1], endPose[2], Interpolation(1.0);

        responseTime_ = trajectoryTime / timeStamp_;

        for (int i = 0; i <= int(responseTime_); i++)
        {
            poseTrajectory_.push_back(PoseTrajectory(i));
            twistTrajectory_.push_back(TwistTrajectory(i));
            accelerationTrajectory_.push_back(AccelerationTrajectory(i));
        }
    }

    Eigen::VectorXd TrajectoryGenerator::PoseTrajectory(double time)
    {
        Eigen::VectorXd poseTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        poseTrajectory = TranslationPositionTrajectory(time);
        poseTrajectory << poseTrajectory[0], poseTrajectory[1], poseTrajectory[2], Interpolation(1.0);
        return poseTrajectory;
    }

    Eigen::VectorXd TrajectoryGenerator::TwistTrajectory(double time)
    {
        Eigen::VectorXd twistTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        twistTrajectory = TranslationSpeedTrajectory(time);
        return twistTrajectory;
    }

    Eigen::VectorXd TrajectoryGenerator::AccelerationTrajectory(double time)
    {
        Eigen::VectorXd accelerationTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        accelerationTrajectory = TranslationAccelerationTrajectory(time);
        return accelerationTrajectory;
    }

    Eigen::VectorXd TrajectoryGenerator::TranslationPositionTrajectory(double time)
    {
        double splineTimeSquared   = pow(time, 2);
        double splineTimeCubed     = pow(time, 3);
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return startPosition_ + (3 / responseTimeSquared) * (endPosition_ - startPosition_) * splineTimeSquared + (-2 / responseTimeCubed) * (endPosition_ - startPosition_) * splineTimeCubed;
    }

    Eigen::VectorXd TrajectoryGenerator::TranslationSpeedTrajectory(double time)
    {
        double splineTime          = time;
        double splineTimeSquared   = pow(time, 2);
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return 2 * (3 / responseTimeSquared) * (endPosition_ - startPosition_) * splineTime + 3 * (-2 / responseTimeCubed) * (endPosition_ - startPosition_) * splineTimeSquared;
    }

    Eigen::VectorXd TrajectoryGenerator::TranslationAccelerationTrajectory(double time)
    {
        double splineTime          = time;
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return 2 * (3 / responseTimeSquared) * (endPosition_ - startPosition_) + 6 * (-2 / responseTimeCubed) * (endPosition_ - startPosition_) * splineTime;
    }


    Eigen::Vector3d TrajectoryGenerator::Interpolation(double time)
    {
        endOrientation_.slerp(time, startOrientation_);
        return endOrientation_.toRotationMatrix().eulerAngles(0, 1, 2);
    }

}