#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";
String userData = "{\"name\": \"John\", \"hobby\": \"Reading\"}"; // Data pribadi

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");
  
  sendPersonalizedData(userData);
}

void sendPersonalizedData(String data) {
  HTTPClient http;
  http.begin("https://api.openai.com/v1/chat/completions");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer YOUR_API_KEY");

  String body = "{\"model\": \"gpt-4\", \"messages\": [{\"role\": \"system\", \"content\": \"You are a helpful assistant named Hairo.\"}, {\"role\": \"user\", \"content\": \"" + data + "\"}]}";

  int httpResponseCode = http.POST(body);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();
}

void loop() {
  // Your other logic
}
