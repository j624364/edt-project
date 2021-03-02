#include "drone.hpp"

axis_data SubtractAxisData(const axis_data& dat1, const axis_data& dat2)
{
    axis_data outputData;
    outputData.x = dat1.x - dat2.x;
    outputData.y = dat1.y - dat2.y;
    outputData.z = dat1.z - dat2.z;

    return outputData;
}
