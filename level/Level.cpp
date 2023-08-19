#include <fstream>
#include <iostream>

#include "Level.h"
#include "TileFactory.h"
#include "../utility/Utility.h"

Level::~Level ( void ) {
    for ( const auto & row : m_Level ) 
        for ( const auto & col : row )
            delete col;
}

void Level::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    if ( ifs . fail ( ) )
        throw new std::runtime_error ( "Invalid file" );

    std::string buffer;
    while ( std::getline ( ifs, buffer ) ) {
        m_Level . push_back ( std::vector<Tile *> ( ) );
        stripCR ( buffer );
        
        for ( const auto & c : buffer )
            m_Level[m_Level . size ( ) - 1] . push_back ( TileFactory::Create ( c ) );
    }
}

const Layout & Level::GetLayout ( void ) {
    return m_Level;
}

Tile * Level::GetTile ( Point pt ) {
    return m_Level[pt['y']][pt['x']];
}

void Level::EmptyTile ( Point pt ) {
    //Empty Tile
    Tile * t = TileFactory::Create ( );
    delete m_Level[pt['y']][pt['x']];
    m_Level[pt['y']][pt['x']] = t;
}

void Level::Print ( void ) {
    for ( const auto & row : m_Level ) {
        for ( const auto & col : row )
            std::cout << *col;
        std::cout << std::endl;
    }

}