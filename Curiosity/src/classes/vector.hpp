#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>

class Vector {
    public:
        Vector();
        Vector(double x, double y);
        double getX() const;
        double getY() const;
        std::string getPos();
        void setX(double x);
        void setY(double y);
        double magnitude() const;
        void normalize();
        double dotProduct(const Vector& other) const;
        
    private:
        double x;
        double y;
};

#endif