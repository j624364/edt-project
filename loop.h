#pragma once

#include "platform.h"
#include "config.h"

#if !defined(KP)
#error "KP not defined!"
#endif

#if !defined(KI)
#error "KI not defined!"
#endif

#if !defined(KD)
#error "KD not defined!"
#endif

float pidLoop(const float err, const float dt, float& integral);
void updateEachAccess();

