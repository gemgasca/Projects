//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include <map>
#include "BattleShipGame.h"
#include "AiPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::BattleShipGame::BattleShipGame(int numRows, int numCols, int numShips, std::vector<char>& shipChars,
                                           std::vector<int>& shipSizes, int gameType, int seed) : currentTurn(0),
                                           gameAttributes(GameAttributes(numRows, numCols, numShips, shipChars, shipSizes, gameType, seed)){

}

void BattleShip::BattleShipGame::playGame() {
    BattleShip::AiPlayer::seed_random_number_generator(gameAttributes.getSeed());
    initializePlayers();

    players[currentTurn]->getBoard().displayFiring(players[currentTurn]->getName());
    std::cout << "\n" << std::endl;
    players[currentTurn]->getBoard().displayPlacement(players[currentTurn]->getName());

    do {
        takeTurn(players, currentTurn);
    }while(!gameOver());
    changeTurn(currentTurn);
    std::cout << std::endl;
    printWinner(currentTurn);

}

void BattleShip::BattleShipGame::initializePlayers(){
    ShipPosition tempPosition;
    std::vector<Ship> ships;
    //create vector of ships
    for(int i = 0; i < gameAttributes.getNumShips(); i++){
        ships.emplace_back(Ship(gameAttributes.getShipSizes()[i], gameAttributes.getShipChars()[i], tempPosition));
    }

    int gameType = gameAttributes.getGameType();    //get game type

    if(gameType == 1){      // human vs human
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1)));
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 2)));
    }
    else if(gameType == 2){     // human vs ai
        this->players.push_back(std::unique_ptr<Player>(new HumanPlayer(gameAttributes, ships, 1)));
        int aiType = 0;
        do{
            std::cout << "What AI do you want?" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }
    }
    else{       // ai vs ai
        int aiType = 0;     // first ai
        do{
            std::cout << "What AI do you want?" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }

        aiType = 0;         // second ai
        do{
            std::cout << "What AI do you want?" << std::endl;
            std::cout << "1. Cheating AI" << std::endl;
            std::cout << "2. Random AI" << std::endl;
            std::cout << "3. Hunt Destroy AI" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> aiType;
        } while(aiType != 1 && aiType != 2 && aiType != 3);
        if(aiType == 1) {
            this->players.push_back(std::unique_ptr<Player>(new CheatingAI(gameAttributes, ships)));
        }
        else if(aiType == 2){
            this->players.push_back(std::unique_ptr<Player>(new RandomAI(gameAttributes, ships)));
        }
        else{
            this->players.push_back(std::unique_ptr<Player>(new HuntDestroyAI(gameAttributes, ships)));
        }
    }
}

void BattleShip::BattleShipGame::takeTurn(std::vector<std::unique_ptr<BattleShip::Player>>& players, int& currentTurn) {
    std::unique_ptr<BattleShip::Player>& player = players[currentTurn];

    int otherTurn = 0;
    if(currentTurn == 1){
        otherTurn = 0;
    }
    else{
        otherTurn = 1;
    }
    Move move = player->getPosition(players[currentTurn], players[otherTurn]);
    player->getBoard().makeMove(move, players[otherTurn], players[currentTurn]->getName());
    changeTurn(currentTurn);
}

void BattleShip::BattleShipGame::changeTurn(int& currentTurn) {
    if(currentTurn == 0){
        currentTurn = 1;
    }
    else {
        currentTurn = 0;
    }
}


bool BattleShip::BattleShipGame::gameOver() {
    for(int i = 0; i < 2; i++) {        // iterate over both players
        int numDestroyedShips = 0;
        for (auto &ship : players[i]->getShipHealths()) {
            // std::cout << ship.first << "\t" << ship.second << std::endl;
            if (ship.second == 0) {
                numDestroyedShips++;
            }
            if (numDestroyedShips == gameAttributes.getNumShips()) {
                return true;
            }
        }
    }
    return false;
}

void BattleShip::BattleShipGame::printWinner(int& currentTurn) {
    std::cout << players[currentTurn]->getName() <<" won the game!" << std::endl;
}