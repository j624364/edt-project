#pragma once

struct axis_data
{
	float x = -1.0f;
	float y = -1.0f;
	float z = -1.0f;
};

// subtracts src from dest
axis_data SubtractAxisData(const axis_data& dat1, const axis_data& dat2);
