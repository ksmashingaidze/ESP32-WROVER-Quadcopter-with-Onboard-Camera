// Include ESC and motor libraries
#include <ESC.h>            // RC_ESC library by Eric Nantel
#include <ESP32Servo.h>     // ESP32Servo library by Kevin Harrington
// Include Adafruit gyroscope/accelerometer and barometer libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>           // Facilitates communication with I2C devices
// Include Wi-Fi libraries
#include <driver/dac.h>
#include <Arduino_BuiltIn.h>
#include <dummy.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>
#include <ESPAsyncWebSrv.h>
#include <AsyncTCP.h>

// Define I2C pins
#define SDA_PIN 21
#define SCL_PIN 22
// Declare sensor objects to interface with I2C
Adafruit_BMP085 bmp;   // Declare a new BMP085 object
Adafruit_MPU6050 mpu;  // Declare a new MPU6050 object
// Define PWM pin names for GPIO pins 12, 14, 32, and 33 which will control the motor drivers for motors M1, M2, M3, and M4
#define PWM_PIN_M1 14
#define PWM_PIN_M2 27
#define PWM_PIN_M3 32
#define PWM_PIN_M4 33
// Initialize ESC variables
ESC casper_esc_1(PWM_PIN_M1, 1000, 2200, 500);  // ESC(PIN, Min. Val., Max. Val., Arm Val.)
ESC casper_esc_2(PWM_PIN_M2, 1000, 2200, 500);  // ESC(PIN, Min. Val., Max. Val., Arm Val.)
ESC casper_esc_3(PWM_PIN_M3, 1000, 2200, 500);  // ESC(PIN, Min. Val., Max. Val., Arm Val.)
ESC casper_esc_4(PWM_PIN_M4, 1000, 2200, 500);  // ESC(PIN, Min. Val., Max. Val., Arm Val.)
// Initialize current motor speed variables
int m1_speed = 0;
int m2_speed = 0;
int m3_speed = 0;
int m4_speed = 0;
// Initialize motor thresholds
int down_threshold = 1200;        
int hover_threshold = 1250;
int up_threshold = 1300;
// Initialize PID control variables
double level_setpoint = 0;
double tilt_setpoint = 15;
double dt = 4.17*pow(10,-9);
double e_roll = 0;
double e_roll_old = 0;  
double e_roll_i = 0;
double e_roll_d = 0;
double e_pitch = 0; 
double e_pitch_old = 0;
double e_pitch_i = 0;
double e_pitch_d = 0;
double kp_roll = 1;
double kp_pitch = 1;
double ki_roll = 1;
double ki_pitch = 1;
double kd_roll = 1;
double kd_pitch = 1;
// Initialize Wi-Fi connection variables
const char* casper_status = ""; //Initialize a variable to store the current state of the quadcopter. The states are: Up, Down, Yaw L, Yaw R, Roll F, Roll B, Pitch L, Pitch R, and Hover
const char* wifi_ssid = "casper_ap";  // Define the ESP32 Wi-Fi SSID
const char* wifi_password = "AnFnxNVf1";    // Define the ESP32 Wi-Fi password
int wifi_channel = 1;                       // Wi-Fi channels can be 1-13
int wifi_ssid_hidden = 0;                   // SSID Broadcast = 0 | SSID Hidden = 1
int wifi_max_connections = 1;               // Define maximum number of devices that can connect
// Define an AsyncWebServer object, where the ESP32 will listen for requests on port 80
AsyncWebServer casper_server(80);

