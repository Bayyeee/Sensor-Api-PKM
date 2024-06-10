#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "UD-LiMa";
const char* password = "udlimagantengbos123";
const char* serverAddress = "http://192.168.1.198/add_data.php";

const int flamePin = A0;
const int flameThreshold = 0;
const int maxSensorValue = 4095;
const int minSensorValue = 0;
const int maxDistance = 1;
const int minDistance = 150;

void setup() {
  Serial.begin(9600);
  connectWiFi();
}

void loop() {
  int flameValue = analogRead(flamePin);

  if (flameValue > flameThreshold) {
    sendData(flameValue);
  }

  delay(1000);
}

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void sendData(int flameValue) {
  Serial.print("Sending data...");

  float distance = map(flameValue, minSensorValue, maxSensorValue, minDistance, maxDistance);

  HTTPClient http;
  String url = String(serverAddress) + "?flameValue=" + String(flameValue) + "&distance=" + String(distance);
  // String url = serverAddress + "?flameValue=" + String(flameValue) + "&distance=" + String(distance);
  http.begin(url);

  int httpCode = http.GET();
  String payload = http.getString();

  Serial.print("HTTP Code: ");
  Serial.println(httpCode);
  Serial.print("Response: ");
  Serial.println(payload);

  http.end();
}
