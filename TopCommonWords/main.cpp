#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "stringFunctions.h"
#include "TopCommonWords.h"
#include <tuple>

// Helped by Obeid 914143011
// accepts command line argument for file name
int main(int argc, char** argv) {
    std::ifstream f;                   // opens file specified in command line
    f.open(argv[1]);

    std::vector<std::string> vector;   // instantiates variables
    std::map<std::string, int> map;
    std::vector<std::tuple<int, std::string>> countsVector;

    vector = makeVector(f);            // initializes vector of file words (strings)
    map = makeMap(vector);             // initializes map of words (strings) to count (int)
    countsVector = getCounts(map);     // initializes vector that contains count, word tuples

    int numWords;                      // determines how many top words are to be printed
    if (argc == 2){
        numWords = 10;
    }
    else if ((argc > 2) && (std::stoul(argv[2]) < countsVector.size())){
        numWords = std::stoi(argv[2]);
    }
    else{
        numWords = countsVector.size();
    }

    printVector(countsVector, numWords);


    f.close();
    return 0;
}