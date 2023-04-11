#include "en_cuadrante.hpp"
#include <cstdio>
#include <string>

std::vector<Point> en_cuadrante(std::string x1_str, std::string x2_str, std::string y1_str, std::string y2_str, System& s) {
    double x1, x2, y1, y2;
    x1 = std::stod(x1_str);
    x2 = std::stod(x2_str);
    y1 = std::stod(y1_str);
    y2 = std::stod(y2_str);
    std::vector<Point> elementos;

    elementos=s.getTree().listaPreorder(s.getTree().getRoot(), x1, x2, y1, y2, elementos);

    for (auto a : elementos) {
        printf("%f, %f\n", a.getX(), a.getY());
    }

    return elementos;
}