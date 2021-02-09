#include "utils.hpp"
#include "motor.hpp"
#include "gyroscope.hpp"
#include "loop.hpp"
#include "error.hpp"

Servo esc;

constexpr int SERVOPIN { 11 };

void droneInit()
{
	// setup systems

	setupMPU();
	setupMotor(esc, SERVOPIN);

	// provide some delay before starting the main loop

	delay(DRONE_STARTUP_DELAY - millis());
}

void droneLoop()
{
	// read data
	gyroscope_data gyroData;
	readIMUValues(gyroData);

	// update logic
	updateEachAxis(gyroData);

	// update the signal given to the motors
	updateMotors();
}

