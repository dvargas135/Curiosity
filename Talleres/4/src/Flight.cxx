#include "Flight.hpp"

Flight::Flight(Airport* source, Airport* dest, double avg_time, double price)
    : source(source), dest(dest), avg_time(avg_time), price(price) {}

Flight::Flight() {}

Flight::~Flight() {}