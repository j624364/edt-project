#pragma once

#include "platform.hpp"

#include <Servo.h>

int GetMotorPin(size_t motorIndex);
Servo& GetMotor(size_t motorIndex);
void SetupMotor(size_t motorIndex);
void WriteToMotor(Servo& esc, const float value);
