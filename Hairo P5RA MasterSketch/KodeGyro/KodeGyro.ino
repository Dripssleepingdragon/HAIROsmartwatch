#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  Serial.print("Accelerometer: ");
  Serial.print("X= "); Serial.print(ax); 
  Serial.print(" Y= "); Serial.print(ay); 
  Serial.print(" Z= "); Serial.print(az);
  Serial.print("\t");

  Serial.print("Gyroscope: ");
  Serial.print("X= "); Serial.print(gx); 
  Serial.print(" Y= "); Serial.print(gy); 
  Serial.print(" Z= "); Serial.println(gz);

  delay(1000);
}
