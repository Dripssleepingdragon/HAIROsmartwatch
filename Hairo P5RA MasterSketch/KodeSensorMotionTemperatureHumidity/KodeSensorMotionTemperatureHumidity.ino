#include <DHT.h>
#define DHTPIN 15          // Pin DHT sensor
#define DHTTYPE DHT11      // DHT 11 (DHT22 bisa dipilih juga)
DHT dht(DHTPIN, DHTTYPE);

int pirPin = 13;          // Pin sensor gerak PIR
int pirState = LOW;       // Status sensor gerak

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(pirPin, INPUT);
}

void loop() {
  pirState = digitalRead(pirPin);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  if (pirState == HIGH) {
    Serial.println("Movement detected!");
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C  ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000);
}
