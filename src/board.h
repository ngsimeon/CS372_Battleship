// board.h
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Header File

// TODO:
// - addShip function - check if ship coordinate is valid within board size
// - list of coordinates that have ships on them
// - 

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <cstddef>
#include <vector>
#include "ship.h"
using std::vector;

struct Coords {
    size_t x;
    size_t y;

    bool operator==(const Coords& c) const {
        return x == c.x && y == c.y;
    }
};

class Board {

public:
    Board();
    Board(size_t);
    Board(size_t, size_t);
    size_t size() const;

private:
    size_t _length = 0;
    size_t _width = 0;
    vector<Ship> _ships;

};


#endif //BATTLESHIP_BOARD_H
