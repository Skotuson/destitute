#include "Tile.h"

Tile::Tile ( char look )
: m_Look ( look )
{}

Action Tile::Interact ( void ) {
    return Action::NOP;
}