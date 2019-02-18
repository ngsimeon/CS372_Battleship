//
// Created by Jason on 2/17/2019.
//

#ifndef CS372_BATTLESHIP_SHIP_H
#define CS372_BATTLESHIP_SHIP_H


#include <cstddef>



//Ship
//size will always be from size 1-5
//position will always be from 1-100
class Ship{


public:
    Ship(std::size_t position, std::size_t size);

    std::size_t getSize();
    std::size_t getPosition();


private:
    std::size_t _position;
    std::size_t _size;





};


#endif //CS372_BATTLESHIP_SHIP_H
