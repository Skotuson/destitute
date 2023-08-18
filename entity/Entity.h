#ifndef ENTITY_H
#define ENTITY_H

#include "../utility/Point.h"
#include "../utility/Direction.h"

class Entity {
    public:
                              Entity      ( char           look,
                                            Point          coords );
                        
               void           Move        ( Direction      dir );

        friend std::ostream & operator << ( std::ostream & os,
                                            const Entity & e );

    private:
        char  m_Look;
        Point m_Coords;
};

#endif