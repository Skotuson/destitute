#include "Entity.h"

Entity::Entity ( char look, Point coords = { 0, 0 } )
: m_Look   ( look ),
  m_Coords ( coords )
{}