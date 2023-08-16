#include <stdexcept>

#include "Point.h"

Point::Point ( int x, int y ) 
: m_X ( x ),
  m_Y ( y )
{}

int Point::operator [] ( char coord ) {
    switch ( coord ) {
        case 'x':
        case 'X':
            return m_X;
        case 'y':
        case 'Y':
            return m_Y;
        default:
            throw new std::runtime_error ( "Invalid axis" );
            return 0;
    }
}