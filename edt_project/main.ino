#include "utils.hpp"
#include "motor.hpp"
#include "gyroscope.hpp"
#include "loop.hpp"
#include "error.hpp"

Servo esc;

#define SERVOPIN 11

void droneInit()
{
	// write test signal to check program is working

	pinMode(3, OUTPUT);
	pinMode(8, OUTPUT);
	digitalWrite(8, HIGH);

	// setup systems

	setupMPU();
	setupMotor(esc, SERVOPIN);

	// provide some delay before starting the main loop

	delay(DRONE_STARTUP_DELAY - millis());
}

void droneLoop()
{
	unsigned long milliseconds = millis();

	if (digitalRead(2) == HIGH)
	{
		analogWrite(3, 0);
		analogWrite(5, 0);
	}
	else
	{
		double blue = square(sin(milliseconds * TIME_MULTIPLIER));
		double red  = square(cos(milliseconds * TIME_MULTIPLIER));
		analogWrite(3, ledAnalogMap(blue));
		analogWrite(5, ledAnalogMap(red));
	}
}

