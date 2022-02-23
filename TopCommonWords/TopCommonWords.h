//
// Created by Gem Gasca on 2019-04-16.
//

#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

std::map<std::string, int> makeMap(std::vector<std::string> &vector);
std::vector<std::string> makeVector(std::ifstream& file);
std::vector<std::tuple<int, std::string>> getCounts(std::map<std::string, int>& map);
void  printVector(std::vector<std::tuple<int, std::string>>& vector, int numWords);
void swap(std::string& string1, std::string& string2);

#endif //TOPCOMMONWORDS_TOPCOMMONWORDS_H
