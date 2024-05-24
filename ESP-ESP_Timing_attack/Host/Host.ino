#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESPattack";
const char* password = "password123";
ESP8266WebServer server(80);

const char* correctPassword = "1586";

void handleRoot() {
  String message = "Enter Password: ";
  server.send(200, "text/plain", message);
}

void handlePassword() {
  String receivedPassword = server.arg("password");
  Serial.print("Received password: ");
  Serial.println(receivedPassword);

  bool isCorrect = true;
  if (receivedPassword.length() != strlen(correctPassword)) {
    isCorrect = false;
  } 
  else {
    for (int i = 0; i < strlen(correctPassword); ++i) {
      if (receivedPassword[i] != correctPassword[i]) {
        isCorrect = false;
        break;
      }
      delay(100);
    }
  }

  if (isCorrect) {
    delay(500); // Simulate longer processing time for correct password
    server.send(200, "text/plain", "Access Granted");
  } else {
    delay(100); // Simulate shorter processing time for incorrect password
    server.send(403, "text/plain", "Access Denied");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);  // Set the ESP8266 as an Access Point
  WiFi.softAP(ssid, password);

  // Print the IP address of the ESP8266
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/password", HTTP_POST, handlePassword);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}