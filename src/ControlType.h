//
// Created by olavoie on 5/1/18.
//

#ifndef CONTROL_LIBRARY_CONTROLTYPE_H
#define CONTROL_LIBRARY_CONTROLTYPE_H

#include <eigen3/Eigen/Eigen>

const int CARTESIAN_SPACE   = 6;
const int POSITION_SPACE    = 3;
const int ORIENTATION_SPACE = 3;

struct DynamicModelParam
{
    Eigen::MatrixXd auvDamping;
    Eigen::MatrixXd auvAddedMass;
    Eigen::Vector3d auvBuoyancyCenter;
    double          resultingForce;
    double          buoyancyForce;
};

#endif //CONTROL_LIBRARY_CONTROLTYPE_H
