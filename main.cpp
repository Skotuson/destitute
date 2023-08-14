#include <iostream>
#include <unistd.h>
#include <thread>

#include "control/Controller.h"

int main ( void ) {
    Controller cntrl;
    std::thread input ( &Controller::Read, cntrl );

    while ( 42 ) {
        usleep ( 500'000 );
        if ( cntrl . Peek ( ) )
            std::cout << cntrl . Peek ( ) << std::endl;
        if ( cntrl . Peek ( ) == 'x' ) break;
    }

    input . join ( );
    return 0;
}