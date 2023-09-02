#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "../draw/Draw.h"
#include "../game/Action.h"
#include "../utility/Point.h"
#include "../utility/Direction.h"

class Entity {
    public:
                               Entity      ( char           look,
                                             Point          coords = { 0, 0 },
                                             Color          color  = Draw::COLOR_DEFAULT ); 
        virtual               ~Entity      ( void );
                        
                void           Move        ( Direction      dir );
        virtual void           Attack      ( void ) = 0;
                Point          GetCoords   ( void );
                void           SetCoords   ( Point          pt );
                void           Interact    ( Action         action );
                
                bool           IsAt        ( Point          pt );

        friend  std::ostream & operator << ( std::ostream & os,
                                            const Entity & e );

    private:
        char  m_Look;
        Point m_Coords;
        Color m_Color;
};

#endif