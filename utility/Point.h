#ifndef POINT_H
#define POINT_H

struct Point {
         Point       ( int   x = 0, 
                       int   y = 0 );    
    
    bool operator <  ( const Point pt ) const;
    bool operator == ( const Point pt ) const;
    int  operator [] ( char  coord );

    int m_X,
        m_Y;
};

#endif