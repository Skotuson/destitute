#include "DoorTile.h"

DoorTile::DoorTile ( char look, Color color, Direction dir )
: Tile ( look, color ),
  m_Dir ( dir )
{}

DoorTile::~DoorTile ( void )
{
}

Action DoorTile::Interact ( void ) {
    switch ( m_Dir ) {
        case Direction::UP:
            return Action::DOOR_UP;
        case Direction::DOWN:
            return Action::DOOR_DOWN;
        case Direction::LEFT:
            return Action::DOOR_LEFT;
        case Direction::RIGHT:
            return Action::DOOR_RIGHT;
        default: return Action::NOP;
    }
}

Direction DoorTile::GetDir ( void ) {
    return m_Dir;
}

void DoorTile::SetOut ( Point out ) {
    m_Out = out;
}

void DoorTile::ReverseDir ( void ) {
    m_Dir = GetOppositeDirection ( m_Dir );
}