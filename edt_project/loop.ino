#include "drone.hpp"

float xPrevErr = 0.0f;
float yPrevErr = 0.0f;
float zPrevErr = 0.0f;

float xIntegral = 0.0f;
float yIntegral = 0.0f;
float zIntegral = 0.0f;

float pidLoop(const float err, const float dt, float& integral, float previousErr)
{
	// usual pid loop calculation
	integral = integral + (err * dt);
	float derivative = (err - previousErr) / dt;
	return (KP * err) + (KI * integral) + (KD * derivative);
}

void UpdateEachAxis(const axis_data& target, const axis_data& current, axis_data& pidData)
{
	// get time since last calculation
	static float lastTime = millis();
	float currentTime = millis();
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;

	float xErr = target.x - current.x;
	float yErr = target.y - current.y;
	float zErr = target.z - current.z;

	// calculate the pid loop for each axis
	pidData.x = pidLoop(xErr, deltaTime, xIntegral, xPrevErr);
	pidData.y = pidLoop(yErr, deltaTime, yIntegral, yPrevErr);
	pidData.z = pidLoop(zErr, deltaTime, zIntegral, zPrevErr);

	// move all current values to be the last values
	xPrevErr = xErr;
	yPrevErr = yErr;
	zPrevErr = zErr;
}

static void updateAxis(float thrust,
	float& p1Thrust, float& p2Thrust, float& n1Thrust, float& n2Thrust)
{
	p1Thrust += thrust;
	p2Thrust += thrust;
	n1Thrust += thrust;
	n2Thrust += thrust;
}

void UpdateMotors(const axis_data& pidData)
{
	// find the thrust values using trigonometry
	float pitchThrust = tan(pidData.y) * ThrustMultiplier;
	float rollThrust = tan(pidData.y) * ThrustMultiplier;
	float yawThrust = tan(pidData.z);

	// these are the values of thrust each motor receives
	float wThrust = 0.0f;
	float xThrust = 0.0f;
	float yThrust = 0.0f;
	float zThrust = 0.0f;

	// update the individual motors, with the previously calculated thrusts
	updateAxis(pitchThrust, xThrust, yThrust, zThrust, wThrust);
	updateAxis(rollThrust, xThrust, zThrust, yThrust, wThrust);
	updateAxis(yawThrust, zThrust, wThrust, yThrust, zThrust);

	// write to each motor value
	WriteToMotor(GetMotor(1), xThrust);
	WriteToMotor(GetMotor(2), yThrust);
	WriteToMotor(GetMotor(3), zThrust);
	WriteToMotor(GetMotor(4), wThrust);
}
