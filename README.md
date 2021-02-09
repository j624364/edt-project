# edt-project
Source code for the EDT Project Drone.



The source files are in edt_project/
To open the project in the Arduino Editor, just open one of the .ino files

Yes, the project structure is bad but so is the Arduino IDE so ¯\\_(ツ)_/¯.



##### To do:

| Task                                       | Status   |
| ------------------------------------------ | -------- |
| Create utilities                           | WIP      |
| Get gyro data                              | Done     |
| Convert gyro data to output to esc         | WIP      |
| Create fail safes                          | Not done |
| Get receiver data                          | Not done |
| Update gyro data to include receiver input | Not done |



##### Libraries used:

- Adafruit_MPU6050
- Adafruit_BusIO
- Wire
- SPI
- Adafruit_Unified_Sensor
- Servo