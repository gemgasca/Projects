//
// Created by Gem Gasca on 2019-04-15.
//
#include "JumpGame.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

// takes reference to vector with current best answer and possible new best answer
// returns true if new solution is shorter than current best solution, false otherwise
bool bestAnswer(std::vector<int>& bestAnswer, std::vector<int> newVector){
    if (bestAnswer.size() > newVector.size()){
        return true;
    }
    return false;
}

// takes reference to vector with current best answer and new best answer
// clears best vector and adds all elements of new solution to best solution
void setBestAnswer(std::vector<int>& bestAnswer, std::vector<int> newVector){
    bestAnswer.clear();
    for (int elem : newVector){
        bestAnswer.push_back(elem);
    }
}


// takes vector reference and position at currently
// returns false if desired jump + position is too far left (out of bounds), true otherwise
bool attemptLeft(std::vector<int>& vector, int currentPos){
        int jumps = vector.at(currentPos);
        if (currentPos-jumps < 0) {
            return false;
        }
        return true;
}

// takes reference to vector, current position, and desired position
// returns true if making jump will not result in endless loop
// returns false if making jump will return in endless loop
bool checkEndlessLoopLeft(std::vector<int>& vector, const int currentPos, const int newPos){
    int jumps2 = vector.at(newPos);
    if (attemptLeft(vector, newPos)){
        return true;
    }
    if ((newPos + jumps2) == currentPos){
        return false;
    }
    return true;
}

bool checkEndlessLoopRight(std::vector<int>& vector, const int currentPos, const int newPos){
    int jumps2 = vector.at(newPos);
    if (attemptRight(vector, newPos)){
        return true;
    }
    if ((newPos + jumps2) == currentPos){
        return false;
    }
    return true;
}

// takes vector reference and position at currently
// returns false if desired jump + position is too far right (out of bounds), true otherwise
bool attemptRight(std::vector<int>& vector, int currentPos){
    int jumps = vector.at(currentPos);
    unsigned int move = currentPos + jumps;
    if (move > vector.size() - 1){
        return false;
    }
    return true;
}

// takes number of elements in command line and pointer as arguments
// makes a vector of command line argument integers specified
std::vector<int> stringToVector(int len, char** argv){
    std::vector<int> vect;
    for (int i = 1; i < len; i++){
        vect.push_back(std::stoi(argv[i]));
    }
    return vect;
}

// takes reference to vector as parameters, prints values of vector to screen
// iterates over all values of vector with correct commas, beginning braces, and end braces
void printVector(std::vector<int> v){
    std::cout << "{";
    for (unsigned int i = 0; i < v.size(); i++){
        std::cout << v[i];
        if (v[i] == v[v.size()-1]){
            std::cout << "}" << std::endl;
        }else{
            std::cout << ", ";
        }
    } // end of for
}