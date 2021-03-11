#include "gyroscope.hpp"
#include "assert.hpp"

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

static Adafruit_MPU6050 s_MPU;

void SetupMPU()
{
	// start the mpu and get its state
	bool mpuState = s_MPU.begin();
	// always check as it is important to run
	check(mpuState, ErrorCode::InvalidMPUSetup);

	// setup the properties of the mpu
	// use the most precise values
	s_MPU.setAccelerometerRange(MPU6050_RANGE_8_G);
	s_MPU.setGyroRange(MPU6050_RANGE_1000_DEG);
	s_MPU.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void ReadIMUValues(AxisData& gyroData)
{
	// get the current data
	sensors_event_t a, g, temp;
	s_MPU.getEvent(&a, &g, &temp);

	// push that data into the gyroData reference variable
	gyroData.x = g.gyro.x;
	gyroData.y = g.gyro.y;
	gyroData.z = g.gyro.z;
}
