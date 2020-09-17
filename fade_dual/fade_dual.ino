const uint8_t PIN09 = 9;
const uint8_t PIN10 = 10;
uint8_t dutyCycle = 0;
uint8_t change = 5;

// the setup function runs once on power or reset
void setup() {
  // set pins as output
  pinMode(PIN09, OUTPUT);
  pinMode(PIN10, OUTPUT);
  // validate change value to be a factor of 255
  if (255 % change != 0)
    change = 5;
}

// the loop function loops forever
void loop() {
  // set the duty cycle of pins
  analogWrite(PIN09, dutyCycle);
  // inverting using bitwise NOT
  analogWrite(PIN10, ~dutyCycle);
  // change the duty cycle each loop
  dutyCycle += change;
  // reverse direction of changing if limit reached
  if (dutyCycle == 0 || dutyCycle == 255)
    change *= -1;
  // smoothen the change effect
  delay(30);
}
