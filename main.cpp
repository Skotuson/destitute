#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "level/LevelView.h"
#include "entity/Human.h"
#include "level/Level.h"
#include "draw/Draw.h"

int main ( void ) {
    std::cout << Draw::CLEAR_SCREEN << Draw::HIDE_CURSOR;
    Level l;
    l . Load ( "level/examples/vault.txt" );

    std::vector<Entity *> v = { new Human ( '&', { 7, 4 } ) };
    
    std::thread input ( Controller::Read );
    while ( true ) {
        std::cout << Draw::RETURN_CURSOR;
        LevelView::View ( l, v );
        if ( Controller::Peek ( ) ) {
            if ( Controller::Peek ( ) == EXIT_CHAR )
                break;
            v[0] -> Move ( keyToDirection ( Controller::Get ( ) ) );
        }
    }
    
    input . join ( );

    std::cout << Draw::SHOW_CURSOR;

    return 0;
}