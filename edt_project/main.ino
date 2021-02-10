#include "drone.hpp"

bool g_DroneRunning = true;

void DroneInit()
{
	// setup systems

	SetupMPU();
	SetupDroppingMechanism();

	for (size_t i = 0; i < 4; i++)
		SetupMotor(i);

	// provide some delay before starting the main loop

	delay(DroneStartupDelay - millis());
}

void DroneLoop()
{
	if (!g_DroneRunning)
		return;

	// read data
	axis_data gyroData;
	axis_data receiverData;

	ReadIMUValues(gyroData);
	ReadReceiver(receiverData);

	// update logic
	UpdateEachAxis(gyroData);

	// update the signal given to the motors
	UpdateMotors();

	attachInterrupt(digitalPinToInterrupt(ShutdownPin), &StopDrone, RISING);
}

void StopDrone()
{
	g_DroneRunning = false;
	droneExit();
}

void droneExit()
{
	// add closing logic here
}

