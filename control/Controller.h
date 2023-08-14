#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <queue>

class Controller {
    public:
        void Read ( void );
        char Peek ( void );
        char Get  ( void );
    private:
        std::queue<char> m_Buffer;
};

#endif