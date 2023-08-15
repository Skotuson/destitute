#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <queue>

class Controller {
    public:
        void   Read          ( void );
        char   Peek          ( void );
        char   Get           ( void );
        size_t GetBufferSize ( void );
        void   Kill          ( void );
    private:
        std::queue<char> m_Buffer;
        bool             m_Quit    = false;
};

#endif