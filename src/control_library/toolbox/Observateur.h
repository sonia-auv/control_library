#ifndef CONTROL_LIBRARY_TRANSFERFUNCTION_H
#define CONTROL_LIBRARY_TRANSFERFUNCTION_H

#include <eigen3/Eigen/Eigen>
#include <vector>
#include <memory>
#include <fstream>
#include "control_library/ControlType.h"

namespace control
{
    class Observateur
    {

    public:
        Observateur(Eigen::MatrixXd Ad, Eigen::MatrixXd Hd,Eigen::MatrixXd Bd,Eigen::MatrixXd Cd);
        ~Observateur() = default;

        Eigen::MatrixXd Update(Eigen::MatrixXd x, Eigen::MatrixXd u, Eigen::MatrixXd y);
                    

    private:

        Eigen::MatrixXd Ad;
        Eigen::MatrixXd Hd;
        Eigen::MatrixXd Bd;
        Eigen::MatrixXd Cd;
        

    };



}



#endif //CONTROL_LIBRARY_TRANSFERFUNCTION_H
