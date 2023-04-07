#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "vector.hpp"
#include <string>

class Element {
    public:
        Element(const std::string&, double, std::string&, const Vector&);
        std::string getType() const;
        double getSize() const;
        std::string getMeasurementUnit() const;
        Vector getPosition() const;
        void setPosition(const Vector&);
    private:
        std::string type;
        double size;
        std::string measurement_unit;
        Vector position;
};

#endif