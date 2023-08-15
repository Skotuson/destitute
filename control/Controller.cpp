#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <cctype>
#include <cstdio>

#include "Controller.h"

void Controller::Read ( ) {
    struct termios oldt, newt;
    tcgetattr ( STDIN_FILENO, &oldt );
    
    newt = oldt;
    newt . c_lflag &= ~( ICANON | ECHO );

    tcsetattr ( STDIN_FILENO, TCSANOW, &newt );

    char c;
    while ( ! m_Quit ) {
        c = getchar ( );
        if ( ! isspace ( c ) ) {
            printf ( "=> %c\n", c );
            m_Buffer . push ( c );
        }
    }

    tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
}

char Controller::Peek ( void ) {
    if ( ! m_Buffer . empty ( ) )
        return m_Buffer . front ( );
    return '\0';
}

char Controller::Get ( void ) {
    if ( ! m_Buffer . empty ( ) ) {
        char f = m_Buffer . front ( );
        m_Buffer . pop ( );
        return f;
    }
    return '\0';
}

size_t Controller::GetBufferSize ( void ) {
    return m_Buffer . size ( );
}

void Controller::Kill ( void ) {
    m_Quit = true;
}