#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Airport.hpp"

class Flight {
public:
    Airport* source;
    Airport* dest;
    double avg_time;
    double price;

    Flight(Airport*, Airport*, double, double);
    Flight();
    ~Flight();
};

#endif