// arduino flight controller
// main functions

/*
	style notes:

	constexpr is not supported
*/

#include "utils.h"
#include "motor.h"
#include "gyroscope.h"
#include "loop.h"
#include "error.h"

Servo esc;

#define SERVOPIN 11

void setup()
{
	pinMode(3, OUTPUT);
	pinMode(8, OUTPUT);
	digitalWrite(8, HIGH);

	if (!setupMPU())
	{
		throwError(ErrorCode::InvalidMPUSetup);
	}

	setupMotor(esc, SERVOPIN);
	delay(1000);
}

#define TIME_MULTIPLIER 0.004f

void loop()
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

	// delay(0);
}

