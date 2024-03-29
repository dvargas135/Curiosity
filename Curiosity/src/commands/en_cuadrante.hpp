#ifndef EN_CUADRANTE_HPP
#define EN_CUADRANTE_HPP

#include <vector>

#include "../trees/quad/quadnode.hpp"
#include "../trees/quad/point.hpp"
#include "../classes/system.hpp"

// std::vector<Point> en_cuadrante(std::string, std::string, std::string, std::string, System&);
void en_cuadrante(std::string, std::string, std::string, std::string, System&);
void comparePoints(std::vector<Element>, const std::vector<Point>&, System&);

#endif