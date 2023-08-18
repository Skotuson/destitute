#ifndef DIRECTION_H
#define DIRECTION_H

#include "Point.h"

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

Direction KeyToDirection     ( char      key );

Point     GetDirectionVector ( Direction dir );

#endif