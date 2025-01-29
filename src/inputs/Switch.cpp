/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Switch
*/

#include "Switch.hh"

namespace boxx {
    Switch::Switch(uint8_t pin, float actuation):
        _pin(pin), _actuation(actuation), _baseline(0), _isPressed(false), _index(0)
    {
        pinMode(_pin, INPUT);
        _baseline = analogRead(_pin);
    }

    Switch::~Switch()
    {}

    void Switch::update()
    {
        _samples[_index] = analogRead(_pin);
        _index = (_index + 1) % AVG;
        int smoothedValue = getSmoothedValue();

        if (!_isPressed && smoothedValue < _baseline * _actuation)
            _isPressed = true;
        if (_isPressed && smoothedValue > _baseline * _actuation)
            _isPressed = false;
    }

    bool Switch::isPressed()
    {
        return _isPressed;
    }

    uint16_t Switch::getSmoothedValue()
    {
        uint16_t sum = 0;
        for (int i = 0; i < AVG; i++) {
            sum += _samples[i];
        }
        return sum / AVG;
    }
}
