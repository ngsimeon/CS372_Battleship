cmake_minimum_required(VERSION 3.0)
project(Battleship)
project(Battleship_tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

#with test
add_executable(Battleship_tests
        catch.hpp
        battleship_tests.cpp
        ship.cpp ship.h
        board.cpp board.h
        player.cpp player.h
        game.cpp game.h)

#with main
add_executable(Battleship
        main.cpp
        ship.cpp ship.h
        board.cpp board.h
        player.cpp player.h
        game.cpp game.h)
