#ifndef BEHAVIOR_ARTIFICIAL_H
#define BEHAVIOR_ARTIFICIAL_H

#include "Behavior.h"

class BehaviorArtificial : public Behavior {
    public: 
        Action GetNextAction ( void ) override;
    private:
};

#endif