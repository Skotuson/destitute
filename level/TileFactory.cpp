#include "TileFactory.h"

#include "WallTile.h"

Tile * TileFactory::CreateTile ( char c ) {
    switch ( c ) {
        case '#': return new WallTile ( c );
    }
}