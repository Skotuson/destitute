#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>

#include "Point.h"

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

const std::vector<Direction> DIRECTION_ITERATOR = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT, Direction::NOP };

Direction KeyToDirection       ( char      key );

Direction GetOppositeDirection ( Direction dir );

Point     GetDirectionVector   ( Direction dir );

Point     Translate            ( Point     pt, 
                                 Point     translation );

#endif