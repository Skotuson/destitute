#include "Utility.h"

void stripCR ( std::string & str ) {
    if ( str[ str . length ( ) - 1 ] == '\r' )
        str . pop_back ( );
}