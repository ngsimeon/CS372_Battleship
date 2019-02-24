// board.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Source File

#include "board.h"

// Default ctor
// Default board is 10x10 in size.
Board::Board() : _length(10), _width(10) {}

// 1-Param ctor
// Creates a board that is length*length in size.
Board::Board(size_t length) : _length(length), _width(length) {}

// 2-Param ctor
// Creates a board that is length*width in size.
Board::Board(size_t length, size_t width) : _length(length), _width(width) {}

size_t Board::size() const {
    return _length * _width;
}
