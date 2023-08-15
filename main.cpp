#include <iostream>
#include <thread>

#include "control/Controller.h"

int main ( void ) {
    Controller cntrl;
    std::thread input ( &Controller::Read, std::ref ( cntrl ) );

    while ( 42 ) {
        if ( cntrl . Peek ( ) ) {
            if ( cntrl . Peek ( ) == 'x' ) break;
            std::cout << cntrl . Get ( ) << std::endl;
        }
    }

    std::cout << "Loop Done" << std::endl;
    cntrl . Kill ( );

    input . join ( );
    return 0;
}