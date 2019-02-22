// battleship_tests.cpp
// Simeon Ng
// Jason Herning
// CS372 Software Construction
// Updated 2/17/19
// Catch2 Tests for Battleship Game

#include "catch.hpp"
#include "ship.h"
#include "board.h"

TEST_CASE("Testing General Ship Functions") {

    Ship testShip1(1,1);
    Ship testShip2(5,5);

    SECTION("Length = 1, Position = 1")
    REQUIRE(testShip1.getLength() == 1);
    REQUIRE(testShip1.getPosition() == 1);

    SECTION("Length = 5, Position = 5")
    REQUIRE(testShip2.getLength() == 5);
    REQUIRE(testShip2.getPosition() == 5);

    testShip2.hit(1);
    testShip2.hit(3);

    SECTION("Test Hitting the Ship")
    REQUIRE(testShip2.getHits(1));
    REQUIRE(testShip2.getHits(3));
    REQUIRE(!testShip2.getHits(4));
}

TEST_CASE("Testing Board Size and Coordinates") {

    Board board1;
    SECTION("Default Size is 10x10 = 100 Tiles")
    REQUIRE(board1.size() == 100);

    Board board2(6);
    SECTION("1-Param Ctor")
    REQUIRE(board2.size() == 36);

    Board board3(8, 6);
    SECTION("2-Param Ctor")
    REQUIRE(board3.size() == 48);
}