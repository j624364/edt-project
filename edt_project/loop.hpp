#pragma once

#include "platform.hpp"
#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral, float& previousErr);
void updateEachAccess();
void updateMotors(gyroscope_data& gyroData);

