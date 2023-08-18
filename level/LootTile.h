#ifndef LOOTTILE_H
#define LOOTTILE_H

#include "Tile.h"

class LootTile : public Tile {
    public:
               LootTile ( char look );
              ~LootTile ( void );
        Action Interact ( void ) override;
    private:

};

#endif