#include <Point.h>

// Point.cpp
Point::Point() : _x(0), _y(0) {}
Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const  Point  &obj) {
	*this  =  obj;
}

Point::~Point() {}

Point  &Point::operator=(const  Point  &obj) {
	this->_x = obj._x;
	this->_y = obj._y;
	return *this;
}
