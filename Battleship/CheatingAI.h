//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
    class CheatingAI : public AiPlayer {
    public:
        CheatingAI(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        ~CheatingAI() override;
//        virtual void initializeName() override;
//        void setName(std::string name) override ;
        void placeShips() override;
        BattleShip::Board& getBoard() override;
        Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) override;
        std::map<char, int>& getShipHealths() override;
        std::vector<BattleShip::Move> makeVector(std::unique_ptr<BattleShip::Player>& otherPlayer);
    protected:
        Board board;
        std::map<char, int> shipHealths;
        std::string name;
        std::vector<Ship> ships;
    };
}
#endif //BATTLESHIP_CHEATINGAI_H