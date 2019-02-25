// battleship_tests.cpp
// Simeon Ng
// Jason Herning
// CS372 Software Construction
// Updated 2/23/19
// Catch2 Tests for Battleship Game

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ship.h"
#include "board.h"

TEST_CASE("Testing General Ship Functions") {

    Coords c1, c2, c3, c4;
    c1.x = 0, c1.y = 0;
    c2.x = 2, c1.y = 0;
    c3.x = 4, c3.y = 4;
    c4.x = 4, c4.y = 8;

    Ship testShip1(c1, c2);
    Ship testShip2(c3, c4);

    SECTION("Length = 2, Begin = (0, 0), End = (2, 0)")
    REQUIRE(testShip1.getLength() == 3);
    REQUIRE(testShip1.getBegin() == c1);
    REQUIRE(testShip1.getEnd() == c2);

    SECTION("Length = 5, Begin = (4, 4), End = (4, 8)")
    REQUIRE(testShip2.getLength() == 5);
    REQUIRE(testShip2.getBegin() == c3);
    REQUIRE(testShip2.getEnd() == c4);

    c2.x = 1, c2.y = 0;
    c3.x = 2, c3.y = 0;
    testShip1.attack(c1);
    testShip1.attack(c2);
    testShip1.attack(c3);

    c1.x = 4, c1.y = 4;
    c2.x = 4, c2.y = 5;
    testShip2.attack(c1);
    testShip2.attack(c2);

    SECTION("Test Hitting the Ship")
    REQUIRE(testShip1.isSunk());
    REQUIRE(!testShip2.isSunk());
}

TEST_CASE("Testing Board Size, Coordinates, and adding Ships") {

    Board board1;
    SECTION("Default Size is 10x10 = 100 Tiles")
    REQUIRE(board1.size() == 100);

    Board board2(6);
    SECTION("1-Param Ctor")
    REQUIRE(board2.size() == 36);

    Board board3(8, 6);
    SECTION("2-Param Ctor")
    REQUIRE(board3.size() == 48);

    Coords c1, c2, c3, c4;
    c1.x = 0, c1.y = 0;
    c2.x = 2, c1.y = 0;
    c3.x = 4, c3.y = 4;
    c4.x = 4, c4.y = 8;

    Ship testShip1(c1, c2);
    Ship testShip2(c3, c4);

    SECTION("Adding a length 2 ship to the board.")
    REQUIRE()
}