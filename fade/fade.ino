int pin = 9;
int brightness = 0;
int fadeAmount = 5;

// the setup function runs once on power or reset
void setup() {
  // set pin 9 as output
  pinMode(pin, OUTPUT);
}

// the loop function loops forever
void loop() {
  // set the brightness of pin 9
  analogWrite(pin, brightness);
  // change brightness each loop
  brightness = brightness + fadeAmount;
  // reverse direction of fading at each end of the fade
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // smoothen the dimming effect
  delay(30);
}
