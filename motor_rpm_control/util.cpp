//
// Created by Mohammad Al Zouabi on 20/09/2020.
//
#include "util.h"

/**
 * Sets whether the serial monitor will be used by waiting for input
 * for the first 3 seconds after power or reset
 * @param usable
 */
void setSerialUsability(uint8_t &usable) {
  // wait for 3 seconds or input from the serial monitor
  while (Serial.available() == 0 && millis() < 3000);
  // if any available inputs
  if (Serial.available()) {
    // clear the received input from serial monitor
    Serial.read();
    // set usability flag to usable
    usable = 1;
  } else usable = 0; // else set as not usable
}

/**
 * Delay for a given time in milliseconds
 * @param milliseconds
 */
void delayMilliseconds(const uint32_t &milliseconds) {
  volatile uint32_t startTime = millis();
  while (millis() - startTime < milliseconds);
}

/**
 * Reads a character and returns it as number
 * @return
 */
uint8_t readNumber() {
  return (float) Serial.read() - '0';
}

/**
 * Returns duty cycle of a number out of outOf
 * @param number
 * @param outOf
 * @return duty cycle
 */
uint8_t numberToDutyCycle(const uint8_t &number, const uint8_t &outOf) {
  // percentage of number out of outOf * 255 (max duty cycle)
  return (((float) number / (float) outOf) * 255.0f);
}

/**
 * Print the rpm tp the serial monitor
 * @param rpm
 */
void printRpm(const uint16_t &rpm) {
  Serial.print(rpm);
  Serial.println(" RPM");
}