// Setup code, which runs once
void setup() {
  // Setup serial port for debugging
  Serial.begin(115200);                     // Enable serial data transmission to communicate with the serial monitor
  delay(1000);                              // Wait for serial monitor to open, as same port we used to program the micro is the one tied to the serial monitor

  // Check whether the BMP180 barometer works
  // If not, display an error message then hang in an infinite loop
  if (!bmp.begin()){
    Serial.println("No BMP180 atmospheric barometer detected.");
    while(1){
       //Infinite loop
    }
  }
  Serial.println("BMP180 Detected Successfully.");

  // Check whether the MPU6050 gyroscope/accelerometer works
  // If not, display an error message then hang in an infinite loop
  if (!mpu.begin()){
    Serial.println("No MPU6050 accelerometer/gyroscope detected.");
    while(1){
      // Infinite loop
    }
  }
  Serial.println("MPU6050 Detected Successfully.");

  // Define MPU6050 accelerometer/gyroscope parameters
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_184_HZ);
  delay(1000);

  // Define modes for GPIO pins 12, 14, 32, and 33
  pinMode(PWM_PIN_M1, OUTPUT);
  pinMode(PWM_PIN_M2, OUTPUT);
  pinMode(PWM_PIN_M3, OUTPUT);
  pinMode(PWM_PIN_M4, OUTPUT);

  // Arm ESCs
  casper_esc_1.arm();  
  delay(5000);
  casper_esc_2.arm();
  delay(5000);   
  casper_esc_3.arm();
  delay(5000);
  casper_esc_4.arm();
  delay(5000);

  // Configure ESP32 WROVER as a Wi-Fi access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(wifi_ssid, wifi_password, wifi_channel, wifi_ssid_hidden, wifi_max_connections);
  // Get the IP address of the ESP32, and display it in the console
  IPAddress casper_ip = WiFi.softAPIP();
  Serial.print("The ESP32 Wrover's IP Address is: ");
  Serial.println(casper_ip);

  // Listen for commands in the form of HTTP requests from the client on port 80
  //
  // Hover
  casper_server.on("/hover", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Hover";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the quadcopter maintaining a hover state, all motors fire equally to hover
    if (casper_status == "Hover"){
      // Assign the "Hover" setpoint motor speed
      m1_speed = hover_threshold;
      m2_speed = hover_threshold;
      m3_speed = hover_threshold;
      m4_speed = hover_threshold;
    }
  });
  //
  // Up
  casper_server.on("/up", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Up";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the "UP" button is pressed on the Android app, all motors fire equally to rise
    if (casper_status == "Up"){
      // Assign the "Up" setpoint motor speed
      m1_speed = up_threshold;
      m2_speed = up_threshold;
      m3_speed = up_threshold;
      m4_speed = up_threshold;
    }
  });
  //
  // Down
  casper_server.on("/down", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Down";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the "DOWN" button is pressed on the Android app, all motors fire equally to descend
    if (casper_status == "Down"){
      // Assign the "Down" setpoint motor speed
      m1_speed = down_threshold;
      m2_speed = down_threshold;
      m3_speed = down_threshold;
      m4_speed = down_threshold;
    }
  });
  //
  // Yaw L
  casper_server.on("/yawl", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Yaw L";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the "YAW L" button is pressed on the Android app, motors M2 & M3 fire equally faster to yaw left
    if (casper_status == "Yaw L"){
      // Assign the "Yaw L" setpoint motor speed
      m1_speed = hover_threshold;
      m2_speed = up_threshold;
      m3_speed = up_threshold;
      m4_speed = hover_threshold;
    }
  });
  //
  // Yaw R
  casper_server.on("/yawr", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Yaw R";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the "YAW R" button is pressed on the Android app, motors M1 & M4 fire equally faster to yaw right
    if (casper_status == "Yaw L"){
      // Assign the "Yaw L" setpoint motor speed
      m1_speed = up_threshold;
      m2_speed = hover_threshold;
      m3_speed = hover_threshold;
      m4_speed = up_threshold;
    }
  });
  //
  // Roll F
  casper_server.on("/rollf", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Roll F";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Roll B
  casper_server.on("/rollb", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Roll B";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Pitch L
  casper_server.on("/pitchl", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Pitch L";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Pitch R
  casper_server.on("/pitchr", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Pitch R";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Stop
  casper_server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Stop";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
    // If the "STOP" button is pressed on the Android app, all motors abruptly stop for an emergency shutdown
    if (casper_status == "Stop"){
      m1_speed = 0;
      m2_speed = 0;
      m3_speed = 0;
      m4_speed = 0;
    }
  });
  //
  // Capture
  casper_server.on("/capture", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Capture";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  //

  // Start the server on the ESP32 WROVER
  casper_server.begin();
  Serial.println("Casper is now ready to connect.");
}

// Main code, which runs infinitely
void loop() {
  delay(500);                   //Introduce a delay to protect the ESCs 
  // Set all motor speeds
  casper_esc_1.speed(m1_speed);
  casper_esc_2.speed(m2_speed);
  casper_esc_3.speed(m3_speed);
  casper_esc_4.speed(m4_speed);

  // IMPLEMENT PID CONTROL  
  // HOVER, UP, DOWN, YAW L, YAW R STATES
  // Ensure the quadcopter is level 
  if ((casper_status == "Hover") | (casper_status == "Up") | (casper_status == "Down") | (casper_status == "Yaw L") | (casper_status == "Yaw R")){
    // Get initial readings for error
    e_roll = level_setpoint - read_roll();
    e_pitch = level_setpoint - read_pitch();
    // To maintain level roll, motors M1 & M2 compensate
    if (e_roll != 0){
      e_roll_i += e_roll*dt;                // Update the integral error
      e_roll_d += (e_roll - e_roll_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
      m2_speed = m2_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
    }
    // To maintain level pitch, motors M1 & M3 compensate
    if (e_pitch != 0){
      e_pitch_i += e_pitch*dt;                // Update the integral error
      e_pitch_d += (e_pitch - e_pitch_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
      m3_speed = m3_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
    }
  }
  // ROLL F STATE
  else if (casper_status == "Roll F"){
    // Get initial readings for error
    e_roll = tilt_setpoint - read_roll();
    e_pitch = level_setpoint - read_pitch();
    // To roll forwards, motors M1 & M2 compensate
    if (e_roll != 0){
      e_roll_i += e_roll*dt;                // Update the integral error
      e_roll_d += (e_roll - e_roll_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
      m2_speed = m2_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
    }
    // To maintain level pitch, motors M1 & M3 compensate
    if (e_pitch != 0){
      e_pitch_i += e_pitch*dt;                // Update the integral error
      e_pitch_d += (e_pitch - e_pitch_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
      m3_speed = m3_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
    }
  }
  // ROLL B STATE
  else if (casper_status == "Roll B"){
    // Get initial readings for error
    e_roll = tilt_setpoint - (-read_roll());
    e_pitch = level_setpoint - read_pitch();
    // To roll backwards, motors M3 & M4 compensate
    if (e_roll != 0){
      e_roll_i += e_roll*dt;                // Update the integral error
      e_roll_d += (e_roll - e_roll_old)/dt; // Update the derivative error
      m3_speed = m3_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
      m4_speed = m4_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
    }
    // To maintain level pitch, motors M1 & M3 compensate
    if (e_pitch != 0){
      e_pitch_i += e_pitch*dt;                // Update the integral error
      e_pitch_d += (e_pitch - e_pitch_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
      m3_speed = m3_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
    } 
  }
  // PITCH L STATE
  else if (casper_status == "Pitch L"){
    // Get initial readings for error
    e_roll = level_setpoint - read_roll();
    e_pitch = tilt_setpoint - read_pitch();
    // To maintain level roll, motors M1 & M2 compensate
    if (e_roll != 0){
      e_roll_i += e_roll*dt;                // Update the integral error
      e_roll_d += (e_roll - e_roll_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
      m2_speed = m2_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
    }
    // To pitch left, motors M1 & M3 compensate
    if (e_pitch != 0){
      e_pitch_i += e_pitch*dt;                // Update the integral error
      e_pitch_d += (e_pitch - e_pitch_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
      m3_speed = m3_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
    } 
  }
  // PITCH R STATE
  else if (casper_status == "Pitch R"){
    // Get initial readings for error
    e_roll = level_setpoint - read_roll();
    e_pitch = tilt_setpoint - (-read_pitch());
    // To maintain level roll, motors M1 & M2 compensate
    if (e_roll != 0){
      e_roll_i += e_roll*dt;                // Update the integral error
      e_roll_d += (e_roll - e_roll_old)/dt; // Update the derivative error
      m1_speed = m1_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
      m2_speed = m2_speed + int((kp_roll*e_roll) + (ki_roll*e_roll_i) + (kd_roll*e_roll_d));
    }
    // To pitch right, motors M2 & M4 compensate
    if (e_pitch != 0){
      e_pitch_i += e_pitch*dt;                // Update the integral error
      e_pitch_d += (e_pitch - e_pitch_old)/dt; // Update the derivative error
      m2_speed = m2_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
      m4_speed = m4_speed + int((kp_pitch*e_pitch) + (ki_pitch*e_pitch_i) + (kd_pitch*e_pitch_d));
    } 
  }
    
  e_roll_old = e_roll;
  e_pitch_old = e_pitch;

}

// Declare function to read roll data from accelerometer/gyroscope
double read_roll(){
  // Get and update MPU6050 sensor events with the latest readings
  sensors_event_t my_acc_event, my_gyro_event, my_temp_event;
  mpu.getEvent(&my_acc_event, &my_gyro_event, &my_temp_event);
  // Read angular velocity from MPU6050 sensor
  double gyro_x = my_gyro_event.gyro.x;
  double gyro_y = my_gyro_event.gyro.y;
  double gyro_z = my_gyro_event.gyro.z;
  // Read acceleration from MPU6050 sensor
  double acc_x = my_acc_event.acceleration.x;
  double acc_y = my_acc_event.acceleration.y;
  double acc_z = my_acc_event.acceleration.z;
  // Calculate roll angle using accelerometer data
  double roll_angle = atan(acc_y/sqrt((acc_x*acc_x)+(acc_z*acc_z)))*(180/M_PI);
  // Return the roll angle
  return(roll_angle);
}

// Declare function to read pitch data from accelerometer/gyroscope
double read_pitch(){
  // Get and update MPU6050 sensor events with the latest readings
  sensors_event_t my_acc_event, my_gyro_event, my_temp_event;
  mpu.getEvent(&my_acc_event, &my_gyro_event, &my_temp_event);
  // Read angular velocity from MPU6050 sensor
  double gyro_x = my_gyro_event.gyro.x;
  double gyro_y = my_gyro_event.gyro.y;
  double gyro_z = my_gyro_event.gyro.z;
  // Read acceleration from MPU6050 sensor
  double acc_x = my_acc_event.acceleration.x;
  double acc_y = my_acc_event.acceleration.y;
  double acc_z = my_acc_event.acceleration.z;
  // Calculate pitch angle using accelerometer data
  double pitch_angle = -atan(acc_x/sqrt((acc_y*acc_y)+(acc_z*acc_z)))*(180/M_PI);
  // Return the pitch angle
  return(pitch_angle);
}

// REFERENCE NOTES
// ---------------
// Client = Wi-Fi station (Can make HTTP requests to the server i.e. HTTP GET, HTTP POST)
// Server = Wi-Fi access point (Listens for incoming requests from the client and responds accordingly)
// "analogWrite()"" does not work on ESP32. "ledcWrite()" should be used instead 
// Each GPIO pin can be assigned a PWM channel from 0-15
// The resolution of the pulse width can be set from 1-16

// FUTURE WORK
// -----------
// The ESP32-WROVER should be configured as a Wi-Fi station for a future solution.
// For the ideal solution, Web hosting would be organised, e.g. Amazon EC2, to
// provide a distinct web server. The user would then be able to control the ESP32
// over the internet, even when not in range. The user would also be able to request
// security data or footage from the Amazon EC2 web server, even when the user is
// off-site.

// For the sake of simplicity, and rapid prototyping without web-hosting expenses, the
// ESP32 WROVER is being used here as a Wi-Fi access point.

// USEFUL CODE
// -----------
// #define DAC_CH1 25
// dacWrite(DAC_CH1, dac_out_value);
// delay(3000);