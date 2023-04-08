#ifndef UTIL_HPP
#define UTIL_HPP

#include <fstream>
#include <string>

bool is_positive(const std::string&);
bool is_number(const std::string&);
bool file_exists (const std::string&);
bool file_is_empty(std::ifstream&);
Point vectorToPoint(const Vector&);

#endif