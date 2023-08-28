#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <vector>

#include "Tile.h"
#include "../utility/Point.h"
#include "../utility/Direction.h"

//forward declare for using
class Room;

using Layout   = std::vector<std::vector<Tile *>>;
using RoomInfo = std::pair<Room *, Point>;

class Room {
    public:
                       Room        ( const Layout      & layout = std::vector<std::vector<Tile*>> ( ) );
                      ~Room        ( void );
        void           Load        ( const std::string & filename );
        const Layout & GetLayout   ( void );
        void           SetLayout   ( const Layout      & layout );
        void           AddAdjacent ( RoomInfo            adj,
                                     Direction           dir );
        RoomInfo       GetAdjacent ( Direction           dir );
        Tile         * GetTile     ( Point               pt );
        void           EmptyTile   ( Point               pt );
        void           Print       ( void );
    private:
        Layout                        m_Layout;
        std::map<Direction, RoomInfo> m_AdjacentRooms;
    
};

#endif