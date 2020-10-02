//
// Created by Mohammad Al Zouabi on 01/10/2020.
//
#include "utility.hpp"

/**
 * Delay for a given time in milliseconds
 * @param milliseconds
 */
void delayMilliseconds(const uint32_t &milliseconds) {
  volatile uint32_t startTime = millis();
  while (millis() - startTime < milliseconds);
}

/**
 * prints temperature.
 * @param temperature
 */
void printWeatherInfo(const float &temperature) {
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F(" C°"));
}

/**
 * prints temperature and humidity.
 * @param temperature
 * @param humidity
 */
void printWeatherInfo(const float &temperature, const float &humidity) {
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.print(F(" C° # "));
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println(F("%"));
}

/**
 * prints temperature, humidity, and heat index.
 * @param temperature
 * @param humidity
 * @param heatIndex
 */
void printWeatherInfo(const float &temperature, const float &humidity, const float &heatIndex) {
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.print(F(" C° # "));
  Serial.print(F("Feels like: "));
  Serial.print(heatIndex);
  Serial.print(F(" C° # "));
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.println(F("%"));
}
