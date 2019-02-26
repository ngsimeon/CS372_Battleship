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

class Board {

public:
    Board();
    Board(size_t);
    Board(size_t, size_t);

    size_t size() const;
    void addShip(const Ship& s);

private:
    size_t _length = 0;         // Length of board
    size_t _width = 0;          // Width of board
    vector<Ship> _ships;        // List of ships added to the board
    vector<Coords> _shipCoords; // List of Coords that are taken by ships

};


#endif //BATTLESHIP_BOARD_H
