ESP32-WROVER Quadcopter with Onboard Camera (a.k.a. Casper)
==============================================================================================================================================================================

App controlled quadcopter with onboard camera implemented using the Freenove ESP32-WROVER CAM Board.
Included:
Android Controller Code folder containing the quadcopter remote Android app C# code, written in MS Visual Studio.
ESP32-WROVER MCU Code folder containing the MCU control embedded C code, written in Arduino IDE.

The user connects their Android device to the quadcopter's Wi-Fi access point in order to control the quadcopter using the Android app.

Completed
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
- Assembled quadcopter frame and installed x4 A2212 KV2200 brushless motors, and x4 30A ESCs
- Setup ESP32-WROVER in Wi-Fi AP mode and configured a dedicated server using Arduino IDE
- Developed an Android app interface in Microsoft Visual Studio
- Established communication between ESP32-WROVER and Android app using HTTP (HTTP.GET requests & responses)
- Defined x4 PWM outputs to control the motors via the electronic speed controllers
- Installed x2 CCW and x2 CW props on the quadcopter
- Added "Stop" button to Android app to implement an abrupt emergency shutdown of the quadcopter. Quadcopter is in "Stop" state at startup
- Added functionality to enforce hover state on release of Android app buttons
- Changed line 16 of RC_ESC -> src -> ESC.h from "#include Servo.h" to "#include ESP32Servo.h"
- Included "ESC.h" (from "RC_ESC" library by Eric Nantel) and "ESP32Servo.h" (from "ESP32Servo" library by Kevin Harrington) at the beginning of the main casper.ino file
- Replaced faulty ESC3 (electronic speed controller attached to motor M3)
- Ran preliminary tests to check motor functionality, lift, and app<->MCU responsiveness
- Replaced broken prop (damaged in flight test) and opposing/mirroring prop with placeholders
- Tuned DAC outputs against quadcopter weight to **add basic flight and hover functionality**
- **Achieved vertical take-off**
- Adjusted motor thrusts, mindful of susceptibility of ESCs to blowing up when overdriven for long periods
- Replaced electronic speed controller ESC 1 (burned) and motor M2 (broken connector) combination. Cheaper to buy as a set, rather than sourcing replacement connectors, etc.
- Sourced uniform props

To-Do
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
- **Interface IMU** (gyroscope rotational data & barometer altitude information) with ESP32-WROVER
- Use IMU barometer/gyroscope data to **complete flight controller with vertical/rotational constraints and improved flight functionality**
- **Allow capture of a still image** using the ESP32-WROVER camera when the "Capture" button is pressed on the Android app
