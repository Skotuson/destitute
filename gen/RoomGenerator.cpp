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

Room * RoomGenerator::GenerateRoom ( Direction entryDir, RoomInfo prevRoom ) {
    Layout m_Room;

    //Lambda function
    auto GetDoorsDir = []( const std::map<Direction,Point> & doors, const Point & pt ) {
        for ( const auto & d : doors )
            if ( d . second == pt ) return d . first;
        return Direction::NOP;
    };

    auto DoorTranslate = []( Point pt, Direction dir ){
        return Translate ( pt, GetDirectionVector ( GetOppositeDirection ( dir ) ) );
    };

    //Generate dimensions
    int rows = RandomNumber ( MIN_ROOM_SIZE, MAX_ROOM_SIZE );
    int cols = rows * 2;

    Room * room = new Room ( );

    //Generate doors        
    std::map<Direction, Point> doors;
    
    //Create return to previous room
    if ( entryDir != Direction::NOP ) {
        Direction dir = GetOppositeDirection ( entryDir );
        Point randomDoors = GetRandomDoor ( rows, cols, dir );
        doors . insert ( { dir, randomDoors } );
        room -> AddAdjacent ( prevRoom, dir );
        prevRoom . first -> AddAdjacent ( { room, DoorTranslate ( randomDoors, dir ) }, entryDir );
    }

    //Random generate doors
    for ( size_t i = 0; DIRECTION_ITERATOR[i] != Direction::NOP; i++ )
        if (    m_GeneratedRooms < MAX_ROOMS
             && RandomNumber ( 0, MAX_ROOMS ) >= m_GeneratedRooms 
             && ! doors . count ( DIRECTION_ITERATOR[i] ) )
        {
            m_GeneratedRooms++;
            //Log generated door
            Point randomDoors = GetRandomDoor ( rows, cols, DIRECTION_ITERATOR[i] );
            doors . insert ( { DIRECTION_ITERATOR[i], randomDoors } );
            //Register neigbouring room ( using side-effect in recursive GenerateRoom call )
            GenerateRoom ( DIRECTION_ITERATOR[i], 
                { room, DoorTranslate ( randomDoors, DIRECTION_ITERATOR[i] ) } );
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
                //Check whether there are doors at [j,i] coords
                Direction dir = GetDoorsDir ( doors, { j, i } );
                if ( dir == Direction::UP || dir == Direction::DOWN ) 
                    m_Room[i] . push_back ( TileFactory::Create ( '-', dir ) );
                else if ( dir == Direction::LEFT || dir == Direction::RIGHT )
                    m_Room[i] . push_back ( TileFactory::Create ( '|', dir ) );
                else m_Room[i] . push_back ( TileFactory::Create ( '#' ) );
            }
            else m_Room[i] . push_back ( TileFactory::Create ( ' ' ) );
        }
    }

    room -> SetLayout ( m_Room );

    return room;
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