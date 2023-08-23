#ifndef DIRECTION_H
#define DIRECTION_H

#include "Point.h"

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

Direction KeyToDirection       ( char      key );

Direction GetOppositeDirection ( Direction dir );

Point     GetDirectionVector   ( Direction dir );

Point     Translate            ( Point     pt, 
                                 Point     translation );

#endif