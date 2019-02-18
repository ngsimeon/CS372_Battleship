//
// Created by Jason on 2/17/2019.
//

#include "ship.h"



Ship::Ship(size_t position, size_t size):_position(position),_size(size){}

std::size_t Ship::getPosition()
{
    return _position;
}

std::size_t Ship::getSize()
{
    return _size;
}