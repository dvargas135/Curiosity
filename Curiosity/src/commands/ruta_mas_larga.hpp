#ifndef RUTA_MAS_LARGA_HPP
#define RUTA_MAS_LARGA_HPP

#include "../classes/system.hpp"
#include "../classes/element.hpp"

void ruta_mas_larga(System&);
void findMaxDistancePath(const Node*, const std::string&, double, std::unordered_set<const Node*>& visited, double&, std::string&);
std::pair<double, std::string> findPathWithMaxDistance(const Graph*);

#endif