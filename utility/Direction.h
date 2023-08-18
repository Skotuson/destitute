#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

Direction KeyToDirection ( char key );

#endif