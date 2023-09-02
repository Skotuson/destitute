#include <iostream>
#include <thread>

#include "entity/EntityFactory.h"
#include "control/Controller.h"
#include "gen/RoomGenerator.h"
#include "entity/Projectile.h"
#include "game/RunInstance.h"
#include "entity/Human.h"
#include "level/Level.h"
#include "draw/Draw.h"

int main ( void ) {
    std::cout << Draw::HIDE_CURSOR;
    Draw::ClearScreen ( );
    
    Level * l = new Level ( RoomGenerator::Generate ( ) );
    std::vector<Entity *> v = { EntityFactory::Create ( '&', { 7, 4 } ) };
    
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