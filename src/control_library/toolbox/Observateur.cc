#include "Observateur.h"

namespace control
{
    Observateur::Observateur(Eigen::MatrixXd _Ad, Eigen::MatrixXd _Hd,Eigen::MatrixXd _Bd,Eigen::MatrixXd _Cd)
    {
        Ad = _Ad;
        Hd = _Hd;
        Bd = _Bd;
        Cd = _Cd;
    }

    Eigen::MatrixXd Observateur::Update(Eigen::MatrixXd x, Eigen::MatrixXd u, Eigen::MatrixXd y)
    {
        return (Ad - Hd * Cd) * x + Bd * u + Hd * y;
    }

}