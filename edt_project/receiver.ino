#include "drone.hpp"

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

bool IsReceiverReceiving()
{
	AxisData tempData;
	ReadReceiver(tempData);

	return (tempData.x != 0) || (tempData.y != 0) || (tempData.z != 0);
}
