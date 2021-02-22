#include "drone.hpp"

// variables for this compilation unit

const int g_ServoPins[4] PROGMEM = { MotorOnePin, MotorTwoPin, MotorThreePin, MotorFourPin };
Servo g_Servos[4];

// normal function definitions

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

void SetupMotor(size_t motorIndex)
{
	assert(motorIndex <= 4, ErrorCode::OutOfBounds);

	// get the motor pin
	int pinNumber = GetMotorPin(motorIndex);

	// get the motor object
	Servo& esc = GetMotor(motorIndex);
	
	// set up the motor with the given pin
	esc.attach(pinNumber);
}

void WriteToMotor(Servo& esc, const float value)
{
	// map the value from 0.0-1.0 to MinMotorValue-MaxMotorValue
	int mappedValue = (value * (MaxMotorValue - MinMotorValue)) + MinMotorValue;

	// write the value to the motor
	esc.writeMicroseconds(mappedValue);
}
