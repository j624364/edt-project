#pragma once

#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral, float previousErr);
void UpdateEachAccess(const axis_data& target, const axis_data& current, axis_data& output);
void UpdateMotors(const axis_data& pidData);
