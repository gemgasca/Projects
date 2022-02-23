//
// Created by Lucas Rodriguez on 2019-06-04.
//

#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H

namespace BattleShip {
    class Move {
    public:
        Move();
        Move(int row, int col);
        int row;
        int col;
    };
}

#endif //BATTLESHIP_MOVE_H