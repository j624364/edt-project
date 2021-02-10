#pragma once

#include "platform.hpp"

struct axis_data
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

void SetupMPU();
void ReadIMUValues(axis_data& gyroData);

