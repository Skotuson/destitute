#ifndef RUNINSTANCE_H
#define RUNINSTANCE_H

#include <cstdlib>

#include "../level/Level.h"
#include "../entity/Entity.h"

class RunInstance {
    public:
             //First entity will be treated as a player
             RunInstance       ( Level                       * level, 
                                 const std::vector<Entity *> & entities );
      
        void Run               ( void );

        void HandleInteraction ( void );
    private:
        size_t                  m_Balance = 0;

        Level                 * m_Level;
        std::vector<Entity *>   m_Entities;
        Entity                * m_Player;
};

#endif