#include "Tile.h"

Tile::Tile ( char look )
: m_Look ( look )
{}

Tile::~Tile ( void )
{
}

Action Tile::Interact ( void ) {
    return Action::NOP;
}

std::ostream & operator << ( std::ostream & os, const Tile   & t ) {
    return ( os << t . m_Look );
}