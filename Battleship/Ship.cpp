//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "Ship.h"

BattleShip::Ship::Ship(int size, char symbol, BattleShip::ShipPosition position) :  size(size), symbol(symbol), position(position){

}

const int BattleShip::Ship::getSize() const {
    return size;
}

char BattleShip::Ship::getSymbol() const {
    return symbol;
}

const BattleShip::ShipPosition &BattleShip::Ship::getPosition() const {
    return position;
}