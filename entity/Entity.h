#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "../game/Action.h"
#include "../utility/Point.h"
#include "../utility/Direction.h"

class Entity {
    public:
                              Entity      ( char           look,
                                            Point          coords );
                        
               void           Move        ( Direction      dir );
               Point          GetCoords   ( void );
               void           SetCoords   ( Point          pt );
               void           Interact    ( Action         action );
                
               bool           IsAt        ( Point          pt );

        friend std::ostream & operator << ( std::ostream & os,
                                            const Entity & e );

    private:
        char  m_Look;
        Point m_Coords;
};

#endif