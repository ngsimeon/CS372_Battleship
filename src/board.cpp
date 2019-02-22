// board.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Source File

#include "board.h"

// Default ctor
// Default board is 10x10
Board::Board() : _width(10), _length(10) {}

size_t Board::getSize() {
    return _length * _width;
}
