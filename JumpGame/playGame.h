//
// Created by Gem Gasca on 2019-04-25.
//
#include <vector>
#include <algorithm>

#ifndef JUMPGAME_PLAYGAME_H
#define JUMPGAME_PLAYGAME_H


void makeJumps(std::vector<int>& vector, std::vector<int>& solutionVect, std::vector<int>& controlVect, unsigned int& pos);
void goLeft(std::vector<int>& V, std::vector<int>& solution, std::vector<int> newControl, unsigned int pos);
void goRight(std::vector<int>& V, std::vector<int>& solution, std::vector<int> newControl, unsigned int pos);


#endif //JUMPGAME_PLAYGAME_H
