# edt-project
The source files are in edt_project/

##### To do:

| Task                                       | Status   |
| ------------------------------------------ | -------- |
| Create utilities                           | WIP      |
| Get gyro data                              | Done     |
| Convert gyro data to output to esc         | WIP      |
| Create fail safes                          | Not done |
| Get receiver data                          | Not done |
| Update gyro data to include receiver input | Not done |

##### Opening the project:

- Open one of the .ino files
- Download the libraries
- Upload to the Arduino

##### Libraries used:

- Adafruit_MPU6050
- Adafruit_BusIO
- Wire
- SPI
- Adafruit_Unified_Sensor
- Servo

##### Style Note:

- Yes, I know the structure is bad, but the Arduino IDE struggles with complex projects.
- I have tried to use as modern C++ as possible, but that is difficult when there is no standard library.