#ifndef POINT_H
#define POINT_H

#include <Fixed.h>

class Point {
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &obj);
    ~Point();
    Point &operator=(const Point &obj);
    Fixed getX() const;
    Fixed getY() const;

private:
    Fixed const _x;
    Fixed const _y;
};

#endif
