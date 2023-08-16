#ifndef POINT_H
#define POINT_H

struct Point {
        Point       ( int  x, 
                      int  y );    
    
    int operator [] ( char coord );

    int m_X,
        m_Y;
};

#endif