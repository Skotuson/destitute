#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <vector>

#include "Tile.h"
#include "../utility/Point.h"
#include "../utility/Direction.h"

using Layout = std::vector<std::vector<Tile *>>;

class Room {
    public:
                       Room        ( const Layout      & layout = std::vector<std::vector<Tile*>> ( ) );
                      ~Room        ( void );
        void           Load        ( const std::string & filename );
        const Layout & GetLayout   ( void );
        void           SetLayout   ( const Layout      & layout );
        void           AddAdjacent ( Room              * adj,
                                     Direction           dir );
        Room         * GetAdjacent ( Direction           dir );
        Tile         * GetTile     ( Point               pt );
        void           EmptyTile   ( Point               pt );
        void           Print       ( void );
    private:
        Layout                      m_Layout;
        std::map<Direction, Room *> m_AdjacentRooms;
    
};

#endif