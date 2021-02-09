#include "gyroscope.hpp"
#include "assert.hpp"

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setupMPU()
{
	bool mpuState = !mpu.begin();
	assert(mpuState, ErrorCode::InvalidMPUSetup);

	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void readIMUValues(gyroscope_data& gyroData)
{
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	gyroData.x = g.gyro.x;
	gyroData.y = g.gyro.y;
	gyroData.z = g.gyro.z;
}

