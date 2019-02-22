// board.h
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Board Class Header File

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <cstddef>

class Board {

public:
    Board();

    size_t getSize();

private:
    size_t _width = 0;
    size_t _length = 0;

};


#endif //BATTLESHIP_BOARD_H
