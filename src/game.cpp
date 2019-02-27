// game.h
// Simeon Ng
// Jason Herning
// Updated: 2/26/19
// Game Class Source File

#include "game.h"

// ---- Game: Ctor ----

Game::Game() = default;

// ---- Game : Public Member Functions

// gameLoop()
// Main game loop where game is played.
void Game::gameLoop()
{
    cout << "Game started" << endl;

    // Player 1 places ships
    cout << "Player 1, place your ships!" << endl;
    placeDefaultShips(_playerOne);

    clearBoard();

    // Player 2 places ships
    cout << "Player 2, place your ships!" << endl;
    placeDefaultShips(_playerTwo);

    clearBoard();

    while(true) {
        // ---- PLAYER 1'S TURN ----

        cout << "Player 1's Turn" << endl;
        cout << "Your Board: " << endl;
        printTopPlayer1();
        printBottomPlayer1();
        cout << "Fire at Player 2!" << endl;
        Coords c1 = getUserCoordFire(_playerOne);
        if(_playerTwo.hit(c1)) {
            cout << "HIT!" << endl;
        }
        else {
            cout << "MISS!" << endl;
        }

        if(_playerTwo.getAllSunk()) {
            cout << "PLAYER 1 WINS!!!" << endl;
            break;
        }

        clearBoard();

        // ---- PLAYER 2'S TURN ----

        cout << "Player 2's Turn" << endl;
        cout << "Your Board: " << endl;
        printTopPlayer1();
        printBottomPlayer1();
        cout << "Fire at Player 1!" << endl;
        Coords c2 = getUserCoordFire(_playerTwo);
        if(_playerOne.hit(c1)) {
            cout << "HIT!" << endl;
        }
        else {
            cout << "MISS!" << endl;
        }

        if(_playerOne.getAllSunk()) {
            cout << "PLAYER 2 WINS !!!" << endl;
            break;
        }

        clearBoard();
    }
}

// placeDefaultShips()
// Asks players to place the standard battleships.
void Game::placeDefaultShips(Player & player) {
    Ships ship1 = CARRIER;
    Ships ship2 = BATTLESHIP;
    Ships ship3 = DESTROYER;
    Ships ship4 = SUBMARINE;
    Ships ship5 = PATROL;

    placeShip(player, ship1);
    placeShip(player, ship2);
    placeShip(player, ship3);
    placeShip(player, ship4);
    placeShip(player, ship5);
}

// getUserCoordFire()
// Gets a users coordinates and checks if the user has fired at it before.
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

// getUserCoordShip()
// Gets a users coordinates and checks if the user has placed a ship on it before.
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

// getUserCoordX()
// Gets a users X coordinate and returns it.
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

// getUserCoordY()
// Gets a users Y coordinate and returns it.
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

// getUserOrientation()
// Gets a users ship orientation and returns it.
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
            case 'H': return true;
            case 'V': return false;
            case 'h': return true;
            case 'v': return false;
            default:
                cout << "Not a valid orientation." << endl;
                continue;
        }
    }
}

// placeShip()
// Places a default ship based on the given enumeration.
void Game::placeShip(Player & player, Game::Ships ship) {
    string shipType;
    size_t shipValue = 0;
    switch(ship) {
        case CARRIER: shipType = "Carrier"; shipValue = 4; break;
        case BATTLESHIP: shipType = "Battleship"; shipValue = 3; break;
        case DESTROYER: shipType = "Destroyer"; shipValue = 2; break;
        case SUBMARINE: shipType = "Submarine"; shipValue = 2; break;
        case PATROL: shipType = "Patrol Boat"; shipValue = 1; break;
    }

    while (true) {
        cout << "Place the front of your " << shipType << ":" << endl;
        Coords c1 = getUserCoordShip(player);
        bool orientation = getUserOrientation();
        Coords c2 = {0, 0};

        if (orientation) {
            if (c1.x + shipValue < player.getLength()) {
                c2 = {c1.x + shipValue, c1.y};
            }
            else if (c1.y + shipValue < player.getWidth()) {
                cout << "No space. Ship has been placed vertically instead.";
                c2 = {c1.x, c1.y + shipValue};
            }
            else {
                cout << "Unable to place ship try again." << endl;
                continue;
            }
        }
        else {
            if (c1.y + shipValue < player.getWidth()) {
                c2 = {c1.x, c1.y + shipValue};
            }
            else if (c1.x + shipValue < player.getLength()) {
                cout << "No space. Ship has been placed horizontally instead.";
                c2 = {c1.x + shipValue, c1.y};
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

// printTopPlayer1()
// Prints player 1's top board.
void Game::printTopPlayer1() {
    cout << "Top Board: HITS and MISSES" << endl;
    for (size_t y=0; y < _playerOne.getWidth(); ++y) {
        for(size_t x=0; x < _playerOne.getLength(); ++x) {
            Coords c = {x,y};

            if(_playerTwo.isCoordTakenHits(c)) {
                cout << "X";
            }
            else if(_playerTwo.isCoordTakenFired(c)) {
                cout << "O";
            }
            else
                cout << "#";
        }
        cout << endl;
    }
}

// printBottomPlayer1()
// Prints player 1's bottom board.
void Game::printBottomPlayer1() {
    cout << "Bottom Board: SHIPS and ENEMY HITS" << endl;
    for (size_t y=0; y< _playerOne.getLength(); ++y)
    {
        for (size_t x = 0; x < _playerOne.getWidth(); ++x)
        {
            Coords c = {x,y};
            if(_playerOne.isCoordTakenHits(c))
                cout << "X";
            else if(_playerOne.isCoordTakenFired(c))
                cout << "O";
            else if(_playerOne.isCoordTakenShip(c))
                cout << "S";
            else
                cout << "~";
        }
        cout << endl;
    }
}

// printTopPlayer2()
// Prints player 2's top board.
void Game::printTopPlayer2(){
    cout << "Top Board: HITS and MISSES" << endl;
    for (size_t y=0; y < _playerTwo.getWidth(); ++y) {
        for(size_t x=0; x < _playerTwo.getLength(); ++x) {
            Coords c = {x,y};

            if(_playerOne.isCoordTakenHits(c)) {
                cout << "X";
            }
            else if(_playerOne.isCoordTakenFired(c)) {
                cout << "O";
            }
            else
                cout << "#";
        }
        cout << endl;
    }
    cout << endl;
}

// printBottomPlayer2()
// Prints player 2's bottom board.
void Game::printBottomPlayer2() {
    cout << "Bottom Board: SHIPS and ENEMY HITS" << endl;
    for (size_t y=0; y< _playerTwo.getLength(); ++y)
    {
        for (size_t x = 0; x < _playerTwo.getWidth(); ++x)
        {
            Coords c = {x,y};
            if(_playerTwo.isCoordTakenHits(c))
                cout << "X";
            else if(_playerTwo.isCoordTakenFired(c))
                cout << "O";
            else if(_playerTwo.isCoordTakenShip(c))
                cout << "S";
            else
                cout << "~";
        }
        cout << endl;
    }
}

// clearBoard()
// Clears the board.
void Game::clearBoard() const {
    cout << string(50, '\n');
}




