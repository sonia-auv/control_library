/**
 * \file	DynamicModelTest.cc
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
#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include "control_library/toolbox/TrajectoryGenerator.h"
#include "control_library/toolbox/DynamicModel.h"
#include "control_library/ControlType.h"

#include <iostream>


class DynamicModel_Unit_Test : public testing::Test
{
public:
    DynamicModel_Unit_Test()  {}
    virtual ~DynamicModel_Unit_Test() {}

    void SetUp()
    {
        timeStamp_ = 0.02;
        pTrajectoryGenerator_ = std::make_shared<control::TrajectoryGenerator>(timeStamp_);
        pDynamicModelParam_   = std::make_shared<control::DynamicModelParam>();
    }

    void TearDown()
    {
        std::ofstream myfile;
        myfile.open(fileName_);

        for (Eigen::VectorXd &pose : outWrench_)
        {
            myfile << pose[0] << ";" << pose[1] << ";" << pose[2] << ";" << pose[3] << ";" << pose[4] << ";" << pose[5] << std::endl;
        }
        myfile.close();
    }

    void initDynamicParameters()
    {
        pDynamicModelParam_->auvDamping.constDragCoefficient = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        pDynamicModelParam_->auvDamping.quadDragCoefficient  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
        pDynamicModelParam_->auvAddedMass                    = Eigen::MatrixXd::Zero(control::CARTESIAN_SPACE, control::CARTESIAN_SPACE);

        pDynamicModelParam_->auvBuoyancyCenter << 0.0, 0.0, 0.0;
        pDynamicModelParam_->auvDamping.constDragCoefficient << 136.1473, 104.6571, 0.0, 0.0, 0.0, 76.4971;
        pDynamicModelParam_->auvDamping.quadDragCoefficient  << 3.7787, 51.7301, 0.0, 0.0, 0.0, -122.1888;

        pDynamicModelParam_->auvAddedMass << 50.0, 0.0,  0.0,  0.0, 0.0, 0.0,
                                             0.0,  50.0, 0.0,  0.0, 0.0, 0.0,
                                             0.0,  0.0,  50.0, 0.0, 0.0, 0.0,
                                             0.0,  0.0,  0.0,  1.9, 0.0, 0.0,
                                             0.0,  0.0,  0.0,  0.0, 3.1, 0.0,
                                             0.0,  0.0,  0.0,  0.0, 0.0, 1.7;

        pDynamicModelParam_->buoyancyForce  = -0.04949949 * 1025.0 * 9.81;
        double gravity = 50.0 * 9.81;

        pDynamicModelParam_->resultingForce = gravity + pDynamicModelParam_->buoyancyForce;

        pDynamicModel_ = std::make_shared<control::DynamicModel>(pDynamicModelParam_);

    }

    std::shared_ptr<control::DynamicModelParam>   pDynamicModelParam_;
    std::shared_ptr<control::TrajectoryGenerator> pTrajectoryGenerator_;
    std::shared_ptr<control::DynamicModel>        pDynamicModel_;
    std::vector<Eigen::VectorXd> poseTrajectory_;
    std::vector<Eigen::VectorXd> twistTrajectory_;
    std::vector<Eigen::VectorXd> accelTrajectory_;
    std::vector<Eigen::VectorXd> outWrench_;
    std::string                  fileName_;
    double timeStamp_;

};


TEST_F(DynamicModel_Unit_Test, DynamicModelXaxisTest)
{
    double trajectoryTime = 5.0;

    fileName_         = "DynamicModelXaxis.csv";
    Eigen::VectorXd initialPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    finalPose << 1.0, 0.0, 0.0, 0.0, 0.0, 0.0;

    pTrajectoryGenerator_->GenerateTrajectory(trajectoryTime, initialPose, finalPose);
    poseTrajectory_   = pTrajectoryGenerator_->GetPoseTrajectory();
    twistTrajectory_  = pTrajectoryGenerator_->GetTwistTrajectory();
    accelTrajectory_  = pTrajectoryGenerator_->GetAccelerationTrajectory();
    initDynamicParameters();

    for (size_t i = 0; i < poseTrajectory_.size(); i++)
    {
        Eigen::Vector3d orientation;
        orientation << poseTrajectory_[i][3], poseTrajectory_[i][4], poseTrajectory_[i][5];
        outWrench_.push_back(pDynamicModel_->Update(accelTrajectory_[i], twistTrajectory_[i], orientation));
    }

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
