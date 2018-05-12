/**
 * \file	ControllerPIDWithDynamicTest.cc
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
#include "toolbox/TrajectoryGenerator.h"
#include "Controller/ControllerPIDWithDynamic.h"
#include "toolbox/TransferFunction.h"
#include "ControlType.h"


class ControllerPIDWithDynamic_Unit_Test : public testing::Test
{
public:
    ControllerPIDWithDynamic_Unit_Test()  {}
    virtual ~ControllerPIDWithDynamic_Unit_Test() {}

    void SetUp()
    {
        timeStamp_ = 0.02;
        pTrajectoryGenerator_ = std::make_shared<control::TrajectoryGenerator>(timeStamp_);
        pDynamicModelParam_   = std::make_shared<control::DynamicModelParam>();

        pTransferFunctionCoefficientPosition_ = std::make_shared<control::TransferFunctionCoefficient>();
        pTransferFunctionCoefficientVelocity_ = std::make_shared<control::TransferFunctionCoefficient>();
        pTransferFunctionCoefficientRobot_    = std::make_shared<control::TransferFunctionCoefficient>();

        pRobotTransferFunction_    = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientRobot_, 1);
        pIntegralTransferFunction_ = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientVelocity_, 1);

    }

    void TearDown()
    {
        std::ofstream myfile;
        myfile.open(fileName_);

        for (Eigen::VectorXd &pose : outPose_)
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
    }

    void TfCoefficient()
    {
        Eigen::ArrayXXd denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2);
        Eigen::ArrayXXd numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << 0.0, -1.0;
            numeratorFactor.row(i)   << 310.0185000000000, -539.9630000000001, 230.0185000000000;
        }

        pTransferFunctionCoefficientPosition_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientPosition_->denominatorFactor = denominatorFactor;

        denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1);
        numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << -1.0;
            numeratorFactor.row(i)   << 0.01, 0.01;
        }

        pTransferFunctionCoefficientVelocity_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientVelocity_->denominatorFactor = denominatorFactor;


        denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1);
        numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << -0.946463485239604;
            numeratorFactor.row(i)   << 0.000196612473256526, 0.000196612473256526;
        }

        pTransferFunctionCoefficientRobot_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientRobot_->denominatorFactor = denominatorFactor;
    }

    std::shared_ptr<control::DynamicModelParam>            pDynamicModelParam_;
    std::shared_ptr<control::TrajectoryGenerator>          pTrajectoryGenerator_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientPosition_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientVelocity_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientRobot_;
    std::shared_ptr<control::ControllerIF>                 AUVController_;
    std::shared_ptr<control::TransferFunction>             pRobotTransferFunction_;
    std::shared_ptr<control::TransferFunction>             pIntegralTransferFunction_;

    std::vector<Eigen::VectorXd> poseTrajectory_;
    std::vector<Eigen::VectorXd> twistTrajectory_;
    std::vector<Eigen::VectorXd> accelTrajectory_;
    std::vector<Eigen::VectorXd> outPose_;
    std::string                  fileName_;
    double timeStamp_;

};


TEST_F(ControllerPIDWithDynamic_Unit_Test, ControllerPIDDynamicXaxisTest)
{
    control::ControllerCMD controllerCMD;

    initDynamicParameters();
    TfCoefficient();

    AUVController_ = std::make_shared<control::ControllerPIDWithDynamic>(pTransferFunctionCoefficientPosition_, pTransferFunctionCoefficientVelocity_, pDynamicModelParam_, 2, 1);

    double trajectoryTime = 3.0;

    fileName_         = "ControllerPIDWithDynamicXaxis.csv";
    Eigen::VectorXd initialPose = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    Eigen::VectorXd poseTrajectory;
    Eigen::VectorXd twistTrajectory;
    Eigen::VectorXd accelTrajectory;

    finalPose << 2.0, 0.0, 0.0, 0.0, 0.0, 0.0;

    pTrajectoryGenerator_->GenerateTrajectory(trajectoryTime, initialPose, finalPose);
    poseTrajectory_   = pTrajectoryGenerator_->GetPoseTrajectory();
    twistTrajectory_  = pTrajectoryGenerator_->GetTwistTrajectory();
    accelTrajectory_  = pTrajectoryGenerator_->GetAccelerationTrajectory();

    Eigen::VectorXd actualPose  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd actualTwist = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd wrench      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    for (unsigned int i = 0; i < 372; i++)
    {
        if (i < poseTrajectory_.size())
        {
            poseTrajectory  = poseTrajectory_[i];
            twistTrajectory = twistTrajectory_[i];
            accelTrajectory = accelTrajectory_[i];
        } else
        {
            poseTrajectory  = poseTrajectory_[poseTrajectory_.size() - 1];
            twistTrajectory = twistTrajectory_[twistTrajectory_.size() - 1];
            accelTrajectory = accelTrajectory_[accelTrajectory_.size() - 1];
        }


        controllerCMD.errorPose     = poseTrajectory  - actualPose;
        controllerCMD.errorVelocity = twistTrajectory - actualTwist;

        controllerCMD.orientation   << poseTrajectory[3], poseTrajectory[4], poseTrajectory[5];
        controllerCMD.velocity      = actualTwist;
        controllerCMD.acceleration  = accelTrajectory;

        wrench = AUVController_->Update(controllerCMD);

        actualTwist = pRobotTransferFunction_->Update(wrench);
        actualPose  = pIntegralTransferFunction_->Update(actualTwist);
        outPose_.push_back(actualPose);

    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
