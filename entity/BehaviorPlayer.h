#ifndef BEHAVIOR_PLAYER_H
#define BEHAVIOR_PLAYER_H

#include "Behavior.h"

class BehaviorPlayer : public Behavior {
    public: 
        Action GetNextAction ( void ) override;
    private:
};

#endif