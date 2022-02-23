//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include <random>
#include "Player.h"
#include "Utility.h"
#include "Board.h"


namespace BattleShip {
class Move;
class AiPlayer : public Player {
     public:
        AiPlayer();
        ~AiPlayer() override;
        AiPlayer(const BattleShip::GameAttributes& gameAttributes, std::vector<Ship> ships, int aiId);
        static void seed_random_number_generator(int seed);
        virtual void placeShips() override = 0;
        virtual void initializeName() override;
        virtual BattleShip::Board& getBoard() override=0;
        virtual void setName(std::string name);
        std::string getName() override;
        virtual Move getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) override{Move move; return move;};
        virtual std::map<char, int>& getShipHealths() override=0;

     protected:
        static std::mt19937 randomNumberGenerator;

     private:
        static int nextAiId;
        const int aiId;
        std::vector<Ship> ships;
        std::string name;
    };
}
#endif //BATTLESHIP_AIPLAYER_H