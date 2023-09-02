#include "EntityFactory.h"

#include "Human.h"
#include "Projectile.h"

Entity * EntityFactory::Create ( char look, Point coords ) {
    switch ( look ) {
        case '&': return new Human ( look, coords );
        case '*': return new Projectile ( look, coords );
        default:
            return nullptr;
    }
}