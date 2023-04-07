#include "point.hpp"

Point& Point::operator = (const Point &p) {
    x = p.x;
    y = p.y;
    return *this;
}

bool Point::operator == (const Point &p) const {
    return (x == p.x && y == p.y);
}

std::ostream& operator << (std::ostream &o, const Point &p) {
    o << "(" << p.x << "," << p.y << ")";
    return o;
}