#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include "Tile.h"
#include "../utility/Direction.h"

class TileFactory {
    public:
        static Tile * Create ( char      c = ' ',
                               Direction dir = Direction::NOP );
    private:
};

#endif