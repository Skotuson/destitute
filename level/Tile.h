#ifndef TILE_H
#define TILE_H

#include <ostream>

#include "../draw/Draw.h"
#include "../game/Action.h"
#include "../utility/Direction.h"

class Tile {
    public: 
                               Tile        ( char           look,
                                             Color          color = Draw::COLOR_DEFAULT );
        virtual               ~Tile        ( void );
        virtual Action         Interact    ( void );
        virtual Direction      GetDir      ( void );
        friend  std::ostream & operator << ( std::ostream & os, 
                                             const Tile   & t );
    private:
        char  m_Look;
        Color m_Color;
};

#endif 