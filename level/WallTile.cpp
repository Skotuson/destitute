#include "WallTile.h"

WallTile::WallTile ( char look )
: Tile ( look )
{}

WallTile::~WallTile ( void )
{
}

Action WallTile::Interact ( void ) {
    return Action::STOP;
}