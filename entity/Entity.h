#ifndef ENTITY_H
#define ENTITY_H

#include "../utility/Point.h"
#include "../utility/Utility.h"

class Entity {
    public:
                 Entity ( char      look,
                          Point     coords );
        
    virtual void Move   ( Direction dir )    = 0;
    private:
        char  m_Look;
        Point m_Coords;
};

#endif