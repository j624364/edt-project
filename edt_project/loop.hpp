#pragma once

#include "platform.hpp"
#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral, float& previousErr);
void UpdateEachAccess(const axis_data& gyroData);
void UpdateMotors();

