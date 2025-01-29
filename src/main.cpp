#include <Arduino.h>

#include "USBAPI.h"
#include "inputs/Switch.hh"

boxx::Switch *mySwitch;

void setup() {
    Serial.begin(9600); // Start serial communication
    delay(1000); // Allow time for stabilization

    mySwitch = new boxx::Switch(A3, 0.9);
}

void loop() {
    mySwitch->update();
    if (mySwitch->isPressed()) {
        Serial.println("Pressed");
    } else {
        Serial.println("Not pressed");
    }
}
