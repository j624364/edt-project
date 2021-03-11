#pragma once

struct AxisData
{
	float x = -1.0f;
	float y = -1.0f;
	float z = -1.0f;
};

// subtracts src from dest
AxisData SubtractAxisData(const AxisData& dat1, const AxisData& dat2);
bool IsAxisDataNull(const AxisData& data);
