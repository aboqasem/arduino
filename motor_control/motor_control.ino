#include "utility.hpp"
#include "motor.hpp"

#define PIN_CONTROLLER 3

uint8_t useSerialMonitor = 0;
uint8_t userInput = 0;
uint8_t dutyCycle = 0;

// the setup function runs once on power or reset
void setup() {
  // attach motor controller to pin 3
  attachMotorController(PIN_CONTROLLER);
  // begin serial connection for data transmission
  Serial.begin(9600);
  // allow user to choose serial monitor usability within the
  // first 3 seconds of power/reset by pressing any key
  setSerialUsability(useSerialMonitor);
  if (useSerialMonitor)
    Serial.println("Enter motor speed (4 to 9, 0 to turn off).\nWaiting for input...");
}

// the loop function loops forever
void loop() {
  if (useSerialMonitor) {
    // if input received
    if (Serial.available()) {
      // read number received
      userInput = readNumber();
      // if user input value is not in range, turn off the motor
      if (!(userInput >= 4 && userInput <= 9)) {
        dutyCycle = 0;
        setMotorSpeed(PIN_CONTROLLER, dutyCycle);
        Serial.println("Motor turned off.");
      }
        // else, change the speed
      else {
        dutyCycle = numberToDutyCycle(userInput, 9);
        setMotorSpeed(PIN_CONTROLLER, dutyCycle);
      }
      Serial.println("Waiting for input...");
    } // if input received
  } // if useSerialMonitor
}
