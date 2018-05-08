/**
 * \file	TrajectoryGenerator.cc
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

#include "TrajectoryGenerator.h"
#include "iostream"

namespace control
{
    TrajectoryGenerator::TrajectoryGenerator(double timeStamp):
        responseTime_(0.0),
        timeStamp_(timeStamp)
    {
        startPose_    = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        endPose_      = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        startPostion_ = Eigen::Vector3d::Zero();
        endPosition_  = Eigen::Vector3d::Zero();

    }

    void TrajectoryGenerator::GenerateTrajectory(double trajectoryTime, Eigen::VectorXd &startPose, Eigen::VectorXd &endPose)
    {
        startPose_      = startPose;
        endPose_        = endPose;

        startPostion_ << startPose_[0], startPose_[1], startPose_[2];
        endPosition_  << endPose_[0], endPose_[1], endPose_[2];

        responseTime_ = trajectoryTime;

        double time;
        for (int i = 0; i < int(trajectoryTime / timeStamp_); i++)
        {
            time = i * timeStamp_;
            poseTrajectory_.push_back(PoseTrajectory(time));
            twistTrajectory_.push_back(TwistTrajectory(time));
            accelerationTrajectory_.push_back(AccelerationTrajectory(time));
        }
    }

    Eigen::VectorXd TrajectoryGenerator::PoseTrajectory(double time)
    {
        Eigen::VectorXd poseTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        poseTrajectory << TranslationPositionTrajectory(time), 0.0, 0.0, 0.0;
        return poseTrajectory;
    }

    Eigen::VectorXd TrajectoryGenerator::TwistTrajectory(double time)
    {
        Eigen::VectorXd twistTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        twistTrajectory << TranslationSpeedTrajectory(time), 0.0, 0.0, 0.0;
        return twistTrajectory;
    }

    Eigen::VectorXd TrajectoryGenerator::AccelerationTrajectory(double time)
    {
        Eigen::VectorXd accelerationTrajectory = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        accelerationTrajectory << TranslationAccelerationTrajectory(time), 0.0, 0.0, 0.0;
        return accelerationTrajectory;
    }

    Eigen::Vector3d TrajectoryGenerator::TranslationPositionTrajectory(double time)
    {
        double splineTimeSquared   = pow(time, 2);
        double splineTimeCubed     = pow(time, 3);
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return startPostion_ + (3 / responseTimeSquared) * (endPosition_ - startPostion_) * splineTimeSquared + (-2 / responseTimeCubed) * (endPosition_ - startPostion_) * splineTimeCubed;
    }

    Eigen::Vector3d TrajectoryGenerator::TranslationSpeedTrajectory(double time)
    {
        double splineTime          = time;
        double splineTimeSquared   = pow(time, 2);
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return 2 * (3 / responseTimeSquared) * (endPosition_ - startPostion_) * splineTime + 3 * (-2 / responseTimeCubed) * (endPosition_ - startPostion_) * splineTimeSquared;
    }

    Eigen::Vector3d TrajectoryGenerator::TranslationAccelerationTrajectory(double time)
    {
        double splineTime          = time;
        double responseTimeSquared = pow(responseTime_, 2);
        double responseTimeCubed   = pow(responseTime_, 3);

        return 2 * (3 / responseTimeSquared) * (endPosition_ - startPostion_) + 6 * (-2 / responseTimeCubed) * (endPosition_ - startPostion_) * splineTime;
    }




}