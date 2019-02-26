// main.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/26/19
// Game Class Source File

#include <iostream>
#include "game.h"
using std::cout;

int main() {
    cout << "Welcome to Battleship!\n";

    Game g;

    g.gameLoop();

    return 0;
}