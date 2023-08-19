#include "DoorTile.h"

DoorTile::DoorTile ( char look, Color color )
: Tile ( look, color )
{}

DoorTile::~DoorTile ( void )
{
}

Action DoorTile::Interact ( void ) {
    return Action::STOP;
}