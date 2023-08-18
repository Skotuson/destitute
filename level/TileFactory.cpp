#include "TileFactory.h"

#include "WallTile.h"
#include "LootTile.h"

Tile * TileFactory::Create ( char c ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
        case '$': return new LootTile ( c );
        default: return new Tile ( c );
    }
}