#include "Observateur.h"

namespace control
{
    Observateur::Observateur(Eigen::MatrixXd Ad, Eigen::MatrixXd Bd, Eigen::MatrixXd Cd, Eigen::MatrixXd Hd)
    {
        Ad_ = Ad;
        Bd_ = Bd;
        Cd_ = Cd;
        Hd_ = Hd;

    }

    Eigen::MatrixXd Observateur::Update(Eigen::MatrixXd x, Eigen::MatrixXd u, Eigen::MatrixXd y)
    {
        return (Ad_ - Hd_ * Cd_) * x + Bd_ * u + Hd_ * y;
    }

}