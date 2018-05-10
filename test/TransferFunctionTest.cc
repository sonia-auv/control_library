/**
 * \file	TransferFunctionTest.cc
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

#include "toolbox/TransferFunction.h"
#include "ControlType.h"

class TransferFunction_Unit_Test : public testing::Test
{
public:
    TransferFunction_Unit_Test()  {}
    virtual ~TransferFunction_Unit_Test() {}

    void SetUp()
    {
        nbDegreeOfFreedom_ = 7;
        pTransferFunctionCoefficient_ = std::make_shared<control::TransferFunctionCoefficient>();
    }

    void TearDown()
    {
        std::ofstream myfile;
        myfile.open(fileName_);

        for (Eigen::VectorXd &result : historyResult_)
        {
            myfile << result[0] << ";" << result[1] << ";" << result[2] << ";" << result[3] << ";" << result[4] << ";" << result[5] << std::endl;
        }
        myfile.close();
    }

    void init(int order, std::shared_ptr<control::TransferFunctionCoefficient> &ftParameters)
    {
        pTransferFunction_  = std::make_shared<control::TransferFunction>(nbDegreeOfFreedom_, ftParameters, order);
    }

    std::shared_ptr<control::TransferFunction>  pTransferFunction_;
    std::shared_ptr<control::TransferFunctionCoefficient>  pTransferFunctionCoefficient_;
    std::vector<Eigen::VectorXd> historyResult_;
    Eigen::ArrayXXd              denominatorFactor_;
    Eigen::ArrayXXd              numeratorFactor_;
    std::string                  fileName_;
    int nbDegreeOfFreedom_;
};


TEST_F(TransferFunction_Unit_Test, TransferFunction2Order)
{
    /*          200
       ft = -------------
            s^2 + 3s + 4
    */
    const float tolerance = 1E-2f;

    int filterOrder = 2;
    int nbIteration = 600;
    fileName_ = "TransferFunction2Order.csv";

    denominatorFactor_ = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder);
    numeratorFactor_   = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder + 1);

    for (int i = 0; i < nbDegreeOfFreedom_; i++)
    {
        denominatorFactor_.row(i) << -1.970052211604768, 0.970446261452074;
        numeratorFactor_.row(i)   << 0.004925623091321, 0.009851246182642, 0.004925623091321;
    }

    pTransferFunctionCoefficient_->numeratorFactor  = numeratorFactor_;
    pTransferFunctionCoefficient_->denominatorFactor = denominatorFactor_;

    init(filterOrder, pTransferFunctionCoefficient_);
    Eigen::VectorXd result = Eigen::VectorXd::Zero(nbDegreeOfFreedom_);
    std::vector<Eigen::VectorXd> historyResult;
    Eigen::VectorXd command;
    //step command
    command.setConstant(nbDegreeOfFreedom_, 1.0f);
    Eigen::VectorXd expectedInfinity = Eigen::VectorXd::Zero(nbDegreeOfFreedom_);
    // with the final value theorem we get : 200 / 4 --> 50.0
    expectedInfinity.setConstant(nbDegreeOfFreedom_, 50.0);

    for (int i = 0; i <= nbIteration; i++)
    {
        result = pTransferFunction_->Update(command);
        historyResult_.push_back(result);
    }

    for (int atcIdx = 0; atcIdx < nbDegreeOfFreedom_; atcIdx++)
    {
        EXPECT_NEAR(expectedInfinity(atcIdx), historyResult_[nbIteration](atcIdx), tolerance);
    }

}

TEST_F(TransferFunction_Unit_Test, TransferFunction3Order)
{
    /*                200
       ft = ------------------------
            s^3 + 18s^2 + 107s + 210
    */
    const float tolerance = 1E-6f;
    int filterOrder = 3;
    int nbIteration = 170;
    fileName_ = "TransferFunction3Order.csv";

    denominatorFactor_ = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder);
    numeratorFactor_   = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder + 1);

    for (int i = 0; i < nbDegreeOfFreedom_; i++)
    {
        denominatorFactor_.row(i) << -1.651927599598069,  0.906597088644294, -0.165298888221586;
        numeratorFactor_.row(i)   << 0.0, 0.021413192813791, 0.054999185079390, 0.008702480035046;
    }

    pTransferFunctionCoefficient_->numeratorFactor  = numeratorFactor_;
    pTransferFunctionCoefficient_->denominatorFactor = denominatorFactor_;

    init(filterOrder, pTransferFunctionCoefficient_);
    Eigen::VectorXd result = Eigen::VectorXd::Zero(nbDegreeOfFreedom_);
    Eigen::VectorXd command;
    //step command
    command.setConstant(nbDegreeOfFreedom_, 1.0f);
    Eigen::VectorXd expectedInfinity = Eigen::VectorXd::Zero(nbDegreeOfFreedom_);
    // with the final value theorem we get : 20 / 21 --> 0.952381
    expectedInfinity.setConstant(nbDegreeOfFreedom_, 0.952381);

    for (int i = 0; i <= nbIteration; i++)
    {
        result = pTransferFunction_->Update(command);
        historyResult_.push_back(result);
    }

    for (int atcIdx = 0; atcIdx < nbDegreeOfFreedom_; atcIdx++)
    {
        EXPECT_NEAR(expectedInfinity(atcIdx), historyResult_[nbIteration](atcIdx), tolerance);
    }

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}