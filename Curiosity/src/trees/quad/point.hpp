#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
public:
    double x;
    double y;
    Point& operator = (const Point &p);
    bool operator == (const Point &p) const;
    friend std::ostream& operator << (std::ostream &o, const Point &p);
};

#endif