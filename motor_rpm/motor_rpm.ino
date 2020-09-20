#include "util.h"
#include "motor.h"

uint8_t useSerialMonitor = 0;

// the setup function runs once on power or reset
void setup() {
  // attach motor to pin 2
  attachMotor(2);
  // begin serial connection for data transmission
  Serial.begin(9600);
  // allow user to choose serial monitor usability within the
  // first 3 seconds of power/reset by pressing any key
  setSerialUsability(useSerialMonitor);
  if (useSerialMonitor)
    Serial.println("Motor speed:");
}

// the loop function loops forever
void loop() {
  if (useSerialMonitor) {
    Serial.print(getMotorRpm());
    Serial.println(" RPM");
  }
}
