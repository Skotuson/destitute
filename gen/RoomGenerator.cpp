#include "RoomGenerator.h"

#include <iostream>
#include <vector>

void RoomGenerator::Generate ( void ) {
    std::vector<std::vector<int>> m_Room;
    srand ( time ( nullptr ) );
    size_t n = rand ( ) % MAX_ROOM_SIZE + MIN_ROOM_SIZE;

    for ( size_t i = 0; i < n; i++ ) {
        m_Room . push_back ( std::vector<int> ( ) );
        for ( size_t j = 0; j < n; j++ ) {
            if ( ! j || ! i || j == ( n - 1 ) || i == ( n - 1 ) ) 
                m_Room[i] . push_back ( 0 );
            else m_Room[i] . push_back ( rand ( ) % ( n / 2 ) );
        }
    }

    //for ( const auto & row : m_Room ) {
    //    for ( const auto & col : row )
    //        std::cout << col << " ";
    //    std::cout << std::endl; 
    //}
}