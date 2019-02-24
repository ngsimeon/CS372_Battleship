// ship.cpp
// Simeon Ng
// Jason Herning
// Updated: 2/23/19
// Ship Class Source File

#include "ship.h"

// 2-Parameter ctor
Ship::Ship(Coords c1, Coords c2) :
    _begin(c1), _end(c2) {
    _hits.resize(this->getLength());
}

// getLength()
// Returns ship length
std::size_t Ship::getLength() const {
    if (_end.x - _begin.x == 0) {
        return _end.y - _begin.y + 1;
    }
    return _end.x - _begin.x + 1;

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


