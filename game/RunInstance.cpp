#include <iostream>

#include "RunInstance.h"
#include "../level/LevelView.h"
#include "../control/Controller.h"

RunInstance::RunInstance ( Level * level, const std::vector<Entity *> & entities )
: m_Level    ( level ),
  m_Entities ( entities ),
  m_Player   ( entities[0] )
{}

void RunInstance::Run ( void ) {
    while ( true ) {
        HandleInteraction ( );
        std::cout << Draw::RETURN_CURSOR;
        LevelView::View ( *m_Level, m_Entities );
        std::cout << "Balance: " << m_Balance << std::endl;
        if ( Controller::Peek ( ) ) {
            if ( Controller::Peek ( ) == EXIT_CHAR )
                break;
            Direction dir = KeyToDirection ( Controller::Get ( ) );
            Point futureCoords = Translate ( m_Player -> GetCoords ( ), GetDirectionVector ( dir ) );
            if ( m_Level -> GetTile ( futureCoords ) -> Interact ( ) != Action::STOP )
                m_Player -> Move ( dir );
        }
    }
}

void RunInstance::HandleInteraction ( void ) {
    Action action = m_Level -> GetTile ( m_Player -> GetCoords ( ) ) -> Interact ( );
    switch ( action ) {
        case Action::LOOT:
            //TODO: Remove hardcoded
            m_Balance += 100;
            m_Level -> EmptyTile ( m_Player -> GetCoords ( ) );
            break;
        case Action::DOOR_UP:
        case Action::DOOR_DOWN:
        case Action::DOOR_LEFT:
        case Action::DOOR_RIGHT:
        case Action::STOP:
        case Action::NOP:
        default:
            break;
    }
}