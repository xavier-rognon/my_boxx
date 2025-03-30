/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Multiplexer
*/

#include "Multiplexer.hh"
#include "Arduino.h"
#include <cstdint>

namespace boxx {
    Multiplexer::Multiplexer(const uint8_t &pinS0, const uint8_t &pinS1,
                             const uint8_t &pinS2, const uint8_t &pinS3,
                             const uint8_t &pinAnalogue, const uint8_t &nbInputs):
        _nbInputs(nbInputs), _controlPin({pinS0, pinS1, pinS2, pinS3}),
        _switches(nbInputs), _pinAnalogue(pinAnalogue)
    {
        pinMode(_controlPin[0], OUTPUT);
        pinMode(_controlPin[1], OUTPUT);
        pinMode(_controlPin[2], OUTPUT);
        pinMode(_controlPin[3], OUTPUT);

        digitalWrite(_controlPin[0], LOW);
        digitalWrite(_controlPin[1], LOW);
        digitalWrite(_controlPin[2], LOW);
        digitalWrite(_controlPin[3], LOW);

        _truthTable = {
            {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {1,1,0,0},
            {0,0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0},
            {0,0,0,1}, {1,0,0,1}, {0,1,0,1}, {1,1,0,1},
            {0,0,1,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}
        };
    }

    Multiplexer::~Multiplexer()
    {}

    void Multiplexer::update()
    {
        for (int i = 0; i < _nbInputs; i++) {
            for (int j = 0; j < 4; j++)
                digitalWrite(_controlPin[j], _truthTable[i][j]);
            _switches[i].update(analogRead(_pinAnalogue));
        }
    }

    bool Multiplexer::operator[](const uint8_t &index)
    {
        if (index >= _nbInputs)
            return false;
        return _switches[index].isPressed();
    }
}
