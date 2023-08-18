#ifndef LOOTTILE_H
#define LOOTTILE_H

#include "Tile.h"

class LootTile : public Tile {
    public:
               LootTile ( char  look,
                          Color color = Draw::COLOR_B_GREEN );
              ~LootTile ( void );
        Action Interact ( void ) override;
    private:

};

#endif