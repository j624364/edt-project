# edt-project
The source files are in edt_project/

##### To do:

| Task                                          | Status |
| --------------------------------------------- | ------ |
| Get gyro data                                 | Done   |
| Convert gyro data to output to esc            | Done   |
| Get receiver data                             | Done   |
| Update gyro data to include receiver input    | Done   |
| Control the servos for the dropping mechanism | Done   |

##### Opening the project:

- Open one of the .ino files.
- Download the libraries.
- Upload to the Arduino.

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
