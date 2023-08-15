#include "WallTile.h"

WallTile::WallTile ( char look )
: Tile ( look )
{}

Action WallTile::Interact ( void ) {
    return Action::STOP;
}