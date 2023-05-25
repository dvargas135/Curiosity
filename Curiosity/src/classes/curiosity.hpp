#ifndef CURIOSITY_HPP
#define CURIOSITY_HPP

#include "command.hpp"

class Curiosity {
    public:
        Curiosity(double x, double y, double direction);
        void move(double distance);
        void turn(double degrees);
        std::string getLocation() const;
        void moveTo(double x, double y);
        
    private:
        double x_;
        double y_;
        double direction_;
};

#endif