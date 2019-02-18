//
// Created by Jason on 2/17/2019.
//

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

void Ship::hit(int position)
{
    _hits[position] = true;
}


bool Ship::getHits(int position)
{
    return _hits[position];

}