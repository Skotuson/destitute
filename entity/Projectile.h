#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity {
    public:
             Projectile ( char                   look,
                          Point                  coords   = { 0, 0 },
                          Color                  Color    = Draw::COLOR_ORANGE,
                          Behavior::BehaviorType behavior = Behavior::BehaviorType::AI );
        void Attack     ( void ) override;

    private:
};

#endif