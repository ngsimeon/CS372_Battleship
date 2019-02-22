// ship.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Ship Class Source File

#include "ship.h"

// 2-Parameter ctor
Ship::Ship(size_t position, size_t length):_position(position),_length(length)
{
    _hits.resize(_length);
}

// getPosition()
// Returns ship position
std::size_t Ship::getPosition()
{
    return _position;
}

// getLength()
// Returns ship length
std::size_t Ship::getLength(){
    return _length ;
}

// hit()
// Attacks the ship. If true, the position on the ship has been hit.
void Ship::hit(size_t position)
{
    _hits[position] = true;
}

// getHits()
// Returns if a position on the ship has been hit.
bool Ship::getHits(size_t position)
{
    return _hits[position];
}