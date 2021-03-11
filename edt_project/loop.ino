#include "drone.hpp"

static float xPrevErr = 0.0f;
static float yPrevErr = 0.0f;
static float zPrevErr = 0.0f;

static float xIntegral = 0.0f;
static float yIntegral = 0.0f;
static float zIntegral = 0.0f;

float pidLoop(const float err, const float dt, float& integral, float previousErr)
{
	// usual pid loop calculation
	integral = integral + (err * dt);
	float derivative = (err - previousErr) / dt;
	return (KP * err) + (KI * integral) + (KD * derivative);
}

void UpdateEachAxis(const AxisData& target, const AxisData& current, AxisData& pidData)
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
	n1Thrust -= thrust;
	n2Thrust -= thrust;
}

void UpdateMotors(const AxisData& pidData)
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
	WriteToMotor(1, xThrust);
	WriteToMotor(2, yThrust);
	WriteToMotor(3, zThrust);
	WriteToMotor(4, wThrust);
}
