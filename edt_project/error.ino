#include "drone.hpp"

// string messages lookup table

// todo: move to progmem
// when i figure out the syntax
const char* g_Messages[] =
{
	"", // none
	"AssertionFailed",
	"Invalid MPU Setup",
	"OutOfBounds"
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

