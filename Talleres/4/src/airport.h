#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <unordered_map>

class Airport {
public:
    Airport() = default;
    Airport(const std::string& city, const std::string& code, double lat, double lon);

    std::string getCity() const;
    std::string getCode() const;
    double getLatitude() const;
    double getLongitude() const;

private:
    std::string m_city;
    std::string m_code;
    double m_latitude;
    double m_longitude;
};

class AirportHasher {
public:
    std::size_t operator()(const Airport& airport) const {
        return std::hash<std::string>()(airport.getCode());
    }
};

class AirportEqual {
public:
    bool operator()(const Airport& lhs, const Airport& rhs) const {
        return lhs.getCode() == rhs.getCode();
    }
};

#endif
