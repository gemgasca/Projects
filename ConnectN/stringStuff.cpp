//
// Created by Gem Gasca on 2019-04-30.
//
#include <string>
#include "stringStuff.h"


bool contains(const std::string& string, char letter) {
    return std::find(string.cbegin(), string.cend(), letter) != string.cend();
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

int CountWords(std::string string){
    int numSpaces = 0;
    unsigned int i = 0;
    while(isspace(string.at(i))){i++;}
    for(int i = 0; i < string.length(); i++)
    {
        if(isspace(string.at(i)))
        {
            numSpaces++;
            while(isspace(string.at(i++)))
                if (string.at(i) == '\0')
                    numSpaces--;
        }
    }
    return (numSpaces + 1);
}