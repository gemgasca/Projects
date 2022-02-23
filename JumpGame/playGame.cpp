//
// Created by Gem Gasca on 2019-04-25.
//

#include "playGame.h"
#include "JumpGame.h"
#include <vector>
#include <algorithm>
#include <iostream>

void makeJumps(std::vector<int>& vector, std::vector<int>& solutionVect, std::vector<int>& controlVect, unsigned int& pos){
    if (pos == vector.size()-1) {
        if (bestAnswer(solutionVect, controlVect)) {
            setBestAnswer(solutionVect, controlVect);
        }
    }
    goLeft(vector, solutionVect, controlVect, pos);
    goRight(vector, solutionVect, controlVect, pos);
}

void goLeft(std::vector<int>& V, std::vector<int>& solution, std::vector<int> newControl, unsigned int pos){
    if (attemptLeft(V, pos)){
        auto x = pos - V[pos];
        if (checkEndlessLoopLeft(V, pos, x)) {
            auto move = pos - V[pos];
            if (std::find(newControl.begin(), newControl.end(), move) != newControl.end()) {
                return;
            } else {
                pos -= V[pos];
                newControl.push_back(pos);
            }
            goLeft(V, solution, newControl, pos);
            goRight(V, solution, newControl, pos);
        }
    }
    else{
        return;
    }
}

void goRight(std::vector<int>& V, std::vector<int>& solution, std::vector<int> newControl, unsigned int pos){
    if (attemptRight(V, pos)) {
        auto x = pos + V[pos];
        if (checkEndlessLoopRight(V, pos, x)){
            auto  move = pos + V[pos];
            if (std::find(newControl.begin(), newControl.end(), move) != newControl.end()){
                return;
            }
            else{
                pos += V[pos];
                newControl.push_back(pos);
            }
            goLeft(V, solution, newControl, pos);
            goRight(V, solution, newControl, pos);
            }
    }
    else{
        return;
    }

    if (pos == V.size()-1){
        if (bestAnswer(solution, newControl)) {
            setBestAnswer(solution, newControl);
        }
        return;
    }
}