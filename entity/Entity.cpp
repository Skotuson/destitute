#include "Entity.h"

#include <iostream>

Entity::Entity ( char look, Point coords = { 0, 0 } )
: m_Look   ( look ),
  m_Coords ( coords )
{}

Point Entity::Move ( Direction dir ) {
    Point coords ( 0, 0 );
    switch ( dir ) {
        case Direction::UP:
            coords = { m_Coords['x'], m_Coords['y'] - 1 };
            break;
        case Direction::DOWN:
            coords = { m_Coords['x'], m_Coords['y'] + 1 };
            break;
        case Direction::LEFT:
            coords = { m_Coords['x'] - 1, m_Coords['y'] };
            break;
        case Direction::RIGHT:
            coords = { m_Coords['x'] + 1, m_Coords['y'] };
            break;
        case Direction::NOP:
        default:
            return m_Coords;
    }
    return coords;
}

void Entity::Interact ( Action action ) {
    
}

bool Entity::IsAt ( Point pt ) {
    return m_Coords == pt;
}

std::ostream & operator << ( std::ostream & os, const Entity & e ) {
    return os << e . m_Look;
}