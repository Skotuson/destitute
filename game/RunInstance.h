#ifndef RUNINSTANCE_H
#define RUNINSTANCE_H

#include "../level/Level.h"
#include "../entity/Entity.h"

class RunInstance {
    public:
        RunInstance ( Level  * level, 
                      Entity * player );
    private:
        Level  * m_Level;
        Entity * m_Player;
};

#endif