#ifndef UTILITY_H
#define UTILITY_H

#include <string>

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NOP
};

void stripCR ( std::string & str );

#endif