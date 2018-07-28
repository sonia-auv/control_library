/**
 * \file	ControllerPPI.h
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

#ifndef CONTROL_LIBRARY_CONTROLLERPPI_H
#define CONTROL_LIBRARY_CONTROLLERPPI_H

#include "control_library/toolbox/TransferFunction.h"
#include "ControllerIF.h"


namespace control
{
    class ControllerPPI : public ControllerIF
    {
    public:
        ControllerPPI(std::shared_ptr<TransferFunctionCoefficient> &transferFunctionCoefficient, int filterOrder,const double gainP);
        virtual ~ControllerPPI() = default;

        Eigen::VectorXd Update(ControllerCMD &controllerCMD) override;
        void Exit() override;

    private:
        Eigen::VectorXd  positionCommand_;
        Eigen::VectorXd  computedWrench_;
        TransferFunction transferFunction_;
        double gainP_;

    };
}

#endif //CONTROL_LIBRARY_CONTROLLERPPI_H
