#include "loop.hpp"
#include "gyroscope.hpp"

float xErr = 0.0f;
float yErr = 0.0f;
float zErr = 0.0f;

float xPrevErr = 0.0f;
float yPrevErr = 0.0f;
float zPrevErr = 0.0f;

float xIntegral = 0.0f;
float yIntegral = 0.0f;
float zIntegral = 0.0f;

float pidLoop(const float err, const float dt, float& integral, float& previousErr)
{
	integral = integral + (err * dt);
	float derivative = (err - previousErr) / dt;
	return (KP * err) + (KI * integral) + (KD * derivative);
}

void updateEachAxis(const gyroscope_data& gyroData)
{
	static float lastTime = millis();
	float currentTime = millis();
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;

	pidLoop(xErr, deltaTime, xIntegral, xPrevErr);
	pidLoop(yErr, deltaTime, yIntegral, yPrevErr);
	pidLoop(zErr, deltaTime, zIntegral, zPrevErr);

	xPrevErr = xErr;
	yPrevErr = yErr;
	zPrevErr = zErr;
}

void updateMotors()
{
	float pitch = 0.0f;	// pitch is how far forward or backwards it is
	float yaw = 0.0f;	// yaw is how far to the side it is
	float roll = 0.0f;	// roll is sideways

}

