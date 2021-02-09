#pragma once

#include "platform.hpp"
#include "config.hpp"

float pidLoop(const float err, const float dt, float& integral);
void updateEachAccess();

