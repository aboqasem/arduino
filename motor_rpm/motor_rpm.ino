#include <Arduino.h>

volatile uint8_t interrupts_count = 0;
volatile uint64_t start_time = 0;
uint16_t motor_rpm = 0;

// the setup function runs once on power or reset
void setup() {
  // begin the serial for data transmission
  Serial.begin(9600);
  // attach interrupt to increment interrupts_count on RISING signal on pin 2
  attachInterrupt(digitalPinToInterrupt(2), [](){++interrupts_count;}, RISING);
}

// the loop function loops forever
void loop() {
  // time to start counting the interrupts
  start_time = millis();
  // reset number of interrupts
  interrupts_count = 0;
  // count interrupts for one second
  while (millis() - start_time < 1000);
  // the motor rounds per minutes =
  // interrupts / 2 (pulses per revolution) * 60 (seconds)
  motor_rpm = interrupts_count / 2 * 60;
  // print the data to the serial
  Serial.print(motor_rpm); Serial.println(" RPM");
}
