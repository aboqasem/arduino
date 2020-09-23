//
// Created by Mohammad Al Zouabi on 20/09/2020.
//
#include "utility.hpp"

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
    // flush the serial monitor
    Serial.flush();
    // set usability flag to usable
    usable = 1;
  } else usable = 0; // else set as not usable
}
