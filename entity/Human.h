#ifndef HUMAN_H
#define HUMAN_H

#include "Entity.h"

class Human : public Entity {
    public:
             Human ( char      look,
                     Point     coords );

        void Move  ( Direction dir ) override;
    private:
};

#endif