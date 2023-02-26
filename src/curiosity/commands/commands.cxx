#include "commands.h"
#include "../../util/util.h"
//#include "../../vector/vector.h"
//#include "../movement/curiosity_movement.h"
#include "../../curiosity/curiosity.h"

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

//extern Vector position;
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

void cargar_comandos(std::string fileName, Cmds& c) {
    std::string filepath = "./motion/movement/" + fileName;
    if (!file_exists(filepath)) {
        std::cout << fileName << " no se encuentra o no puede leerse." << std::endl;
        return;
    }
    
    std::ifstream infile(filepath);

    if (file_is_empty(infile)) {
        std::cout << fileName << " no contiene comandos." << std::endl;
        return;
    }

    std::queue<std::vector<std::string>> cmds;
    std::string line;

    while (getline(infile, line)) {
        std::vector<std::string> row;

        std::istringstream iss(line);
        std::string token;
        //while(getline(iss, token, ' ')) {
        while (iss >> token) {
            row.push_back(token);
        }
        cmds.push(row);
    }
    c.setCommands(cmds);

    std::cout << cmds.size() << " comandos cargados correctamente desde " << fileName << "!" << std::endl;
}

void cargar_elementos(std::string fileName, Elmts& e) {
    std::string filepath = "./motion/analysis/" + fileName;
    if (!file_exists(filepath)) {
        std::cout << fileName << " no se encuentra o no puede leerse." << std::endl;
        return;
    }

    std::ifstream infile(fileName);

    if (file_is_empty(infile)) {
        std::cout << fileName << " no contiene elementos." << std::endl;
        return;
    }
    
    std::queue<std::vector<std::string>> elmts;
    std::string line;

    while (getline(infile, line)) {
        std::vector<std::string> row;

        std::istringstream iss(line);
        std::string token;

        while (iss >> token) {
        //while(getline(iss, token, ' ')) {
            row.push_back(token);
        }
        elmts.push(row);
    }
    e.setElements(elmts);

    std::cout << elmts.size() << " elementos cargados correctamente desde " << fileName << "!" << std::endl;
}

