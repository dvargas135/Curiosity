#include "curiosity.h"
#include <cmath>
#include <iostream>

Robot::Robot(double x, double y, double direction): x_(x), y_(y), direction_(direction) {}

void Robot::move(double distance) {
    double radians = direction_ * M_PI / 180.0;
    double delta_x = distance * sin(radians);
    double delta_y = distance * cos(radians);
    x_ += delta_x;
    y_ += delta_y;
}

void Robot::turn(double degrees) {
    direction_ += degrees;
}

void Robot::printLocation() const {
    std::cout << "Posición del robot: (" << x_ << ", " << y_ << "). Dirección: " << direction_ << " grados." << std::endl;
}

void Robot::moveTo(double x, double y) {
    double delta_x = x - x_;
    double delta_y = y - y_;
    double radians = atan2(delta_x, delta_y);
    x_ += x;
    y_ += y;
    direction_ = radians * 180.0 / M_PI;
}