#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "Tile.h"

using Layout = std::vector<std::vector<Tile *>>;

class Level {
    public:
        void Load  ( const std::string & filename );
        void Print ( void );
    private:
        Layout m_Level;
};

#endif