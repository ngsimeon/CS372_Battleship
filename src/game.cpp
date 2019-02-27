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
            cout << "Enter another coordinate";
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
            cout << "Enter another coordinate." << endl;
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
        cout << "Enter X coordinate [0-" << _playerOne.getLength() - 1 << "]: ";
        getline(cin, inputX);
        if(!cin) {
            std::cout << "Input error. Try again." << endl;
            continue;
        }
        istringstream iss(inputX);
        size_t coordX;
        iss >> coordX;
        if(!iss || coordX >= _playerOne.getLength()) {
            std::cout << "X coordinate must be an integer between [0-" << _playerOne.getLength() - 1 << "]" << endl;
            continue;
        }
        return coordX;
    }
}

size_t Game::getUserCoordY() {
    while(true) {
        string inputY;
        cout << "Enter Y coordinate [0-" << _playerOne.getWidth() - 1 << "]: ";
        getline(cin, inputY);
        if (!cin) {
            std::cout << "Input error. Try again." << endl;
            continue;
        }
        istringstream iss(inputY);
        iss.str(inputY);
        size_t coordY;
        iss >> coordY;
        if (!iss || coordY >= _playerOne.getWidth()) {
            std::cout << "Y coordinate must be an integer between [0-" << _playerOne.getWidth() - 1 << "]" << endl;
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

    while (true) {
        cout << "Place the front of your Carrier:" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + 4 < player.getLength()) {
                c2 = {c1.x + 4, c1.y};
            }
            else if (c1.y + 4 < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + 4};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + 4 < player.getWidth()) {
                c2 = {c1.x, c1.y + 4};
            }
            else if (c1.x + 4 < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + 4, c1.y};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        Ship ship(c1, c2);
        player.addShip(ship);
        break;
    }
}

void Game::placeBattleship(Player & player) {
    while (true) {
        cout << "Place the front of your Battleship:" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + 3 < player.getLength()) {
                c2 = {c1.x + 3, c1.y};
            }
            else if (c1.y + 3 < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + 3};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + 3 < player.getWidth()) {
                c2 = {c1.x, c1.y + 3};
            }
            else if (c1.x + 3 < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + 3, c1.y};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        Ship ship(c1, c2);
        player.addShip(ship);
        break;
    }
}

void Game::placeDestroyer(Player & player) {
    while (true) {
        cout << "Place the front of your Destroyer:" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + 2 < player.getLength()) {
                c2 = {c1.x + 2, c1.y};
            }
            else if (c1.y + 2 < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + 2};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + 2 < player.getWidth()) {
                c2 = {c1.x, c1.y + 2};
            }
            else if (c1.x + 2 < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + 2, c1.y};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        Ship ship(c1, c2);
        player.addShip(ship);
        break;
    }
}

void Game::placeSubmarine(Player & player) {
    while (true) {
        cout << "Place the front of your Submarine:" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + 2 < player.getLength()) {
                c2 = {c1.x + 2, c1.y};
            }
            else if (c1.y + 2 < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + 2};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + 2 < player.getWidth()) {
                c2 = {c1.x, c1.y + 2};
            }
            else if (c1.x + 2 < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + 2, c1.y};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        Ship ship(c1, c2);
        player.addShip(ship);
        break;
    }
}

void Game::placePatrol(Player & player) {
    while (true) {
        cout << "Place the front of your Patrol Boat:" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + 1 < player.getLength()) {
                c2 = {c1.x + 1, c1.y};
            }
            else if (c1.y + 1 < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + 1};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + 4 < player.getWidth()) {
                c2 = {c1.x, c1.y + 1};
            }
            else if (c1.x + 1 < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + 1, c1.y};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        Ship ship(c1, c2);
        player.addShip(ship);
        break;
    }
}

