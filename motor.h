#pragma once

#include "platform.h"

#include <Servo.h>

void setupMotor(Servo& esc, const int servoPin);
void writeToMotor(const int motorPin, const float value);

