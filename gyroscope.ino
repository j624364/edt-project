#include "gyroscope.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

bool setupMPU()
{
	if (!mpu.begin())
		return false;

	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	return true;
}

gyro_data_t readIMUValues()
{
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	return { g.gyro.x, g.gyro.y, g.gyro.z };
}

