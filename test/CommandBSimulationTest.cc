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


class BSimulation_Unit_Test : public testing::Test
{
public:
    BSimulation_Unit_Test()  {}
    virtual ~BSimulation_Unit_Test() {}

    void SetUp()
    {
        timeStamp_ = 0.02;

        pTransferFunctionCoefficientB_      = std::make_shared<control::TransferFunctionCoefficient>();
        pTransferFunctionCoefficientRobot_  = std::make_shared<control::TransferFunctionCoefficient>();

        pRobotTransferFunction_    = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientRobot_, 2);
        pBTransferFunction_ = std::make_shared<control::TransferFunction>(control::CARTESIAN_SPACE, pTransferFunctionCoefficientB_, 4);

    }

    void TearDown()
    {
        std::ofstream myfile;
        myfile.open(fileName_);

        for (Eigen::VectorXd &pose : outPose_)
        {
            myfile << pose[0] << ";" << pose[1] << ";" << pose[2] << ";" << pose[3] << ";" << pose[4] << ";" << pose[5] << std::endl;
            //myfile << pose << std::endl << std::endl;
        }
        myfile.close();
    }

    void TfCoefficient()
    {
        Eigen::ArrayXXd denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 4);
        Eigen::ArrayXXd numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 4 + 1);

        denominatorFactor.row(0) << -3.639591435619611, 4.951840184694524, -2.984799708005306, 0.672550978879680;
        numeratorFactor.row(0)   <<  3.663521493460744, 0.062852137377651, -7.264065541170898, -0.062601520631772, 3.600794664456033;

        denominatorFactor.row(1) << -3.721140132164017,   5.182918636148546,  -3.202408853963115,   0.740630350805249;
        numeratorFactor.row(1)   <<  2.874571854497089, 0.016292762391361, -5.732850946601702, -0.016292762389132, 2.858279092106842;

        denominatorFactor.row(2) << -3.484172225823234,   4.540683509002915,  -2.623846480821100,   0.567336194791450;
        numeratorFactor.row(2)   <<  4.099794429988902,   0.465668934749429,  -7.721362226736669,  -0.440553537766016,   3.646683193731180;

        denominatorFactor.row(3) << 0.0, 0.0, 0.0, 0.0;
        numeratorFactor.row(3)   << 0.0, 0.0, 0.0, 0.0, 0.0;

        denominatorFactor.row(4) << 0.0, 0.0, 0.0, 0.0;
        numeratorFactor.row(4)   << 0.0, 0.0, 0.0, 0.0, 0.0;

        denominatorFactor.row(5) << -3.438254439400247,   4.364849833917319,  -2.413705446788345,   0.487110296428659;
        numeratorFactor.row(5)   <<  0.006654007474324,   0.000513789197763,  -0.012775927167275,  -0.000477192030541,   0.006158516860172;

        pTransferFunctionCoefficientB_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientB_->denominatorFactor = denominatorFactor;

        denominatorFactor = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2);
        numeratorFactor   = Eigen::ArrayXXd::Zero(control::CARTESIAN_SPACE, 2 + 1);

        denominatorFactor.row(0) << -1.982843791829845, 0.982877996180266;
        numeratorFactor.row(0)   <<  4.352249784952539e-05, 1.362027148092105e-07, -4.338629513471618e-05;

        denominatorFactor.row(1) << -1.994332108148254,   0.994332108148642;
        numeratorFactor.row(1)   <<  2.867158136575574e-05, 6.114622243587014e-09, -2.866546674351215e-05;

        denominatorFactor.row(2) << -1.886416516071346,   0.889479522938191;
        numeratorFactor.row(2)   <<  -2.386838283658904e-05, 5.937596521342501e-06, 2.980597935793154e-05;

        denominatorFactor.row(3) << 0.0, 0.0;
        numeratorFactor.row(3)   << 0.0, 0.0, 0.0;

        denominatorFactor.row(4) << 0.0, 0.0;
        numeratorFactor.row(4)   << 0.0, 0.0, 0.0;

        denominatorFactor.row(5) << -1.922784998401985, 0.925535007878473;
        numeratorFactor.row(5)   << -3.263375365325829e-04,   2.761169604506229e-04,  6.024544969832058e-04;

        pTransferFunctionCoefficientRobot_->numeratorFactor   = numeratorFactor;
        pTransferFunctionCoefficientRobot_->denominatorFactor = denominatorFactor;
    }

    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientB_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficientRobot_;
    std::shared_ptr<control::TransferFunction>             pRobotTransferFunction_;
    std::shared_ptr<control::TransferFunction>             pBTransferFunction_;

    std::vector<Eigen::VectorXd> outPose_;
    std::string                  fileName_;
    double timeStamp_;

};


TEST_F(BSimulation_Unit_Test, BSimulatioTest)
{
    control::ControllerCMD controllerCMD;

    TfCoefficient();

    fileName_         = "BSimulation.csv";
    Eigen::VectorXd finalTwist   = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    Eigen::ArrayXXd saturation(control::CARTESIAN_SPACE, 2);
    saturation.col(0) << 110.0, 110.0, 110.0, 110.0, 110.0, 110.0;
    saturation.col(1) << 0.0, 0.0, 0.0, 0.0, 0.0, 0.0;

    finalTwist << 0.5, 0.5, 0.35, 0.0, 0.0, 0.5;

    Eigen::VectorXd actualTwist = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd wrench      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);
    Eigen::VectorXd errorV      = Eigen::VectorXd::Zero(control::CARTESIAN_SPACE);

    for (unsigned int i = 0; i < 500; i++)
    {
        errorV      = finalTwist - actualTwist;
        wrench      = pBTransferFunction_->Update(errorV);
        saturation.col(1) = wrench;
        wrench = saturation.matrix().rowwise().minCoeff();
        actualTwist = pRobotTransferFunction_->Update(wrench);
        outPose_.push_back(actualTwist);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


