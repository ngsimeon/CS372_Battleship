cmake_minimum_required(VERSION 3.13)
project(Battleship)

set(CMAKE_CXX_STANDARD 17)

#include_directories(.)


#with test
#add_executable(Battleship battleship_tests.cpp
#        ship.cpp ship.h
#        board.cpp board.h)

#with main
add_executable(Battleship main.cpp
        ship.cpp ship.h
        board.cpp board.h game.cpp game.h)
