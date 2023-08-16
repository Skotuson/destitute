#include <iostream>

#include "LevelView.h"

void LevelView::View ( Level & level, std::vector<Entity *> & entities ) {
    const Layout & layout = level . GetLayout ( );
    for ( size_t i = 0; i < layout . size ( ); i++ ) {
        for ( size_t j = 0; j < layout[i] . size ( ); j++ )
            std::cout << *layout[i][j];
        std::cout << std::endl;
    }
}