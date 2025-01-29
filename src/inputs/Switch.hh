/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Switch
*/


#pragma once

#include <Arduino.h>
#include <array>
#include <cstdint>

#define AVG 10

namespace boxx {
    class Switch {
    public:
        Switch(uint8_t pin, float actuation);
        ~Switch();

        void update();

        bool isPressed();
    private:
        uint16_t getSmoothedValue();

        uint8_t _pin;
        float _actuation;
        uint16_t _baseline;
        std::array<int, AVG> _samples;
        bool _isPressed;
        uint8_t _index;
    };
}
