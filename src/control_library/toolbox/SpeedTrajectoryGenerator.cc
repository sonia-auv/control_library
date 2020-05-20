/**
 * \file	SpeedTrajectoryGenerator.cc
 * \author	Francis Alonzo <francisalonzo29@gmail.com>
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

#include "SpeedTrajectoryGenerator.h"


namespace control
{
    SpeedTrajectoryGenerator::SpeedTrajectoryGenerator(double timeStamp):
            responseTime_(0.0),
            timeStamp_(timeStamp)
    {
        SetZero();
        amplitude_ = 5.0;
        maxAngle_ = 90;
        maxSpeed_ = 0.5;
        kSpeed_ = 0.15;
        kAngle_ = 0.02;
    }

    void SpeedTrajectoryGenerator::SpeedGenerateTrajectory(double trajectoryTime, Eigen::VectorXd &startPose, Eigen::VectorXd &endPose) // Z isnt implented yet start and end should be equal
    {
        double time{0};
        Eigen::Vector3d startOrientation = Eigen::Vector3d(startPose[3], startPose[4], startPose[5]);
        Eigen::Vector3d endOrientation   = Eigen::Vector3d(Eigen::Vector3d(endPose[3], endPose[4], endPose[5]));

        startOrientation_ = EulerToQuaternion(startOrientation);
        endOrientation_   = EulerToQuaternion(endOrientation);

        startPosition_ = startPose;
        endPosition_  << endPose[0], endPose[1], endPose[2], Interpolation(1.0);

        hermiteXvalues_[0] = startPosition_[0];
        hermiteXvalues_[1] = endPosition_[0];
        hermiteXvalues_[2] = amplitude_ * sin(startPosition_[5]*DEGREE_TO_RAD);
        hermiteXvalues_[3] = amplitude_ * sin(endPosition_[5]*DEGREE_TO_RAD);
        
        hermiteYvalues_[0] = startPosition_[1];
        hermiteYvalues_[1] = endPosition_[1];
        hermiteYvalues_[2] = amplitude_ * cos(startPosition_[5]*DEGREE_TO_RAD);
        hermiteYvalues_[3] = amplitude_ * cos(endPosition_[5]*DEGREE_TO_RAD);

        while (time <= 1.0)
        {
            poseTrajectory_.push_back(HermitePositionTrajectory(time));
            twistTrajectory_.push_back(HermiteSpeedTrajectory());
            time += timeStamp_;
        }
    }
    /**
     * @brief Position for trajectory
     * 
     * @param time for the position to be calculated
     * @return Eigen::VectorXd pose for the time
     */
    Eigen::VectorXd SpeedTrajectoryGenerator::HermitePositionTrajectory(double time)
    {
        Eigen::VectorXd posePosition = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        
        posePosition[0] = HermiteX(time);
        posePosition[1] = HermiteY(time);
        posePosition[2] = endPosition_[2];
        posePosition[3] = endPosition_[3];
        posePosition[4] = endPosition_[4];
        posePosition[5] = AngleYaw(posePosition);

        return posePosition;
    }
    /**
     * @brief Speed for trajectory
     * 
     * @return Eigen::VectorXd for the last point created for the trajectory
     */
    Eigen::VectorXd SpeedTrajectoryGenerator::HermiteSpeedTrajectory()
    {
        Eigen::VectorXd poseTemp = poseTrajectory_.back();
        Eigen::VectorXd twist = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

        double speed = kSpeed_ * pow((pow(endPosition_[0]-poseTemp[0],2))+(pow(endPosition_[1]-poseTemp[1],2)),0.5);

        if(speed >= maxSpeed_)
        {
            speed = maxSpeed_;
        }

        twist[0] = speed;
        twist[5] = poseTemp[5];

        return twist;
    }

    Eigen::Vector3d SpeedTrajectoryGenerator::Interpolation(double time)
    {
        endOrientation_.slerp(time, startOrientation_);
        return endOrientation_.toRotationMatrix().eulerAngles(0, 1, 2);
    }
    
    void SpeedTrajectoryGenerator::SetZero() 
    {
        poseTrajectory_.clear();
        twistTrajectory_.clear();

        startPosition_ = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
        endPosition_   = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    }
    /**
     * @brief Hermite Cubic function
     * 
     * @param time for the hermite curve to be calculated
     * @return double answer of the equation for X
     */
    double SpeedTrajectoryGenerator::HermiteX(double time)
    {
        double timesquared = pow(time,2.0);
        double timecubed = pow(time,3.0);
    
        return (2 * timecubed - 3 * timesquared + 1) * hermiteXvalues_[0] + (-2 * timecubed + 3 * timesquared) * hermiteXvalues_[1] +
                    (timecubed - 2 * timesquared + time) * hermiteXvalues_[2] + (timecubed - timesquared) * hermiteXvalues_[3];
    }
    /**
     * @brief Hermite Cubic function
     * 
     * @param time for the hermite curve to be calculated
     * @return double answer of the equation for Y
     */
    double SpeedTrajectoryGenerator::HermiteY(double time)
    {
        double timesquared = pow(time,2.0);
        double timecubed = pow(time,3.0);
    
        return (2 * timecubed - 3 * timesquared + 1) * hermiteYvalues_[0] + (-2 * timecubed + 3 * timesquared) * hermiteYvalues_[1] +
                    (timecubed - 2 * timesquared + time) * hermiteYvalues_[2] + (timecubed - timesquared) * hermiteYvalues_[3];
    }
    /**
     * @brief Max angle equation and verification
     * 
     * @param pose to use from tangente
     * @return double value of the angle
     */
    double SpeedTrajectoryGenerator::AngleYaw(Eigen::VectorXd &pose)
    {
        double angle = atan2(endPosition_[1]-pose[1],endPosition_[0]-pose[0])*RAD_TO_DEGREE;

        if(angle <= -maxAngle_)
        {
            return -maxAngle_;
        }
        else if(angle >= maxAngle_)
        {
            return maxAngle_;
        }
        else
        {
            return angle;
        }
    }
}