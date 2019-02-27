// game.h
// Simeon Ng
// Jason Herning
// Updated: 2/26/19
// Game Class Source File

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include "player.h"
#include <iostream>
#include <string>
#include <sstream>
using std::istringstream;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

// ---- Class Game ----

class Game {

    // ---- Game: Ctor ----

public:
    Game();

    // ---- Game: Public Member Functions ----





public:
    void gameLoop();
    void placeDefaultShips(Player &);
    Coords getUserCoordFire(Player &);
    Coords getUserCoordShip(Player &);
    size_t getUserCoordX();
    size_t getUserCoordY();
    bool getUserOrientation();

    void placeCarrier(Player &);
    void placeBattleship(Player &);
    void placeDestroyer(Player &);
    void placeSubmarine(Player &);
    void placePatrol(Player &);



    // ---- Game: Data Members ----

private:
    Player _playerOne;
    Player _playerTwo;

};


#endif //BATTLESHIP_GAME_H
