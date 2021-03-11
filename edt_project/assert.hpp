#pragma once

#include "config.hpp"
#include "error.hpp"

// only check condition in debug mode
void assert(bool condition, size_t errorCode = ErrorCode::AssertionFailed);

// always check the condition
void check(bool condition, size_t errorCode = ErrorCode::AssertionFailed);
