//
// Created by olavoie on 5/12/18.
//

#ifndef CONTROL_LIBRARY_CONTROLINTERFACE_H
#define CONTROL_LIBRARY_CONTROLINTERFACE_H

#include <memory>

#include "control_library/ControlType.h"
#include "control_library/toolbox/TrajectoryGenerator.h"

namespace control
{
    class Trajectory
    {
    public:
        Trajectory();
        ~Trajectory() = default;

        void GenerateTrajectory(TrajectoryGeneratorType &trajectoryGeneratorType);
        TrajectoryResult GetTrajectory();
        bool IsTrajectoryComputed() {return isTrajectoryComputed_;}
        void ResetTrajectory();

    private:
        std::shared_ptr<TrajectoryGenerator> pTrajectoryGenerator_;
        TrajectoryResultList                 trajectoryResultList_;

        TrajectoryResult trajectoryResult_;

        bool isTrajectoryComputed_;
        unsigned int i_;
    };

}

#endif //CONTROL_LIBRARY_CONTROLINTERFACE_H
