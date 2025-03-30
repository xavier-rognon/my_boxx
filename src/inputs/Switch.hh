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

namespace boxx {
    class Switch {
    public:
        Switch(const uint8_t &pin = 0, const float &actuation = 0.9);
        ~Switch();

        void update();
        void update(const uint16_t &value);

        bool isPressed();
    private:
        uint8_t _pin;
        float _actuation;
        bool _isPressed;
        std::array<uint16_t, 2> _extremums; // INFO: 0 is min, 1 is max
    };
}
