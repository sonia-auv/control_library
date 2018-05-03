//
// Created by olavoie on 5/2/18.
//

#ifndef CONTROL_LIBRARY_DYNAMICMODEL_H
#define CONTROL_LIBRARY_DYNAMICMODEL_H

#include <memory>
#include <eigen3/Eigen/Eigen>

#include "ControlType.h"

namespace control
{
    class DynamicModel {
    private:
        DynamicModel(std::shared_ptr<DynamicModelParam> &auvDynamicParameters);
        ~DynamicModel() = default;

        Eigen::VectorXd Update(Eigen::VectorXd &acceleration, Eigen::VectorXd &velocity, Eigen::Vector3d &orientation);

    private:
        Eigen::VectorXd ComputeDamping(Eigen::VectorXd &velocity);
        Eigen::VectorXd ComputeGravity(Eigen::Vector3d &orientation);

        std::shared_ptr<DynamicModelParam> auvDynamicParameters_;

    };
}



#endif //CONTROL_LIBRARY_DYNAMICMODEL_H
