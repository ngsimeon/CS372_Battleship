// battleship_tests.cpp
// Simeon Ng
// Jason Herning
// CS372 Software Construction
// Updated 2/17/19
// Catch2 Tests for Battleship Game

#include "catch.hpp"
#include "ship.h"
#include "board.h"

Ship testShip1(1,1);
Ship testShip2(5,5);

TEST_CASE("Testing General Ship Functions") {

    SECTION("Size = 1, Position = 1")
    REQUIRE(testShip1.getSize() == 1);
    REQUIRE(testShip1.getPosition() == 1);

    SECTION("Size = 5, Position = 5")
    REQUIRE(testShip2.getSize() == 5);
    REQUIRE(testShip2.getPosition() == 5);

    testShip2.hit(1);
    testShip2.hit(3);

    SECTION("Test Hitting the Ship")
    REQUIRE(testShip2.getHits(1));
    REQUIRE(testShip2.getHits(3));
    REQUIRE_FALSE(testShip2.getHits(5));
}

Board board1;

TEST_CASE("Testing Board Size and Coordinates") {

    SECTION("Default Size is 10x10 = 100 Tiles")
    REQUIRE(board1.getSize() == 100);
}