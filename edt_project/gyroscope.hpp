#pragma once

#include "platform.hpp"
#include "axis_data.hpp"

void SetupMPU();
void ReadIMUValues(axis_data& gyroData);
