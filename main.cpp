#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "gen/RoomGenerator.h"
#include "game/RunInstance.h"
#include "entity/Human.h"
#include "level/Level.h"
#include "draw/Draw.h"

int main ( void ) {
    std::cout << Draw::CLEAR_SCREEN << Draw::RETURN_CURSOR << Draw::HIDE_CURSOR;
    
    Level * l = new Level ( );
    l -> Load ( "level/examples/vault.txt" );
    std::vector<Entity *> v = { new Human ( '&', { 7, 4 } ) };
    
    //std::thread input ( Controller::Read );
    //RunInstance inst ( l, v );
    //inst . Run ( );
    //input . join ( );
    
    delete v[0];
    delete l;
    std::cout << Draw::SHOW_CURSOR;

    Room * r = RoomGenerator::Generate ( );
    r -> Print ( );
    delete r;

    return 0;
}