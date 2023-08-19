#include "TileFactory.h"

#include "WallTile.h"
#include "LootTile.h"
#include "DoorTile.h"

Tile * TileFactory::Create ( char c ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
        case '$': return new LootTile ( c );
        case '-':
        case '|': return new DoorTile ( c );
        default : return new Tile ( c );
    }
}