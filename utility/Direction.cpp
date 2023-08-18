#include "Direction.h"

Direction KeyToDirection ( char key ) {
    switch ( key ) {
        case 'w' : return Direction::UP;
        case 'a' : return Direction::LEFT;
        case 's' : return Direction::DOWN;
        case 'd' : return Direction::RIGHT;
        default  : return Direction::NOP;
    }
}