/*
** EPITECH PROJECT 2025
** my_boxx
** File description:
** input
*/

#pragma once

#include <ArduinoSTL.h>

#define INPUTS 20;

#define ANALOG_UP 0
#define ANALOG_DOWN 1
#define ANALOG_LEFT 2
#define ANALOG_RIGHT 3
#define MOD_X 4
#define MOD_Y 5
#define A 6
#define B 7
#define X 8
#define Y 9
#define L 10
#define R 11
#define Z 12
#define C_UP 13
#define C_DOWN 14
#define C_LEFT 15
#define C_RIGHT 16
#define LIGHT_SHIELD 17
#define START 19

namespace boxx {
    class Input {
    public:
        Input();
        ~Input();
        void checkIfInputArePressed(int *analogValues);
        bool *getInputs() const;
    private:
        bool *_inputs;
    };
}
