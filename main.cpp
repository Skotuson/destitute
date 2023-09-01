#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "gen/RoomGenerator.h"
#include "game/RunInstance.h"
#include "entity/Projectile.h"
#include "entity/Human.h"
#include "level/Level.h"
#include "draw/Draw.h"

int main ( void ) {
    std::cout << Draw::HIDE_CURSOR;
    Draw::ClearScreen ( );
    
    Level * l = new Level ( RoomGenerator::Generate ( ) );
    std::vector<Entity *> v = { new Human ( '&', { 7, 4 } ) };
    
    std::thread input ( Controller::Read );
    RunInstance inst ( l, v );
    inst . Run ( );
    input . join ( );
    
    for ( const auto & e : v )
        delete e;
    delete l;
    std::cout << Draw::SHOW_CURSOR;

    return 0;
}