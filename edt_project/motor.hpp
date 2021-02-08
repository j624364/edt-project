#pragma once

#include "platform.hpp"

#include <Servo.h>

void setupMotor(Servo& esc, const int servoPin);
void writeToMotor(const int motorPin, const float value);

