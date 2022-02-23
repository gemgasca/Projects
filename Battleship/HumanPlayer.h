//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include <memory>
#include "Player.h"
#include "Board.h"

namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(const GameAttributes& gameAttributes, std::vector<Ship>& ships, int playerNumber);
        ~HumanPlayer() override;
        void placeShips() override;
        std::string getName() override;
        Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) override;
        BattleShip::Board& getBoard() override;
        bool validMove(int row, int col);
        std::map<char, int>& getShipHealths() override;
        void initializeName() override;
        
    protected:
        Board board;
        std::map<char, int> shipHealths;
        std::string name;
        std::vector<BattleShip::Ship> ships;
    };
}

#endif //BATTLESHIP_HUMANPLAYER_H