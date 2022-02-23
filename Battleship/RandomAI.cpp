//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "RandomAI.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
        :  board(gameAttributes),ships(ships){
    this->initializeName();
    for(int i = 0; i < static_cast<int>(ships.size()); i++){
        shipHealths[ships[i].getSymbol()] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

std::map<char, int>& BattleShip::RandomAI::getShipHealths() {
    return shipHealths;
}

BattleShip::Move BattleShip::RandomAI::getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) {
    std::vector<Move> possibleMoves = makeVector();
    int randInt = getRandInt(0, possibleMoves.size() - 1, randomNumberGenerator);
    return possibleMoves[randInt];
}

std::vector<BattleShip::Move> BattleShip::RandomAI::makeVector() {
    std::vector<Move> possibleMoves;
    for(int i = 0; i < getBoard().getNumRows(); i++){
        for(int k = 0; k < getBoard().getNumCols(); k++){
            if(getBoard().getFiringBoard()[i][k] == '*'){
                Move temp(i, k);
                possibleMoves.push_back(temp);
            }
        }
    }
    return possibleMoves;
}

BattleShip::Board &BattleShip::RandomAI::getBoard() {
    return board;
}

BattleShip::RandomAI::~RandomAI() {

}

void BattleShip::RandomAI::placeShips() {
    std::vector<char> orientation_choice{'h', 'v'};
    const int numRows = getBoard().getNumRows();
    const int numCols = getBoard().getNumCols();

    ShipPosition placement;
    //getBoard().displayBlankBoard();
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
