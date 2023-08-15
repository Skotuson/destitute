#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "level/Level.h"

int main ( void ) {
    
    Level l;
    l . Load ( "level/examples/vault.txt" );
    l . Print ( );
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

    return 0;
}