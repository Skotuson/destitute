#include "Entity.h"

#include <iostream>

Entity::Entity ( char look, Point coords = { 0, 0 } )
: m_Look   ( look ),
  m_Coords ( coords )
{}

void Entity::Move ( Direction dir ) {
    switch ( dir ) {
        case Direction::UP:
            m_Coords = { m_Coords['x'], m_Coords['y'] - 1 };
            break;
        case Direction::DOWN:
            m_Coords = { m_Coords['x'], m_Coords['y'] + 1 };
            break;
        case Direction::LEFT:
            m_Coords = { m_Coords['x'] - 1, m_Coords['y'] };
            break;
        case Direction::RIGHT:
            m_Coords = { m_Coords['x'] + 1, m_Coords['y'] };
            break;
        case Direction::NOP:
        default:
            break;
    }
}

Point Entity::GetCoords ( void ) {
    return m_Coords;
}

void Entity::Interact ( Action action ) {
    
}

bool Entity::IsAt ( Point pt ) {
    return m_Coords == pt;
}

std::ostream & operator << ( std::ostream & os, const Entity & e ) {
    return os << e . m_Look;
}