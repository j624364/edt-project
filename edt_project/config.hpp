#pragma once

/*
	Here are the values configurations,
	that should be corrected after testing.
*/

// define if assertions should be used
// (slow down drone program, but add error checking)
#define DEBUG

// main PID values
static constexpr float KP { 1.0 };
static constexpr float KI { 1.0 };
static constexpr float KD { 1.0 };

// max and min values of the escs
// NOTE: you may need to set the minimum
// 	 higher than the default value to
// 	 still get some thrust
static constexpr int MAXMOTORVALUE { 2000 };
static constexpr int MINMOTORVALUE { 2000 };

// amount of times between each time an error should be
// reported
static constexpr int ERROR_REPEAT_DELAY { 1000 };

// amount of milliseconds taken for the drone to wait
// before attempting to fly
static constexpr int DRONE_STARTUP_DELAY { 1000 };

static constexpr float TIME_MULTIPLIER { 0.004f };

// the pins the motors are connected to
static constexpr int MotorOnePin { 11 };
static constexpr int MotorTwoPin { 10 };
static constexpr int MotorThreePin { 9 };
static constexpr int MotorFourPin { 6 };

