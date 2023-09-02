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
        HandleTileInteraction ( );
        std::cout << Draw::RETURN_CURSOR;
        LevelView::View ( *m_Level, m_Entities );
        std::cout << "Balance: " << m_Balance << std::endl;
        if ( Controller::Peek ( ) == EXIT_CHAR )
                break;
        if ( Controller::GetKeyType ( Controller::Peek ( ) ) == Controller::ControlType::MOVEMENT )
            HandleMovement ( );
        else if ( Controller::GetKeyType ( Controller::Peek ( ) ) == Controller::ControlType::ACTION )
            HandleAction ( );
        else Controller::Get ( );
    }
}

void RunInstance::HandleTileInteraction ( void ) {
    Tile * tile = m_Level -> GetTile ( m_Player -> GetCoords ( ) );
    Action action = tile -> Interact ( );
    switch ( action ) {
        case Action::LOOT:
            //TODO: Remove hardcoded
            m_Balance += 100;
            m_Level -> EmptyTile ( m_Player -> GetCoords ( ) );
            break;
        case Action::DOOR:
            Draw::ClearScreen ( );
            m_Level  -> ChangeRoom ( tile -> GetDir ( ) );
            m_Player -> SetCoords  ( m_Level -> StartPoint ( ) );
            break;
        case Action::STOP:
        case Action::NOP:
        default:
            break;
    }
}

void RunInstance::HandleMovement ( void ) {
    Direction dir = KeyToDirection ( Controller::Get ( ) );
    Point futureCoords = Translate ( m_Player -> GetCoords ( ), GetDirectionVector ( dir ) );
    if ( m_Level -> GetTile ( futureCoords ) -> Interact ( ) != Action::STOP )
        m_Player -> Move ( dir );
}

void RunInstance::HandleAction ( void ) {
    Action a = KeyToAction ( Controller::Get ( ) );
}