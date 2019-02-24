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
std::size_t Ship::getLength() {
    if (_end.x - _begin.x == 0) {
        _orientation = false;
        return _end.y - _begin.y + 1;
    }
    _orientation = true;
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
void Ship::attack(const Coords& c) {
    if (c.x <= _end.x && c.y <= _end.y) {
        if (_orientation) {
            _hits[_hits.size() - _end.x - c.x - 1] = true;
        }
        else {
            _hits[_hits.size() - _end.y - c.y - 1] = true;
        }
    }
}

// isSunk()
// Returns true if entire ship has been hit.
bool Ship::isSunk() const {
    for (auto i : _hits) {
        if (!i)
            return false;
    }
    return true;
}


