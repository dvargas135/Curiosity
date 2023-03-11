#include "element.h"
#include <string>

Element::Element(const std::string& t, double s, std::string& mu, double x, double y) : type(t), size(s), measurement_unit(mu), x(x), y(y) {}
std::string Element::getType() const { return type; }
double Element::getSize() const { return size; }
std::string Element::getMeasurementUnit() const { return measurement_unit; }
double Element::getX() const { return x; }
double Element::getY() const { return y; }