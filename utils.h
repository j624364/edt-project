#pragma once

#include "platform.h"

inline double square(double x)
{
	return x * x;
}

inline int ledAnalogMap(double value)
{
	return value * 255;
}

