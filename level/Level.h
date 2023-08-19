#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "Tile.h"
#include "../utility/Point.h"

using Layout = std::vector<std::vector<Tile *>>;

class Level {
    public:
                      ~Level     ( void );
        void           Load      ( const std::string & filename );
        const Layout & GetLayout ( void );
        Tile         * GetTile   ( Point               pt );
        void           Print     ( void );
    private:
        Layout m_Level;
};

#endif