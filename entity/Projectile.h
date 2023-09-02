#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity {
    public:
             Projectile ( char  look,
                          Point coords = { 0, 0 },
                          Color Color  = Draw::COLOR_ORANGE );
        void Attack     ( void ) override;

    private:
};

#endif