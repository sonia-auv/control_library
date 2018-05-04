//
// Created by olavoie on 5/2/18.
//

#include "DynamicModel.h"


namespace control
{
    DynamicModel::DynamicModel(std::shared_ptr<DynamicModelParam> &auvDynamicParameters): auvDynamicParameters_(auvDynamicParameters) {}

    Eigen::VectorXd DynamicModel::Update(Eigen::VectorXd &acceleration, Eigen::VectorXd &velocity, Eigen::Vector3d &orientation)
    {
        Eigen::VectorXd wrench;

        wrench = auvDynamicParameters_->auvAddedMass * acceleration + ComputeDamping(velocity) * velocity + ComputeGravity(orientation);

        return wrench;
    }

    Eigen::VectorXd DynamicModel::ComputeDamping(Eigen::VectorXd &velocity)
    {
        return auvDynamicParameters_->auvDamping.constDragCoefficient +  auvDynamicParameters_->auvDamping.quadDragCoefficient * (velocity * velocity);
    }

    Eigen::VectorXd DynamicModel::ComputeGravity(Eigen::Vector3d &orientation)
    {
        Eigen::VectorXd gravityVector = Eigen::VectorXd::Zero(CARTESIAN_SPACE);

        gravityVector[0] = auvDynamicParameters_->resultingForce  * sin(orientation[1]);
        gravityVector[1] = -auvDynamicParameters_->resultingForce * sin(orientation[0]) * cos(orientation[1]);
        gravityVector[2] = -auvDynamicParameters_->resultingForce * cos(orientation[0]) * cos(orientation[1]);

        gravityVector[3] = auvDynamicParameters_->buoyancyForce  * cos(orientation[1]) * (auvDynamicParameters_->auvBuoyancyCenter[3] * sin(orientation[0]) - auvDynamicParameters_->auvBuoyancyCenter[1] * cos(orientation[0]));
        gravityVector[4] = auvDynamicParameters_->buoyancyForce  * (auvDynamicParameters_->auvBuoyancyCenter[0] * cos(orientation[0]) * cos(orientation[1]) - auvDynamicParameters_->auvBuoyancyCenter[2] * sin(orientation[1]));
        gravityVector[5] = -auvDynamicParameters_->buoyancyForce * (auvDynamicParameters_->auvBuoyancyCenter[0] * sin(orientation[0]) * cos(orientation[1]) - auvDynamicParameters_->auvBuoyancyCenter[1] * sin(orientation[1]));
        return gravityVector;
    }

}