cmake_minimum_required(VERSION 3.13)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 14)

add_executable(RockPaperScissors main.cpp stringFunctions.cpp stringFunctions.h RockPaperScissors.cpp RockPaperScissors.h random.cpp random.h)
target_compile_options(RockPaperScissors PRIVATE -Wall -Werror)