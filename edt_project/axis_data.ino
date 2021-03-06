#include "drone.hpp"

AxisData SubtractAxisData(const AxisData& dat1, const AxisData& dat2)
{
    AxisData outputData;
    outputData.x = dat1.x - dat2.x;
    outputData.y = dat1.y - dat2.y;
    outputData.z = dat1.z - dat2.z;

    return outputData;
}

bool IsAxisDataNull(const AxisData& data)
{
    return (data.x != 0) && (data.y != 0) && (data.z != 0);
}
