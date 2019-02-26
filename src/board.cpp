// board.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Source File

#include "board.h"

// ---- Board: Ctors ----

// Default ctor
// Default board is 10x10 in size.
Board::Board() : _length(10), _width(10) {}

// 1-Param ctor
// Creates a board that is length*length in size.
Board::Board(size_t length) : _length(length), _width(length) {}

// 2-Param ctor
// Creates a board that is length*width in size.
Board::Board(size_t length, size_t width) : _length(length), _width(width) {}

// ---- Board: General Public Member Functions ----

// size()
// Returns size of board.
size_t Board::size() const {
    return _length * _width;
}

// addShip()
// Adds a ship to the board.
void Board::addShip(const Ship& ship) {
    _ships.push_back(ship);

    // If horizontal
    if(ship.getOrientation()) {
        this->addCoordHorizontal(ship);
    }
    else {
        this->addCoordVertical(ship);
    }
}

// addCoordHorizontal
// Adds a ships coordinates to the board if the orientation is horizontal.
void Board::addCoordHorizontal(const Ship& ship) {
    auto addCoord = ship.getBegin();
    _shipCoords.push_back(addCoord);

    while(addCoord != ship.getEnd()) {
        addCoord.x += 1;
        _shipCoords.push_back(addCoord);
    }
}

// addCoordVertical
// Adds a ships coordinates to the board if the orientation is vertical.
void Board::addCoordVertical(const Ship & ship) {
    auto addCoord = ship.getBegin();
    _shipCoords.push_back(addCoord);

    while(addCoord != ship.getEnd()) {
        addCoord.y += 1;
        _shipCoords.push_back(addCoord);
    }
}