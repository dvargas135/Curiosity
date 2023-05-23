#include "element.hpp"

Element::Element(const std::string& t, double s, std::string& mu, const Vector& p) : type(t), size(s), measurement_unit(mu), position(p) {}
Element::Element() {}
Element::~Element() {}
std::string Element::getType() const { return type; }
double Element::getSize() const { return size; }
std::string Element::getMeasurementUnit() const { return measurement_unit; }
Vector Element::getPosition() const { return position; }
void Element::setPosition(const Vector& position) { this->position = position; }
//double Element::getX() const { return x; }
//double Element::getY() const { return y; }