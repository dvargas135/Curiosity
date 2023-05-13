#include "Airport.hpp"

Airport::Airport() = default;

Airport::Airport(const std::string& name, const std::string& code, double latitude, double longitude)
    : name(name), code(code), latitude(latitude), longitude(longitude) {}

bool Airport::operator==(const Airport& other) const {
    return code == other.code;
}

bool Airport::operator!=(const Airport& other) const {
    return code != other.code;
}

bool Airport::operator<(const Airport& other) const {
    return code < other.code;
}

Airport::~Airport() {}