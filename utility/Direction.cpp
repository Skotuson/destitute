#include "Direction.h"

Direction keyToDirection ( char key ) {
    switch ( key ) {
        case 'w' : return Direction::UP;
        case 'a' : return Direction::LEFT;
        case 's' : return Direction::DOWN;
        case 'd' : return Direction::RIGHT;
        default  : return Direction::NOP;
    }
}