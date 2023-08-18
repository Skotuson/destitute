#include "Direction.h"

Direction keyToDirection ( char key ) {
    switch ( key ) {
        case 'W' : return Direction::UP;
        case 'S' : return Direction::DOWN;
        case 'A' : return Direction::LEFT;
        case 'D' : return Direction::RIGHT;
        default  : return Direction::NOP;
    }
}