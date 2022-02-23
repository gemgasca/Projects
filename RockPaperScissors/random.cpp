//
// Created by Gem Gasca on 2019-04-15.
//

#include <random>
#include <string>
#include "random.h"

int randGenerator(const int& seed){
    std::minstd_rand random;
    std::uniform_int_distribution<int> distribution(0,2);
    random.seed(seed);
    return distribution(random);
}