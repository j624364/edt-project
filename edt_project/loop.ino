#include "loop.hpp"
#include "gyroscope.hpp"

float pidLoop(const float err, const float dt, float& integral)
{
	static float previousErr = 0.0;
	integral = integral + (err * dt);
	float derivative = (err - previousErr) / dt;
	return (KP * err) + (KI * integral) + (KD * derivative);
}

void updateEachAxis()
{
	static float xErr = 0.0f;
	static float yErr = 0.0f;
	static float zErr = 0.0f;

	static float xIntegral = 0.0f;
	static float yIntegral = 0.0f;
	static float zIntegral = 0.0f;

	static float lastTime = millis();
	float currentTime = millis();
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;
}

