#pragma once

#include "platform.hpp"

#include <Servo.h>

int GetMotorPin(size_t motorIndex);
Servo& GetMotor(size_t motorIndex);
void setupMotor(size_t motorIndex);
void writeToMotor(Servo& esc, const float value);

