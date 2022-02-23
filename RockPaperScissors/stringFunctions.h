//
// Created by Gem Gasca on 2019-04-14.
//

#ifndef RPS_STRINGFUNCTIONS_H
#define RPS_STRINGFUNCTIONS_H

#include <string>
#include <iostream>

char tolower(char c);
bool isupper(char c);
void lowerInPlace(std::string& string);
std::string lower(std::string string);
void lstripInPlace(std::string& string, const std::string& charsToRemove = "\t\n ");
void rstripInPlace(std::string& string, const std::string& charsToRemove = "\t\n ");
bool contains(const std::string& string, char letter);

#endif //RockPaperScissors_stringFunctions_H
