#include <iostream>

#include "LevelView.h"

void LevelView::View ( Level & level, std::vector<Entity *> & entities ) {
    const Layout & layout = level . GetLayout ( );
    for ( size_t i = 0; i < layout . size ( ); i++ ) {
        for ( size_t j = 0; j < layout[i] . size ( ); j++ ) {
            bool occupied = false;
            for ( const auto & e : entities ) {
                if ( e -> IsAt ( { i, j } ) ) {
                    std::cout << *e;
                    occupied = true;
                    break;
                } 
            }
            
            if ( ! occupied )
                std::cout << *layout[i][j];
        }
        std::cout << std::endl;
    }
}