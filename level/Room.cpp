#include <fstream>

#include "Room.h"
#include "../utility/Utility.h"
#include "../level/TileFactory.h"

void Room::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    if ( ifs . fail ( ) )
        throw new std::runtime_error ( "Invalid file" );

    std::string buffer;
    while ( std::getline ( ifs, buffer ) ) {
        m_Layout . push_back ( std::vector<Tile *> ( ) );
        stripCR ( buffer );
        
        for ( const auto & c : buffer )
            m_Layout[m_Layout . size ( ) - 1] . push_back ( TileFactory::Create ( c ) );
    }
}

Tile * Room::GetTile ( Point & pt ) {
    return m_Layout[pt['y']][pt['x']];
}