#include "curiosity.hpp"
#include <cmath>
#include <iostream>

Curiosity::Curiosity(double x, double y, double direction): x_(x), y_(y), direction_(direction) {}

void Curiosity::move(double distance) {
    double radians = direction_ * M_PI / 180.0;
    double delta_x = distance * sin(radians);
    double delta_y = distance * cos(radians);
    x_ += delta_x;
    y_ += delta_y;
}

void Curiosity::turn(double degrees) {
    direction_ += degrees;
}

std::string Curiosity::getLocation() const {
    return "Posición: (" + std::to_string(x_) + ", " + std::to_string(y_) +"). Dirección: " + std::to_string(direction_) + ".";
}

void Curiosity::moveTo(double x, double y) {
    double delta_x = x - x_;
    double delta_y = y - y_;
    double radians = atan2(delta_x, delta_y);
    x_ += x;
    y_ += y;
    direction_ = radians * 180.0 / M_PI;
}