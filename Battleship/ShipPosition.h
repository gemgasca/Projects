//
// Created by Lucas Rodriguez on 2019-06-03.
//

#ifndef BATTLESHIP_SHIPPOSITION_H
#define BATTLESHIP_SHIPPOSITION_H

namespace BattleShip {
    class ShipPosition {
    public:
        ShipPosition(int rowStart, int startCol, int rowEnd, int colEnd);
        ShipPosition();

        int rowStart;
        int colStart;
        int rowEnd;
        int colEnd;

    };
}

#endif //BATTLESHIP_SHIPPOSITION_H
