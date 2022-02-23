#include <iostream>
#include <vector>
#include <fstream>
#include "BattleShipGame.h"

int main(int argC, char** argV) {
    //GET ALL THE ARGUMENTS FROM CONFIGURATION FILE
    int numRows, numCols, numShips, tempShipSize;
    char tempShipChar;
    std::vector<char> shipChars;
    std::vector<int> shipSizes;
    std::ifstream configFile;
    configFile.open(argV[1]);
    configFile >> numRows;
    configFile >> numCols;
    configFile >> numShips;
    while(configFile){
        configFile >> tempShipChar;
        configFile >> tempShipSize;
        shipChars.push_back(tempShipChar);
        shipSizes.push_back(tempShipSize);
    }

    //get seed
    int seed = time(nullptr);
    if(argC == 3){
        seed = std::stoi(argV[2]);
    }

    int gameType = 0;
    do {
        std::cout << "What type of game do you want to play?" << std::endl;
        std::cout << "1. Human vs Human" << std::endl;
        std::cout << "2. Human vs AI" << std::endl;
        std::cout << "3. AI vs AI" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> gameType;
    } while(gameType != 1 && gameType != 2 && gameType != 3);

    //create the game
    BattleShip::BattleShipGame game(numRows, numCols, numShips, shipChars, shipSizes, gameType, seed);

    //play it
    game.playGame();

}