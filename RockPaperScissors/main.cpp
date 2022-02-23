#include <iostream>
#include <random>
#include <string>
#include "stringFunctions.h"
#include "RockPaperScissors.h"
#include "random.h"

int main(int argc, char** argv) {
    std::string user, ai;
    bool keepPlaying;

    int seed;
    std::minstd_rand random;

    if (argc > 1){
        seed = std::stoi(argv[1]);
        random.seed(seed);
    }
    else{
        random.seed(time(nullptr));
    }

    std::uniform_int_distribution<int> distribution(0,2);


    do{
        int userNum = getInput();               // gets valid user choice
        int aiNum = distribution(random);                   // sets ai choice
        std::string userC = getWord(userNum);   // gets word value for user choice
        std::string aiC = getWord(aiNum);       // gets word value for ai choice

//        std::cout << "";
//        std::cout << "User word: " << userC << std::endl;         // checks user word
//        std::cout << "User number: " << userNum << std::endl;     // checks user number
//        std::cout << "AI number: " << aiNum << std::endl;           // checks ai number
//        std::cout << "AI choice: " << aiC << std::endl;             // checks ai word

        std::cout << "The ai played " << aiC << "." << std::endl;

        if (whoWins(aiNum, userNum) == 0){
            keepPlaying = contPlaying();
        }
        else{
            keepPlaying = true;
        }

    }while(keepPlaying);

    return 0;
}