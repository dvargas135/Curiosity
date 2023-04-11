#include "point.hpp"

double Point::getX() const { return x; }
double Point::getY() const { return y; }
void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

Point& Point::operator = (const Point &p) {
    x = p.x;
    y = p.y;
    return *this;
}

bool Point::operator == (const Point &p) const {
    return (x == p.x && y == p.y);
}

std::ostream& operator << (std::ostream &o, const Point &p) {
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}