#include <SPIFFS.h>

void saveToFlash(String data) {
  if (!SPIFFS.begin(true)) {
    Serial.println("Gagal mount SPIFFS");
    return;
  }
  File file = SPIFFS.open("/backup.txt", FILE_APPEND);
  if (file) {
    file.println(data);
    file.close();
  }
}
