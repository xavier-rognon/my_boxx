/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Switch
*/

#include "Switch.hh"

namespace boxx {
    Switch::Switch(const uint8_t &pin, const float &actuation):
        _pin(pin), _actuation(actuation), _isPressed(false), _extremums({160, 400})
    {
        pinMode(_pin, INPUT);
    }

    Switch::~Switch()
    {}

    void Switch::update()
    {
        int value = analogRead(_pin);

        if (value < _extremums[0])
            _extremums[0] = value;
        if (value > _extremums[1])
            _extremums[1] = value;
        _isPressed = value - _extremums[0] < _actuation *
                     (_extremums[1] - _extremums[0]);
    }

    void Switch::update(const uint16_t &value)
    {
        if (value < _extremums[0])
            _extremums[0] = value;
        if (value > _extremums[1])
            _extremums[1] = value;
        _isPressed = value - _extremums[0] < _actuation *
                     (_extremums[1] - _extremums[0]);
    }

    bool Switch::isPressed()
    {
        return _isPressed;
    }
}
