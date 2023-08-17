#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "level/LevelView.h"
#include "level/Level.h"

int main ( void ) {
    //Controller cntrl;
    //std::thread input ( &Controller::Read, std::ref ( cntrl ) );
    //while ( true ) {
    //    if ( cntrl . Peek ( ) ) {
    //        if ( cntrl . Peek ( ) == EXIT_CHAR )
    //            break;
    //        std::cout << cntrl . Get ( ) << std::endl;
    //    }
    //}
    //
    //input . join ( );

    Level l;
    l . Load ( "level/examples/vault.txt" );

    std::vector<Entity *> v;
    LevelView::View ( l, v );

    return 0;
}