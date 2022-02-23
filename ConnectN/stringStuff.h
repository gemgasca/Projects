//
// Created by Gem Gasca on 2019-04-30.
//

#include <string>

#ifndef CONNECTN_STRINGSTUFF_H
#define CONNECTN_STRINGSTUFF_H

bool contains(const std::string& string, char letter);
void rstripInPlace(std::string& string, const std::string& charsToRemove = "\t\n ");
int CountWords(std::string string);

#endif //CONNECTN_STRINGSTUFF_H
