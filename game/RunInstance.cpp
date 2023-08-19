#include <iostream>

#include "RunInstance.h"
#include "../level/LevelView.h"
#include "../control/Controller.h"

RunInstance::RunInstance ( Level * level, const std::vector<Entity *> & entities )
: m_Level    ( level ),
  m_Entities ( entities )
{}

void RunInstance::Run ( void ) {
    while ( true ) {
        std::cout << Draw::RETURN_CURSOR;
        LevelView::View ( *m_Level, m_Entities );
        if ( Controller::Peek ( ) ) {
            if ( Controller::Peek ( ) == EXIT_CHAR )
                break;
            m_Entities[0] -> Move ( KeyToDirection ( Controller::Get ( ) ) );
        }
    }
}