//
// Created by Mohammad Al Zouabi on 20/09/2020.
//
#pragma once

#include <Arduino.h>

/**
 * Sets whether the serial monitor will be used
 * @param usable
 */
void setSerialUsability(uint8_t &usable);

/**
 * Delay for a given time in milliseconds
 * @param milliseconds
 */
void delayMilliseconds(const uint32_t &milliseconds);

/**
 * Reads a character and returns it as number
 * @return number
 */
uint8_t readNumber();

/**
 * Returns duty cycle of a number out of outOf
 * @param number
 * @param max
 * @return
 */
uint8_t numberToDutyCycle(const uint8_t &number, const uint8_t &max);

/**
 * Print the rpm tp the serial monitor
 * @param rpm
 */
void printRpm(const uint16_t &rpm);