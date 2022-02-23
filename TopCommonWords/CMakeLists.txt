cmake_minimum_required(VERSION 3.13)
project(TopCommonWords)

set(CMAKE_CXX_STANDARD 14)

add_executable(TopCommonWords main.cpp TopCommonWords.cpp TopCommonWords.h stringFunctions.cpp stringFunctions.h)

target_compile_options(TopCommonWords PRIVATE -Wall -Werror)