//
// Created by Mohammad Al Zouabi on 22/09/2020.
//
#pragma once

#include <Arduino.h>

/**
 * Attaches motor to interrupt pin
 * @param pin
 */
void attachMotor(const uint8_t &pin);

/**
 * Detaches motor from interrupt pin
 * @param pin
 */
void detachMotor(const uint8_t &pin);

/**
 * Calculates and returns the motor rounds per minute
 * @return motor rounds per minute
 */
uint16_t getMotorRpm();

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
