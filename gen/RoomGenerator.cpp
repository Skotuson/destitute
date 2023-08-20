#include "RoomGenerator.h"

#include <iostream>
#include <vector>

#include "../level/TileFactory.h"

Room * RoomGenerator::Generate ( void ) {
    std::vector<std::vector<Tile*>> m_Room;
    srand ( time ( nullptr ) );
    size_t n = rand ( ) % MAX_ROOM_SIZE + MIN_ROOM_SIZE;

    for ( size_t i = 0; i < n; i++ ) {
        m_Room . push_back ( std::vector<Tile*> ( ) );
        for ( size_t j = 0; j < n * 2; j++ ) {
            if (    ! j || ! i 
                 || j == ( n * 2 - 1 ) || i == ( n - 1 ) 
                 || ( rand ( ) % n ) == i ) 
                m_Room[i] . push_back ( TileFactory::Create ( '#' ) );
            else m_Room[i] . push_back ( TileFactory::Create ( ' ' ) );
        }
    }

    return new Room ( m_Room );
}