cmake_minimum_required(VERSION 3.13)
project(CS372_Battleship)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(CS372_Battleship
        ship.cpp ship.h
        battleship_tests.cpp
        catch.hpp
        main.cpp
        )
