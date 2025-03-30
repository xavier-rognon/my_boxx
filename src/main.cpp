#include <Arduino.h>
#include <cstdio>

#include "Gamecube/Gamecube.hh"

boxx::Gamecube *gamecube;

void setup() {
    gamecube = new boxx::Gamecube(7);
    Serial.begin(9600);
}

void loop() {
    gamecube->update();
}
