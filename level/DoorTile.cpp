#include "DoorTile.h"

DoorTile::DoorTile ( char look, Color color, Direction dir )
: Tile ( look, color ),
  m_Dir ( dir )
{}

DoorTile::~DoorTile ( void )
{
}

Action DoorTile::Interact ( void ) {
    return Action::DOOR;
}

Direction DoorTile::GetDir ( void ) {
    return m_Dir;
}

void DoorTile::ReverseDir ( void ) {
    m_Dir = GetOppositeDirection ( m_Dir );
}