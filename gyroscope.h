#pragma once

#include "platform.h"

struct gyroscope_data
{
	float x;
	float y;
	float z;
};

typedef gyroscope_data gyro_data_t;

bool setupMPU();
gyro_data_t readIMUValues();

