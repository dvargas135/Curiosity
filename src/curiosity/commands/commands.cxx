#include "commands.h"
#include "../../util/util.h"
#include "../../curiosity/curiosity.h"

#include <iostream>
#include <queue>
#include <string>
#include <vector>

extern Robot curiosity;

// Cmds class declarations (commands and analyses)
std::queue<std::vector<std::string>> Cmds::getCommands() const {
    return commands;
}
void Cmds::setCommands(const std::queue<std::vector<std::string>>& c) {
    this -> commands = c;
}
void Cmds::addCommand(const std::vector<std::string>& v) {
    this -> commands.push(v);
}

// Elmts class declarations (elements)
std::queue<std::vector<std::string>> Elmts::getElements() const {
    return elements;
}
void Elmts::setElements(const std::queue<std::vector<std::string>>& e) {
    this -> elements = e;
}
void Elmts::addElement(const std::vector<std::string>& v) {
    this -> elements.push(v);
}

void simular_comandos(std::string x_, std::string y_) {
    double x = stod(x_);
    double y = stod(y_);

    curiosity.moveTo(x, y);
    curiosity.printLocation();
}

void ubicar_elementos() {}

void en_cuadrante(std::string x1, std::string x2, std::string y1, std::string y2) {}

void crear_mapa(std::string conn_coeficient) {}

void ruta_mas_larga() {}

void simular(std::string type, std::string magnitude, std::string measurement_unit, Cmds& c) {
    double m = stod(magnitude);
    if (type == "avanzar") {
        if (is_positive(magnitude)) {
            if (measurement_unit == "cm") {
                m = m*0.1;
                curiosity.move(m);
            } else if (measurement_unit == "m") {
                curiosity.move(m);
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " medida inválida!" << std::endl;
            return;
        }
    } else if (type == "girar") {
        if (is_number(magnitude)) {
            if (measurement_unit == "g") {
                curiosity.turn(m);
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " medida inválida!" << std::endl;
            return;
        }
    } else {
        std::cout << " tipo de movimiento inválido!" << std::endl;
        return;
    }
    curiosity.printLocation();
}

void print(Cmds& c) {
    //test
    /*
    std::queue<std::vector<std::string>> cad = c.getCommands();
    while (!cad.empty()) {
        std::vector<std::string> row = cad.front();
        cad.pop();

        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    */
}