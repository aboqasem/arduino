// the setup function runs once on power or reset
void setup() {
  // set pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function loops forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
}
