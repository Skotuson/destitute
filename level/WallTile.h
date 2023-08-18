#ifndef WALLTILE_H
#define WALLTILE_H

#include "Tile.h"

class WallTile : public Tile {
    public:
               WallTile ( char look );
              ~WallTile ( void );     
        Action Interact ( void ) override;
    private:

};

#endif