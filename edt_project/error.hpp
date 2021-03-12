#pragma once

// Contains the error code to be thrown,
// so that the error message does not have
// to be repeated

// enum class not supported
enum ErrorCode
{
	None,
	AssertionFailed,
	InvalidMPUSetup,
	OutOfBounds,
	NoReceiverData,
	InvalidMotorIndex,

	End
};

void ThrowError(size_t code);
