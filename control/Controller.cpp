#include <iostream>

#include "Controller.h"

void Controller::Read ( ) {
    while ( 42 ) {
        char c;
        std::cin >> c;
        std::cout << GetBufferSize ( ) << std::endl;
        m_Buffer . push ( c );
    }
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