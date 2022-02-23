//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include "AiPlayer.h"

namespace BattleShip {
    class HuntDestroyAI : public AiPlayer{
    public:
        HuntDestroyAI(const GameAttributes& gameAttributes, std::vector<Ship> ships);
        ~HuntDestroyAI() override;
        //virtual void initializeName() override;
        //void setName(std::string name) override;
        void placeShips() override;
        std::vector<Move> makeRandomVector();
        std::vector<Move> makeDestroyVector();
        Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) override;
        BattleShip::Board& getBoard() override;
        std::vector<Move> makeVector();
        std::map<char, int>& getShipHealths() override;

    protected:
        Board board;
        std::map<char, int> shipHealths;
        //std::string name;
        std::vector<Ship> ships;
        int mode;
        Move lastHit;

    };
}

#endif //BATTLESHIP_HUNTDESTROYAI_H