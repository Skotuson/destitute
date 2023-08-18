#include "RunInstance.h"

RunInstance::RunInstance ( Level * level, std::vector<Entity *> & entities )
: m_Level    ( level ),
  m_Entities ( entities )
{}