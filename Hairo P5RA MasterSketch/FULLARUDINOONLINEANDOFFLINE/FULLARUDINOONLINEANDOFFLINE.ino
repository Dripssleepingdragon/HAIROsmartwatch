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

String analisisOfflineEmosi(int detak, int suhu) {
  if (detak > 110 && suhu > 38) return "Kurang sehat bro, masa depan masih panjang, kita rehat sejenak!.";
  else if (detak > 90) return "Bro? kamu lagi cemas ya? apa lagi aktif nih bun?.";
  else if (detak < 70) return "Lagi santai kah bro, chill dulu gak sih? mau ngobrol ngobrol juga boleh.";
  return "Kondisimu normal dan stabil.";
}

String getLocalResponse(String input, int detak, int suhu) {
  input.toLowerCase();

  if (input.indexOf("hai") >= 0 || input.indexOf("halo") >= 0) {
    return "Hai! Ada yang bisa aku bantu?";
  } else if (input.indexOf("suhu") >= 0) {
    return "Suhu tubuhmu sekarang sekitar " + String(suhu);
  } else if (input.indexOf("detak") >= 0 || input.indexOf("jantung") >= 0) {
    return "Detak jantungmu sekarang " + String(detak);
  } else if (input.indexOf("kabar") >= 0 || input.indexOf("bagaimana") >= 0) {
    return analisisOfflineEmosi(detak, suhu);
  } else {
    return "Maaf, aku tidak mengerti. Coba gunakan kata lain.";
  }
}

void saveUserQueryOffline(String input, String response) {
  if (!SPIFFS.begin(true)) return;

  File log = SPIFFS.open("/offline_log.txt", FILE_APPEND);
  if (log) {
    log.println("Q: " + input);
    log.println("A: " + response);
    log.close();
  }
}

String analisisOnlineEmosi(int detak, int suhu) {
  if (detak > 100 && suhu > 38) return "stres dan demam";
  else if (detak < 70) return "tenang dan rileks";
  return "emosi normal";
}

void sendDataOnline(String dataJson) {
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
  SPIFFS.begin(true);
  connectWiFi();
}

void loop() {
  int heartRate = analogRead(heartRatePin);
  int suhu = analogRead(tempSensorPin);

  // Simulasi input pengguna
  String userInput = "hai haiiro";  // Ganti dengan input dari STT jika tersedia

  if (WiFi.status() == WL_CONNECTED) {
    String emosi = analisisOnlineEmosi(heartRate, suhu);

    String json = "{";
    json += "\"heartRate\":" + String(heartRate) + ",";
    json += "\"temperature\":" + String(suhu) + ",";
    json += "\"emotion\":\"" + emosi + "\"}";

    Serial.println("Online Mode: " + json);
    sendDataOnline(json);
  } else {
    String response = getLocalResponse(userInput, heartRate, suhu);
    Serial.println("Hairo [offline]: " + response);
    saveUserQueryOffline(userInput, response);
  }

  delay(10000); // Delay 10 detik
}
