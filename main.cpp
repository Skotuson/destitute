#include <iostream>
#include <thread>

#include "control/Controller.h"
#include "gen/RoomGenerator.h"
#include "game/RunInstance.h"
#include "entity/Human.h"
#include "level/Level.h"
#include "draw/Draw.h"

int main ( void ) {
    std::cout << Draw::CLEAR_SCREEN << Draw::HIDE_CURSOR;
    std::thread input ( Controller::Read );

    Level * l = new Level ( );
    l -> Load ( "level/examples/vault.txt" );
    std::vector<Entity *> v = { new Human ( '&', { 7, 4 } ) };
    
    RunInstance inst ( l, v );

    inst . Run ( );

    input . join ( );
    delete v[0];
    delete l;
    std::cout << Draw::SHOW_CURSOR;

    Room * r = RoomGenerator::Generate ( );

    delete r;

    return 0;
}