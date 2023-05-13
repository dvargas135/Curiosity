#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include <string>

class Airport {
public:
    std::string name;
    std::string code;
    double latitude;
    double longitude;

    Airport();
    Airport(const std::string&, const std::string&, double, double);

    bool operator==(const Airport&) const;
    bool operator!=(const Airport&) const;
    bool operator<(const Airport&) const;

    ~Airport();
};

#endif