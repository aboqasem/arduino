//
// Created by Mohammad Al Zouabi on 22/09/2020.
//
#pragma once

#include <Arduino.h>

/**
 * Attaches motor controller to pin
 * @param pin
 */
void attachMotorController(const uint8_t &pin);

/**
 * Sets the motor duty cycle at pin to dutyCycle
 * @param pin
 * @param dutyCycle
 */
void setMotorSpeed(const uint8_t &pin, const uint8_t &dutyCycle);
