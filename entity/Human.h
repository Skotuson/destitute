#ifndef HUMAN_H
#define HUMAN_H

#include "Entity.h"

class Human : public Entity {
    public:
             Human  ( char                   look,
                      Point                  coords   = { 0, 0 },
                      Color                  color    = Draw::COLOR_DEFAULT,
                      Behavior::BehaviorType behavior = Behavior::BehaviorType::AI );
            
        void Attack ( void ) override;

    private:
};

#endif