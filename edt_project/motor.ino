#include "motor.hpp"
#include "assert.hpp"
#include "config.hpp"

const int g_ServoPins[4] PROGMEM = { MotorOnePin, MotorTwoPin, MotorThreePin, MotorFourPin };
Servo g_Servos[4];

int GetMotorPin(size_t motorIndex)
{
	assert(motorIndex <= 4, ErrorCode::OutOfBounds);
	return g_ServoPins[motorIndex];
}

Servo& GetMotor(size_t motorIndex)
{
	assert(motorIndex <= 4, ErrorCode::OutOfBounds);
	return g_Servos[motorIndex];
}

void setupMotor(size_t motorIndex)
{
	assert(motorIndex <= 4, ErrorCode::OutOfBounds);

	int pinNumber = GetMotorPin(motorIndex);
	Servo& esc = GetESC(motorIndex);
	
	esc.attach(pinNumber);
}

void writeToMotor(Servo& esc, const float value)
{
	int mappedValue = (value * (MAXMOTORVALUE - MINMOTORVALUE)) + MINMOTORVALUE;
	esc.writeMicroseconds(mappedValue);
}

