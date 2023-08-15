#include <fstream>
#include <iostream>

#include "Level.h"
#include "../utility/Utility.h"

void Level::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    if ( ifs . fail ( ) )
        throw new std::runtime_error ( "Invalid file" );

    std::string buffer;
    while ( std::getline ( ifs, buffer ) ) {
        stripCR ( buffer );
        for ( const auto & c : buffer )
            std::cout << (int) c << " ";
        std::cout << std::endl;
    }
}