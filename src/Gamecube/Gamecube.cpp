/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Gamecube
*/

#include "Gamecube.hh"

namespace boxx {
    Gamecube::Gamecube(const uint8_t &pin):
        _connectedTo(NOT_CONNECTED), _console(pin)
    {
        multiplexers[0] = new Multiplexer(2, 3, 4, 5, A0, 2);
        multiplexers[1] = nullptr;
    }

    Gamecube::~Gamecube()
    {
        delete multiplexers[0];
    }

    void Gamecube::update()
    {
        multiplexers[0]->update();

        if (_connectedTo == NOT_CONNECTED)
            checkConnection();
        _connectedTo == GAMECUBE ? communicateGamecube() : communicateOther();
    }

    void Gamecube::checkConnection()
    {
        Gamecube_Data_t temp = defaultGamecubeData;

        _console.write(temp) == true ? _connectedTo = GAMECUBE : _connectedTo = OTHER;
    }

    void Gamecube::communicateGamecube()
    {
        inputs = defaultGamecubeData;

        multiplexers[0]->operator[](0) ? inputs.report.a = 1 : inputs.report.a = 0;
        multiplexers[0]->operator[](1) ? inputs.report.b = 1 : inputs.report.b = 0;
        _console.write(inputs);
    }

    void Gamecube::communicateOther()
    {
    }
}
