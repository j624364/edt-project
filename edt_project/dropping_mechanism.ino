#include "drone.hpp"

Servo g_DroppingMechanismServo;

void SetupDroppingMechanism()
{
	g_DroppingMechanismServo.attach(DroppingMechanismPin);
}

void OpenDroppingMechanism()
{
	g_DroppingMechanismServo.writeMicroseconds(DroppingMechanismOpenValue);
}

void CloseDroppingMechanism()
{
	g_DroppingMechanismServo.writeMicroseconds(DroppingMechanismCloseValue);
}
