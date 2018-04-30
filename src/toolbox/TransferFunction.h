//
// Created by olavoie on 4/28/18.
//

#ifndef CONTROL_LIBRARY_TRANSFERFUNCTION_H
#define CONTROL_LIBRARY_TRANSFERFUNCTION_H

#include <eigen3/Eigen/Eigen>
#include <vector>

namespace control
{
    class TransferFunction
    {

    public:
        TransferFunction(int nbTransferFunction, std::vector<Eigen::ArrayXXd> &transferFunctionCoefficient, int filterOrder);
        ~TransferFunction() = default;

        Eigen::VectorXd Update(Eigen::VectorXd &error);

    private:
        Eigen::VectorXd FilterXOrder();
        void UpdateHistory();

        int             filterOrder_;
        int             nbTransferFunction_;
        Eigen::VectorXd filterResult_;
        Eigen::VectorXd lastError_;
        Eigen::ArrayXXd denominatorFactor_;
        Eigen::ArrayXXd outputHistory_;
        Eigen::ArrayXXd numeratorFactor_;
        Eigen::ArrayXXd errorHistory_;

    };

}



#endif //CONTROL_LIBRARY_TRANSFERFUNCTION_H
