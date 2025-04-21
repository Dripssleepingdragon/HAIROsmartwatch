#include <Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;
SoftwareSerial ss(4, 3);  // RX, TX pins for GPS module

void setup() {
  Serial.begin(115200);
  ss.begin(9600);
}

void loop() {
  while (ss.available() > 0) {
    gps.encode(ss.read());
    
    if (gps.location.isUpdated()) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      
      Serial.print("Latitude= "); 
      Serial.print(latitude, 6); 
      Serial.print(" Longitude= "); 
      Serial.println(longitude, 6);
    }
  }
}
