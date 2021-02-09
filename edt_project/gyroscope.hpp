#pragma once

#include "platform.hpp"

struct gyroscope_data
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

void setupMPU();
void readIMUValues(gyroscope_data& gyroData);

