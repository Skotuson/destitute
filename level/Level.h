#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "Tile.h"
#include "Room.h"
#include "TileFactory.h"
#include "../utility/Point.h"

using Layout = std::vector<std::vector<Tile *>>;

class Level {
    public:
                       Level     ( Room * room );
                      ~Level     ( void );
        const Layout & GetLayout ( void );
        Tile         * GetTile   ( Point  pt );
        void           EmptyTile ( Point  pt );
    private:
        Room * m_Room;

};

#endif