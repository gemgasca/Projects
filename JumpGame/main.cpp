#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "JumpGame.h"
#include "playGame.h"

int main(int argc, char** argv) {
    if (argc == 1){
        std::cout << "There is no solution to the given game." << std::endl;
        return 0;
    }

    std::vector<int> V;
    V = stringToVector(argc, argv);
    std::vector<int> solutionVector ;        // stores best solutions
    for(int i = 0; i < 50; i++){
        solutionVector.push_back(i);
    }
    std::vector<int> controlVect;           // will continue to change each time finding new solution
    controlVect.push_back(0);

    unsigned int pos = 0;
    makeJumps(V, solutionVector, controlVect, pos);

    if (solutionVector.size() > 0 && solutionVector.size() < 50) {
        std::cout << "The solution is: ";
        printVector(solutionVector);
    }
    else{
        std::cout << "There is no solution to the given game." << std::endl;
    }
    return 0;
}