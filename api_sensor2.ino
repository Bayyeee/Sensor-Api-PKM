#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "UD-LiMa";
const char* password = "udlimagantengbos123";
const char* serverAddress = "https://fireguardudlima.000webhostapp.com/add_data.php";

const int flamePin = A0;
const int flameThreshold = 0;
const int maxSensorValue = 4095;
const int minSensorValue = 0;
const int maxDistance = 1;
const int minDistance = 150;

bool flameDetected = false;
unsigned long flameDetectedTime = 0;
const unsigned long detectionTimeout = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);
  connectWiFi();
}

void loop() {
  int flameValue = analogRead(flamePin);
  
  if (flameValue > flameThreshold) {
    flameDetected = true;
    flameDetectedTime = millis();
    sendData(flameValue);
  } else if (flameDetected && millis() - flameDetectedTime >= detectionTimeout) {
    flameDetected = false;
    sendData(0);
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

  float distance = (flameValue == 0) ? 0 : map(flameValue, minSensorValue, maxSensorValue, minDistance, maxDistance);

  HTTPClient http;
  String url = String(serverAddress) + "?flameValue=" + String(flameValue) + "&distance=" + String(distance);
  http.begin(url);

  int httpCode = http.GET();
  String payload = http.getString();

  Serial.print("HTTP Code: ");
  Serial.println(httpCode);
  Serial.print("Response: ");
  Serial.println(payload);

  http.end();
}
