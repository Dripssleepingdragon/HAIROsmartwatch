if (WiFi.status() != WL_CONNECTED) {
  String offlineEmotion = analisisOfflineEmosi(heartRate, suhu);
  Serial.println("Hairo [offline emotion]: " + offlineEmotion);
}
✅ Poin Bonus – Menyimpan Input Offline
cpp
Copy
Edit
void saveUserQueryOffline(String input, String response) {
  if (!SPIFFS.begin(true)) return;

  File log = SPIFFS.open("/offline_log.txt", FILE_APPEND);
  if (log) {
    log.println("Q: " + input);
    log.println("A: " + response);
    log.close();
  }
}