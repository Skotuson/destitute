#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

Direction keyToDirection ( char key );

#endif