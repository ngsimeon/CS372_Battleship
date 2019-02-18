//
// Created by Jason on 2/17/2019.
//

#ifndef CS372_BATTLESHIP_SHIP_H
#define CS372_BATTLESHIP_SHIP_H

#include <iostream>
#include <cstddef>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::size_t;

//To Do:
// -find way to hold locations of shots
//

//Ship
//size will always be from size 1-5
//position will always be from 1-100
class Ship{


public:
    Ship(std::size_t position, std::size_t size);

    std::size_t getSize();
    std::size_t getPosition();

    void hit(int position);
    bool getHits(int position);



private:
    std::size_t _position;
    std::size_t _size;
    std::vector<bool> _hits;





};


#endif //CS372_BATTLESHIP_SHIP_H
