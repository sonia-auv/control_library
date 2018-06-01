/**
 * \file	TransferFunctionTest.h
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

#ifndef CONTROL_LIBRARY_TRANSFERFUNCTION_H
#define CONTROL_LIBRARY_TRANSFERFUNCTION_H

#include <eigen3/Eigen/Eigen>
#include <vector>
#include <memory>

#include "control_library/ControlType.h"

namespace control
{
    class TransferFunction
    {

    public:
        TransferFunction(int nbTransferFunction, std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder);
        ~TransferFunction() = default;

        Eigen::VectorXd Update(Eigen::VectorXd &error);
        
        void SetZero();

    private:
        Eigen::VectorXd FilterXOrder();
        void UpdateHistory();

        int             filterOrder_;
        int             nbTransferFunction_;
        Eigen::VectorXd filterResult_;
        Eigen::ArrayXXd outputHistory_;
        Eigen::ArrayXXd errorHistory_;

        std::shared_ptr<TransferFunctionCoefficient> transferFunctionCoefficient_;

    };

}



#endif //CONTROL_LIBRARY_TRANSFERFUNCTION_H
