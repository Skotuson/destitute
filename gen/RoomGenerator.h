#ifndef ROOMGENERATOR_H
#define ROOMGENERATOR_H

#include <stack>
#include <tuple>
#include <cstdlib>

#include "../level/Room.h"

using RoomConfig = std::pair<Direction, Room *>;

const size_t MAX_ROOM_SIZE = 20,
             MIN_ROOM_SIZE = 10,
             MAX_ROOMS     = 8;

class RoomGenerator {
    public:
        static Room * GenerateRoom ( void );
    private:
        inline static std::stack<RoomConfig> m_ToProcess;

};

#endif