#include "LootTile.h"

LootTile::LootTile ( char look, Color color )
: Tile ( look, color )
{}

LootTile::~LootTile ( void )
{
}

Action LootTile::Interact ( void ) {
    return Action::LOOT;
}