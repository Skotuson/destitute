#include "EntityFactory.h"

#include "Human.h"
#include "Projectile.h"

Entity * EntityFactory::Create ( char look, Point coords, Color color, Behavior::BehaviorType behavior ) {
    switch ( look ) {
        case '&': return new Human ( look, coords, color, behavior );
        case '*': return new Projectile ( look, coords, color, behavior );
        default:
            return nullptr;
    }
}