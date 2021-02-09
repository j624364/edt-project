#pragma once

/*
	Here are the values configurations,
	that should be corrected after testing.
*/

// define if assertions should be used
// (slow down drone program, but add error checking)
#define DEBUG

// main PID values
#define KP 1
#define KI 1
#define KD 1

// max and min values of the escs
// NOTE: you may need to set the minimum
// 	 higher than the default value to
// 	 still get some thrust
#define MAXMOTORVALUE 2000
#define MINMOTORVALUE 1000

// amount of times between each time an error should be
// reported
#define ERROR_REPEAT_DELAY 1000

// amount of milliseconds taken for the drone to wait
// before attempting to fly
#define DRONE_STARTUP_DELAY 10000

static constexpr float TIME_MULTIPLIER { 0.004f };

