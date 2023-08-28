#ifndef DOORTILE_H
#define DOORTILE_H

#include "Tile.h"
#include "../utility/Direction.h"

class DoorTile : public Tile {
    public:
                  DoorTile   ( char      look,
                               Color     color = Draw::COLOR_BROWN,
                               Direction dir   = Direction::NOP );
                 ~DoorTile   ( void );
        Action    Interact   ( void ) override;
        Direction GetDir     ( void ) override;
        void      SetOut     ( Point     out );
        void      ReverseDir ( void );
    private:
        Direction m_Dir;
        Point     m_Out = { 0, 0 };

};

#endif