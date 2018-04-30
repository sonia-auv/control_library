//
// Created by olavoie on 4/28/18.
//

#include "TransferFunction.h"

namespace control
{
    TransferFunction::TransferFunction(int nbTransferFunction, std::vector<Eigen::ArrayXXd> &transferFunctionCoefficient, int filterOrder) :
        filterOrder_(filterOrder),
        nbTransferFunction_(nbTransferFunction)
    {
        filterResult_      = Eigen::VectorXd::Zero(nbTransferFunction);
        lastError_         = Eigen::VectorXd::Zero(nbTransferFunction);
        denominatorFactor_ = Eigen::ArrayXXd::Zero(nbTransferFunction, filterOrder_);
        outputHistory_     = Eigen::ArrayXXd::Zero(nbTransferFunction, filterOrder_);
        numeratorFactor_   = Eigen::ArrayXXd::Zero(nbTransferFunction, filterOrder_ + 1);
        errorHistory_      = Eigen::ArrayXXd::Zero(nbTransferFunction, filterOrder_ + 1);

        numeratorFactor_   = transferFunctionCoefficient[0];
        denominatorFactor_ = transferFunctionCoefficient[1];
    }

    Eigen::VectorXd TransferFunction::Update(Eigen::VectorXd &error)
    {
        errorHistory_.col(0) = error;
        filterResult_ = FilterXOrder();
        UpdateHistory();
        outputHistory_.col(0) = filterResult_;
        return filterResult_;
    }

    void TransferFunction::UpdateHistory()
    {
        outputHistory_.matrix().block(0,1,nbTransferFunction_, filterOrder_ - 1) = outputHistory_.matrix().block(0,0,nbTransferFunction_, filterOrder_ - 1);
        errorHistory_.matrix().block(0,1,nbTransferFunction_, filterOrder_) = errorHistory_.matrix().block(0,0,nbTransferFunction_, filterOrder_);
    }

    Eigen::VectorXd TransferFunction::FilterXOrder()
    {
        Eigen::VectorXd numeratorResult = (numeratorFactor_ * errorHistory_).rowwise().sum();
        Eigen::VectorXd denominatorResult = (denominatorFactor_ * outputHistory_).rowwise().sum();
        return numeratorResult - denominatorResult;
    }

}