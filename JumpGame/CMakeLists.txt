cmake_minimum_required(VERSION 3.13)
project(JumpGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(JumpGame main.cpp JumpGame.cpp JumpGame.h playGame.cpp playGame.h)
target_compile_options(JumpGame PRIVATE -Wall -Werror)