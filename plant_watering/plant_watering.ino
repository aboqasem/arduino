#include <Arduino.h>

// water pump pin
#define PIN_PUMP 3
// moisture sensor pin
#define PIN_MOISTURE_SENSOR 14
// water pump triggering point
#define TRIGGER_MOISTURE 350
// good moisture level
#define GOOD_MOISTURE 700
// interval for dry soil checking (12 hours)
#define INTERVAL_CHECK_DRY 43200000
// interval for wet soil checking (1 second)
#define INTERVAL_CHECK_WET 1000

// moisture value variable
uint16_t moisture = 0;

// the setup function runs once on power or reset
void setup() {
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    // attach water pump to its pin
    pinMode(PIN_PUMP, OUTPUT);
    digitalWrite(PIN_PUMP, LOW);
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    // attach moisture sensor to its pin
    pinMode(PIN_MOISTURE_SENSOR, INPUT);
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    // begin serial connection for data transmission
    Serial.begin(9600);
    if (Serial) {
        Serial.println(F("System started..."));
        Serial.println();
        Serial.println(F("---- Sensor Output ----"));
        Serial.println(F("  0~300       Dry soil"));
        Serial.println(F("300~700       Humid soil"));
        Serial.println(F("700~950       Water"));
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
}

// the loop function loops forever
void loop() {
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    moisture = analogRead(PIN_MOISTURE_SENSOR);
    // wait until the moisture level becomes low
    while (moisture > TRIGGER_MOISTURE) {
        // print moisture level
        if (Serial) {
            Serial.print(F("Moisture level: "));
            Serial.println(moisture);
        }
        // delay rechecking for an interval to save power
        delay(INTERVAL_CHECK_DRY);
        moisture = analogRead(PIN_MOISTURE_SENSOR);
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    //  turn the water pump on maximum speed
    analogWrite(PIN_PUMP, 255);
    if (Serial) {
        Serial.println(F(" - PUMP ON -"));
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    moisture = analogRead(PIN_MOISTURE_SENSOR);
    // wait until the moisture level becomes good
    while (moisture < GOOD_MOISTURE) {
        // print moisture level
        if (Serial) {
            Serial.print(F("Moisture level: "));
            Serial.println(moisture);
        }
        // delay rechecking for an interval to save power
        delay(INTERVAL_CHECK_WET);
        moisture = analogRead(PIN_MOISTURE_SENSOR);
    }
    // turn the pump off
    digitalWrite(PIN_PUMP, LOW);
    if (Serial) {
        Serial.println(F(" - PUMP OFF -"));
    }
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
}
