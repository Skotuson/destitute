#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "level/LevelView.h"
#include "level/Level.h"
#include "entity/Human.h"

int main ( void ) {
    //std::thread input ( Controller::Read );
    //while ( true ) {
    //    if ( Controller::Peek ( ) ) {
    //        if ( Controller::Peek ( ) == EXIT_CHAR )
    //            break;
    //        std::cout << Controller::Get ( ) << std::endl;
    //    }
    //}
    //
    //input . join ( );

    Level l;
    l . Load ( "level/examples/vault.txt" );

    std::vector<Entity *> v = { new Human ( '&', { 2, 5 } ) };
    LevelView::View ( l, v );

    return 0;
}