#pragma once

/*
	Here are the values configurations,
	that should be corrected after testing.
*/

// define if assertions should be used
// (slow down drone program, but add error checking)
#define DEBUG

// main PID values
static constexpr float KP { 1.0f };
static constexpr float KI { 1.0f };
static constexpr float KD { 1.0f };

// max and min values of the escs
// NOTE: you may need to set the minimum
// 	 higher than the default value to
// 	 still get some thrust
static constexpr int MaxMotorValue { 2000 };
static constexpr int MinMotorValue { 1000 };

static constexpr int DroppingMechanismOpenValue { 2000 };
static constexpr int DroppingMechanismCloseValue { 0000 };

static constexpr float MaxAnalogValue { 1024.0 };

// amount of times between each time an error should be reported
// (in milliseconds)
static constexpr int ErrorRepeatDelay { 1000 };

// amount of milliseconds taken for the drone to wait
// before attempting to fly
static constexpr int DroneStartupDelay { 1000 };

// the pins the motors are connected to
static constexpr int MotorOnePin { 11 };
static constexpr int MotorTwoPin { 10 };
static constexpr int MotorThreePin { 9 };
static constexpr int MotorFourPin { 6 };

static constexpr int DroppingMechanismPin { 5 };

static constexpr int ShutdownPin { 8 };

static constexpr int ReceiverPitchPin { A0 };
static constexpr int ReceiverYawPin { A1 };
static constexpr int ReceiverRollPin { A2 };

