#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "Tile.h"
#include "../utility/Point.h"

using Layout = std::vector<std::vector<Tile *>>;

class Room {
    public:
                       Room      ( const Layout      & layout = std::vector<std::vector<Tile*>> ( ) );
                      ~Room      ( void );
        void           Load      ( const std::string & filename );
        const Layout & GetLayout ( void );
        Tile         * GetTile   ( Point               pt );
        void           EmptyTile ( Point               pt );
        void           Print     ( void );
    private:
        Layout m_Layout;
    
};

#endif