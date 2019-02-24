// board.h
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Header File

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <cstddef>

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

};


#endif //BATTLESHIP_BOARD_H
