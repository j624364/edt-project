#include "gyroscope.hpp"
#include "assert.hpp"

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void SetupMPU()
{
	// start the mou and get its state
	bool mpuState = mpu.begin();
	assert(mpuState, ErrorCode::InvalidMPUSetup);

	// setup the properties of the mpu
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void ReadIMUValues(gyroscope_data& gyroData)
{
	// get the current data
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	// push that data into the gyroData reference variable
	gyroData.x = g.gyro.x;
	gyroData.y = g.gyro.y;
	gyroData.z = g.gyro.z;
}

