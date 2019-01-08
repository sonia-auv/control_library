#ifndef CONTROL_LIBRARY_TRANSFERFUNCTION_H
#define CONTROL_LIBRARY_TRANSFERFUNCTION_H

#include <eigen3/Eigen/Eigen>
#include <vector>
#include <memory>
#include <fstream>

namespace control
{
    class Observateur
    {

    public:
        Observateur(Eigen::MatrixXd Ad, Eigen::MatrixXd Bd, Eigen::MatrixXd Cd, Eigen::MatrixXd Hd);
        ~Observateur() = default;

        Eigen::MatrixXd Update(Eigen::MatrixXd x, Eigen::MatrixXd u, Eigen::MatrixXd y);
                    

    private:

        Eigen::MatrixXd Ad_;
        Eigen::MatrixXd Bd_;
        Eigen::MatrixXd Cd_;
        Eigen::MatrixXd Hd_;
        

    };



}



#endif //CONTROL_LIBRARY_TRANSFERFUNCTION_H
