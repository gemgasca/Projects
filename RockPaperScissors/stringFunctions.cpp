//
// Created by Gem Gasca on 2019-04-14.
//

#include "stringFunctions.h"
#include "RockPaperScissors.h"
#include <string>
#include <iostream>
#include <algorithm>

bool isupper(char c) {
    return c >= 'A' && c <= 'Z'; // incorrect 'A' <= c <= 'Z
}

char tolower(char c) {
    if(isupper(c)){
        return 'a' + c - 'A';
    }
    else{
        return c;
    }
}

void lowerInPlace(std::string& string) {
    for (auto &letter : string) {
        letter = tolower(letter);
    }
}

std::string lower(std::string string) {
    lowerInPlace(string);
    return string;
}

bool contains(const std::string& string, char letter) {
    return std::find(string.cbegin(), string.cend(), letter) != string.cend();
    for(const auto& curChar : string){
        if(curChar == letter){
            return true;
        }
    }
    return false;
}

void lstripInPlace(std::string& string, const std::string& charsToRemove) {

    auto itr = string.begin();
    for(; itr != string.end(); ++itr){
        if(!contains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(string.begin(), itr);
}

void rstripInPlace(std::string& string, const std::string& charsToRemove) {
    auto itr = string.rbegin();
    for(; itr != string.rend(); ++itr){
        if(!contains(charsToRemove, *itr)){
            break;
        }
    }
    string.erase(itr.base(), string.end());
}



