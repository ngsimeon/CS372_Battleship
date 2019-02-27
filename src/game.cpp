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
    placeDefaultShips(_playerOne);
    _playerOne.fireAtEnemy(getUserCoordFire(_playerOne));
    cout << _playerOne.getBoard();
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

void Game::placeDefaultShips(Player & player) {
    placeCarrier(player);
    placeBattleship(player);
    placeDestroyer(player);
    placeSubmarine(player);
    placePatrol(player);
}

Coords Game::getUserCoordFire(Player & player){
    while(true) {
        size_t coordX = getUserCoordX();
        size_t coordY = getUserCoordY();

        Coords c(coordX, coordY);
        if(player.isCoordTakenFired(c)) {
            cout << "You have already fired at this coordinate!" << endl;
            continue;
        }
        else {
            return c;
        }
    }
}

Coords Game::getUserCoordShip(Player & player) {
    while(true) {
        size_t coordX = getUserCoordX();
        size_t coordY = getUserCoordY();

        Coords c(coordX, coordY);
        if(player.isCoordTakenShip(c)) {
            cout << "Another ship is already there!" << endl;
            continue;
        }
        else {
            return c;
        }
    }
}

size_t Game::getUserCoordX() {
    while(true) {
        string inputX;
        cout << "Enter X coordinate [0-" << _playerOne.getLength() << "]: ";
        getline(cin, inputX);
        if(!cin) {
            std::cout << "Input error. Try again." << endl;
            continue;
        }
        istringstream iss(inputX);
        size_t coordX;
        iss >> coordX;
        if(!iss) {
            std::cout << "X coordinate must be an integer between [0-" << _playerOne.getLength() << "]";
            continue;
        }
        return coordX;
    }
}

size_t Game::getUserCoordY() {
    while(true) {
        string inputY;
        cout << "Enter Y coordinate [0-" << _playerOne.getWidth() << "]: ";
        getline(cin, inputY);
        if (!cin) {
            std::cout << "Input error. Try again." << endl;
            continue;
        }
        istringstream iss(inputY);
        iss.str(inputY);
        size_t coordY;
        iss >> coordY;
        if (!iss) {
            std::cout << "Y coordinate must be an integer between [0-" << _playerOne.getWidth() << "]";
            continue;
        }
        return coordY;
    }
}

bool Game::getUserOrientation() {
    while(true) {
        string orientation;
        cout << "[H]orizontal or [V]ertical?: ";
        getline(cin, orientation);
        if (!cin) {
            std::cout << "Input error. Try again." << endl;
            continue;
        }
        switch(orientation[0]) {
            case 'H':
                return true;
            case 'V':
                return false;
            case 'h':
                return true;
            case 'v':
                return false;
            default:
                cout << "Not a valid orientation." << endl;
                continue;
        }
    }
}

void Game::placeCarrier(Player & player) {
    cout << "Place the bow(front) of your Carrier:" << endl;
    Coords c1 = getUserCoordShip(player);
    bool orientation = getUserOrientation();
    Coords c2 = {0, 0};
        // If unable to place horizontally, place vertically.
    if (c1.x+4 >= player.getLength()) {
        if (c1.x-4 > 0) {
            // Place horizontal/negative
            c2 = {c1.x-4, c1.y};
        }
        else if (c1.y+4 >= player.getWidth())
            // Place vertical/negative
            c2 = {c1.x, c1.y - 4};
        else {
            // Place vertical/positive
            c2 = {c1.x, c1.y + 4};
        }
    }
    // Else place horizontal/positive
    else {
        c2 = {c1.x + 4, c1.y};
    }

    Ship ship(c1, c2);
    player.addShip(ship);
}

void Game::placeBattleship(Player & player) {
    cout << "Place the bow(front) of your Battleship:" << endl;
    Coords c1 = getUserCoordShip(player);
    bool orientation = getUserOrientation();
    Coords c2 = {0, 0};
    // If unable to place horizontally, place vertically.
    if (c1.x+3 >= player.getLength()) {
        if (c1.x-3 > 0) {
            // Place horizontal/negative
            c2 = {c1.x-3, c1.y};
        }
        else if (c1.y+3 >= player.getWidth())
            // Place vertical/negative
            c2 = {c1.x, c1.y-3};
        else {
            // Place vertical/positive
            c2 = {c1.x, c1.y+3};
        }
    }
        // Else place horizontal/positive
    else {
        c2 = {c1.x+3, c1.y};
    }
    Ship ship(c1, c2);
    player.addShip(ship);
}

void Game::placeDestroyer(Player & player) {
    cout << "Place the bow(front) of your Destroyer:" << endl;
    Coords c1 = getUserCoordShip(player);
    bool orientation = getUserOrientation();
    Coords c2 = {0, 0};
    // If unable to place horizontally, place vertically.
    if (c1.x+2 >= player.getLength()) {
        if (c1.x-2 > 0) {
            // Place horizontal/negative
            c2 = {c1.x-2, c1.y};
        }
        else if (c1.y+2 >= player.getWidth())
            // Place vertical/negative
            c2 = {c1.x, c1.y - 2};
        else {
            // Place vertical/positive
            c2 = {c1.x, c1.y + 2};
        }
    }
        // Else place horizontal/positive
    else {
        c2 = {c1.x + 2, c1.y};
    }
    Ship ship(c1, c2);
    player.addShip(ship);
}

void Game::placeSubmarine(Player & player) {
    cout << "Place the bow(front) of your Submarine:" << endl;
    Coords c1 = getUserCoordShip(player);
    bool orientation = getUserOrientation();
    Coords c2 = {0, 0};
    // If unable to place horizontally, place vertically.
    if (c1.x+2 >= player.getLength()) {
        if (c1.x-2 > 0) {
            // Place horizontal/negative
            c2 = {c1.x-2, c1.y};
        }
        else if (c1.y+2 >= player.getWidth())
            // Place vertical/negative
            c2 = {c1.x, c1.y - 2};
        else {
            // Place vertical/positive
            c2 = {c1.x, c1.y + 2};
        }
    }
        // Else place horizontal/positive
    else {
        c2 = {c1.x + 2, c1.y};
    }

    Ship ship(c1, c2);
    player.addShip(ship);
}

void Game::placePatrol(Player & player) {
    cout << "Place the bow(front) of your Patrol Boat:" << endl;
    Coords c1 = getUserCoordShip(player);
    bool orientation = getUserOrientation();
    Coords c2 = {0, 0};
    // If unable to place horizontally, place vertically.
    if (c1.x+1 >= player.getLength()) {
        if (c1.x-1 > 0) {
            // Place horizontal/negative
            c2 = {c1.x-1, c1.y};
        }
        else if (c1.y+1 >= player.getWidth())
            // Place vertical/negative
            c2 = {c1.x, c1.y - 1};
        else {
            // Place vertical/positive
            c2 = {c1.x, c1.y + 1};
        }
    }
        // Else place horizontal/positive
    else {
        c2 = {c1.x + 1, c1.y};
    }
    Ship ship(c1, c2);
    player.addShip(ship);
}