void agregar_movimiento(std::string type, std::string magnitude, std::string measurement_unit, Cmds& c) {
    if (type == "avanzar") {
        if (is_positive(magnitude)) {
            if (measurement_unit == "cm" || measurement_unit == "m") {
                c.addCommand({type, magnitude, measurement_unit});
                std::cout << " El comando de movimiento ha sido agregado exitosamente." << std::endl;
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " medida inválida!" << std::endl;
            return;
        }
    } else if (type == "girar") {
        if (is_positive(magnitude)) {
            if (measurement_unit == "g") {
                c.addCommand({type, magnitude, measurement_unit});
                std::cout << " El comando de movimiento ha sido agregado exitosamente." << std::endl;
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
}

void agregar_analisis(std::string type, std::string obj, std::string comment, Cmds& c) {
    if (type == "fotografiar" || type == "composicion" || type == "perforar") {
        if (obj == "roca" || obj == "crater" || obj == "monticulo" || obj == "duna") {
            if (!comment.empty() && (comment.front() == '\'' && comment.back() == '\'')) {
                c.addCommand({type, obj, comment});
                std::cout << " El comando de análisis ha sido agregado exitosamente." << std::endl;
            } else {
                std::cout << " el comentario debe estar encerrado entre comillas simples!" << std::endl;
                return;
            }
            c.addCommand({type, obj});
            std::cout << " El comando de análisis ha sido agregado exitosamente." << std::endl;
        } else {
            std::cout << " tipo de análisis inválido!" << std::endl;
            return;
        }
    } else {
        std::cout << " objeto inválido!" << std::endl;
        return;
    }
}

void agregar_elemento(std::string type, std::string size, std::string measurement_unit, std::string x, std::string y, Elmts& e) {
    if (type == "fotografiar" || type == "composicion" || type == "perforar") {
        if (is_positive(size)) {
            if (measurement_unit == "cm" || measurement_unit == "m") {
                if (is_number(x) && is_number(y)) {
                    e.addElement({type, size, measurement_unit, x, y});
                    std::cout << " El elemento ha sido agregado exitosamente." << std::endl;
                } else {
                    std::cout << " valores incorrectos para x o y!" << std::endl;
                    return;
                }
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " tamaño inválido!" << std::endl;
            return;
        }
    } else {
        std::cout << " tipo de componente inválido!" << std::endl;
        return;
    }
}

void guardar(std::string type, std::string fileName, Cmds& c, Elmts& e) {
    if (type == "comandos") {
        fileName = "./motion/movement/" + fileName;
        std::ofstream outfile(fileName);

        std::queue<std::vector<std::string>> data = c.getCommands();

        if (data.empty()) {
            std::cout << " La información requerida no está almacenada en memoria." << std::endl;
            return;
        }
        
        while (!data.empty()) {
            std::vector<std::string> row = data.front();

            for (std::string column : row) {
                outfile << column << " ";
            }
            outfile << std::endl;
            data.pop();
        }
        outfile.close();

        std::cout << " La información ha sido guardada en " << fileName << "." << std::endl;
    } else if (type == "elementos") {
        fileName = "./motion/analysis/" + fileName;
        std::ofstream outfile(fileName);

        std::queue<std::vector<std::string>> data = e.getElements();

        if (data.empty()) {
            std::cout << " La información requerida no está almacenada en memoria." << std::endl;
            return;
        }
        
        while (!data.empty()) {
            std::vector<std::string> row = data.front();

            for (std::string column : row) {
                outfile << column << " ";
            }
            outfile << std::endl;
            data.pop();
        }
        outfile.close();
    } else {
        std::cout << " tipo de archivo inválido!" << std::endl;
        return;
    }
}

void simular_comandos(std::string x_, std::string y_) {
/*    double x = stod(x_);
    double y = stod(y_);

    Vector v(x, y);
    position = position + v;
    std::cout << " La simulación de los comandos, a partir de la posición (" << x_ << ", " << y_ << ")," << std::endl;
    std::cout << " deja al robot en la nueva posición (" << position.x() << ", " << position.y() << ")." << std::endl;
    */
}

void ubicar_elementos() {
    
}

void en_cuadrante(std::string x1, std::string x2, std::string y1, std::string y2) {

}

void crear_mapa(std::string conn_coeficient) {
    
}

void ruta_mas_larga() {

}

void ayuda(std::map<std::string, int> cmd_map, std::string cmd) {
    std::cout<<std::endl<<std::endl;
    switch (cmd_map[cmd]) {
        case 1:
            std::cout << "Uso: cargar_comandos <nombre_archivo>" << std::endl;
            break;
        case 2:
            std::cout << "Uso: cargar_elementos <nombre_archivo>" << std::endl;
            break;
        case 3:
            std::cout << "Uso: agregar_movimiento <tipo_mov> <magnitud> <unidad_med>" << std::endl;
            break;
        case 4:
            std::cout << "Uso: agregar_analisis <tipo_analisis> <objeto> <comentario>" << std::endl;
            break;
        case 5:
            std::cout << "Uso: agregar_elemento <tipo_comp <tamano> <unidad_med> <coordX> <coordY>" << std::endl;
            break;
        case 6:
            std::cout << "Uso: guardar <tipo_archivo> <nombre_archivo>" << std::endl;
            break;
        case 7:
            std::cout << "Uso: simular_comandos <coordX> <coordY>" << std::endl;
            break;
        case 8:
            std::cout << "Uso: salir" << std::endl;
            break;
        case 9:
            std::cout << "Uso: ubicar_elementos" << std::endl;
            break;
        case 10:
            std::cout << "Uso: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << std::endl;
            break;
        case 11:
            std::cout << "Uso: crear_mapa <coeficiente_conectividad>" << std::endl;
            break;
        case 12:
            std::cout << "Uso: ruta_mas_larga" << std::endl;
            break;
        case 13:
            std::cout << "Uso: ayuda <comando>" << std::endl;
            break;
        default:
            std::cout << "Comando no encontrado! Intente nuevamente. Uso: ayuda <comando>" << std::endl;
            break;
    }
}

void simular(std::string type, std::string magnitude, std::string measurement_unit, Cmds& c) {

    curiosity.printLocation();
    curiosity.move(10.3);
    curiosity.printLocation();
    curiosity.turn(90);
    curiosity.printLocation();
    curiosity.move(5.6);
    curiosity.printLocation();
}