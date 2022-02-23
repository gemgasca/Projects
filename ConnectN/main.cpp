#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "stringStuff.h"
#include "ConnectN.h"


int main(int argc, char** argv) {
    int rows = std::stoi(argv[1]);
    int cols = std::stoi(argv[2]);
    int inRow = std::stoi(argv[3]);

    std::string string = "*";
    std::vector<std::vector<std::string> > board;        // makes vector of vector full of *'s
    for (int i = 0; i < rows; i++) {
        board.push_back(std::vector<std::string>());
        for (int j = 0; j < cols; j++)
            board[i].push_back(string);
    }

//    Board(cols, rows, inRow);                 // doesn't work -- infinite loop???
//    getAndSetNamesSymbols();


// TOP DOWN METHOD
// MAKE BOARD
// GET NAMES
// {    MAKE PLAYER 1 GO
//      CHECK FOR WIN
//      MAKE PLAYER 2 GO
//      CHECK FOR WIN       }
// LOOP UNTIL SOMEONE WINS

    printBoard(board);

    return 0;
}

