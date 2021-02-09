#include "assert.hpp"
#include "error.hpp"

void assert(bool condition, size_t errorCode)
{

#if defined(DEBUG)

	// if in debug mode, then check for the error

	if (!condition)
	{
		ThrowError(errorCode);
	}

#else

	// should do nothing when not in debug mode
	// and should get entirely optimised away by
	// the -Os

#endif

}

