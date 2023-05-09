#include "airport.h"

Airport::Airport(const std::string& city, const std::string& code, double lat, double lon)
    : m_city(city), m_code(code), m_latitude(lat), m_longitude(lon)
{
}

std::string Airport::getCity() const
{
    return m_city;
}

std::string Airport::getCode() const
{
    return m_code;
}

double Airport::getLatitude() const
{
    return m_latitude;
}

double Airport::getLongitude() const
{
    return m_longitude;
}
