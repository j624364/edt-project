#include "drone.hpp"

static float s_xPrevErr = 0.0f;
static float s_yPrevErr = 0.0f;
static float s_zPrevErr = 0.0f;

static float s_xIntegral = 0.0f;
static float s_yIntegral = 0.0f;
static float s_zIntegral = 0.0f;

static float pidLoop(const float err, const float dt, float& integral, float previousErr)
{
	// usual pid loop calculation
	integral = integral + (err * dt);
	float derivative = (err - previousErr) / dt;
	return (KP * err) + (KI * integral) + (KD * derivative);
}

void UpdateEachAxis(const AxisData& target, const AxisData& current, AxisData& pidData, float deltaTime)
{
	float xErr = target.x - current.x;
	float yErr = target.y - current.y;
	float zErr = target.z - current.z;

	// calculate the pid loop for each axis
	pidData.x = pidLoop(xErr, deltaTime, s_xIntegral, s_xPrevErr);
	pidData.y = pidLoop(yErr, deltaTime, s_yIntegral, s_yPrevErr);
	pidData.z = pidLoop(zErr, deltaTime, s_zIntegral, s_zPrevErr);

	// move all current values to be the last values
	s_xPrevErr = xErr;
	s_yPrevErr = yErr;
	s_zPrevErr = zErr;
}

static void updateAxis(float thrust,
	float& p1Thrust, float& p2Thrust, float& n1Thrust, float& n2Thrust)
{
	p1Thrust += thrust;
	p2Thrust += thrust;
	n1Thrust -= thrust;
	n2Thrust -= thrust;
}

void UpdateMotors(const AxisData& pidData, float currentThrustMultiplier, float deltaTime)
{
	// find the thrust values using trigonometry
	float pitchThrust = tan(pidData.y) * ThrustMultiplier;
	float rollThrust = tan(pidData.y) * ThrustMultiplier;
	float yawThrust = tan(pidData.z) * TurnMultiplier;

	// these are the values of thrust each motor receives
	float wThrust = 0.0f;
	float xThrust = 0.0f;
	float yThrust = 0.0f;
	float zThrust = 0.0f;

	// update the individual motors, with the previously calculated thrusts
	updateAxis(pitchThrust, xThrust, yThrust, zThrust, wThrust);
	updateAxis(rollThrust, xThrust, zThrust, yThrust, wThrust);
	updateAxis(yawThrust, zThrust, wThrust, yThrust, zThrust);

	// mutlipy by thrust multiplier to gain / loose altitude
	xThrust *= currentThrustMultiplier * AltitudeMultiplier;
	yThrust *= currentThrustMultiplier * AltitudeMultiplier;
	zThrust *= currentThrustMultiplier * AltitudeMultiplier;
	wThrust *= currentThrustMultiplier * AltitudeMultiplier;

	// write to each motor value
	WriteToMotor(1, xThrust);
	WriteToMotor(2, yThrust);
	WriteToMotor(3, zThrust);
	WriteToMotor(4, wThrust);
}
