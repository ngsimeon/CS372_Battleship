// game.h
// Simeon Ng
// Jason Herning
// Updated: 2/26/19
// Game Class Source File

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include "player.h"

// ---- Class Game ----

class Game {

    // ---- Game: Ctor ----

public:
    Game();

    // ---- Game: Public Member Functions ----

public:
    void gameLoop();

    // ---- Game: Data Members ----

private:
    Player _playerOne;
    Player _playerTwo;

};


#endif //BATTLESHIP_GAME_H
