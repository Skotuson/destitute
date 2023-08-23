#include "RoomGenerator.h"

#include <iostream>
#include <vector>

#include "../level/TileFactory.h"
#include "../utility/Utility.h"

Room * RoomGenerator::Generate ( void ) {
    return nullptr;
}

Room * RoomGenerator::GenerateRoom ( void ) {
    Layout m_Room;
    srand ( time ( nullptr ) );
    int n = rand ( ) % MAX_ROOM_SIZE + MIN_ROOM_SIZE;

    //Generate layout
    for ( int i = 0; i < n; i++ ) {
        m_Room . push_back ( std::vector<Tile *> ( ) );
        for ( int j = 0; j < n * 2; j++ ) {
            //Outer walls
            if (    ! j || ! i 
                 || j == ( n * 2 - 1 ) || i == ( n - 1 ) 
                 || RandomNumber ( 1, n ) == i ) 
                 {
                    m_Room[i] . push_back ( TileFactory::Create ( '#' ) );
                 }
            else m_Room[i] . push_back ( TileFactory::Create ( ' ' ) );
        }
    }

    return new Room ( m_Room );
}