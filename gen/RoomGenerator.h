#ifndef ROOMGENERATOR_H
#define ROOMGENERATOR_H

#include <stack>
#include <tuple>
#include <cstdlib>

#include "../level/Room.h"

const int MAX_ROOM_SIZE = 20,
          MIN_ROOM_SIZE = 10,
          MAX_ROOMS     = 4;

class RoomGenerator {
    public:
        static Room * Generate      ( void );
        static Room * GenerateRoom  ( Direction   entryDir = Direction::NOP,
                                      Room      * prevRoom = nullptr );
    private:
        static Point  GetRandomDoor ( int         rows, 
                                      int         cols, 
                                      Direction   dir );
        inline static int m_GeneratedRooms = 0;

};

#endif