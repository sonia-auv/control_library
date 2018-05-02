/**
 * \file	TrajectoryGeneratorTest.cc
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

#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include "toolbox/TrajectoryGenerator.h"


class TrajectoryGenerator_Unit_Test : public testing::Test
{
public:
    TrajectoryGenerator_Unit_Test()  {}
    virtual ~TrajectoryGenerator_Unit_Test() {}

    void SetUp()
    {
        timeStamp_ = 0.01;
        pTrajectoryGenerator_ = std::make_shared<control::TrajectoryGenerator>(timeStamp_);
    }

    void TearDown()
    {
        std::ofstream myfile;
        myfile.open(fileName_);

        for (Eigen::VectorXd &pose : outTrajectory_)
        {
            myfile << pose[0] << ";" << pose[1] << ";" << pose[2] << std::endl;
        }
        myfile.close();
    }

    std::shared_ptr<control::TrajectoryGenerator>  pTrajectoryGenerator_;
    std::vector<Eigen::VectorXd> outTrajectory_;
    std::string                  fileName_;
    double timeStamp_;

};


TEST_F(TrajectoryGenerator_Unit_Test, TrajectoryGeneratorTestPose)
{
    double trajectoryTime = 10.0;
    double tol = 1e-10;
    Eigen::VectorXd initialPose = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

    finalPose << 10.0, 0.0, 11.0, 0.0, 0.0, 0.0;

    pTrajectoryGenerator_->GenerateTrajectory(trajectoryTime, initialPose, finalPose);
    outTrajectory_ = pTrajectoryGenerator_->GetPoseTrajectory();
    fileName_      = "TrajectoryPose.csv";

    for (int i = 0; i < CARTESIAN_SPACE; i ++)
    {
        EXPECT_NEAR(outTrajectory_[int(trajectoryTime / timeStamp_)][i], finalPose[i], tol);
    }
}

TEST_F(TrajectoryGenerator_Unit_Test, TrajectoryGeneratorTestTwist)
{
    double trajectoryTime = 10.0;
    Eigen::VectorXd initialPose = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

    finalPose << 10.0, 0.0, 11.0, 0.0, 0.0, 0.0;

    pTrajectoryGenerator_->GenerateTrajectory(trajectoryTime, initialPose, finalPose);
    outTrajectory_ = pTrajectoryGenerator_->GetTwistTrajectory();
    fileName_      = "TrajectoryTwist.csv";
}

TEST_F(TrajectoryGenerator_Unit_Test, TrajectoryGeneratorTestAcceleration)
{
    double trajectoryTime = 10.0;
    Eigen::VectorXd initialPose = Eigen::VectorXd::Zero(CARTESIAN_SPACE);
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

    finalPose << 10.0, 0.0, 11.0, 0.0, 0.0, 0.0;

    pTrajectoryGenerator_->GenerateTrajectory(trajectoryTime, initialPose, finalPose);
    outTrajectory_ = pTrajectoryGenerator_->GetAccelerationTrajectory();
    fileName_      = "TrajectoryAcceleration.csv";
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

