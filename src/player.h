// player.h
// Simeon Ng
// Jason Herning
// Updated: 2/23/19
// Player Class Source File

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include "board.h"

class Player {
public:
    Player(const Board&, const Board&);

    void attackShip();

private:
    Board _shipBoard;
    Board _trackBoard;
};


#endif //BATTLESHIP_PLAYER_H
