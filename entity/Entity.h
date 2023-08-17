#ifndef ENTITY_H
#define ENTITY_H

#include "../utility/Point.h"
#include "../utility/Utility.h"

class Entity {
    public:
         Entity ( char      look,
                  Point     coords );
        
    void Move   ( Direction dir );
    private:
        char  m_Look;
        Point m_Coords;
};

#endif