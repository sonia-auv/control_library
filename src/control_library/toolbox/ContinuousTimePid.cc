/**
 * \file	ContinuousTimePID.cc
 * \author	Jeremie St-Jules <jeremie.st.jules.prevost@gmail.com>
 * \coauthor Francis Masse <francis.masse05@gmail.com>
 * \date	10/17/16
 *
 * \copyright Copyright (c) 2017 S.O.N.I.A. AUV All rights reserved.
 *
 * \section LICENSE
 *
 * This file is part of S.O.N.I.A. software.
 *
 * S.O.N.I.A. AUV software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S.O.N.I.A. AUV software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S.O.N.I.A. AUV software. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ContinuousTimePid.h"

namespace control
{
    ContinuousTimePid::ContinuousTimePid(std::shared_ptr<control::PIDParameters> & pidParameters):
        lastTime_{ std::chrono::steady_clock::now() },
        pidParameters_{pidParameters},
        lastError_{ 0 },
        integrationSum_{ 0 }
    {

    }

    double ContinuousTimePid::Update(double const &error)
    {
        std::chrono::steady_clock::time_point now_time = std::chrono::steady_clock::now();
        auto diff = now_time - lastTime_;

        double deltaTime_s = double(std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count())/(double(1E9));

        double proportional, derivative, integrale;

        double actuation = 0; // Actuation (output of PID block)
        // Prevent dividing by 0
        // 0.0001 s == 1000 HZ so we good :)
        if(deltaTime_s > (0.0001f) )
        {
            // Compute and add the proportional gain term
            proportional = (pidParameters_->Kp * error);
            actuation = proportional;

            // Compute and add the derivative gain term
            derivative = pidParameters_->Kd * ((error - lastError_) / (deltaTime_s));
            actuation += derivative;
            // Integrate cumulative error
            integrationSum_ += (error * deltaTime_s);
            // Reset I if position crosses target (if error is 0 or changes sign)
            if ((copysign(1.0f, error) != copysign(1.0f, lastError_)) || (error == 0.0)) {
                integrationSum_ = 0;
            } else {
                // Clip I to prevent Integral WindUp
                integrationSum_ = std::min(std::max(integrationSum_, -(pidParameters_->iLimit)), pidParameters_->iLimit);
                integrale = (pidParameters_->Ki * integrationSum_);
                actuation += integrale;
            }
        }

        lastTime_ = now_time;
        lastError_ = error;

        return actuation;
    }


}