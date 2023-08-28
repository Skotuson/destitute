#include <iostream>
#include <fstream>
#include <cassert>

#include "Room.h"
#include "../utility/Utility.h"
#include "../level/TileFactory.h"

Room::Room ( const Layout & layout )
: m_Layout ( std::move ( layout ) )
{}

Room::~Room ( void ) {
    for ( const auto & row : m_Layout ) 
        for ( const auto & col : row )
            delete col;
    for ( const auto & room : m_AdjacentRooms ) {
        //Disconnect pointer
        room . second . first -> m_AdjacentRooms . erase ( GetOppositeDirection ( room . first ) );
        delete room . second . first;
    }
}

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

const Layout & Room::GetLayout ( void ) {
    return m_Layout;
}

void Room::SetLayout ( const Layout & layout ) {
    m_Layout = layout;
}

void Room::AddAdjacent ( RoomInfo adj, Direction dir ) {
    m_AdjacentRooms . insert ( { dir, adj } );
}

RoomInfo Room::GetAdjacent ( Direction dir ) {
    auto it = m_AdjacentRooms . find ( dir );
    assert ( it != m_AdjacentRooms . end ( ) );
    return it -> second;
}

Tile * Room::GetTile ( Point pt ) {
    return m_Layout[pt['y']][pt['x']];
}

void Room::EmptyTile ( Point pt ) {
    //Empty Tile
    Tile * t = TileFactory::Create ( );
    delete m_Layout[pt['y']][pt['x']];
    m_Layout[pt['y']][pt['x']] = t;
}

void Room::Print ( void ) {
    for ( const auto & row : m_Layout ) {
        for ( const auto & col : row )
            std::cout << *col;
        std::cout << std::endl;
    }
}