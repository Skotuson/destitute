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

Direction GetOppositeDirection ( Direction dir ) {
    switch ( dir ) {
        case Direction::UP:
            return Direction::DOWN;
        case Direction::DOWN:
            return Direction::UP;
        case Direction::LEFT:
            return Direction::RIGHT;
        case Direction::RIGHT:
            return Direction::LEFT;
        case Direction::NOP:
        default:
            return dir;
        }
}

Point GetDirectionVector ( Direction dir ) {
    switch ( dir ) {
        case Direction::UP:
            return { 0, -1 };
        case Direction::DOWN:
            return { 0, 1 };
        case Direction::LEFT:
            return { -1, 0 };
        case Direction::RIGHT:
            return { 1, 0 };
        case Direction::NOP:
        default:
            return { 0, 0 };
    }
}

Point Translate ( Point pt, Point translation ) {
    return { pt['x'] + translation['x'], pt['y'] + translation['y'] };
}