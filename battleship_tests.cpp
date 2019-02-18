// battleship_tests.cpp
// Simeon Ng
// Jason Herning
// CS372 Software Construction
// Updated 2/17/19
// Catch2 Tests for Battleship Game

#include "catch.hpp"
#include "ship.h"




Ship testShip1(1,1);
Ship testShip2(-1, -1);



TEST_CASE("ship with is 1 & position 1"){
    REQUIRE(testShip1.getSize() == 1);
    REQUIRE(testShip1.getPosition() == 1);
    REQUIRE(testShip2.getSize() > 0);




}