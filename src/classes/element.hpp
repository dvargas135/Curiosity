#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

class Element {
    public:
        Element(const std::string&, double, std::string&, double, double);
        std::string getType() const;
        double getSize() const;
        std::string getMeasurementUnit() const;
        double getX() const;
        double getY() const;
    private:
        std::string type;
        double size;
        std::string measurement_unit;
        double x;
        double y;
};

#endif