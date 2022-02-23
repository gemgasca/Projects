//
// Created by Gem Gasca on 2019-11-19.
//
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "AVL.cpp"

int main(int argc, char** argv) {
    nlohmann::json jsonObject;          // creates json object and opens file
    std::ifstream json_file;
    json_file.open(argv[1]);

    if (!json_file.is_open()){          // prints error and exits if file not open
        std::cout << "ERROR: file not open.";
        return 0;
    }
    else{
        json_file >> jsonObject;        // reads json data into object as long as file is open
    }

    AVL AVLTree = AVL();           // creates new AVLtree

    // creates AVL tree using operations in json
    for (auto elem : jsonObject){
        std::cout << elem << std::endl;
        try {
            int key = elem["key"];
            AVLTree.Insert(key);
        }
        catch(...){
            break;
        }
    }

    // prints resulting AVL tree to screen
    std::cout << AVLTree.JSON();

    json_file.close();
    return 0;
}