#include <WiFi.h>
#include <BluetoothSerial.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
#include "DHT.h"
#include <NewPing.h>

// ---------- WiFi ----------
const char* ssid = "Nama_WiFi";
const char* password = "Password_WiFi";

// ---------- Bluetooth ----------
BluetoothSerial SerialBT;

// ---------- MAX30102 ----------
MAX30105 particleSensor;
#define MAX_BRIGHTNESS 255

// ---------- DHT22 ----------
#define DHTPIN 27
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ---------- MPU6050 ----------
Adafruit_MPU6050 mpu;

// ---------- Ultrasonik ----------
#define TRIG_PIN 5
#define ECHO_PIN 4
NewPing sonar(TRIG_PIN, ECHO_PIN, 200); // max jarak 200cm

void setup() {
  Serial.begin(115200);

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTerhubung ke WiFi: " + WiFi.localIP().toString());

  // Bluetooth
  SerialBT.begin("Hairo_BT"); // Nama Bluetooth
  Serial.println("Bluetooth diaktifkan");

  // MAX30102
  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 tidak terdeteksi");
  } else {
    particleSensor.setup(); // default settings
    particleSensor.setPulseAmplitudeRed(0x0A);
    particleSensor.setPulseAmplitudeGreen(0);
  }

  // DHT
  dht.begin();

  // MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 tidak ditemukan");
  } else {
    Serial.println("MPU6050 siap");
  }

  // Ultrasonik tidak perlu setup khusus
}

void loop() {
  Serial.println("---- Sensor Data ----");

  // MAX30102 - Heart Rate
  long irValue = particleSensor.getIR();
  if (irValue > 50000) {
    Serial.print("IR Value: ");
    Serial.println(irValue);
  } else {
    Serial.println("Letakkan jari di sensor MAX30102");
  }

  // DHT22 - Suhu & Kelembapan
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (!isnan(h) && !isnan(t)) {
    Serial.print("Suhu: ");
    Serial.print(t);
    Serial.print("°C  Kelembapan: ");
    Serial.print(h);
    Serial.println("%");
  }

  // MPU6050 - Akselerometer
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print("Accel X: ");
  Serial.print(a.acceleration.x);
  Serial.print(" m/s², Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.println(a.acceleration.z);

  // HC-SR04 - Ultrasonik
  int jarak = sonar.ping_cm();
  Serial.print("Jarak Ultrasonik: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Kirim via Bluetooth (opsional)
  SerialBT.println("HR: " + String(irValue) + ", Suhu: " + String(t) + ", Jarak: " + String(jarak) + "cm");

  delay(3000);
}
