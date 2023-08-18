#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <queue>

const char EXIT_CHAR = 'x';

class Controller {
    public:
        static void   Read          ( void );
        static char   Peek          ( void );
        static char   Get           ( void );
        static size_t GetBufferSize ( void );
    private:
        inline static std::queue<char> m_Buffer;
};

#endif