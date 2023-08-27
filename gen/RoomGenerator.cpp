#include "RoomGenerator.h"

#include <iostream>
#include <vector>

#include "../level/TileFactory.h"
#include "../utility/Utility.h"

Room * RoomGenerator::Generate ( void ) {
    RoomGenerator::m_GeneratedRooms = 0;
    return GenerateRoom ( );
}

Room * RoomGenerator::GenerateRoom ( void ) {
    Layout m_Room;
    //Seed the PRNG
    srand ( time ( nullptr ) );
    //Generate dimensions
    int rows = rand ( ) % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
    int cols = rows * 2;

    //Generate doors
    std::map<Direction, Point> doors;
    for ( size_t i = 0; DIRECTION_ITERATOR[i] != Direction::NOP; i++ )
        if ( RandomNumber ( 0, 5 ) == 3 )
            doors . insert ( { DIRECTION_ITERATOR[i], Point ( RandomNumber ( 1, cols - 2 ), RandomNumber ( 1, rows - 2 ) ) } );
    
    //Generate layout
    for ( int i = 0; i < rows; i++ ) {
        m_Room . push_back ( std::vector<Tile *> ( ) );
        for ( int j = 0; j < cols; j++ ) {
            //Outer walls
            if (    ! j || ! i 
                 || j == ( cols - 1 ) || i == ( rows - 1 ) 
                 || RandomNumber ( 1, rows ) == i ) 
            {
                m_Room[i] . push_back ( TileFactory::Create ( '#' ) );
            }
            else m_Room[i] . push_back ( TileFactory::Create ( ' ' ) );
        }
    }

    return new Room ( m_Room );
}

Point RoomGenerator::GetRandomDoor ( Direction dir ) {
    
}