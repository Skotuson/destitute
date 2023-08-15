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
        m_Level . push_back ( std::vector<Tile *> ( ) );
        stripCR ( buffer );
        
        for ( size_t i = 0; i < buffer . size ( ); i++ ) {
            
        }
        
    }
}