#include "Entity.h"

#include <iostream>

Entity::Entity ( char look, Point coords = { 0, 0 } )
: m_Look   ( look ),
  m_Coords ( coords )
{}

Point Entity::Move ( Direction dir ) {
    switch ( dir ) {
        case Direction::UP:
            m_Coords = { m_Coords['x'], m_Coords['y'] - 1 };
            return { 0, -1 };
        case Direction::DOWN:
            m_Coords = { m_Coords['x'], m_Coords['y'] + 1 };
            return { 0, 1 };
        case Direction::LEFT:
            m_Coords = { m_Coords['x'] - 1, m_Coords['y'] };
            return { -1, 0 };
        case Direction::RIGHT:
            m_Coords = { m_Coords['x'] + 1, m_Coords['y'] };
            return { 1, 0 };
        case Direction::NOP:
        default:
            return { 0, 0 };
    }
}

bool Entity::IsAt ( Point pt ) {
    return m_Coords == pt;
}

std::ostream & operator << ( std::ostream & os, const Entity & e ) {
    return os << e . m_Look;
}