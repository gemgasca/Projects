//
// Created by Gem Gasca on 2019-04-16.
//
#include "TopCommonWords.h"
#include "stringFunctions.h"
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>

// takes references to map, vector of strings, and string to be added to map; returns map of words as key and count as value
std::map<std::string, int> makeMap(std::vector<std::string> &vector){
    std::map<std::string, int> map;
    for(std::string string : vector){                           // iterates over all strings in vector
        if (map.find(string) == map.end() ) {                   // adds words not already in map to the map with value count from vector
            map[string] = std::count(vector.begin(), vector.end(), string);
        }
    }
    return map;
}

// takes reference to file, returns vector of all words in file
std::vector<std::string> makeVector(std::ifstream& file){
    std::string word;
    std::vector<std::string> vector;
    while(file >> word) {                   // iterates over every word in file
        word = lower(word);                 // formats word, making lower case, removing whitespace, removing special characters
        lstripInPlace(word);
        rstripInPlace(word);
        if (word == "a" || word == "an" || word == "and" || word == "in" || word == "is" || word == "the" || word == "it"){     // skips over word if uninteresting
            continue;
        }
        vector.push_back(word);             // adds word to vector
    }
    return vector;
}

// takes two string references and swaps values
void swap(std::string& string1, std::string& string2){
    std::string temp = string1;
    string1 = string2;
    string2 = temp;
}

//
std::vector<std::tuple<int, std::string>> getCounts(std::map<std::string, int>& map){           // makes vector of tuples in the form count, word
    std::vector<std::tuple<int, std::string>> vector;
    for (auto pair : map){
        vector.push_back(std::tuple<int, std::string>(pair.second, pair.first));
    }
    std::sort(vector.rbegin(), vector.rend());              // bubble sorts words in alphabetical order if they have the same count
    for (unsigned int i = 0; i < vector.size()-1; i++) {
        for (unsigned int j = 0; j < vector.size()-i-1; j++) {
            while (std::get<0>(vector[j]) == std::get<0>(vector[j + 1])) {
                if (std::get<1>(vector[j]) > std::get<1>(vector[j + 1])) {
                    swap(std::get<1>(vector[j]), std::get<1>(vector[j + 1]));
                }
                j++;
        }// end inner for
    }// end outer for
    }
    return vector;
}


void  printVector(std::vector<std::tuple<int, std::string>>& vector, int numWords){
    int timesIterated = 1;
    for (unsigned int i = 0; i < vector.size(); i++){
        std::cout << timesIterated << ".) These words appeared " << std::get<0>(vector[i]) << " times: {" << std::get<1>(vector[i]);
        if (std::get<0>(vector[i]) != std::get<0>(vector[i+1])){
            std::cout << "}" << std::endl;
        }
        else{
            std::cout << ", ";
        }
        while(std::get<0>(vector[i]) == std::get<0>(vector[i+1])){
            std::cout << std::get<1>(vector[i+1]);
            i++;
            if (std::get<0>(vector[i]) != std::get<0>(vector[i+1])){
                    std::cout << "}" << std::endl;
            }
            else{
                std::cout  << ", ";
            }
        }

        if (timesIterated == numWords){
            break;
        }
        timesIterated ++;
    }
}
