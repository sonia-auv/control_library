/**
 * \file	PPISimulationTest.cc
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
#include "control_library/Controller/ControllerPID.h"
#include "control_library/toolbox/TransferFunction.h"
#include "control_library/ControlType.h"


class PPISimulation_Unit_Test : public testing::Test
{
public:
    PPISimulation_Unit_Test()  {}
    virtual ~PPISimulation_Unit_Test() {}

    void SetUp()
    {
        timeStamp_ = 0.001;

        pTransferFunctionCoefficientPI_ = std::make_shared<control::TransferFunctionCoefficient>();
        pTransferFunctionCoefficientFeedback_ = std::make_shared<control::TransferFunctionCoefficient>();
        pTransferFunctionCoefficientRobot_    = std::make_shared<control::TransferFunctionCoefficient>();

        pRobotTransferFunction_    = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientRobot_, 2);
        pFeedbackTransferFunction_ = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientFeedback_, 1);
        pPITransferFunction_ = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientPI_, 1);

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

    void TfCoefficient()
    {
        Eigen::ArrayXXd denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1);
        Eigen::ArrayXXd numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << -1;
            numeratorFactor.row(i)   << 44.819837987862144, -44.609995880983732;
        }

        pTransferFunctionCoefficientPI_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientPI_->denominatorFactor = denominatorFactor;

        denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1);
        numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 1 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << -0.995318097603672;
            numeratorFactor.row(i)   << 0.0, 0.00007048135867432401;
        }

        pTransferFunctionCoefficientFeedback_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientFeedback_->denominatorFactor = denominatorFactor;


        denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2);
        numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2 + 1);

        for (int i = 0; i < control::CARTESIAN_SPACE; i++)
        {
            denominatorFactor.row(i) << -(0.995318097603672 + 1),0.995318097603672;
            numeratorFactor.row(i)   << 3.526824280564631e-08, 3.521311586867696e-08, 0.0;
        }

        pTransferFunctionCoefficientRobot_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientRobot_->denominatorFactor = denominatorFactor;
    }

    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientPI_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientFeedback_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientRobot_;
    std::shared_ptr<control::TransferFunction>             pRobotTransferFunction_;
    std::shared_ptr<control::TransferFunction>             pPITransferFunction_;
    std::shared_ptr<control::TransferFunction>             pFeedbackTransferFunction_;

    std::vector<Eigen::VectorXd> outPose_;
    std::string                  fileName_;
    double timeStamp_;

};


TEST_F(PPISimulation_Unit_Test, PPISimulatioTest)
{
    control::ControllerCMD controllerCMD;

    TfCoefficient();
    double P = 0.790365564859249;

    fileName_         = "PPISimulation.csv";
    Eigen::VectorXd finalPose   = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    finalPose << 10.0, 23.0, 100.0, 2000.0, 2.0, 2.0;

    Eigen::VectorXd actualPose  = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd actualTwist = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd wrench      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd errorP      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd errorV      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    for (unsigned int i = 0; i < 5000; i++)
    {
        errorP      = (finalPose - actualPose) * P;
        errorV      = errorP - actualTwist;
        wrench      = pPITransferFunction_->Update(errorV);
        actualTwist = pFeedbackTransferFunction_->Update(wrench);
        actualPose  = pRobotTransferFunction_->Update(wrench);
        outPose_.push_back(actualPose);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


