#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

// Pin untuk koneksi dengan modul Fingerprint
SoftwareSerial mySerial(2, 3); // RX, TX pin
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  Serial.begin(115200);
  mySerial.begin(57600);
  
  if (finger.begin()) {
    Serial.println("Fingerprint sensor found");
  } else {
    Serial.println("Fingerprint sensor not found");
    while (1);
  }
}

void loop() {
  getFingerprintID();
}

void getFingerprintID() {
  int p = finger.getImage();
  if (p != FINGERPRINT_OK) {
    Serial.println("Failed to get image");
    return;
  }
  
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) {
    Serial.println("Failed to convert image");
    return;
  }
  
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) {
    Serial.println("No match found");
  } else {
    Serial.println("Fingerprint match found!");
  }
}
