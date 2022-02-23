//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <map>
#include <memory>
#include "Ship.h"
#include "Move.h"
#include "GameAttributes.h"

namespace BattleShip {
    class Board;
    class Player {
    public:
        virtual ~Player();
        virtual void placeShips()=0;
        virtual void initializeName()=0;
        virtual Board& getBoard()=0;
        virtual std::string getName()=0;
        virtual Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer)=0;
        virtual std::map<char, int>& getShipHealths()=0;
    };
}
#endif //BATTLESHIP_PLAYER_H