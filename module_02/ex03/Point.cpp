#include <Point.h>

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point &obj) : _x(obj.getX()), _y(obj.getY()) {}
Point::~Point() {}

// note: the assignment operator can not set const attributes!
Point  &Point::operator=(const Point &obj)
{
    (void)obj;
    return *this;
}

Fixed Point::getX() const
{
    return (this->_x);
}

Fixed Point::getY() const
{
    return (this->_y);
}
