//
// Created by Jason on 2/17/2019.
//

#ifndef CS372_BATTLESHIP_SHIP_H
#define CS372_BATTLESHIP_SHIP_H


#include <cstddef>

class Ship{


public:
    Ship(int position, std::size_t size);

    getSize();
    getPosition();


private:
    int _position;
    std::size_t _size;




};


#endif //CS372_BATTLESHIP_SHIP_H
