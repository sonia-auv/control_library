//#include <gtest/gtest.h>
//#include "toolbox/TransferFunction.h"
//#include <eigen3/Eigen/Eigen>
//#include <memory>
//
//class TransferFunction_Unit_Test : public testing::Test
//{
//public:
//    TransferFunction_Unit_Test()  {}
//    virtual ~TransferFunction_Unit_Test() {}
//
//    void SetUp()
//    {
//        nbDegreeOfFreedom_ = 6;
//    }
//
//    void TearDown() {}
//
//    void init(int order, std::vector<Eigen::ArrayXXd> &ftParameters)
//    {
//        pTransferFunction_  = std::make_shared<TransferFunction>(nbDegreeOfFreedom_, ftParameters, order);
//    }
//
//    std::shared_ptr<TransferFunction>  pTransferFunction_;
//    Eigen::ArrayXXd denominatorFactor_;
//    Eigen::ArrayXXd numeratorFactor_;
//    int nbDegreeOfFreedom_;
//};
//
//
//TEST_F(TransferFunction_Unit_Test, TransferFunction2Order)
//{
//    /*          200
//       ft = -------------
//            s^2 + 3s + 4
//    */
//    const float tolerance = 1E-2f;
//
//    int filterOrder = 2;
//    int nbIteration = 600;
//
//    std::vector<Eigen::ArrayXXd> ftParameters;
//
//    denominatorFactor_ = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder);
//    numeratorFactor_   = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder + 1);
//
//    for (int i = 0; i < nbDegreeOfFreedom_; i++)
//    {
//        denominatorFactor_.row(i) << -1.970052211604768,  0.970446261452074;
//        numeratorFactor_.row(i)   << 0.004925623091321, 0.009851246182642, 0.004925623091321;
//    }
//
//    ftParameters.push_back(numeratorFactor_);
//    ftParameters.push_back(denominatorFactor_);
//
//    init(filterOrder, ftParameters);
//    Eigen::VectorXf result = Eigen::VectorXf::Zero(nbDegreeOfFreedom_);
//    std::vector<Eigen::VectorXf> historyResult;
//    Eigen::VectorXf command;
//    //step command
//    command.setConstant(nbDegreeOfFreedom_, 1.0f);
//    Eigen::VectorXf expectedInfinity = Eigen::VectorXf::Zero(nbDegreeOfFreedom_);
//    // with the final value theorem we get : 200 / 4 --> 0.952381
//    expectedInfinity.setConstant(nbDegreeOfFreedom_, 50.0);
//
//    for (int i = 0; i <= nbIteration; i++)
//    {
//        result = pTransferFunction_->Process(command);
//        historyResult.push_back(result);
//    }
//
//    for (int atcIdx = 0; atcIdx < nbDegreeOfFreedom_; atcIdx++){
//        EXPECT_NEAR(expectedInfinity(atcIdx), historyResult[nbIteration](atcIdx), tolerance);
//    }
//
//}
//
//TEST_F(TransferFunction_Unit_Test, TransferFunction3Order)
//{
//    /*                200
//       ft = ------------------------
//            s^3 + 18s^2 + 107s + 210
//    */
//    const float tolerance = 1E-6f;
//    int filterOrder = 3;
//    int nbIteration = 170;
//
//    std::vector<Eigen::ArrayXXd> ftParameters;
//
//    denominatorFactor_ = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder);
//    numeratorFactor_   = Eigen::ArrayXXd::Zero(nbDegreeOfFreedom_, filterOrder + 1);
//
//    for (int i = 0; i < nbDegreeOfFreedom_; i++)
//    {
//        denominatorFactor_.row(i) << -1.651927599598069,  0.906597088644294, -0.165298888221586;
//        numeratorFactor_.row(i)   << 0.0, 0.021413192813791, 0.054999185079390, 0.008702480035046;
//    }
//
//    ftParameters.push_back(numeratorFactor_);
//    ftParameters.push_back(denominatorFactor_);
//
//    init(filterOrder, ftParameters);
//    Eigen::VectorXf result = Eigen::VectorXf::Zero(nbDegreeOfFreedom_);
//    std::vector<Eigen::VectorXf> historyResult;
//    Eigen::VectorXf command;
//    //step command
//    command.setConstant(nbDegreeOfFreedom_, 1.0f);
//    Eigen::VectorXf expectedInfinity = Eigen::VectorXf::Zero(nbDegreeOfFreedom_);
//    // with the final value theorem we get : 20 / 21 --> 0.952381
//    expectedInfinity.setConstant(nbDegreeOfFreedom_, 0.952381);
//
//    for (int i = 0; i <= nbIteration; i++)
//    {
//        result = pTransferFunction_->Process(command);
//        historyResult.push_back(result);
//    }
//
//    for (int atcIdx = 0; atcIdx < nbDegreeOfFreedom_; atcIdx++)
//    {
//        EXPECT_NEAR(expectedInfinity(atcIdx), historyResult[nbIteration](atcIdx), tolerance);
//    }
//
//}