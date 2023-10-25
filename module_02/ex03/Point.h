#ifndef POINT_H
#define POINT_H

#include <Fixed.h>

class Point {
public:
    Point();
    Point(float x, float y);
    Point(const Point &obj);
    ~Point();
    Point &operator=(const Point &obj);

private:
    Fixed _x;
    Fixed _y;
};

#endif
