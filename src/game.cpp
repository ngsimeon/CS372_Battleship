// game.h
// Simeon Ng
// Jason Herning
// Updated: 2/26/19
// Game Class Source File

#include "game.h"

// ---- Game: Ctor ----

Game::Game() = default;

// ---- Game : Public Member Functions

void Game::gameLoop() {
    // Player 1 places ships
    cout << "Player 1, place your ships!" << endl;
    // Player 2 places ships
    cout << "Player 2, place your ships!" << endl;

    cout << "Game started" << endl;

    // Game loop starts
    // - Alternating fire by p1 and p2
    // ----> Print p1 board
    // ----> p1 fires.
    // ----> Hide p1 board
    // ----> Print p2 board
    // ----> p2 fires.
    // ----> Hide p2 board

    // - check if all ships are sunken.
}

void Game::placeDefaultShips(const Player &) {

    // Place battleship
    // Place destroyer
    // Place submarine
    // Place patrol boat
}

void Game::placeCarrier(const Player & player) {
    Coords c1 = getUserCoord();
}

void Game::placeBattleship(const Player & player) {

}

void Game::placeDestroyer(const Player & player) {

}

void Game::placeSubmarine(const Player & player) {

}

void Game::placePatrol(const Player & player) {

}

Coords Game::getUserCoord() {
    cout << "Enter X coordinate [0-" << _playerOne.
}