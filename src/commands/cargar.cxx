#include "cargar.hpp"
#include "../util/util.hpp"
#include "../classes/command.hpp"
#include "../classes/element.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <cstdio>
#include <stdexcept>

void cargar_comandos(std::string filename, System& sys) {
    sys.clearCommands();
    std::string filepath = "textfiles/commands/" + fileName;
    if (!file_exists(filepath)) {
        printf("%s no se encuentra o no puede leerse.\n", filename.c_str());
        return;
    }

    std::ifstream infile(filepath);

    if (file_is_empty(infile)) {
        printf("%s no contiene comandos.\n", filename.c_str());
        return;
    }

    std::string line;
    while (getline(infile, line)) {
        std::string col1, col2, col3;
        double mag;

        std::stringstream ss(line);
        ss >> col1 >> col2 >> col3;
        if (col1 == "avanzar" || col1 == "girar") {
            try {
                mag = std::stod(col2);
            } catch (const std::invalid_argument& e) {
                printf("Magnitud inválida: '%s'. Saltando línea: %s\n", col2.c_str(), line.c_str());
                continue;
            }
            if ((col1 == "avanzar") && mag >= 0.0 && (col3 == "cm" || col3 == "m")) {
                Movement* m = new Movement(col1, mag, col3);
                sys.addCommand(m);
            } else if ((col1 == "girar") && col3 == "g") {
                Movement* m = new Movement(col1, mag, col3);
                sys.addCommand(m);
            } else {
                printf("La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad). Saltando línea: %s\n", line.c_str());
                return;
            }
        } else if (col1 == "fotografiar" || col1 == "composicion" || col1 == "perforar") {
            if (!col3.empty()) {
                if (!(col3.front() == '\'' && col3.back() == '\'')) {
                    printf("Sintax de comando incorrecto. Saltando línea: %s\n", line.c_str());
                    continue;
                }
            } else {
                col3 = "";
            }
            Analysis* a = new Analysis(col1, col2, col3);
            sys.addCommand(a);
        } else {
            printf("Comando incorrecto. Saltando línea: %s\n", line.c_str());
            continue;
        }
        printf("Comando `%s %s %s` cargado exitosamente.\n", col1.c_str(), col2.c_str(), col3.c_str());
    }
    infile.close();
}

void cargar_elementos(std::string filename, System& sys) {
    std::string errorMsg = "La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario).";
    sys.clearElements();
    //std::string filepath = "src/motion_files/analysis/" + fileName;
    std::string filepath = "textfiles/elements/" + filename;
    if (!file_exists(filepath)) {
        printf("%s no se encuentra o no puede leerse.\n", filename.c_str());
        return;
    }

    std::ifstream infile(filepath);

    if (file_is_empty(infile)) {
            printf("%s no contiene comandos.\n", filename.c_str());
        return;
    }

    std::string line;
    while (getline(infile, line)) {
        std::string col1, col2, col3, col4, col5;
        double size, x, y;

        std::stringstream ss(line);
        ss >> col1 >> col2 >> col3 >> col4 >> col5;

        try {
            size = std::stod(col2);
            if (!(size >= 0.0)) { printf("%s Saltando línea: %s\n", errorMsg.c_str(), line.c_str()); continue; }
            x = std::stod(col4);
            y = std::stod(col5);
        } catch (const std::invalid_argument& e) {
            printf("%s Saltando línea: %s\n", errorMsg.c_str(), line.c_str());
            continue;
        }

        if (!(col1 == "roca" || col1 == "crater" || col1 == "monticulo" || col1 == "duna") && (col3 == "cm" || col3 == "m")) {
            printf("%s Saltando línea: %s\n", errorMsg.c_str(), line.c_str());
            continue;
        }
        Element* e = new Element(col1, size, col3, x, y);
        sys.addElement(e);
        printf("Elemento `%s %s %s %s %s` cargado exitosamente.\n", col1.c_str(), col2.c_str(), col3.c_str(), col4.c_str(), col5.c_str());
    }
    infile.close();
}
