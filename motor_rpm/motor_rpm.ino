volatile uint8_t interruptsCount = 0;
volatile uint64_t startTime = 0;
uint16_t motorRpm = 0;

// the setup function runs once on power or reset
void setup() {
  // attach interrupt to increment interruptsCount on RISING signal on pin 2
  attachInterrupt(digitalPinToInterrupt(2), [](){++interruptsCount;}, RISING);
  // begin the serial for data transmission
  Serial.begin(9600);
  Serial.println("Motor speed (press any key to start):");
}

// the loop function loops forever
void loop() {
  // if there is a serial
  if (Serial.available()) {
    // time to start counting the interrupts
    startTime = millis();
    // reset number of interrupts
    interruptsCount = 0;
    // count interrupts for one second
    while (millis() - startTime < 1000);
    // the motor rounds per minutes =
    // interrupts / 2 (pulses per revolution) * 60 (seconds)
    motorRpm = interruptsCount / 2 * 60;
    // print the motor RPM to the serial
    Serial.print(motorRpm);
    Serial.println(" RPM");
  }
}
