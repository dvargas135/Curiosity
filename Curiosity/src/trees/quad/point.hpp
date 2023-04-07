#ifndef PUNTO_HPP
#define PUNTO_HPP

#include <iostream>

class Point {
public:
    int x;
    int y;
    Point& operator = (const Point &p);
    bool operator == (const Point &p) const;
    friend std::ostream& operator << (std::ostream &o, const Point &p);
};

#endif