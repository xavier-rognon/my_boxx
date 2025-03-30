/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Multiplexer
*/


#pragma once

#include <array>
#include <cstdint>
#include <utility>
#include <vector>

#include <Arduino.h>

#include "Switch.hh"

typedef std::array<uint16_t, 16> inputArray_t;
typedef std::array<std::array<bool, 4>, 16> truthTable_t;

// INFO: This class is only working for the 74HC4067 multiplexer

namespace boxx {
    class Multiplexer {
    public:
        Multiplexer(const uint8_t &pinS0, const uint8_t &pinS1, const uint8_t &pinS2,
                    const uint8_t &pinS3, const uint8_t &pinAnalogue,
                    const uint8_t &nbInputs = 16);
        ~Multiplexer();

        void update();

        bool operator[](const uint8_t &index);
    private:
        uint8_t _nbInputs;
        truthTable_t _truthTable;
        std::array<uint8_t, 4> _controlPin;
        std::vector<Switch> _switches;
        uint8_t _pinAnalogue;
    };
}
