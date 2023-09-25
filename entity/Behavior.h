#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "../game/Action.h"

class Behavior {
    public: 
        enum class BehaviorType {
            PLAYER, AI
        };

        virtual Action GetNextAction ( void ) = 0;
    
    private:
        
};

#endif