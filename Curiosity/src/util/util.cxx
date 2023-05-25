#include "util.hpp"

#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <sstream>

bool is_positive(const std::string& s) {
    return !s.empty() && std::find_if(
        s.begin(), s.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }
    ) == s.end();
}

bool is_number(const std::string& str) {
    if (str.empty()) return false;
    bool has_sign = str[0] == '+' || str[0] == '-';
    for (size_t i = has_sign ? 1 : 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool file_exists(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

bool file_is_empty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

Point vectorToPoint(const Vector& v) {
    return Point{v.getX(), v.getY()};
}

bool isDouble(const std::string& input) {
    std::istringstream iss(input);
    double value;
    iss >> std::noskipws >> value;
    
    return iss.eof() && !iss.fail();
}