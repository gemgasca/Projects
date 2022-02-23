//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "Board.h"

BattleShip::Board::Board(const BattleShip::GameAttributes& gameAttributes) : firingBoard(gameAttributes.getNumRows(), std::string(gameAttributes.getNumCols(), '*')),
    placementBoard(gameAttributes.getNumRows(), std::string(gameAttributes.getNumCols(), '*')){}

int BattleShip::Board::getNumRows() {
    return placementBoard.size();
}

int BattleShip::Board::getNumCols() {
    return placementBoard[0].size();
}

void BattleShip::Board::AddShip(const BattleShip::Ship &ship, BattleShip::ShipPosition placement) {
    for(int i = placement.rowStart ; i <= placement.rowEnd; i++){
        for(int k = placement.colStart; k <= placement.colEnd; k++){
            placementBoard[i][k] = ship.getSymbol();
        }
    }
}

void BattleShip::Board::displayPlacementAi(std::string name) {
    std::cout << name << "'s Board" << std::endl;
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : placementBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}

void BattleShip::Board::displayFiringNoName() {
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : firingBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}

void BattleShip::Board::displayPlacementNoName() {
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : placementBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}

void BattleShip::Board::displayFiring(std::string name) {
    std::cout << name << "'s Firing Board" << std::endl;
    //print column headers
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : firingBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}

void BattleShip::Board::displayBlankBoard() {
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : firingBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}


void BattleShip::Board::displayPlacement(std::string name) {
    std::cout << name << "'s Placement Board" << std::endl;
    //print column headers
    std::cout << "  ";
    for (int i = 0; i < getNumCols(); ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int rowIndex = 0;
    for (const auto& row : placementBoard) {
        std::cout << rowIndex << ' ';
        for(const auto& elem : row){
            std::cout << elem << ' ';
        }
        rowIndex++;
        std::cout << std::endl;
    }
}

void BattleShip::Board::makeMove(BattleShip::Move& move, std::unique_ptr<BattleShip::Player>& otherPlayer, std::string name) {
    if(otherPlayer->getBoard().getPlacementBoard()[move.row][move.col] == '*'){
        this->firingBoard[move.row][move.col] = 'O';
        otherPlayer->getBoard().placementBoard[move.row][move.col] = 'O';
        this->displayFiring(name);
        std::cout << "\n" << std::endl;
        this->displayPlacement(name);
        std::cout << "Missed." << std::endl;
    }
    else{
        char shipChar = otherPlayer->getBoard().getPlacementBoard()[move.row][move.col];
        for(auto& ship : otherPlayer->getShipHealths()){
            if(ship.first == shipChar){
                ship.second = ship.second - 1;
            }
        }
        this->firingBoard[move.row][move.col] = 'X';
        otherPlayer->getBoard().placementBoard[move.row][move.col] = 'X';
        if(gameOver(otherPlayer)){

        }
        this->displayFiring(name);
        std::cout << "\n" << std::endl;
        this->displayPlacement(name);
        std::cout << name << " hit " << otherPlayer->getName() << "'s " << shipChar << "!" << std::endl;
        if(otherPlayer->getShipHealths()[shipChar] == 0){
            std::cout << name << " destroyed " << otherPlayer->getName() << "'s " << shipChar << "!" << std::endl;
        }
    }


    if (!gameOver(otherPlayer)) {
        std::cout << std::endl;
        otherPlayer->getBoard().displayFiring(otherPlayer->getName());
        std::cout << "\n" << std::endl;
        otherPlayer->getBoard().displayPlacement(otherPlayer->getName());
    }
}

bool BattleShip::Board::canPlaceShipAt(BattleShip::ShipPosition placement) {
    if(placement.rowStart < 0 || placement.rowStart > getNumRows()){
        return false;
    }
    if(placement.rowEnd < 0 || placement.rowEnd > getNumRows()){
        return false;
    }
    if(placement.colStart < 0 || placement.colStart > getNumCols()){
        return false;
    }
    if(placement.colEnd < 0 || placement.colEnd > getNumCols()){
        return false;
    }
    for(int row = placement.rowStart; row <= placement.rowEnd; row++){
        if(placementBoard[row][placement.colStart] != '*'){
            return false;
        }
    }
    for(int col = placement.colStart; col <= placement.colEnd; col++){
        if(placementBoard[placement.rowStart][col] != '*'){
            return false;
        }
    }
    return true;
}

BattleShip::Board::Board() : firingBoard(0, 0), placementBoard(0,0) {

}

bool BattleShip::Board::gameOver(std::unique_ptr<BattleShip::Player> &otherPlayer) {
    for(auto& element : otherPlayer->getShipHealths()){
        if(element.second != 0){
            return false;
        }
    }
    return true;
}