ESP32-WROVER Quadcopter with Onboard Camera
-------------------------------------------

App controlled quadcopter with onboard camera implemented using the Freenove ESP32-WROVER CAM Board.
Included:
Android Controller Code folder containing the quadcopter remote Android app C# code, written in MS Visual Studio.
ESP32-WROVER MCU Code folder containing the MCU control embedded C code, written in Arduino IDE.

The user connects their Android device to the quadcopter's Wi-Fi access point, in order to control the quadcopter using the Android app.

Completed
---------
- Assembled quadcopter frame and installed x4 A2212 KV2200 brushless motors
- Setup ESP32-WROVER in Wi-Fi AP mode and configured a dedicated server using Arduino IDE
- Developed an Android app interface in Microsoft Visual Studio
- Established communication between ESP32-WROVER and Android app using HTTP (dummy HTTP.GET requests & responses)
- Defined x4 PWM outputs to control the motors through the L293D motor drivers
- Installed x2 CCW and x2 CW props on the quadcopter
- Set all quadcopter motors to produce maximum lift (max 8-bit PWM value: 255) when "Up" is pressed, and minimum lift (min 8-bit PWM value: 0) when "Down" is pressed, in order to test lift-off capability.
- Added "Stop" button to Android app to implement an abrupt emergency shutdown of the quadcopter
- Added functionality to enforce hover state on release of Android app buttons

To-Do
-----
- Tune DAC outputs against quadcopter weight to **add vertical flight and hover functionality**
- Interface IMU (gyroscope rotational data & barometer altitude information) with ESP32-WROVER
- Use IMU gyroscope rotational data to implement **PID control loops** and additional flight functionality (Yaw L, Yaw R, Pitch L, Pitch R, Roll F, Roll B)
- Allow capture of a still image using the ESP32-WROVER camera when the "Capture" button is pressed on the Android app

  
