#include "drone.hpp"

// string messages lookup table
// stored in program memory

static const char g_BlankMessage[] PROGMEM = "An Error Occured!";
static const char g_AssertionFailedMessage[] PROGMEM = "Assertion Failed!";
static const char g_InvalidMPUSetupMessage[] PROGMEM = "Invalid MPU Setup!";
static const char g_OutOfBoundsMessage[] PROGMEM = "Out of Bounds!";
static const char g_NoReceiverData[] PROGMEM = "No Data Read by Receiver!";
static const char g_InvalidMotorIndex[] PROGMEM = "Invalid Motor Index!";

static const char* const g_Messages[] PROGMEM =
{
	g_BlankMessage,
	g_AssertionFailedMessage,
	g_InvalidMPUSetupMessage,
	g_OutOfBoundsMessage,
	g_NoReceiverData,
	g_InvalidMotorIndex,
};

static void reportError(size_t code)
{
	assert(code < static_cast<size_t>(ErrorCode::End), ErrorCode::OutOfBounds);

	// write the error message to the serial port
	Serial.println(g_Messages[code]);
}

void ThrowError(size_t code)
{
	StopDrone();

	// write to the led pin
	digitalWrite(ErrorLEDPin, HIGH);

	// must enter an infinite cycle,
	// to block further code execution

	while (true)
	{
		// report the error to serial
		reportError(code);

		// wait a the specified number of seconds
		// to not be too annoying
		delay(ErrorRepeatDelay);
	}
}
