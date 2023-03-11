#ifndef CURIOSITY_H
#define CURIOSITY_H

#include "command.h"

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