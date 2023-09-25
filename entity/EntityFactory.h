#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "Behavior.h"
#include "../draw/Draw.h"
#include "../utility/Point.h"

class EntityFactory {
    public:
        static Entity * Create ( char                   look, 
                                 Point                  coords,
                                 Color                  color    = Draw::COLOR_DEFAULT,
                                 Behavior::BehaviorType behavior = Behavior::BehaviorType::AI );
};

#endif