#ifndef TILE_H
#define TILE_H

#include <ostream>

#include "../draw/Draw.h"

enum class Action { NOP, STOP, LOOT };

class Tile {
    public: 
                               Tile        ( char           look,
                                             Color          color = Draw::COLOR_DEFAULT );
        virtual               ~Tile        ( void );
        virtual Action         Interact    ( void );
        friend  std::ostream & operator << ( std::ostream & os, 
                                             const Tile   & t );
    private:
        char  m_Look;
        Color m_Color;
};

#endif 