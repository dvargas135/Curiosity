#include "command.h"
#include <string>

Command::Command(const std::string& type) : type(type) {}
Command::~Command() {}
std::string Command::getType() const { return type; }

std::string Command::getMovementType() const { return 0; };
double Command::getMagnitude() const { return 0; };
std::string Command::getMeasurementUnit() const { return 0; };

std::string Command::getAnalysisType() const { return 0; }
std::string Command::getObject() const { return 0; }
std::string Command::getComment() const { return 0; }

Movement::Movement(std::string mt, double m, std::string mu) : Command("movement"), movement_type(mt), magnitude(m), measurement_unit(mu) {}
std::string Movement::getMovementType() const { return movement_type; }
double Movement::getMagnitude() const { return magnitude; }
std::string Movement::getMeasurementUnit() const { return measurement_unit; }

Analysis::Analysis(std::string at, std::string o, std::string c) : Command("analysis"), analysis_type(at), object(o), comment(c) {}
std::string Analysis::getAnalysisType() const { return analysis_type; }
std::string Analysis::getObject() const { return object; }
std::string Analysis::getComment() const { return comment; }