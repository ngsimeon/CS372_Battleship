// ship.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/22/19
// Ship Class Source File

#include "ship.h"

// 2-Parameter ctor
Ship::Ship(size_t len, Coords c1, Coords c2) :
    _length(len), _begin(c1), _end(c2) {
    _hits.resize(_length);
}

// getLength()
// Returns ship length
std::size_t Ship::getLength() const {
    return _length;
}

// getBegin()
// Returns ships beginning coordinate.
Coords Ship::getBegin() const {
    return _begin;
}

// getEnd()
// Returns ships ending coordinate.
Coords Ship::getEnd() const {
    return _end;
}

// attack()
// Attacks the ship. If true, the position on the ship has been hit.
void Ship::attack(const size_t& position) {
    _hits[position] = true;
}

// getHits()
// Returns if a position on the ship has been hit.
bool Ship::getHits(const size_t& position) const {
    return _hits[position];
}


