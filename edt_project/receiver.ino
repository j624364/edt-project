#include "drone.hpp"

static bool g_HasReceivedData = false;

float readAxis(int pinNumber)
{
	int intData = analogRead(pinNumber);
	float floatData = static_cast<float>(intData);
	return floatData / MaxAnalogValue;
}

void ReadReceiver(AxisData& remoteControllerData)
{
	remoteControllerData.z = readAxis(ReceiverPitchPin);
	remoteControllerData.x = readAxis(ReceiverYawPin);
	remoteControllerData.y = readAxis(ReceiverRollPin);
}

bool CheckReceiver()
{
	if (g_HasReceivedData)
		return g_HasReceivedData;

	// read the current data
	AxisData tempData;
	ReadReceiver(tempData);

	if (!IsAxisDataNull(tempData))
		g_HasReceivedData = true;

	return g_HasReceivedData;
}
