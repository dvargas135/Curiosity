#include "vector.hpp"
#include <cmath>

Vector::Vector() : x(0), y(0) {}
Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }
std::string Vector::getPos() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
void Vector::setX(double x) { this->x = x; }
void Vector::setY(double y) { this->y = y; }

double Vector::magnitude() const {
    return std::sqrt(x*x + y*y);
}
void Vector::normalize() {
    double mag = magnitude();
    if (mag != 0) {
        x /= mag;
        y /= mag;
    }
}

double Vector::dotProduct(const Vector& other) const {
    return x*other.getX() + y*other.getY();
}