#include <iostream>
#include <unistd.h>
#include <thread>

#include "control/Controller.h"

int main ( void ) {
    Controller cntrl;
    std::thread input ( &Controller::Read, cntrl );

    while ( 42 ) {
        std::cout << "A" << std::endl;
        if ( cntrl . Peek ( ) )
            std::cout << cntrl . Get ( ) << std::endl;
        if ( cntrl . Peek ( ) == 'x' ) break;
    }

    input . join ( );
    return 0;
}