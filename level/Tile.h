#ifndef TILE_H
#define TILE_H

enum class Action { NOP, STOP };

class Tile {
    public: 
                       Tile     ( char look );
        virtual Action Interact ( void );
    private:
        char m_Look;
};

#endif 