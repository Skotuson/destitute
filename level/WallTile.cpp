#include "WallTile.h"

WallTile::WallTile ( char look, Color color )
: Tile ( look, color )
{}

WallTile::~WallTile ( void )
{
}

Action WallTile::Interact ( void ) {
    return Action::STOP;
}