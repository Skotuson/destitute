#include <iostream>
#include <thread>

#include "control/Controller.h"

int main ( void ) {
    Controller cntrl;
    std::thread input ( &Controller::Read, cntrl );

    input . join ( );
    return 0;
}