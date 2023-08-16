#ifndef LEVELVIEW_H
#define LEVELVIEW_H

#include <vector>

#include "Level.h"
#include "../entity/Entity.h"

class LevelView {
    public:
        static void View ( Level                 & level, 
                           std::vector<Entity *> & entities );
    private:
};

#endif