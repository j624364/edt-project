#pragma once

#include "platform.hpp"
#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral, float& previousErr);
void updateEachAccess(const gyroscope_data& gyroData);
void updateMotors();

