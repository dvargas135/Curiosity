#include "cargar.h"
#include "../../util/util.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <unistd.h>

void cargar_comandos(std::string fileName, Cmds& c) {
    std::string filepath = "src/motion_files/movement/" + fileName;
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
    std::string filepath = "src/motion_files/analysis/" + fileName;
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