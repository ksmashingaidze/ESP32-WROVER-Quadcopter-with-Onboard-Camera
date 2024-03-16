ESP32-WROVER Quadcopter with Onboard Camera
-------------------------------------------

App controlled quadcopter with onboard camera implemented using the Freenove ESP32-WROVER CAM Board.
Included:
Android Controller Code folder containing the quadcopter remote Android app C# code, written in MS Visual Studio.
ESP32-WROVER MCU Code folder containing the MCU control embedded C code, written in Arduino IDE.

The user connects their Android device to the quadcopter's Wi-Fi access point, in order to control the quadcopter using the Android app.

Completed
---------
- Assembled quadcopter frame and installed x4 Fafeicy 8520 coreless brushed Motors
- Setup ESP32-WROVER in Wi-Fi AP mode and configured a dedicated server using Arduino IDE
- Developed an Android app interface in Microsoft Visual Studio
- Established communication between ESP32-WROVER and Android app using HTTP (dummy HTTP.GET requests & responses)

To-Do
-----
- Interface IMU with ESP32-WROVER
- Define x4 PWM outputs to control the motors through the L293D motor drivers
- Use IMU data to implement control loop and flight functionality (Hover, Up, Down, Yaw L, Yaw R, Pitch L, Pitch R, Roll F, Roll B)

  
