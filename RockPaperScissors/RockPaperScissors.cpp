//
// Created by Gem Gasca on 2019-04-14.
//

#include <iostream>
#include "RockPaperScissors.h"
#include "stringFunctions.h"
#include <string>

bool contPlaying(){
    std::string cont;
    while (true){
        std::cout << "Would you like to replay the game?\nEnter (Y)es or (N)o: ";
        getline(std::cin, cont);
        // std::cout << "Value of cont:" << cont;
        cont = lower(cont);
        lstripInPlace(cont);
        rstripInPlace(cont);
        if (cont == "y" || cont == "(y)es" || cont == "yes" ){
            return true;
        }
        else if (cont == "n" || cont == "(n)o" || cont == "no"){
            return false;
        }
        else{
            continue;
        }
    }
    //return true;
}

int getInput(){
    std::string input;
    while (true){
        std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: ";
        getline(std::cin, input);
        input = lower(input);
        lstripInPlace(input);
        rstripInPlace(input);
        if (input == "r" || input == "(r)ock" || input == "rock"){
            return 0;
        }
        else if (input == "p" || input == "(p)aper" || input == "paper"){
            return 1;
        }
        else if (input == "s" || input == "(s)cissors" || input == "scissors"){
            return 2;
        }
        else{
            continue;
        }
    }
}

std::string getWord(int x){
    if (x == 0){
        return "rock";
    }
    else if (x == 1){
        return "paper";
    }
    else {
        return "scissors";
    }
}

int whoWins(int ai, int user){
    std::string userC = getWord(ai);
    std::string aiC = getWord(user);
    if (user == ai){
        std::cout << "You and the AI both played " << aiC << ".\nKeep playing until someone wins." << std::endl;
        return 1;
    }
    else if ((userC == "rock" && aiC == "paper") || (userC == "paper" && aiC == "scissors") || (userC == "scissors" && aiC == "rock")){
        // user wins
        std::cout << "You win!" << std::endl;
        return 0;
    }
    else{
        // ai wins
        std::cout << "The AI wins :(" << std::endl;
        return 0;
    }
    return 0;
}