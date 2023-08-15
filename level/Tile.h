#ifndef TILE_H
#define TILE_H

#include <ostream>

enum class Action { NOP, STOP };

class Tile {
    public: 
                               Tile        ( char           look );
        virtual Action         Interact    ( void );
        friend  std::ostream & operator << ( std::ostream & os, 
                                             const Tile   & t );
    private:
        char m_Look;
};

#endif 