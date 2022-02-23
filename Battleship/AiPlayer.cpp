//
// Created by mfbut on 3/9/2019.
//
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "AiPlayer.h"
#include "ShipPosition.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

int BattleShip::AiPlayer::nextAiId = 1;
std::mt19937 BattleShip::AiPlayer::randomNumberGenerator((time(nullptr)));

BattleShip::AiPlayer::AiPlayer() : aiId(nextAiId){
    nextAiId++;
}

BattleShip::AiPlayer::AiPlayer(const BattleShip::GameAttributes& gameAttributes, std::vector<Ship> ships, int aiId) : aiId(aiId), ships(ships){
    int aiType = 0;
    do{
        std::cout << "What AI do you want?" << std::endl;
        std::cout << "1. Cheating AI" << std::endl;
        std::cout << "2. Random AI" << std::endl;
        std::cout << "3. Hunt Destroy AI" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> aiType;
    } while(aiType != 1 && aiType != 2 && aiType != 3);
    if(aiType == 1){
        std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships));
    }
    else if(aiType == 2){
        std::unique_ptr<Player>(new RandomAI(gameAttributes, ships));
    }
    else{
        std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships));
    }
}

void BattleShip::AiPlayer::placeShips() {
  std::vector<char> orientation_choice{'h', 'v'};
  const int numRows = getBoard().getNumRows();
  const int numCols = getBoard().getNumCols();

    ShipPosition placement;
    for(const auto& ship : ships) {
        do {
            char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
            if (orientation == 'h') {
                placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - ship.getSize(), randomNumberGenerator);
                placement.rowEnd = placement.rowStart;
                placement.colEnd = placement.colStart + ship.getSize() - 1;
            } else {
                placement.rowStart = getRandInt(0, numRows - ship.getSize(), randomNumberGenerator);
                placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
                placement.rowEnd = placement.rowStart + ship.getSize() - 1;
                placement.colEnd = placement.colStart;
            }
        }while(!getBoard().canPlaceShipAt(placement));
        getBoard().AddShip(ship, placement);
        getBoard().displayPlacementAi(this->getName());
    }
}

void BattleShip::AiPlayer::initializeName() {
  std::stringstream tempName;
  tempName << "AI " << aiId;
  setName(tempName.str());
}

void BattleShip::AiPlayer::seed_random_number_generator(int seed) {
  BattleShip::AiPlayer::randomNumberGenerator.seed(seed);
}

void BattleShip::AiPlayer::setName(std::string tempName) {
    this->name = tempName;
}

std::string BattleShip::AiPlayer::getName() {
    return name;
}

BattleShip::AiPlayer::~AiPlayer() {
}