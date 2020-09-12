int pin = 9;
int brightness = 0;
int fadeAmount = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  // set pin 9 as output
  pinMode(pin, OUTPUT);
}

// the loop function runs over and over again forever
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
