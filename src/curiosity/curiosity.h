class Robot {
    public:
        Robot(double x, double y, double direction);
        void move(double distance);
        void turn(double degrees);
        void printLocation() const;
    private:
        double x_;
        double y_;
        double direction_;
};