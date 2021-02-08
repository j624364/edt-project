#pragma once

#include "config.h"
#include "error.h"

#if defined(DEBUG)
// if debug mode, then check the condition
#define ASSERT(condition) if (!(condition)) throwError(errorCode::AssertionFailed);
#else
// if in release/distribution, then ignore
#define ASSERT(condition)
#endif

