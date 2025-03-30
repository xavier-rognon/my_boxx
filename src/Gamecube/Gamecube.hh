/*
** EPITECH PROJECT, 2025
** my_boxx
** File description:
** Gamecube
*/

#pragma once

#include <Nintendo.h>

#include "../inputs/Multiplexer.hh"

#define ANALOG_UP multiplexer[0]->operator[](0)
#define ANALOG_DOWN multiplexer[0]->operator[](1)
#define ANALOG_LEFT multiplexer[0]->operator[](2)
#define ANALOG_RIGHT multiplexer[0]->operator[](3)
#define MOD_X multiplexer[0]->operator[](4)
#define MOD_Y multiplexer[0]->operator[](5)
#define A multiplexer[0]->operator[](6)
#define B multiplexer[0]->operator[](7)
#define X multiplexer[0]->operator[](8)
#define Y multiplexer[0]->operator[](9)
#define L multiplexer[0]->operator[](10)
#define R multiplexer[0]->operator[](11)
#define Z multiplexer[0]->operator[](12)
#define C_UP multiplexer[0]->operator[](13)
#define C_DOWN multiplexer[0]->operator[](14)
#define C_LEFT multiplexer[0]->operator[](15)
#define C_RIGHT multiplexer[1]->operator[](0)
#define LIGHT_SHIELD multiplexer[1]->operator[](2)
#define START multiplexer[1]->operator[](3)

namespace boxx {
    enum connectedTo {
        GAMECUBE,
        OTHER,
        NOT_CONNECTED
    };

    class Gamecube {
    public:
        Gamecube(const uint8_t &pin);
        ~Gamecube();

        void update();
    protected:
        void checkConnection();

        void communicateGamecube();
        void communicateOther();

        std::array<Multiplexer *, 2> multiplexers;
        connectedTo _connectedTo;
        CGamecubeConsole _console;
        Gamecube_Data_t inputs;
    };
}
