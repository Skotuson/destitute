#include "TileFactory.h"

#include "WallTile.h"
#include "LootTile.h"
#include "DoorTile.h"

#include "../draw/Draw.h"

Tile * TileFactory::Create ( char c ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
        case '$': return new LootTile ( c );
        case '-': return new DoorTile ( c, Draw::COLOR_BROWN, Direction::UP );
        case '|': return new DoorTile ( c, Draw::COLOR_BROWN, Direction::DOWN );
        default : return new Tile ( c );
    }
}