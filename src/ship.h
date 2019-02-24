// ship.h
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Ship Class Header File

#ifndef CS372_BATTLESHIP_SHIP_H
#define CS372_BATTLESHIP_SHIP_H

#include <iostream>
#include <cstddef>
#include <vector>
#include <cmath>
#include "board.h"

using std::cout;
using std::endl;
using std::vector;

//To Do:
// -find way to hold locations of shots
//

//Ship
//size will always be from size 1-5
//position will always be from 1-100
class Ship {

public:
    Ship(size_t len, Coords c1, Coords c2);

    size_t getLength() const;
    Coords getBegin() const;
    Coords getEnd() const;

    void attack(const size_t& position);
    bool getHits(const size_t& position) const;

private:
    const size_t _length;
    const Coords _begin;
    const Coords _end;
    vector<bool> _hits;

};


#endif //CS372_BATTLESHIP_SHIP_H
