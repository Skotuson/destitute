#include <fstream>
#include <iostream>

#include "Level.h"
#include "TileFactory.h"
#include "../utility/Utility.h"

Level::Level ( Room * room )
: m_Room ( room )
{}

Level::~Level ( void ) {
    delete m_Room;
}

const Layout & Level::GetLayout ( void ) {
    return m_Room -> GetLayout ( );
}

void Level::ChangeRoom ( Direction dir ) {
    m_Room = m_Room -> GetAdjacent ( dir );
}

Tile * Level::GetTile ( Point pt ) {
    return m_Room -> GetTile ( pt );
}

void Level::EmptyTile ( Point pt ) {
    return m_Room -> EmptyTile ( pt );
}