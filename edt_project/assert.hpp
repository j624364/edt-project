#pragma once

#include "config.hpp"
#include "error.hpp"

void assert(bool condition, size_t errorCode = ErrorCode::AssertionFailed);
void check(bool condition, size_t errorCode = ErrorCode::AssertionFailed);
