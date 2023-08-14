#include <iostream>
#include <thread>

#include "control/Controller.h"

int main ( void ) {
    Controller cntrl;
    std::thread input ( &Controller::Read, cntrl );

    while ( cntrl . Peek ( ) != 'x' && cntrl . Peek ( ) ) {
        std::cout << cntrl . Get ( ) << std::endl;
    }

    input . join ( );
    return 0;
}