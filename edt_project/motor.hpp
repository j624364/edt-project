#pragma once

#include <Servo.h>

int GetMotorPin(size_t motorIndex);
Servo& GetMotor(size_t motorIndex);
void SetupMotor(size_t motorIndex);
void WriteToMotor(size_t motorIndex, const float value);
