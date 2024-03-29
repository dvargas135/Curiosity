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
void nate(std::vector<Airport*>);
bool file_exists (const std::string&);
bool file_is_empty(std::ifstream&);

#endif