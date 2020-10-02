#include "utility.hpp"

#define PIN_DHT 2
#define TYPE_DHT DHT22

DHT dht(PIN_DHT, TYPE_DHT);

float temperature = 0;
float humidity = 0;
float feelsLike = 0;

// the setup function runs once on power or reset
void setup() {
  // begin the DHT temperature sensor
  dht.begin();
  // begin serial connection for data transmission
  Serial.begin(9600);
  // wait for serial monitor
  while (!Serial);
}

// the loop function loops forever
void loop() {
  // read temperature
  temperature = dht.readTemperature();
  // read humidity
  humidity = dht.readHumidity();
  // calculate heat index
  feelsLike = dht.computeHeatIndex(temperature, humidity);
  printWeatherInfo(temperature, humidity, feelsLike);
  // delay 2 seconds (DHT22 sensing period)
  delayMilliseconds(2000);
}
