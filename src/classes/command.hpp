#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
    public:
        Command(const std::string&);
        virtual ~Command();
        //command type: movement or analysis
        std::string getType() const;

        //movement functions to overwrite
        std::string getMovementType() const;
        double getMagnitude() const;
        std::string getMeasurementUnit() const;

        //analysis functions to overwrite
        std::string getAnalysisType() const;
        std::string getObject() const;
        std::string getComment() const;
    private:
        std::string type;
};

class Movement : public Command {
    public:
        Movement(std::string, double, std::string);
        std::string getMovementType() const;
        double getMagnitude() const;
        std::string getMeasurementUnit() const;
    private:
        std::string movement_type;
        double magnitude;
        std::string measurement_unit;
};

class Analysis : public Command {
    public:
        Analysis(std::string, std::string, std::string);
        std::string getAnalysisType() const;
        std::string getObject() const;
        std::string getComment() const;
    private:
        std::string analysis_type;
        std::string object;
        std::string comment;
};

#endif