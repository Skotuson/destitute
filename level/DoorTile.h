#ifndef DOORTILE_H
#define DOORTILE_H

#include "Tile.h"
#include "../utility/Direction.h"

class DoorTile : public Tile {
    public:
               DoorTile ( char      look,
                          Color     color = Draw::COLOR_BROWN,
                          Direction dir   = Direction::NOP );
              ~DoorTile ( void );
        Action Interact ( void ) override;
    private:
        Direction m_Dir;

};

#endif