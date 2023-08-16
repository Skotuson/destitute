#ifndef ENTITY_H
#define ENTITY_H

#include "../utility/Point.h"

class Entity {
    public:
        Entity ( char  look,
                 Point coords );
    private:
        char  m_Look;
        Point m_Coords;
};

#endif