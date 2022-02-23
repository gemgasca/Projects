//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H
#include "ShipPosition.h"

namespace BattleShip {
    class Ship {
    public:
        Ship(int size, char symbol, ShipPosition position);
        const int getSize() const;
        char getSymbol() const;
        const ShipPosition &getPosition() const;


    private:
        //bool destroyed;
        const int size;
        const char symbol;
        ShipPosition position;
    };
}

#endif //BATTLESHIP_SHIP_H