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

// Initialize key variables
int dac_out_value = 0;   // Initialize a variable to store the DAC output
const char* casper_status = ""; //Initialize a variable to store the current state of the quadcopter. The states are: Up, Down, Yaw L, Yaw R, Roll F, Roll B, Pitch L, Pitch R, and Hover
const char* wifi_ssid = "casper_ap";  // Define the ESP32 Wi-Fi SSID
const char* wifi_password = "AnFnxNVf1";    // Define the ESP32 Wi-Fi password
int wifi_channel = 1;                       // Wi-Fi channels can be 1-13
int wifi_ssid_hidden = 0;                   // SSID Broadcast = 0 | SSID Hidden = 1
int wifi_max_connections = 1;               // Define maximum number of devices that can connect
// Define an AsyncWebServer object, where the ESP32 will listen for requests on port 80
AsyncWebServer casper_server(80);

void setup() {
  // Setup serial port for debugging
  Serial.begin(115200);                       // Enable serial data transmission to communicate with the serial monitor
  delay(1000);                                // Wait for serial monitor to open, as same port we used to program the micro is the one tied to the serial monitor

  // Configure ESP32 WROVER as a Wi-Fi access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(wifi_ssid, wifi_password, wifi_channel, wifi_ssid_hidden, wifi_max_connections);
  // Get the IP address of the ESP32, and display it in the console
  IPAddress casper_ip = WiFi.softAPIP();
  Serial.print("The ESP32 Wrover's IP Address is: ");
  Serial.println(casper_ip);

  // Listen for commands in the form of HTTP requests from the client on port 80
  //
  // Up
  casper_server.on("/up", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Up";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
  });
  //
  // Down
  casper_server.on("/down", HTTP_GET, [](AsyncWebServerRequest *request) {
    casper_status = "Down";
    request->send_P(200, "text/plain", casper_status);
    Serial.println(casper_status);
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

void loop() {
  // Main code which runs infinitely
  // Control quadcopter motors using PWM

}

// REFERENCE NOTES
// ---------------
// Client = Wi-Fi station (Can make HTTP requests to the server i.e. HTTP GET, HTTP POST)
// Server = Wi-Fi access point (Listens for incoming requests from the client and responds accordingly)

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