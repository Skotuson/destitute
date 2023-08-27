#include "RoomGenerator.h"

#include <iostream>
#include <vector>

#include "../level/TileFactory.h"
#include "../utility/Utility.h"

Room * RoomGenerator::Generate ( void ) {
    //Reset generated rooms count
    RoomGenerator::m_GeneratedRooms = 0;
    //Seed the PRNG
    srand ( time ( nullptr ) );
    return GenerateRoom ( );
}

Room * RoomGenerator::GenerateRoom ( void ) {
    Layout m_Room;
    //Generate dimensions
    int rows = rand ( ) % MAX_ROOM_SIZE + MIN_ROOM_SIZE;
    int cols = rows * 2;

    //Generate doors
    std::map<Direction, Point> doors;
    for ( size_t i = 0; DIRECTION_ITERATOR[i] != Direction::NOP; i++ )
        if ( RandomNumber ( 0, 5 ) == 3 && m_GeneratedRooms <= MAX_ROOMS ) {
            m_GeneratedRooms++;
            doors . insert ( { DIRECTION_ITERATOR[i], GetRandomDoor ( rows, cols, DIRECTION_ITERATOR[i] ) } );
        }
    
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

Point RoomGenerator::GetRandomDoor ( int rows, int cols, Direction dir ) {
    Point doors ( RandomNumber ( 1, cols - 2 ), RandomNumber ( 1, rows - 2 ) );
    switch ( dir ) {
        case Direction::UP:
            doors . m_Y = 0;
            break;
        case Direction::DOWN:
            doors . m_Y = rows - 1;
            break;
        case Direction::LEFT:
            doors . m_X = 0;
            break;
        case Direction::RIGHT:
            doors . m_X = cols - 1;
            break;
        case Direction::NOP:
            return { 0, 0 };
    }    
    return doors;
}