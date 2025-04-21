void sendData(String dataJson) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://your-server.com/api/data");
    http.addHeader("Content-Type", "application/json");
    http.POST(dataJson);
    http.end();
  } else {
    saveToFlash(dataJson);  // Simpan kalau offline
  }
}
