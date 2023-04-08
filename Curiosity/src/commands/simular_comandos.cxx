#include "simular_comandos.hpp"
#include "../classes/curiosity.hpp"
#include "../classes/command.hpp"

#include <cstdio>
#include <stdexcept>

void simular_comandos(std::string x_str, std::string y_str, std::string d_str, System& sys) {
    double x, y, d, mag;

    try {
        x = std::stod(x_str);
        y = std::stod(y_str);
        d = std::stod(d_str);
    } catch (const std::invalid_argument& e) {
        printf("Input inválido.\n");
        return;
    }

    Curiosity c(x, y, d);

    printf("Simulando comandos... Posición inicial: %s\n\n", c.getLocation().c_str());

    std::queue<Command*> command_list = sys.getCommands();
    
    if (command_list.empty()) {
        printf("La información requerida no está almacenada en memoria.\n");
        return;
    }
    
    while (!command_list.empty()) {
        Command* s = command_list.front();
        Movement* m = dynamic_cast<Movement*>(s);
        Analysis* a = dynamic_cast<Analysis*>(s);
        if (m != nullptr) {
            mag = m->getMagnitude();
            if (m->getMovementType() == "avanzar") {
                if (m->getMeasurementUnit() == "cm") { mag *= 0.1; }
                c.move(mag);
            } else if (m->getMovementType() == "girar") {
                c.turn(mag);
            }
            printf(" >>> %s %f %s > %s\n", m->getMovementType().c_str(), m->getMagnitude(), m->getMeasurementUnit().c_str(), c.getLocation().c_str());
        } else if (a != nullptr) {
            printf(" >>> Análisis: %s %s %s", a->getAnalysisType().c_str(), a->getObject().c_str(), a->getComment().c_str());
        }
        command_list.pop();
    }
}