//
// Created by Gem Gasca on 2019-04-15.
//

#ifndef JUMPGAME_JUMPGAME_H
#define JUMPGAME_JUMPGAME_H

#include <vector>
#include <string>
#include <algorithm>

std::vector<int> stringToVector(int len, char** argv);
void printVector(std::vector<int> v);
bool attemptLeft(std::vector<int>& vector, int currentPos);
bool attemptRight(std::vector<int>& vector, int currentPos);
bool bestAnswer(std::vector<int>& bestAnswer, std::vector<int> newVector);
void setBestAnswer(std::vector<int>& bestAnswer, std::vector<int> newVector);
bool checkEndlessLoopLeft(std::vector<int>& vector, const int currentPos, const int newPos);
bool checkEndlessLoopRight(std::vector<int>& vector, const int currentPos, const int newPos);

#endif //JUMPGAME_JUMPGAME_H
