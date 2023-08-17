#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include "Tile.h"

class TileFactory {
    public:
        static Tile * Create ( char c );
    private:
};

#endif