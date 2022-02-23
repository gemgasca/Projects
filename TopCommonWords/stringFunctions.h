//
// Created by Gem Gasca on 2019-04-16.
//

#ifndef TOPCOMMONWORDS_STRINGFUNCTIONS_H
#define TOPCOMMONWORDS_STRINGFUNCTIONS_H

#include <string>
#include <iostream>

char tolower(char c);
bool isupper(char c);
void lowerInPlace(std::string& string);
std::string lower(std::string string);
void lstripInPlace(std::string& string, const std::string& charsToRemove = "\t\n ,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`' ");
void rstripInPlace(std::string& string, const std::string& charsToRemove = "\t\n ,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`' ");
bool contains(const std::string& string, char letter);

#endif //TOPCOMMONWORDS_STRINGFUNCTIONS_H
