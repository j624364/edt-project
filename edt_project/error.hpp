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

	End
};

void throwError(size_t code);

