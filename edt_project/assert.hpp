#pragma once

#include "config.hpp"
#include "error.hpp"

void assert(bool condition, ErrorCode errorCode = ErrorCode::AssertionFailed);

