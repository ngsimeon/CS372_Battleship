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
    Ship(size_t position, size_t length);

    size_t getLength();
    size_t getPosition();

    void hit(size_t position);
    bool getHits(size_t position);

private:
    size_t _position;
    size_t _length;
    vector<bool> _hits;

};


#endif //CS372_BATTLESHIP_SHIP_H
