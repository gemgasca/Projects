//
// Created by Gem Gasca on 2019-04-30.
//
#include <string>

#ifndef CONNECTN_CONNECTN_H
#define CONNECTN_CONNECTN_H


class Board {
public:
    Board(const int cols, const int rows, const int inRow);
    int cols, rows, inRow;
};

class Player{
public:
    Player(const std::string name, const std::string symbol);
    std::string name;
    std::string symbol;

};

void printBoard(Board &Board);
void printBoard(std::vector<std::vector<std::string>>& board);
void changeBoard(Board& Board);
void getAndSetNamesSymbols();

#endif //CONNECTN_CONNECTN_H
