#include <iostream>

#include "LevelView.h"

void LevelView::View ( Level & level, std::vector<Entity *> & entities ) {
    const Layout & layout = level . GetLayout ( );
    for ( const auto & row : layout ) {
        for ( const auto & col : row )
            std::cout << *col;
        std::cout << std::endl;
    }
}