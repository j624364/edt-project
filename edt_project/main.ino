#include "drone.hpp"

static bool s_DroneRunning = true;

void DroneInit()
{
	// setup systems
	SetupMPU();
	SetupReceiver();

	// setup each four motors
	for (size_t i = 0; i < 4; i++)
		SetupMotor(i);

	// turn off led pin if on
	pinMode(ErrorLEDPin, OUTPUT);
	digitalWrite(ErrorLEDPin, LOW);

	// attach an interupt to the shutdown pin
	// when the pin is triggered, run the StopDrone function
	attachInterrupt(digitalPinToInterrupt(ShutdownPin), &StopDrone, RISING);

	// provide some delay before starting the main loop
	delay(DroneStartupDelay - millis());
}

void DroneLoop()
{
	if (!s_DroneRunning)
		return;

	// get time since last calculation
	static float lastTime = millis() / 1000.0f;
	float currentTime = millis() / 1000.0f;
	float deltaTime = lastTime - currentTime;
	lastTime = currentTime;

	// reserve room for data
	AxisData gyroData;
	AxisData receiverData;
	AxisData pidData;
	float elevatorData;

	// read the data
	ReadIMUValues(gyroData);
	ReadReceiver(receiverData);
	ReadElevator(elevatorData);

	// if the drone is not part the startup time,
	// then check for data
	// after the startup time, check if any data has
	// been received in that time and if not throw an error
	if (currentTime <= DroneCheckDelay)
		CheckReceiver();
	else if (currentTime > DroneCheckDelay)
		check(CheckReceiver(), ErrorCode::NoReceiverData);

	// update logic
	UpdateEachAxis(receiverData, gyroData, pidData, deltaTime);

	// update the signal given to the motors
	UpdateMotors(pidData, elevatorData, deltaTime);
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
