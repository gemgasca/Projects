//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <string>
#include <memory>
#include "GameAttributes.h"
#include "ShipPosition.h"
#include "Ship.h"
#include "Move.h"
#include "Player.h"

namespace BattleShip {
    class Player;
    class Board {
    public:
        Board();
        Board(const GameAttributes& gameAttributes);
        void displayFiring(std::string name);
        void displayFiringNoName();
        void displayPlacement(std::string name);
        void displayPlacementNoName();
        void displayBlankBoard();
        void displayPlacementAi(std::string name);
        int getNumRows();
        int getNumCols();
        bool canPlaceShipAt(ShipPosition placement);
        void AddShip(const Ship& ship, ShipPosition placement);
        std::vector<std::string> getFiringBoard(){ return firingBoard; }
        std::vector<std::string> getPlacementBoard(){ return placementBoard; }
        bool gameOver(std::unique_ptr<BattleShip::Player>& otherPlayer);
        void makeMove(BattleShip::Move& move, std::unique_ptr<BattleShip::Player>& otherPlayer, std::string name);
    private:
        std::vector<std::string> firingBoard;
        std::vector<std::string> placementBoard;
    };
}

#endif //BATTLESHIP_BOARD_H