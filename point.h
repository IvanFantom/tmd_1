#ifndef POINT_H
#define POINT_H

struct Point
{
    int x;
    int y;

    bool operator==(const struct Point& p1)
    {
        return ( p1.x == x && p1.y == y );
    }
};

#endif // POINT_H
