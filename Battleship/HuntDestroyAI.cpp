//
// Created by Lucas Rodriguez on 2019-06-04.
//

#include "HuntDestroyAI.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship> ships)
    :  board(gameAttributes) ,ships(ships), mode(1), lastHit(-1, -1){
    this->initializeName();
    for(int i = 0; i < static_cast<int>(ships.size()); i++){
        shipHealths[ships[i].getSymbol()] = gameAttributes.getShipSizes()[i];
    }
    placeShips();
}
std::vector<BattleShip::Move> BattleShip::HuntDestroyAI::makeVector() {
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

std::map<char, int>& BattleShip::HuntDestroyAI::getShipHealths() {
    return shipHealths;
}

BattleShip::Move BattleShip::HuntDestroyAI::getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) {
    std::vector<Move> possibleMoves;
    if(this->mode == 2){
        possibleMoves = makeDestroyVector();
        if(possibleMoves.empty()){
            this->mode = 1;
        }
        else {
            Move aiMove = possibleMoves[0];
            if(otherPlayer->getBoard().getPlacementBoard()[aiMove.row][aiMove.col] != '*'){
                lastHit = aiMove;
            }
            return possibleMoves[0];
        }
    }
    if(this->mode == 1){
        possibleMoves = makeRandomVector();
        int randInt = getRandInt(0, possibleMoves.size() - 1, randomNumberGenerator);
        Move aiMove = possibleMoves[randInt];
        if(otherPlayer->getBoard().getPlacementBoard()[aiMove.row][aiMove.col] != '*'){
            lastHit = aiMove;
            this->mode = 2;
        }
        return possibleMoves[randInt];
    }
    else{
        return Move(0, 0);
    }
}

BattleShip::Board &BattleShip::HuntDestroyAI::getBoard() {
    return board;
}

BattleShip::HuntDestroyAI::~HuntDestroyAI() {

}

void BattleShip::HuntDestroyAI::placeShips() {
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

std::vector<BattleShip::Move> BattleShip::HuntDestroyAI::makeRandomVector() {
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

std::vector<BattleShip::Move> BattleShip::HuntDestroyAI::makeDestroyVector() {
    int row = this->lastHit.row;
    int col = this->lastHit.col;
    Move tempMove;
    std::vector<Move> possibleMoves;
    if(col - 1 >= 0 && getBoard().getFiringBoard()[row][col - 1] == '*'){
        tempMove = Move(row, col - 1);
        possibleMoves.push_back(tempMove);
    }
    if(row - 1 >= 0 && getBoard().getFiringBoard()[row - 1][col] == '*'){
        tempMove = Move(row - 1, col);
        possibleMoves.push_back(tempMove);
    }
    if(col + 1 < getBoard().getNumCols() && getBoard().getFiringBoard()[row][col + 1] == '*'){
        tempMove = Move(row, col+ 1);
    }
    if(row + 1 < getBoard().getNumRows() && getBoard().getFiringBoard()[row + 1][col] == '*'){
        tempMove = Move(row + 1, col);
        possibleMoves.push_back(tempMove);
    }

    return possibleMoves;
}
