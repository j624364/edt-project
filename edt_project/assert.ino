#include "assert.hpp"
#include "error.hpp"

void assert(bool condition, size_t errorCode)
{
#if defined(DEBUG)
	if (!condition)
	{
		throwError(errorCode);
	}
#else
	// should do nothing when not in debug mode
#endif
}

