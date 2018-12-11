//
// Created by olavoie on 12/11/18.
//

#ifndef CONTROL_LIBRARY_CONTINUOUSTIMEPID_H
#define CONTROL_LIBRARY_CONTINUOUSTIMEPID_H

#include <memory>
#include <chrono>
#include "control_library/ControlType.h"

namespace control
{
    class ContinuousTimePid
    {
    public:
        ContinuousTimePid(std::shared_ptr<PIDParameters> & pidParameters);
        ~ContinuousTimePid()= default;

        double Update(double const & error);

    private:
        std::chrono::steady_clock::time_point lastTime_;
        std::shared_ptr<PIDParameters>        pidParameters_;

        double lastError_;
        double integrationSum_;




    };
}

#endif //CONTROL_LIBRARY_CONTINUOUSTIMEPID_H
