#include "error.hpp"
#include "config.hpp"
#include "array.hpp"

const char* g_Messages[] =
{
	// none
	"",
	"AssertionFailed",
	"Invalid MPU Setup",
};

void throwError(size_t code)
{
	if (code == ErrorCode::None)
		return;

	// must enter an infinite cycle,
	// to block further code execution

	while (true)
	{
		delay(ERROR_REPEAT_DELAY);
	}
}

