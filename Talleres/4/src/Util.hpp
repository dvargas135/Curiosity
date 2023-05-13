#ifndef UTIL_HPP
#define UTIL_HPP

#include <unordered_map>
#include <utility>
#include <vector>
#include "Airport.hpp"
#include "Flight.hpp"

std::pair<Airport*, int> searchAirportByCode(const std::unordered_map<int, Airport*>&, const std::string&);
std::unordered_map<int, Airport*> read_airports();
std::vector<Flight*> read_flights(std::unordered_map<int, Airport*>&);

#endif