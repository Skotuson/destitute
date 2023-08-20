#ifndef ROOMGENERATOR_H
#define ROOMGENERATOR_H

#include <cstdlib>

#include "../level/Room.h"

const size_t MAX_ROOM_SIZE = 15,
             MIN_ROOM_SIZE = 5;

class RoomGenerator {
    public:
        static Room * Generate ( void );
    private:
};

#endif