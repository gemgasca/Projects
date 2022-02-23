//
// Created by Lucas Rodriguez on 2019-06-03.
//

#include "ShipPosition.h"

BattleShip::ShipPosition::ShipPosition(int rowStart, int colStart, int rowEnd, int colEnd) :
     rowStart(rowStart), colStart(colStart), rowEnd(rowEnd), colEnd(colEnd){

}


BattleShip::ShipPosition::ShipPosition() :
                                           rowStart(-1), colStart(-1), rowEnd(-1), colEnd(-1) {

}