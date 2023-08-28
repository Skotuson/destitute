#include "Tile.h"

Tile::Tile ( char look, Color color )
: m_Look  ( look ),
  m_Color ( color )
{}

Tile::~Tile ( void )
{
}

Action Tile::Interact ( void ) {
    return Action::NOP;
}

Direction Tile::GetDir ( void ) {
    return Direction::NOP;
}

std::ostream & operator << ( std::ostream & os, const Tile   & t ) {
    return ( os << t . m_Color << t . m_Look << Draw::COLOR_DEFAULT );
}