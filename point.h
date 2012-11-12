#ifndef POINT_H
#define POINT_H

#include <QString>

struct Point
{
    int x;
    int y;
    int clas;

    bool operator==(const struct Point& p1)
    {
        return ( p1.x == x && p1.y == y && p1.clas == clas);
    }
};

#endif // POINT_H
