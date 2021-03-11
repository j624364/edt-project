#pragma once

// contains all of the function definitions

// vscode does not recognise size_t so
// im defining it here
#if defined(VSCODE)
using size_t = unsigned int;
#endif

#include "axis_data.hpp"
#include "main.hpp"
#include "motor.hpp"
#include "gyroscope.hpp"
#include "loop.hpp"
#include "assert.hpp"
#include "error.hpp"
#include "receiver.hpp"
