#include "TileFactory.h"

#include "WallTile.h"

Tile * TileFactory::Create ( char c ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
        default: return new Tile ( c );
    }
}