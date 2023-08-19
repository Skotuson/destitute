#ifndef DOORTILE_H
#define DOORTILE_H

#include "Tile.h"

class DoorTile : public Tile {
    public:
               DoorTile ( char  look,
                          Color color = Draw::COLOR_BROWN );
              ~DoorTile ( void );
        Action Interact ( void ) override;
    private:

};

#endif