#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "Tile.h"
#include "../utility/Point.h"

using Layout = std::vector<std::vector<Tile *>>;

class Room {
    public:
        void   Load    ( const std::string & filename );
        Tile * GetTile ( Point             & pt );
    private:
        Layout m_Layout;
    
};

#endif