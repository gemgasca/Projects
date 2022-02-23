//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include "AiPlayer.h"


namespace BattleShip{
    class RandomAI : public AiPlayer {
    public:
        RandomAI(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        ~RandomAI() override;
//        virtual void initializeName() override;
        void placeShips() override;
//        void setName(std::string name) override ;
        Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) override;
        BattleShip::Board& getBoard() override;
        std::vector<Move> makeVector();
        std::map<char, int>& getShipHealths() override;


    protected:
        Board board;
        std::map<char, int> shipHealths;
        //std::string name;
        std::vector<Ship> ships;

    };
}

#endif //BATTLESHIP_RANDOMAI_H