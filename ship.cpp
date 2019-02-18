//
// Created by Jason on 2/17/2019.
//

#include "ship.h"



Ship::Ship(int position, size_t size):_position(position),_size(size){}

int Ship::getPosition()
{
    return _position;
}

int Ship::getSize()
{
    return _size;
}