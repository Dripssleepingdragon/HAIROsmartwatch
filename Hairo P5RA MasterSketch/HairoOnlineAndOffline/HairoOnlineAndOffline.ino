// === HAIRO SMARTWATCH AI - ARDUINO CODE ===
#include <WiFi.h>
#include <HTTPClient.h>
#include <SPIFFS.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";

int heartRatePin = 34;
int tempSensorPin = 35;

void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

String analisisEmosi(int detak, int suhu) {
  if (detak > 100 && suhu > 38) return "stres dan demam";
  else if (detak < 70) return "tenang dan rileks";
  return "emosi normal";
}

void sendData(String dataJson) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://192.168.1.100:5000/api/data");
    http.addHeader("Content-Type", "application/json");
    int code = http.POST(dataJson);
    Serial.println("Response code: " + String(code));
    http.end();
  } else {
    saveToFlash(dataJson);
  }
}

void saveToFlash(String data) {
  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }
  File file = SPIFFS.open("/backup.txt", FILE_APPEND);
  if (file) {
    file.println(data);
    file.close();
  }
}

void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  int heartRate = analogRead(heartRatePin);
  int suhu = analogRead(tempSensorPin);
  String emosi = analisisEmosi(heartRate, suhu);

  String json = "{";
  json += "\"heartRate\":" + String(heartRate) + ",";
  json += "\"temperature\":" + String(suhu) + ",";
  json += "\"emotion\":\"" + emosi + "\"}";

  Serial.println(json);
  sendData(json);
  delay(10000);
}