const uint8_t PIN09 = 9;
uint8_t dutyCycle = 0;
uint8_t change = 5;

// the setup function runs once on power or reset
void setup() {
  // set pin 9 as output
  pinMode(PIN09, OUTPUT);
  // validate change value to be a factor of 255
  if (255 % change != 0)
    change = 5;
}

// the loop function loops forever
void loop() {
  // set the duty cycle of pin 9
  analogWrite(PIN09, dutyCycle);
  // change duty cycle each loop
  dutyCycle += change;
  // reverse direction of changing if limit reached
  if (dutyCycle == 0 || dutyCycle == 255)
      change *= -1;
  // smoothen the change effect
  delay(30);
}
