//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "CheatingAI.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
        : board(gameAttributes), ships(ships){
    this->initializeName();
    for(int i = 0; i < static_cast<int>(ships.size()); i++){
        shipHealths[ships[i].getSymbol()] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}

void BattleShip::CheatingAI::placeShips() {
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

std::map<char, int>& BattleShip::CheatingAI::getShipHealths() {
    return shipHealths;
}

std::vector<BattleShip::Move> BattleShip::CheatingAI::makeVector(std::unique_ptr<BattleShip::Player>& otherPlayer) {
    std::vector<Move> possibleMoves;
    for(int i = 0; i < getBoard().getNumRows(); i++){
        for(int k = 0; k < getBoard().getNumCols(); k++){
            for(auto ship : shipHealths) {
                if (otherPlayer->getBoard().getPlacementBoard()[i][k] == ship.first) {
                    Move temp(i, k);
                    possibleMoves.push_back(temp);
                }
            }
        }
    }
    return possibleMoves;
}

BattleShip::Move BattleShip::CheatingAI::getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) {
    std::vector<Move> possibleMoves = makeVector(otherPlayer);
    return possibleMoves[0];
}

BattleShip::Board &BattleShip::CheatingAI::getBoard() {
    return board;
}

BattleShip::CheatingAI::~CheatingAI() {
}