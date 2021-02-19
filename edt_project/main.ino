#include "drone.hpp"

bool g_DroneRunning = true;

void DroneInit()
{
	// setup systems
	SetupMPU();
	SetupDroppingMechanism();

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
	if (!g_DroneRunning)
		return;

	// reserve room for data
	axis_data gyroData;
	axis_data receiverData;

	// read the data
	ReadIMUValues(gyroData);
	ReadReceiver(receiverData);

	// update logic
	UpdateEachAxis(gyroData);

	// update the signal given to the motors
	UpdateMotors();
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

