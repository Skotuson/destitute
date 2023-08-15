#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "Tile.h"

class Level {
    public:
        void Load ( const std::string & filename );
    private:
        std::vector<std::vector<Tile *>> m_Level;
};

#endif