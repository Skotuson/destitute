#include "LootTile.h"

LootTile::LootTile ( char look )
: Tile ( look )
{}

LootTile::~LootTile ( void )
{
}

Action LootTile::Interact ( void ) {
    return Action::LOOT;
}