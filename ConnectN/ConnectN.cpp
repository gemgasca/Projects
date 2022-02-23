//
// Created by Gem Gasca on 2019-04-30.
//

#include "ConnectN.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "stringStuff.h"

Board::Board(const int cols, const int rows, const int inRow) : cols(cols), rows(rows), inRow(inRow) {
    std::vector<std::vector<std::string>> board;        // makes vector of vector full of *'s
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board[i].push_back("*");
        }
    }
}

Player::Player(const std::string name, const std::string symbol) : name(name), symbol(symbol) {

}

void getAndSetNamesSymbols(){
    int numPlayer = 1;
    std::string input, name1, name2, symbol, symbol1, symbol2;
    while(true){
        std::cout << "Player " << numPlayer << ", please enter your name: ";
        getline(std::cin, input);
        rstripInPlace(input);
        if (CountWords(input) == 1 && numPlayer == 1){      // checks if user enters one word for name
            name1 = input;
            while(true){
                std::cout << name1 << ", please enter the character you want to use for your piece: ";
                getline(std::cin, symbol);
                rstripInPlace(symbol);
                if (symbol.length() == 1){
                    symbol1 = symbol;
                    break;
                }
            }
            numPlayer ++;
        }
        else if (CountWords(input) == 1 && numPlayer == 2 && name1 != input) {
            name2 = input;
            while(true){
                std::cout << name2 << ", please enter the character you want to use for your piece: ";
                getline(std::cin, symbol);
                rstripInPlace(symbol);
                if (symbol.length() == 1 && symbol != symbol1){
                    symbol2 = symbol;
                    break;
                }
            }
            break;
        } // end else if
    } // end of while
    Player(name1, symbol1);
    Player(name2, symbol2);

}

void changeBoard(Board &Board, int& board.row, int& board.col, std::string symbol) {

}

void printBoard(std::vector<std::vector<std::string>>& board) {
    int numCol = 7;     // change value
    std::cout << "  ";
    for (int i = 0; i < numCol; i++){std::cout << i << " ";}
    std::cout << "\n";
    int numRow = 5;     // change value
    for (int i = 0; i < board.size(); i++){
        std::cout << numRow << " ";
        numRow --;
        for (int j = 0; j < board[i].size(); j++){
            std::cout << board[i].at(j) << " ";
        }
        std::cout << "\n";
    }
}
