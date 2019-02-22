// ship.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Ship Class Source File

#include "ship.h"

Ship::Ship(size_t position, size_t size):_position(position),_size(size)
{
    _hits.resize(_size);
}

std::size_t Ship::getPosition()
{
    return _position;
}

std::size_t Ship::getSize()
{
    return _size;
}

void Ship::hit(size_t position)
{
    _hits[position] = true;
}


bool Ship::getHits(size_t position)
{
    return _hits[position];
}