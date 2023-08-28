#include "Draw.h"

#include <iostream>

void Draw::ClearScreen ( void ) {
    std::cout << RETURN_CURSOR << CLEAR_SCREEN;
}