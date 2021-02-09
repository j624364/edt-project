#include "error.hpp"
#include "config.hpp"
#include "array.hpp"

// string messages lookup table

const char* g_Messages[] =
{
	"", // none
	"AssertionFailed",
	"Invalid MPU Setup",
};

inline void reportError(size_t code)
{
	assert(code < ErrorCode::End);
	Serial.println(g_Messages[code]);
}

void throwError(size_t code)
{
	
	// check if not null assertion
	if (code == ErrorCode::None)
		return;

	// must enter an infinite cycle,
	// to block further code execution

	while (true)
	{
		reportError(code);
		delay(ERROR_REPEAT_DELAY);
	}
}

