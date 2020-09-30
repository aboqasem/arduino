#include "utility.hpp"
#include "motor.hpp"

#define PIN_MOTOR 2
#define PIN_CONTROLLER 3

uint8_t useSerialMonitor = 0;
uint8_t userInput = 0;
uint8_t previousUserInput = 0;
uint8_t dutyCycle = 0;

// the setup function runs once on power or reset
void setup() {
  // attach a motor to pin 2
  attachMotor(PIN_MOTOR);
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
      // these statements are to make sure:
      // 1- in range 4 to 9) values
      // 2- better accuracy when new speeds are entered
      // 3- no extra delays or repetition on 0
      // 4- no extra delays or repetition on old values
      // if user input value is not in range, turn off the motor
      if (!(userInput >= 4 && userInput <= 9)) {
        userInput = previousUserInput = dutyCycle = 0;
        setMotorSpeed(PIN_CONTROLLER, dutyCycle);
        Serial.println("Motor turned off.");
      }
        // else if the value is repeated just get and print the RPM
      else if (userInput == previousUserInput) {
        Serial.println("Calculating RPM...");
        printRpm(getMotorRpm());
      }
        // else, the value is new, calculate the duty cycle and set it,
        // delay 5 seconds while the motor is changing speed for accuracy,
        // then calculate and print the RPM
      else {
        previousUserInput = userInput;
        dutyCycle = numberToDutyCycle(userInput, 9);
        Serial.println("Changing speed...");
        setMotorSpeed(PIN_CONTROLLER, dutyCycle);
        delayMilliseconds(5000);
        printRpm(getMotorRpm());
      }
      Serial.println("Waiting for input...");
    } // if input received
    // always print the rpm
    printRpm(getMotorRpm());
  } // if useSerialMonitor
}
