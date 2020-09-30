//
// Created by Mohammad Al Zouabi on 22/09/2020.
//
#include "motor.hpp"

/**
 * Attaches motor controller to pin
 * @param pin
 */
void attachMotorController(const uint8_t &pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

/**
 * Sets the motor duty cycle at pin to dutyCycle
 * @param pin
 * @param dutyCycle
 */
void setMotorSpeed(const uint8_t &pin, const uint8_t &dutyCycle) {
  analogWrite(pin, dutyCycle);
}
