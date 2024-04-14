#include <ESC.h>            // RC_ESC library by Eric Nantel
#include <ESP32Servo.h>     // ESP32Servo library by Kevin Harrington

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
      casper_esc_1.speed(1200);
      casper_esc_2.speed(1200);
      casper_esc_3.speed(1200);
      casper_esc_4.speed(1200);

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
      casper_esc_1.speed(1500);
      casper_esc_2.speed(1500);
      casper_esc_3.speed(1500);
      casper_esc_4.speed(1500);
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
      casper_esc_1.speed(500);
      casper_esc_2.speed(500);
      casper_esc_3.speed(500);
      casper_esc_4.speed(500);
    }
  });
  //
  // Yaw L
  casper_server.on("/yawl", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Yaw L";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Yaw R
  casper_server.on("/yawr", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Yaw R";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
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
      casper_esc_1.speed(0);
      casper_esc_2.speed(0);
      casper_esc_3.speed(0);
      casper_esc_4.speed(0);
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
}

// Main code, which runs infinitely
void loop() {

  // Asynchronous server is activated above, so this loop is bypassed

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