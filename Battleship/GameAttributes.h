//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H
#include <vector>
#include <iostream>

namespace BattleShip {
    class GameAttributes {
    public:
        GameAttributes(int numRows, int numCols, int numShips, std::vector<char>& shipChars, std::vector<int>& shipSizes, int gameType, int seed);
        const int getNumRows() const;
        const int getNumCols() const;
        const int getNumShips() const;
        const std::vector<char> &getShipChars() const;
        const std::vector<int> &getShipSizes() const;
        const int getGameType() const;
        const int getSeed() const;

    private:
        const int numRows;
        const int numCols;
        const int numShips;
        const std::vector<char> shipChars;
        const std::vector<int> shipSizes;
        const int gameType;
        const int seed;
    };
}

#endif //BATTLESHIP_GAMEATTRIBUTES_H