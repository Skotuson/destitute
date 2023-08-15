#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <queue>

const char EXIT_CHAR = 'x';

class Controller {
    public:
        void   Read          ( void );
        char   Peek          ( void );
        char   Get           ( void );
        size_t GetBufferSize ( void );
    private:
        std::queue<char> m_Buffer;
};

#endif