#include "motor.hpp"
#include "config.hpp"

void setupMotor(Servo& esc, const int servoPin)
{
	esc.attach(servoPin);
}

void writeToMotor(const int motorPin, const float value)
{
	int mappedValue = (value * (MAXMOTORVALUE - MINMOTORVALUE)) + MINMOTORVALUE;
	esc.writeMicroseconds(mappedValue);
}

