#ifndef POINT_HPP
#define POINT_HPP

#include "../../classes/element.hpp"
#include <iostream>

class Point {
public:
    double x;
    double y;
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    //Element e;
    Point& operator = (const Point &p);
    bool operator == (const Point &p) const;
    friend std::ostream& operator << (std::ostream &o, const Point &p);
};

#endif