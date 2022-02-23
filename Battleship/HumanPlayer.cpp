//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include <map>
#include "HumanPlayer.h"


BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, std::vector<BattleShip::Ship>& ships, int playerNumber) :
        board(gameAttributes), shipHealths(), ships(ships){
    std::cout << "Player " << playerNumber << " please enter your name: ";
    std::cin >> this->name;
    for(int i = 0; i < static_cast<int>(ships.size()); i++){
        shipHealths[ships[i].getSymbol()] = gameAttributes.getShipSizes()[i];
    }
    this->placeShips();
}

void BattleShip::HumanPlayer::placeShips() {
    char orientation;

    ShipPosition placement;
    getBoard().displayBlankBoard();
    for(const auto& ship : ships) {
        do {
            std::cout<< this->name << ", do you want to place " << ship.getSymbol() << " horizontally or vertically?" << std::endl;
            std::cout << "Enter h for horizontal or v for vertical" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> orientation;
            if (orientation == 'h') {
                std::cout << this->name << ", enter the row and column you want to place " << ship.getSymbol() << ", which is " << ship.getSize() << " long, at with a space in between row and col: ";
                std::cin >> placement.rowStart;
                std::cin >> placement.colStart;
                placement.rowEnd = placement.rowStart;
                placement.colEnd = placement.colStart + ship.getSize() - 1;

            } else if (orientation == 'v'){
                std::cout << this->name << ", enter the row and column you want to place " << ship.getSymbol() << ", which is " << ship.getSize() << " long, at with a space in between row and col: ";
                std::cin >> placement.rowStart;
                std::cin >> placement.colStart;
                placement.rowEnd = placement.rowStart + ship.getSize() - 1;
                placement.colEnd = placement.colStart;
            }
            else{
                continue;
            }
        }while(!getBoard().canPlaceShipAt(placement));
        getBoard().AddShip(ship, placement);
        getBoard().displayPlacementNoName();
    }
}

std::string BattleShip::HumanPlayer::getName() {
    return name;
}

BattleShip::Move BattleShip::HumanPlayer::getPosition(std::unique_ptr<BattleShip::Player>& player, std::unique_ptr<BattleShip::Player>& otherPlayer) {
    int row, col;
    do {
        std::cout << getName() << ", where would you like to fire?" << std::endl;
        std::cout << "Enter your attack coordinate in the form row col: ";
        std::cin >> row;
        std::cin >> col;
    }while(row > getBoard().getNumRows() || col > getBoard().getNumCols() || !validMove(row, col));
    Move temp = Move(row, col);
    return temp;
}

bool BattleShip::HumanPlayer::validMove(int row, int col) {
    return getBoard().getFiringBoard()[row][col] == '*';
}

std::map<char, int>& BattleShip::HumanPlayer::getShipHealths() {
    return shipHealths;
}

BattleShip::Board &BattleShip::HumanPlayer::getBoard() {
    return board;
}

void BattleShip::HumanPlayer::initializeName() {
    return;
}

BattleShip::HumanPlayer::~HumanPlayer() {
}