#include "TileFactory.h"

#include "WallTile.h"
#include "LootTile.h"
#include "DoorTile.h"

#include "../draw/Draw.h"

Tile * TileFactory::Create ( char c, Direction dir ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
        case '$': return new LootTile ( c );
        case '-': return new DoorTile ( c, Draw::COLOR_BROWN, dir );
        case '|': return new DoorTile ( c, Draw::COLOR_BROWN, dir );
        default : return new Tile ( c );
    }
}