#include "drone.hpp"

float readAxis(int pinNumber)
{
	int data = analogRead(pinNumber);
	float floatData = static_cast<float>(data);
	return floatData / MaxAnalogValue;
}

void ReadReceiver(axis_data& remoteControllerData)
{
	remoteControllerData.z = readAxis(ReceiverPitchPin);
	remoteControllerData.x = readAxis(ReceiverYawPin);
	remoteControllerData.y = readAxis(ReceiverRollPin);
}
