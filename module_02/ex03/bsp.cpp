#include <Point.h>
#include <Fixed.h>

// returns dy / dx;
static Fixed slope(Point const p1, Point const p2)
{
    return ((p2.getY() - p1.getY()) / (p2.getX() - p1.getX()));
}

// point is south of edge
static bool is_so(Point const p1, Point const p2, Point const point)
{
    // yRef = y value of the point on edge p1p2 with same x value as 'point';
    Fixed yRef = p1.getY() + (point.getX() - p1.getX()) * slope(p1, p2);
    return (point.getY() < yRef
            && yRef >= Fixed::min(p1.getY(), p2.getY())
            && yRef <= Fixed::max(p1.getY(), p2.getY()));
}

// point is north of edge
static bool is_no(Point const p1, Point const p2, Point const point)
{
    // yRef = y value of the point on edge p1p2 with same x value as 'point';
    Fixed yRef = p1.getY() + (point.getX() - p1.getX()) * slope(p1, p2);
    return (point.getY() > yRef
            && yRef >= Fixed::min(p1.getY(), p2.getY())
            && yRef <= Fixed::max(p1.getY(), p2.getY()));
}

// point is west of edge
static bool is_we(Point const p1, Point const p2, Point const point)
{
    // xRef = x value of the point on edge p1p2 with same y value as 'point';
    Fixed xRef = p1.getX() + (point.getY() - p1.getY()) / slope(p1, p2);
    return (point.getX() < xRef
            && xRef >= Fixed::min(p1.getX(), p2.getX())
            && xRef <= Fixed::max(p1.getX(), p2.getX()));
}

// point is east of edge
static bool is_es(Point const p1, Point const p2, Point const point)
{
    // xRef = x value of the point on edge p1p2 with same y value as 'point';
    Fixed xRef = p1.getX() + (point.getY() - p1.getY()) / slope(p1, p2);
    return (point.getX() > xRef
            && xRef >= Fixed::min(p1.getX(), p2.getX())
            && xRef <= Fixed::max(p1.getX(), p2.getX()));
}

// traversing from 'point' an edge should be encoutered in all four directions
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    return ((is_no(a, b, point) || is_no(a, c, point) || is_no(b, c, point))
            && (is_es(a, b, point) || is_es(a, c, point) || is_es(b, c, point))
            && (is_so(a, b, point) || is_so(a, c, point) || is_so(b, c, point))
            && (is_we(a, b, point) || is_we(a, c, point) || is_we(b, c, point)));
}
