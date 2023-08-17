#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "../utility/Point.h"

class EntityFactory {
    public:
        static Entity * Create ( char  look, 
                                 Point coords );
};

#endif