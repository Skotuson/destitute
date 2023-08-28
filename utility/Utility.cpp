#include "Utility.h"

void stripCR ( std::string & str ) {
    if ( str[ str . length ( ) - 1 ] == '\r' )
        str . pop_back ( );
}

int RandomNumber ( int lo, int hi ) {
    return rand( ) % ( hi - lo + 1 ) + lo;
}