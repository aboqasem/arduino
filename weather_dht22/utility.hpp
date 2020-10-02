//
// Created by Mohammad Al Zouabi on 01/10/2020.
//
#pragma once

#include <Arduino.h>
#include <DHT.h>

/**
 * Delay for a given time in milliseconds
 * @param milliseconds
 */
void delayMilliseconds(const uint32_t &milliseconds);

/**
 * prints temperature.
 * @param temperature
 */
void printWeatherInfo(const float &temperature);

/**
 * prints temperature and humidity.
 * @param temperature
 * @param humidity
 */
void printWeatherInfo(const float &temperature, const float &humidity);

/**
 * prints temperature, humidity, and heat index.
 * @param temperature
 * @param humidity
 * @param heatIndex
 */
void printWeatherInfo(const float &temperature, const float &humidity, const float &heatIndex);
