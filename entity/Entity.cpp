#include "Entity.h"

Entity::Entity ( char look, Point coords = { 0, 0 } )
: m_Look   ( look ),
  m_Coords ( coords )
{}

void Entity::Move ( Direction dir ) {
    
}

std::ostream & operator << ( std::ostream & os, const Entity & e ) {
    return os << e . m_Look;
}