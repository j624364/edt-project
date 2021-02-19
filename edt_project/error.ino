#include "drone.hpp"

// string messages lookup table
// stored in program memory

const char g_BlankMessage[] PROGMEM = "";
const char g_AssertionFailedMessage[] PROGMEM = "";
const char g_InvalidMPUSetupMessage[] PROGMEM = "";
const char g_OutOfBoundsMessage[] PROGMEM = "";

const char* const g_Messages[] PROGMEM =
{
	g_BlankMessage,
	g_AssertionFailedMessage,
	g_InvalidMPUSetupMessage,
	g_OutOfBoundsMessage
};

static void reportError(size_t code)
{
	assert(code < ErrorCode::End, ErrorCode::OutOfBounds);

	// write the error message to the serial port
	Serial.println(g_Messages[code]);
}

void ThrowError(size_t code)
{
	
	// check if not null assertion
	if (code == ErrorCode::None)
		return;

	droneExit();

	// must enter an infinite cycle,
	// to block further code execution

	while (true)
	{
		reportError(code);
		delay(ErrorRepeatDelay);
	}
}

