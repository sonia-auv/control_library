/**
 * \file	TransferFunction.cc
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

#include "TransferFunction.h"


namespace control
{
    TransferFunction::TransferFunction(int nbTransferFunction, std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder) :
        filterOrder_(filterOrder),
        nbTransferFunction_(nbTransferFunction),
        transferFunctionCoefficient_(transferFunctionCoefficient)
    {
        SetZero();
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
        Eigen::ArrayXXd outputHistory = Eigen::ArrayXXd::Zero(nbTransferFunction_, filterOrder_);
        Eigen::ArrayXXd errorHistory  = Eigen::ArrayXXd::Zero(nbTransferFunction_, filterOrder_ + 1);
        outputHistory.matrix().block(0,1,nbTransferFunction_, filterOrder_ - 1) = outputHistory_.matrix().block(0,0,nbTransferFunction_, filterOrder_ - 1);
        errorHistory.matrix().block(0,1,nbTransferFunction_, filterOrder_) = errorHistory_.matrix().block(0,0,nbTransferFunction_, filterOrder_);
        outputHistory_ = outputHistory;
        errorHistory_ = errorHistory;

    }

    Eigen::VectorXd TransferFunction::FilterXOrder()
    {
        Eigen::VectorXd numeratorResult = (transferFunctionCoefficient_->numeratorFactor * errorHistory_).rowwise().sum();
        Eigen::VectorXd denominatorResult = (transferFunctionCoefficient_->denominatorFactor * outputHistory_).rowwise().sum();
        return numeratorResult - denominatorResult;
    }
    
    void TransferFunction::SetZero() 
    {
        filterResult_      = Eigen::VectorXd::Zero(nbTransferFunction_);
        outputHistory_     = Eigen::ArrayXXd::Zero(nbTransferFunction_, filterOrder_);
        errorHistory_      = Eigen::ArrayXXd::Zero(nbTransferFunction_, filterOrder_ + 1);
    }

}