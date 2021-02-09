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

void updateEachAxis()
{
	static float lastTime = millis();
	float currentTime = millis();
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;

	pidLoop(xErr, deltaTime, xIntegral, xPrevErr);
	pidLoop(yErr, deltaTime, yIntegral, yPrevErr);
	pidLoop(zErr, deltaTime, zIntegral, zPrevErr);
}

void updateMotors(gyroscope_data& gyroData)
{
	updateEachAxis();
}

