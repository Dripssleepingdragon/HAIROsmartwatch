#include <AESLib.h>
#include <SPIFFS.h>

AESLib aesLib;
byte key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0x85, 0x48, 0x1f, 0x22, 0x6b, 0x9d, 0x15, 0x14};  // 128-bit key

void setup() {
  Serial.begin(115200);
  
  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }

  String userData = "{\"name\": \"John\", \"dob\": \"01/01/1990\", \"hobby\": \"Reading\"}";

  byte encData[128];
  aesLib.encrypt((byte*)userData.c_str(), userData.length(), encData, key);
  
  File file = SPIFFS.open("/userdata.enc", FILE_WRITE);
  if (file) {
    file.write(encData, sizeof(encData));
    file.close();
    Serial.println("Data encrypted and saved");
  }
}

void loop() {
  // Your other logic
}
