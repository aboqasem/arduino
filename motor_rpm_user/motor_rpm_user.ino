#define PIN03 3

volatile uint8_t interrupts_count = 0;
volatile uint64_t start_time = 0;
uint8_t userInput = 0;
uint8_t previousUserInput = 0;
uint8_t dutyCycle = 0;
uint16_t motor_rpm = 0;

// the setup function runs once on power or reset
void setup() {
  // attach interrupt to increment interrupts_count on RISING signal on pin 2
  attachInterrupt(digitalPinToInterrupt(2), [](){++interrupts_count;}, RISING);
  // set pin 3 as output
  pinMode(PIN03, OUTPUT);
  // write LOW to pin 3
  analogWrite(PIN03, LOW);
  // begin the serial for data transmission
  Serial.begin(9600);
  Serial.println("Enter motor speed: 3 to 9 | 0 to turn off.");
}

// the loop function loops forever
void loop() {
  // if there is a serial
  if (Serial.available()) {
    // get user input character, cast to number
    userInput = (float) Serial.read() - '0';

    // this is to make sure better accuracy when new speeds are entered, and no
    // extra delays or repetition on 0 or old values
    // if user input value is not within 3 and 9, turn off the motor
    if (!(userInput >= 3 && userInput <= 9)) {
      previousUserInput = 0;
      analogWrite(PIN03, 0);
      Serial.println("Off");
    }
    // else if the value is repeated there is no need for an extra delay,
    // thus, calculate and print the RPM
    else if (previousUserInput == userInput) {
      Serial.println("Calculating RPM...");
      calculateMotorRpm();
      Serial.print(motor_rpm);
      Serial.println(" RPM");
    }
    // else, the value is new, calculate the duty cycle and set it as output,
    // delay 5 seconds while the motor is speeding up for accuracy,
    // then calculate and print the RPM
    else {
      previousUserInput = userInput;
      // the duty cycle =
      // percentage (user input [3 to 9] to 9) * 255 (the maximum duty cycle value)
      dutyCycle = (((float) userInput / 9.0f) * 255.0f);
      // set the duty cycle of pin 3
      analogWrite(PIN03, dutyCycle);
      start_time = millis();
      Serial.println("Changing speed...");
      while (millis() - start_time < 5000);
      Serial.println("Calculating RPM...");
      calculateMotorRpm();
      // print the data to the serial
      Serial.print(motor_rpm);
      Serial.println(" RPM");
    }
  }
}

void calculateMotorRpm() {
  // time to start counting the interrupts
  start_time = millis();
  // reset number of interrupts
  interrupts_count = 0;
  // count interrupts for one second
  while (millis() - start_time < 1000);
  // the motor rounds per minutes =
  // interrupts / 2 (pulses per revolution) * 60 (seconds)
  motor_rpm = interrupts_count / 2 * 60;
}
