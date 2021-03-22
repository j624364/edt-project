#include "drone.hpp"

static bool s_DroneRunning = true;

void DroneInit()
{
	// setup systems
	SetupMPU();

	// setup each four motors
	for (size_t i = 0; i < 4; i++)
		SetupMotor(i);

	// provide some delay before starting the main loop
	delay(DroneStartupDelay - millis());

	// attach an interupt to the shutdown pin
	// when the pin is triggered, run the StopDrone function
	attachInterrupt(digitalPinToInterrupt(ShutdownPin), &StopDrone, RISING);
}

void DroneLoop()
{
	if (!s_DroneRunning)
		return;

	// get time since last calculation
	static float lastTime = millis();
	float currentTime = millis();
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;

	// reserve room for data
	AxisData gyroData;
	AxisData receiverData;
	AxisData pidData;
	float auxData;

	// read the data
	ReadIMUValues(gyroData);
	ReadReceiver(receiverData);
	ReadAux(auxData);

	// if the drone is past the startup limit,
	// then check if the drone has received input
	// if it has not, then throw an error
	if (millis() > DroneCheckDelay)
	{
		check(CheckReceiver(), ErrorCode::NoReceiverData);
	}

	// update logic
	UpdateEachAxis(receiverData, gyroData, pidData, deltaTime);

	// update the signal given to the motors
	UpdateMotors(pidData, auxData, deltaTime);
}

// handle the drone exiting
// should only be called once
// managed by StopDrone()
static void droneExit()
{
	MotorsExit();
}

// can be called multiple times
void StopDrone()
{
	if (!s_DroneRunning)
		return;

	droneExit();
	s_DroneRunning = false;
}
