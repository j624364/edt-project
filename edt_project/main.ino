#include "utils.hpp"
#include "motor.hpp"
#include "gyroscope.hpp"
#include "loop.hpp"
#include "error.hpp"

Servo esc;

void DroneInit()
{
	// setup systems

	SetupMPU();

	for (size_t i = 0; i < 4; i++)
		SetupMotor(i);

	// provide some delay before starting the main loop

	delay(DRONE_STARTUP_DELAY - millis());
}

void DroneLoop()
{
	// read data
	gyroscope_data gyroData;
	ReadIMUValues(gyroData);

	// update logic
	UpdateEachAxis(gyroData);

	// update the signal given to the motors
	UpdateMotors();
}

