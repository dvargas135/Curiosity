#ifndef CURIOSITY_H
#define CURIOSITY_H

class Robot {
    public:
        Robot(double x, double y, double direction);
        void move(double distance);
        void turn(double degrees);
        void printLocation() const;
        void moveTo(double x, double y);
    private:
        double x_;
        double y_;
        double direction_;
};

#endif