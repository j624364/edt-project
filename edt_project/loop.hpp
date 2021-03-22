#pragma once

#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral, float previousErr);
void UpdateEachAccess(const AxisData& target, const AxisData& current, AxisData& output, float deltaTime);
void UpdateMotors(const AxisData& pidData, float deltaTime);
