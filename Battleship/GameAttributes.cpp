//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "GameAttributes.h"


BattleShip::GameAttributes::GameAttributes(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                                           std::vector<int>& shipSizes, int gameType, int seed) : numRows(numRows), numCols(numCols), numShips(numShips),
                                           shipChars(shipChars), shipSizes(shipSizes), gameType(gameType), seed(seed) {

}

const int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}

const int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

const int BattleShip::GameAttributes::getNumShips() const {
    return numShips;
}

const std::vector<char> &BattleShip::GameAttributes::getShipChars() const {
    return shipChars;
}

const std::vector<int> &BattleShip::GameAttributes::getShipSizes() const {
    return shipSizes;
}

const int BattleShip::GameAttributes::getGameType() const {
    return gameType;
}

const int BattleShip::GameAttributes::getSeed() const {
    return seed;
}